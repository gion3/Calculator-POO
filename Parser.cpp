#include "Parser.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cctype>

Parser::Parser(){}

Parser::Parser(const string& _input, const string& _output) : input(_input), output(_output) {

}

void Parser::ParseazaEcuatie() {
	output.clear();
	string operatori;
	for (char c : input) {
		if (isdigit(c) || isspace(c)) {
			output += c;
		}
		else if (eOperator(c)) {
			while (!operatori.empty() && operatori.back() != '(' && ordineOp(c) <= ordineOp(operatori.back())) {
				output += operatori.back();
				operatori.pop_back();
			}
			operatori += c;
		}
		else if (c == '(' || c == '[') {
			operatori += c;
		}
		else if (c == ')' || c == ']') {
			char okParanteze;
			if (c == ')') {
				okParanteze = '(';
			}
			else if (c == ']') {
				okParanteze = '[';
			}
			while (!operatori.empty() && operatori.back() != okParanteze) {
				output += operatori.back();
				operatori.pop_back();
			}
			operatori.pop_back();
		}
	}
	while (!operatori.empty()) {
		output += operatori.back();
		operatori.pop_back();
	}
}

string Parser::getInput() const{
	return input;
}

void Parser::setInput(const string& _input) {
	input = _input;

}

void Parser::setOutput(const string& _output) {
	output = _output;

}


ostream& operator<<(ostream& os, Parser p) {
	os << p.output;
	return os;
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
