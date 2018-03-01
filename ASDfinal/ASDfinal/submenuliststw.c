#include "submenuliststw.h"

void submenu_liststw_run() {
	twlist ltw = 0;
	twlist ltwc = 0;
	int run = 1, value = 0;
	srand(time(NULL));
	for (int i = 0; i < 10; i++) {
		value = rand() % (99 - 10) + 10;
		twcpush_front(&ltwc, value);
		twpush_sorted(&ltw, value);
	}
	while (run)
	{
		system("cls");
		boldf("MENU LIST DWUSTRONNYCH (zad 9-12) WYBIERZ OPCJE:");
		printf("\n\t1 - wyswietlenie listy dwukierunkowej");
		printf("\n\t2 - wyswietlenie listy cyklicznej");
		printf("\n\t3 - usuniecie z listy dwukierunkowej");
		printf("\n\tz - powrot do menu glownego\n");
		int c = 0, doit = 1, y = 0, flag = 0;
		c = _getch();
		switch (c) {
			int input;
		case '1':
			system("cls");
			boldf("Zawartosc listy dwukierunkowej:");
			twlist_print(ltw);
			printf("\n ...aby przejsc dalej, wcisnij dowlony klawisz");
			_getch();
			break;

		case '2':
			system("cls");
			boldf("Zawartosc listy cyklicznej:");
			twclist_print(ltwc);
			printf("\n ...aby przejsc dalej, wcisnij dowlony klawisz");
			_getch();
			break;

		case '3':
			system("cls");
			//deleteElementC(&ltwc);
			boldf("Zawartosc listy dwukierunkowej:");
			twlist_print(ltw);
			printf("\nWprowadz klucz do usuniecia:\t");
			scanf(" %d", &input);
			search_tw(&ltw, input);
			twlist_print(ltw);
			_getch();
			system("cls");
			break; 

		case '4':
			system("cls");
			//deleteElementC(&ltwc);
			boldf("Zawartosc listy cyklicznej:");
			twclist_print(ltwc);
			printf("\nWprowadz klucz do usuniecia:\t");
			scanf("%d", &input);
			search_tw(&ltwc, input);
			twclist_print(ltwc);
			_getch();
			system("cls");
			break;

		case 'z':
			boldf("Czy napewno chcesz zakonczyc program? Wcisnij y, aby zakonczyc...");
			y = _getch();
			if (y == 'y')
			{
				system("cls");
				run = 0;
				break;
			}
			system("cls");
			break;

		default:
			system("cls");
			boldf("Wybrano nieprawidlowa opcje, sprobuj ponownie");
			_getch();
			system("cls");
			break;
		}
	}
	
}