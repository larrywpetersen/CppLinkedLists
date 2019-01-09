#pragma once

#include <iostream>
using namespace std;

class SllNode
{

private:
  SllNode *prtNext;
  int key;

  static int index;

public:
  //
  //
  /**************************************
   * constructor and destructor
  **************************************/

  SllNode();
  SllNode(int);
  virtual ~SllNode();
  void init(int);

  //
  //
  /**************************************
   * getter and setter for node pointers
  **************************************/

  virtual void setNext(SllNode *);
  virtual void setKey(int);
  virtual void setIndex(int);

  virtual SllNode *getNext();
  virtual int getKey();
  virtual int getIndex();

  //
  //
  /**************************************
   * management function
  **************************************/

  virtual string to_string();
};
