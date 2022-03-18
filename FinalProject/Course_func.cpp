#include "Course_func.h"

void MoveUpMenu(int X, int& Y, int dis) {
	Y = Y - (dis + 1);
	gotoxy(X, Y);
}
void MoveDownMenu(int X, int& Y, int dis) {
	Y = Y + (dis + 1);
	gotoxy(X, Y);
}

int MoveAndChoose(int a, string A[], int _X, int _Y, int dis) { 
	char _COMMAND;
	int X = _X, Y = _Y;
	int i = 0;
	int maxlength = A[0].length();
	for (int j = 1; j < a; j++) {
		if (maxlength < A[j].length()) {
			maxlength = A[j].length();
		}
	}
	while (1) {
		_COMMAND = toupper(_getch());
		if (_COMMAND == 27) {
			return -1;
		}
		else {
			if (i >= 0 && i < a && Y <= 23 + a) {
				if (_COMMAND == 72 && Y > _Y) {
					drawRectangle(X, Y, maxlength, 1, 6);
					gotoxy(X, Y);
					textBgColor(0, 6);
					cout << A[i];
					MoveUpMenu(X, Y, dis);
					i--;
					drawRectangle(X, Y, maxlength, 1, 0);
					textBgColor(6, 0);
					gotoxy(X, Y);
					cout << A[i];
					textBgColor(0, 15);
				}
				else if (_COMMAND == 80 && Y < _Y + (dis + 1) * (a - 1)) {
					drawRectangle(X, Y, maxlength, 1, 6);
					gotoxy(X, Y);
					textBgColor(0, 6);
					cout << A[i];
					MoveDownMenu(X, Y, dis);
					i++;
					drawRectangle(X, Y, maxlength, 1, 0);
					textBgColor(6, 0);
					gotoxy(X, Y);
					cout << A[i];
					textBgColor(0, 15);
				}
				else if (_COMMAND == 13) {
					return i;
				}
			}
		}
	}
}