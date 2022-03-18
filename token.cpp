#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <unordered_map>

using namespace std;

#define TT_INT "INT"
#define TT_DOUB "DOUBLE"
#define TT_PLUS "PLUS"
#define TT_MINUS "MINUS"
#define TT_MUL "MUL"
#define TT_DIV "DIV"
#define TT_LPAREN "LPAREN"
#define TT_RPAREN "RPAREN"
#define TT_EOF "EOF"

const unordered_map <char, bool> DIGITS = {{'1',1},{'2',1},{'3',1},{'4',1},{'5',1},{'6',1},{'7',1},{'8',1},{'9',1},{'0',1},{'.',1}};

class Token
{
    public:
        typedef int DataType;
        string type;
        DataType value;
        bool hasValue;

        Token(string type_, DataType value_) 
        {
            (*this).type = type_;
            (*this).value = value_;
            (*this).hasValue = true;
        }
        Token(string type_) 
        {
            (*this).type = type_;
            (*this).hasValue = false;
        }

        void print() 
        {
            if ((*this).hasValue)
            {
                cout << (*this).type << " " << (*this).value << "\n";
            }
            else
            {
                cout << (*this).type << "\n";
            }
        }
};