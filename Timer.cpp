#include "framework.h"

Timer::Timer()
{
    //현재 시간 측정
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

    //델타가 1/60보다 작다면
    while (deltaTime < (1.0f / lock))
    {
        //현재시간을 다시측정
        currentTime = chrono::steady_clock::now();
        //델타를 다시 계산
        Delta = currentTime - lastTime;
        deltaTime = (float)Delta.count();
    }

    //마지막 시간을 기록
    lastTime = currentTime;

    //전체 시간 경과량을 연산
    WorldTime += deltaTime;

    //1초를 잡아주는 변수
    FPSTimeElapsed += deltaTime;

    FPSCount++;
    //FPSTimeElapsed 이 1초가 넘었을때
    if (FPSTimeElapsed > 1.0f)
    {
        FPS = FPSCount;
        FPSCount = 0;
        FPSTimeElapsed = 0.0f;
    }
}
