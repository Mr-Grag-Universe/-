#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "h1.h"

void start() {
	//filtr();
	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");
	//system("mode con cols=300 lines=50");
	/*
	COORD crd = { 100, 1000 };
	SMALL_RECT src = { 0, 0, crd.X, crd.Y };
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), crd);
	SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &src);
	*/
	std::cout << "Приветствуем Вас в игре \"Виселица\".\n";
	std::cout << "Нажмите любую клавишу, чтобы начать.";

	//int k;// = _getch();
	//std::cin >> k;
	//std::cout << "hi";

	//std::cin >> k;
	//rules();
}