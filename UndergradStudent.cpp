#include <numeric>
#include <iostream>
#include "UndergradStudent.hpp"

int UndergradStudent::numUndergradStudents = 0;
//Calling on constructor of Student to init our derived class
UndergradStudent::UndergradStudent(std::string name,
                     int yearOfBirth,
                     const std::vector<double> &assignmentsScore,
                     double projectScore,
                     std::string residenceHall,
                     std::string yearInCollege) : Student (name, yearOfBirth,
 				assignmentsScore, projectScore) {

	this->residenceHall = residenceHall; //The hall that the ugrad student resides in.
	this->yearInCollege = yearInCollege; //The current year/grade level of student.
	++UndergradStudent::numUndergradStudents;
}

std::string UndergradStudent::getResidenceHall() {
	return residenceHall;
}

std::string UndergradStudent::getYearInCollege() {
	return yearInCollege;
}

int UndergradStudent::getNumStudents() {
	return numUndergradStudents;
}

void UndergradStudent::printDetails() {
	Student::printDetails(); //Calling on overrided function
	std::cout << "Type = Undergraduate Student\n";
	std::cout << "Residence Hall = " << getResidenceHall() << "\n";
	std::cout << "Year in College = " << getYearInCollege() << "\n\n";
}

double UndergradStudent::getTotal() {
	std::vector<double> asm_scores = getAssignmentsScore();
	double avg_scores = std::accumulate(asm_scores.begin(), asm_scores.end(), 0)/asm_scores.size();

	return avg_scores * 0.7 + getProjectScore() * 0.3;
}

std::string UndergradStudent::getGrade() {
	if (getTotal() >= 70.0) 
		return "CR";	//Return credit if grade >= 70.
	return "N";		//Return no-credit if < 70.
}
