#include <iostream>
#include <sstream>
using namespace std;

#include <SllList.hpp>

bool SllListTestPass = true;

string SllListTest_ptrToString(SllList *node)
{
    if (node == nullptr)
    {
        return "nullptr";
    }
    std::ostringstream address;
    address << (void const *)node;
    return address.str();
}

string errorMessage(long k, string fn, string s, string i)
{
    SllListTestPass = false;
    string msg = "\n\nproblem with " + fn + " of List ";
    msg += to_string(k) + "\n";
    msg += "    Should be '" + s;
    msg += "'\n       but is '" + i + "'\n";
    return msg;
}

string testGetKey(SllList *tn, long k)
{
    if (tn->getKey() == k)
    {
        return ".";
    }
    return errorMessage(tn->getKey(),
                        "getKey",
                        to_string(k),
                        to_string(tn->getKey()));
}

string testGetIndex(SllList *tn, long i)
{
    if (tn->getIndex() == i)
    {
        return ".";
    }
    return errorMessage(tn->getKey(),
                        "getIndex",
                        to_string(i),
                        to_string(tn->getIndex()));
}

string testNodeKey(SllNode *nNode, string fn, long shouldB)
{
    if (nNode->getKey() == shouldB)
    {
        return ".";
    }
    else
    {
        return errorMessage(nNode->getKey(),
                            fn,
                            std::to_string(shouldB),
                            std::to_string(nNode->getKey()));
    }
}

string testNodeNull(SllNode *nNode, bool n)
{
    if ((nNode == nullptr) == n)
    {
        return ".";
    }
    else
    {
        return errorMessage(nNode->getKey(),
                            "node is null",
                            std::to_string(n),
                            std::to_string(nNode->getKey()));
    }
}

string testIsEmpty(SllList *tn, bool p)
{
    if (tn->isEmpty() == p)
    {
        return ".";
    }
    return errorMessage(tn->getKey(),
                        "getKey",
                        to_string(p),
                        to_string(tn->isEmpty()));
}

string testLength(SllList *tn, long l)
{
    if (tn->length() == l)
    {
        return ".";
    }
    return errorMessage(tn->length(),
                        "length",
                        to_string(l),
                        to_string(tn->length()));
}

long SllListTest(bool verb)
{

    /***********************
     * 
     *  Initialize things
     * 
     * *********************/

    // make sure SllNode index is back to a known - 0
    SllNode *tmpNode;
    tmpNode = new SllNode;
    tmpNode->setIndex(0);
    delete (tmpNode);

    // make sure SllList index is back to a known - 0
    SllList *tmpList;
    tmpList = new SllList;
    tmpList->setIndex(0);
    // cout << "tmpList index - " << tmpList->getIndex() << endl;
    delete (tmpList);

    /***********************
     * 
     *  Start testing
     * 
     * *********************/

    SllList testList1; //  **  test constructor
    // cout << "testList1 index - " << std::to_string(testList1.getIndex()) << endl;
    // cout << "testList1 key   - " << std::to_string(testList1.getKey()) << endl;

    cout << testIsEmpty(&testList1, true); //  **  testList1 is empty true
    cout << testGetKey(&testList1, 0);     //  **  testList1 getKey
    cout << testGetIndex(&testList1, 1);   //  **  testList1 getIndex

    testList1.setKey(23);    //  **  test setKey
    testList1.setIndex(124); //  **  test setIndex

    cout << testGetKey(&testList1, 23);    //  **  testList1 getKey
    cout << testGetIndex(&testList1, 124); //  **  testList1 getIndex

    SllNode *testNode;

    for (int i = 100; i < 110; i++) //  **  Test add
    {
        testNode = new SllNode(i);
        testList1.add(testNode);
    }

    cout << testIsEmpty(&testList1, false); //  **  testList1 is empty false
    cout << testLength(&testList1, 10);     //  **  testList1 length

    testList1.resetToHead(); //  **  Test resetToHead

    cout << testNodeKey(testList1.getCurrent(), "getCurrent", 100); //  **  Test getCurrent
    cout << testNodeKey(testList1.getNext(), "getNext", 101);       //  **  Test getNext

    for (int i = 0; i < 3; i++)
    {
        testList1.getNext();
    }

    cout << testNodeKey(testList1.getCurrent(), "getCurrent", 104); //  **  Test getCurrent

    testNode = new SllNode(200);
    testList1.insert(testNode); //  **  Test insert

    testNode = new SllNode(201);
    testList1.insert(testNode, 8); //  **  Test insert at a location

    testList1.resetToHead(); //  **  Test resetToHead

    cout << testNodeKey(testList1.getCurrent(), "getCurrent", 100); //  **  Test getCurrent

    // cout << testLength(&testList1, 12);

    // cout << testNodeKey(testList1.getCurrent(), "getCurrent", 100); //  **  Test getCurrent
    // cout << testNodeKey(testList1.getNext(), "getNext", 101);
    // cout << testNodeKey(testList1.getNext(), "getNext", 102);
    // cout << testNodeKey(testList1.getNext(), "getNext", 103);
    // cout << testNodeKey(testList1.getNext(), "getNext", 104);
    // cout << testNodeKey(testList1.getNext(), "getNext", 200);
    // cout << testNodeKey(testList1.getNext(), "getNext", 105);
    // cout << testNodeKey(testList1.getNext(), "getNext", 106);
    // cout << testNodeKey(testList1.getNext(), "getNext", 107);
    // cout << testNodeKey(testList1.getNext(), "getNext", 201);
    // cout << testNodeKey(testList1.getNext(), "getNext", 108);
    // cout << testNodeKey(testList1.getNext(), "getNext", 109);

    // cout << endl;
    // cout << testList1.find(10) << endl;
    // cout << testList1.find(11) << endl;
    // cout << testList1.find(12) << endl;
    // cout << testList1.find(13) << endl;
    // cout << testList1.find(14) << endl;
    // cout << testList1.findKey(106) << endl;

    testList1.moveTo(6); //  **  test moveTo
    cout << testNodeKey(testList1.getCurrent(), "getNext", 105);

    // cout << testNodeNull(testList1.getNext(), false);
    // cout << testNodeNull(testList1.getNode(28), false);

    cout << endl;

    if (verb)
    {
        cout << "testList 1 - " << testList1.to_string() << endl;
    }

    cout << endl;

    if (SllListTestPass)
    {
        cout << "SllListTest Passed" << endl;
    }
    else
    {
        cout << "*****     SllListTest Failed     *****" << endl;
    }

    return 0;

    /******************************************************
     * 
     * Untested
     * 
     *     destructor
     * 
     *     init() - tested indirectly since constructors us it
     * 
     * 
     * ***************************************************/
}
