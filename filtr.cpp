#include <fstream>
#include <iostream>
#include <string>
#pragma once
void filtr() {
	std::ifstream f1; f1.open("словарь.txt", std::ios::in);
	std::ofstream f2; f2.open("словарь1.txt", std::ios::out | std::ios_base::trunc);
	
	while (!f1.eof()) {
		std::string temp{ "" };
		f1 >> temp;
		f2 << temp << std::endl;	
	}
	f1.close();
	f2.close();

	std::ifstream f3; f3.open("словарь1.txt", std::ios::in);
	std::ofstream f4; f4.open("словарь.txt", std::ios::out | std::ios_base::trunc);
	while (!f3.eof()) {
		std::string temp{ "" };
		f3 >> temp;
		f4 << temp << std::endl;
	}
}