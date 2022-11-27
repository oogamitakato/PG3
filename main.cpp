#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <functional>

typedef void (*PFunc)(int*, int*);

//�R�[���o�b�N�֐�
void DisplayResult(int* s, int* num) {
	//���ʂ�\��
	printf("%d! ", *num);
	if (*num % 2 == 0) {
		printf("��!\n");
	}
	else {
		printf("��!\n");
	}

}

void SetTimeOut(PFunc p, int second, int num) {
	//�R�[���o�b�N�֐����Ăяo��
	Sleep(second * 1000);

	p(&second, &num);
}

int main(int argc, const char* argv[])
{
	PFunc p = DisplayResult;
	int diceNum = rand() % 6 + 1;
	int number = 0;

	//�T�C�R���̖ڂ������_���Ɍ��߂�
	srand(time(nullptr));

	//�������������
	printf("�������������\n1...�� 2...��\n");
	scanf_s("%d", &number);

	//�����̉񓚂�\��
	if (number == 1) {
		printf("��:��\n");
	}
	else if (number == 2) {
		printf("��:��\n");
	}
	else {
		printf("��:�Ȃ�\n");
	}

	//���b�ԑ҂�
	printf("������...\n");

	//�����_��
	std::function<void(PFunc,int,int)> result = [=](PFunc p,int num,int second) {	
		SetTimeOut(p, second, num);
		return 0;
	};

	result(p, diceNum, 3);

	//���s����
	if (number % 2 == diceNum % 2) {
		printf("����\n");
	}
	else {
		printf("���s\n");
	}

	return 0;
}