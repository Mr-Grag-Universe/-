#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include "h1.h"

int game(std::string word) {
	std::cout << word;

	// счётчик ошибок
	short i{ 0 };
	short mist_type{ 0 };
	bool letters[33]; for (int j = 0; j < 33; ++j) { letters[j] = false; }

	//временное не разгаданное слово
	std::string word_new = "";	for (auto now : word) { word_new += "_"; }

	while (i < 10) {
		
		//отрисовка всего
		drawing(i, word_new, word, mist_type); mist_type = 0;

		std::string enter;//введённая строка
		std::cin >> enter;

		//обработка ввода
		//если ошибся
		/*
		if (word.find(enter) == word.npos) {
			std::cout << "Неверно.";
			i++;
		}
		*/
		//если введена не 1 буква и не слово
		if ((enter.size() > 1) && (enter.size() != word.size())) {
			mist_type = 5;
			continue;
		}
		//если ввели букву или слово нужного размера
		else {
			if (word.size() == enter.size()) { // если ввели слово
				//если угадал слово
				if (word == enter) { drawing(i, word_new, word, mist_type); return i; }

				//если не угадал слово
				else { i++; mist_type = 4; }
			}
			//если буквы нет в загаданном слове
			if (word.find(enter) == word.npos) { i++; mist_type = 1; }
			else { // если ввели букву
				if (letters[enter.at(0) - 'а']) { mist_type = 2; continue; }
				if ('а' >= enter[0] || enter[0] <= 'ю') { letters[enter[0] - 'а'] = true; }
				for (int j = 0; j < word.size(); ++j) {
					//если нашлась введённая буква в загаданном слове
					if (enter.at(0) == word.at(j)) {
						//если такая буква уже открыта
						if (word_new[j] == enter[0]) { mist_type = 2; continue; }
						
						//если закрытая буква угадана
						else {
							word_new[j] = enter[0];
							//std::string :: iterator iter = word_new.begin();
							//word_new.erase(iter+j+1, 1);
							//word_new.insert(j+1, enter[0]);
						}
					}

				}
				mist_type = 3;
			}

			//word_new.insert(word.find(enter), enter);
		}
		if (word == word_new) { drawing(i, word_new, word, mist_type);  return i; }
	}
	drawing(i, word_new, word, mist_type);
	return i;
}