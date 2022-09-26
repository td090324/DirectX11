#include "framework.h"

MainGame::~MainGame()
{
}

void MainGame::Init()
{
    //MemDc �޸𸮻��� dc�� �ϳ� �� �߰�
    HBITMAP	 m_hOldBitmap, m_hBitmap;
    HDC	hdc = GetDC(g_hwnd); //���� �ڵ�
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
        //���⺤��, ��������
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

    //Ű�� ������ �� wm_paint �� �߻� ���Ѷ�
    InvalidateRect(g_hwnd, NULL, false);
}

void MainGame::Render()
{
    PAINTSTRUCT ps;
    //hdc-> ��ȭ��
    g_hdc = BeginPaint(g_hwnd, &ps);

    //������ ���
    PatBlt(g_MemDC, 0, 0, 800, 600, WHITENESS);

    //�׸��� ����
    MoveToEx(g_MemDC, 0, 0, NULL);
    LineTo(g_MemDC, pos.x, pos.y);

    //��� ���� g_MemDC���� g_hdc��
    BitBlt(g_hdc, 0, 0, 800, 600, g_MemDC, 0, 0, SRCCOPY);

    EndPaint(g_hwnd, &ps);
}
