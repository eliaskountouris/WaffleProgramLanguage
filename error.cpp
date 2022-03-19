#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <unordered_map>
#include <vector>

#include "position.cpp"

using namespace std;

#define INVALID_CHARECTER "Invalid Charecter Input"

class Error
{
    public:
        Position posStart;
        Position posEnd;
        string errorType;
        string details;

    Error(Position posStart_, Position posEnd_, const string errorType_, const string details_)
    {
        (*this).posStart = posStart_;
        (*this).posEnd = posEnd_;
        (*this).errorType = errorType_;
        (*this).details = details_;
    }
    
    void print()
    {
        string result = "Line: " + to_string((*this).posStart.ln + 1) + ", "; 
        result += (*this).errorType + ": " + (*this).details;
        cout << result;
    }
};

class InvalidCharecterError: public Error
{
    InvalidCharecterError(Position posStart_, Position posEnd_, string details_): Error(posStart_, posEnd_, "Invalid Syntax", details_)
    {
        
    }
};