#pragma once
#include "myStack.h"
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

class Solver
{
public:
	Solver();
	double solve(const string& postfix);
	bool eTermen(const string& token);
	bool eOperator(const string& token);
	void procesareOp(const string& op, myStack& operatori);
};

