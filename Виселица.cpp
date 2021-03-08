#include <iostream>
#include <string>
#include "h1.h"

int main()
{
    std::cout << "hi";
    start();
    std::string word = chosing();
    int result = game(word);
    finish(result, word);
    return 0;
}