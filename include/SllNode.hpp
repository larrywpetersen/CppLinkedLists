#pragma once

#include <iostream>
using namespace std;

using keyType = long;
using indexType = int;

// template <class T>
class SllNode
{

private:
  SllNode *prtNext;
  keyType key;
  void *data;

  static indexType index;

public:
  //
  //
  /**************************************
   * constructor and destructor
   *************************************/

  SllNode();
  SllNode(keyType);
  SllNode(void *);
  SllNode(keyType, void *);
  void init(keyType, void *);

  virtual ~SllNode();

  //
  //
  /**************************************
   * getters and setters
   *************************************/

  virtual void *getData();
  virtual SllNode *getNext();
  virtual keyType getKey();
  virtual indexType getIndex();

  virtual void setData(void *);
  virtual void setNext(SllNode *);
  virtual void setKey(keyType);
  virtual void setIndex(indexType);

  //
  //
  /**************************************
   * management function
   *************************************/

  virtual string to_string();
};
