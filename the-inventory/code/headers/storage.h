#pragma once


#include <master.h>
using namespace std;


struct Storage
{
  //  Still new to vectors but my idea is to create a cluster table. When we access the first index then we will check the first index of all vectors but if we want a different name then we will first go through the vector and once we find it. We will go through that column.
  vector<string> names;
  vector<int> amount;
  vector<int> price;

  //  These are some basic boolean values right now. Meant to be used as simple on off switch to tell like "Your booze is almost out" notifications
  bool inStock = false;
  bool wants_add = false;
  bool wants_remove = false;

  //  Count-up() is mean to be used as calculation and validation function. This is nothing crazy.
  //  Same as Count_up(). Count_down() simply does the calculation function and validates the amounts.
  int count_up();
  int count_down();
};

