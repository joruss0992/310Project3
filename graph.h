#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <locale>

void testGraph();
void buildGraph(std::string edgesFile, int& eNum, std::string datesFile, int& vNum, std::string command);
// void saveEdges(std::string edgesFile, Edge *edges);
void saveNodes();
int *sortArray(int arr[], int size);



struct Node{
    int code;
    int list_index;
    Node* next;
};

struct Edge{
    int src, dest;
};

class Graph{
    // Function to allocate a new node for the adjacency list
    Node* getAdjListNode(int dest, Node* head)
    {
        Node* newNode = new Node;
        newNode->code = dest;
    
        // point new node to the current head
        newNode->next = head;
        // std::cout << newNode->code << "----" << newNode->next << std::endl;
        return newNode;
    }

    int N; // total number of verticies in graph

public:
 
    // An array of pointers to Node to represent the
    // adjacency list
    Node **head;
 
    // Constructor
    Graph(Edge edges[], int n, int N, int V[])
    {
        // allocate memory
        head = new Node*[N]();
        this->N = N;
 
        // initialize head pointer for all vertices
        for (int i = 0; i < N; i++) {
            head[i] = nullptr;
        }
 
        // add edges to the directed graph
        for (unsigned i = 0; i < n; i++)
        {
            int src = edges[i].src;
            int dest = edges[i].dest;

            
            // insert at the beginning
            Node* newNode = getAdjListNode(dest, head[src]);
 
            // point head pointer to the new node
            head[src] = newNode;        
            // std::cout << edges[i].src << "-->" << edges[i].dest << std::endl;

        }
    }
 
    // Destructor
    ~Graph() {
        for (int i = 0; i < N; i++) {
            delete[] head[i];
        }
 
        delete[] head;
    }
};

void printList(Node* ptr);
