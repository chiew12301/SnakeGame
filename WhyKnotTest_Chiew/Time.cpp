#include "Time.h"

Time* Time::_instance = nullptr;

Time::Time()
{
	Reset();
	_TimeScale = 1.0f;
	_DeltaTime = std::chrono::duration<float>(0.0f);
}

Time::~Time()
{

}

Time* Time::Instance()
{
	if (_instance == nullptr)
	{
		_instance = new Time();
	}
	return _instance;
}

void Time::Release()
{
	delete _instance;
	_instance = nullptr;
}

void Time::Reset()
{
	_StartTime = std::chrono::system_clock::now();
}

float Time::DeltaTime()
{
	return _DeltaTime.count();
}

void Time::TimeScale(float t)
{
	_TimeScale = t;
}

float Time::TimeScale()
{
	return _TimeScale;
}

void Time::Tick()
{
	_DeltaTime = std::chrono::system_clock::now() - _StartTime;
}
