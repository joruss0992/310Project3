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
    int degree = 0;
    int max = 0;
    int year1 = 0;
    int year2 = 0;
    string out = "";



    countLines(argv[3], cNum);  // function counts number of commands
    string commands[cNum];  // Initializes array of commands to number of commands in file
    saveComm(commands, argv[3]);    // function then saves all commands to array






    for(int i = 0; i < cNum; i++){  // Checks every command's end and makes sure \r isn't there
        currComm = commands[i];
        if(currComm.back() == '\r'){
            currComm.pop_back();
        }
                

        // Checks which command is being asked by comparing the second character
        // to the given command
        if(currComm[1] == 't'){ // Current Command is: start-graph
            currComm += "";
            cout << "Command: " << currComm << endl;
            newLine();
            // Number of verticies and edges are calculated and saved into arrays V and edges
            // --------------------------------------------------------
            countVerticies(argv[2], currComm, vNum, year1, year2);
            int V[vNum];
            saveVerticies(argv[2], V, currComm);
            countEdges(argv[1], currComm, eNum, V, vNum);            
            struct Edge edges[eNum];
            saveEdges(argv[1], edges, V, vNum);
            // --------------------------------------------------------
            
            reverseArray(edges, eNum);  // Edges is reversed so the values are in incrementing order
            Graph graph(edges, eNum, vNum, V);  // Graph is greated


            std::stringstream buffer;
            buffer << "The graph G for the years " << year1 << " " << year2 << " has:" << endl;
            cout << buffer.str();
            cout << "\t|V| = " << vNum << " vertices" << endl;
            cout << "\t|E| = " << eNum << " edges" << endl;
            
            // // section prints out adjacency list for testing
            // for (int i = 0; i < vNum; i++){
            //     // print given vertex
            //     std::cout << i;
            //     // print all its neighboring vertices
            //     printList(graph.head[i]);
            // }
            
            int outArray[vNum]; // Array holds all out degree values who's maximum value is # of Nodes
            max = 0;    // Max keep track of how many different degrees there are
            degree = 0; // Holds the degree value for each node 

            for (int i = 0; i < vNum; i++){ // initialize each value in array = 0;
                int present = 0;
                outArray[i] = present;
            }
            for (int i = 0; i < vNum; i++){ // for every vertex, count how how many edges each one has
                degreeDist(graph.head[i], degree);
                if(degree == 0){    // If the degree = 0, it has no edges
                    outArray[degree]++; // Increment the 0th degree tally
                    continue;   // Jump back to the top of array
                }
                outArray[degree]++; // Otherwise, the current vertex has edges and it's number's position is 
                                    // tallied in the array
                if(degree > max)    // Max keeps track of how many unique edges counters there are
                    max = degree;   // If the current degree is bigger, max is increased to that degree
            }
            for (int i = 0; i < max+1; i++){    // For every unique degree found, it is printed into:
                string in = to_string(i);   // in holds current index
                string deg = to_string(outArray[i]);    // out holds current degree distribution
                out = out + "\n\t" + in + " : " + deg;  // Out is the string that holds the degree output
            }
            newLine();
        }

        else if(currComm[1] == 'u'){ // Current Command is: out-degree
        // Most of this command's data is calculated where the graph is formed
            cout << "Command: " << currComm << endl;
            newLine();
            cout << "The graph G has average out-degree " 
            << eNum << "/" << vNum << " = " << std::fixed 
            << std::setprecision(2) << calculateDegree(eNum, vNum) << "." << endl;    // rounded to two places
            newLine();
            cout << "The out-degree distribution is:\n\tOut-degree : Number of vertices";
            cout << out << endl;    // out is printed which was created previously
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
            return 0;   // The program is ended
        }
        else    // If this is reached, the command didn't match and is an error
            return -1;
    }




    return -1;  // This shouldn't be reachable
}