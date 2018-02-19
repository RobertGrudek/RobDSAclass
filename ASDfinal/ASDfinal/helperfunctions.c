#include "helperfunctions.h"

void fflushstdin(void)
{
	int c;
	while ((c = fgetc(stdin)) != EOF && c != '\n');
}

void boldf(const char *tekst) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	WORD saved_attributes;

	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	saved_attributes = consoleInfo.wAttributes;

	printf("\n");
	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE);
	printf("%s ", tekst);
	SetConsoleTextAttribute(hConsole, saved_attributes);
	printf("\n\n");
}

void print_arr(char *arr) {
	for (int i = 0; i <= strlen(arr) + 1; i++) { printf("%c", arr[i]); }
}

void spacer(int n, int m, int p) {
	for (int i = 0; i < n; i++) { printf("\n"); }
	for (int i = 0; i < p; i++) { printf("====="); }
	for (int i = 0; i < m; i++) { printf("\n"); }
}