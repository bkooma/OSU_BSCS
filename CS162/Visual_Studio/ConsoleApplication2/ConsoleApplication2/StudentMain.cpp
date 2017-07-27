#include "Student.hpp"
#include <iostream>
#include <string>
#include "StudentMain.h"

const int MAX = 2;

int main()
{
	double studentScore;
	std::string studentName;

	double* scores = new double[MAX];
	std::string* students = new std::string[MAX];

	Student **pStudent = new Student*[MAX];
//	Student* pStudent[MAX];

	for (int index = 0; index < MAX; index++)
	{
		std::cout << "Enter the student's name: " << std::endl;
		std::cin >> studentName;

		std::cout << "Enter the student's score: " << std::endl;
		std::cin >> studentScore;

		*(students + index) = studentName;
		*(scores + index) = studentScore;
		pStudent[index] = new Student(studentName, studentScore);
	}

//	pStudent[0] = new Student("Cat", 75);
	
//	for (int index = 0; index < 4; index++)
//	{
//		Student* account1;
//		pStudent[index] = &account1("Harry Potter", 95.6);
//	}

//	Student account1("Harry Potter", 95.6);
//  Student account2("Random Guy", 56.7);
//	Student account3("That Guy", 98.5);

	std::cout << "Student Name1: " << *(pStudent) << std::endl;
	std::cout << "Student Name1: " << pStudent[0]->getStudentName() << std::endl;
	std::cout << "Student Name1: " << pStudent[0] << std::endl;
	std::cout << "Student Name1: " << *(students) << std::endl;
	std::cout << "Student Score: " << *(pStudent + 1) << std::endl;
	std::cout << "Student Score: " << *(scores) << std::endl;
//	std::cout << "Student Name2: " << pStudent.getStudentName() << std::endl;
//	std::cout << "Student Score: " << account2.getStudentScore() << std::endl;
}