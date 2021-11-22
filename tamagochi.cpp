#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <vector>
#include <windows.h>
#include <ctime>
#include <cstdlib>
#include "windows.h"

int choice;
double varibleValue = 4;
double startValue = 0;
bool petSpawn = false;
std::string loadName;
double loadHunger;
double loadFatigue;
double loadHappiness;
bool load = false;
bool isEat = false;
bool isSleep = false;
bool isPlay = false;
double multipluer = 0;

class Pet
{
	public:
		std::string name;
		Pet(double hunger = startValue, double fatigue = startValue, double happiness = startValue);
		void goFood(double food = varibleValue);
		void goSleep(double sleep = varibleValue);
		void goPlay(double fun = varibleValue);
		double getHunger();
		double getFatigue();
		double getHappiness();
		void changeHunger(double hunger);
		void changeFatigue(double fatigue);
		void changeHappiness(double happiness);
		void Talk();
		void changeAll(double deltaTime);
	private:
		double Hunger;
		double Fatigue;
		double Happiness;
		double getMood() const;
};

Pet::Pet(double hunger, double fatigue, double happiness) :
	Hunger(hunger),
	Fatigue(fatigue),
	Happiness(happiness)
{}

Pet testPet;


void newGame(Pet pet);
void loadGame(Pet pet);
void saveGame(Pet pet);
void petName();
void startGame(Pet pet);

double Pet::getHunger()
{
	return(Hunger);
}

double Pet::getFatigue()
{
	return(Fatigue);
}

double Pet::getHappiness()
{
	return(Happiness);
}

void Pet::changeHunger(double hunger)
{
	Hunger = hunger;
}

void Pet::changeFatigue(double fatigue)
{
	Fatigue = fatigue;
}

void Pet::changeHappiness(double happiness)
{
	Happiness = happiness;
}

void Pet::Talk()
{
	system("cls");

	srand(static_cast<unsigned int> (time(0)));
	int textNumber = (rand() % 3) + 1;

	std::cout << "Привет, я " << name << "!\n";
	double mood = getMood();
	if (mood < 3)
	{
		switch (textNumber)
		{
			case 1: 
				std::cout << "У меня замечательное настроение!!!\n";
				break;
			case 2:
				std::cout << "Настроение просто супер ;D\n";
				break;
			case 3:
				std::cout << "Плохое настроение????\nНе, не слышал))\n";
		}
	}
	else if (mood < 8)
	{
		switch (textNumber)
		{
			case 1:
				std::cout << "У меня хорошее настроение!\n";
				break;
			case 2:
				std::cout << "Все хорошо, но...\n";
				break;
			case 3:
				std::cout << "Такая жизнь меня устраивает\n";
				break;
		}
	}
	else if (mood < 13)
	{
		switch (textNumber)
		{
			case 1:
				std::cout << "У меня все нормально :)\n";
				break;
			case 2:
				std::cout << "Отличное настроение? Давно у меня его не было\n";
				break;
			case 3:
				std::cout << "Как-то мне не хорошо(\n";
				break;
		}
	}
	else
	{
		switch (textNumber)
		{
			case 1: 
				std::cout << "Все очень очень плохо\n";
				break;
			case 2:
				std::cout << "Так плохо я себя еще никогда не чувствовал\n";
				break;
			case 3:
				std::cout << "Плохое настроение стало обыденным для меня\n";
				break;
		}
	}

	if (Hunger < 2)
	{
	std::cout << "\nЯ не голоден\n";
	}
	else if (Hunger < 3)
	{
		std::cout << "\nЯ бы перекусил, наверное\n";
	}
	else if (Hunger < 4)
	{
		std::cout << "\nМне хочется кушать\n";
	}
	else if (Hunger < 5)
	{
		std::cout << "\nЯ очень голоден\n";
	}
	else if (Hunger < 6)
	{
		std::cout << "\nСейчас умру от голода\n";
	}

	if (Fatigue < 2)
	{
		std::cout << "\nБодрость мое второе имя\n";
	}
	else if (Fatigue < 3)
	{
		std::cout << "\nМожет вздремнуть не много?\n";
	}
	else if (Fatigue < 4)
	{
		std::cout << "\nЧувствую усталость\n";
	}
	else if (Fatigue < 5)
	{
		std::cout << "\nЯ засыпаю на ходу\n";
	}
	else if (Fatigue < 6)
	{
		std::cout << "\nКак же давно я не спал\n";
	}

	if (Happiness < 2)
	{
		std::cout << "\nЛюблю играть, но пока что не хочется\n";
	}
	else if (Happiness < 3)
	{
		std::cout << "\nМожет поиграем не много?\n";
	}
	else if (Happiness < 4)
	{
		std::cout << "\nМне скучно, ты со мной редко играешь\n";
	}
	else if (Happiness < 5)
	{
		std::cout << "\nМячик?! Ты сказал мячик?\nПоходу послышалось(((\nТак давно я его не видел :(\n";
	}
	else if (Happiness < 6)
	{
		std::cout << "\nСкука одолевает меня\nПоходу меня здеь не любят\n";
	}

	Sleep(5000);
}

