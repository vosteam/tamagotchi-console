#include "Tamagotchi.h"

using namespace std;

void gotoxy(int x, int y)
{
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void SetColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void SetColor(int text)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | text));
}

void SetColor()
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 15));
}

//������� ��� ������� ������
void clearScreen()
{
	system("cls");
}
//������� ��� ������ ������ �� ������ � ��������� �� ����� ������ � ��������� � ������ �����
void printlnText(string text, int time = 1, int delay = 1000, int color = 7)
{
	SetColor(color);
	for (int i = 0; i < text.length(); i++)
	{
		cout << text[i];
		Sleep(time);
	}
	cout << endl;
	Sleep(delay);
	SetColor();
}

//���� ����
//������� ��� ������ ����
void menu()
{
	clearScreen();
	printlnText("1.����� ����");
	printlnText("2.��������� ����");
	printlnText("3.�����");
}
//������� ��� ������ ���� �� ����� ����
void menuGame()
{
	clearScreen();
	printlnText("1.����������");
	printlnText("2.��������");
	printlnText("3.��������� ����");
	printlnText("4.����� �� ����");
}
//������� ��� ������ ���� ����������
void menuInfo()
{
	clearScreen();
	printlnText("1.���������� � ��������");
	printlnText("2.��������� � ����");
}
//������� ��� ������ ���� ��������
void menuAction()
{
	clearScreen();
	printlnText("1.���������");
	printlnText("2.��������");
	printlnText("3.��������");
	printlnText("4.�������");
	printlnText("5.�������");
	printlnText("6.��������� � ����");
}
//������� ��� ������ ���� �������
void menuBuy()
{
	clearScreen();
	printlnText("1.���");
	printlnText("2.�������");
	printlnText("3.���������");
	printlnText("4.��������� � ����");
}
//������� ��� ������ ���� ���
void menuFood()
{
	clearScreen();
	printlnText("1.����");
	printlnText("2.��������");
	printlnText("3.������");
	printlnText("4.��������� � ����");
}
//������� ��� ������ ���� �������
void menuToys()
{
	clearScreen();
	printlnText("1.���");
	printlnText("2.�����");
	printlnText("3.��������� � ����");
}
//������� ��� ������ ���� ��������
void menuMedicines()
{
	clearScreen();
	printlnText("1.����������");
	printlnText("2.��������");
	printlnText("3.�������");
}

//������� ��� ������ ���������� � ��������
void infoTamagochi()
{
	auto tamagotchi = tama.getAllData();
	clearScreen();
	std::vector<std::string> arr;
	arr = {
		"���: ",
		"�������: ",
		"��������: ",
		"�����: ",
		"����������: ",
		"���: ",
		"�������: ",
		"�������: ",
		"���: ",
		"����: ",
		"�������: ",
		"����: "
	};
	for (int i=0; i<tamagotchi.size(); i++)
	{
		printlnText(arr.at(i) + tamagotchi.at(i));
	}
	printlnText("��������� � ����", 100, 0, 4);
	cin.get();

}

void new_game()
{
	printlnText("����� ��� ������ ��������"); printf("\n");
	std::string name;
	std::cin >> name;

	tama.setName(name);
	tama.set_default();
	tama.save_game();
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	SetConsoleTitle("Tamagotchi");
	auto hConsole = GetConsoleWindow();
	SetConsoleTextAttribute(hConsole, 7);
	std::string homedrive = getenv("HOMEDRIVE");
	std::string homepath = getenv("HOMEPATH");
	std::string folder_path = homedrive + homepath + "\\Documents\\vos.team\\Tamagotchi\\";

	int choice;
	do
	{
		auto files = utils::get_files(folder_path);
		menu();
		cin >> choice;
		std::string load;
		
		switch (choice)
		{
		case 1:
			//����� ����
			new_game();
			goto MAIN;
			break;
		case 2:
			for (auto& item : files)
				printlnText(item);
			printlnText("�������� ��� ����������");
			std::cin >> load;
			tama.load_game(load);
			printlnText("���� ���������", 100, 0, 4);
			goto MAIN;
			break;
		case 3:
			exit(1);
			break;
		default:
			printlnText("�������� ����", 100, 0, 4);
			break;
		}
	} while (choice != 3);
MAIN:
	do
	{
		menuGame();
		cin >> choice;
		switch (choice)
		{
		case 1:
			infoTamagochi();
			break;
		case 2:
			menuAction();
			break;
		case 3:
			tama.save_game();
			printlnText("���� ���������", 100, 0, 4);
			Sleep(1000);
			break;
		case 4:
			exit(1);
			break;
		default:
			printlnText("�������� ����", 100, 0, 4);
			break;
		}
	} while (choice != 4);
	return 0;
}