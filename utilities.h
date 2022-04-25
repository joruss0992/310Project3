#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <locale>

void newLine();

void countLines(std::string file, int& count);
void saveComm(std::string commands[], std::string file);
void countVerticies(std::string datesFile, std::string command, int& count, int& year1, int& year2);
void countEdges(std::string edgesFile, std::string command, int& count, int V[], int vNum);
std::string RemoveChar(std::string str, char c);