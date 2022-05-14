#pragma once
#include<iostream>
#include<string>
using namespace std;
class MyException
{
    string message;
public:
    MyException(string message) : message(message) {}
    string What() { return message; }
};
