#pragma once
#include <iostream>
#include <string>

void finish(int result, std::string word) {
	if (result == 10) { std::cout << "�� ���������!\n"; std::cout << "�� �������� ����� " << word; }
	else { std::cout << "�� ��������! ������ ��������� " << result; }
}