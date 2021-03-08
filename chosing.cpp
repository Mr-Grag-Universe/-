#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

std::string chosing() {
	std::ifstream f;
	f.open("словарь.txt", std::ios::in);
	long rand;
	//std::srand(time(0));
	rand = std::rand();
	for (long i = 0; i < rand; ++i) {
		std::string temp;
		if (f.eof()) { f.close(); f.open("словарь.txt", std::ios::in); }
		getline(f,temp);
	}
	std::string word;
	f >> word;
	f.close();
	//std::cout << word;
	return word;
}