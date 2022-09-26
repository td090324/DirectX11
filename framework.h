#include <windows.h>
#include <math.h>
#include <chrono>

#define ToRadian 0.0174533f

#include "SimpleMath.h"
using namespace DirectX;
using namespace SimpleMath;
using namespace std;

#include "Type.h"
#include "Input.h"
#include "Timer.h"

#include "GameObject.h"
#include "ObRect.h"
#include "ObStar.h"
#include "ObCircle.h"

#include "MainGame.h"

extern HDC g_hdc;
extern HDC g_MemDC;
extern HWND g_hwnd;

#define INPUT Input::GetInstance()
#define TIMER Timer::GetInstance()
#define DELTA Timer::GetInstance()->GetDeltaTime()

#define UP Vector2(0, -1)
#define DOWN Vector2(0, 1)
#define RIGHT Vector2(1, 0)
#define LEFT Vector2(-1, 0)
