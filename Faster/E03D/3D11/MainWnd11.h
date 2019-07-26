#pragma once
#include "Box.h"

using namespace Microsoft::WRL;

struct ConstantBuffer
{
	XMMATRIX mWorld;
	XMMATRIX mView;
	XMMATRIX mProjection;
};

class MainWnd11 : public XWnd
{
public:
	MainWnd11();
	virtual ~MainWnd11();

	BOOL Create();
protected:
	ATOM Register();
	LRESULT WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) override;
	
	BOOL OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) override;
	void OnDestroy(HWND hwnd) override;
	virtual void OnPaint(HWND hwnd) override;
	virtual BOOL OnEraseBkgnd(HWND hwnd, HDC hdc);
	virtual void OnSize(HWND hwnd, UINT state, int cx, int cy);
private:
	ComPtr<ID3D11Device> m_ptrDevice;
	ComPtr<ID3D11DeviceContext> m_ptrDevCtx;
	ComPtr<IDXGISwapChain> m_ptrDXGISwapChain;
	ComPtr<ID3D11Texture2D> m_ptrZBuf;
	ComPtr<ID3D11RenderTargetView> m_ptrRTV;
	ComPtr<ID3D11DepthStencilView> m_ptrDSV;
	ComPtr<ID3D11RasterizerState> m_ptrRS;
	ComPtr<ID3D11Buffer> m_ptrConstant;

	BYTE *m_pVS, *m_pPS;
	DWORD m_dwVS, m_dwPS;
	ComPtr<ID3D11VertexShader> m_ptrVS;
	ComPtr<ID3D11PixelShader> m_ptrPS;

	// ����D3D�豸
	HRESULT CreateDevice(ComPtr<IDXGIFactory5> &ptrDXGIFactory5);
	// ����˫������
	HRESULT CreateSwapChain(ComPtr<IDXGIFactory5>& ptrDXGIFactory5);
	// ������Ȼ�����
	HRESULT CreateDepthBuffer(int cx, int cy);
	// ����RS��Դ
	HRESULT CreateRSState();
	// ����GPU����
	HRESULT LoadShaders();
	DWORD LoadShader(const wchar_t *shaderFileName, BYTE **ppBuf);
	// �趨����
	HRESULT Set3DSpace();
private:
	// ȫ�����궨��
	ConstantBuffer m_cb;
	// �����Ƶ�Ŀ��
	Box m_box;
	// ���㻺����
	ComPtr<ID3D11Buffer> m_ptrBoxVB;
	// ����������
	ComPtr<ID3D11Buffer> m_ptrBoxIB;
};
