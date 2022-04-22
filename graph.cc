#include "graph.h"


// This function would print the adjacency list
// I mainly used it for testing if it was built properly
void printList(Node* ptr){
    while (ptr != nullptr)
    {
        std::cout << " —> " << ptr->code;
        ptr = ptr->next;
    }
    std::cout << std::endl;
}

// This is an insertion sort algorithm to sort the Verticies in V
// I got it from my project 1
int *sortArray(int arr[], int size) {
    for(int j = 1; j < size; j++){
        int key = arr[j];
        int i = j - 1;
        while(i >= 0 && arr[i] > key){
            arr[i + 1] = arr[i];
            i = i - 1;
        }
        arr[i + 1] = key;
    }
    return arr;
}

// Function saves the verticies from the file, so long as the year is within the parameters
// given from the command
// Functions exactly like countVerticies function in utilities.cc
// However this time, the values are saved to the array V then sorted in increasing order
void saveVerticies(std::string datesFile, int V[], std::string command){
    int y1 = 0;
    int y2 = 0;
    std::ifstream fileStream;  // ifStream variable to read through the file
    fileStream.open(datesFile);  // Opens dates.txt file
    if(fileStream.fail()){    // Makes sure the file is acutally open
        std::cerr << "Error openning file, file not found: file 1" << std::endl;
        exit(1);
    }
    std::stringstream inputString(command);     // Initializing scanning variable
    std::string year1 = "";
    std::string year2 = "";
    std::getline(inputString, year1, ' '); 
    std::getline(inputString, year1, ' ');  
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
        std::getline(inputString, node1, '\t');
        std::getline(inputString, year);


        n1 = std::stoi(node1);
        y = std::stoi(year);
        if(y >= y1 && y <= y2){ // if the year is between command years, the value is saved to V
            V[count] = n1;  
            count++;
        }
    }
    
    int *a = sortArray(V, count);   // V is then sorted using insertion sort
}

// This function saves the edges given from edges file
// It then assignes the edges value the index position represented in array V
// This allows for the adjacency list to properly form itself with values:
//  0,1,2,3, ... , n for an n numbered verticies
void saveEdges(std::string edgesFile, Edge *edges, int V[], int vNum){
    std::ifstream fileStream;  // ifStream variable to read through the file
    fileStream.open(edgesFile);  // Opens edges.txt file
    if(fileStream.fail()){    // Makes sure the file is acutally open
        std::cerr << "Error openning file, file not found: file 1" << std::endl;
        exit(1);
    }
    int count = 0;  // a node is a given verticy
    // int repeats = 0;
    

    std::string line = "";   // Line will hold the value of each line in file
    while (getline(fileStream, line)){
        int n1 = 0;
        int n2 = 0;
        bool inside = false;
        std::string node1 = "";
        std::string node2 = "";
        std::stringstream inputString(line);     // Initializing scanning variable

        std::getline(inputString, node1, '\t'); // Saves the value of verticy in string form temporarily
        std::getline(inputString, node2);
        
        // int b = n1;
        n1 = std::stoi(node1);  // Converts node1 to int and finds which index it should be represented
        n2 = std::stoi(node2);

        std::cout << n1 << std::endl;
        std::cout << n2 << std::endl;
        
        

        inside = check(V, vNum, n1);
        std::cout << inside << std::endl;

        if(inside == false){
            continue;
        }

        inside = check(V, vNum, n2);
        std::cout << inside << std::endl;

        if(inside == false){
            continue;
        }

        for(int i = 0; i < vNum; i++){  // Goes through array V and finds match, the position found is
            if(n1 == V[i]){              // then saved as the value
                n1 = i;
                std::cout << n1 << std::endl;
            }
        }
        
        for(int i = 0; i < vNum; i++){
            if(n2 == V[i]){              // then saved as the value
                n2 = i;
                std::cout << n2 << std::endl;
            }
        }
        

        edges[count] = {n1, n2};    // array of edges are then saved
        count++;
        // int a = n1;
        // if(a == b){
        //     repeats++;
        // }
        // std::cout << repeats << std::endl;
    }
}

void reverseArray(struct Edge edges[], int size){
    struct Edge temp[size];    // temp array created to help with inversing the edges array so 
    int start = 0;              // values are in incrementing order
    int end = size-1;
    while (start < end){    // reverses edges array
        temp[start] = edges[start];
        edges[start] = edges[end];
        edges[end] = temp[start];
        start++;
        end--;
    }
}

bool check(int V[], int vNum, int val){
    for(int i = 0; i < vNum; i++){
        if(V[i] == val)
            return true;
    }
    return false;
}


// // This function saves arrays V and edges to be in their proper formatting and values
// void saveArrays(std::string edgesFile, std::string datesFile, int& vNum, std::string command
//     , struct Edge edges[], int V[]){
                    
//     // std::cout << "testing1" << std::endl; // Newline function to simply aid in formatting
//     saveVerticies(datesFile, V, command);
//     // std::cout << "testing2" << std::endl; // Newline function to simply aid in formatting
//     saveEdges(edgesFile, edges, V, vNum);
//     // std::cout << "testing3" << std::endl; // Newline function to simply aid in formatting
// }