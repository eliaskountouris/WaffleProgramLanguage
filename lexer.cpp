#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <unordered_map>
#include <vector>

#include "token.cpp"
#include "error.cpp"

using namespace std;

class Lexer
{
  public:
    string text;
    char current_char;
    Position pos;
    
    Lexer(string text_)
    {   
        (*this).text = text_;
        (*this).current_char = '\0';
        (*this).pos = Position(-1,0,-1);
        advance();
    }  

    void advance()
    {
        (*this).pos.advance((*this).current_char);
        if ((*this).pos.idx < (*this).text.length())
        {
            (*this).current_char = (*this).text[(*this).pos.idx];
        }
        else
        {
            (*this).current_char = '\0';    
        }
    }

    vector<Token> makeTokens(vector<Error>& errorReturn)
    {
        vector<Token> ret;

        while ((*this).current_char != '\0')
        {
            if ((*this).current_char == ' ' || (*this).current_char == '\t' || (*this).current_char == '\n')
            {
                advance();
            }
            else if(DIGITS.count((*this).current_char))
            {
               ret.push_back(makeNumber());

            }
            else
            {
                string s = "";
                s+= current_char;
                errorReturn.push_back(Error((*this).pos, (*this).pos, INVALID_CHARECTER, s));
                advance();
            }
        }

        return ret;
    }

    Token makeNumber()
    {
        string num = "";
        int dot = 0;
        
        while(DIGITS.count((*this).current_char))
        {
            if ((*this).current_char == '.')
            {
                if (dot == 0)
                {
                    dot++;
                    num += '.';
                }
                else
                {
                    break;
                }
            }
            else
            {
                num += (*this).current_char;
            }
            advance();
        }

        if (dot == 0)
        {
            return Token(TT_INT, stoi(num));
        }
        else
        {
            return Token(TT_DOUB, stod(num));
        }
    }
    
};

