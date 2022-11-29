#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int wordCount = 16;

typedef struct cell{
	int val;
	struct cell* prev;
	struct cell* next;
} CELL;

void create(CELL* currentCell, int val);
void deleteCell(CELL* currentCell);
void index(CELL* firstCell);
CELL* getInsertListAddress(CELL *endCELL, int iteretor);

int main()
{
	int operation;
	int iteretor;
	int inputValue;
	CELL* insertCell;

	CELL head;
	head.next = nullptr;
	head.prev = nullptr;

	while (true) {
		printf("[�v�f�̑���]\n");
		printf("1.�}�� 2.�폜");
		scanf_s("%d", &operation);

		if (operation == 1) {
			printf("���Ԗڂ̃Z���̌��ɑ}�����܂���\n");
			scanf_s("%d", &iteretor);

			printf("�}������l����͂��Ă�������\n");
			scanf_s("%d", &inputValue);

			printf("\n");

			//�C�ӂ̃Z���̌��ɒǉ�
			insertCell = getInsertListAddress(&head, iteretor);
			create(insertCell, inputValue);

			//���X�g�ꗗ�̕\��
			printf("���X�g�ꗗ\n");
			index(&head);
			printf("\n");
		}
		else if (operation == 2) {
			printf("���Ԗڂ̃Z���̌��ɑ}�����܂���\n");
			scanf_s("%d", &iteretor);

			printf("\n");
			insertCell = getInsertListAddress(&head, iteretor);
			deleteCell(insertCell);

			//���X�g�ꗗ�̕\��
			printf("���X�g�ꗗ\n");
			//index(&head);
			printf("\n");
		}


	}

	return 0;
}

void create(CELL* currentCell, int val) {
	//�V�K�쐬����Z��
	CELL* newCell;
	//�V�K�쐬����Z�����̃��������m��
	newCell = (CELL*)malloc(sizeof(CELL));
	newCell->val = val;
	newCell->prev = currentCell;
	newCell->next = currentCell->next;

	if (currentCell->next) {
		CELL *nextCell = currentCell->next;
		nextCell->prev = newCell;
	}

	currentCell->next = newCell;

};

void deleteCell(CELL* currentCell) {
	
}

void index(CELL* endCell) {
	int no = 1;
	while (endCell->next != nullptr) {
		endCell = endCell->next;
		printf("%d : ", no);
		printf("%d\n", endCell->val);

		no++;
	}
};

CELL* getInsertListAddress(CELL* endCELL, int iteretor) {
	for (int i = 0; i < iteretor; i++) {
		if (endCELL->next) {
			endCELL = endCELL->next;
		}
		else {
			break;
		}
	}
	return endCELL;
}