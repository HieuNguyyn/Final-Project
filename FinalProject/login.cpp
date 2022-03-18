#include "login.h"
#include"Header.h"
#include<stdio.h> 
#include<conio.h> 

void LoginInterface(User& user) {
    showPointer();
    textBgColor(2, 0);
    system("cls");

    user.ID = user.Password = "";

    textColor(0);
    drawRectangle(47, 15, 27, 10, 11);
    printtext("USERNAME : ", 48, 16);
    printtext("PASSWORD : ", 48, 19);

    drawRectangle(48, 17, 25, 1, 15);
    drawRectangle(48, 20, 25, 1, 15);
    gotoxy(48, 22);
    cout << "ENTER TO LOGIN";

    gotoxy(48, 17);
    insertUserName(user.ID);

    gotoxy(48, 20);
    insertPassword(user.Password);
}

//void repeatLogin(User& user) {
//    textColor(0);
//    do
//    {
//        system("cls");
//        LoginInterface(user);
//
//        if (CheckLogin(user) == -1)
//        {
//            gotoxy(48, 24);
//            cout << "LOGIN FAIL";
//            hidePointer();
//            Sleep(900);
//        }
//    } while (CheckLogin(user) == -1);
//    gotoxy(48, 24);
//    cout << "LOGIN SUCCESSFUL";
//    hidePointer();
//    Sleep(900);
//    system("cls");
//    if (user.role == 1) menuStudent(user);
//    else menuStaff(user);
//}

int CheckLogin(User& user) {
    fstream f1, f2;
    f1.open("file_save/login_info.csv", ios::in);
    f2.open("file_save/login_info.csv", ios::in);
    if (!f1.is_open() || !f2.is_open())
        printtext("DATA NOT EXISTS", 80, 20);
    string row, column;
    int caseUser;
    bool check = false;
    while (!f1.eof())
    {
        getline(f1, row);
        while (!f2.eof())
        {
            getline(f1, column, ',');
            if (column.compare(user.ID) == 0) {
                getline(f2, column, ',');
                if (column.compare(user.Password) == 0) {
                    check = true;
                    getline(f2, column, ',');
                    caseUser = stoi(column, 0, 10);
                    break;
                }
            }
            getline(f2, column);
            break;
        }
        if (check == true) break;
    }

    if (check == false) return -1; // Không phải giáo viên hay sinh viên nên return -1
    user.role = caseUser;
    if (caseUser == 1) {
        getline(f2, column, '\n');
        user.info.Class = column;
    }
    f1.close();
    f2.close();

    return caseUser;
}

void insertUserName(string& username) {
    showPointer();
    char index = getch();
    while (index != 13) {
        if (index == 8) {
            if (username.size() > 0) {
                username.pop_back();
                gotoxy(ReturnX() - 1, ReturnY());
                cout << " ";
                gotoxy(ReturnX() - 1, ReturnY());
            }
        }
        else if (index >= 33 && index <= 126 && username.size() <= 15) {
            cout << index;
            username.push_back(index);
        }
        index = getch();
    }
}

void insertPassword(string& password) {
    showPointer();
    password = "";
    char index = getch();
    while (index != 13) {
        if (index == 8) {
            if (password.size() > 0) {
                password.pop_back();
                gotoxy(ReturnX() - 1, ReturnY());
                cout << " ";
                gotoxy(ReturnX() - 1, ReturnY());
            }
        }
        else if (index >= 33 && index <= 126 && password.size() <= 15) {
            cout << "*";
            password.push_back(index);
        }
        index = getch();
    }
}