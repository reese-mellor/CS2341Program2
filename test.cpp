//#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "DSList.h"
#include "DSStack.h"
#include "DSStackList.h"
using namespace std;
// add includes
TEST_CASE("Check that DSList works", "[DSList]")
{
    //TEST INTS
    DSList <int> a;
    DSList <int> b;
    DSList<int> c;
    DSList<char> isItEmpty;

    DSList<string> d;
    DSList<string> e;
    string f = "d";
    d.push_back(f); //d0
    string etemp = "z";
    d.push_back("z");
    e.push_back(etemp); //e0 = z
    e.push_back("hello"); //e1 = hello
    e.push_back("my little"); //e2
    e.push_back("friend"); //e3
    e.push_back("welcome");//e4
    e.push_back("to");//e5
    e.push_back("cs2341");//e6
    e.push_back("with Hahsler"); //e7

    //create info to test on
    int temp = 12;
    a.push_back(temp); //rewrite it later
    temp += 5;
    a.push_back(temp);
    temp -= 9;
    for (int i = 0; i < 10; i++){
        b.push_back(i);
    }
    for (int i = 10; i > 0; i--){
        c.push_back(i);
    }
    int tempIt = a.size();
    // add test cases (create lists and specify what the expected output is)
    SECTION("Size"){
        REQUIRE((a.size() == 2));
        REQUIRE((!(b.size() == 7)));
        REQUIRE((!(c.size() == 14)));
    }
    SECTION("ElementAt"){
        REQUIRE((e.elementAt("cs2341") == 7));
        REQUIRE((e.elementAt("friend") == 4));
        REQUIRE((!(d.elementAt("z") == 1)));
    }
}
TEST_CASE("Check that DSStack works", "[DSStack]"){
    DSStack<int> a;
    DSStack<char> checker;
    DSStack<char> b;
    DSStack<int> c;

    c.push(1);
    c.push(2);
    c.push(3);
    REQUIRE((c.size()==3));
    REQUIRE((c.top() == 1));
    CHECK((!(a.size() == c.size())));
    CHECK((!(a.size() == c.size())));
    a.push(3);
    a.push(2);
    a.push(4);
    checker.push(2);
    a.pop();
    REQUIRE((a.size() == checker.size()));
    //Push, pop, removeValAt, top, empty, size
}
TEST_CASE("Check that DSStackList works", "[DSStackList]"){
    DSStackList<int> temp;
    DSStackList<int> check;
    DSStackList<char> charTemp;
    DSStackList<char> charTest;
    DSStackList<int> emptyTemp;

    charTest.push('a');
    temp.push(1);
    CHECK((temp.pop() == 1));
    temp.push(9);
    CHECK((temp.size() == 1));
    temp.push(10);
    temp.push(11); //size = 3
    check.push(2);
    check.push(6);
    check.push(9);
    check.push(8); //size = 3
    //CHECK((check.size() == temp.size()));
    REQUIRE((!(charTest.size() == check.size())));
    REQUIRE((!(charTest.pop() == check.pop())));
    CHECK((emptyTemp.size() == 0));
}
// you can run the test using Run CTest in the task bar or by running the tests executable.