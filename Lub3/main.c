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

int SizeNumber(FILE* f)
{
	int ans = 0;
	char c;
	while (((c = fgetc(f)) != EOF))
	{
		if (c != '-')
		{
			ans++;
			if (MyIsDigit(c) == 0)
			{
				printf("Некоректное число");
				exit(4);
			}
		}
	}
	fseek(f, 0, SEEK_SET);
	return ans;

}

void BuffNumber(BigInt* x, FILE* f)
{
	char c;
	for (int i = 0; i < x->size; i++)
	{
		c = fgetc(f);
		if (c == '-') {
			x->sign = 1;
			i--;
			continue;
		}
		if (c == EOF)break;
		x->number[i] = MyAtoIForChar(c);
	}
}

void ReadNumber(BigInt* x, FILE* f)
{
	x->size = SizeNumber(f);
	x->number = (int*)malloc(x->size * sizeof(int));
	BuffNumber(x, f);

}


	int main()
	{
		FILE* f1;
		FILE* f2;
		fopen_s(&f1, "Num1.txt", "r");
		fopen_s(&f2, "Num2.txt", "r");
		FileChek(f1);
		FileChek(f2);
		BigInt x, y;
		ReadNumber(&x, f1);
		ReadNumber(&y, f2);

		if (x.sign == 1)printf("-");
		for (int i = 0; i < x.size; i++)
		{
			printf("%d", x.number[i]);
		}
		printf("\n");
		if (y.sign == 1)printf("-"); 
		for (int i = 0; i < y.size; i++)
		{
			printf("%d", y.number[i]);
		}


	//	Addition(x, y);
	//	printf("\n");
		//Subtraction(x, y);


		//Multiplication(x, y);
		//Division(x, y);
		system("pause");

	}
