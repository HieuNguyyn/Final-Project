#pragma once
#include <iostream>
#include "windows.h"
#include <iomanip>
#include <cmath>
#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdio.h> 
#include <conio.h> 
using namespace std;

struct Mark {
	string ID;
	string Name;
	string C;
	float Total_Mark;
	float Final_Mark;
	float Midterm_Mark;
	float Other_Mark;
};

struct MarkNode {
	Mark data;
	MarkNode* pNext;
};

struct Data {
	int NO_inclass;
	string IDstd;
	string name;
	string sex;// 0 is male, 1 is female
	string Bir;
	string IDsocial;
	string Class;
	MarkNode* phead;
};

struct Course {
	string ID_course;
	string name;
	string teacher;
	int Num_of_creadit;
	int Max_student;
	string Schedule;
	string session[2];
	string DayOfWeek;
	MarkNode* pHead;
};

struct Class {
	string name;
	string MajorClass;
	int Num_of_std_now;
	int Year;
};

struct Semester {
	string Name;
	int Num_of_std_now;
	string schoolyear;
	string date_star;
	string date_end;
	Course Course;
	Class Class;
};

struct SchoolYear {
	Semester semester;
	string year; //ex: 2012
	int Num_of_std_now;
	string date_star;
	string date_end;
};

struct User {
	string ID;
	string Password;
	int role;// 0 is academic staff, 1 is student
	Data info;
};

