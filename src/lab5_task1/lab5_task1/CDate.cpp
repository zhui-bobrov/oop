#include "stdafx.h"
#include "CDate.h"

CDate::CDate(unsigned day, Month month, unsigned year)
	: m_days(GetDaysSinceEpoch(day, month, year))
{
}

CDate::CDate(unsigned dayCount)
	: m_days(dayCount)
{
}

unsigned CDate::GetDay() const
{
	return GetDate(DateType::DAY);
}

WeekDay CDate::GetWeekDay() const
{
	return static_cast<WeekDay>((m_days + 4) % 7);
}

Month CDate::GetMonth() const
{
	return static_cast<Month>(GetDate(DateType::MONTH));
}

unsigned CDate::GetYear() const
{
	return GetDate(DateType::YEAR);
}

bool CDate::IsValid() const
{
	return (m_days >= 0 && m_days <= 2932896);
}

unsigned CDate::GetDaysSinceEpoch(unsigned day, Month month, unsigned year) const
{
	unsigned daysCount = 0;

	for (unsigned i = 1970; i < year; ++i)
	{
		daysCount += IsLeapYear(i) ? 366 : 365;
	}

	for (unsigned i = 1; i < static_cast<unsigned>(month); ++i)
	{
		daysCount += GetDaysInMonth(static_cast<Month>(i), year);
	}

	daysCount += day - 1;

	return daysCount;
}

unsigned CDate::GetDate(DateType dateType) const
{
	unsigned year = 1970;
	unsigned month = 1;
	unsigned day = 1 + m_days;

	while (day > GetDaysInMonth(static_cast<Month>(month), year))
	{
		day -= GetDaysInMonth(static_cast<Month>(month), year);
		month++;
		if (month > 12)
		{
			month = 1;
			year++;
		}
	}

	switch (dateType)
	{
	case DateType::DAY:
		return day;
	case DateType::MONTH:
		return month;
	case DateType::YEAR:
		return year;
	}
}

bool CDate::IsLeapYear(unsigned year) const
{
	return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));
}

unsigned CDate::GetDaysInMonth(Month month, unsigned year) const
{
	unsigned monthNum = static_cast<unsigned>(month);

	return (monthNum == static_cast<unsigned>(Month::FEBRUARY) && IsLeapYear(year)) ? daysInMonth[monthNum] + 1 : daysInMonth[monthNum];
}

CDate& CDate::operator++()
{
	++m_days;
	return *this;
}

CDate CDate::operator++(int)
{
	CDate tmpCopy(*this);
	++(*this);
	return tmpCopy;
}

CDate& CDate::operator--()
{
	--m_days;
	return *this;
}

CDate CDate::operator--(int)
{
	CDate tmpCopy(*this);
	--(*this);
	return tmpCopy;
}

CDate CDate::operator+(unsigned days) const
{
	return CDate(m_days + days);
}

CDate CDate::operator-(unsigned days) const
{
	return CDate(m_days - days);
}

int CDate::operator-(const CDate& date2) const
{
	return m_days - date2.m_days;
}

CDate& CDate::operator+=(unsigned days)
{
	m_days += days;
	return *this;
}

CDate& CDate::operator-=(unsigned days)
{
	m_days -= days;
	return *this;
}

bool CDate::operator==(const CDate& date2) const
{
	return m_days == date2.m_days;
}

bool CDate::operator!=(const CDate& date2) const
{
	return m_days != date2.m_days;
}

bool CDate::operator<(const CDate& date2) const
{
	return m_days < date2.m_days;
}

bool CDate::operator>(const CDate& date2) const
{
	return m_days > date2.m_days;
}

bool CDate::operator<=(const CDate& date2) const
{
	return m_days <= date2.m_days;
}

bool CDate::operator>=(const CDate& date2) const
{
	return m_days >= date2.m_days;
}

std::ostream& operator<<(std::ostream& stream, const CDate& date)
{
	stream << date.GetDay() << '.' << static_cast<int>(date.GetMonth()) << '.' << date.GetYear();
	return stream;
}

std::istream& operator>>(std::istream& stream, CDate& date)
{
	unsigned day, month, year;
	char delimiter1, delimiter2;

	stream >> day >> delimiter1 >> month >> delimiter2 >> year;

	if (isdigit(day) && isdigit(month) && isdigit(year))
	{
		date = CDate(day, static_cast<Month>(month), year);
	}
	else
	{
		stream.setstate(std::ios_base::failbit | stream.rdstate());
	}

	return stream;
}