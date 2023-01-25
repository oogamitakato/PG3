#pragma once
#include "IShape.h"

class Rectangle : public IShape
{
public:
	void size() override;
	void draw() override;
};

