#pragma once
#include "AllHeaderFile.h"

class Air : public Food
{
public:
	Air(int startxPos, int startyPos, int bWidth, int bHeight);
	void Update();
};

