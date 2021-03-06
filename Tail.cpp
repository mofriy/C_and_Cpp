#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int x;
	int n;
	int hex;
	unsigned char c;
	//"анализ" аргументов
	{
		if (argc == 5)
		{
			n = atoi(argv[2]);
			x = 3;
			hex = 1 - strcmp(argv[4], "hex");
		}
		if (argc == 4)
		{
			if ( (strcmp(argv[3], "hex") == 0) || (strcmp(argv[3], "txt") == 0) )
			{
				hex = 1 - strcmp(argv[3], "hex");
				x = 2;
				n = 10;
			}
			else
			{
				hex = 1;
				x = 3;
				n = atoi(argv[2]);
			}
		}
		if (argc == 3)
		{
			n = 10;
			x = 2;
			hex = 1;
		}
		
	}

	if (strcmp(argv[1], "-c") == 0)
	{
		FILE *f = fopen(argv[x], "rb");
		if (f != NULL)
		{
			fseek(f, -n - 1, SEEK_END);
			fscanf(f, "%c", &c);	
			if (hex != 0)
			{
				int i = 0;
				while (not(feof(f)))
				{
					if (i == 16)
					{
						i = 0;
						printf("\n");
					}
					i++;
					printf("%02x ", c);
					fscanf(f, "%c", &c);
				}
			}
			else
			{
				while (not(feof(f)))
				{
					printf("%c", c);
					fscanf(f, "%c", &c);
				}
			}
			fclose(f);
		}
		else
		{
			printf("Sorry, some error.\n");
		}
	}
	else
	{
		FILE *f = fopen(argv[x], "rt");
		if (f != NULL)
		{
			fseek(f, -1, SEEK_END);
			
			//РАБОТА С УКАЗАТЕЛЕМ
			int string_num;
			int e = 0;
			for (string_num = 0; string_num < n; string_num++)
			{
				fscanf(f, "%c", &c);
				while ( not(c == '\n') )
				{
					e = fseek(f, -2, SEEK_CUR);
					if (e != 0)
					{
						fseek(f, 0, SEEK_SET);
						goto text_print;
					}
					fscanf(f, "%c", &c);
				}
				fseek(f, -3	, SEEK_CUR);
			}
			fscanf(f, "%c", &c);
			fscanf(f, "%c", &c);
			text_print:
			fscanf(f, "%c", &c);
			if (hex != 0)
			{
				int i = 0;
				while (not(feof(f)))
				{
					if (i == 16)
					{
						i = 0;
						printf("\n");
					}
					i++;
					printf("%02x ", c);
					fscanf(f, "%c", &c);
				}
			}
			else
			{
				while (not(feof(f)))
				{
					printf("%c", c);
					fscanf(f, "%c", &c);
				}
			}
			fclose(f);
		}
		else 
		{
			printf("Sorry, some error.\n");
		}
	}
}

/*
-c - выводить указанное N количество байт с конца файла;
-n - выводить указанное количество строк из конца файла;
tail -c name
tail -n 100 /var/log/syslog
*/