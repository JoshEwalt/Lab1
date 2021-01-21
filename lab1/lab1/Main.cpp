/*
	Josh Ewalt
	Semester 2
	Due 1/20/2021
	Lab 1: C++ Class Example
	Description:  Create a student class that will store important information about a student.
	As a part of this lab, a client file needs to be created to test the class by displaying to
	the screen all the attributes and display all classes that match a user requested grade.
*/
#include <iostream>
#include "Student.h"
#include <array>

using namespace std;

int main() {
	Student jimmy = Student();
	jimmy.setStudentName("Jimmy Qwerty");
	jimmy.setStudentId(5445345);
	jimmy.addClass("Data Structures", 98, 2);
	jimmy.addClass("Java", 89, 1);
	jimmy.addClass("C++", 100, 1);
	jimmy.addClass("HTML", 100, 2);
	jimmy.addClass("Intro To Woods", 57, 1);
	jimmy.addClass("Government", 4, 2);
	jimmy.addClass("Math A", 23, 1);
	jimmy.addClass("Math B", 40, 2);

	//inputs grade

	string className;
	int classGrade;
	int classSemester;
	char ex = 'y';
	while (ex != 'n') {
		cout << "Enter class name: ";
		cin >> className;
		cout << "\nEnter the grade for " << className << " (0-100): ";
		cin >> classGrade;
		cout << "\nEnter the semester " << className << " (1-2): ";
		cin >> classSemester;

		jimmy.addClass(className, classGrade, classSemester);
		cout << "\nWould you like to add another class? y/n: ";
		cin >> ex;
		ex = tolower(ex);
	}
	char grade;
	ex = 'y';

	//Inputs and searches class letter

	while (ex != 'n') {
		cout << "Enter a letter grade to find the matching classes: ";
		cin >> grade;

		string* classes = jimmy.getClassesByGrade(grade);
		int classCount = jimmy.getLastClassListSize();

		if (classCount > 0) {
			cout << endl << jimmy.getStudentName() << "'s classes with " << (char)toupper(grade) << "s:\n";

			for (int num = 0; num < classCount; num++) {
				cout << "-  " << classes[num] << " (" << jimmy.getGradeByClass(classes[num]) << "/100)\n";
			}
		}
		cout << "\nWould you like to search for another grade? y/n: ";
		cin >> ex;
		ex = tolower(ex);
	}
	jimmy.calculateGPA();

	cout << "\nGPA: " << jimmy.getGPA() << endl;
	cout << "History Grade: " << jimmy.getGradeByClass("Math A") << endl;
	cout << "Student Id: " << jimmy.getStudentId() << endl;
	cout << "Government Semester: " << jimmy.getSemesterByClass("HTML") << endl;
	return 0;
}