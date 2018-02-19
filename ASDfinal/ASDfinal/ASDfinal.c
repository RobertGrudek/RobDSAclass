#include "libincludes.h"
#include "mainmenu.h"

int main() {
	
	//boldf("pisze");
	mainmenu_run();
	//submenu_lists_run(); 
	//boldf("zakonczono program");
	//submenu_liststw_run();
	//submenu_trees_run();
	//heapsort_run();

	/*
	twlist *li = 0; 

	twpush_sorted(&li, 3);
	twpush_sorted(&li, 7);
	twpush_sorted(&li, 39);
	twpush_sorted(&li, 2);
	twpush_sorted(&li, 222);
	twpush_sorted(&li, 22);
	twpush_sorted(&li, 2222);
	twpush_sorted(&li, 2);

	twlist_print(li);
	*/


	list *li = 0;
	push_front(&li, 40);
	push_front(&li, 42);
	push_front(&li, 45);
	push_front(&li, 13);
	list_print(li);
	li = revr(&li);
	list_print(li);
	boldf("kaczka");

	/*
	push_front(&li, 40);
	push_front(&li, 42);
	push_front(&li, 45);
	list_print(li);
	printf("cos\n");
	push_front(&li, 40);
	list_print(li);
	push_back(&li, 90);
	push_back(&li, 90);
	push_back(&li, 90);
	push_back(&li, 90);
	push_back(&li, 990);
	printf("cos\n");
	list_print(li);
	printf("huhu\n");
	pop_front(&li);
	pop_front(&li);
	pop_front(&li);
	push_front(&li, 731);
	list_print(li);
	del_key_rec(&li, 90);
	printf("huhu\n");
	*/
	/*
	list_print_rev(li);
	pop_front(&li);
	pop_front(&li);
	pop_front(&li);
	pop_front(&li);
	pop_front(&li);
	pop_front(&li);
	pop_front(&li);
	pop_front(&li);
	pop_front(&li);
	pop_front(&li);
	list_print_rev(li);*/
	//li = list_del_even(&li);
	//list_print_rev(li);
	//pop_back(&li);
	//del_key(&(*li), 40);
	//mainmenu_run();*/
	system("pause");
	return 0;
}