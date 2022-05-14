#pragma once
#include<iostream>
#include "Exception.h"
#include "MyException.h"
using namespace std;

class Object
{
    static unsigned int count;
public:
    Object();
    ~Object();
    unsigned int get_count() { return count; };
};
