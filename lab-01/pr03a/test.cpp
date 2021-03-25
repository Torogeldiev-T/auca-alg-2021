#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest.h"
#include <utility>
#include "List.hpp"
// TEST_CASE("constructor")
// {
//     List<int> v;
//     v.pushBack(1);
//     v.pushBack(2);
//     v.pushBack(3);
//     REQUIRE(v.size() == 3);
//     REQUIRE(v.toStr() == "{1, 2, 3}");
//     REQUIRE(v.toReversedStr() == "{3, 2, 1}");
// }
TEST_CASE("List<T>:: Iter")
{
    List<int> v;
    v.pushBack(1);
    v.pushBack(2);
    v.pushBack(3);

    auto it = v.begin();
    REQUIRE(*it == 1);
    ++it;
    REQUIRE(*it == 2);
    ++it;
    REQUIRE(*it == 3);
    ++it;
    REQUIRE(it == v.end());
    --it;
    REQUIRE(*it == 3);
    --it;
    REQUIRE(*it == 2);
    --it;
    REQUIRE(*it == 1);
    REQUIRE(it == v.begin());
    std::ostringstream out;
    for (auto e : v)
    {
        out << " " << e;
    }
    REQUIRE(out.str() == " 1 2 3");
    std::reverse(v.begin(), v.end());
    REQUIRE(v.toStr() == "{3, 2, 1}");
}
TEST_CASE("erase")
{
    List<int> v;
    v.pushBack(1);
    v.pushBack(2);
    v.pushBack(3);

    auto it = v.begin();
    ++it;
    it = v.erase(it);
    REQUIRE(v.size() == 2);
    REQUIRE(v.toStr() == "{1, 3}");

    it = v.erase(it);
    REQUIRE(v.size() == 1);
    REQUIRE(v.toStr() == "{1}");
    REQUIRE(it == v.end());

    --it;
    it = v.erase(it);
    REQUIRE(v.size() == 0);
    REQUIRE(v.toStr() == "{}");
    REQUIRE(it == v.end());
}

TEST_CASE("List<pair<int,int> v")
{
    List<std::pair<int, int>> v;
    v.pushBack({1, 1});
    v.pushBack({2, 2});
    v.pushBack({3, 3});

    auto it = v.begin();
    REQUIRE(it->first == 1);
    ++it;
    REQUIRE(it->first == 2);
    ++it;
    REQUIRE(it->first == 3);
    ++it;
    REQUIRE(it == v.end());
    --it;
    REQUIRE(it->second == 3);
    --it;
    REQUIRE(it->second == 2);
    --it;
    REQUIRE(it->second == 1);
    REQUIRE(it == v.begin());
}
TEST_CASE("popback")
{
    List<int> v;
    v.pushBack(1);
    v.pushBack(2);
    v.pushBack(3);
    v.popBack();
    REQUIRE(v.size() == 2);
    REQUIRE(v.toStr() == "{1, 2}");
    auto it = v.begin();
    REQUIRE(*it == 1);
    ++it;
    REQUIRE(*it == 2);
    ++it;
    REQUIRE(it == v.end());
}
TEST_CASE("pushback")
{
    List<int> v;
    v.pushBack(1);

    auto it = v.begin();
    REQUIRE(v.toStr() == "{1}");
    REQUIRE(v.size() == 1);
    REQUIRE(*it == 1);

    v.pushBack(2);

    REQUIRE(v.toStr() == "{1, 2}");
    REQUIRE(v.size() == 2);
    ++it;
    REQUIRE(*it == 2);

    v.pushBack(3);

    REQUIRE(v.toStr() == "{1, 2, 3}");
    REQUIRE(v.size() == 3);
    ++it;
    REQUIRE(*it == 3);
}
TEST_CASE("pushfront")
{
    List<int> v;
    v.pushFront(1);

    auto it = v.begin();
    REQUIRE(v.toStr() == "{1}");
    REQUIRE(v.size() == 1);
    REQUIRE(*it == 1);

    v.pushFront(2);
    it = v.begin();
    REQUIRE(v.toStr() == "{2, 1}");
    REQUIRE(v.size() == 2);
    REQUIRE(*it == 2);

    v.pushFront(3);
    it = v.begin();
    REQUIRE(v.toStr() == "{3, 2, 1}");
    REQUIRE(v.size() == 3);
    REQUIRE(*it == 3);
    ++it;
    REQUIRE(*it == 2);
    ++it;
    REQUIRE(*it == 1);
}
TEST_CASE("popFront")
{
    List<int> v;
    v.pushBack(1);
    v.pushBack(2);
    v.pushBack(3);

    v.popFront();
    REQUIRE(v.size() == 2);
    REQUIRE(v.toStr() == "{2, 3}");
    auto it = v.begin();
    REQUIRE(*it == 2);
    ++it;
    REQUIRE(*it == 3);
    ++it;
    REQUIRE(it == v.end());
}
TEST_CASE("copy_constuctor")
{
    List<int> v;
    v.pushBack(1);
    v.pushBack(2);
    v.pushBack(3);

    List<int> v2 = v;
    REQUIRE(v2.size() == 3);
    REQUIRE(v2.toStr() == "{1, 2, 3}");
    auto it = v2.begin();
    REQUIRE(*it == 1);
    ++it;
    REQUIRE(*it == 2);
    ++it;
    REQUIRE(*it == 3);
    ++it;
    REQUIRE(it == v2.end());
}
TEST_CASE("move_constuctor")
{
    List<int> v;
    v.pushBack(1);
    v.pushBack(2);
    v.pushBack(3);
    v.pushBack(3);
    v.pushBack(3);
    v.pushBack(3);
    v.pushBack(3);
    v.pushBack(3);
    v.pushBack(3);
    v.pushBack(3);
    v.pushBack(3);
    v.pushBack(3);
    v.pushBack(3);
    v.pushBack(3);
    v.pushBack(3);
    v.pushBack(3);
    v.pushBack(3);
    v.pushBack(3);
    v.pushBack(3);
    v.pushBack(3);
    v.pushBack(3);
    v.pushBack(3);
}