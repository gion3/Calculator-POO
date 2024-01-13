#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include "myStack.h"
#include "Parser.h"
#include "Solver.h"
#include "Utils.h"

class Calculator : public Utils {
private:
    std::vector<double> rezultate;
    Parser parser;
    Solver solver;

public:
    Calculator();
    void afisare();
    void scriereFisier(double rez,const string nume,const int nrEc);
    void afiseazaMeniu();
    void afiseazaSubmeniuCitireFisier();
    int getNumarLiniiFisier(const std::string& numeFisier);
    void introducereEcuatieTastatura();
    void citireEcuatiiFisier(const std::string& numeFisier);
    void salveazaRezultat();
    void incarcaVariabila();
    void afiseazaRezultateSalvate();
};