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

//функция для очистки экрана
void clearScreen()
{
	system("cls");
}
//функция для вывода текста по буквам с переходом на новую строку и задержкой и сменой цвета
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

//меню игры
//функция для вывода меню
void menu()
{
	clearScreen();
	printlnText("1.Новая игра");
	printlnText("2.Загрузить игру");
	printlnText("3.Выход");
}
//функция для вывода меню во время игры
void menuGame()
{
	clearScreen();
	printlnText("1.Информация");
	printlnText("2.Действия");
	printlnText("3.Сохранить игру");
	printlnText("4.Выйти из игры");
}
//функция для вывода меню информации
void menuInfo()
{
	clearScreen();
	printlnText("1.Информация о Тамагочи");
	printlnText("2.Вернуться в меню");
}
//функция для вывода меню действий
void menuAction()
{
	clearScreen();
	printlnText("1.Покормить");
	printlnText("2.Поиграть");
	printlnText("3.Полечить");
	printlnText("4.Поспать");
	printlnText("5.Покупки");
	printlnText("6.Вернуться в меню");
}
//функция для вывода меню покупок
void menuBuy()
{
	clearScreen();
	printlnText("1.Еда");
	printlnText("2.Игрушки");
	printlnText("3.Лекарства");
	printlnText("4.Вернуться в меню");
}
//функция для вывода меню еды
void menuFood()
{
	clearScreen();
	printlnText("1.Корм");
	printlnText("2.Сладости");
	printlnText("3.Фрукты");
	printlnText("4.Вернуться в меню");
}
//функция для вывода меню игрушек
void menuToys()
{
	clearScreen();
	printlnText("1.Мяч");
	printlnText("2.Кубик");
	printlnText("3.Вернуться в меню");
}
//функция для вывода меню лекарств
void menuMedicines()
{
	clearScreen();
	printlnText("1.Антибиотик");
	printlnText("2.Витамины");
	printlnText("3.Вернуть");
}

//функция для вывода информации о Тамагочи
void infoTamagochi()
{
	auto tamagotchi = tama.getAllData();
	clearScreen();
	std::vector<std::string> arr;
	arr = {
		"Имя: ",
		"Возраст: ",
		"Здоровье: ",
		"Голод: ",
		"Настроение: ",
		"Сон: ",
		"Чистота: ",
		"Энергия: ",
		"Вес: ",
		"Рост: ",
		"Уровень: ",
		"Опыт: "
	};
	for (int i=0; i<tamagotchi.size(); i++)
	{
		printlnText(arr.at(i) + tamagotchi.at(i));
	}
	printlnText("Вернуться в меню", 100, 0, 4);
	cin.get();

}

void new_game()
{
	printlnText("Дайте имя своему тамагочи"); printf("\n");
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
			//новая игра
			new_game();
			goto MAIN;
			break;
		case 2:
			for (auto& item : files)
				printlnText(item);
			printlnText("Напишите имя сохранения");
			std::cin >> load;
			tama.load_game(load);
			printlnText("Игра загружена", 100, 0, 4);
			goto MAIN;
			break;
		case 3:
			exit(1);
			break;
		default:
			printlnText("Неверный ввод", 100, 0, 4);
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
			printlnText("Игра сохранена", 100, 0, 4);
			Sleep(1000);
			break;
		case 4:
			exit(1);
			break;
		default:
			printlnText("Неверный ввод", 100, 0, 4);
			break;
		}
	} while (choice != 4);
	return 0;
}