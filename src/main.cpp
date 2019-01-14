#include <iostream>
using namespace std;

#include <sys/resource.h>
#include <sys/time.h>
//above libraries have to be included for getrusage

#include <SllNode.hpp>
#include <SllList.hpp>

#include <SllNodeTest.hpp>
#include <SllListTest.hpp>

#include <person.hpp>
#include <personList.hpp>

void printList(SllList *ptrTestList)
{
     SllNode *ptrHere;
     ptrTestList->resetToHead();
     ptrHere = ptrTestList->getCurrent();

     while (ptrHere != nullptr)
     {
          cout << ptrHere->getKey() << endl;
          ptrHere = ptrTestList->getNext();
     }
}

void testSllNode(bool verb)
{
     cout << endl
          << "Testing SllNode:" << endl
          << endl;

     SllNodeTest(verb);

     cout << "Done testing SllNode:" << endl
          << endl;
}
void testSllList(bool verb)
{
     cout
         << endl
         << "Testing SllList:" << endl
         << endl;

     SllListTest(verb);

     cout << "Done testing SllList:" << endl
          << endl;
}

// int main(int argc, char *argv[])
int main()
{

     // Person me("Larry", "Petersen");
     // cout << me.to_string() << endl;

     // me.setAddress1("789 Marinus Ln.");
     // me.setCity("Pocatello");
     // me.setState("Idaho");
     // me.setZip("83201");

     // Person you("Becky", "Petersen");
     // cout << me.to_string() << endl;

     // // me.setNext(&you);

     // cout << endl
     //      << "me:" << endl;

     // // cout << "getKey - " << me.getKey() << endl;
     // // cout << "getNext - " << me.getNext() << endl;
     // // cout << "getIndex - " << me.getIndex() << endl;

     // cout << endl
     //      << "you:" << endl;

     // cout << "getKey - " << you.getKey() << endl;
     // cout << "getNext - " << you.getNext() << endl;
     // cout << "getIndex - " << you.getIndex() << endl;

     testSllNode(false);

     testSllList(false);

     return 0;
}
