# Basic Drawing
![pentangle](http://ic-media.oss-cn-hangzhou.aliyuncs.com/2016%2F03%2Fpentangle.png)

## DeviceContext
    - ����ϵ
	- ���� ǰ��ɫ ����ɫ
	- ����
	- ��ˢ

## ����ϵ
+ SetMapMode SetViewportOrgEx SetWindowExtEx SetViewportExtEx
	- **MM_TEXT** 1��λ��1�����ص㣬X���������ң�Y����������
	- **MM_LOMETRIC** 1��λ��0.1���ף�X���������ң�Y����������
	- **MM_HIMETRIC** 1��λ��0.01���ף�X���������ң�Y����������
	- **MM_ISOTROPIC** X���Y���1��λ������ͬ�������Զ��壬1��λ��������Զ���
	- **MM_ANISOTROPIC** X���Y�������ȫ�����趨

## ������ͼAPI
    - �㣺 SetPixel GetPixel
	- ֱ�ߣ� MoveTo LineTo
	- ���ƽ��ͼ�Σ� Rectangle Ellipse RoundRect Chord Pie Polygon
