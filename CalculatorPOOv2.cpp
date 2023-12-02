#include "Parser.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

int main()
{
    string input;
    string token;
    Parser p;

    cout << "Introduceti expresia: ";
    getline(cin, input);
    p.setInput(input);
    
    p.ParseazaEcuatie();

    istringstream iss(input);



    cout << p;
    return 0;
}

