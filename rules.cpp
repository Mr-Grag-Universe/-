#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void rules() {
	std::ifstream f;
	f.open("rules.txt", std::ios::in);
	const int width_of_str{ 70 };
	std::vector <std::string> A;
	A.push_back("");
	while (!f.eof()) {
		std::string temp;
		f >> temp;
		A.at(A.size()-1).append(temp);//сложение строк
		A.at(A.size() - 1) += " ";
		if (A.at(A.size() - 1).size() >= width_of_str) { A.push_back(""); }
	}
	int max{ 0 };

	//нахождение максимальной длины строки
	for (int i = 0; i < A.size(); ++i) { if (A.at(i).size() > max) { max = A.at(i).size(); } }

	for (int i = 0; i < max + 6; ++i) { std::cout << "#"; } std::cout << std::endl;
	for (int i = 0; i < A.size(); ++i) {
		std::cout << "#  " << A.at(i);
		if (A.at(i).size() < max) {
			for (int k = 0; k < max - A.at(i).size(); ++k) {
				std::cout << " ";
			}
		}
		std::cout << "  #\n";
	}
	for (int i = 0; i < max + 6; ++i) { std::cout << "#"; } std::cout << std::endl;
	/*
	while (!f.eof()) {
		std::string temp;
		getline(f, temp);
		std::cout << temp << std::endl;
	}
	*/
	f.close();
}