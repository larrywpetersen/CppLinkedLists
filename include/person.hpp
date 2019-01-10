#pragma once

#include <iostream>
using namespace std;

#include <SllNode.hpp>

class Person : public SllNode
{
  private:
    string firstName;
    string lastName;
    string address1;
    string address2;
    string city;
    string state;
    string zip;

  public:
    //
    //
    /**************************************
   * constructor and destructor
   *************************************/

    Person();
    Person(string, string);
    Person(string, string, string, string, string, string, string);
    void init(string, string,
              string, string,
              string, string, string);

    //
    //
    /**************************************
   * getters and setters
   *************************************/

    string getFirstName();
    string getLastName();
    string getAddress1();
    string getAddress2();
    string getCity();
    string getState();
    string getZip();

    void setFirstName(string);
    void setLastName(string);
    void setAddress1(string);
    void setAddress2(string);
    void setCity(string);
    void setState(string);
    void setZip(string);

    //
    //
    /**************************************
   * management function
   *************************************/

    virtual string to_string();
};
