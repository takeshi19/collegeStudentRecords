////////////////////////////////////////////////////////////////////////////////
// Main File:        main.cpp
// This File:        GradStudent.cpp
// Other Files:      UndergradStudent.cpp, processStudent.cpp
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
// Persons:             N/A         
// 
//
// Online sources:      N/A
//
// 
//////////////////////////// 80 columns wide ///////////////////////////////////

#include <iostream>
#include "GradStudent.hpp"
#include <vector>
#include <numeric>

int GradStudent::numGradStudents = 0;

//**Constructor of graduate student class.**
GradStudent::GradStudent(std::string name,
                int yearOfBirth,
                const std::vector<double> &assignmentsScore,
                double projectScore,
                std::string researchArea,
                std::string advisor) : Student(name, yearOfBirth,
                                assignmentsScore, projectScore) {
	
	this->researchArea = researchArea;
	this->advisor = advisor;	
	++GradStudent::numGradStudents;
}

std::string GradStudent::getResearchArea() {
	return researchArea;
}

std::string GradStudent::getAdvisor() {
	return advisor;
}

int GradStudent::getNumStudents() {
	return numGradStudents;
}

void GradStudent::printDetails() {
	Student::printDetails();
	std::cout << "Type = Graduate Student\n";
	std::cout << "Research Area = " << researchArea << "\n";
	std::cout << "Advisor = " << advisor << "\n\n";
}

double GradStudent::getTotal() {
	std::vector<double> asm_scores = getAssignmentsScore();
        double avg_scores = std::accumulate(asm_scores.begin(), asm_scores.end(), 0)/asm_scores.size();

        return avg_scores * 0.5 + getProjectScore() * 0.5;
}

std::string GradStudent::getGrade() {
	if (getTotal() >= 80) 
		return "CR";
	return "N";
}



