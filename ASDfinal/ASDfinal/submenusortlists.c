#include "submenulists.h"
/*
void enter_series(list *_list) {
	int _value = 0, _doit = 1;
	system("cls");
	boldf("Dodawanie do listy:");
	list_print(&_list);
	while (_doit)
	{
		printf("\n wpisz wartosc jaka ma byc dodana do listy, wartosc ujemna zakonczy dodawanie\n");
		scanf(" %d", &_value);
		if (_value < 0)
		{
			printf("\n wprowadzono wartosc ujemna, zakonczono dodawanie do listy");
			_getch();
			_doit = 0;
		}
		else
		{
			push_front(&_list, _value);
		}
	}
	system("cls");
	boldf("Zawartosc listy:");
	list_print(_list);
	_getch();
}
*/
void submenu_sortlists_run() {
	list *li1s = 0;

	list *ls2 = 0;
	list *ls3 = 0;

	int run = 1;
	while (run)
	{
		system("cls");
		boldf("MENU LIST SORTOWANYCH ROSNACO (zad 6-8) WYBIERZ OPCJE:");
		printf("\n\t1 - dodawanie do listy");
		printf("\n\t2 - dodawanie do listy (z uzyciem wartownika)");
		printf("\n\t7 - laczenie list");
		printf("\n\t8 - porownywanie list");
		printf("\n\tz - powrot do menu glownego\n");
		int c = 0, cc = 0, doit = 1, y = 0, flag = 0;
		c = _getch();

		switch (c) {
			int value = 0;
		case '1':
			system("cls");
			boldf("Dodawanie do listy:");
			list_print(li1s);
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
					push_sorted(&li1s, value);
				}
			}
			system("cls");
			boldf("Zawartosc listy:");
			list_print(li1s);
			_getch();
			break;

		case '2':
			system("cls");
			boldf("Dodawanie do listy (z uzyciem wartownika):");
			list_print(li1s);
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
					push_sorted_sentinel(&li1s, value);
				}
			}
			system("cls");
			boldf("Zawartosc listy:");
			list_print(li1s);
			_getch();
			break;

		case '3':
			system("cls");
			pop_front(&li1s);
			boldf("Usunieto element z poczatku listy...");
			_getch();
			system("cls");
			break;

		case '4':
			system("cls");
			pop_back(&li1s);
			boldf("Usunieto element z konca listy...");
			_getch();
			system("cls");
			break;

		case '7':
			system("cls");
			list *li2s = 0;
			list *li3s = 0;
			boldf("Wprowadzanie szeregu danych dla pierwszej listy");
			while (doit)
			{
				printf("\n wpisz wartosc jaka ma byc dodana do listy, wartosc ujemna zakonczy dodawanie\n");
				scanf(" %d", &value);
				if (value < 0)
				{
					printf("\n wprowadzono wartosc ujemna, zakonczono dodawanie do listy\n");
					_getch();
					doit = 0;
				}
				else
				{
					push_sorted(&li2s, value);
				}
			}
			doit = 1;
			boldf("Wprowadzanie szeregu danych dla drugiej listy");
			while (doit)
			{
				printf("\n wpisz wartosc jaka ma byc dodana do listy, wartosc ujemna zakonczy dodawanie\n");
				scanf(" %d", &value);
				if (value < 0)
				{
					printf("\n wprowadzono wartosc ujemna, zakonczono dodawanie do listy\n");
					_getch();
					doit = 0;
				}
				else
				{
					push_sorted(&li3s, value);
				}
			}
			system("cls");
			boldf("Polaczone zostana listy:");
			list_print(li2s);
			list_print(li3s);
			printf("\n ...aby przejsc dalej, wcisnij dowlony klawisz");
			_getch();
			li2s = merge_lists(&li2s, &li3s);
			system("cls");
			boldf("Listy polaczono w :");
			list_print(li2s);
			_getch();
			system("cls");
			break;

		case '8':
			system("cls");
			list *li4s = 0;
			list *li5s = 0;
			list *li4comp = 0;
			list *li5comp = 0;
			boldf("Wprowadzanie szeregu danych dla pierwszej listy");
			while (doit)
			{
				printf("\n wpisz wartosc jaka ma byc dodana do listy, wartosc ujemna zakonczy dodawanie\n");
				scanf(" %d", &value);
				if (value < 0)
				{
					printf("\n wprowadzono wartosc ujemna, zakonczono dodawanie do listy\n");
					_getch();
					doit = 0;
				}
				else
				{
					push_sorted(&li4s, value);
				}
			}
			doit = 1;
			boldf("Wprowadzanie szeregu danych dla drugiej listy");
			while (doit)
			{
				printf("\n wpisz wartosc jaka ma byc dodana do listy, wartosc ujemna zakonczy dodawanie\n");
				scanf(" %d", &value);
				if (value < 0)
				{
					printf("\n wprowadzono wartosc ujemna, zakonczono dodawanie do listy\n");
					_getch();
					doit = 0;
				}
				else
				{
					push_sorted(&li5s, value);
				}
			}
			system("cls");
			boldf("Porownane zostana listy:");
			list_print(li4s);
			list_print(li5s);
			printf("\n ...aby przejsc dalej, wcisnij dowlony klawisz\n");
			_getch();
			compare_lists(&li4s, &li5s, &li4comp, &li5comp);
			list_print(li4comp);
			list_print(li5comp);
			_getch();
			system("cls");
			break;

		case 'w':
			system("cls");
			boldf("Zawartosc listy:");
			list_print(li1s);
			printf("\n ...aby przejsc dalej, wcisnij dowlony klawisz");
			_getch();
			system("cls");
			break;

		case 'r':
			system("cls");
			boldf("Zawartosc listy wypisana od tylu:");
			list_print_rev(li1s);
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