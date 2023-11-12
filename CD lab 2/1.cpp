#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <set>

using namespace std; // Added using namespace std to avoid std:: prefixes

int main() {
    // Open the input file for reading
    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cerr << "Error opening input file." << endl;
        return 1;
    }

    // Open the second file for reading
    ifstream secondFile("keywords.txt");
    if (!secondFile.is_open()) {
        cerr << "Error opening second file." << endl;
        return 1;
    }

    // Open the third file for reading
    ifstream thirdFile("operator.txt");
    if (!thirdFile.is_open()) {
        cerr << "Error opening third file." << endl;
        return 1;
    }

    // Create sets to store words from the second and third files
    set<string> wordSetSecond;
    set<string> wordSetThird;

    string line;

    // Read words from the second file and store them in the set
    while (getline(secondFile, line)) {
        istringstream iss(line);
        string word;
        while (iss >> word) {
            wordSetSecond.insert(word);
        }
    }

    // Read words from the third file and store them in the set
    while (getline(thirdFile, line)) {
        istringstream iss(line);
        string word;
        while (iss >> word) {
            wordSetThird.insert(word);
        }
    }

    // Read words from the input file and check if they exist in either set
    while (getline(inputFile, line)) {
        istringstream iss(line);
        string word;
        while (iss >> word) {
        
            if (wordSetSecond.find(word) != wordSetSecond.end()) {
                cout<<"keywords are: "<<endl;
                cout << word << endl;
            } 
            
            else if (wordSetThird.find(word) != wordSetThird.end()) {
                cout<<"operators are: "<<endl;
                cout  << word << endl;
            }
        }
    }

    inputFile.close();
    secondFile.close();
    thirdFile.close();

    return 0;
}
