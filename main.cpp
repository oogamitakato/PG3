#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <functional>

int main(int argc, const char* argv[])
{
	//�T�C�R���̖ڂ������_���Ɍ��߂�
	srand(time(nullptr));
	int diceNum = rand() % 6 + 1;

	//�������������
	int number = 0;
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
	std::function<int(int)> fx = [=](int s) {
		//���b�҂�
		Sleep(s * 1000);

		//���ʂ�\��
		printf("%d! ", diceNum);
		if (diceNum % 2 == 0) {
			printf("��!\n");
		}
		else {
			printf("��!\n");
		}

		return 0;
	};

	fx(3);

	//���s����
	if (number % 2 == diceNum % 2) {
		printf("����\n");
	}
	else {
		printf("���s\n");
	}

	return 0;
}