void Pet::goFood(double food)
{
	system("cls");
	isEat = true;

	std::cout << "Как вкусно!!!";

	Hunger -= food;
	if (Hunger < 0)
	{
		Hunger = 0;
	}
	Sleep(3000);
}

void Pet::goSleep(double sleep)
{
	system("cls");
	isSleep = true;

	std::cout << "Спокойной ночи...";

	Fatigue -= sleep;
	if (Fatigue < 0)
	{
		Fatigue = 0;
	}
	Sleep(5000);
}

void Pet::goPlay(double play)
{
	system("cls");
	isPlay = true;

	std::cout << "Ура, играть!!!\nСейчас найду свой любимый мячик";

	Happiness -= play;
	if (Happiness < 0)
	{
		Happiness = 0;
	}
	Sleep(4000);
}

void Pet::changeAll(double deltaTime)
{
	if (isEat)
	{
		Fatigue = Fatigue + multipluer * deltaTime;
		Happiness = Happiness + (multipluer / 2) * deltaTime;
	}
	else if (isSleep)
	{
		Hunger = Hunger + multipluer * deltaTime;
		Happiness = Happiness + (multipluer / 2) * deltaTime;
	}
	else if (isPlay)
	{
		Hunger = Hunger + multipluer * deltaTime;
		Fatigue = Fatigue + multipluer * deltaTime;
	}
	else
	{
		Hunger = Hunger + multipluer * deltaTime;
		Fatigue = Fatigue + multipluer * deltaTime;
		Happiness = Happiness + multipluer * deltaTime;
	}
}

double Pet::getMood() const
{
	double mood = Hunger + Fatigue + Happiness;
	return(mood);
}

void correctInput(int max)
{
	bool correct = false;
	while (!correct)
	{
		std::cout << "\nВвод: ";
		std::cin >> choice;
		if (max != 0)
		{
			if (choice < 0 || choice > max)
			{
				std::cout << "\nНекорректно выбранный номер\n";
				std::cout << "Попробуйте еще раз";
			}
			else
			{
				correct = true;
			}
		}
		else
		{
			if (choice != 0)
			{
				std::cout << "\nНекорректно выбранный номер\n";
				std::cout << "Попробуйте еще раз";
			}
			else
			{
				correct = true;
			}
		}
	}
}

void mainMenu(Pet pet)
{
	system("cls");

	std::cout << "Добро пожаловать в игру тамагочи:dog edition\n";
	std::cout << "1. Новая игра\n";
	std::cout << "2. Загрузить игру\n";
	if (petSpawn)
	{
		std::cout << "3. Сохранить игру\n";
		std::cout << "4. Выйти из игры\n";

		correctInput(4);

		switch (choice)
		{
		case 1:
			newGame(pet);
			break;
		case 2:
			loadGame(pet);
			break;
		case 3:
			saveGame(pet);
			break;
		case 4:
			exit(0);
		}
	}
	else
	{
		std::cout << "3. Выйти из игры\n";
		std::cout << "\n(Для того что бы вернутся в главное меня введите 0 во время вашего действия)\n\n";

		correctInput(3);

		switch (choice)
		{
		case 1:
			newGame(testPet);
			break;
		case 2:
			loadGame(pet);
			break;
		case 3:
			exit(0);
		}
	}
}
	
void newGame(Pet pet)
{
	system("cls");

	std::cout << "Выберите сложность игры:\n";
	std::cout << "1. Легкая\n";
	std::cout << "2. Нормальная\n";
	std::cout << "3. Сложная\n";

	correctInput(3);
	
	switch (choice)
	{
		case 1:
			system("cls");
			std::cout << "Вы выбрали легкий уровень сложности!\n\n";
			multipluer = 0.025;
			Sleep(1000);
			petName();
			break;
		case 2:
			system("cls");
			std::cout << "Вы выбрали нормальный уровень сложности!\n\n";
			startValue = 2;
			multipluer = 0.05;
			Sleep(1000);
			petName();
			break;
		case 3:
			system("cls");
			std::cout << "Вы выбрали сложный уровень сложности!\n\n";
			startValue = 3;
			varibleValue = 3;
			multipluer = 0.1;
			Sleep(1000);
			petName();
			break;
		case 0:
			mainMenu(pet);
			break;
	}
}

