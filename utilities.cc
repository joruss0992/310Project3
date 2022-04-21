#include "utilities.h"

void newLine(){
    std::cout << std::endl;
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
    std::string year1 = "";
    std::string year2 = "";
    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    std::getline(inputString, year1, ' '); // This may be a '\t' and not a ' ' 
    std::getline(inputString, year1, ' '); // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    std::getline(inputString, year2);
    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    y1 = std::stoi(year1);
    y2 = std::stoi(year2);

    count = 0;
    int n1 = 0;
    int y = 0;
    std::string line = "";   // Line will hold the value of each line in file
    while (getline(fileStream, line)){
        std::string node1 = "";
        std::string year = "";
        std::stringstream inputString(line);     // Initializing scanning variable
        std::getline(inputString, node1, '\t'); // may be a '\t' and not a ' '
        std::getline(inputString, year);
    // std::cout << "asdsadasdadadadad" << node1 << "----" << year << std::endl;

        n1 = std::stoi(node1);
        y = std::stoi(year);
    // std::cout << "asdsadasdadadadad" << std::endl;

        if(y >= y1 && y <= y2){
            count++;
        }
    }
}