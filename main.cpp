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

            countVerticies(argv[2], currComm, vNum);
            int V[vNum];
            saveVerticies(argv[2], V, currComm);
            countEdges(argv[1], currComm, eNum, V, vNum);            

            struct Edge edges[eNum];
            saveEdges(argv[1], edges, V, vNum);
            cout << "\t|V| = " << vNum << " verticies" << endl;
            cout << "\t|E| = " << eNum << " edges" << endl;
        
            reverseArray(edges, eNum);
            Graph graph(edges, eNum, vNum, V);
            
            
            // // section prints out adjacency list for testing
            // for (int i = 0; i < vNum; i++){
            // // print given vertex
            // std::cout << i;
            // // print all its neighboring vertices
            // printList(graph.head[i]);
            // }
            

            newLine();
        }

        else if(currComm[1] == 'u'){ // Current Command is: out-degree
            cout << "Command: " << currComm << endl;
            newLine();
            cout << "The graph G has average out-degree " 
            << eNum << "/" << vNum << " = " << std::fixed << std::setprecision(2) << calculateDegree(eNum, vNum) << endl;

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