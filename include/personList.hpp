#include <sstream>
#include <iostream>
using namespace std;

#include <SllList.hpp>
#include <person.hpp>

class PersonList : public SllList
{
private:
  int test;

public:
  //
  //
  /**************************************
     * getters and setters
     *************************************/

  // virtual Person *getCurrent();
  // virtual Person *getNext();
  // virtual Person *getNode(int);

  //
  //
  /**************************************
     * public methods - management function
     *************************************/

  virtual string to_string();
};
