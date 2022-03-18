#pragma once
#include <iostream>
#include "windows.h"
#include <iomanip>
#include <cmath>
#include <fstream>
#include <string>
#include"Header.h"

void gotoxy(short int x, short int y);

void textColor(int color);

void textBgColor(int colorText, int colorBG);

void drawRectangle(int positionX, int positionY, int width, int height, int color);

int ReturnX();

int ReturnY();

void hidePointer();

void showPointer();

void DrawAppName(int TextColor, int BgColor);

void drawBoder(int positionX, int positionY, int width, int height, int color);
void printtext(string str, int x, int y);
void FixConsoleWindow();


