#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <functional>

int main(int argc, const char* argv[])
{
	//サイコロの目をランダムに決める
	srand(time(nullptr));
	int diceNum = rand() % 6 + 1;

	//半か丁かを入力
	int number = 0;
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
	std::function<int(int)> fx = [=](int s) {
		//数秒待つ
		Sleep(s * 1000);

		//結果を表示
		printf("%d! ", diceNum);
		if (diceNum % 2 == 0) {
			printf("丁!\n");
		}
		else {
			printf("半!\n");
		}

		return 0;
	};

	fx(3);

	//勝敗判定
	if (number % 2 == diceNum % 2) {
		printf("成功\n");
	}
	else {
		printf("失敗\n");
	}

	return 0;
}