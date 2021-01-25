#pragma once

#include <iostream>
#include <fstream>

using namespace std;

template<typename T>
class IPrintable
{
	
public:
	virtual ostream& operator<<(ostream &out) const = 0;
	virtual istream& operator>>(istream &in) { return in; }
};

