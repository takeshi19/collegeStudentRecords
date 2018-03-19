#include <iostream>
#include "Student.hpp"

int Student::numStudents = 0; //The number of references of this class.

/**
 * @brief Constructor for Student class.
 * 
 * @param 
 */
Student::Student (std::string name, int yearOfBirth,
 const std::vector<double> &assignmentsScore,
 double projectScore) {
	Student::name = name; 		    	      //The name of student.
	Student::yearOfBirth = yearOfBirth;           //The year of birth of student
	Student::assignmentsScore = assignmentsScore; //Vect of student's assignment scores.
	Student::projectScore = projectScore;	      //Vect of their project scores.
	
	
}

/**
 *
 *
 *
 *
 */
