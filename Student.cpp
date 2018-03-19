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

int getID() {
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
	return 2016 - getYearOfBirth(); //Current year - YOB = age.
} 

//FIXME how to return properly?
const std::vector<double>& Student::getAssignmentsScore() {
	return assignmentsScore;
}

double Student::getProjectScore() {
	return projectScore;
}

int Student::getNumStudents() {
	return numStudents;
}
//Implement the virtual method printDetails() which should print the id, name, age, assignments score, project score, total score, and grade for a given student

//void printDetail
















