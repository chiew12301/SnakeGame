#include "Air.h"

Air::Air(int startxPos, int startyPos, int bWidth, int bHeight) : Food(startxPos, startyPos, bWidth, bHeight)
{
	m_Symbol = '@';
	m_food_Score = 1;
}

void Air::Update()
{
	//if there's any feature update could be added
}
