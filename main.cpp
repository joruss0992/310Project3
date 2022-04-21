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

    int eNum = 0;   // Variables used to save number of edges, verticies and commands respectively
    int vNum = 0;
    int cNum = 0;
    string currComm = "";   // current command is stored in this string

    countLines(argv[3], cNum);  // function counts number of commands
    string commands[cNum];  // Initializes array of commands to number of commands in file
    saveComm(commands, argv[3]);    // function then saves all commands to array

    
    for(int i = 0; i < cNum; i++){  // Loop iterates through every command and handles it
        currComm = commands[i];

        // Checks which command is being asked by comparing the second character
        // to the given command
        if(currComm[1] == 't'){ // Current Command is: start-graph
            cout << "Command: " << currComm << endl;
            newLine();
            
            countLines(argv[1], eNum);
            countVerticies(argv[2], currComm, vNum);

            cout << "\t|V| = " << vNum << " verticies" << endl;
            cout << "\t|E| = " << eNum << " edges" << endl;
            
            buildGraph(argv[1], eNum, argv[2], vNum, currComm);
            

            newLine();
        }

        else if(currComm[1] == 'u'){ // Current Command is: out-degree
            cout << "Command: " << currComm << endl;
            newLine();
        }

        else if(currComm[1] == 'i'){ // Current Command is: diameter
            cout << "Command: " << currComm << endl;
            newLine();
        }

        else if(currComm[1] == 'c'){ // Current Command is: scc
            cout << "Command: " << currComm << endl;
            newLine();
        }

        else if(currComm[1] == 'n'){ // Current Command is: end-graph
            cout << "Command: " << currComm << endl;
            newLine();
        }
        else    // If this is reached, the command didn't match and is an error
            return -1;
    }




    
       
    return 0;
}