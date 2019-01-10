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

// int main(int argc, char *argv[])
int main()
{

     Person me("Larry", "Petersen");

     cout << me.to_string() << endl;

     me.setAddress1("789 Marinus Ln.");
     me.setCity("Pocatello");
     me.setState("Idaho");
     me.setZip("83201");

     cout << me.to_string() << endl;

     Person becky("Becky", "Petersen");

     PersonList family;

     cout << "Sie of family is " << family.length() << endl;

     family.add(me);
     family.add(becky);

     cout << "Sie of family is " << family.length() << endl;
     cout << "family.to_string - " << family.to_string() << endl;

     // cout << endl
     //      << "Testing SllNode:" << endl
     //      << endl;

     // SllNodeTest(false);

     // cout << endl
     //      << "Done testing SllNode:" << endl
     //      << endl;

     // cout << endl
     //      << "Testing SllList:" << endl
     //      << endl;

     // SllListTest(false);

     // cout << endl
     //      << "Done testing SllList:" << endl
     //      << endl;

     //      SllList testList;
     //      SllList *ptrTestList = &testList;

     //      cout << endl
     //           << "List not built yet - " << endl
     //           << "length of testList - " << testList.length() << endl;

     //      SllNode *ptrNode;
     //      int i;
     //      for (i = 0; i < 10; i++)
     //      {
     //           ptrNode = new SllNode;
     //           testList.add(ptrNode);
     //      }

     //      cout << endl
     //           << "List has been built - " << endl
     //           << "length of testList - " << testList.length() << endl;

     //      printList(ptrTestList);

     //      ptrTestList->reset();
     //      for (i = 0; i < 3; i++)
     //      {
     //           ptrTestList->getNext();
     //      }

     //      ptrNode = new SllNode;
     //      ptrNode->setKey(20);
     //      testList.insert(ptrNode);

     //      ptrNode = new SllNode;
     //      // ptrNode->setKey(35);
     //      testList.insert(ptrNode, 6);

     //      ptrNode = new SllNode;
     //      // ptrNode->setKey(35);
     //      testList.insert(ptrNode, 100);

     //      cout << endl
     //           << "Two have been added - " << endl
     //           << "length of testList - " << testList.length() << endl;

     //      printList(ptrTestList);

     //      int n = 8;

     //      ptrNode = testList.getNode(n);

     //      cout << endl
     //           << n << "th node is " << ptrNode->getKey() << endl;

     //      struct rusage *usage; // = nullptr;
     //      __rusage_who_t who = 0;

     //      cout << endl
     //           << "size of SllNode - " << sizeof(ptrNode) << endl;

     //      getrusage(who, usage);
     //      cout << endl
     //           << "Node not yet constructed" << endl
     //           << "ru_idrss - " << usage->ru_idrss << endl
     //           << "ru_isrss - " << usage->ru_isrss << endl
     //           << "ptrNode - " << ptrNode << endl
     //           << "   key = " << ptrNode->getKey() << endl;

     //      ptrNode = new SllNode;

     //      getrusage(who, usage);
     //      cout << endl
     //           << "just constructed" << endl
     //           << "ru_idrss - " << usage->ru_idrss << endl
     //           << "ru_isrss - " << usage->ru_isrss << endl
     //           << "ptrNode - " << ptrNode << endl
     //           << "   key = " << ptrNode->getKey() << endl;

     //      ptrNode->~SllNode();

     //      getrusage(who, usage);
     //      cout << endl
     //           << "just destructed" << endl
     //           << "ru_idrss - " << usage->ru_idrss << endl
     //           << "ru_isrss - " << usage->ru_isrss << endl
     //           << "ptrNode - " << ptrNode << endl
     //           << "   key = " << ptrNode->getKey() << endl;

     //      delete (ptrNode);

     //      getrusage(who, usage);
     //      cout << endl
     //           << "just deleted" << endl
     //           << "ru_idrss - " << usage->ru_idrss << endl
     //           << "ru_isrss - " << usage->ru_isrss << endl
     //           << "ptrNode - " << ptrNode << endl
     //           << "   key = " << ptrNode->getKey() << endl;

     //      cout << endl;

     //      cout << endl;

     // cout << "Hello Easy C++ project!" << endl;
}
