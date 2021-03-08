#pragma once
#include <iostream>
#include <string>

void finish(int result, std::string word) {
	if (result == 10) { std::cout << "Вы проиграли!\n"; std::cout << "Мы загадали слово " << word; }
	else { std::cout << "Вы победили! Ошибок совершено " << result; }
}