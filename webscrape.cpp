#include <iostream>                                                                                     // for cin cout
#include <string>                                                                                       // for string class
#include <fstream>                                                                                      // for file I/O
#include <curl/curl.h>                                                                                  // libcurl
using namespace std;                                                                                    // standard namespace
int main(){                                                                                             // main function
    int count = 0;                                                                                          // count of word
    string word;                                                                                            // word to search
    string website;                                                                                         // website to search
    string line;                                                                                            // line to read
    while (word != "exit" || website != "exit"){                                                            // main loop that runs until user enters "exit"
        cout << "\nTYPE \"exit\" ANYTIME TO EXIT";                                                              // note to user
        cout << "\n\n\nEnter a website: ";                                                                      // ask for website
        cin >> website;                                                                                         // get website
        string command = "curl -s https://www." + website + "/ > data.txt";                                     // attach the website to system command : create data.txt
        system(command.c_str());                                                                                // execute the command
        ifstream file("data.txt");                                                                              // open file
        while (getline(file, line)){                                                                            // read line by line
        cout << "\n\nEnter the word to be searched on " << website << ": ";                                     // ask for word
        cin >> word;                                                                                            // get word
        while(getline(file, line)){                                                                             // read line by line in file
            if(line.find(word) != string::npos){                                                                    // if word is found in line
                count++;                                                                                                // increment count
                line.erase(0, line.find(word));                                                                         // erase the line from the start of the word
                if(line.length() > 100){                                                                                // if line length is greater than 50
                    line.erase(100, line.length());}                                                                        // erase the line from 50th character
                cout << "\n" << count << " : " << line;}}                                                               // print the line
        cout << "\n\n\nThe word " << word << " has been spotted " << count << " times on " << website << "\n\n\n";} // print the result
        count = 0;}                                                                                                 // reset count to 0
return 0;}                                                                                               // end of main

