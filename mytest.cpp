/*                                                                                                                                                                                
This is the Tester class and main. Here it tests all the functions and seeing if it works.                                                                                        
 */
#include "course.h"
#include <iostream>
using namespace std;

class Tester{
public:
  bool testConstructor();
  bool testConstructorErr();
  bool testCopyConstructor();
  bool testCopyConstructorErr();
  bool testAssignmentOp();
  bool testAssignmentOpErr();
  bool testAssignmentEdge();
  bool testStudAvg();
  bool testStudAvgEdge();
  bool testTestAvg();
  bool testTestAvgEdge();
  bool testClassAvg();
  bool testInsert();
  bool testInsertErr();
  bool testRemove();
  bool testDest();
  bool testDeepCopy();
  bool testSimulateData();
};

int main(){
  Tester test;
  if(test.testConstructor()==true){
    cout<<"Constructor: Passed"<<endl;
  }
  else
    cout<<"Constructor: Failed"<<endl;
  if(test.testConstructorErr()==true){
    cout<< "Constructor Error: Passed"<<endl;
  }
  else
    cout<<"Constructor Error: Failed"<<endl;
  if(test.testCopyConstructor()==true){
    cout<<"Copy Constructor: Passed"<<endl;
  }
  else
    cout<<"Copy Constructor: Failed"<<endl;
  if(test.testCopyConstructorErr()==true){
    cout<<"Copy Constructor Error: Passed"<<endl;
  }
  else
    cout<<"Copy Constructor Error: Failed"<<endl;
  if(test.testAssignmentOp()==true){
    cout<<"Assignment Operator: Passed"<<endl;
  }
  else
    cout<<"Assignment Operator: Failed"<<endl;
  if(test.testAssignmentOpErr()==true){
    cout<<"Assignment Operator Error: Passed"<<endl;
  }
  else
    cout<<"Assignment Operator Error: Failed"<<endl;
  if(test.testAssignmentEdge()==true){
    cout<<"Assignment Operator Edge: Passed"<<endl;
  }
  else
    cout<<"Assignment Operator Edge: Failed"<<endl;
  if(test.testStudAvg()==true){
    cout<<"Student Average: Passed"<<endl;
  }
  else
    cout<<"Student Average: Failed"<<endl;
  if(test.testStudAvgEdge()==true){
    cout<<"Student Average Edge: Passed"<<endl;
  }
  else
    cout<<"Student Average Edge: Failed"<<endl;
  if(test.testTestAvg()==true){
    cout<<"Test Average: Passed"<<endl;
  }
  else
    cout<<"Test Average: Failed"<<endl;
  if(test.testTestAvgEdge()==true){
    cout<<"Test Average Edge: Passed"<<endl;
  }
  else
    cout<<"Test Average Edge: Failed"<<endl;
  if(test.testClassAvg()==true){
    cout<<"Class Average: Passed"<<endl;
  }
  else
  cout<<"Class Average: Failed"<<endl;*/
  if(test.testInsert()==true){
    cout<<"Insert Section: Passed"<<endl;
   }
  else
    cout<<"Insert Section: Failed"<<endl;
  if(test.testInsertErr()==true){
    cout<<"Insert Section Error: Passed"<<endl;
  }
  else
    cout<<"Insert Section Error: Failed"<<endl;
  if(test.testRemove()==true){
    cout<<"Remove Section: Passed"<<endl;
  }
  else
    cout<< "Remove Section: Failed"<<endl;
  if(test.testDest()==true){
    cout<<"Destructor: Passed"<<endl;
  }
  else
    cout<<"Destructor: Failed"<<endl;
  if(test.testDeepCopy()==true){
    cout<<"Deep Copy: Passed"<<endl;
  }
  else
    cout<<"Deep Copy: Failed"<<endl;
  if(test.testSimulateData()==true){
    cout<<"Simulate Data: Passed"<<endl;
  }
  else
    cout<<"Simulate Data: Failed"<<endl;

  return 0;
}


bool Tester::testConstructor(){
  Section section(1001,"John Smith", 8, 8);
  return section.classAverage()==0;
}

bool Tester::testConstructorErr(){
  Section section(-1001,"",-5,-10);
  return section.classAverage()==0;
}
bool Tester::testCopyConstructor(){
  Section section(1001, "John Smith", 1, 2);
  section.simulateData();
  Section sectionCopy=section;
  return section.classAverage()==sectionCopy.classAverage();
}
bool Tester::testCopyConstructorErr(){
  Section section;
  Section section1=section;
  return section1.classAverage()==0;
}
bool Tester::testAssignmentOp(){
  Section section(1001, "John Smith",10, 20);
  section.simulateData();
  Section section1;
  section1=section;
  return section.classAverage()==section1.classAverage();
}
bool Tester::testAssignmentOpErr() {
  Section section1(1001, "John Smith", 10, 20);
  section1.simulateData();
  section1 = section1;
  Section section2;
  section2 = section1;

  return section2.classAverage() == section1.classAverage();
}

bool Tester::testAssignmentEdge(){
  Section section;
  Section section1(1001,"John Smith", 10, 20);
  section1=section;
  return section.classAverage()==section.classAverage();
}
bool Tester::testStudAvg(){
  Section section(1001, "John Smith", 10, 20);
  section.simulateData();
  return section.studentAverage(0)>=0;
}
bool Tester::testStudAvgEdge() {
    Section section(101, "John Smith", 3, 1);
    section.simulateData();
    double avg = section.studentAverage(0);
    return avg >= 0 && avg <= 100;
}
bool Tester::testTestAvg(){
  Section section(1001, "John Smith", 30, 50);
  section.simulateData();
  return section.testAverage(0)>=0;
}
bool Tester::testTestAvgEdge() {
    Section section(1000, "John Smith", 4, 10);
    section.simulateData();
    double avgLow = section.testAverage(0);
    double avgHigh = section.testAverage(3);
    return (avgLow >= 0 && avgLow <= 100) && (avgHigh >= 0 && avgHigh <= 100);
}

bool Tester::testClassAvg() {
    Section section(1001, "John Smith", 5, 8);
    section.simulateData();
    double avg = section.classAverage();
    return avg >= 0 && avg <= 100;
    }
bool Tester::testInsert(){
  Course course(3);
  return course.insertSection(10001, "John Smith", 30, 50);
}
bool Tester::testInsertErr(){
  Course course(3);
  course.insertSection(10001, "John Smith", 30, 50);
  return !course.insertSection(10001, "Johns Smith", 30, 50);
}
bool Tester::testRemove(){
  Course course(3);
  course.insertSection(10001, "John Smith", 30, 50);
  return course.removeSection(10001);
}
bool Tester::testDest() {
    Section *section = new Section(10003, "John Smith", 3, 6);
    section->simulateData();
    delete section;
    return true;
}
bool Tester::testDeepCopy(){
  Section section(10001, "John Smith", 30, 50);
  section.simulateData();
  Section section1=section;
  section1.m_section[0][0]=1000;
  return section.m_section[0][0] !=1000;
}
bool Tester::testSimulateData(){
  Section section(10001, "John Smith", 30, 50);
  section.simulateData();
  return section.classAverage()>0;
}

