#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest.h"

#include "HashSetStr.hpp"
TEST_CASE("constructor")
{
    HashSetStr v;

    REQUIRE(v.size() == 0);
}
TEST_CASE("insert")
{
    HashSetStr v;

    REQUIRE(v.insert("C++") == true);
    REQUIRE(v.size() == 1);
    REQUIRE(!v.insert("C++"));

    REQUIRE(v.insert("C") == true);
    REQUIRE(v.size() == 2);
    REQUIRE(!v.insert("C"));

    REQUIRE(v.insert("python") == true);
    REQUIRE(v.size() == 3);
    REQUIRE(!v.insert("python"));

    REQUIRE(v.insert("java") == true);
    REQUIRE(v.size() == 4);
    REQUIRE(!v.insert("java"));

    REQUIRE(v.insert("jaba") == true);
    REQUIRE(v.size() == 5);
    REQUIRE(!v.insert("jaba"));

    REQUIRE(v.insert("scala") == true);
    REQUIRE(v.size() == 6);
    REQUIRE(!v.insert("scala"));
}
TEST_CASE("Clear")
{
    HashSetStr v;

    REQUIRE(v.insert("C++"));
    REQUIRE(v.insert("C"));

    REQUIRE(v.insert("C+"));
    REQUIRE(v.insert("C+-"));
    REQUIRE(v.insert("C-+"));
    REQUIRE(v.insert("C--"));
    //v.print();
    v.clear();
    REQUIRE(v.size() == 0);
}
TEST_CASE("erase")
{
    HashSetStr v;

    REQUIRE(v.insert("C++"));
    REQUIRE(v.insert("C"));
    REQUIRE(v.insert("C+"));

    REQUIRE(v.erase("C++"));
    v.print();
    REQUIRE(v.size() == 2);
}
TEST_CASE("print")
{
    HashSetStr v;

    REQUIRE(v.insert("C++"));
    REQUIRE(v.insert("C"));
    REQUIRE(v.insert("C+"));
    REQUIRE(v.insert("Python"));
    v.print();
    REQUIRE(v.erase("C++"));
    REQUIRE(v.size() == 3);
}