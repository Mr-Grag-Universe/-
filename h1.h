#include <string>
#ifndef START
#define START
void start();
#endif // !START

#ifndef CHOSING
#define CHOSING
std::string chosing();
#endif // !CHOSING

#ifndef GAME
#define GAME
int game(std::string word);
#endif // !GAME

#ifndef FINISH
#define FINISH
void finish(int result, std::string word);
#endif // !FINISH

#ifndef RULES
#define RULES
void rules();
#endif // !RULES

#ifndef DRAWING
#define DRAWING
void drawing(int mistakes, std::string word_new, std::string word, int mist_type);
#endif // !DRAWING

#ifndef FILTR
#define FILTR
void filtr();
#endif // !FILTR
