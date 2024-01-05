#include "Parser.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cctype>

Parser::Parser(){}

Parser::Parser(const string& _input, const string& _output) : input(_input), output(_output) {
	if (input.empty()) {
		cerr << "Fara input. Inputul va fi setat cu valoarea default 0" << endl;
		input = "0";
	}
	if (output.empty()) {
		cerr << "Fara output. Ouputul va fi setat cu valoarea default 0" << endl;
		output = "0";
	}
	nrInputuri++;
}

void Parser::ParseazaEcuatie() {
	output.clear();
	string operatori;
	string nrCurent;
	bool areVirgula = false;
	bool virgulaErr = false;
	for (char c : input) {
		if (eNumar(c) || isspace(c)) {
			nrCurent += c;
		}
		else if (c == '.') {
			if (!nrCurent.empty() && areVirgula) {
				throw invalid_argument("Eroare: Termen cu prea multe virgule!");
			}
			if (!nrCurent.empty()) {
				nrCurent += c;
				areVirgula= true;
			}
		}
		else if (eOperator(c)) {
			if (!nrCurent.empty()) {
				output += nrCurent + ' ';
				nrCurent.clear();
				areVirgula = false;
			}
			procesareOp(c, operatori);
			output += ' ';
		}
		else if (c == '(' || c == '[') {
			operatori += c;
		}
		else if (c == ')') {
			if (!nrCurent.empty()) {
				output += nrCurent + ' ';
				nrCurent.clear();
			}
			procesareParantezaInchisaR(c, operatori);
			output += ' ';
		}
		else if (c == ']') {
			if (!nrCurent.empty()) {
				output += nrCurent + ' ';
				nrCurent.clear();
			}
			procesareParantezaInchisaP(c, operatori);
			output += ' ';
		}
	}
	if (!nrCurent.empty()) {
		output += nrCurent + ' ';
	}
	while (!operatori.empty()) {
		output += operatori.back();
		operatori.pop_back();
		output += ' ';
	}
	output = removePara(output);
}

void Parser::procesareOp(char c, string& operatori) {
	while (!operatori.empty() && operatori.back() != '(' && ordineOp(c) <= ordineOp(operatori.back())) {
		output += operatori.back();
		operatori.pop_back();
		output += ' ';
	}
	operatori += c;
}

void Parser::procesareParantezaInchisaR(char c, string& operatori) {
	while (!operatori.empty() && operatori.back() != '(') {
		output += operatori.back();
		operatori.pop_back();
		output += ' '; 
	}
	operatori.pop_back();
}

void Parser::procesareParantezaInchisaP(char c, string& operatori) {
	while (!operatori.empty() && operatori.back() != '[') {
		output += operatori.back();
		operatori.pop_back();
		output += ' '; 
	}
	operatori.pop_back();
}

string Parser::removePara(string& output) {
	string rez;
	for (int i = 0; i < output.size(); i++) {
		char crt = output[i];
		if (crt != '(' && crt != '[' && crt != ')' && crt != ']')
			rez += crt;
	}
	return rez;
}

int Parser::getNrInputuri() {
	return nrInputuri;
}

string Parser::getInput() const{
	return input;
}

void Parser::setInput(const string& _input) {
	input = _input;
	output.clear();
}

void Parser::setOutput(const string& _output) {
	output = _output;

}

string Parser::getOutput() const {
	return output;
}

istream& operator>>(istream& is, Parser& p) {
	is >> p.input;
	return is;
}

ostream& operator<<(ostream& os, Parser p) {
	os << p.output;
	return os;
}

bool Parser::eNumar(char c) {
	return (isdigit(c));
}

bool Parser::eOperator(char c) {
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '#');
}

int Parser::ordineOp(char op) {
	if (op == '+' || op == '-') {
		return 1;
	}
	else if (op == '*' || op == '/') {
		return 2;
	}
	else if (op == '^' || op == '#') {
		return 3;
	}
	return 0;
}
