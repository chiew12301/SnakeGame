#include "Time.h"

Time* Time::_instance = nullptr;

Time::Time()
{
	Reset();
	this->_TimeScale = 1.0f;
	this->_DeltaTime = std::chrono::duration<float>(0.0f);
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
	this->_StartTime = std::chrono::system_clock::now();
}

float Time::DeltaTime()
{
	return this->_DeltaTime.count();
}

void Time::TimeScale(float t)
{
	this->_TimeScale = t;
}

float Time::TimeScale()
{
	return this->_TimeScale;
}

void Time::Tick()
{
	this->_DeltaTime = std::chrono::system_clock::now() - this->_StartTime;
}
