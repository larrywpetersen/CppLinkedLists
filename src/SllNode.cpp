#include "SllNode.hpp"

#include <sstream>
#include <iostream>
using namespace std;

int SllNode::index = 0;

SllNode::SllNode()
{
    // this->prtNext = nullptr;
    // this->key = this->index++;
    // cout << "SllNode " << this->getKey() << " constructed" << endl;
    init(this->index);
}

SllNode::SllNode(int key)
{
    // this->prtNext = nullptr;
    // // this->key = this->index++;
    // this->key = key;
    // cout << "SllNode " << this->getKey() << " constructed" << endl;
    init(key);
}

SllNode::~SllNode()
{
    // cout << "SllNode " << this->getKey() << " destructed" << endl;
}

void SllNode::init(int key)
{
    this->prtNext = nullptr;
    this->key = key;
    this->index++;
    // cout << "SllNode " << this->getKey() << " constructed" << endl;
}

void SllNode::setNext(SllNode *nptr)
{
    this->prtNext = nptr;
}

void SllNode::setKey(int key)
{
    this->key = key;
}

void SllNode::setIndex(int index)
{
    this->index = index;
}

SllNode *SllNode::getNext()
{
    return this->prtNext;
}

int SllNode::getKey()
{
    return this->key;
}

int SllNode::getIndex()
{
    return this->index;
}

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