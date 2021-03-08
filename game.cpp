#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include "h1.h"

int game(std::string word) {
	std::cout << word;

	// ������� ������
	short i{ 0 };
	short mist_type{ 0 };
	bool letters[33]; for (int j = 0; j < 33; ++j) { letters[j] = false; }

	//��������� �� ����������� �����
	std::string word_new = "";	for (auto now : word) { word_new += "_"; }

	while (i < 10) {
		
		//��������� �����
		drawing(i, word_new, word, mist_type); mist_type = 0;

		std::string enter;//�������� ������
		std::cin >> enter;

		//��������� �����
		//���� ������
		/*
		if (word.find(enter) == word.npos) {
			std::cout << "�������.";
			i++;
		}
		*/
		//���� ������� �� 1 ����� � �� �����
		if ((enter.size() > 1) && (enter.size() != word.size())) {
			mist_type = 5;
			continue;
		}
		//���� ����� ����� ��� ����� ������� �������
		else {
			if (word.size() == enter.size()) { // ���� ����� �����
				//���� ������ �����
				if (word == enter) { drawing(i, word_new, word, mist_type); return i; }

				//���� �� ������ �����
				else { i++; mist_type = 4; }
			}
			//���� ����� ��� � ���������� �����
			if (word.find(enter) == word.npos) { i++; mist_type = 1; }
			else { // ���� ����� �����
				if (letters[enter.at(0) - '�']) { mist_type = 2; continue; }
				if ('�' >= enter[0] || enter[0] <= '�') { letters[enter[0] - '�'] = true; }
				for (int j = 0; j < word.size(); ++j) {
					//���� ������� �������� ����� � ���������� �����
					if (enter.at(0) == word.at(j)) {
						//���� ����� ����� ��� �������
						if (word_new[j] == enter[0]) { mist_type = 2; continue; }
						
						//���� �������� ����� �������
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