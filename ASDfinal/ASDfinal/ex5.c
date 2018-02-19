#include "ex5.h"

void rev(list *l) {

	if (*l == NULL) { return; }
	list nextEl = 0;
	list currentEl = *l;
	while (currentEl->next) 
	{
		nextEl = currentEl->next;
		currentEl->next = nextEl->next;
		nextEl->next = *l;
		*l = nextEl;
	}
}

list revr(list *l)
{
	list p, q;
	if (*l == NULL || (*l)->next == NULL) { return *l; }
	p = (*l)->next;
	q = revr(&p);
	p->next = *l;
	(*l)->next = 0;
	return q;
}