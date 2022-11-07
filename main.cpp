#include <stdio.h>
#include <iostream>
#include <list>

int main()
{
	//�R����w���ꗗ(1970�N)
	std::list<const char*> yamanoteStaition{
		"Tokyo","Yurakucho","Shimbashi","Hamamatsucho","Tamachi","Shinagawa",
		"Osaki","Gotanda","Meguro","Ebisu","Shibuya","Harajuku","Yoyogi",
		"Shinjuku","Shin-Okubo","Takadanobaba","Mejiro","Ikebukuro","Otsuka",
		"Sugamo","Komagome","Tabata","Nippori","Uguisudani","Ueno",
		"Okachimachi","Akihabara","Kanda"
	};

	//1970�N�̎R����w���ꗗ��\��
	printf("1970�N\n");
	printf("\n");
	for (auto itr = yamanoteStaition.begin(); itr != yamanoteStaition.end(); ++itr)
	{
		std::cout << *itr << "\n";
	}
	printf("\n");

	//���闢�̑O�ɐ����闢��ǉ�
	for (std::list<const char*>::iterator itr = yamanoteStaition.begin(); itr != yamanoteStaition.end(); ++itr)
	{
		if (*itr == "Nippori")
		{
			itr = yamanoteStaition.insert(itr, "Nishi-Nippori");
			++itr;
		}
	}

	//2019�N�̎R����w���ꗗ��\��
	printf("2019�N\n");
	printf("\n");
	for (auto itr = yamanoteStaition.begin(); itr != yamanoteStaition.end(); ++itr)
	{
		std::cout << *itr << "\n";
	}
	printf("\n");

	//�i��̑O�ɍ��փQ�[�g�E�F�C��ǉ�
	for (std::list<const char*>::iterator itr = yamanoteStaition.begin(); itr != yamanoteStaition.end(); ++itr)
	{
		if (*itr == "Shinagawa")
		{
			itr = yamanoteStaition.insert(itr, "Takanawa-Gateway");
			++itr;
		}
	}

	//2022�N�̎R����w���ꗗ��\��
	printf("2022�N\n");
	printf("\n");
	for (auto itr = yamanoteStaition.begin(); itr != yamanoteStaition.end(); ++itr)
	{
		std::cout << *itr << "\n";
	}

	return 0;
}