#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

class Parser
{private:
	string input;
	string output;
public:
	Parser();
	Parser(const string& _input, const string& _output);

	string getInput() const;
	void setInput(const string& _input);

	void setOutput(const string& _output);

	void ParseazaEcuatie();
	bool eOperator(char c);
	int ordineOp(char op);

	friend istream& operator>>(istream&, Parser&);
	friend ostream& operator<<(ostream&, Parser);

	//~Parser();
};

