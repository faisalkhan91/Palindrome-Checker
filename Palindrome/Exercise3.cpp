// Driver Program

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstring>
#include <cstdlib>

#include "tools.hpp"
#include "QueType.h"
#include "StackType.h"
#include "Statistics.hpp"

using namespace std;

bool isPalindrome(const string& stringToCheck, Statistics& pstat); // Palindrome checker function

int main()
{
    ifstream inFile;       // file containing operations
    ofstream outFile;      // file containing output
    ofstream outFile2;      // file containing output
    string inFileName /*= "palindrome-testfile.txt"*/;     // input file external name
    string outFileName = "palindromes.log";    // Log file 1 for storing the Palindromes
    string outFileName2 = "notpalindromes.log"; // Log file 2 for storing not Palindromes
    string outputLabel = "Palindromes";
    string outputLabel2 = "NotPalindromes";
    string palindrome;        // Line to be processed

    string option;
    Statistics stat;

    banner();

    do
    {
        // Prompt for file names, read file names, and prepare files
        cout << "Enter name of input command file; press return." << endl;
        cin  >> inFileName;
        inFile.open(inFileName.c_str());

        outFile.open(outFileName.c_str(), ios::out | ios::app);
        outFile2.open(outFileName2.c_str(), ios::out | ios::app);

        outFile << "\n[" << outputLabel << "]" << endl << endl;
        outFile2 << "\n[" << outputLabel2 << "]" << endl << endl;

        if (!inFile)
        {
            cout << "file not found" << endl;
            exit(2);
        }

        int count = 0;
        int pcount = 0;
        int npcount = 0;

        for(;;) // Infinite loop until end of file
        {
            getline(inFile, palindrome); // To get a single line form the file
            if (inFile.good()) // If the file is in good shape
            {
                if (isPalindrome(palindrome, stat) == true) // If the palindrome functions return true, i.e if the sentence is a palindrome
                {
                    outFile << palindrome << endl;
                    pcount++; // Counting number of lines that are palindromes
                }
                else // If the function returns false
                {
                    outFile2 << palindrome <<endl;
                    npcount++; // counting number of lines that are not palindromes
                }
            }
            else if(inFile.eof()) // To check for end of file
            {
                break; // Break out of loop
            }
            count ++; // counting number of lines processed
        }

        stat.setLines(count); // Storing lines
        stat.setTotal_palindromes(pcount); // Storing number of palindromes
        stat.setTotal_notpalindromes(npcount); // Storing number of not palindromes

        stat.printStats(); // Printing Statistics after processing the file

        inFile.close();
        cout<<"\n\nDo you want to check another file? [Y/N]" << endl; // To ask user if they want to enter another item
        getline(cin>>ws, option);

    }while(option == "Y" || option == "y" || option == "Yes" || option == "yes");

    // If the user selects to exit out of the program, close the files
    inFile.close();
    outFile.close();
    outFile2.close();

    bye();

    return 0;
}

bool isPalindrome(const string& stringToCheck, Statistics& pstat)
//Function: To check whether a sentence is a palindrome or not.
//Pre: Takes string as input and a class stat
//Post: Return true or false based on the processing
{
    bool palindrome = true;
    StackType stack;
    QueType queue;
    char stackChar;
    char queChar;
    locale loc;

    int charac = 0;

//    cout << "The String: " << stringToCheck << endl;

    for (const char& character : stringToCheck)
    {
//        cout << "One character: " << character << endl;
//        cout << "One character: " << tolower(character) << endl;

        charac++;
        // Converts charters to lowercase and skips characters other than alphabets.
        if (tolower(character) >= 97  && tolower(character) <= 122)
        {
            stack.Push(tolower(character,loc)); // Pushes to Stack
            queue.Enqueue(tolower(character,loc)); //Pushes to Queue
        }
    }

    pstat.avgChar(charac); // Calculates average
//    cout << "The String: " << stringToCheck << endl;
    pstat.shortLongPal(charac, stringToCheck); // function call to find the longest and the shortest palindrome

    // Validates the string as palindrome or not
    while (palindrome && !queue.IsEmpty())
    {
        stackChar = stack.Top();
        stack.Pop();
        queue.Dequeue(queChar);

        if (stackChar != queChar)
            palindrome = false;
    }
/*
    if (palindrome)
        cout << "String is a palindrome" << endl;
    else
        cout << "String is not a palindrome" << endl;
*/
    return palindrome;
}

