#include "submenulists.h"

void submenu_lists_run() {
	list *li1 = 0;
	int run = 1;
	while (run)
	{
		system("cls");
		boldf("MENU LIST (zad 1-5) WYBIERZ OPCJE:");
		printf("\n\t1 - dodawanie na poczatek listy");
		printf("\n\t2 - dodawanie na koniec listy");
		printf("\n\t3 - usuwanie z poczatku listy");
		printf("\n\t4 - usuwanie z konca listy");
		printf("\n\t5 - usuniecie zadanego klucza");
		printf("\n\t6 - rekurencyjne usuniecie zadanego klucza");
		printf("\n\t7 - wyswietlenie najczestszego klucza");
		printf("\n\t8 - odwrocenie listy");
		printf("\n\t9 - rekurencyjne odwrocenie listy");
		printf("\n\tw - wyswietlenie listy");
		printf("\n\tr - wyswietlenie listy od konca");
		printf("\n\tz - powrot do menu glownego\n");
		int c = 0, doit = 1, y = 0, flag = 0;
		c = _getch();

		switch (c) {
			int value = 0;
		case '1':
			system("cls");
			boldf("Dodawanie na poczatek listy:");
			list_print(li1);
			while (doit)
			{
				printf("\n wpisz wartosc jaka ma byc dodana do listy, wartosc ujemna zakonczy dodawanie\n");
				scanf(" %d", &value);
				if (value < 0) 
				{ 
					printf("\n wprowadzono wartosc ujemna, zakonczono dodawanie do listy");
					_getch();
					doit = 0;
				}
				else
				{
					push_front(&li1, value);
				}
			}
			system("cls");
			boldf("Zawartosc listy::");
			list_print(li1);
			_getch();
			break;

		case '2':
			system("cls");
			boldf("Dodawanie na koniec listy:");
			list_print(li1);
			while (doit)
			{
				printf("\n wpisz wartosc jaka ma byc dodana do listy, wartosc ujemna zakonczy dodawanie\n");
				scanf(" %d", &value);
				if (value < 0)
				{
					printf("\n wprowadzono wartosc ujemna, zakonczono dodawanie do listy");
					_getch();
					doit = 0;
				}
				else
				{
					push_back(&li1, value);
				}
			}
			system("cls");
			boldf("Zawartosc listy:");
			list_print(li1);
			_getch();
			break;

		case '3':
			system("cls");
			pop_front(&li1);
			boldf("Usunieto element z poczatku listy...");
			_getch();
			system("cls");
			break;

		case '4':
			system("cls");
			pop_back(&li1);
			boldf("Usunieto element z konca listy...");
			_getch();
			system("cls");
			break;

		case '5':
			system("cls");
			printf("Wprowadz klucz do usuniecia:\t");
			fflushstdin();
			scanf("%d", &value);
			if (search_for_key(&li1, value))
			{
				del_key(&li1, value);
				printf("\n\tUsunieto klucz... %d", value);		
			}
			else
			{
				printf("\n\tW liscie nie ma podanego klucza");
			}
			_getch();
			system("cls");
			break;

		case '6':
			system("cls");
			printf("Wprowadz klucz do usuniecia:\t");
			fflushstdin();
			scanf("%d", &value);
			if (search_for_key(&li1, value))
			{
				del_key_rec(&li1, value);
				printf("\n\tRekurencyjnie usunieto klucz... %d", value);
			}
			else
			{
				printf("\n\tW liscie nie ma podanego klucza");
			}
			_getch();
			system("cls");
			break;

		case '7':
			system("cls");
			boldf("Najczesciej pojawiajacy sie klucz w liscie:");
			list_print(li1);
			boldf("to:");
			printf("[ %d ]\n", list_most_common(li1));
			printf(" ...aby przejsc dalej, wcisnij dowlony klawisz");
			_getch();
			break;

		case '8':
			system("cls");
			boldf("Lista przed odwroceniem:");
			list_print(li1);
			rev(&li1);
			boldf("Lista po odwroceniu:");
			list_print(li1);
			printf(" ...aby przejsc dalej, wcisnij dowlony klawisz");
			_getch();
			break;

		case '9':
			system("cls");
			boldf("Lista przed odwroceniem:");
			list_print(li1);
			li1 = revr(&li1);
			boldf("Lista po odwroceniu:");
			list_print(li1);
			printf(" ...aby przejsc dalej, wcisnij dowlony klawisz");
			_getch();
			break;
		
		case 'w':
			system("cls");
			boldf("Zawartosc listy:");
			list_print(li1);
			printf("\n ...aby przejsc dalej, wcisnij dowlony klawisz");
			_getch();
			system("cls");
			break;

		case 'r':
			system("cls");
			boldf("Zawartosc listy wypisana od tylu:");
			list_print_rev(li1);
			printf("\n ...aby przejsc dalej, wcisnij dowlony klawisz");
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