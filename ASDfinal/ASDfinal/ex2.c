#include "ex2.h"
//zadanie: usunac elementy o podanym kluczu w sposob iteracyjny i rekurencyjny
//przeszlo testy

int search_for_key(list *l_p, int _key) {
	int flag = 0;
	if (*l_p == NULL) 
	{
		printf("\n\tlista jest pusta!\n");
	}
	while ((*l_p)) 
	{
		if ((*l_p)->key != _key)
		{
			l_p = &(*l_p)->next;
		}
		else
		{
			flag = 1;
			l_p = &(*l_p)->next;
		}
	}
	return flag;
}

list del_key(list *l_p, int _key) {
	while ((*l_p))
	{
		if ((*l_p)->key != _key)
		{
			l_p = &(*l_p)->next;
		}
		else
		{
			pop_front(l_p);
			l_p = &(*l_p);
		}
	}
}

list del_key_rec(list *l_p, int _key) {
	if (*l_p != NULL)
	{
		if ((*l_p)->key != _key)
		{
			del_key_rec(&(*l_p)->next, _key);
		}
		else
		{
			pop_front(l_p);
			del_key_rec(&(*l_p), _key);
		}
	}
}

void free_list(list *l_p)
{
	while (*l_p != NULL)
	{
		list todel = *l_p;
		if (todel->next != NULL)
		{
			*l_p = todel->next;
		}
		free(todel);
	}
}
