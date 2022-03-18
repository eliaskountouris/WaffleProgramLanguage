#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <unordered_map>

using namespace std;

class Position
{
    public:
        int idx, ln, col;

        Position()
        {
            (*this).idx = 0;
            (*this).ln = 0;
            (*this).col = 0;
        }

        Position(int idx_, int ln_, int col_)
        {
            (*this).idx = idx_;
            (*this).ln = ln_;
            (*this).col = col_;
        }

        void advance(char current_char = '\0')
        {
            (*this).idx++;
            (*this).col++;

            if (current_char == '\n')
            {
                (*this).ln++;
                (*this).col = 0;
            }
        }
};