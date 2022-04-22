#include "utilities.h"

void newLine(){
    std::cout << std::endl; // Newline function to simply aid in formatting
}


// This function goes through every line of a given file and counts the number of lines incrementally
void countLines(std::string file, int& count){
    std::ifstream fileStream;  // ifStream variable to read through the file
    fileStream.open(file);  // Opens given txt file
    if(fileStream.fail()){    // Makes sure the file is acutally open
        std::cerr << "Error openning file, file not found: file 1" << std::endl;
        exit(1);
    }

    std::string line = "";   // Line will hold the value of each line in file
    count = 0;
    while (getline(fileStream, line)){
        count++;    // For every line, count++
    }
}

void saveComm(std::string commands[], std::string file){
    std::ifstream fileStream;  // ifStream variable to read through the file
    fileStream.open(file);  // Opens commands.txt file
    if(fileStream.fail()){    // Makes sure the file is acutally open
        std::cerr << "Error openning file, file not found: file 1" << std::endl;
        exit(1);
    }

    std::string line = "";   // Line will hold the value of each line in file
    int current = 0;  // Keep track of the current line
    while (getline(fileStream, line)){
        commands[current] = line;   // Current line's command is saved to the array
        current++;
    }
}


void countVerticies(std::string datesFile, std::string command, int& count){

    int y1 = 0;
    int y2 = 0;
    std::ifstream fileStream;  // ifStream variable to read through the file
    fileStream.open(datesFile);  // Opens edges.txt file
    if(fileStream.fail()){    // Makes sure the file is acutally open
        std::cerr << "Error openning file, file not found: file 1" << std::endl;
        exit(1);
    }
    std::stringstream inputString(command);     // Initializing scanning variable
    std::string year1 = "";     // string variables store the years from command
    std::string year2 = "";
    std::getline(inputString, year1, ' ');  
    std::getline(inputString, year1, ' ');  // year's 1 and 2 saved from line
    std::getline(inputString, year2);
    y1 = std::stoi(year1);  // then converted to integers to allow comparing
    y2 = std::stoi(year2);

    count = 0;
    int n1 = 0;
    int y = 0;
    std::string line = "";   // Line will hold the value of each line in file
    while (getline(fileStream, line)){  // scans line by line and ensures verticies within years given are counted
        std::string node1 = "";
        std::string year = "";
        std::stringstream inputString(line);     // Initializing scanning variable
        std::getline(inputString, node1, '\t'); // may be a '\t' and not a ' '
        std::getline(inputString, year);

        y = std::stoi(year);
        if(y >= y1 && y <= y2){ // if the year given is between the years given from the command, it is counted
            count++;
        }
    }
}

void countEdges(std::string edgesFile, std::string command, int& count, int V[], int vNum){

    std::ifstream fileStream;  // ifStream variable to read through the file
    fileStream.open(edgesFile);  // Opens edges.txt file
    if(fileStream.fail()){    // Makes sure the file is acutally open
        std::cerr << "Error openning file, file not found: file 1" << std::endl;
        exit(1);
    }

    count = 0;
    int s = 0;
    int d = 0;
    std::string line = "";   // Line will hold the value of each line in file
    while (getline(fileStream, line)){  // scans line by line and ensures verticies within years given are counted
        std::string src = "";
        std::string dest = "";
        std::stringstream inputString(line);     // Initializing scanning variable
        std::getline(inputString, src, '\t'); // may be a '\t' and not a ' '
        std::getline(inputString, dest);

        s = std::stoi(src);
        d = std::stoi(dest);
        // std::cout << s << std::endl;
        for(int i = 0; i < vNum; i++){
            // std::cout << s << std::endl;
            // std::cout << V[i] << std::endl;
            if(V[i] == s){
                for(int i = 0; i < vNum; i++){
                    if(V[i] == d)
                        count++;
                }
            }
        }
    }
}