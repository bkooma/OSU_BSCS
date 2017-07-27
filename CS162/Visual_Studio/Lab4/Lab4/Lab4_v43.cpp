#include <string>
#include <iostream>
#include <vector>
#include <memory>

class People
{
protected:
	std::string name;
	int age = 0;
	int workHours = 0;
public:
	People() {
		std::cout << "Default constructor Base class.\n";
		setName("");
	}
	People(std::string Name, int age) {
		std::cout << "Parameterized constructor Base class.\n";
		this->name = Name;
		this->age = age;
	}
	void setName(std::string pName) {
		name = pName;
	}

	void setAge(int x) {
		age = x;
	}

	std::string getName() {
		return name;
	}

	int getAge() {
		return age;
	}

	int getHours() {
		return workHours;
	}

	virtual void do_work(int x) {
		workHours = x;
	}
	~People() {}
};

class Student:public People
{
private:
  double gpa;
  int studentHrs;

public:
  //constructor
	Student()
	{
		std::cout << "In Student sub class default constructor\n";
	}
	Student(std::string sname, int age, double gpa) :People(sname, age) {
		std::cout << "In Student sub class constructor\n";
		setGpa(gpa);
	}
	
	void setGpa(double g) {
		gpa = g;
	}

	double getGpa() {
		return gpa;
	}

	void do_work(int x) {
	  studentHrs = x;
	  std::cout << this->name << " did " << studentHrs << "hours of homework.";
	}

  ~Student() {}
};


class Instructor:public People 
{
private:
  double instructorRating;
  int instructHrs;
public:
  //constructor
  Instructor(std::string sname, int age, double rating) : People(sname, age)
  {
	std::cout << "In Instructor sub class constructor.\n";
	setRating(rating);
  }
  
  void setRating(double r) {
	  instructorRating = r;
  }

  double getRating() {
	  return instructorRating;
  }

  void do_work(int x) {
	  instructHrs = x;
	  std::cout << "Instructor " << this->name << " graded papers for " << instructHrs << " hours.";
  }
  ~Instructor() {}
};

/*class TFaculty : public Faculty
{
private:
  string title;
public:
  TFaculty(string fname, Discipline d, string title)
  : Faculty(fname, d) { 
	  setTitle(title); 
  }
  void setTitle(string title) { 
	  this->title = title; 
  }
  //override getName()
  string getName( ) { return title + " " + People::getName();}
};*/

class Building {
private:
	std::string name;
	int bldgSqFt;
	std::string bldgAddress;
public:
	Building() {
		std::cout << "Default constructor Building class.\n";

	}
	Building(std::string Name, int Sqft, std::string bAddress) {
		std::cout << "Parameterized constructor Building class.\n";
		name = Name;
		bldgSqFt = Sqft;
		bldgAddress = bAddress;
	}
	void setName(std::string pName) {
		name = pName;
	}
	std::string getName() {
		return name;
	}
	int getSqFt() {
		return bldgSqFt;
	}
	std::string getAddress() {
		return bldgAddress;
	}
	~Building() {}
};

class University {
private:
	std::string name;
	int n = 0;
	int m = 0;
	std::vector <People*> ppl;
	std::vector <Building> bldg;
	People *p1;
	Instructor *i1;

public:
	University() {
	}
	void University::addPeople(People *p1) {
		ppl.push_back(p1);
		n = ppl.size();
	}
	void University::addBuilding(Building *b1) {
		bldg.push_back(*b1);
		m = bldg.size();
	}
	void University::printPeople() {
		std::vector<People*>::iterator vecIterator;
		
		for (vecIterator = ppl.begin(); vecIterator != ppl.end(); vecIterator++) {
			People* pPeople = *vecIterator;
			Student* sPeople = dynamic_cast<Student*>(pPeople);
			Instructor* iPeople = dynamic_cast<Instructor*>(pPeople);

			std::cout << "Name:\t\tAge:\t\t";

			if (sPeople) {
				std::cout << "GPA:\n" << sPeople->getGpa();
			}
			else if (iPeople) {
				std::cout << "Rating:\n" << iPeople->getRating(); 
			}

//			std::cout << ppl[i].getName() << "\t\t";
//			std::cout << ppl[i].getAge() << "\t\t";
//			std::cout << ppl[i].
		}

	}
	~University() {
		std::vector<People*>::iterator vecIterator;
		for (vecIterator = ppl.begin(); vecIterator != ppl.end(); vecIterator++) {
			People* pPeople = *vecIterator;
			delete pPeople;
		}
	}
};


int main() {
	University OSU;
//	Student *student1;
	People *student2 = new Student("Bryan", 37, 3.7);
	People *instructor1 = new Instructor("Bob", 56, 4.9);
//	student2 = new Student;
	student2->do_work(17);
	OSU.addPeople(student2);
	OSU.addPeople(instructor1);
	Building *OSU1 = new Building("Sully", 34000, "2211 Crystal Creek");
	OSU.addBuilding(OSU1);
	OSU.printPeople();
	OSU.printPeople();
}

    

