#pragma once

#include <iostream>
using namespace std;

class SllNode
{

private:
  SllNode *prtNext;
  long key;

  static long index;

public:
  //
  //
  /**************************************
   * constructor and destructor
   *************************************/

  SllNode();
  SllNode(long);
  virtual ~SllNode();
  void init(long);

  //
  //
  /**************************************
   * getters and setters
   *************************************/

  virtual SllNode *getNext();
  virtual long getKey();
  virtual long getIndex();

  virtual void setNext(SllNode *);
  virtual void setKey(long);
  virtual void setIndex(long);

  //
  //
  /**************************************
   * management function
   *************************************/

  virtual string to_string();
};
