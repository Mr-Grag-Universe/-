#include <iostream>
#include <string>
#include <fstream>
#include "h1.h"

void drawing(int mistakes, std::string word_new, std::string word, int mist_type) {

	system("cls"); // очистка экрана

	//отрисовка правил игры в рамочке
	rules();

	//отрисовка загаданного слова
	std::cout << "Загаданное слово: ";
	for (int i = 0; i < word_new.size(); ++i) {
		std::cout << word_new.at(i) << " ";
	}
	std::cout << std::endl;

	std::ifstream f;
	if (mistakes == 0) { std::cout << "Ошибок нет.\n"; }
	else {//если ошибки есть то нарисовать соответствующий их числу кадр
		std::cout << "Вы совершили " << mistakes << " ошибок.\n";
		f.open("picture.txt", std::ios::in);
		for (int i = 1; i < mistakes; ++i) {
			for (int j = 0; j < 16; ++j) {
				std::string temp;
				getline(f, temp);
			}
		}
		for (int j = 0; j < 16; ++j) {
			std::string temp;
			getline(f, temp);
			std::cout << temp << std::endl;
		}
		f.close();
	}

	std::cout << "";
	switch (mist_type)
	{
	case 1:
		std::cout << "Такой буквы нет.\n";
		break;
	case 2:
		std::cout << "Вы уже проверяли эту букву. Попробуйте другую.\n";
		break;
	case 3:
		std::cout << "Верно. Такая буква есть в нашем слове.\n";
		break;
	case 4:
		std::cout << "Мы загадали не это слово.\n";
		break;
	case 5:
		std::cout << "Вы можете ввести лишь 1 букву или слово целиком (нужного размера). Повторите.\n";
		break;
	}
	if (mistakes < 10) { std::cout << "Введите вашу букву или слово целиком: "; }
	
}