#include <stdio.h>
#include <stdlib.h>
#include "Str.h"

// возвращает количество элементов в строке
int MyStrLen(char* string)
{
	int i = 0;
	while (string[i] != 0)
	{
		i++;
	}
	return i;
}

// return 0 - данный символ не число
// return 1 - данный символ число 
int MyIsDigit(char c)
{
	if (((int)c >= 48 && (int)c <= 57) || ((int)c >= 43 && (int)c <= 46))
		return 1; else  return 0;
}

// return 0 - отсутсвие заданной поодстроки
// return 1 - существует заданная подстрока 
int FlagSubString(char* string, char* subString, int pos)
{
	int SizeString = MyStrLen(string);
	int SizeSubString = MyStrLen(subString);
	if (SizeSubString > SizeString) return 0;
	int flag = 1;
	for (int i = 0; i < SizeSubString; i++)
		if (string[pos + i] != subString[i]) flag = 0;
	if (flag == 1) return 1;
	else return 0;


}

// возвращает количество вхождений подстроки в строку
int KolSubString(char* string, char* subString)
{
	int SizeString = MyStrLen(string);
	int SizeSubString = MyStrLen(subString);
	int i = 0;
	int k = 0;
	while (i < SizeString)
	{
		if (string[i] == subString[0])
		{
			if (FlagSubString(string, subString, i) == 1)
			{
				k++;
				i += SizeSubString;
			}
			else { i++; }
		}
		else { i++; }

	}

	return k;

}

//заменить подстроку в строке 
void EditingString(char* string, char* subString1, char* subString2, char* ans)
{
	int SizeString = MyStrLen(string);
	int SizeSubString = MyStrLen(subString2);
	int pos = 0;
	int i = 0;
	while (i < SizeString)
	{
		if (string[i] != subString1[0])
		{
			ans[pos] = string[i];
			pos++;
			i++;
		}
		else
		{
			if (FlagSubString(string, subString1, i) == 1)
			{
				for (int j = 0; j < SizeSubString; j++)
				{
					ans[pos] = subString2[j];
					pos++;

				}
				for (int j = 0; j < MyStrLen(subString1); j++)
					i++;
			}
			else
			{
				ans[pos] = string[i];
				pos++;
				i++;
			}
		}
	}
	ans[pos] = 0;

}

void StrSymbol(int* mass, char* string)
{
	for (int i = 0; i < strlen(string); i++)
	{
		mass[(int)string[i]]++;
	}
}

int MyAtoIForChar(char x)
{
	if (x == '0')return 0;
	if (x == '1')return 1;
	if (x == '2')return 2;
	if (x == '3')return 3;
	if (x == '4')return 4;
	if (x == '5')return 5;
	if (x == '6')return 6;
	if (x == '7')return 7;
	if (x == '8')return 8;
	if (x == '9')return 9;
}