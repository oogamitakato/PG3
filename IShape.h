#pragma once
class IShape
{
public:
	//�R���X�g���N�^
	IShape();
	//�f�X�g���N�^
	virtual ~IShape();

	virtual void size() = 0;
	virtual void draw() = 0;
};

