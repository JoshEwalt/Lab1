/*
	Josh Ewalt
	Semester 2
	Due 1/20/2021
	Lab 1: C++ Class Example
	Description:  Create a student class that will store important information about a student.
	As a part of this lab, a client file needs to be created to test the class by displaying to
	the screen all the attributes and display all classes that match a user requested grade.
*/
#pragma once
#include <iostream>

using namespace std;

class Student {
public:
	int grades[100];

	string studentName;
	int studentId;


	string classes[100];
	float gpa;
	int currentIndex = 0;

	int semesters[100];
	int last = 0;
	int getLastClassListSize();
	string getStudentName();
	int getStudentId();


	int getSemesterByClass(string className);
	void addClass(string name, int grade, int semester);
	string* getClassesByGrade(char grade);
	void calculateGPA();
	float getGPA();

	void setStudentName(string newStudentName);
	void setStudentId(int newStudentId);
	int getGradeByClass(string className);
};