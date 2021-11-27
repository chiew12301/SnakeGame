#pragma once
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <chrono>

class Time
{
private:
	static Time* _instance; //singletons

	std::chrono::system_clock::time_point _StartTime;
	std::chrono::duration<float> _DeltaTime;
	float _TimeScale;

	Time();

	~Time();

public:
	static Time* Instance();
	static void Release();

	void Reset();

	float DeltaTime();

	void TimeScale(float t = 1.0f); //default is 1.0f

	float TimeScale();

	void Tick();
};


