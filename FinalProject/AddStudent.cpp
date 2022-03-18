#include "AddStudent.h"
#include "ConsoleProcess.h"
#include "Header.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdlib.h>
#include <string>
#include <fstream>
#include "ListClass.h"

using namespace std;
const string csv_tail = ".csv";

void AddStudentToClass()
{
	
}

void AddRandomInfoStudentToClass()
{
}

int RunMenuAddInfoStudentToClass()
{
	char ch;
	int command;
	while (true)
	{
		showPointer();
		system("cls");
		gotoxy(40, 12);

		string MenuAdd[] = { "1. Add One Student To Class",
		"2. Import Info Student From File To Class",
		"3. Exit" };
		/*drawMenu(MenuAdd, 3, 45, 12, 1, &drawMenuView);*/
		command = MoveAndChoose(3, MenuAdd, 45, 12, 1);

		switch (command)
		{
		case 0:
		{
			system("cls");
			AddStudentToClass();
			system("cls");
			break;
		}
		case 1:
		{
			system("cls");
			AddRandomInfoStudentToClass();
			system("cls");
			break;
		}
		case 2:
		{
			textBgColor(10, 11);
			printtext("PRESS ENTER TO GET BACK TO MENU", 40, 20);
			ch = _getch();
			textBgColor(0, 15);
			return 0;
		}
		}
	}
}
