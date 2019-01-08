#include <iostream>
#include <sstream>
using namespace std;

#include <SllNode.hpp>

bool SlllNodeTestPass = true;

string SllNodeTest_ptrToString(SllNode *node)
{
    if (node == nullptr)
    {
        return "nullptr";
    }
    std::ostringstream address;
    address << (void const *)node;
    return address.str();
}

string errorMessage(int k, string fn, string s, string i)
{
    SlllNodeTestPass = false;
    string msg = "\n\nproblem with " + fn + " of node ";
    msg += to_string(k) + "\n";
    msg += "    Should be '" + s;
    msg += "' but is '" + i + "'\n";
    return msg;
}

string testGetKey(SllNode tn, int k)
{
    if (tn.getKey() == k)
    {
        return ".";
    }
    return errorMessage(tn.getKey(),
                        "getKey",
                        to_string(k),
                        to_string(tn.getKey()));
}

string testGetNext(SllNode tn, SllNode *dn)
{
    if (tn.getNext() == dn)
    {
        return ".";
    }
    return errorMessage(tn.getKey(),
                        "getNext",
                        SllNodeTest_ptrToString(dn),
                        SllNodeTest_ptrToString(tn.getNext()));
}

int SllNodeTest(bool verb)
{
    SllNode testNode1;     // testNode1 is 0
    SllNode testNode2(42); // testNode2 is 42

    testNode1.setNext(&testNode2); // testNode1 points to testNode2

    testNode1.setIndex(25);
    SllNode testNode3; // testNode3 is 25
    SllNode testNode4;

    testNode4.setNext(&testNode2); // testNode4 points to testNode2

    testNode4.setKey(100); // testNode4 is 100

    cout << testGetNext(testNode1, &testNode2);
    cout << testGetNext(testNode2, nullptr);
    cout << testGetNext(testNode3, nullptr);
    cout << testGetNext(testNode4, &testNode2);

    cout << testGetKey(testNode1, 0);
    cout << testGetKey(testNode2, 42);
    cout << testGetKey(testNode3, 25);
    cout << testGetKey(testNode4, 100);

    cout << endl
         << endl;

    if (verb)
    {
        cout << "testNode 1 - " << testNode1.to_string() << endl;
        cout << "testNode 2 - " << testNode2.to_string() << endl;
        cout << "testNode 3 - " << testNode3.to_string() << endl;
        cout << "testNode 4 - " << testNode4.to_string() << endl;
    }

    if (SlllNodeTestPass)
    {
        cout << "SllNodeTest Passed" << endl;
    }
    else
    {
        cout << "*****     SllNodeTest Failed     *****" << endl;
    }

    return 0;
}
