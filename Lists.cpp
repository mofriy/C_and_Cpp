#include "pch.h"
#include <stdio.h>
#define LIST_SIZE 10

int end = -1;
int list[LIST_SIZE];

void push(int x) {
	if (end >= LIST_SIZE - 1) return;

	list[++end] = x;
}

int pop(int a) {
	if ((end < 0)||(a<0)||(a>end)) return -999;
	int i;
	for (i = a; i < end; i++)
	{
		list[i] = list[i + 1];
	}
	--end;
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
	push(7);
	push(4);
	push(9);
	push(1);
	push(3);
	print_list();

	pop(3);
	print_list();

}