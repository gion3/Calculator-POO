#include "myStack.h"


void myStack::push(double valoare) {
	stack.push_back(valoare);
}

double myStack::pop() {
	if (faraElemente()) {
		cerr << "Stack fara elemente" << endl;
		return 0.0;
	}
	double valoare = stack.back();
	stack.pop_back();
	return valoare;
}

bool myStack::faraElemente() const {
	return stack.empty();
}