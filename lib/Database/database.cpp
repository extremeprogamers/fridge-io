//
// Created by Marcin Włoczko on 2019-04-25.
//
#include "database.h"

using namespace std;

Database :: Database() {
}

bool Database :: add(string message) {
    storage.push_front(message);
    return true;
}

bool Database ::remove(string message) {
    storage.remove(message);
    return true;
}

list<string> Database :: getAll() {
    return storage;
}

bool Database ::clear() {
    storage.clear();
    return true;
}
