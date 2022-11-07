#include <stdio.h>
#include <iostream>
#include <list>

int main()
{
	//山手線駅名一覧(1970年)
	std::list<const char*> yamanoteStaition{
		"Tokyo","Yurakucho","Shimbashi","Hamamatsucho","Tamachi","Shinagawa",
		"Osaki","Gotanda","Meguro","Ebisu","Shibuya","Harajuku","Yoyogi",
		"Shinjuku","Shin-Okubo","Takadanobaba","Mejiro","Ikebukuro","Otsuka",
		"Sugamo","Komagome","Tabata","Nippori","Uguisudani","Ueno",
		"Okachimachi","Akihabara","Kanda"
	};

	//1970年の山手線駅名一覧を表示
	printf("1970年\n");
	printf("\n");
	for (auto itr = yamanoteStaition.begin(); itr != yamanoteStaition.end(); ++itr)
	{
		std::cout << *itr << "\n";
	}
	printf("\n");

	//日暮里の前に西日暮里を追加
	for (std::list<const char*>::iterator itr = yamanoteStaition.begin(); itr != yamanoteStaition.end(); ++itr)
	{
		if (*itr == "Nippori")
		{
			itr = yamanoteStaition.insert(itr, "Nishi-Nippori");
			++itr;
		}
	}

	//2019年の山手線駅名一覧を表示
	printf("2019年\n");
	printf("\n");
	for (auto itr = yamanoteStaition.begin(); itr != yamanoteStaition.end(); ++itr)
	{
		std::cout << *itr << "\n";
	}
	printf("\n");

	//品川の前に高輪ゲートウェイを追加
	for (std::list<const char*>::iterator itr = yamanoteStaition.begin(); itr != yamanoteStaition.end(); ++itr)
	{
		if (*itr == "Shinagawa")
		{
			itr = yamanoteStaition.insert(itr, "Takanawa-Gateway");
			++itr;
		}
	}

	//2022年の山手線駅名一覧を表示
	printf("2022年\n");
	printf("\n");
	for (auto itr = yamanoteStaition.begin(); itr != yamanoteStaition.end(); ++itr)
	{
		std::cout << *itr << "\n";
	}

	return 0;
}