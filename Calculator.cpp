#include "Calculator.h"
#include <fstream>
#include <vector>
#include <iostream>

Calculator::Calculator() {
}

void Calculator::afiseazaMeniu() {
    std::cout << "\n===== Meniu =====\n";
    std::cout << "1. Introducere ecuatie de la tastatura\n";
    std::cout << "2. Citire ecuatii din fisier\n";
    std::cout << "3. Salveaza rezultatul curent\n";
    std::cout << "4. Incarca o variabila salvata\n";
    std::cout << "5. Afiseaza rezultatele salvate\n";
    std::cout << "6. Exit\n";
    std::cout << "Alege optiunea (1-6): ";
}

void Calculator::afiseazaSubmeniuCitireFisier() {
    std::cout << "\n===== Submeniu Citire Fisier =====\n";
    std::cout << "1. Scriere rezultate in consola\n";
    std::cout << "2. Scriere intr-un fisier text\n";
    std::cout << "3. Scriere intr-un fisier binar\n";
    std::cout << "Alege optiunea (1-3): ";
}

void Calculator::introducereEcuatieTastatura() {
    std::string input;
    std::cout << "Introduceti expresia: ";
    std::getline(std::cin, input);

    parser.setInput(input);
    parser.ParseazaEcuatie();

    double rezultat = solver.solve(parser.getOutput());

    rezultate.push_back(rezultat);

    std::cout << "Rezultat: " << std::fixed << std::setprecision(4) << rezultat << std::endl;
}

int Calculator::getNumarLiniiFisier(const std::string& numeFisier) {
    std::ifstream file(numeFisier);
    if (!file.is_open()) {
        std::cerr << "Nu s-a putut deschide fisierul: " << numeFisier << std::endl;
        return 0;
    }

    int numarLinii = 0;
    std::string line;
    while (std::getline(file, line)) {
        ++numarLinii;
    }

    file.close();
    return numarLinii;
}

void Calculator::citireEcuatiiFisier(const std::string& numeFisier) {
    afiseazaSubmeniuCitireFisier();
    int optiune;
    std::cin >> optiune;
    std::cin.ignore();  // Ignoră newline rămas în buffer

    if (optiune < 1 || optiune > 3) {
        std::cerr << "Optiune invalida pentru submeniu citire fisier.\n";
        return;
    }

    std::ifstream inputFile(numeFisier);
    if (!inputFile.is_open()) {
        std::cerr << "Nu s-a putut deschide fisierul: " << numeFisier << std::endl;
        return;
    }
    std::string numeFisierRezultate;
    std::ofstream outputFile(numeFisierRezultate);
    if (optiune == 2) {
        std::cout << "Introduceti numele fisierului pentru rezultate: ";
        std::getline(std::cin, numeFisierRezultate);

    }
        int numarLinii = getNumarLiniiFisier(numeFisier);
    for (int i = 1; i < numarLinii + 1; ++i) {
        std::string input;
        std::getline(inputFile, input);

        parser.setInput(input);
        parser.ParseazaEcuatie();
        double rezultat = solver.solve(parser.getOutput());

        rezultate.push_back(rezultat);

        if (optiune == 1) {
            std::cout << "Rezultat pentru expresia " << "[" << i << "]"<< " din fisier : " << std::fixed << std::setprecision(4) << rezultat << std::endl;
        }
        else if (optiune == 2) {
            outputFile << "Rezultat: " << std::fixed << std::setprecision(4) << rezultat << std::endl;
        }
        else if (optiune == 3) {
            // Implementează scrierea în fișierul binar
            std::ofstream binFile("rezultate.bin", std::ios::binary | std::ios::app);
            binFile.write(reinterpret_cast<char*>(&rezultat), sizeof(rezultat));
            binFile.close();
        }
    }

    inputFile.close();
    outputFile.close();
    if (optiune == 2) {
        std::cout << "Rezultatele au fost salvate in fisierul: " << numeFisierRezultate << std::endl;
    }
    else if (optiune == 3) {
        std::cout << "Rezultatele au fost salvate in fisierul binar. " << endl;
    }
}

void Calculator::salveazaRezultat() {
    if (rezultate.empty()) {
        std::cout << "Nu exista rezultate de salvat." << std::endl;
        return;
    }

    std::cout << "Rezultatele salvate: ";
    for (size_t i = 0; i < rezultate.size(); ++i) {
        std::cout << rezultate[i] << " ";
    }

    std::cout << "\nAlege indicele rezultatului pe care doresti sa il salvezi: ";
    size_t index;
    std::cin >> index;

    if (index < 1 || index > rezultate.size()) {
        std::cerr << "Indice invalid.\n";
        return;
    }

    std::string numeVariabila;
    std::cout << "Introduceti numele pentru variabila salvata: ";
    std::cin >> numeVariabila;

    // Implementează scrierea în fișierul text
    std::ofstream textFile("variabile.txt", std::ios::app);
    textFile << numeVariabila << " " << rezultate[index - 1] << std::endl;
    textFile.close();

    std::cout << "Rezultatul a fost salvat cu succes ca variabila '" << numeVariabila << "'.\n";
}

void Calculator::incarcaVariabila() {
    std::string numeVariabila;
    std::cout << "Introduceti numele variabilei pe care doriti sa o incarcati: ";
    std::cin >> numeVariabila;

    std::ifstream textFile("variabile.txt");
    if (!textFile.is_open()) {
        std::cerr << "Nu exista fisierul de variabile.\n";
        return;
    }

    std::string variabila;
    double valoare;

    while (textFile >> variabila >> valoare) {
        if (variabila == numeVariabila) {
            rezultate.push_back(valoare);
            std::cout << "Variabila '" << numeVariabila << "' incarcata cu succes.\n";
            textFile.close();
            return;
        }
    }

    std::cerr << "Variabila cu numele '" << numeVariabila << "' nu a fost gasita.\n";
    textFile.close();
}

void Calculator::afiseazaRezultateSalvate() {
    if (rezultate.empty()) {
        std::cout << "Nu exista rezultate salvate.\n";
        return;
    }

    std::cout << "Rezultatele salvate sunt: ";
    for (size_t i = 0; i < rezultate.size(); ++i) {
        std::cout << rezultate[i] << " ";
    }
    std::cout << std::endl;
}