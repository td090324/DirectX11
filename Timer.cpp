#include "framework.h"

Timer::Timer()
{
    //���� �ð� ����
    lastTime = chrono::steady_clock::now();

    deltaTime = 0.0f;
    WorldTime = 0.0f;
    FPS = 0;
    FPSCount = 0;
    FPSTimeElapsed = 0.0f;
}

void Timer::Chronometry(UINT lock)
{
    currentTime = chrono::steady_clock::now();
    chrono::duration<double> Delta = currentTime - lastTime;
    deltaTime = (float)Delta.count();

    //��Ÿ�� 1/60���� �۴ٸ�
    while (deltaTime < (1.0f / lock))
    {
        //����ð��� �ٽ�����
        currentTime = chrono::steady_clock::now();
        //��Ÿ�� �ٽ� ���
        Delta = currentTime - lastTime;
        deltaTime = (float)Delta.count();
    }

    //������ �ð��� ���
    lastTime = currentTime;

    //��ü �ð� ������� ����
    WorldTime += deltaTime;

    //1�ʸ� ����ִ� ����
    FPSTimeElapsed += deltaTime;

    FPSCount++;
    //FPSTimeElapsed �� 1�ʰ� �Ѿ�����
    if (FPSTimeElapsed > 1.0f)
    {
        FPS = FPSCount;
        FPSCount = 0;
        FPSTimeElapsed = 0.0f;
    }
}
