﻿// WindowsProject1.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "WindowsProject1.h"

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINDOWSPROJECT1, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJECT1));

    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT1));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINDOWSPROJECT1);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//




void Сrown(HDC hdc, int cx, int cy, int sizeX, int sizeY, COLORREF color) {

    POINT p[] = {
        cx,		cy - sizeY,
        cx + sizeX / 2,	cy,
        cx + sizeX,	cy - sizeY,
        cx + sizeX,	cy + sizeY,
        cx - sizeX,	cy + sizeY,
        cx - sizeX,	cy - sizeY,
        cx - sizeX / 2,	cy,
        cx,		cy - sizeY
    };

    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 3, color);
    SelectObject(hdc, hPen);
    Polyline(hdc, p, 8);
    DeleteObject(hPen);
}

void Thing(HDC hdc, int cx, int cy, int sizeX, int sizeY, COLORREF color) {

    POINT p[] = {
        cx,		cy/2 - sizeY,
        cx + sizeX * 2,	cy/2,
        cx + sizeX,	cy - sizeY,
        cx + sizeX,	cy + sizeY,
        cx - sizeX,	cy + sizeY,
        cx - sizeX,	cy - sizeY,
        cx - sizeX * 2,	cy/2,
        cx,		cy/2 - sizeY
    };

    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 3, color);
    SelectObject(hdc, hPen);
    Polyline(hdc, p, 8);
    DeleteObject(hPen);
}

void BlockCrown(HDC hdc) {
    int r = 0;
    int g = 0;
    int b = 0;

    int y = 50;
    int sizeY = 10;

    while (y < 400) {
        int x = 50;
        int sizeX = 10;
        g = 0;
        while (x < 900) {
            Сrown(hdc, x, y, sizeX, sizeY, RGB(r, g, b));
            x += 100;
            sizeX += 5;
            g += 30;
        }
        y += 100;
        sizeY += 10;
        r += 80;
    }
}

void BlockThing(HDC hdc) {
    int r = 0;
    int g = 0;
    int b = 0;

    int y = 50;
    int sizeY = 10;

    while (y < 400) {
        int x = 50;
        int sizeX = 10;
        g = 0;
        while (x < 900) {
            Thing(hdc, x, y, sizeX, sizeY, RGB(r, g, b));
            x += 100;
            sizeX += 5;
            g += 30;
        }
        y += 100;
        sizeY += 1;
        r += 80;
    }
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Разобрать выбор в меню:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            int r = 0;
            int g = 0;
            int b = 0;

            int y = 50;
            int sizeY = 30;
            int x = 50;
            int sizeX = 10;

            /*while (x <= 900) {
                Сrown(hdc, x, y, sizeX, sizeY, RGB(r, g, b));
                g += 22;
                x += 100;
                sizeX += 5;
            }*/
            /*while (y <= 900) {
                Сrown(hdc, x, y, sizeX, sizeY, RGB(r, g, b));
                r += 20;

                y += 100;
                sizeX += 5;
            }*/

            /*while (x <= 900) {
                Сrown(hdc, x, y, sizeX, sizeY, RGB(r, g, b));
                r += 20;
                b += 10;
                y += 100;
                sizeX += 5;
                sizeY += 5;
                x += 100;
                y += 50;
            }*/

            //BlockCrown(hdc);


            y += 20;
            // Thing(hdc, x, y, sizeX, sizeY, RGB(10, 100, 200));
            /*while (x <= 1000) {
                Thing(hdc, x, y, sizeX, sizeY, RGB(r, g, b));
                g += 22;
                x += 200;
                sizeX += 5;
            }*/

            /*while (y <= 900) {
                Thing(hdc, x, y, sizeX, sizeY, RGB(r, g, b));
                r += 20;
                y += 100;
                sizeY += 1;
            }*/

            /*while (x <= 900) {
                Thing(hdc, x, y, sizeX, sizeY, RGB(r, g, b));
                r += 20;
                b += 10;
                y += 100;
                sizeX += 5;
                sizeY += 1;
                x += 100;
                y += 50;
            }*/

           BlockThing(hdc);
            





            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
