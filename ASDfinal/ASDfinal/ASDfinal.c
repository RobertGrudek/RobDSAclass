#include "libincludes.h"
#include "mainmenu.h"

int main() {
	prlist *kaszanka = 0;
	prlist_add(&kaszanka, 5, 2);
	prlist_view(&kaszanka);
	//mainmenu_run();

	system("pause");
	return 0;
}