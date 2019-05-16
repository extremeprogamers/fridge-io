#pragma once

#ifndef FRIDGE1_DATABASE_H
#define FRIDGE1_DATABASE_H

#include <string>
#include <vector>
#include "AbstractDatabase.h"

using namespace std;

class Database : public AbstractDatabase {
private:
    vector<string> storage;

public:
    bool add(string message);
    bool remove(string message);
    vector<string> getAll();
    bool clear();
};

#endif