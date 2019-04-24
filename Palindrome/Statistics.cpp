#include "Statistics.hpp"

Statistics::Statistics()
{

}

Statistics::~Statistics()
{

}

void Statistics::printStats()
// Post: Prints all the statistics of the file
{
    int avg = getAvg_char()/getLines();

    cout << "\n\t The statistics for the file: " << endl << endl;
    cout << "Total number of lines processed: " << getLines() << endl;
    cout << "Total number of lines that were palindromes: " << getTotal_palindromes()<< endl;
    cout << "Total number of lines that were NOT palindromes: " << getTotal_notpalindromes() << endl;
    cout << "Average number of characters processed per line: " << avg << endl;
    cout << "Shortest palindrome found is: \n" << getShortPalindrome() << endl << "\nLength for the shortest palindrome is: " << getShort_palindrome() << endl <<endl;
    cout << "Longest palindrome found is: \n" << getLongPalindrome() << endl << "\nLength for the longest palindrome is: " << getLong_palindrome()<< endl <<endl;

    return;
}

void Statistics::avgChar(int charac)
// Pre: Sums total number of characters processed in the file
// Post: Sets the total to avg characters
{
    int total = getAvg_char() + charac;
    setAvg_char(total);
}

void Statistics::shortLongPal(int charac, string stringToCheck)
// Pre: If variables are 0 then it sets the character value of the first palindrome
// Post: Check to see if character value is smaller than smallest value store. Check to see if the character
// value is the longest than the longest value stored. It true modifies the value.
{
    if (getShort_palindrome() == 0 && getLong_palindrome() == 0)
    {
        setShort_palindrome(charac);
        setLong_palindrome(charac);
    }
    else if(charac < getShort_palindrome())
    {
        setShort_palindrome(charac);
        setShortPalindrome(stringToCheck);
    }
    else if (charac > getLong_palindrome())
    {
        setLong_palindrome(charac);
        setLongPalindrome(stringToCheck);
    }
}
