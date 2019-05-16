#pragma once

#include <string>
#include <vector>

using namespace std;

class AbstractDatabase
{
public:
    virtual bool add(string message) = 0;
    virtual bool remove(string message) = 0;
    virtual vector<string> getAll() = 0;
    virtual bool clear() = 0;    
};