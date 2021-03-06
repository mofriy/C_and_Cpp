#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include <stdio.h>
//#include <cstdlib>
#include <stdlib.h>


struct list_element
{
	int value;
	struct list_element* next;
};
struct list_element begin;

void insert(struct list_element *new_element, struct list_element *after)
{	
	if (after != NULL)
	{
		(*new_element).next = (*after).next;
		(*after).next = &(*new_element);
	}
	else
	{
		int t = begin.value;
		begin.value = (*new_element).value;
		(*new_element).value = t;
		insert(new_element, &begin);
	}
}

void remove_el(struct list_element *element)
{
	struct list_element *a = &begin;
	
	while ((*a).next != element)
	{
		a = (*a).next;
	}
	struct list_element *b = (*a).next;
	(*a).next = (*b).next;
	//free(b);		//удалить "b" из памяти
}

void print_list()
{
	struct list_element *a = &begin;
	while ((*a).next != NULL)
	{
		printf("%d ", (*a).value);
		a = (*a).next;
	}
	printf("%d\n", (*a).value);
}

int main()
{
	begin.value = 1;
	begin.next = NULL;
	
	struct list_element a;
	a.value = 2;
	a.next = NULL;
	
	struct list_element b;
	b.value = 3;
	b.next = NULL;

	insert(&a, &begin);
	insert(&b, &a);
	print_list();
	
	remove_el(&b);
	print_list();

	struct list_element c;
	c.value = 0;
	c.next = NULL;


	insert(&c, NULL);
	print_list();

}