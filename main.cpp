#include <stdio.h>
#include <stdlib.h>

typedef struct cell{
	int val;
	struct cell* next;
} CELL;

void create(CELL *firstCell, int insertVal){
	//�V�K�쐬����Z��
	CELL* cell;
	//�V�K�쐬����Z�����̃��������m��
	cell = (CELL*)malloc(sizeof(CELL));

	cell->val = insertVal;
	cell->next = nullptr;

	while (firstCell->next != nullptr) {
		firstCell = firstCell->next;
	}

	firstCell = cell;

};

void index(CELL *firstCell) {
	while (firstCell->next != nullptr) {
		firstCell = firstCell->next;
		printf("%d\n", firstCell->val);
	}
};

int main()
{
	int val;
	int count = 0;

	CELL head;
	head.next = nullptr;

	while (count < 5) {
		scanf_s("%d", &val);

		//�Ō���ɃZ����ǉ�
		create(&head, val);

		//���X�g�ꗗ�̕\��
		index(&head);

		count++;
	}

	return 0;
}