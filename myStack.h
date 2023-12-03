#pragma once
#include <iostream>
#include <sstream>
#include <cmath>
#include <vector>

using namespace std;

class myStack
{
private:
	vector<double> stack;
public:
	myStack();

	const vector<double>& getStack() const;
	void setStack(const vector<double>& _Stack);

	void push(double valoare);
	double pop();
	bool faraElemente() const;
};

