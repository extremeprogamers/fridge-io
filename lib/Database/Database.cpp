#include "Database.h"

bool Database::add(string message) {
    storage.push_back(message);
    return true;
}

bool Database::remove(string message) {
    storage.erase(storage.begin());
    return true;
}

vector<string> Database::getAll() {
    return storage;
}

bool Database::clear() {
    storage.clear();
    return true;
}
