#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include "myStack.h"
#include "Parser.h"
#include "Solver.h"

class Calculator {
private:
    std::vector<double> rezultate;
    Parser parser;
    Solver solver;

public:
    Calculator();
    void afiseazaMeniu();
    void afiseazaSubmeniuCitireFisier();
    int getNumarLiniiFisier(const std::string& numeFisier);
    void introducereEcuatieTastatura();
    void citireEcuatiiFisier(const std::string& numeFisier);
    void salveazaRezultat();
    void incarcaVariabila();
    void afiseazaRezultateSalvate();
};