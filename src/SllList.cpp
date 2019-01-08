#include "SllList.hpp"

#include <iostream>
using namespace std;

//
//
/**************************************
 * 
 * private methos to deal with listLength
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
 * private methos - getter and setter for node pointers
**************************************/

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

SllNode *SllList::getHead()
{
    return this->ptrSllNode_head;
}

SllNode *SllList::getTail()
{
    return this->ptrSllNode_tail;
}

//
//
/**************************************
 * constructor and destructor
**************************************/

SllList::SllList()
{
    this->setHead(nullptr);
    this->setTail(nullptr);
    this->setCurrent(nullptr);
    this->setListLength(0);
}

SllList::~SllList()
{
    cout << "SllList destroyed" << endl;
}

//
//
/**************************************
 * public methos - adding to the list
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
 * public methos - Accessing the list
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
 * public methos - management function
**************************************/

void SllList::clear() {}

void SllList::resetToHead()
{
    this->setCurrent(this->getHead());
}

bool SllList::isEmpty()
{
    if (this->getCurrent() == nullptr)
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
    return "This is the SllList.to_string() method.";
}
