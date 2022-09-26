#include "framework.h"

MainGame::~MainGame()
{
}

void MainGame::Init()
{
    //MemDc 메모리상의 dc를 하나 더 추가
    HBITMAP	 m_hOldBitmap, m_hBitmap;
    HDC	hdc = GetDC(g_hwnd); //기존 핸들
    g_MemDC = CreateCompatibleDC(hdc);
    m_hBitmap = CreateCompatibleBitmap(hdc, 800, 600);
    m_hOldBitmap = (HBITMAP)SelectObject(g_MemDC, m_hBitmap);
    ReleaseDC(g_hwnd, hdc);

    pos.x = 400.0f;
    pos.y = 300.0f;
}

void MainGame::Update()
{
    if (INPUT->KeyPress(VK_UP))
    {
        //방향벡터, 단위벡터
        pos += UP * 200.0f * DELTA;
    }
    if (INPUT->KeyPress(VK_DOWN))
    {
        pos += DOWN * 200.0f * DELTA;
    }
    if (INPUT->KeyPress(VK_LEFT))
    {
        pos += LEFT * 200.0f * DELTA;
    }
    if (INPUT->KeyPress(VK_RIGHT))
    {
        pos += RIGHT * 200.0f * DELTA;
    }

    //키가 눌렸을 때 wm_paint 를 발생 시켜라
    InvalidateRect(g_hwnd, NULL, false);
}

void MainGame::Render()
{
    PAINTSTRUCT ps;
    //hdc-> 도화지
    g_hdc = BeginPaint(g_hwnd, &ps);

    //바탕색 깔기
    PatBlt(g_MemDC, 0, 0, 800, 600, WHITENESS);

    //그리는 공간
    MoveToEx(g_MemDC, 0, 0, NULL);
    LineTo(g_MemDC, pos.x, pos.y);

    //고속 복사 g_MemDC에서 g_hdc로
    BitBlt(g_hdc, 0, 0, 800, 600, g_MemDC, 0, 0, SRCCOPY);

    EndPaint(g_hwnd, &ps);
}
