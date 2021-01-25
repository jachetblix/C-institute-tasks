#pragma once
#include<iostream>
#include<string>
using namespace std;

template<typename T>
class Interval
{
public:
	Interval(T a, T b)
	{
		_a = a;
		_b = b;

		
	}
	Interval() 
	{
		_a                 = -1;
		_b                 = -1;
		_nValidationResult = -1;
	}
								    
	bool isEmpty()    
	{
		if ((this->_a == this->_b) && (this->_a == -1) && (_nValidationResult == -1))
		{
			_nValidationResult = 3;
			return true;
		}		
		return false; 
	}
	bool isBefore(Interval<T> other)
	{
		
		if ((this->_a <= this->_b) && (this->_b <= other._a) && (other._a <= other._b))
			return true;
		return false;

		if ((this->_a <=other._a) &&(other._a<=this->_b))
		{
			if (this->_b<other._b)
			{
				return false;
			}
		}
		return true;
	}
	bool isAfter(Interval<T> other)    
	{
		if ((this->_a >= other._a) && (other._a >= this->_b))
		{
			if (this->_b >= other._b)
			{
				return true;
			}
		}
		return false;
	}
	bool intersects(Interval<T> other)  
	{ 
		if ((this->_a < other._a) && (other._a < this->_b))
		{
			if (this->_b < other._b)
			{
				return true;
			}
		}
	
		if ((this->_a > other._a) && (other._b > this->_a))
		{
			if (this->_b > other._b)
			{
				return true;
			}
		}
		
		return false; 
	}
	

	bool contains(T c)
	{
		if ((_a < c) && (c < _b))
		{
			return true;
		}
		else
		
		return false;

	}
	Interval<T> operator&&(Interval<T> const &other)
	{
		Interval <T> c;
		if ((this->_a < other._a) &&(other._a < this->_b))
		{			
			c._a = other._a;
			c._b = this->_b;
		}
			
		if ((this->_a < other._b) && (other._b < this->_b))
			{
				c._a = this->_a;
				c._b = other._b;
			}
		return c;
	}

	Interval<T> operator||(Interval<T> const &other)
	{
		Interval <T> c;

		if ((this->_a < other._a) && (this->_a < this->_b) && (this->_b < other._a) && (other._a < other._b))
		{

			c._nValidationResult = 1;
			return c;
		}

		if ((other._a < this->_a) && (other._a < other._b) && (other._b <= this->_a) && (this->_a < this->_b))
		{

			c._nValidationResult = 1;
			return c;
		}

		

		if (this->_a > other._b)
		{
			
			c._nValidationResult = 1;
			return c;
		}


		if ((this->_a < other._a) && (other._a < this->_b))
		{
			c._a = this->_a;
			c._b = other._b;
			return c;
		}

		if ((this->_a > other._a) && (other._a < this->_b))
		{
			c._a = other._a;
			c._b = this->_b;
			return c;
		}
		if (!((this->_a > other._a) && (other._a < this->_b)))
		{
			c._a = other._a;
			c._b = this->_b;
			return c;
		}
		if (!((other._a < this->_a) && (this->_a < other._b)))
		{
			
			c._nValidationResult = 0;
			return c;
		}

		
		c._nValidationResult = 1;

		return c;
		
	}
	
	std::ostream &operator<<(std::ostream &out) const
	{
		return out;
	}

	
	friend ostream& operator<<(ostream& out, Interval<T> const& other)
	{		
		if ((((Interval<int> &)other).isEmpty()))
		{
			out << ((Interval<int> &)other).getProblem();
		}	
		else if (!(((Interval<int> &)other).isValid()))
		{
			out << ((Interval<int> &)other).getProblem();

		}				
		else
		{
			out << "(" << other._a << ", " << other._b << ")";
		}
		
		return out;
	}

	friend istream& operator>>(istream& xx, Interval<T>&)
	{
		return xx;
	}


	bool isValid() 
	{ 
		if ((_a >_b) || (_a == _b))
		{
			
			_nValidationResult = 1;
			return false;
		}
		
		return true; 
	}

	string  getProblem()
	{
		if (_nValidationResult == 3)
		{
			return "EMPTY";
		}
		if (_nValidationResult == 1)
		{
			return "Invalid interval";
		}
		return "";
		
	}

	

private:
	T      _a;
	T      _b;
	int _nValidationResult;
	
};

