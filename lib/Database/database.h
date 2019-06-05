//
// Created by Marcin Włoczko on 2019-04-25.
//
#pragma once

#ifndef FRIDGE1_DATABASE_H
#define FRIDGE1_DATABASE_H

#include <map>
#include <memory>
#include <string>
#include <vector>
#include <abstract_database.h>
#include "message.h"


class Database : public AbstractDatabase {
  public:
    Database();
    bool add(std::string message);
    bool remove(int id);
    bool clear();
    std::vector<std::string> getAll();

  private:
    std::map<int, unique_ptr<Message>> storage;
    int max_id = 0;
};

#endif
