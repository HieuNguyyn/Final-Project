#pragma once
#include <iostream>
#include "windows.h"
#include <iomanip>
#include <fstream>
#include <string>
#include <iostream>
#include"Header.h"
#include "ConsoleProcess.h"
#pragma warning(disable : 4996)
using namespace std;

void LoginInterface(User& user);

void repeatLogin(User& user);

int CheckLogin(User& user);

void insertUserName(string& username);

void insertPassword(string& password);


