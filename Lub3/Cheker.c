#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <locale.h>
#include "Cheker.h"
#include "Str.h"

void FileChek(FILE* f)
{


	//FILE* f;
	//fopen_s(&f, Name, "r");
	setlocale(LC_ALL, "Rus");
	if (errno == EACCES) {
		printf("������, ��� ������� � ����� \n");
		system("pause");
		exit(1);
		
	}
	if (!f)
	{
		printf("������, ����� �� ���������� \n");
		system("pause");
		exit(2);
		
	}
	if (f != NULL)
	{
		if (getc(f) == EOF)
		{
			printf("������, ���� ������\n");
			system("pause");
			exit(3);
			
		}
	}
	fseek(f, 0, SEEK_SET);
	//fclose(f);
	
}
