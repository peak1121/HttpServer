#include "base/baseTest.h"
#include<iostream>

class netTest
{

public:
    netTest() : bt(baseTest()){}
    ~netTest(){}
    void netTestFun();
private:
    baseTest bt;
};
