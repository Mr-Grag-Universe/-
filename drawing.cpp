#include <iostream>
#include <string>
#include <fstream>
#include "h1.h"

void drawing(int mistakes, std::string word_new, std::string word, int mist_type) {

	system("cls"); // ������� ������

	//��������� ������ ���� � �������
	rules();

	//��������� ����������� �����
	std::cout << "���������� �����: ";
	for (int i = 0; i < word_new.size(); ++i) {
		std::cout << word_new.at(i) << " ";
	}
	std::cout << std::endl;

	std::ifstream f;
	if (mistakes == 0) { std::cout << "������ ���.\n"; }
	else {//���� ������ ���� �� ���������� ��������������� �� ����� ����
		std::cout << "�� ��������� " << mistakes << " ������.\n";
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
		std::cout << "����� ����� ���.\n";
		break;
	case 2:
		std::cout << "�� ��� ��������� ��� �����. ���������� ������.\n";
		break;
	case 3:
		std::cout << "�����. ����� ����� ���� � ����� �����.\n";
		break;
	case 4:
		std::cout << "�� �������� �� ��� �����.\n";
		break;
	case 5:
		std::cout << "�� ������ ������ ���� 1 ����� ��� ����� ������� (������� �������). ���������.\n";
		break;
	}
	if (mistakes < 10) { std::cout << "������� ���� ����� ��� ����� �������: "; }
	
}