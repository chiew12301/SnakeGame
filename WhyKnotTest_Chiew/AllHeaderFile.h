#pragma once
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <string>

//Color List
/*1:Blue
2:Green
3:Cyan
4:Red
5:Purple
6:Yellow (Dark)
7:Default white
8:Gray
9:Bright Blue
10:Bright Green
11:Bright Cyan
12:Bright Red
13:Pink/Magenta
14:Yellow
15:Bright White
Numbers after 15 are background colors
*/

//Below are game file
#include "GameSystem.h"
#include "Time.h"
#include "Transform.h"
#include "ObjectCreation.h"

//Board Class
#include "Board.h"
#include "DiamondBoard.h"
#include "DefaultBoard.h"

//FoodClass
#include "Food.h"
#include "AirFood.h"
#include "OakFood.h"
#include "HashFood.h"

//SnakeClass
#include "Snake.h"
#include "AirSnake.h"
#include "OakSnake.h"
#include "HashSnake.h"

//ExtraObject
#include "InnerWall.h"

using namespace std;