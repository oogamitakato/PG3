#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <functional>

typedef void (*PFunc)(int*, int*);

//コールバック関数
void DisplayResult(int* s, int* num) {
	//結果を表示
	printf("%d! ", *num);
	if (*num % 2 == 0) {
		printf("丁!\n");
	}
	else {
		printf("半!\n");
	}

}

void SetTimeOut(PFunc p, int second, int num) {
	//コールバック関数を呼び出す
	Sleep(second * 1000);

	p(&second, &num);
}

int main(int argc, const char* argv[])
{
	PFunc p = DisplayResult;
	int diceNum = rand() % 6 + 1;
	int number = 0;

	//サイコロの目をランダムに決める
	srand(time(nullptr));

	//半か丁かを入力
	printf("半か丁かを入力\n1...半 2...丁\n");
	scanf_s("%d", &number);

	//自分の回答を表示
	if (number == 1) {
		printf("回答:半\n");
	}
	else if (number == 2) {
		printf("回答:丁\n");
	}
	else {
		printf("回答:なし\n");
	}

	//数秒間待つ
	printf("正解は...\n");

	//ラムダ式
	std::function<void(PFunc,int,int)> result = [=](PFunc p,int num,int second) {	
		SetTimeOut(p, second, num);
		return 0;
	};

	result(p, diceNum, 3);

	//勝敗判定
	if (number % 2 == diceNum % 2) {
		printf("成功\n");
	}
	else {
		printf("失敗\n");
	}

	return 0;
}