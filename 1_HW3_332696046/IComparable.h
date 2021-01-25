#pragma once
template<typename T>
class IComparable
{
public:
	virtual bool operator >  (T& op2) = 0;
	virtual bool operator <  (T& op2) = 0;
	virtual bool operator != (T& op2) = 0;
	virtual bool operator <= (T& op2) = 0;
	virtual bool operator >= (T& op2) = 0;
	virtual bool operator == (T& op2) = 0;		
	
};


