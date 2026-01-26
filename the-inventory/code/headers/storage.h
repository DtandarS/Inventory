#pragma once


#include <master.h>
#include <string>
#include <cstring>
using namespace std;

static void msg(char *msg)
{
  fprintf(stderr, "[%d] %s\n,", errno, msg);
}

struct Storage
{
  char name;
  int amount;
  int total_amount;
  int meow;
};




