#include "ex3.h"
//zadanie: wyswietlic wartosc najczesciej wystepujacego klucza
//przeszlo testy
int list_most_common(list l_p) {
	list glowica = l_p, p = l_p;
	int current_value, current_counter, max_counter, max_value;
	max_counter = 0;
	max_value = current_value = p->key;
	while (p->next != NULL)
	{
		glowica = l_p;
		current_value = p->key;
		current_counter = 0;
		while (glowica->next != NULL)
		{
			if (glowica->key == current_value) { current_counter++; }
			glowica = glowica->next;
			if (current_counter > max_counter)
			{
				max_counter = current_counter;
				max_value = current_value;
			}
		}
		p = p->next;
	} 
	return max_value;
}