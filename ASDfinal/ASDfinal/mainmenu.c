#include "mainmenu.h"

void mainmenu_run() 
{
	int run = 1;
	while (run) 
	{
		int c, y;
		boldf("WITAJ W PROGRAMIE PREZENTUJACYM ALGORYTMY I STRUKTURY DANYCH");
		printf(" WYBIERZ: \n");
		printf("\n\t1 - algorytmy na listach (zad.1-5)");
		printf("\n\t2 - algorytmy na listach sortowanych (zad.6-8)");
		printf("\n\t3 - algorytmy na listach dwustronnych (zad.9)");
		printf("\n\t4 - operacje na drzewie (zad.13)");
		printf("\n\th - sortowanie przez kopce (zad.21)");
		//printf("\n\t3 - zadania obowiazkowe");
		printf("\n\tz - wyjscie z programu\n");
		c = _getch();
		switch (c) {
		case '1':
			boldf("WYBRANO - LISTY");
			printf(" ...aby przejsc dalej, wcisnij dowlony klawisz\n");
			_getch();
			system("cls");

			submenu_lists_run();

			break;
		case '2':
			boldf("WYBRANO - LISTY SORTOWANE");
			printf(" ...aby przejsc dalej, wcisnij dowlony klawisz\n");
			_getch();
			system("cls");

			submenu_sortlists_run();

			break;
		case '3':
			boldf("WYBRANO - LISTY DWUSTRONNE");
			printf(" ...aby przejsc dalej, wcisnij dowlony klawisz\n");
			_getch();
			system("cls");

			submenu_liststw_run();

			break;

		case '4':
			boldf("WYBRANO - DRZEWA");
			printf(" ...aby przejsc dalej, wcisnij dowlony klawisz\n");
			_getch();
			system("cls");
			
			submenu_trees_run();

			break;

		case 'n':
			boldf("WYBRANO - ZADANIA OBOWIAZKOWE");
			printf(" ...aby przejsc dalej, wcisnij dowlony klawisz\n");
			_getch();
			system("cls");
			///
			break;

		case 'h':
			boldf("WYBRANO - HEAPSORT");
			printf(" ...aby przejsc dalej, wcisnij dowlony klawisz\n");
			_getch();
			system("cls");
			
			heapsort_run();

			break;

		case 'z':		
			boldf("Czy napewno chcesz zakonczyc program? Wcisnij y, aby zakonczyc...");
			y = _getch();
			if (y == 'y') 
			{ 
				system("cls");
				boldf("DZIEKUJE ZA UWAGE");
				_getch();
				run = 0;
				break;
			}
			system("cls");
			break;

		default:
			boldf("Wybrano nieprawidlowa opcje, sprobuj ponownie");
			_getch();
			system("cls");
			break;
		}

	}
}