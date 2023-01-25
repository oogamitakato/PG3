#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <functional>

typedef void (*PFunc)( int*);

//�R�[���o�b�N�֐�
void DisplayResult(int* num) {
	//���ʂ�\��
	printf("%d! ", *num);
	if (*num % 2 == 0) {
		printf("��!\n");
	}
	else {
		printf("��!\n");
	}
}

int main(int argc, const char* argv[])
{
	while (true)
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
		std::function<void(int, int)> SetTimeOut = [=](int num, int second) {
			//�R�[���o�b�N�֐����Ăяo��
			Sleep(second * 1000);

			p(&num);

			return 0;
		};

		SetTimeOut(diceNum, 3);

		//���s����
		if (number % 2 == diceNum % 2) {
			printf("����\n");
		}
		else {
			printf("���s\n");
		}

		printf("\n");
	}


	return 0;
}