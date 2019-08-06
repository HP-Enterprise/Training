#include "stdafx.h"
#include "Box.h"

Box::Box()
	: m_vertices{
		{ XMFLOAT3(-1.0f, -1.0f, -1.0f), XMFLOAT4(Colors::White)   },
		{ XMFLOAT3(-1.0f, +1.0f, -1.0f), XMFLOAT4(Colors::Gray)   },
		{ XMFLOAT3(+1.0f, +1.0f, -1.0f), XMFLOAT4(Colors::Red)     },
		{ XMFLOAT3(+1.0f, -1.0f, -1.0f), XMFLOAT4(Colors::Green)   },
		{ XMFLOAT3(-1.0f, -1.0f, +1.0f), XMFLOAT4(Colors::Blue)    },
		{ XMFLOAT3(-1.0f, +1.0f, +1.0f), XMFLOAT4(Colors::Yellow)  },
		{ XMFLOAT3(+1.0f, +1.0f, +1.0f), XMFLOAT4(Colors::Cyan)    },
		{ XMFLOAT3(+1.0f, -1.0f, +1.0f), XMFLOAT4(Colors::Magenta) }
	},
	m_indicies{
		// ǰ
		0, 1, 2,
		0, 2, 3,
		// ��
		4, 6, 5,
		4, 7, 6,
		// ��
		4, 5, 1,
		4, 1, 0,
		// ��
		3, 2, 6,
		3, 6, 7,
		// ��
		1, 5, 6,
		1, 6, 2,
		// ��
		4, 0, 3,
		4, 3, 7
	}
{
	m_vInputDesc = {
		{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 },
		{ "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 }
	};
}

Box::~Box()
{
	// Խ���ͷ�Խ��,����ʱ��Ϊ���ı����ֶ�
	for (int i = 0; i < m_vPtrs.size(); i++) {
		delete m_vPtrs[i];
	}

	m_vPtrs.clear();
}


HRESULT Box::CreateD3DRes(ComPtr<ID3D12GraphicsCommandList> &ptrCmdList)
{
	HRESULT hr;

	// ���㻺����
	hr = CreateGPUBuffer(ptrCmdList, m_ptrVBuf, m_vertices, sizeof(m_vertices));
	if (FAILED(hr)) return hr;

	m_viewVB.BufferLocation = m_ptrVBuf->GetGPUVirtualAddress();
	m_viewVB.SizeInBytes = sizeof(m_vertices);
	m_viewVB.StrideInBytes = sizeof(m_vertices) / _countof(m_vertices);
	
	// ��������������
	hr = CreateGPUBuffer(ptrCmdList, m_ptrIBuf, m_indicies, sizeof(m_indicies));
	m_viewIB.BufferLocation = m_ptrIBuf->GetGPUVirtualAddress();
	m_viewIB.SizeInBytes = sizeof(m_indicies);
	m_viewIB.Format = DXGI_FORMAT_R32_UINT;
	
	return hr;
}

HRESULT Box::CreateGPUBuffer(ComPtr<ID3D12GraphicsCommandList>& ptrCmdList, ComPtr<ID3D12Resource1>& ptrResDst, void* pSrc, rsize_t size)
{
	D3D12_HEAP_PROPERTIES heap{
		D3D12_HEAP_TYPE_DEFAULT,
		D3D12_CPU_PAGE_PROPERTY_UNKNOWN,
		D3D12_MEMORY_POOL_UNKNOWN,
		0,
		0
	};

	D3D12_RESOURCE_DESC desc{
		D3D12_RESOURCE_DIMENSION_BUFFER,
		0, // alignment
		size,
		1,
		1,
		1,
		DXGI_FORMAT_UNKNOWN,
		{ 1, 0 },
		D3D12_TEXTURE_LAYOUT_ROW_MAJOR,
		D3D12_RESOURCE_FLAG_NONE
	};

	ComPtr<ID3D12Device> ptrDev;
	HRESULT hr = ptrCmdList->GetDevice(IID_PPV_ARGS(&ptrDev));

	// ����Ŀ�껺����
	hr = ptrDev->CreateCommittedResource(&heap, D3D12_HEAP_FLAG_NONE, &desc, D3D12_RESOURCE_STATE_COMMON, nullptr, IID_PPV_ARGS(&ptrResDst));
	if (FAILED(hr)) return hr;

	// D3D12_HEAP_TYPE_DEFAULT���͵Ļ�����ֻ�ܱ�GPU����,���,��Ҫͨ����һ��D3D12_HEAP_TYPE_UPLOAD����������
	ComPtr<ID3D12Resource1>* pPtrUploadBuf = new ComPtr<ID3D12Resource1>();
	m_vPtrs.push_back(pPtrUploadBuf);

	heap.Type = D3D12_HEAP_TYPE_UPLOAD;
	ComPtr<ID3D12Resource1>& ptrUploadBuf = *pPtrUploadBuf;
	hr = ptrDev->CreateCommittedResource(&heap, D3D12_HEAP_FLAG_NONE, &desc, D3D12_RESOURCE_STATE_GENERIC_READ, nullptr, IID_PPV_ARGS(&ptrUploadBuf));

	// �������� pSrc -> ptrUploadBuf
	void* pData;
	hr = ptrUploadBuf->Map(0, nullptr, &pData);
	memcpy_s(pData, size, pSrc, size);
	ptrUploadBuf->Unmap(0, nullptr);

	// �������� ptrUploadBuf -> ptrResDst
	D3D12_RESOURCE_BARRIER barrier{
		D3D12_RESOURCE_BARRIER_TYPE_TRANSITION,
		D3D12_RESOURCE_BARRIER_FLAG_NONE,
		{
			ptrResDst.Get(),
			D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES,
			D3D12_RESOURCE_STATE_COMMON,
			D3D12_RESOURCE_STATE_COPY_DEST
		}
	};
	ptrCmdList->ResourceBarrier(1, &barrier);

	// TRANSITION : STATE_COPY_DEST -> STATE_GENERIC_READ
	// ����ֻ�Ǵ���һ����������,GPU�����Ժ�ʵ��ִ���������
	// �ڿ���ʵ�����ǰ�������ͷŵ�ptrUploadBuf
	ptrCmdList->CopyBufferRegion(ptrResDst.Get(), 0, ptrUploadBuf.Get(), 0, size);

	D3D12_RESOURCE_BARRIER barrier2{
		D3D12_RESOURCE_BARRIER_TYPE_TRANSITION,
		D3D12_RESOURCE_BARRIER_FLAG_NONE,
		{
			ptrResDst.Get(),
			D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES,
			D3D12_RESOURCE_STATE_COPY_DEST,
			D3D12_RESOURCE_STATE_GENERIC_READ
		}
	};
	ptrCmdList->ResourceBarrier(1, &barrier2);
	
	return hr;
}