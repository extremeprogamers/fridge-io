//
// Created by Marcin Włoczko on 2019-04-25.
//
#include "database.h"

using namespace std;

Database :: Database() {
}

bool Database :: add(string message) {
    storage.push_back(message);
    return true;
}

bool Database ::remove(string message) {
    storage.erase(storage.begin());
    return true;
}

vector<string> Database :: getAll() {
    return storage;
}

bool Database ::clear() {
    storage.clear();
    return true;
}
