#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IShape.h"
#include "Circle.h"
#include "Rectangle.h"

int main()
{
	IShape* iShape[3];

	//�C���X�^���X����
	for (int i = 0; i < 2; i++) {
		if (i < 1) {
			iShape[i] = new Rectangle;
		}
		else {
			iShape[i] = new Circle;
		}
	}

	//�֐��Ăяo��
	for (int i = 0; i < 2; i++) {
		iShape[i]->size();
		iShape[i]->draw();
		printf("\n");
	}

	return 0;
}