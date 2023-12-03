#include "Parser.h"
#include "Solver.h"
#include "myStack.h"
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
    Solver s;
    double rezultat;

    cout << "Introduceti expresia: ";
    getline(cin, input);
    p.setInput(input);
    
    p.ParseazaEcuatie();

    rezultat = s.solve(p.getOutput());

    cout << rezultat << endl;
    //cout << p;
    return 0;
}

