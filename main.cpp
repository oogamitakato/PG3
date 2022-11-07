#include <stdio.h>
#include <stdlib.h>

typedef struct cell{
	int val;
	struct cell* next;
} CELL;

void create(CELL *firstCell, int insertVal){
	//新規作成するセル
	CELL* cell;
	//新規作成するセル分のメモリを確保
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

		//最後尾にセルを追加
		create(&head, val);

		//リスト一覧の表示
		index(&head);

		count++;
	}

	return 0;
}