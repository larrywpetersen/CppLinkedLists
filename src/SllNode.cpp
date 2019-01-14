#include <sstream>
#include <iostream>
using namespace std;

#include <SllNode.hpp>

// using keyType = long;
// using indexType = int;

indexType SllNode::index = 0;

//
//
/**************************************
 * constructor and destructor
 *************************************/

SllNode::SllNode()
{
    init(this->index, nullptr);
}

SllNode::SllNode(keyType key)
{
    init(key, nullptr);
}

SllNode::SllNode(void *data)
{
    init(this->index, data);
}

SllNode::SllNode(keyType key, void *data)
{
    init(key, data);
}

void SllNode::init(keyType key, void *data)
{
    this->prtNext = nullptr;
    this->key = key;
    this->data = data;
    this->index++;
    // cout << "SllNode " << this->getKey() << " constructed" << endl;
}

SllNode::~SllNode()
{
    // cout << "SllNode " << this->getKey() << " destructed" << endl;
}

//
//
/**************************************
 * getters and setters
 *************************************/

void *SllNode::getData()
{
    return this->data;
}

SllNode *SllNode::getNext()
{
    return this->prtNext;
}

keyType SllNode::getKey()
{
    return this->key;
}

indexType SllNode::getIndex()
{
    return this->index;
}

void SllNode::setData(void *data)
{
    this->data = data;
}

void SllNode::setNext(SllNode *nptr)
{
    this->prtNext = nptr;
}

void SllNode::setKey(keyType key)
{
    this->key = key;
}

void SllNode::setIndex(indexType index)
{
    this->index = index;
}

//
//
/**************************************
 * management function
 *************************************/

string SllNodePtrToString(SllNode *node)
{
    if (node == nullptr)
    {
        return "nullptr";
    }
    std::ostringstream address;
    address << (void const *)node;
    return address.str();
}

string SllNode::to_string()
{
    string msg;
    // SllNode *node;
    string addr;

    msg = "Node at " + SllNodePtrToString(this);

    // node = this->getNext();
    // if (node == nullptr)
    // {
    //     addr = "nullptr";
    // }
    // else
    // {
    //     std::ostringstream address;
    //     address << (void const *)node;
    //     addr = address.str();
    // }

    msg += " - key=" + std::to_string(this->getKey());
    msg += " - next=" + SllNodePtrToString(this->getNext());
    return msg;
}