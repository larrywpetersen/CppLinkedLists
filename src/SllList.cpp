#include <sstream>
#include <iostream>
using namespace std;

#include <SllList.hpp>

long SllList::index = 0;

//
//
/**************************************
 * 
 * private methods to deal with listLength
 * 
**************************************/

void SllList::setListLength(long l)
{
    this->listLength = l;
}

long SllList::getListLength()
{
    return this->listLength;
}

void SllList::incListLength()
{
    this->listLength++;
}

//
//
/**************************************
 * private methods - getter and setter for node pointers
**************************************/

SllNode *SllList::getHead()
{
    return this->ptrSllNode_head;
}

SllNode *SllList::getTail()
{
    return this->ptrSllNode_tail;
}

void SllList::setHead(SllNode *ptrHead)
{
    this->ptrSllNode_head = ptrHead;
}

void SllList::setCurrent(SllNode *ptrCurrent)
{
    this->ptrSllNode_current = ptrCurrent;
}

void SllList::setTail(SllNode *ptrTail)
{
    this->ptrSllNode_tail = ptrTail;
}

//
//
/**************************************
 * constructor and destructor
**************************************/

SllList::SllList()
{
    this->init(this->index);
    // cout << "SllList " + std::to_string(this->getKey()) + " constructed" << endl;
}

SllList::SllList(long key)
{
    this->init(key);
    // cout << "SllList " + std::to_string(this->getKey()) + " constructed" << endl;
}

void SllList::init(long key)
{
    this->setHead(nullptr);
    this->setTail(nullptr);
    this->setCurrent(nullptr);
    this->setListLength(0);
    // cout << "setting key to " << key << endl;
    this->setKey(key);
    // cout << "index was " << this->index << endl;
    this->index++;
    // cout << "index  is " << this->index << endl;
}

SllList::~SllList()
{
    // cout << "SllList " + std::to_string(this->getKey()) + " destructed" << endl;
}

//
//
/**************************************
 * public methods - getter and setter
 *************************************/

long SllList::getKey()
{
    return this->key;
}
long SllList::getIndex()
{
    return this->index;
}

void SllList::setKey(long key)
{
    this->key = key;
}

void SllList::setIndex(long index)
{
    this->index = index;
}

//
//
/**************************************
 * public methods - adding to the list
**************************************/

void SllList::add(SllNode *ptrNew)
{
    this->incListLength();
    if (this->isEmpty())
    {
        this->setHead(ptrNew);
        this->setCurrent(ptrNew);
        this->setTail(ptrNew);
    }
    else
    {
        SllNode *ptrHere = this->getTail();
        ptrNew->setNext(ptrHere->getNext());
        ptrHere->setNext(ptrNew);
        this->setCurrent(ptrNew);
        this->setTail(ptrNew);
    }
}

void SllList::insert(SllNode *ptrNew)
{
    this->incListLength();
    if (this->isEmpty())
    {
        this->setHead(ptrNew);
        this->setCurrent(ptrNew);
        this->setTail(ptrNew);
    }
    else
    {
        SllNode *ptrHere = this->getCurrent();
        ptrNew->setNext(ptrHere->getNext());
        ptrHere->setNext(ptrNew);
        this->setCurrent(ptrNew);
        if (ptrHere == this->getTail())
        {
            this->setTail(ptrHere);
        }
    }
}

void SllList::insert(SllNode *ptrNew, int n)
{
    this->incListLength();
    if (this->isEmpty())
    {
        this->setHead(ptrNew);
        this->setCurrent(ptrNew);
        this->setTail(ptrNew);
    }
    else
    {
        SllNode *ptrHere = this->getNode(n);
        if (ptrHere == nullptr)
        {
            ptrHere = this->getTail();
        }
        // SllNode *ptrHere = this->getCurrent();
        ptrNew->setNext(ptrHere->getNext());
        ptrHere->setNext(ptrNew);
        this->setCurrent(ptrNew);
    }
}

//
//
/**************************************
 * public methods - Accessing the list
**************************************/

SllNode *SllList::getCurrent()
{
    return this->ptrSllNode_current;
}

SllNode *SllList::getNext()
{
    this->ptrSllNode_current =
        this->ptrSllNode_current->getNext();
    return this->ptrSllNode_current;
}

SllNode *SllList::getNode(int n)
{
    int i = 0;
    SllNode *ptrHere = this->getHead();

    while ((i < n) && (ptrHere != nullptr))
    {
        ptrHere = ptrHere->getNext();
        i++;
    }
    return ptrHere;
}

void SllList::moveTo(int n)
{
    this->setCurrent(this->getNode(this->find(n)));
}

int SllList::find(int n)
{
    int i = 0;
    SllNode *ptrHere = this->getHead();

    while ((i < n) && (ptrHere != nullptr))
    {
        ptrHere = ptrHere->getNext();
        i++;
    }
    if (ptrHere != nullptr)
    {
        return i;
    }
    return -1;
}

int SllList::findKey(int k)
{
    int i = 0;
    SllNode *ptrHere = this->getHead();

    while ((ptrHere != nullptr) &&
           (ptrHere->getKey() != k))
    {
        ptrHere = ptrHere->getNext();
        i++;
    }
    if (ptrHere != nullptr)
    {
        return i;
    }
    return -1;
}

//
//
/**************************************
 * public methods - management function
**************************************/

void SllList::clear() {}

void SllList::resetToHead()
{
    this->setCurrent(this->getHead());
}

bool SllList::isEmpty()
{
    if ((this->getCurrent() == nullptr) &&
        (this->getHead() == nullptr) &&
        (this->getTail() == nullptr))
    {
        return true;
    }
    return false;
}

int SllList::length()
{
    SllNode *curr = this->getHead();
    int l = 0;

    while (curr != nullptr)
    {
        curr = curr->getNext();
        l++;
    }
    return l;
}

string SllList::to_string()
{
    string msg;
    SllList *lNode;
    string addr;

    lNode = this;
    if (lNode == nullptr)
    {
        addr = "nullptr";
    }
    else
    {
        std::ostringstream address;
        address << (void const *)lNode;
        addr = address.str();
    }
    msg = "List " + std::to_string(this->getKey()) +
          " at " + addr + " is " + std::to_string(this->length()) +
          " long\n";

    if (!this->isEmpty())
    {
        SllNode *nNode;
        nNode = this->getHead();
        while (nNode != nullptr)
        {
            msg += "    " + nNode->to_string() + "\n";
            nNode = nNode->getNext();
        }
    }
    return msg;
}
