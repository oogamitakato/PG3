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

		printf("[�v�f�̑���]\n");
		printf("1.�v�f�̕\��\n");
		printf("2.�v�f�̑}��\n");
		printf("3.�v�f�̕ҏW\n");
		printf("4.�v�f�̍폜\n");
		printf("\n");
		printf("-----------------------\n");
		printf("�����I�����Ă�������\n");
		scanf_s("%d", &operation);
		printf("\n");

		if (operation == 1) {
			while (select == 1) {
				printf("[�v�f�̕\��]\n");
				printf("1.�v�f�̈ꗗ�\��\n");
				printf("2.���Ԃ��w�肵�ėv�f��\��\n");
				printf("9.�v�f����ɖ߂�\n");
				printf("\n");
				printf("�����I�����Ă�������\n");
				scanf_s("%d", &display);
				printf("\n");

				if (display == 1) {
					//���X�g�ꗗ�̕\��
					printf("[�v�f�̈ꗗ�\��]\n");
					index(&head);
					printf("\n");
					printf("-----------------------\n");
				}
				if (display == 2) {
					printf("[�ԍ����w�肵�ėv�f��\��]\n");
					printf("�\���������v�f�̔ԍ����w�肵�Ă�������\n");
					scanf_s("%d", &iteretor);
					printf("\n");

					if (iteretor <= 0) {
						printf("�����Ȓl�ł�\n");
					}
					else if (iteretor <= elementNum) {
						insertCell = getInsertListAddress(&head, iteretor);
						specifyIndex(insertCell, iteretor);
					}
					else {
						printf("%d�Ԗڂ̗v�f��������܂���ł���\n", iteretor);
					}

					printf("\n");
				}
				else if (display == 9) {
					break;
				}

				printf("1.�v�f�̕\���ɖ߂�\n");
				printf("2.�v�f�̑���ɖ߂�\n");
				printf("\n");
				scanf_s("%d", &select);
				printf("\n");

				if (select != 1) {
					break;
				}

			}
		}
		else if (operation == 2) {
			printf("�v�f��ǉ�����ꏊ���w�肵�Ă�������\n");
			printf("�Ō���ɒǉ�����ꍇ�́A�v�f���ȏ�̒l����͂��Ă�������\n");
			printf("�v�f�� : %d\n", elementNum);
			scanf_s("%d", &iteretor);
			printf("\n");

			if (iteretor <= 0) {
				printf("�����Ȓl�ł�\n");
			}
			else {
				printf("�ǉ�����v�f�̒l����͂��Ă�������\n");
				scanf_s("%s", &inputString, stringSize);
				printf("\n");

				//�C�ӂ̃Z���̌��ɒǉ�
				insertCell = getInsertListAddress(&head, iteretor);
				create(insertCell, inputString);
				if (iteretor < elementNum) {
					printf("�v�f[%s]��%d�Ԗڂ̌��ɑ}������܂���\n", inputString, iteretor);
				}
				else {
					printf("�v�f[%s]���Ō���ɑ}������܂���\n", inputString);
				}
				elementNum++;
			}

			printf("\n");
		}
		else if (operation == 3) {
			printf("[�v�f�̕ҏW]\n");
			printf("�ҏW�������v�f�̔ԍ����w�肵�Ă�������\n");
			scanf_s("%d", &iteretor);
			printf("\n");

			if (iteretor <= 0) {
				printf("�����Ȓl�ł�\n");
			}
			else if (iteretor < elementNum) {
				printf("%d�Ԗڂ̗v�f�̕ύX����l����͂��Ă�������\n", iteretor);
				scanf_s("%s", &inputString, stringSize);
				printf("\n");

				insertCell = getInsertListAddress(&head, iteretor);
				edit(insertCell, inputString);
				printf("%d�Ԗڂ̗v�f��[%s]�ɕύX����܂���\n", iteretor, inputString);
			}
			else {
				printf("%d�Ԗڂ̗v�f��������܂���ł���\n", iteretor);
			}
	
			printf("\n");
		}
		else if (operation == 4) {
			printf("�폜�������v�f�̔ԍ����w�肵�Ă�������\n");
			scanf_s("%d", &iteretor);
			printf("\n");

			//�w�肵���ԍ��̗v�f���폜
			if (iteretor <= 0) {
				printf("�����Ȓl�ł�\n");
			}
			else if (iteretor <= elementNum) {
				deleteCell(&head, iteretor);
				printf("\n");

				printf("%d�Ԗڂ̗v�f���폜���܂���\n", iteretor);
				elementNum--;
			}
			else {
				printf("%d�Ԗڂ̗v�f��������܂���ł���\n", iteretor);
			}
		
			printf("\n");
		}
		else {
			printf("�G���[\n");
			break;
		}
	}

	return 0;
}

void create(CELL* currentCell, const char *buf) {
	//�V�K�쐬����Z��
	CELL* newCell;
	//�V�K�쐬����Z�����̃��������m��
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
	//�C�ӂ̗v�f�̒l��ύX
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

	printf("�v�f�ꗗ : {\n");
	while (currentCell->next != nullptr) {
		currentCell = currentCell->next;
		printf("  %d(%d�Ԗ�) : ",no, no + 1);
		printf("%s\n", currentCell->str);

		no++;
	}
	printf("}\n");
	printf("\n");
	printf("�v�f�� : %d\n", no);

};

void specifyIndex(CELL* currentCell, int iteretor) {

	int no = 0;
	for (int i = 0; i < iteretor; i++) {
		no++;
	}
	printf("%d(%d�Ԗ�) : ", no - 1, no);
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