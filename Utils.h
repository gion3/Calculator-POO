#pragma once
#include <iostream>

using namespace std;

class Utils
{public:
	virtual void scriereFisier() {
	};
	virtual void afisare() {
		cout << "Exemplu de virtualizare";
	}
};

