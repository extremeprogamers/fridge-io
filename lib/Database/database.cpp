//
// Created by Marcin Włoczko on 2019-04-25.
//
#include "database.h"
#include <memory>

Database :: Database() {
}

bool Database::clear() {
    storage.clear();
    return true;
}

bool Database::add(std::string message) {
    auto p = std::make_unique(Message(message));
    storage.emplace(p->id, std::move(p));
    return true;
}
 
bool Database::remove(int id) {
    storage.erase(id);
    return true;
};