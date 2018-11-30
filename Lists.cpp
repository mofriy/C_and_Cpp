#include "pch.h"
#include <stdio.h>
#define LIST_SIZE 10

int end = -1;
int list[LIST_SIZE];

void push(int x, int a) {
	if (end >= LIST_SIZE - 1) return;

	end++;
	if ((a > end) || (a == -1))
	{
		list[end] = x;
		return;
	}
	else
	{
		int i = end;
		for (i = end; i > a; i--)
		{
			list[i] = list[i - 1];
		}
		list[a] = x;
		return;
	}
}

int pop(int a) {
	if ((end < 0)||(a<0)||(a>end)) return -999;
	int i;
	int x = list[a];
	for (i = a; i < end; i++)
	{
		list[i] = list[i + 1];
	}
	--end;
	return x;
}

void print_list() 
{
	if (end < 0)
	{
		printf("The list is empty\n");
		return;
	}
	int i;
	for (i = 0; i <= end; i++)
	{
		printf("[%d] = %d\n", i, list[i]);
	}
	printf("\n");
}



int main() 
{	
	print_list();
	push(7, -1);
	push(4, -1);
	push(9, -1);
	push(1, -1);
	push(3, -1);
	print_list();

	push(5, 3);
	print_list();

	printf("%d\n", pop(3));
	print_list();

}