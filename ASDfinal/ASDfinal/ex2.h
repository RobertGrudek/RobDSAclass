#pragma once
#include "libincludes.h"

list *search_key(list *l_p, int);
void del_ptr(list);
list del_key(list, int);
list del_key_rec(list, int);
int search_for_key(list, int);

void free_list(list);