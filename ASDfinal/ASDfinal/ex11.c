#include "ex11.h"
//11. Zaimplementuj kolejk? priorytetow?.Potrzebne b?d? funkcje : dodaj?ce element; usuwaj?ce element
//o najwi?kszej warto?ci PRIORYTETU; funkcja umo?liwiaj?ca zmian? warto?ci PRIORYTETU elementu.
void prlist_add(prlist *p_l, int _key, int _p)
{
	prlist l = malloc(sizeof(prlistElement));
	prlist temp = *p_l;
	l->key = _key;
	l->priority = _p;
	l->next = NULL;
	if (p_l == NULL)
	{
		*p_l = l;
		l->next = NULL;
	}
	else if ((*p_l)->priority > _p) 
	{
		l->next = *p_l;
		*p_l = l;
	}
	else
	{
		while (temp->next != NULL && temp->next->priority < _p)
		{
			temp = temp->next;
		} 
		l->next = temp->next;
		temp->next = l;
	}
}
void prlist_view(prlist *p_l)
{
	if (*p_l)
	{
		int x, p;
		prlist temp = *p_l;
		printf("\n");
		while (temp != NULL)
		{
			x = temp->key;
			p = temp->priority;
			printf("[ %d | %d ]", x, p);
			temp = temp->next;
		}
		printf("\n");
	}
}
void prlist_rmhigh(prlist *p_l)
{
	prlist to_del = *p_l;
	*p_l = (*p_l)->next;
	free(to_del);
}
