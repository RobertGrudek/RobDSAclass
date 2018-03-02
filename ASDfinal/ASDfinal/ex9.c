#include "ex9.h"
void twpush_front(twlist *l, int _key) 
{
	twlist temp;
	temp = malloc(sizeof(twlistElement));
	temp->key = _key;
	temp->prev = 0;
	if (*l == 0) 
	{
		*l = temp;
		temp->next = 0;
	}
	else 
	{
		temp->next = *l;
		(*l)->prev = temp;
		*l = temp;
	}
}void twcpush_front(twlist *lc, int _key) {
	twlist temp1, temp2 = 0;
	temp1 = malloc(sizeof(twlistElement));
	temp1->key = _key;
	if (*lc == 0) 
	{
		*lc = temp1;
		temp1->next = temp1;
		temp1->prev = temp1;
	}
	else 
	{
		temp2 = (*lc)->next;
		temp1->prev = *lc;
		temp1->next = temp2;
		(*lc)->next = temp1;
		temp2->prev = temp1;
	}

}void twpush_sorted(twlist *l, int _key)
{
	if (*l && _key > (*l)->key)
	{
		twpush_sorted(&(*l)->next, _key);
	}
	else
	{
		twpush_front(l, _key);
	}
}

void twcpush_sorted(twlist *l, int _key)
{
	if (*l && _key > (*l)->key)
	{
		twcpush_sorted(&(*l)->next, _key);
	}
	else
	{
		twcpush_front(l, _key);
	}
}

void twlist_print(twlist l)
{
	twlist temp = l;
	if (l == NULL) { printf("\n\tlista jest pusta!\n"); return; }
	do
	{
		printf("<%d>", (temp)->key);
		temp = (temp)->next;
	} while (temp);
	printf("\n");
}
void twclist_print(twlist lc) {
	twlist temp = lc;
	if (temp == NULL) { printf("Lista jest pusta!\n\n"); return; }
	do 
	{
		printf("<%d>", temp->key);
		temp = temp->next;
	} while (temp != lc);
	printf("\n");
}

////eh 
void search_twc(twlist *l, int _key) {
	twlist p, temp = *l;
	if (*l == NULL) { return; }
	while (temp->next != *l)
	{
		printf("\n petla hurra");
		if (temp->key == _key)
		{
				p = temp;
				temp = temp->next;
				temp->prev = temp->prev->prev;
				free(p);
		}
		else { temp = temp->next; }
	} 
}

void search_tw(twlist *lc, int _key) {
	twlist del, tmp;
	if (*lc == NULL) { return; }
	tmp = *lc;
	while (tmp->next != NULL)
	{
		del = tmp;
		if (del->key == _key) 
		{
			if (del->next != NULL || del->prev != NULL)
			{
				del->next->prev = del->prev;
				del->prev->next = del->next;
				if (del->next == NULL) { del->prev->next = NULL; }
				else { tmp = del->next; }
			}
			else if (del->prev == NULL )
			{
				del->next->prev = NULL;
				del->prev = NULL;
				tmp = del->next;
				*lc = (*lc)->next;
			}
			free(del);
		}
		else { tmp = tmp->next; }
	} 
}
