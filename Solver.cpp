#include "Solver.h"

Solver::Solver(){}

double Solver::solve(const string& postfix) {
	myStack operatori;
	istringstream iss(postfix);
	string token;

	while (iss >> token) {
		if (eTermen(token)) {
			operatori.push(stod(token));
		}
		else {
			if (eOperator(token)) {
				procesareOp(token, operatori);
			}
			else {
				cerr << "Token invalid: " << token << endl;
				return 0.0;
			}
		}
	}
	if (!operatori.faraElemente()) {
		return operatori.pop();
	}
	else {
		cerr << "Expresie invalida" << endl;
		return 0.0;
	}
}

bool Solver::eTermen(const string& token) {
	return (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1])));
}

bool Solver::eOperator(const string& token) {
	return (token == "+" || token == "-" || token == "*" || token == "/" || token == "^" || token == "#");
}

void Solver::procesareOp(const string& op, myStack& termeni) {
	if (termeni.faraElemente()) {
		cerr << "Termeni insuficienti pentru operatorul: " << op << endl;
		return;
	}
	double termen2 = termeni.pop();
	if (termeni.faraElemente()) {
		cerr << "Termeni insuficienti pentru operatorul: " << op << endl;
		return;
	}
	double termen1 = termeni.pop();

	if (op == "+") {
		termeni.push(termen1 + termen2);
	}
	else if (op == "-") {
		termeni.push(termen1 - termen2);
	}
	else if (op == "*") {
		termeni.push(termen1 * termen2);
	}
	else if (op == "/") {
		if (termen2 == 0) {
			cerr << "Impartire la 0" << endl;
			return;
		}
		termeni.push(termen1 / termen2);
	}
	else if (op == "^") {
		termeni.push(pow(termen1, termen2));
	}
	else if (op == "#") {
		termeni.push(pow(termen1, 1.0 / termen2));
	}
}
