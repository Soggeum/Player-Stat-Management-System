#include <iostream>

void settingHpMp(int status[4]);
void settingDMGDF(int status[4]);
void setPotion(int count, int* p_HPPotion, int* p_MPPotion);
void statManagementSystem(int status[4], int* hpPotion, int* mpPotion);

int main() {
	int status[4] {};	// 기본 스탯 배열 선언 및 초기화
	
	settingHpMp(status);
	settingDMGDF(status);

	int hpPotion{}, mpPotion{};
	setPotion(5, &hpPotion, &mpPotion);
	std::cout << "* 포션이 지급되었습니다. (HP, MP 포션 각 5개)\n";
	std::cout << "=============================================\n";

	statManagementSystem(status, &hpPotion, &mpPotion);
}

void settingHpMp(int status[4]) 
{
	bool isValid{ false };
	while (!isValid)
	{
		std::cout << "HP와 MP를 입력해주세요: ";
		std::cin >> status[0] >> status[1];

		if ((status[0] <= 50) || (status[1] <= 50)) std::cout << "HP나 MP의 값이 너무 작습니다. 다시 입력해주세요.\n";
		else isValid = true;
	}
}

void settingDMGDF(int status[4]) 
{
	bool isValid{ false };
	while (!isValid)
	{
		std::cout << "공격력과 방어력을 입력해주세요: ";
		std::cin >> status[2] >> status[3];

		if ((status[2] <= 0) || (status[3] <= 0)) std::cout << "공격력 또는 방어력의 값이 너무 작습니다. 다시 입력해주세요.\n";
		else isValid = true;
	}
}

void setPotion(int count, int* p_HPPotion, int* p_MPPotion)
{
	*p_HPPotion = count;
	*p_MPPotion = count;
}

void statManagementSystem(int status[4], int* hpPotion, int* mpPotion)
{
	std::cout << "<스탯 관리 시스템>\n"
		<< "1. HP 회복\n"
		<< "2. MP 회복\n"
		<< "3. HP 강화\n"
		<< "4. MP 강화\n"
		<< "5. 공격 스킬 사용\n"
		<< "6. 필살기 사용\n"
		<< "7. 나가기\n";

		int input{};
		while (input != 7)
		{
			std::cout << "번호를 선택해주세요 : ";
			std::cin >> input;
		
			switch (input)
			{
			case 1:
				if (*hpPotion > 0)
				{
					std::cout << "* HP가 20 회복되었습니다. 포션이 1개 차감됩니다.\n";
					status[0] += 20;
					(*hpPotion)--;
					std::cout << "현재 HP : " << status[0] << '\n';
					std::cout << "남은 포션 수 : " << *hpPotion << '\n';
				}
				else
					std::cout << "포션이 부족합니다.\n";
				break;

			case 2:
				if (*mpPotion > 0)
				{
					std::cout << "* MP가 20 회복되었습니다. 포션이 1개 차감됩니다.\n";
					status[1] += 20;
					(*mpPotion)--;
					std::cout << "현재 MP : " << status[1] << '\n';
					std::cout << "남은 포션 수 : " << *mpPotion << '\n';
				}
				else
					std::cout << "포션이 부족합니다.\n";
				break;

			case 3:
				std::cout << "* HP가 2배로 증가되었습니다.\n";
				status[0] *= 2;
				std::cout << "현재 HP : " << status[0] << '\n';
				break;
			
			case 4:
				std::cout << "* MP가 2배로 증가되었습니다.\n";
				status[1] *= 2;
				std::cout << "현재 MP : " << status[1] << '\n';
				break;

			case 5:
				if (status[1] < 50)
					std::cout << "스킬 사용이 불가합니다.\n";
				else 
				{
					std::cout << "* 스킬을 사용하여 MP가 50 소모되었습니다.\n";
					status[1] -= 50;
					std::cout << "현재 MP : " << status[1] << '\n';
				}
				break;

			case 6:
				std::cout << "* 스킬을 사용하여 MP가 50% 소모되었습니다.\n";
				status[1] /= 2;
				std::cout << "현재 MP : " << status[1] << '\n';					
				break;

			default:
				std::cout << "프로그램을 종료합니다.";
				return;
			}
		}
}