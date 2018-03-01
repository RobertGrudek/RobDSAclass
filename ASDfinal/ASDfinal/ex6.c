#include "ex6.h"
//zadanie: dodawanie posortowane z wartownikiem i bez
//przeszlo testy
void push_sorted(list *l_p, int _key)
{
	if (*l_p && _key > (*l_p)->key)
	{
		push_sorted(&(*l_p)->next, _key);
	}
	else
	{
		push_front(l_p, _key);
	}
}

void push_sorted_sentinel(list *l_p, int _key) {
	if (*l_p == NULL) {	push_front(l_p, _key); }
	else
	{
		push_back(l_p, INT_MAX);
		list current = *l_p;
		list toadd = malloc(sizeof(listElement));
		if (current->key >= _key)
		{
			push_front(l_p, _key);
			pop_back(l_p);
		}
		else
		{
			while (current->next->key < _key)
			{
				current = current->next;
			}
			toadd->key = _key;
			current->next = toadd;
			toadd->next = current->next;
			pop_back(l_p);
		}
	}
}
