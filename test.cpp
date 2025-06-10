// liadi.haim@gmail.com

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.hpp"
#include "MyContainer.hpp"
#include <string>
#include <vector>
#include <stdexcept>

using namespace MyNamespace;
using std::vector;
using std::string; 
//Helper: collect range into vector (works with our iterators)
template<typename Range>
auto collect(const Range& rng) {
    using Elem = std::decay_t<decltype(*rng.begin())>;
    std::vector<Elem> out;
    for (auto it = rng.begin(); it != rng.end(); ++it) out.push_back(*it);
    return out;
}
// print vector 
TEST_CASE("Basic operations – ints") {
    MyContainer<int> c;

    SUBCASE("Empty container") {
        CHECK(c.size() == 0);
        CHECK(c.empty());
    }

    SUBCASE("Add & index access") {
        for (int v : {5, 3, 8}) c.add(v);
        CHECK(c.size() == 3);
        CHECK_FALSE(c.empty());
        CHECK(c[0] == 5);
        CHECK(c[1] == 3);
        CHECK(c[2] == 8);
    }

    SUBCASE("Remove existing (all duplicates)") {
        c.add(5); c.add(3); c.add(8); c.add(3);
        CHECK(c.size() == 4);
        c.remove(3);
        CHECK(c.size() == 2);
        CHECK(c[0] == 5);
        CHECK(c[1] == 8);
    }

    SUBCASE("Remove non‑existing throws") {
        c.add(5);
        CHECK_THROWS_AS(c.remove(10), std::runtime_error);
    }

    SUBCASE("Out‑of‑range throws") {
        c.add(1);
        CHECK_THROWS_AS(c[2], std::out_of_range);
    }
}

// Test insertion order and removal
TEST_CASE("Different element types") {
    SUBCASE("std::string") {
        MyContainer<string> sc;
        for (auto &w : {"hello", "world", "cpp"}) sc.add(w);
        CHECK(sc.size() == 3);
        sc.remove("world");
        // insertion order after removal
        CHECK(collect(MyContainer<string>::Order(sc)) == vector<string>{"hello", "cpp"});
    }

    SUBCASE("double") {
        MyContainer<double> dc{3.14, 2.71, 1.41};
        CHECK(dc.size() == 3);
        CHECK(dc[0] == doctest::Approx(3.14));
    }
}

//Fixed demo container for iterator tests
static MyContainer<int> demo_container() {
    MyContainer<int> c;
    for (int v : {7, 15, 6, 1, 2}) c.add(v);
    return c;
}

//Iterator order tests (each order separately)

TEST_CASE("AscendingOrder") {
    auto c = demo_container();
    vector<int> expected{1, 2, 6, 7, 15};
    MyContainer<int>::AscendingOrder asc(c);
    CHECK(collect(asc) == expected);
}

TEST_CASE("DescendingOrder") {
    auto c = demo_container();
    vector<int> expected{15, 7, 6, 2, 1};
    MyContainer<int>::DescendingOrder desc(c);
    CHECK(collect(desc) == expected);
}

TEST_CASE("SideCrossOrder") {
    auto c = demo_container();
    vector<int> expected{1, 15, 2, 7, 6};
    MyContainer<int>::SideCrossOrder cross(c);
    CHECK(collect(cross) == expected);
}

TEST_CASE("ReverseOrder") {
    auto c = demo_container();
    vector<int> expected{2, 1, 6, 15, 7};
    MyContainer<int>::ReverseOrder rev(c);
    CHECK(collect(rev) == expected);
}

TEST_CASE("Insertion order (Order)") {
    auto c = demo_container();
    vector<int> expected{7, 15, 6, 1, 2};
    MyContainer<int>::Order ord(c);
    CHECK(collect(ord) == expected);
}

TEST_CASE("MiddleOutOrder") {
    auto c = demo_container();
    vector<int> expected{6, 15, 1, 7, 2};
    MyContainer<int>::MiddleOutOrder mid(c);
    CHECK(collect(mid) == expected);
}

// Edge cases – empty container & single element

TEST_CASE("Iterators on empty container") {
    MyContainer<int> c;
    CHECK(collect(MyContainer<int>::AscendingOrder (c)).empty());
    CHECK(collect(MyContainer<int>::DescendingOrder(c)).empty());
    CHECK(collect(MyContainer<int>::Order         (c)).empty());
}

TEST_CASE("Iterators on single element container") {
    MyContainer<int> c; c.add(42);
    vector<int> single{42};
    CHECK(collect(MyContainer<int>::AscendingOrder (c)) == single);
    CHECK(collect(MyContainer<int>::MiddleOutOrder(c)) == single);
}

//Copy constructor and assignment operator

TEST_CASE("Copy semantics") {
    MyContainer<int> src{1, 2, 3};

    SUBCASE("Copy ctor") {
        MyContainer<int> dst(src);
        CHECK(collect(MyContainer<int>::Order(dst)) == vector<int>{1, 2, 3});
    }

    SUBCASE("Assignment operator") {
        MyContainer<int> dst; dst.add(99);
        dst = src;
        CHECK(collect(MyContainer<int>::Order(dst)) == vector<int>{1, 2, 3});
    }
}
