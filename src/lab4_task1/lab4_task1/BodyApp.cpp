#include "stdafx.h"
#include "ShapeBox.h"
#include "CBody.h"
#include "BodyConstructor.h"

int main()
{
	BodyConstructor bodyConstructor;
	ShapeBox shapeBox(bodyConstructor);
	
	shapeBox.Init();
	return 0;
}
