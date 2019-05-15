//
// Created by Marcin Włoczko on 2019-04-25.
//


#ifndef FRIDGE1_DATABASE_H
#define FRIDGE1_DATABASE_H

#include <string>
#include <vector>

using namespace std;

class Database {
private:
    vector<string> storage;

public:
    Database();
    bool add(string message);
    bool remove(string message);
    vector<string> getAll();
    bool clear();
};

#endif //FRIDGE1_DATABASE_H
