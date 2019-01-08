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
  SllNode();
  SllNode(int);
  virtual ~SllNode();
  void init(int);

  virtual void setNext(SllNode *);
  virtual void setKey(int);
  virtual void setIndex(int);

  virtual SllNode *getNext();
  virtual int getKey();
  virtual int getIndex();

  virtual string to_string();
};
