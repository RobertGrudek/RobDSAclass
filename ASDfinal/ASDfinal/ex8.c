#include "ex8.h"
//wypelnic listy elementy jednej  listy nie nalezacymi do drugiej

void compare_lists(list *l_1, list *l_2, list *l_1comp, list *l_2comp)
{
	list tmp1 = *l_1;
	list tmp2 = *l_2;
	if (*l_1 == NULL && *l_2 == NULL)
	{
		return;
	}
	else
	{
		if (*l_1 == NULL)
		{
			while (tmp2 != NULL)
			{
				push_front(l_2comp, tmp2->key);
				tmp2 = tmp2->next;
			}
		}
		else if (*l_2 == NULL)
		{
			while (tmp1 != NULL)
			{
				push_front(l_1comp, tmp1->key);
				tmp1 = tmp1->next;
			}
		}
		else
		{
			int add = 1;
			while (tmp1 != NULL)
			{
				while (tmp2 != NULL) 
				{
					if (tmp1->key == tmp2->key) { add = 0; }
					tmp2 = tmp2->next;
				}
				if (add) { push_front(l_1comp, tmp1->key); }
				tmp1 = tmp1->next;
				tmp2 = *l_2;
				add = 1;
			}
			tmp1 = *l_1;
			while (tmp2 != NULL)
			{
				while (tmp1 != NULL)
				{
					if (tmp2->key == tmp1->key) { add = 0; }
					tmp1 = tmp1->next;
				}
				if (add) { push_front(l_2comp, tmp2->key); }
				tmp2 = tmp2->next;
				tmp1 = *l_1;
				add = 1;
			}
		}
		
	}
}