#include "ex1.h"
//zadanie: listy dodawanie, usuwanie z przodu i z konca, wyswietlanie od poczatku i konca
//przeszlo testy

void push_front(list *l_p, int key)
{
	list p = malloc(sizeof(listElement));
	p->key = key;
	p->next = *l_p;
	*l_p = p;
}
 
void push_back(list *l_p, int key)
{
	list p = malloc(sizeof(listElement));
	list current = *l_p;
	p->key = key;
	p->next = NULL;
	while (current->next != NULL) {
		current = current->next;
	}
	current->next = p;
}


void pop_front(list *l_p)
{
	if (*l_p != NULL)
	{
		list current_el = *l_p;
		*l_p = (*l_p)->next;
		free(current_el);
	}
}

void pop_back(list *l_p)
{
	list current_el = *l_p;
	list to_delete = *l_p;
	while ((current_el->next)) {
		to_delete = current_el;
		current_el = current_el->next;
	}
	to_delete->next = 0;
	free(current_el);
}

void list_print(list _list)
{
	if (_list == NULL) { printf("\n\tlista jest pusta!\n"); return; }
	while (_list) 
	{
		printf("%d->", _list->key);
		//printf("[%3d add::%p]\n", _list->key, _list);
		_list = _list->next;
	}
	printf("||\n");
}

void list_print_rev(list _list)
{
	if (_list) 
	{
		list_print_rev(_list->next);
		printf("%d->", _list->key);
	}
}

