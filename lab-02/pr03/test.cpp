#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest.h"
#include "BSTreeInt.hpp"
TEST_CASE("constructor")
{
    BSTreeInt v;
    REQUIRE(v.size() == 0);
}
TEST_CASE("insert")
{
    BSTreeInt v;
    REQUIRE(v.insert(6));
    REQUIRE(v.debug == "");
    REQUIRE(v.insert(5));
    REQUIRE(v.debug == "L");
    REQUIRE(v.insert(9));
    REQUIRE(v.debug == "R");
    REQUIRE(v.insert(1));
    REQUIRE(v.debug == "LL");
    REQUIRE(v.insert(4));
    REQUIRE(v.debug == "LLR");
    REQUIRE(v.insert(7));
    REQUIRE(v.debug == "RL");
    REQUIRE(v.insert(10));
    REQUIRE(v.debug == "RR");
}
TEST_CASE("print")
{
    BSTreeInt v;
    REQUIRE(v.insert(6));
    REQUIRE(v.insert(3));
    REQUIRE(v.insert(9));
    REQUIRE(v.insert(1));
    REQUIRE(v.insert(4));
    REQUIRE(v.insert(7));
    REQUIRE(v.insert(10));
    std::ostringstream out;
    v.print(out);
    REQUIRE(out.str() == "{1, 3, 4, 6, 7, 9, 10}");
    v.insert(2);
    out.str("");
    out.clear();
    v.print(out);
    REQUIRE(out.str() == "{1, 2, 3, 4, 6, 7, 9, 10}");
}
TEST_CASE("erase")
{
    std::ostringstream out;
    BSTreeInt v;
    SUBCASE("one node")
    {
        REQUIRE(v.insert(6));
        REQUIRE(v.erase(6));
        REQUIRE(v.size() == 0);
        v.print(out);
        REQUIRE(out.str() == "{}");
    }
    SUBCASE("many nodes")
    {
        REQUIRE(v.insert(6));
        REQUIRE(v.insert(3));
        REQUIRE(v.insert(9));
        REQUIRE(v.insert(1));
        REQUIRE(v.insert(4));
        REQUIRE(v.insert(7));
        REQUIRE(v.insert(10));

        REQUIRE(v.erase(4));
        REQUIRE(v.size() == 6);
        v.print(out);
        REQUIRE(out.str() == "{1, 3, 6, 7, 9, 10}");

        REQUIRE(v.erase(1));
        REQUIRE(v.size() == 5);
        out.str("");
        out.clear();
        v.print(out);
        REQUIRE(out.str() == "{3, 6, 7, 9, 10}");
    }
}

TEST_CASE("erase node woth one child")
{
    std::ostringstream out;
    BSTreeInt v;
    REQUIRE(v.insert(6));
    REQUIRE(v.insert(3));
    REQUIRE(v.insert(9));
    REQUIRE(v.insert(1));
    REQUIRE(v.insert(4));
    REQUIRE(v.insert(7));
    REQUIRE(v.insert(10));
    REQUIRE(v.insert(12));
    REQUIRE(v.insert(11));

    REQUIRE(v.erase(10));
    REQUIRE(v.size() == 8);
    v.print(out);
    REQUIRE(out.str() == "{1, 3, 4, 6, 7, 9, 11, 12}");

    REQUIRE(v.insert(2));
    REQUIRE(v.erase(1));
    REQUIRE(v.size() == 8);
    out.str("");
    v.print(out);
    REQUIRE(out.str() == "{2, 3, 4, 6, 7, 9, 11, 12}");
}
