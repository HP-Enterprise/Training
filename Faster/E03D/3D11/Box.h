#pragma once

using namespace Microsoft::WRL;
using namespace DirectX;

// �������ݽṹ
struct BoxVertex
{
	XMFLOAT3 pos;
	XMFLOAT4 color;
};

// һ��������
class Box
{
public:
	Box();
	virtual ~Box();

	ID3D11InputLayout* GetLayout() { return m_ptrLayout.Get(); }
	ID3D11Buffer* GetVB() { return m_ptrVB.Get(); }
	ID3D11Buffer* GetIB() { return m_ptrIB.Get(); }
	int GetVBStride() { return sizeof(BoxVertex); }
	int GetIBCount() { return sizeof(m_indicies) / sizeof(unsigned int); }
	DXGI_FORMAT GetIBFmt() { return DXGI_FORMAT_R32_UINT; }

	HRESULT CreateD3DRes(ComPtr<ID3D11Device>& ptrDev, const void* pVS, DWORD dwVS);
private:
	// 8������
	BoxVertex m_vertices[8];
	// 6����,ÿ��2��������
	unsigned int m_indicies[3*12];

	// ��������ʽ
	ComPtr<ID3D11InputLayout> m_ptrLayout;
	// ���㻺����
	ComPtr<ID3D11Buffer> m_ptrVB;
	// ����������
	ComPtr<ID3D11Buffer> m_ptrIB;

	// ������������ʽ
	HRESULT CreateInputLayout(ComPtr<ID3D11Device>& ptrDev, const void* pVS, DWORD dwVS);
	// �������㻺����
	HRESULT CreateVerticesBuffer(ComPtr<ID3D11Device>& ptrDev);
	// ������������������
	HRESULT CreateIndicesBuffer(ComPtr<ID3D11Device>& ptrDev);
};
