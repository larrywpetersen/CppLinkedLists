#include <sstream>
#include <iostream>
using namespace std;

#include <SllNode.hpp>

long SllNode::index = 0;

//
//
/**************************************
 * constructor and destructor
 *************************************/

SllNode::SllNode()
{
    init(this->index);
}

SllNode::SllNode(long key)
{
    init(key);
}

SllNode::~SllNode()
{
    // cout << "SllNode " << this->getKey() << " destructed" << endl;
}

void SllNode::init(long key)
{
    this->prtNext = nullptr;
    this->key = key;
    this->index++;
    // cout << "SllNode " << this->getKey() << " constructed" << endl;
}

//
//
/**************************************
 * getters and setters
 *************************************/

SllNode *SllNode::getNext()
{
    return this->prtNext;
}

long SllNode::getKey()
{
    return this->key;
}

long SllNode::getIndex()
{
    return this->index;
}

void SllNode::setNext(SllNode *nptr)
{
    this->prtNext = nptr;
}

void SllNode::setKey(long key)
{
    this->key = key;
}

void SllNode::setIndex(long index)
{
    this->index = index;
}

//
//
/**************************************
 * management function
 *************************************/

// string ptrToString(SllNode *node)
// {
//     if (node == nullptr)
//     {
//         return "nullptr";
//     }
//     std::ostringstream address;
//     address << (void const *)node;
//     return address.str();
// }

string SllNode::to_string()
{
    string msg;
    SllNode *node;
    string addr;

    node = this;
    if (node == nullptr)
    {
        addr = "nullptr";
    }
    else
    {
        std::ostringstream address;
        address << (void const *)node;
        addr = address.str();
    }
    msg = "Node at " + addr;

    node = this->getNext();
    if (node == nullptr)
    {
        addr = "nullptr";
    }
    else
    {
        std::ostringstream address;
        address << (void const *)node;
        addr = address.str();
    }

    msg += " - key=" + std::to_string(this->getKey());
    msg += " - next=" + addr;
    return msg;
}