#pragma once

#include <iostream>
using namespace std;

#include <SllNode.hpp>

class SllList
{
private:
  SllNode *ptrSllNode_head;
  SllNode *ptrSllNode_current;
  SllNode *ptrSllNode_tail;
  long listLength;

  //
  //
  /**************************************
    * 
    * private methos to deal with listLength
    * 
  **************************************/

  void setListLength(long l);
  long getListLength();
  void incListLength();

  //
  //
  /**************************************
   * private methos - getter and setter for node pointers
  **************************************/

  void setHead(SllNode *);
  void setCurrent(SllNode *);
  void setTail(SllNode *);

  SllNode *getHead();
  SllNode *getTail();

public:
  //
  //
  /**************************************
 * constructor and destructor
**************************************/

  SllList();
  virtual ~SllList();

  //
  //
  /**************************************
 * public methos - adding to the list
**************************************/

  void add(SllNode *);
  void insert(SllNode *);
  void insert(SllNode *, int);

  //
  //
  /**************************************
 * public methos - Accessing the list
**************************************/

  SllNode *getCurrent();
  SllNode *getNext();
  SllNode *getNode(int);
  void moveTo(int);

  int find(int);
  int findKey(int);

  //
  //
  /**************************************
 * public methos - management function
**************************************/

  void clear();
  void resetToHead();
  bool isEmpty();
  int length();
  string to_string();
};
