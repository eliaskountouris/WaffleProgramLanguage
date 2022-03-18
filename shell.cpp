#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <fstream>

#include "lexer.cpp"

using namespace std;

vector<Token> run(string &text)
{
    Lexer lxr = Lexer(text);
    vector<Token> tokens = lxr.makeTokens();
    return tokens;
}

int main()
{
    while(true)
    {
        string text = "";
        cout << "Waffles > ";
        cin >> text;
        vector<Token> tokens = run(text);
        for (int i = 0; i<tokens.size(); i++)
        {
            tokens.at(i).print();
        }
        cout << "\n";
    }

    return 0;
}