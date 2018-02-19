#include "submenutrees.h"

void submenu_trees_run() {
	bTree *t1 = NULL;
	bTree *tmpt = NULL;
	srand((unsigned)time(NULL));
	char prebuffer[2048];
	char buffer[2048];
	char* extr_data;
	int run = 1, count = 0;
	while (run)
	{
		system("cls");
		boldf("MENU OPERACJI NA DRZEWIE:");
		printf("\n\t1 - dodawanie do drzewa");
		printf("\n\t2 - wyswietlenie drzewa");
		printf("\n\t3 - usuwanie klucza");
		printf("\n\t4 - najwiekszy element drzewa");
		printf("\n\t5 - najmniejszy element drzewa");
		printf("\n\tz - powrot do menu glownego\n");
		int c = 0, cc = 0, doit = 1, y = 0, flag = 0;
		c = _getch();

		switch (c) {
			int value = 0;
		
		case '1':
			system("cls");
			boldf("Dodawanie do drzewa:");
			count = 0;
			while (count < 10)
			{
				printf("\n wpisz wartosc jaka ma byc dodana do drzewa\n");
				memset(prebuffer, 0, sizeof prebuffer);
				scanf("%s", &prebuffer);
				add_bTree(&t1, NULL, prebuffer);
				print_bTree(t1);
				count++;
			}
			system("cls");
			boldf("Utworzone drzewo:");
			print_bTree(t1);
			_getch();
			break;

		case '2':
			system("cls");
			boldf("Zawartosc drzewa:");
			print_bTree(t1);
			printf("\n ...aby przejsc dalej, wcisnij dowlony klawisz");
			_getch();
			break;

		case '3':
			system("cls");
			print_bTree(t1);
			boldf("Wprowadz element do usuniecia:");
			scanf("%s", &buffer);
			del_node_bTree(&t1, buffer);
			boldf("Po usunieciu:");
			print_bTree(t1);
			printf("\n ...aby przejsc dalej, wcisnij dowlony klawisz");
			_getch();
			break;

		case '4':
			system("cls");
			boldf("Maksymalny element drzewa:");
			print_bTree(t1);
			boldf("To:");
			tmpt = MaxT(&t1);
			extr_data = (*tmpt)->data;
			for (int i = 0; i <= strlen(extr_data + 1); i++) { printf("%c", extr_data[i]); }
			printf("\n ...aby przejsc dalej, wcisnij dowlony klawisz");
			_getch();
			break;

		case '5':
			system("cls");
			memset(extr_data, 0, sizeof extr_data);
			boldf("Minimalny element drzewa:");
			print_bTree(t1);
			boldf("To:");
			tmpt = MinT(&t1);
			extr_data = (*tmpt)->data;
			for (int i = 0; i <= strlen(extr_data + 1); i++) { printf("%c", extr_data[i]); }
			printf("\n ...aby przejsc dalej, wcisnij dowlony klawisz");
			_getch();
			break;

		case '6':
			tmpt = nast_t(&t1);
			extr_data = (*tmpt)->data;
			for (int i = 0; i <= strlen(extr_data + 1); i++) { printf("%c", extr_data[i]); }
			_getch();
			break;

		case 'l': //to jest "L"
			system("cls");
	
			int r, a, b = 0;
			count = 0;
			while (count < 10) {
				memset(buffer, 0, sizeof buffer);
				r = rand() % (9 - 1) + 1;
				_itoa(r, buffer, 10);
				//scanf("%s", buffer); //&tab[0]
				//spacer(1, 1, 2);
				//print_arr(buffer);
				add_bTree(&t1, NULL, buffer);
				count++;
			}

			spacer(1, 1, 2);
			print_bTree(t1);
			spacer(1, 1, 2);
			parent_inorder(&b);
			boldf("Ay przejsc dalej wcisnij dowolny przycisk...");
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