#pragma once
class IShape
{
public:
	//コンストラクタ
	IShape();
	//デストラクタ
	virtual ~IShape();

	virtual void size() = 0;
	virtual void draw() = 0;
};

