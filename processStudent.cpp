///////////////////////////////////////////////////////////////////////////////
// File Name:      processStudent.cpp
//
// Author:         Manuel Takeshi Gomez
// CS email:       gomez@cs.wisc.edu
//
// Description:    Methods to perform some processing on student objects.
///////////////////////////////////////////////////////////////////////////////

#include "processStudent.hpp"

#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <typeinfo>

/**
 *@brief Reads student's data from an input file and either creates a 
 * 	 a grad or undergrad student object based on the data received.
 *	 Then, these objects are added to their respective vectors. 
 *
 *@param inFile, the file to read in with the student data.
 *@param gstudents, the vector of grad student objects being made.
 *@param ugstudents, the vector of undergrad student objs being made.
 */
void fillStudents(std::ifstream &inFile,
                  std::vector<GradStudent> &gstudents,
                  std::vector<UndergradStudent> &ugstudents) {
	
	std::string linetext; //Line of data from inFile.

	//**Splitting the file data using comma as delimeter (line by line).**
	while (getline(inFile, linetext)) {
		//**All students have these 6 common members.**
		std::stringstream ss(linetext); //Getting each word from line.
		std::string type;		//Type of student.
		std::string name;		//Name of student.
		std::string year;		//YOB of student (4 digits).
		
		getline(ss, type, ',');
		getline(ss, name, ',');
		getline(ss, year, ',');

		int yearnum = std::stoi(year); //Convert the string year to int.
		
		/**Reading in consecutive numbers from file line and using them 
		 *as the project and assignments score per student.
		 */
		std::vector<double> scores;    //The scores of the assignments.
		std::string nums;              //Recycled string found after all numbers were read.
		while (getline(ss, nums, ',')) {
			if (!(nums.find_first_not_of("0123456789") == std::string::npos)) 
				break;	       //If finished reading the scores, break loop. 
			double scoreval = std::stod(nums);
			scores.push_back(scoreval);
		}
		double pscore = scores.back(); //Get the project score of student.
		scores.pop_back();	       //Remove the project score to get assignments score.

		//**Determining what type of Student object to make based on the type of student.**
		if (type == "G") {
			std::string advisor;	//Advisor of grad-student.
			getline(ss, advisor, ',');
			//The afternums string here would be the research area. 
			GradStudent gstud(name, yearnum, scores, pscore, nums, advisor);
			gstudents.push_back(gstud); 
		}
		else {
			std::string gradelvl;
			getline(ss, gradelvl, ','); //Grade level of undergrad.
			//The nums string here would be the residence hall.
			UndergradStudent ugstud(name, yearnum, scores, pscore, nums, gradelvl); 
			ugstudents.push_back(ugstud);
		}
	}
	inFile.close();	//Closing the file to avoid leaks in future.
}

/** 
 *@brief Polymorphic function prints out the details of each student- the content
 * 	 of the details vary per type of student (either the printing function
 * 	 from GradStudent.cpp is called or the one from UnderGradStudent.cpp).
 *
 *@param students, Vector of Student objects to call respective functions on.
 */
void printStudents(const std::vector<std::reference_wrapper<Student>> &students) {
	for (auto it = students.begin(); it != students.end(); it++) 
		(*it).get().printDetails();	
}

void computeStatistics(std::vector<std::reference_wrapper<Student>> &students) {

    // TODO: Implement this method.

    // compute the # of students based on the type of students.

    // compute the mean of the total score.

    // sort and print the students based on their total.
}































