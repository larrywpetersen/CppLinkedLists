#include <sstream>
#include <iostream>
using namespace std;

#include <person.hpp>

//
//
/**************************************
 * constructor and destructor
 *************************************/

Person::Person() // : SllNode()
{
    init("", "", "", "", "", "", "");
}

Person::Person(string first, string last)
{
    init(first, last, "", "", "", "", "");
}

Person::Person(string first, string last,
               string addr1, string addr2,
               string city, string state, string zip)
{
    init(first, last, addr1, addr2, city, state, zip);
}

void Person::init(string first, string last,
                  string addr1, string addr2,
                  string city, string state, string zip)
{
    this->firstName = first;
    this->lastName = last;
    this->address1 = addr1;
    this->address2 = addr2;
    this->city = city;
    this->state = state;
    this->zip = zip;
}

//
//
/**************************************
 * getters and setters
 *************************************/

string Person::getFirstName() { return this->firstName; }
string Person::getLastName() { return this->lastName; }
string Person::getAddress1() { return this->address1; }
string Person::getAddress2() { return this->address2; }
string Person::getCity() { return this->city; }
string Person::getState() { return this->state; }
string Person::getZip() { return this->zip; }

void Person::setFirstName(string firstName) { this->firstName = firstName; }
void Person::setLastName(string lastName) { this->lastName = lastName; }
void Person::setAddress1(string address1) { this->address1 = address1; }
void Person::setAddress2(string address2) { this->address2 = address2; }
void Person::setCity(string city) { this->city = city; }
void Person::setState(string state) { this->state = state; }
void Person::setZip(string zip) { this->zip = zip; }

string Person::getName() { return this->getFirstName() + " " + this->getLastName(); }
string Person::getAddress()
{
    return "hi";
}

//
//
/**************************************
   * management function
   *************************************/

string
Person::to_string()
{
    string msg = "(";
    msg += this->getFirstName() + ' ' + this->getLastName() + ", ";
    msg += this->getAddress1() + ", " + this->getAddress2() + ", ";
    msg += this->getCity() + ", " + this->getState() + ", ";
    msg += this->getZip() + ")";
    return msg;
}