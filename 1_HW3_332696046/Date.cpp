#include "Date.h"


Date::Date(int nDay, int nMonth, int nYear)
{

	if (nDay > 0 && nDay < 32 && nMonth>0 && nMonth < 13) 
	{

		m_nMonth = nMonth;
		m_nDay = nDay;
		m_nYear = nYear;
	}
	

}

void Date::setMonth(int month)
{
	m_nMonth = month;
}

void Date::setDay(int day)
{
	m_nDay = day;
}

void Date::setYear(int year)
{
	m_nYear = year;
}

int Date::GetMonth()
{
	return m_nMonth;
}

int Date::GetDay()
{
	return m_nDay;
}

int Date::GetYear()
{
	return m_nYear;
}


bool Date::operator>(Date & op2)
{
	return false;
}

bool Date::operator<(Date & op2)
{
	return false;
}

bool Date::operator!=(Date & op2)
{
	return false;
}

bool Date::operator<=(Date & other)
{
	if (this->m_nYear < other.m_nYear)
		return true;
	else if (this->m_nYear > other.m_nYear)
		return false;
	else
	{
		if (this->m_nMonth < other.m_nMonth)
			return false;
		else if (this->m_nMonth > other.m_nMonth)
			return false;
		else
		{
			if (this->m_nDay < other.m_nDay)
				return false;
			else if (this->m_nDay > other.m_nDay)
				return false;
		}
	}
		
	return true;		
}

bool Date::operator>=(Date & op2)
{
	return false;
}

bool Date::operator==(Date & op2)
{
	return false;
}

const Date & Date::operator=(const Date &right)
{
	this->m_nMonth = right.m_nMonth;
	this->m_nDay   = right.m_nDay;
	this->m_nYear  = right.m_nYear;
	
	return *this;
}

ostream & Date::operator<<(ostream & out) const
{	
	out << m_nMonth << "/" << m_nDay << "/" << m_nYear <<"/" << endl;
	return out;
}

istream & Date::operator>>(istream & in)// const
{	
	
	in >> m_nDay >> m_nMonth >> m_nYear;	
	return in;
}



