#pragma once

#include<iostream>
#include "IComparable.h"
#include "IPrintable.h"
#include <string>
#include <iomanip>
using namespace std;

class Date : public IComparable<Date>, public IPrintable<Date>
{
public: 
	Date(int , int , int );
	
	void setMonth(int);
	void setDay  (int);
	void setYear (int);

	int  GetMonth();
	int  GetDay();
	int  GetYear();

		// IComparable
	virtual bool operator >  (Date& op2);
	virtual bool operator <  (Date& op2);
	virtual bool operator != (Date& op2);
	virtual bool operator <= (Date& op2);
	virtual bool operator >= (Date& op2);
	virtual bool operator == (Date& op2);
	const Date & operator=(const Date &);
	friend bool operator!=(const Date& first_date, const Date& second_date) 
	{ 
		if (!((first_date.m_nYear == second_date.m_nYear) &&
			(first_date.m_nDay == second_date.m_nDay) &&
			(first_date.m_nMonth == second_date.m_nMonth)))
				return 1; 
		
			return 0;
		
	}

	bool isValid()
	{
		
		if (m_nYear>2500 || m_nYear<1)
		{
			_sValidationResult = 0;
			return false;
		}
		if (m_nDay<0)
		{
			_sValidationResult = 1;
			return false;
		}
		if (m_nMonth <= 12 && m_nMonth >= 1)
		{
			if (m_nMonth == 4 || m_nMonth == 6 || m_nMonth == 9 || m_nMonth == 11)
				if ((m_nDay > 30) || (m_nDay < 1))
				{
					_sValidationResult = 3;
					return false;
				}
			if (m_nMonth == 1 || m_nMonth == 3 || m_nMonth == 5 || m_nMonth == 7 || m_nMonth == 10 || m_nMonth == 12)
			{
				if ((m_nDay > 31) || (m_nDay < 1))
				{
					_sValidationResult = 3;
					return false;
				}
			}
			if (m_nMonth == 2)
			{
				if (!(m_nYear % 4 == 0 && m_nYear % 100 != 0) || (m_nYear % 400 == 0))
				{
					_sValidationResult = 4;
					return false;
				}
				
			}
		}
		else
		{
			_sValidationResult = 2;
			return false;
		}
		
		return true;
	}
	
	string getProblem()
	{
		if (_sValidationResult ==0)
		{
			return "Illegal year";
		}
		if (_sValidationResult == 1)
		{
			return "Illegal day for month";
		}
		if (_sValidationResult == 2)
		{
			return "Illegal month" ;
		}
		if (_sValidationResult == 3)
		{
			return "Illegal day for month";
		}
		if (_sValidationResult == 4)
		{
			return "Not a leap year" ;
		}
		return "";		 
	}


	// IPrintable	
	virtual ostream& operator<<(ostream &out) const;	
	virtual istream& operator>>(istream &in);
	
	//ADDED
	friend ostream& operator<<(ostream& out,  Date& date)
	{
		if (!(date.isValid()))
		{
			
			out << date.getProblem();
		}
		else
		{
			cout << setw(2)<<date.m_nDay << "/" << setw(2)<<date.m_nMonth << "/" << date.m_nYear;
		}
		
		return out;
	}
	friend istream& operator>>(istream& is, Date& date)       
	{ 
		int temp_day;
		int temp_month;
		int temp_year;
		cin >> temp_day;
		cin.get();
		cin >> temp_month;
		cin.get();
		cin >> temp_year;
		cin.get();
		date.setMonth(temp_month);
		date.setDay(temp_day);
		date.setYear(temp_year);
	
   
    return is;
	}
		                               

private:
	int m_nMonth;
	int m_nDay;
	int m_nYear;	
	int _sValidationResult;
	
};

