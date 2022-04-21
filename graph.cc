#include "graph.h"

void testGraph(){
    std::cout << "This the graph test!" << std::endl;
}



void printList(Node* ptr){
    while (ptr != nullptr)
    {
        std::cout << " —> " << ptr->code;
        ptr = ptr->next;
    }
    std::cout << std::endl;
}

int *sortArray(int arr[], int size) {
    for(int j = 1; j < size; j++){
        int key = arr[j];
        int i = j - 1;
        while(i >= 0 && arr[i] > key){
            arr[i + 1] = arr[i];
            i = i - 1;
        }
        arr[i + 1] = key;
        // std::cout << arr[size] << ",";
    }
    
    return arr;
}

void saveVerticies(std::string datesFile, int V[], std::string command){

    int y1 = 0;
    int y2 = 0;
    std::ifstream fileStream;  // ifStream variable to read through the file
    fileStream.open(datesFile);  // Opens edges.txt file
    if(fileStream.fail()){    // Makes sure the file is acutally open
        std::cerr << "Error openning file, file not found: file 1" << std::endl;
        exit(1);
    }
    std::stringstream inputString(command);     // Initializing scanning variable
    std::string year1 = "";
    std::string year2 = "";
    std::getline(inputString, year1, ' '); // 
    std::getline(inputString, year1, ' '); // 
    std::getline(inputString, year2);

    y1 = std::stoi(year1);
    y2 = std::stoi(year2);


    int count = 0;
    int n1 = 0;
    int y = 0;
    std::string line = "";   // Line will hold the value of each line in file
    while (getline(fileStream, line)){
        std::string node1 = "";
        std::string year = "";
        std::stringstream inputString(line);     // Initializing scanning variable
        std::getline(inputString, node1, '\t'); // may be a '\t' and not a ' '
        std::getline(inputString, year);


        n1 = std::stoi(node1);
        y = std::stoi(year);
        if(y >= y1 && y <= y2){
            V[count] = n1;
            // std::cout << V[count] << std::endl;
            count++;
        }
    }
    
    int *a = sortArray(V, count);
    // for(int i = 0 ; i < 11; i++){
    //     std::cout << V[i] << std::endl;
    // }
}

void saveEdges(std::string edgesFile, Edge *edges, int V[], int vNum){
    std::ifstream fileStream;  // ifStream variable to read through the file
    fileStream.open(edgesFile);  // Opens edges.txt file
    if(fileStream.fail()){    // Makes sure the file is acutally open
        std::cerr << "Error openning file, file not found: file 1" << std::endl;
        exit(1);
    }

    
    int count = 0;
    int n1 = 0;
    int n2 = 0;

    std::string line = "";   // Line will hold the value of each line in file
    while (getline(fileStream, line)){
        std::string node1 = "";
        std::string node2 = "";
        std::stringstream inputString(line);     // Initializing scanning variable


        // std::cout << line << std::endl;
        
        std::getline(inputString, node1, '\t'); // may be a '\t' and not a ' '
        std::getline(inputString, node2);

        // std::cout << "Node1: " << node1 << std::endl;
        // std::cout << "Node2: " << node2 << std::endl;

        n1 = std::stoi(node1);
        for(int i = 0; i < vNum; i++){
            if(n1 == V[i])
                n1 = i;
        }
        n2 = std::stoi(node2);
        for(int i = 0; i < vNum; i++){
            if(n2 == V[i])
                n2 = i;
        }
        

        edges[count] = {n1, n2};
        count++;
        // std::cout << "{" << n1 << ", " << n2 << "}, ";
    }
    // std::cout << count << std::endl;
    struct Edge temp[count];
    int start = 0;
    int end = count-1;
    while (start < end){
        // std::cout << "{" << edges[end].src << ", " << edges[end].dest << "}";
        temp[start] = edges[start];
        edges[start] = edges[end];
        edges[end] = temp[start];
        start++;
        end--;
    }
}



void buildGraph(std::string edgesFile, int& eNum, std::string datesFile, int& vNum, std::string command){

    struct Edge edges[eNum];
    int V[vNum];
    saveVerticies(datesFile, V, command);
    saveEdges(edgesFile, edges, V, vNum);
    // for(int i = 0; i < eNum; i++){
    //     std::cout << "{" << edges[i].src << ", " << edges[i].dest << "}";
    // }
    


    // struct Edge edges[] =
    // {
    //     // pair {x, y} represents an edge from `x` to `y`
    //     {0, 1}, {1, 2}, {2, 0}, {2, 1}, {3, 2}, {4, 5}, {5, 4}
    // };

    
 
    // construct graph
    Graph graph(edges, eNum, vNum, V);
 
    // print adjacency list representation of a graph
    for (int i = 0; i < vNum; i++)
    {
        // print given vertex
        std::cout << i;
        // print all its neighboring vertices
        printList(graph.head[i]);
    }

}