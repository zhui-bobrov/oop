#include <iostream>

#define CATCH_CONFIG_MAIN
#include "../../../catch/catch.hpp"
#include "../lab5_task1/CDate.h"

TEST_CASE("CDate 0 day")
{
	CDate date(0);
	CHECK(date.GetDay() == 1);
	CHECK(date.GetWeekDay() == WeekDay::THURSDAY);
	CHECK(date.GetMonth() == Month::JANUARY);
	CHECK(date.GetYear() == 1970);
	CHECK(date.IsValid());
}

TEST_CASE("CDate 1 day")
{
	CDate date(1);
	CHECK(date.GetDay() == 2);
	CHECK(date.GetWeekDay() == WeekDay::FRIDAY);
	CHECK(date.GetMonth() == Month::JANUARY);
	CHECK(date.GetYear() == 1970);
	CHECK(date.IsValid());
}

TEST_CASE("CDate 365 day")
{
	CDate date(365);
	CHECK(date.GetDay() == 1);
	CHECK(date.GetWeekDay() == WeekDay::FRIDAY);
	CHECK(date.GetMonth() == Month::JANUARY);
	CHECK(date.GetYear() == 1971);
	CHECK(date.IsValid());
}

TEST_CASE("CDate 2932896 day")
{
	CDate date(2932896);	
	CHECK(date.GetDay() == 31);
	CHECK(date.GetWeekDay() == WeekDay::FRIDAY);
	CHECK(date.GetMonth() == Month::DECEMBER);
	CHECK(date.GetYear() == 9999);
	CHECK(date.IsValid());
}

TEST_CASE("CDate 2932896+1 day")
{
	CDate date(2932896+1);

	CHECK(date.GetDay() == 1);
	CHECK(date.GetWeekDay() == WeekDay::SATURDAY);
	CHECK(date.GetMonth() == Month::JANUARY);
	CHECK(date.GetYear() == 10000);
	CHECK(!date.IsValid());
}

TEST_CASE("CDate 1/1/1970 day")
{
	CDate date(1, Month::JANUARY, 1970);
	CHECK(date.GetDay() == 1);
	CHECK(date.GetWeekDay() == WeekDay::THURSDAY);
	CHECK(date.GetMonth() == Month::JANUARY);
	CHECK(date.GetYear() == 1970);
	CHECK(date.IsValid());
}

TEST_CASE("CDate 2/1/1970 day")
{
	CDate date(2, Month::JANUARY, 1970);
	CHECK(date.GetDay() == 2);
	CHECK(date.GetWeekDay() == WeekDay::FRIDAY);
	CHECK(date.GetMonth() == Month::JANUARY);
	CHECK(date.GetYear() == 1970);
	CHECK(date.IsValid());
}

TEST_CASE("CDate 31/1/1970 day")
{
	CDate date(31, Month::JANUARY, 1970);
	CHECK(date.GetDay() == 31);
	CHECK(date.GetWeekDay() == WeekDay::SATURDAY);
	CHECK(date.GetMonth() == Month::JANUARY);
	CHECK(date.GetYear() == 1970);
	CHECK(date.IsValid());
}

TEST_CASE("CDate 31/1/1971 day")
{
	CDate date(31, Month::JANUARY, 1971);
	CHECK(date.GetDay() == 31);
	CHECK(date.GetWeekDay() == WeekDay::SUNDAY);
	CHECK(date.GetMonth() == Month::JANUARY);
	CHECK(date.GetYear() == 1971);
	CHECK(date.IsValid());
}

TEST_CASE("CDate 25/6/2023 day")
{
	CDate date(25, Month::JUNE, 2023);
	CHECK(date.GetDay() == 25);
	CHECK(date.GetWeekDay() == WeekDay::SUNDAY);
	CHECK(date.GetMonth() == Month::JUNE);
	CHECK(date.GetYear() == 2023);
	CHECK(date.IsValid());
}

TEST_CASE("CDate 31/12/9999 day")
{
	CDate date(31, Month::DECEMBER, 9999);
	CHECK(date.GetDay() == 31);
	CHECK(date.GetWeekDay() == WeekDay::FRIDAY);
	CHECK(date.GetMonth() == Month::DECEMBER);
	CHECK(date.GetYear() == 9999);
	CHECK(date.IsValid());
}

TEST_CASE("Operator ++/-- pre")
{
	CDate date(1, Month::JANUARY, 1970);
	date++;
	CHECK(date.GetDay() == 2);
	CHECK(date.GetWeekDay() == WeekDay::FRIDAY);
	CHECK(date.GetMonth() == Month::JANUARY);
	CHECK(date.GetYear() == 1970);
	CHECK(date.IsValid());

	date--;
	CHECK(date.GetDay() == 1);
	CHECK(date.GetWeekDay() == WeekDay::THURSDAY);
	CHECK(date.GetMonth() == Month::JANUARY);
	CHECK(date.GetYear() == 1970);
	CHECK(date.IsValid());
}

