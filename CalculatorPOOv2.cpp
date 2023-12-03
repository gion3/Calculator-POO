#include "Parser.h"
#include "Solver.h"
#include "myStack.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <iomanip>

using namespace std;

int Parser::nrInputuri = 0;

int main()
{
    string input;
    string exitstr = "exit";
    Parser p;
    Solver s;
    double rezultat;

    do {
        cout << endl << "Introduceti expresia: "<< endl;

        getline(cin, input);
        p.setInput(input);

        p.ParseazaEcuatie();

        rezultat = s.solve(p.getOutput());

        if (rezultat == trunc(rezultat) || rezultat == ( -1 * trunc(rezultat))) {
            cout << endl << "Rezultat: " << rezultat << endl;
        }
        else {
            cout << endl << "Rezultat: " << fixed << setprecision(4) << rezultat << endl;
        }
    } while (p.getInput() != exitstr);

    return 0;
}

