#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int wordCount = 16;

typedef struct cell{
	char str[wordCount];
	int loanDate;
	int returnDate;
	struct cell* next;
} CELL;

void create(CELL *endCell, const char *buf, int ldate, int rdate){
	//�V�K�쐬����Z��
	CELL* newCell;
	//�V�K�쐬����Z�����̃��������m��
	newCell = (CELL*)malloc(sizeof(CELL));

	strcpy_s(newCell->str, wordCount, buf);
	newCell->loanDate = ldate;
	newCell->returnDate = rdate;
	newCell->next = nullptr;

	while (endCell->next != nullptr) {
		endCell = endCell->next;
	}

	endCell->next = newCell;

};

void index(CELL *firstCell) {
	while (firstCell->next != nullptr) {
		firstCell = firstCell->next;
		printf("%s,%d,%d\n", firstCell->str,firstCell->loanDate,firstCell->returnDate);
	}
	printf("\n");
};

int main()
{
	char str[wordCount];
	int loanDtae = 0;
	int returnDtae = 0;
	int count = 0;

	CELL head;
	head.next = nullptr;

	while (true) {
		printf("���� : ");
		scanf_s("%s", str, wordCount);
		printf("�ݏo�� : ");
		scanf_s("%d", &loanDtae);
		printf("�ԋp�� : ");
		scanf_s("%d", &returnDtae);
		printf("\n");

		//�Ō���ɃZ����ǉ�
		create(&head, str, loanDtae, loanDtae);
		//���X�g�ꗗ�̕\��
		printf("���X�g�ꗗ\n");
		index(&head);
		printf("\n");

		count++;
	}

	return 0;
}