//
// Created by Marcin Włoczko on 2019-04-25.
//

#include "gtest/gtest.h"
#include <string>
#include <list>
#include "database.h"

using namespace std;

string message1 = "Message 1";
string message2 = "Message 2";

TEST(database, add) {
    Database database;
    bool result = database.add(message1);
    ASSERT_TRUE(result);
}

TEST(database, getAll) {
    Database database;
    database.add(message1);
    list<string> result = database.getAll();
    ASSERT_EQ(result.size(), 1);
    database.add(message2);
    result = database.getAll();
    ASSERT_EQ(result.size(), 2);
}

TEST(database, remove) {
    Database database;
    database.add(message1);
    list<string> result = database.getAll();
    ASSERT_EQ(result.size(), 1);
    database.remove(message1);
    result = database.getAll();
    ASSERT_EQ(result.size(), 0);
}

TEST(database, clear) {
    Database database;
    database.add(message1);
    database.add(message2);
    list<string> result = database.getAll();
    ASSERT_EQ(result.size(), 2);
    database.clear();
    result = database.getAll();
    ASSERT_EQ(result.size(), 0);
}






