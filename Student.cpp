////////////////////////////////////////////////////////////////////////////////
// Main File:        main.cpp
// This File:        Student.cpp
// Other Files:      UndergradStudent.cpp, GradStudent.cpp
// Semester:         CS 368 Spring 2018
//
// Author:           Manuel T. Gomez
// Email:            gomez@cs.wisc.edu
// CS Login:         gomez
//
/////////////////////////// OTHER SOURCES OF HELP //////////////////////////////
//                   fully acknowledge and credit all sources of help,
//                   other than Instructors and TAs.
//
// Persons:		N/A         
// 
//
// Online sources:  	N/A
//
// 
//////////////////////////// 80 columns wide ///////////////////////////////////

#include <iostream>
#include "Student.hpp"

int Student::numStudents = 0; //The number of references of this class.
static int ID = 0;	      //The monotonically increasing ID per student.

Student::Student (std::string name, int yearOfBirth,
 const std::vector<double> &assignmentsScore,
 double projectScore) {
	Student::name = name; 		    	      //The name of student.
	Student::yearOfBirth = yearOfBirth;           //The year of birth of student
	Student::assignmentsScore = assignmentsScore; //Vect of student's assignment scores.
	Student::projectScore = projectScore;	      //Vect of their project scores.
	++Student::numStudents;			      //Increment num references made.	
}

int Student::getId() {
	++ID;	//Increment ID; lowest ID is 1.
	return ID;
}

std::string Student::getName() {
	return name;
}

int Student::getYearOfBirth() {
	return yearOfBirth;
}

int Student::getAge() {
	return 2018 - getYearOfBirth(); //Current year - YOB = age.
} 

const std::vector<double> &Student::getAssignmentsScore() {
	return assignmentsScore;
}

double Student::getProjectScore() {
	return projectScore;
}

int Student::getNumStudents() {
	return numStudents;
}

void Student::printDetails() {
	std::cout << "STUDENT DETAILS:\n";
	std::cout << "Id = " << getId() << "\n";
	std::cout << "Name = " << getName() << "\n";
	std::cout << "Age = " << getAge() << "\n";

	std::vector<double> asm_grades = getAssignmentsScore();
	std::vector<double>::iterator it; //Iterator to assignmentsScore.
	
	//**Displaying grades from assignments.**
	std::cout << "Assignments = [";
	for (it = asm_grades.begin(); it != asm_grades.end() - 1; it++)
		std::cout << *it << ", ";
	std::cout << asm_grades.back() << "]\n";
	
	std::cout << "Project = " << getProjectScore() << "\n";
	std::cout << "Total = " << getTotal() << "\n";
	std::cout << "Grade = " << getGrade() << "\n";
}