void loadGame(Pet pet)
{
	system("cls");
	load = false;
	std::ifstream input("allSaves.txt");

	if (input.eof())
	{
		std::cout << "У вас нет сохранений!";
		correctInput(0);
	}
	else
	{
		std::vector<std::string> saves;

		int i = 0;
		std::string save;
		std::cout << "Ваши сохранения:\n";
		while (!input.eof())
		{
			i++;
			input >> save;
			saves.push_back(save);
			std::cout << i << ". " << saves[i - 1] << std::endl;
		}

		std::cout << "Введите номер сохранения: "; //сделать выбор сохранения по цифрам

		correctInput(saves.size());
		if (choice == 0)
		{
			mainMenu(pet);
		}
		std::ifstream inputSave(saves[choice - 1]);
		inputSave >> loadName;
		inputSave >> loadHunger;
		inputSave >> loadFatigue;
		inputSave >> loadHappiness;
		load = true;
		petName();
	}
}

void saveGame(Pet pet)
{
	system("cls");

	std::cout << "Придумайте название сохранения: ";

	std::string filename;
	std::cin >> filename;
	
	std::ofstream save(filename, std::ios::binary);
	save << pet.name;
	save << " ";
	save << pet.getHunger();
	save << " ";
	save << pet.getFatigue();
	save << " ";
	save << pet.getHappiness();
	
	std::ofstream fout("allSaves.txt", std::ios::app);
	fout << filename;
	fout.close();
	
	Sleep(2000);
	std::cout << "\nИгра сохранена, для продолжения введите 0\n";
	correctInput(0);
	if (choice == 0)
	{
		mainMenu(pet);
	}
}

void petName()
{
	system("cls");
	Pet pet;
	petSpawn = true;

	if (load)
	{
		pet.name = loadName;
		pet.changeHunger(loadHunger);
		pet.changeFatigue(loadFatigue);
		pet.changeHappiness(loadHappiness);
		std::cout << "Ваш питомец: ";
		std::cout << pet.name << "\nГолод питомца: " << pet.getHunger() << "\nУсталость питомца: " << pet.getFatigue() << "\nСчастье питомца: " << pet.getHappiness();
	}
	else
	{
		std::cout << "Придумайте имя вашему питомцу: ";
		std::cin >> pet.name;

		std::cout << "Отличное имя!!!";
	}

	std::cout << "\n\nВы готовы начать игру?\n";
	std::cout << "0. Вернуться в меню\n";
	std::cout << "1. Начать игру\n";

	correctInput(1);
	switch (choice)
	{
		case 0:
			mainMenu(pet);
		case 1:
			startGame(pet);
	}
}

void startGame(Pet pet)
{
	double deltaTime = 0;

	while (true)
	{
		auto start = std::chrono::system_clock::now();

		isEat = false;
		isSleep = false;
		isPlay = false;

		system("cls");
		std::cout << "Выберите что бы вы хотели сделать с " << pet.name << ":\n";
		std::cout << "1. Узнать как дела у " << pet.name << std::endl;
		std::cout << "2. Покормить " << pet.name << std::endl;
		std::cout << "3. Отправить спать\n";
		std::cout << "4. Поиграть с " << pet.name << std::endl;

		std::cout << "\nВвод: ";

		if (GetKeyState('1') & 0x8000)
		{
			std::cout << "1";
			Sleep(500);
			pet.Talk();
		}
		else if (GetKeyState('2') & 0x8000)
		{
			std::cout << "2";
			Sleep(500);
			pet.goFood();
		}
		else if (GetKeyState('3') & 0x8000)
		{
			std::cout << "3";
			Sleep(500);
			pet.goSleep();
		}
		else if (GetKeyState('4') & 0x8000)
		{
			std::cout << "4";
			Sleep(500);
			pet.goPlay();
		}
		else if (GetKeyState('0') & 0x8000)
		{
			std::cout << "0";
			Sleep(500);
			mainMenu(pet);
		}

		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> elpsed_seconds = end - start;
		deltaTime = std::chrono::duration<double>(elpsed_seconds).count();

		pet.changeAll(deltaTime);
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	
	mainMenu(testPet);
}