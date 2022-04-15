// Jacob Russ
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <locale>

#include "utilities.h"
#include "graph.h"
#include "floyd.h"
#include "dfs.h"

using namespace std;



int main(int argc,char* argv[]){

    cout << "This is project 3!" << endl;
    test();
    testGraph();
    testFloyd();
    testDFS();
    
    return 0;
}