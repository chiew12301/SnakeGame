#include "Air.h"

Air::Air(int startxPos, int startyPos, int bWidth, int bHeight) : Food(startxPos, startyPos, bWidth, bHeight)
{
	m_Symbol = '@';
}

void Air::Update()
{
	//if there's any feature update could be added
}
