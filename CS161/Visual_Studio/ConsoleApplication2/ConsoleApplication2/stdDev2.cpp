#include "Student.hpp"
#include <iostream>
#include <string>
#include "StudentMain.h"

/*double stdDev(double *a, int sizeArr) {
	double sum = 0, mean = 0;
//	Student *newStudent[2];
//	std::cout << "Student Name1: " << newStudent.getStudentName << std::endl;
	
	for (int i = 0; i < sizeArr; i++)
	{
		sum = sum + a[i];
	}
	mean = sum / sizeArr;
	sum = 0;
	for (int i = 0; i < sizeArr; i++)
	{
		sum += pow(mean - a[i], 2);
	}
	std::cout << "Sum: " << sum << std::endl;
	return sqrt(sum/sizeArr);
}
*/

double stdDev(Student *studentInfo[], int sizeArr) {
	double sum = 0, mean = 0;
	//	Student *newStudent[2];
	//	std::cout << "Student Name1: " << newStudent.getStudentName << std::endl;

	for (int i = 0; i < sizeArr; i++)
	{
		sum = sum + studentInfo[i]->getStudentScore();
	}
	mean = sum / sizeArr;
	sum = 0;
	for (int i = 0; i < sizeArr; i++)
	{
		sum += (mean - studentInfo[i]->getStudentScore()) * (mean - studentInfo[i]->getStudentScore());
	}
	std::cout << "Sum: " << sum << std::endl;
	return sqrt(sum / sizeArr);
}

const int MAX = 4;

int main()
{
	double standardDev;
	double studentScore;
	std::string studentName;

//	double* scores = new double[MAX];
//	std::string* students = new std::string[MAX];

	Student **pStudent = new Student*[MAX];  // This works
//	Student* pStudent[MAX];

	for (int index = 0; index < MAX; index++)
	{
		std::cout << "Enter the student's name: " << std::endl;
		std::cin >> studentName;

		std::cout << "Enter the student's score: " << std::endl;
		std::cin >> studentScore;

//		*(students + index) = studentName;
//		*(scores + index) = studentScore;
		pStudent[index] = new Student(studentName, studentScore);
	}
	standardDev = stdDev(pStudent, MAX);

	std::cout << "Student Name1: " << *(pStudent) << std::endl;
	std::cout << "Student Name1: " << pStudent[0]->getStudentName() << std::endl;
	std::cout << "Student Name1: " << pStudent[0] << std::endl;
//	std::cout << "Student Name1: " << *(students) << std::endl;
	std::cout << "Student Score: " << *(pStudent + 1) << std::endl;
//	std::cout << "Student Score: " << *(scores) << std::endl;
	std::cout << "Standard Deviation: " << standardDev << std::endl;
}