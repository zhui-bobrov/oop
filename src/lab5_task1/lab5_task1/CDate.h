enum class Month
{
	JANUARY = 1,
	FEBRUARY,
	MARCH,
	APRIL,
	MAY,
	JUNE,
	JULY,
	AUGUST,
	SEPTEMBER,
	OCTOBER,
	NOVEMBER,
	DECEMBER
};

enum class WeekDay
{
	SUNDAY = 0,
	MONDAY,
	TUESDAY,
	WEDNESDAY,
	THURSDAY,
	FRIDAY,
	SATURDAY
};

const std::map<Month, unsigned> daysInMonthMap = {
	{ Month::JANUARY, 31 },
	{ Month::FEBRUARY, 28 },
	{ Month::MARCH, 31 },
	{ Month::APRIL, 30 },
	{ Month::MAY, 31 },
	{ Month::JUNE, 30 },
	{ Month::JULY, 31 },
	{ Month::AUGUST, 31 },
	{ Month::SEPTEMBER, 30 },
	{ Month::OCTOBER, 31 },
	{ Month::NOVEMBER, 30 },
	{ Month::DECEMBER, 31 }
};

enum class StartDate { DAY = 1,	MONTH = 1, YEAR = 1970 };

enum class DateType
{
	DAY,
	MONTH,
	YEAR
};

const std::vector<char> validDelimiters = { '.', '/', '-' };

class CDate
{
public:
	CDate(unsigned day, Month month, unsigned year);
	CDate(unsigned dayCount = 0);

	unsigned GetDay() const;
	WeekDay GetWeekDay() const;
	Month GetMonth() const;
	unsigned GetYear() const;
	bool IsValid() const;

	CDate& operator++();
	CDate operator++(int);
	CDate& operator--();
	CDate operator--(int);
	CDate operator+(unsigned days) const;
	CDate operator-(unsigned days) const;
	int operator-(const CDate& date2) const;
	CDate& operator+=(unsigned days);
	CDate& operator-=(unsigned days);

	bool operator==(const CDate& date2) const;
	bool operator!=(const CDate& date2) const;
	bool operator<(const CDate& date2) const;
	bool operator>(const CDate& date2) const;
	bool operator<=(const CDate& date2) const;
	bool operator>=(const CDate& date2) const;

	friend std::ostream& operator<<(std::ostream& stream, const CDate& date);
	friend std::istream& operator>>(std::istream& stream, CDate& date);

private:
	unsigned m_days;

	bool IsLeapYear(unsigned year) const;
	unsigned GetDaysSinceEpoch(unsigned day, Month month, unsigned year) const;
	unsigned GetDaysInMonth(Month month, unsigned year) const;
	std::tuple<unsigned, unsigned, unsigned> GetOperatingDate() const;
};
