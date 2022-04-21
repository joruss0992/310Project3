#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <locale>

void newLine();

void countLines(std::string file, int& count);
void saveComm(std::string commands[], std::string file);
void countVerticies(std::string datesFile, std::string command, int& count);