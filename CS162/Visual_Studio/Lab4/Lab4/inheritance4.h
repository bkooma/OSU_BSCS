#include <string>
using namespace std;

enum Discipline { ARCHEOLOGY, BIOLOGY, COMPUTER_SCIENCE };
enum Classification { FRESHMAN, SOPHOMORE, JUNIOR, SENIOR };

class People
{
protected:
  std::string name;
  int age;
  int workHours;
public:
  People() { setName(""); }
  People(std::string Name, int age) { 
	  setName(Name); 
  }
  virtual void do_work(int x) {
	  workHours = x;
  }
  void setName(std::string pName) { 
	  name = pName; 
  }
  std::string getName() { 
	  return name;
  }
};

class Student:public People
{
private:
  double instructorRating;
  Discipline major;
  People *advisor;
public:
  //constructor
  Student(string sname, Discipline d, People *adv);  
  void setMajor(Discipline d) { 
	  major = d; 
  }
  Discipline getMajor(){ 
	  return major; 
  }
  void setAdvisor(People *p) { 
	  advisor = p; 
  }
  People *getAdvisor() { 
	  return advisor; 
  }
};


class Faculty:public People 
{
private:
  Discipline department;
public:
  //constructor
  Faculty(string fname, Discipline d) : People(fname)
  {  
     department = d;
  }
  void setDepartment(Discipline d) { 
	  department = d; 
  }
  Discipline getDepartment( ) { 
	  return department; 
  }
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


    

