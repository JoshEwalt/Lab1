/*
	Josh Ewalt
	Semester 2
	Due 1/20/2021
	Lab 1: C++ Class Example
	Description:  Create a student class that will store important information about a student.
	As a part of this lab, a client file needs to be created to test the class by displaying to
	the screen all the attributes and display all classes that match a user requested grade.
*/
#include "Student.h"
int Student::getGradeByClass(string className) {
	for (int num = 0; num < 100; num++)
		if (classes[num] == className)
			return grades[num];
	return 0;
}

string Student::getStudentName() { return studentName; }



int Student::getLastClassListSize() { return last; }

int Student::getSemesterByClass(string className) {
	for (int num = 0; num < 100; num++)
		if (classes[num] == className)
			return semesters[num];
	return -1;
}
void Student::setStudentName(string newStudentName) { studentName = newStudentName; }
void Student::setStudentId(int newStudentId) { studentId = newStudentId; }
void Student::calculateGPA() {
	float total = 0;
	for (int num = 0; num < currentIndex; num++) {
		int g = grades[num];
		if (g >= 90) { 
			total += 4; continue; 
		}
		else if (g >= 80) { 
			total += 3; continue; 
		}
		else if (g >= 70) { 
			total += 2; continue; 
		}
		else if (g >= 60) { 
			total += 1; continue; 
		}
	}
	if (total > 0)
		gpa = total / (float)currentIndex;
}
void Student::addClass(string name, int grade, int semester) {
	if (currentIndex == 100) {
		cout << studentName << " has reached the limit of 100" << endl;
		return;
	}
	grades[currentIndex] = grade;
	classes[currentIndex] = name;
	semesters[currentIndex] = semester;
	currentIndex++;
}

float Student::getGPA() { return gpa; }



int Student::getStudentId() { return studentId; }

string* Student::getClassesByGrade(char grade) {
	grade = toupper(grade);
	int gradeInt;
	switch (grade) {
		case 'A': 
			gradeInt = 90; 
			break;
		case 'B': 
			gradeInt = 80; 
			break;
		case 'C':
			gradeInt = 70; 
			break;
		case 'D': 
			gradeInt = 60; 
			break;
		case 'F': 
			gradeInt = 50; 
			break;
		default: 
			cout << "Error: " << grade << " is an invalid grade!" << endl; 
			return new string[0];
	}
	int total = 0;
	for (int num = 0; num < currentIndex; num++) {
		if ((grade == 'A' && grades[num] >= 100) || ((int)((float)grades[num] / 10) == (int)((float)gradeInt / 10)) || (grade == 'F' && grades[num] <= 50)) {
			total += 1;
		}
	}
	string* newClasses = new string[total];
	int index = 0;
	for (int num = 0; num < currentIndex; num++) {
		if ((grade == 'A' && grades[num] >= 100) || ((int)((float)grades[num] / 10) == (int)((float)gradeInt / 10)) || (grade == 'F' && grades[num] <= 50)) {
			newClasses[index] = classes[num];
			index += 1;
		}
	}
	last = total;
	return newClasses;
}