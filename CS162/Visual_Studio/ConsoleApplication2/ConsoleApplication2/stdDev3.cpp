#include "Student.hpp"
#include <iostream>
#include <string>
#include "StudentMain.h"

double stdDev(Student *studentInfo, int sizeArr) {
	double sum = 0, mean = 0, sumSq = 0;

	for (int i = 0; i < sizeArr; i++)
	{
		sum = sum + studentInfo[i].getStudentScore();
	}
	mean = sum / sizeArr;

	for (int i = 0; i < sizeArr; i++)
	{
		sumSq += (mean - studentInfo[i].getStudentScore()) * (mean - studentInfo[i].getStudentScore());
	}
	std::cout << "Sum: " << sum << std::endl;
	std::cout << "Sum of the squares: " << sumSq << std::endl;
	return sqrt(sumSq / sizeArr);
}

const int MAX = 4;

int main()
{
	double standardDev;
	double studentScore;
	std::string studentName;

	Student* pStudent;
	pStudent = new Student[MAX];

	for (int index = 0; index < MAX; index++)
	{
		std::cout << "Enter the student's name: " << std::endl;
		std::cin >> studentName;

		std::cout << "Enter the student's score: " << std::endl;
		std::cin >> studentScore;

		pStudent[index] = Student(studentName, studentScore);
	}
	standardDev = stdDev(pStudent, MAX);

	std::cout << "Student Name1: " << pStudent[0].getStudentName() << std::endl;
	std::cout << "Standard Deviation: " << standardDev << std::endl;

	delete[] pStudent;
	return 0;
}