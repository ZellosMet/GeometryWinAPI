#include<windows.h>
#include<tchar.h>
#include<HeadGeometry.h>

static TCHAR szWindowClass[] = _T("GeometryDesktopApp"); // Задание имени приложения
static TCHAR szTitle[] = _T("Geometry"); // Текст заголовка окна
LRESULT CALLBACK WndProc(_In_ HWND hWnd, _In_ UINT message, _In_ WPARAM wParam, _In_ LPARAM lParam); // Функция обработки процессов

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCMDLine, _In_ int nCmdShow) //Точка входа WinAPI
{
	
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX); //Определяет размер структуры в байтах
	wcex.style = CS_HREDRAW | CS_VREDRAW; //Задание стиля классов
	wcex.lpfnWndProc = WndProc; //Указатель на процедуру окна
	wcex.cbClsExtra = 0; //Выделение дополнительной памяти в байтах в соответствии со структурой окна 
	wcex.cbWndExtra = 0; //Выделение дополнитеельной памяти в байтах после экземпляра окна
	wcex.hInstance = hInstance; //Дескриптор экземпляра окна
	wcex.hIcon = LoadIcon(wcex.hInstance, IDI_APPLICATION); //Значёк для окна
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW); //Курсор для окна
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1); //Задание заливки окна
	wcex.lpszMenuName = NULL; //Указание на меню окна(NULL - нет меню поумолчанию)
	wcex.lpszClassName = szWindowClass; //Имя класса окна(не больше 256 символов)
	wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION); //Дескриптор небольшого значка окна

	if (!RegisterClassExW(&wcex))
	{
		MessageBox(NULL, _T("Call to RegisterClassExW failed!"), _T("Windows Desktop Guided Tour"), NULL);
		return 1;
	}
	//Создание окна
	HWND hWnd = CreateWindowEx
	(
		WS_EX_OVERLAPPEDWINDOW, //Параметр расширенного стяли окна(не обязателен)
		szWindowClass, //Имя приложения
		szTitle, //Текст отображаемый в строке заголовка окна
		WS_OVERLAPPEDWINDOW, //Тип создаваемого окна
		CW_USEDEFAULT, //Начальная позиция окна по Х
		CW_USEDEFAULT, //Начальная позиция по Y
		1000, //Штрина окна
		600, //Длина окна
		NULL, //Родитель окна данного окна
		NULL, //Строка меню окна( NULL - не имеет)
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
	case WM_PAINT: // Кейс перерисовки окна при перемещении или изменении положения относительно других окан
		hdc = BeginPaint(hWnd, &ps);
		//TextOut(hdc, 5, 5, greeting, _tcslen(greeting));
		circle.get_draw(hWnd);
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY: //Кейс для закрытия окна
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}
	return 0;
}