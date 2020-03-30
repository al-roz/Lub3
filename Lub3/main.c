#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "Cheker.h"
#include "Str.h"


typedef struct
{

	int size;
	int* number;
	int sign;

} BigInt;

	int main()
	{
		FILE* f1;
		FILE* f2;
		fopen_s(&f1, "Num1.txt", "r");
		fopen_s(&f2, "Num2.txt", "r");
		FileChek(f1);
		FileChek(f2);
		BigInt x, y;
	//	ReadNumber(&x, f1);
	//	ReadNumber(&y, f2);
		//for (int i = 0; i < y.size; i++)
		//{
		//	printf("%d  ", y.number[i]);
		//}


	//	Addition(x, y);
	//	printf("\n");
		//Subtraction(x, y);


		//Multiplication(x, y);
		//Division(x, y);
		system("pause");

	}
