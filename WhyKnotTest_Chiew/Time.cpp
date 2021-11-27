#include "Time.h"

float Time::mTimeScale                = 1.0f;
float Time::mRealTime                 = 0.0f;
float Time::mTime                     = 0.0f;
float Time::mDeltaTime                = 0.0f;
float Time::mUnscaledDeltaTime        = 0.0f;
float Time::mAccumulatedRealDeltaTime = 0.0f;

float Time::GetTime()
{
    return mTime;
}

float Time::GetUnscaledTime()
{
    return mRealTime;
}

float Time::GetDeltaTime()
{
    return mDeltaTime;
}

float Time::GetUnscaledDeltaTime()
{
    return mUnscaledDeltaTime;
}

float Time::GetTimeScale()
{
    return mTimeScale;
}

void Time::SetTimeScale(const float& timeScale)
{
    mTimeScale = timeScale;
}

void Time::MeasureTime(const float& minFrameDt)
{
    mAccumulatedRealDeltaTime = 0.0f;
    while (mAccumulatedRealDeltaTime <= minFrameDt)
    {
        const float newRealTime = clock();
        mUnscaledDeltaTime = newRealTime - mRealTime;
        mRealTime = newRealTime;
        mAccumulatedRealDeltaTime += mUnscaledDeltaTime;
    }
    
    mDeltaTime = mAccumulatedRealDeltaTime * mTimeScale;
    mTime += mDeltaTime;
}


