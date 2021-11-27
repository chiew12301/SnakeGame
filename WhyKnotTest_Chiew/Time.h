#pragma once
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

class Time
{
public:
	static float GetTime();
	static float GetUnscaledTime();

	static float GetDeltaTime();
	static float GetUnscaledDeltaTime();

	static float GetTimeScale();
	static void SetTimeScale(const float& timeScale);

	static void MeasureTime(const float& minFrameDt);

private:
	static float mTimeScale;
	static float mRealTime;
	static float mTime;
	static float mDeltaTime;
	static float mUnscaledDeltaTime;
	static float mAccumulatedRealDeltaTime;
};
