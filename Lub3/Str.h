// возвращает количество элементов в строке
int MyStrLen(char* string);


// return 0 - данный символ не число
// return 1 - данный символ число 
int MyIsDigit(char c);


// return 0 - отсутсвие заданной поодстроки
// return 1 - существует заданная подстрока 
int FlagSubString(char* string, char* subString, int pos);


// возвращает количество вхождений подстроки в строку
int KolSubString(char* string, char* subString);


//заменить подстроку в строке 
void EditingString(char* string, char* subString1, char* subString2, char* ans);


void StrSymbol(int* mass, char* string);

int MyAtoIForChar(char x);