#include<windows.h>
#include<tchar.h>
#include<HeadGeometry.h>

static TCHAR szWindowClass[] = _T("GeometryDesktopApp"); // ������� ����� ����������
static TCHAR szTitle[] = _T("Geometry"); // ����� ��������� ����
LRESULT CALLBACK WndProc(_In_ HWND hWnd, _In_ UINT message, _In_ WPARAM wParam, _In_ LPARAM lParam); // ������� ��������� ���������

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCMDLine, _In_ int nCmdShow) //����� ����� WinAPI
{
	
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX); //���������� ������ ��������� � ������
	wcex.style = CS_HREDRAW | CS_VREDRAW; //������� ����� �������
	wcex.lpfnWndProc = WndProc; //��������� �� ��������� ����
	wcex.cbClsExtra = 0; //��������� �������������� ������ � ������ � ������������ �� ���������� ���� 
	wcex.cbWndExtra = 0; //��������� ��������������� ������ � ������ ����� ���������� ����
	wcex.hInstance = hInstance; //���������� ���������� ����
	wcex.hIcon = LoadIcon(wcex.hInstance, IDI_APPLICATION); //������ ��� ����
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW); //������ ��� ����
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1); //������� ������� ����
	wcex.lpszMenuName = NULL; //�������� �� ���� ����(NULL - ��� ���� �����������)
	wcex.lpszClassName = szWindowClass; //��� ������ ����(�� ������ 256 ��������)
	wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION); //���������� ���������� ������ ����

	if (!RegisterClassExW(&wcex))
	{
		MessageBox(NULL, _T("Call to RegisterClassExW failed!"), _T("Windows Desktop Guided Tour"), NULL);
		return 1;
	}
	//�������� ����
	HWND hWnd = CreateWindowEx
	(
		WS_EX_OVERLAPPEDWINDOW, //�������� ������������ ����� ����(�� ����������)
		szWindowClass, //��� ����������
		szTitle, //����� ������������ � ������ ��������� ����
		WS_OVERLAPPEDWINDOW, //��� ������������ ����
		CW_USEDEFAULT, //��������� ������� ���� �� �
		CW_USEDEFAULT, //��������� ������� �� Y
		1000, //������ ����
		600, //����� ����
		NULL, //�������� ���� ������� ����
		NULL, //������ ���� ����( NULL - �� �����)
		hInstance, 
		NULL
	);
	if (!hWnd)
	{
		MessageBox(NULL, _T("Call to CreateWindowEx faliled!"),
			_T("Windows Desktop Guided Tour"), NULL);
		return 1;
	}
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(_In_ HWND hWnd, _In_ UINT message, _In_ WPARAM wParam, _In_ LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	TCHAR greeting[] = _T("Hello, Windows desktop!");
	Geometry::Circle circle(60, 1000, 1000, 5, Geometry::Color::red);
	switch (message)
	{
	case WM_PAINT: // ���� ����������� ���� ��� ����������� ��� ��������� ��������� ������������ ������ ����
		hdc = BeginPaint(hWnd, &ps);
		//TextOut(hdc, 5, 5, greeting, _tcslen(greeting));
		circle.get_draw(hWnd);
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY: //���� ��� �������� ����
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}
	return 0;
}