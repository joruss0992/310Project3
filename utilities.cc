#include "utilities.h"

void newLine(){
    std::cout << std::endl; // Newline function to simply aid in formatting
}


// This function goes through every line of a given file and counts the number of lines incrementally
// This was mainly utilized in counting how many commands were inside the command file
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

// Function saves the commands from the command file into an array of strings
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

// This function aids in counting how many verticies will be in the graph
// ie how many years from the file are within the command parameters
void countVerticies(std::string datesFile, std::string command, int& count, int& year1, int& year2){
    std::ifstream fileStream;  // ifStream variable to read through the file
    fileStream.open(datesFile);  // Opens edges.txt file
    if(fileStream.fail()){    // Makes sure the file is acutally open
        std::cerr << "Error openning file, file not found: file 1" << std::endl;
        exit(1);
    }
    std::stringstream inputString(command);     // Initializing scanning variable
    std::string ye1 = "";     // string variables store the years from command
    std::string ye2 = "";
    std::getline(inputString, ye1, ' ');  
    std::getline(inputString, ye1, ' ');  // year's 1 and 2 saved from line
    std::getline(inputString, ye2);
    year1 = std::stoi(ye1);  // then converted to integers to allow comparing
    year2 = std::stoi(ye2);

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
        if(y > year2){      // If the current year is above year2, no further scanning is needed
            return;         // Helps reduce unnecissary scanning
        }
        if(y >= year1 && y <= year2){ // if the year given is between the years given from the command, it is counted
            count++;
        }
    }
}

// Function counts the number of edges where the both nodes are found inside of the array V
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
        std::getline(inputString, src, '\t'); 
        std::getline(inputString, dest);

        s = std::stoi(src); // Source and destination are converted to ints for comparison
        d = std::stoi(dest);

        for(int i = 0; i < vNum; i++){  // Scans through all of V

            if(V[i] == s){  // if the source is found to be inside of V, 
                for(int i = 0; i < vNum; i++){  // the destination is checked as well
                    if(V[i] == d)   // If the destination is found in V
                        count++;    // The number of edges is incremented
                }
            }
        }
    }
}