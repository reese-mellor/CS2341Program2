#define CATCH_CONFIG_RUNNER //defines an environment variable to call functions within catch
#include <iostream>
#include <algorithm>
#include "DSList.h"
#include "DSStack.h"
#include "catch2/catch.hpp"
#include "checker.h"
using namespace std;

int main(int argc, char **argv)
{
    chrono::duration<double> runTime;
    chrono::time_point<chrono::high_resolution_clock> start, end;
    start = chrono::high_resolution_clock::now();

    //if catch
    if(argc == 1){
        return Catch::Session().run(); //will run catch test if no arguments
    }
    //else: whatever for program
    else{
        checker c;
        c.checkingVector(argv[1]);
        //c.checkingLinkList(argv[1]);
    }

    end = chrono::high_resolution_clock::now();
    runTime = end - start;
    cout << runTime.count() << " second" <<endl;
    // A return code != 0 tells the operating system that there is an issue
    return 1;
}

// in the terminal type `cd build` and then `./check_brackets test_data/*`