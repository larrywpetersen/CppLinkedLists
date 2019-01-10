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
  long key;
  long listLength;

  static long index;

  //
  //
  /**************************************
   * 
   * private methods to deal with listLength
   * 
  **************************************/

  void setListLength(long l);
  long getListLength();
  void incListLength();

  //
  //
  /**************************************
   * private methods - getter and setter
   *************************************/

  SllNode *getHead();
  SllNode *getTail();

  void setHead(SllNode *);
  void setCurrent(SllNode *);
  void setTail(SllNode *);

public:
  //
  //
  /**************************************
   * constructor and destructor
   *************************************/

  SllList();
  SllList(long);
  virtual ~SllList();
  void init(long);

  //
  //
  /**************************************
   * public methods - getter and setter
   *************************************/

  long getKey();
  long getIndex();

  void setKey(long);
  void setIndex(long);

  //
  //
  /**************************************
   * public methods - adding to the list
   *************************************/

  void add(SllNode *);
  void insert(SllNode *);
  void insert(SllNode *, int);

  //
  //
  /**************************************
   * public methods - Accessing the list
   *************************************/

  virtual SllNode *getCurrent();
  virtual SllNode *getNext();
  virtual SllNode *getNode(int);

  void moveTo(int);

  int find(int);
  int findKey(int);

  //
  //
  /**************************************
   * public methods - management function
   *************************************/

  void clear();
  void resetToHead();
  bool isEmpty();
  int length();
  virtual string to_string();
};
