#pragma once
#include "IShape.h"
class Circle : public IShape
{
public:
	void size() override;
	void draw() override;
};

