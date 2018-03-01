#include "ex4.h"
//zadanie: usunac wszystkie parzyste klucze
//przeszlo testy
list list_del_even(list *l_p) {
	list p = *l_p;
	list p1 = *l_p;
	list *q = *l_p;
	if (p == NULL) { return NULL; }
	if ((p->next == NULL) && (p->key % 2 == 0)) 
	{
		free(p);
		return NULL;
	}
	while (p->key % 2 == 0) 
	{
		if (p->next == NULL) 
		{
			free(p);
			return NULL;
		}
		p1 = p;
		p = p->next;
		free(p1);
		*l_p = p;
	}
	while (p->next != NULL) 
	{
		while (p->key % 2 == 0) 
		{
			*q = p->next;
			p1 = p;
			if (p->next) 
			{
				p = p->next;
				free(p1);
			}
			else { break; }
		}
		q = &p->next;
		if (p->next) { p = p->next; }
	}
	if ((p->next == NULL) && (p->key % 2 == 0))
	{
		*q = NULL;
		free(p);
	}
	return *l_p;
}