TEST_CASE("Operator ++/-- post")
{
	CDate date(1, Month::JANUARY, 1970);
	++date;
	CHECK(date.GetDay() == 2);
	CHECK(date.GetWeekDay() == WeekDay::FRIDAY);
	CHECK(date.GetMonth() == Month::JANUARY);
	CHECK(date.GetYear() == 1970);
	CHECK(date.IsValid());

	--date;
	CHECK(date.GetDay() == 1);
	CHECK(date.GetWeekDay() == WeekDay::THURSDAY);
	CHECK(date.GetMonth() == Month::JANUARY);
	CHECK(date.GetYear() == 1970);
	CHECK(date.IsValid());
}

TEST_CASE("Operator +/- day")
{
	CDate date(1, Month::JANUARY, 1970);
	date = date + 1;
	CHECK(date.GetDay() == 2);
	CHECK(date.GetWeekDay() == WeekDay::FRIDAY);
	CHECK(date.GetMonth() == Month::JANUARY);
	CHECK(date.GetYear() == 1970);
	CHECK(date.IsValid());

	date = date - 1;
	CHECK(date.GetDay() == 1);
	CHECK(date.GetWeekDay() == WeekDay::THURSDAY);
	CHECK(date.GetMonth() == Month::JANUARY);
	CHECK(date.GetYear() == 1970);
	CHECK(date.IsValid());
}

TEST_CASE("Operator  date - date")
{
	CDate date1(1, Month::JANUARY, 2000);
	CDate date2(3, Month::JANUARY, 2000);
	CHECK(date2 - date1 == 2);
}

TEST_CASE("Operator +=/-= day")
{
	CDate date(1, Month::JANUARY, 3000);
	date += 1;
	CHECK(date.GetDay() == 2);
	CHECK(date.GetWeekDay() == WeekDay::THURSDAY);
	CHECK(date.GetMonth() == Month::JANUARY);
	CHECK(date.GetYear() == 3000);
	CHECK(date.IsValid());

	date -= 1;
	CHECK(date.GetDay() == 1);
	CHECK(date.GetWeekDay() == WeekDay::WEDNESDAY);
	CHECK(date.GetMonth() == Month::JANUARY);
	CHECK(date.GetYear() == 3000);
	CHECK(date.IsValid());
}

TEST_CASE("Operator  date == date")
{
	CDate date1(1, Month::JANUARY, 1970);
	CDate date2(1, Month::JANUARY, 1970);
	CDate date3(2, Month::JANUARY, 1970);
	CHECK(date2 == date1);
	CHECK(!(date3 == date1));
}

TEST_CASE("Trest 365 day")
{
	CDate date1(365);
	CDate date2(1, Month::JANUARY, 1971);
	CHECK(date1 == date2);
}

TEST_CASE("Operator  date != date")
{
	CDate date1(1);
	CDate date2(2, Month::JANUARY, 1970);
	CDate date3(3, Month::JANUARY, 1970);
	CHECK(!(date2 != date1));
	CHECK(date3 != date1);
}

TEST_CASE("Operator  date > date")
{
	CDate date1(1);
	CDate date2(2, Month::JANUARY, 1970);
	CDate date3(3, Month::JANUARY, 1970);
	CHECK(!(date2 > date1));
	CHECK(!(date1 > date3));
	CHECK(date3 > date1);
}

TEST_CASE("Operator  date < date")
{
	CDate date1(1);
	CDate date2(2, Month::JANUARY, 1970);
	CDate date3(3, Month::JANUARY, 1970);
	CHECK(!(date2 < date1));
	CHECK(date1 < date3);
	CHECK(!(date3 < date1));
}

TEST_CASE("Operator  date <= date")
{
	CDate date1(1);
	CDate date2(2, Month::JANUARY, 1970);
	CDate date3(3, Month::JANUARY, 1970);
	CHECK(date2 <= date1);
	CHECK(date1 <= date3);
	CHECK(!(date3 <= date1));
}

TEST_CASE("Operator  date >= date")
{
	CDate date1(1);
	CDate date2(2, Month::JANUARY, 1970);
	CDate date3(3, Month::JANUARY, 1970);
	CHECK(date2 >= date1);
	CHECK(!(date1 >= date3));
	CHECK(date3 >= date1);
}

TEST_CASE("Operators << >> date")
{
	std::stringstream stream;
	unsigned day, month, year;
	char delimiter1, delimiter2;
	CDate date1(666);

	stream << date1;
	stream >> day >> delimiter1 >> month >> delimiter2 >> year;

	CHECK(date1.GetDay() == day);
	CHECK(date1.GetMonth() == static_cast<Month>(month));
	CHECK(date1.GetYear() == year);
}