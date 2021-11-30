#include "Hash.h"

Hash::Hash(int startxPos, int startyPos, int bWidth, int bHeight) : Food(startxPos, startyPos, bWidth, bHeight)
{
	m_Symbol = '#';
	m_food_Score = 5;
}

void Hash::Update()
{
	//if there's any feature update could be added
}
