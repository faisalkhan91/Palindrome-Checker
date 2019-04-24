#ifndef STATISTICS_INCLUDED
#define STATISTICS_INCLUDED

#include <iostream>
#include <fstream>

using namespace std;

class Statistics
{
private:
    int lines; // Total number of lines
    int total_palindromes; // Total palindromes
    int total_notpalindromes; // Total not palindromes
    int avg_char; // Average number of characters
    int short_palindrome = 0; // Character value for the shortest palindrome
    int long_palindrome = 0; // Character value for the longest palindrome
    string shortPalindrome; // Stores the shortest palindrome
    string longPalindrome; // Stores the longest palindrome

public:
    Statistics();  // Class constructor
    ~Statistics();  // Class destructor
    void printStats();
    // Function: Prints stats
    // Post: Print all the statistics of the file
    void avgChar(int charac);
    // Pre: Calculates the average
    // Post: Sets the total to avg characters
    void shortLongPal(int charac, string stringToCheck);
    // Function: Determines Shortest and longest palindrome
    // Pre: If variables are 0 then it sets the character value of the first palindrome
    // Post: Check to see if character value is smaller than smallest value store. Check to see if the character
    // value is the longest than the longest value stored. It true modifies the value.

    //Accessor Setters
    void setLines(int lines){this->lines=lines;};
    void setTotal_palindromes(int total_palindromes){this->total_palindromes=total_palindromes;};
    void setTotal_notpalindromes(int total_notpalindromes){this->total_notpalindromes=total_notpalindromes;};
    void setAvg_char(int avg_char){this->avg_char=avg_char;};
    void setShort_palindrome(int short_palindrome){this->short_palindrome=short_palindrome;};
    void setLong_palindrome(int long_palindrome){this->long_palindrome=long_palindrome;};
    void setShortPalindrome(string shortPalindrome){this->shortPalindrome=shortPalindrome;};
    void setLongPalindrome(string longPalindrome){this->longPalindrome=longPalindrome;};

    //Accessor Getters
    int getLines(){return lines;};
    int getTotal_palindromes(){return total_palindromes;};
    int getTotal_notpalindromes(){return total_notpalindromes;};
    int getAvg_char(){return avg_char;};
    int getShort_palindrome(){return short_palindrome;};
    int getLong_palindrome(){return long_palindrome;};
    string getShortPalindrome(){return shortPalindrome;};
    string getLongPalindrome(){return longPalindrome;};
};

#endif // STATISTICS_INCLUDED
