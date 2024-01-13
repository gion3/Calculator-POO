#include "Parser.h"
#include "Solver.h"
#include "myStack.h"
#include "Calculator.h"
#include "Utils.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cctype>
#include <iomanip>

using namespace std;

int Parser::nrInputuri = 0;

int main() {
    Calculator calculator;

    int optiune;
    do {
        calculator.afiseazaMeniu();
        std::cin >> optiune;
        std::cin.ignore();

        switch (optiune) {
        case 1:
            calculator.introducereEcuatieTastatura();
            break;
        case 2: {
            std::cout << "Introduceti numele fisierului: ";
            std::string numeFisier;
            std::getline(std::cin, numeFisier);
            calculator.citireEcuatiiFisier(numeFisier);
            break;
        }
        case 3:
            calculator.salveazaRezultat();
            break;
        case 4:
            calculator.incarcaVariabila();
            break;
        case 5:
            calculator.afiseazaRezultateSalvate();
            break;
        case 6:
            std::cout << "La revedere!\n";
            break;
        default:
            std::cerr << "Optiune invalida.\n";
        }
    } while (optiune != 6);

    return 0;
}