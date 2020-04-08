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

int Max(int a, int b)
{
	if (a >= b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

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

void ChangeDischargeForSum(BigInt* x)
{
	for (int i = x->size; i > 0; i--)
	{
		if (x->number[i] >= 10)
		{
			x->number[i - 1] += x->number[i] / 10;
			x->number[i] %= 10;
		}
	}
}

void ChangeDischargForSubtraction(BigInt* x)
{
	if (x->number[0] > 0)
	{
		for (int i = x->size; i > 1; i--)
		{
			if (x->number[i - 1] < 0)
			{
				x->number[i - 1] += 10;
				x->number[i - 2] -= 1;
			}
		}
	}
	//else
	//{
	//	for (int i = 0; i < x->size; i++)
	//		x->number[i] = abs(x->number[i]);
	//	ChangeDischargForSubtraction(x);
	//	x->number[0] *= -1;
	//}
}

// return 0 == x > y 
// return 1 == x < y
int comparison(BigInt* x, BigInt* y)
{
	if (x->size > y->size) return 0;
	if (x->size < y->size) return 1;
	if (x->size == y->size)
	{
		for (int i = 0; i < x->size; i++)
		{
			if (x->number[i] > y->number[i]) return 0;
			if (x->number[i] < y->number[i]) return 1;
			
		}
	}
	return 0;
}

void Addition(BigInt x, BigInt y)
{
	int copsizex = x.size;
	int copsizey = y.size;
	int size = Max(copsizex, copsizey);
	BigInt b;
	b.size = size + 1;
	b.number = (int*)malloc(b.size * sizeof(int));
	for (int i = 0; i < b.size; i++)
		b.number[i] = 0;
	int copsizeb = b.size;


	for (int i = copsizex; i > 0; i--)
	{
		b.number[copsizeb - 1] += x.number[i - 1];
		copsizeb--;
	}
	copsizeb = b.size;

	for (int i = copsizey; i > 0; i--)
	{
		b.number[copsizeb - 1] += y.number[i - 1];
		copsizeb--;
	}
	copsizeb = b.size;

	ChangeDischargeForSum(&b);
	for (int i = 1; i < b.size; i++)
	{
		printf("%d", b.number[i]);
	}
}

void Subtraction(BigInt x, BigInt y)
{
	BigInt b;
	int copsizex = x.size;
	int copsizey = y.size;
	int size = Max(copsizex, copsizey);
	int flag = 0;

	if (copsizex < copsizey)
	{
		BigInt temp = x;
		x = y;
		y = temp;
		flag = 1;
	}
	copsizex = x.size;
	copsizey = y.size;

	if (copsizex == copsizey)
	{
		for (int i = 0; i < copsizex; i++)
			if (x.number[i] == y.number[i])
			{
				size--;
			}
			else
			{
				break;
			}
	}
	if (size == 0)
	{
		printf("0");
		return;
	};

	b.size = size;
	int copsizeb = b.size;

	b.number = (int*)malloc(b.size * sizeof(int));
	for (int i = 0; i < b.size; i++)
		b.number[i] = 0;

	for (int i = copsizex; i > 0; i--)
	{
		b.number[copsizeb - 1] += x.number[i - 1];
		copsizeb--;
		if (copsizeb == -1)break;
	}
	copsizeb = b.size;

	for (int i = copsizey; i > 0; i--)
	{
		b.number[copsizeb - 1] -= y.number[i - 1];
		copsizeb--;
		if (copsizeb == -1)break;
	}

	ChangeDischargForSubtraction(&b);
	if (flag == 1) b.number[0] *= -1;
	for (int i = 0; i < b.size; i++)
	{
		if (b.number[i] < 0 && i != 0) b.number[i] *= -1;
		printf("%d", b.number[i]);
	}

}

void Multiplication(BigInt x, BigInt y)
{
	int size = x.size + y.size ;
	BigInt b;
	b.size = size;
	b.number = (int*)malloc(b.size * sizeof(int));
	for (int i = 0; i < b.size; i++)
		b.number[i] = 0;

	int raz = 0;
	
	for (int i = y.size - 1; i >= 0; i--)
	{
		int raz1 = 0;
		for (int j = x.size - 1; j >= 0; j--)
		{			
			raz1++;
			b.number[b.size - raz - raz1] += x.number[j] * y.number[i];
		}

		raz++;
	}
	ChangeDischargeForSum(&b);
	for (int i = 0; i < b.size; i++)
	{
		printf("%d ", b.number[i]);
	}
	
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
		x.sign = 0;
		y.sign = 0;
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
		printf("\n");


		//printf("%d\n", comparison(&x, &y));

		if (x.sign == 0 && y.sign == 0)
		{
			Addition(x, y);
			printf("\n");
			Subtraction(x, y);
			printf("\n");
			Multiplication(x, y);
		}

		if (x.sign == 0 && y.sign == 1)
		{
			Subtraction(x, y);
			printf("\n");
			Addition(x, y);
		}

		if (x.sign == 1 && y.sign == 0)
		{
			int t;
			t = comparison(&x, &y);
			if (t == 0)
			{
				printf("-");
				Subtraction(x, y);
				printf("\n-");
				Addition(x, y);

			}
		}

		if (x.sign == 1 && y.sign == 1)
		{
			int t = comparison(&x, &y);
			if (t == 0)
			{
				printf("-");
				Addition(x, y);
				printf("\n-");
				Subtraction(x, y);
			}
		}


		//
		//Division(x, y);
		system("pause");

	}
