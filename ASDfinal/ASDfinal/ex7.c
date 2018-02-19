#include "ex7.h"
//zadanie: laczenie list z seriami danych w jedna liste uporzadkowana

list merge_lists(list *l_1, list *l_2)
{
	if (*l_1 == NULL) { return *l_2; }
	if (*l_2 == NULL) { return *l_1; }
	list head, tmp;
	if ((*l_1)->key < (*l_2)->key) { head = *l_1; }
	else
	{
		head = *l_2;
		*l_2 = *l_1;
		*l_1 = head;
	}
	while ((*l_1)->next != NULL)
	{
		if ((*l_1)->next->key > (*l_2)->key)
		{
			tmp = (*l_1)->next;
			(*l_1)->next = *l_2;
			*l_2 = tmp;
		}
		*l_1 = (*l_1)->next;
	}
	tmp = *l_2;
	(*l_1)->next = tmp;
	return head;
}
