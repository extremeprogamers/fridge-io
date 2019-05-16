//
// Created by Marcin Włoczko on 2019-04-25.
//
#pragma once

#ifndef FRIDGE1_DATABASE_H
#define FRIDGE1_DATABASE_H

#include <string>
#include <vector>
#include <abstract_database.h>

using namespace std;

class Database : public AbstractDatabase {
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
