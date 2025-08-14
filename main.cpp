#include <iostream>

void settingHpMp(int status[4]);
void settingDMGDF(int status[4]);
void setPotion(int count, int* p_HPPotion, int* p_MPPotion);
void statManagementSystem(int status[4], int* hpPotion, int* mpPotion);

int main() {
	int status[4] {};	// �⺻ ���� �迭 ���� �� �ʱ�ȭ
	
	settingHpMp(status);
	settingDMGDF(status);

	int hpPotion{}, mpPotion{};
	setPotion(5, &hpPotion, &mpPotion);
	std::cout << "* ������ ���޵Ǿ����ϴ�. (HP, MP ���� �� 5��)\n";
	std::cout << "=============================================\n";

	statManagementSystem(status, &hpPotion, &mpPotion);
}

void settingHpMp(int status[4]) 
{
	bool isValid{ false };
	while (!isValid)
	{
		std::cout << "HP�� MP�� �Է����ּ���: ";
		std::cin >> status[0] >> status[1];

		if ((status[0] <= 50) || (status[1] <= 50)) std::cout << "HP�� MP�� ���� �ʹ� �۽��ϴ�. �ٽ� �Է����ּ���.\n";
		else isValid = true;
	}
}

void settingDMGDF(int status[4]) 
{
	bool isValid{ false };
	while (!isValid)
	{
		std::cout << "���ݷ°� ������ �Է����ּ���: ";
		std::cin >> status[2] >> status[3];

		if ((status[2] <= 0) || (status[3] <= 0)) std::cout << "���ݷ� �Ǵ� ������ ���� �ʹ� �۽��ϴ�. �ٽ� �Է����ּ���.\n";
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
	std::cout << "<���� ���� �ý���>\n"
		<< "1. HP ȸ��\n"
		<< "2. MP ȸ��\n"
		<< "3. HP ��ȭ\n"
		<< "4. MP ��ȭ\n"
		<< "5. ���� ��ų ���\n"
		<< "6. �ʻ�� ���\n"
		<< "7. ������\n";

		int input{};
		while (input != 7)
		{
			std::cout << "��ȣ�� �������ּ��� : ";
			std::cin >> input;
		
			switch (input)
			{
			case 1:
				if (*hpPotion > 0)
				{
					std::cout << "* HP�� 20 ȸ���Ǿ����ϴ�. ������ 1�� �����˴ϴ�.\n";
					status[0] += 20;
					(*hpPotion)--;
					std::cout << "���� HP : " << status[0] << '\n';
					std::cout << "���� ���� �� : " << *hpPotion << '\n';
				}
				else
					std::cout << "������ �����մϴ�.\n";
				break;

			case 2:
				if (*mpPotion > 0)
				{
					std::cout << "* MP�� 20 ȸ���Ǿ����ϴ�. ������ 1�� �����˴ϴ�.\n";
					status[1] += 20;
					(*mpPotion)--;
					std::cout << "���� MP : " << status[1] << '\n';
					std::cout << "���� ���� �� : " << *mpPotion << '\n';
				}
				else
					std::cout << "������ �����մϴ�.\n";
				break;

			case 3:
				std::cout << "* HP�� 2��� �����Ǿ����ϴ�.\n";
				status[0] *= 2;
				std::cout << "���� HP : " << status[0] << '\n';
				break;
			
			case 4:
				std::cout << "* MP�� 2��� �����Ǿ����ϴ�.\n";
				status[1] *= 2;
				std::cout << "���� MP : " << status[1] << '\n';
				break;

			case 5:
				if (status[1] < 50)
					std::cout << "��ų ����� �Ұ��մϴ�.\n";
				else 
				{
					std::cout << "* ��ų�� ����Ͽ� MP�� 50 �Ҹ�Ǿ����ϴ�.\n";
					status[1] -= 50;
					std::cout << "���� MP : " << status[1] << '\n';
				}
				break;

			case 6:
				std::cout << "* ��ų�� ����Ͽ� MP�� 50% �Ҹ�Ǿ����ϴ�.\n";
				status[1] /= 2;
				std::cout << "���� MP : " << status[1] << '\n';					
				break;

			default:
				std::cout << "���α׷��� �����մϴ�.";
				return;
			}
		}
}