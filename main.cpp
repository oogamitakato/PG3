#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int stringSize = 16;

typedef struct cell{
	char str[stringSize];
	struct cell* prev;
	struct cell* next;
} CELL;

void create(CELL* currentCell, const char* buf);
void edit(CELL* currentCell, const char* buf);
void deleteCell(CELL* currentCell, int iteretor);
void index(CELL* currentCell);
void specifyIndex(CELL* currentCell,int iteretor);
CELL* getInsertListAddress(CELL *endCELL, int iteretor);

int main()
{
	int operation;
	int display;
	int select = 1;

	int elementNum = 0;
	int iteretor;
	char inputString[stringSize];
	CELL* insertCell;

	CELL head;
	head.next = nullptr;
	head.prev = nullptr;

	while (true) {
		select = 1;

		printf("[要素の操作]\n");
		printf("1.要素の表示\n");
		printf("2.要素の挿入\n");
		printf("3.要素の編集\n");
		printf("4.要素の削除\n");
		printf("\n");
		printf("-----------------------\n");
		printf("操作を選択してください\n");
		scanf_s("%d", &operation);
		printf("\n");

		if (operation == 1) {
			while (select == 1) {
				printf("[要素の表示]\n");
				printf("1.要素の一覧表示\n");
				printf("2.順番を指定して要素を表示\n");
				printf("9.要素操作に戻る\n");
				printf("\n");
				printf("操作を選択してください\n");
				scanf_s("%d", &display);
				printf("\n");

				if (display == 1) {
					//リスト一覧の表示
					printf("[要素の一覧表示]\n");
					index(&head);
					printf("\n");
					printf("-----------------------\n");
				}
				if (display == 2) {
					printf("[番号を指定して要素を表示]\n");
					printf("表示したい要素の番号を指定してください\n");
					scanf_s("%d", &iteretor);
					printf("\n");

					if (iteretor <= 0) {
						printf("無効な値です\n");
					}
					else if (iteretor <= elementNum) {
						insertCell = getInsertListAddress(&head, iteretor);
						specifyIndex(insertCell, iteretor);
					}
					else {
						printf("%d番目の要素が見つかりませんでした\n", iteretor);
					}

					printf("\n");
				}
				else if (display == 9) {
					break;
				}

				printf("1.要素の表示に戻る\n");
				printf("2.要素の操作に戻る\n");
				printf("\n");
				scanf_s("%d", &select);
				printf("\n");

				if (select != 1) {
					break;
				}

			}
		}
		else if (operation == 2) {
			printf("要素を追加する場所を指定してください\n");
			printf("最後尾に追加する場合は、要素数以上の値を入力してください\n");
			printf("要素数 : %d\n", elementNum);
			scanf_s("%d", &iteretor);
			printf("\n");

			if (iteretor <= 0) {
				printf("無効な値です\n");
			}
			else {
				printf("追加する要素の値を入力してください\n");
				scanf_s("%s", &inputString, stringSize);
				printf("\n");

				//任意のセルの後ろに追加
				insertCell = getInsertListAddress(&head, iteretor);
				create(insertCell, inputString);
				if (iteretor < elementNum) {
					printf("要素[%s]が%d番目の後ろに挿入されました\n", inputString, iteretor);
				}
				else {
					printf("要素[%s]が最後尾に挿入されました\n", inputString);
				}
				elementNum++;
			}

			printf("\n");
		}
		else if (operation == 3) {
			printf("[要素の編集]\n");
			printf("編集したい要素の番号を指定してください\n");
			scanf_s("%d", &iteretor);
			printf("\n");

			if (iteretor <= 0) {
				printf("無効な値です\n");
			}
			else if (iteretor < elementNum) {
				printf("%d番目の要素の変更する値を入力してください\n", iteretor);
				scanf_s("%s", &inputString, stringSize);
				printf("\n");

				insertCell = getInsertListAddress(&head, iteretor);
				edit(insertCell, inputString);
				printf("%d番目の要素が[%s]に変更されました\n", iteretor, inputString);
			}
			else {
				printf("%d番目の要素が見つかりませんでした\n", iteretor);
			}
	
			printf("\n");
		}
		else if (operation == 4) {
			printf("削除したい要素の番号を指定してください\n");
			scanf_s("%d", &iteretor);
			printf("\n");

			//指定した番号の要素を削除
			if (iteretor <= 0) {
				printf("無効な値です\n");
			}
			else if (iteretor <= elementNum) {
				deleteCell(&head, iteretor);
				printf("\n");

				printf("%d番目の要素を削除しました\n", iteretor);
				elementNum--;
			}
			else {
				printf("%d番目の要素が見つかりませんでした\n", iteretor);
			}
		
			printf("\n");
		}
		else {
			printf("エラー\n");
			break;
		}
	}

	return 0;
}

void create(CELL* currentCell, const char *buf) {
	//新規作成するセル
	CELL* newCell;
	//新規作成するセル分のメモリを確保
	newCell = (CELL*)malloc(sizeof(CELL));
	strcpy_s(newCell->str, stringSize, buf);
	newCell->prev = currentCell;
	newCell->next = currentCell->next;

	if (currentCell->next) {
		CELL *nextCell = currentCell->next;
		nextCell->prev = newCell;
	}

	currentCell->next = newCell;

};

void edit(CELL* currentCell, const char* buf) {
	//任意の要素の値を変更
	strcpy_s(currentCell->str, stringSize, buf);
}

void deleteCell(CELL* currentCell, int iteretor) {
	CELL * insertCell = getInsertListAddress(currentCell, iteretor);
	CELL * insertCellPrev = getInsertListAddress(currentCell, iteretor - 1);
	CELL * insertCellNext = getInsertListAddress(currentCell, iteretor + 1);

	if (insertCell->next != nullptr) {
		insertCellPrev->next = insertCellNext;
		insertCellNext->prev = insertCellPrev;
	}
	else {
		insertCellPrev->next = nullptr;
	}

}

void index(CELL* currentCell) {
	int no = 0;

	printf("要素一覧 : {\n");
	while (currentCell->next != nullptr) {
		currentCell = currentCell->next;
		printf("  %d(%d番目) : ",no, no + 1);
		printf("%s\n", currentCell->str);

		no++;
	}
	printf("}\n");
	printf("\n");
	printf("要素数 : %d\n", no);

};

void specifyIndex(CELL* currentCell, int iteretor) {

	int no = 0;
	for (int i = 0; i < iteretor; i++) {
		no++;
	}
	printf("%d(%d番目) : ", no - 1, no);
	printf("%s\n", currentCell->str);
}

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