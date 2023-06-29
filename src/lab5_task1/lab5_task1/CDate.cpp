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

WeekDay CDate::GetWeekDay() const
{
	return static_cast<WeekDay>((m_days + 4) % 7);
}

unsigned CDate::GetDay() const
{
	return std::get<0>(GetOperatingDate());
}

Month CDate::GetMonth() const
{
	return static_cast<Month>(std::get<1>(GetOperatingDate()));
}

unsigned CDate::GetYear() const
{
	return std::get<2>(GetOperatingDate());
}

bool CDate::IsValid() const
{
	return (m_days >= 0 && m_days <= 2932896);
}

unsigned CDate::GetDaysSinceEpoch(unsigned day, Month month, unsigned year) const
{
	unsigned daysCount = 0;

	for (unsigned i = static_cast<unsigned>(StartDate::YEAR); i < year; ++i)
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

std::tuple < unsigned, unsigned, unsigned> CDate::GetOperatingDate() const
{
	unsigned year = static_cast<unsigned>(StartDate::YEAR);
	unsigned month = static_cast<unsigned>(StartDate::MONTH);
	unsigned day = static_cast<unsigned>(StartDate::DAY) + m_days;

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

	return std::make_tuple(day, month, year);
}

bool CDate::IsLeapYear(unsigned year) const
{
	return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));
}

unsigned CDate::GetDaysInMonth(Month month, unsigned year) const
{
	return (month == Month::FEBRUARY && IsLeapYear(year)) ? daysInMonthMap.at(month) + 1 : daysInMonthMap.at(month);
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
	auto operatingDate = date.GetOperatingDate();
	stream << std::get<0>(operatingDate) << '.' << std::get<1>(operatingDate) << '.' << std::get<2>(operatingDate);
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