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
	void push(double valoare);
	double pop();
	bool faraElemente() const;
};

