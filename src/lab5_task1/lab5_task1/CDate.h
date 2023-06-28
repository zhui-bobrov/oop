
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

enum class DateType
{
	DAY,
	MONTH,
	YEAR
};

const unsigned daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
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
	unsigned GetDate(DateType dateType) const;
};
