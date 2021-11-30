#pragma once
class Transform
{
private:
	int m_xPosition;
	int m_yPosition;
public:
	int getXPosition();
	int getYPosition();

	void setPosition(int newXPos, int newYPos);
};

