#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	std::ifstream dt("data.csv");
	if (!dt)
	   throw BitcoinExchangeException("Cannot open database.");

	std::string line;
	std::getline(dt, line);
	bool empty = true;
	while (std::getline(dt, line))
	{
		empty = false;
		std::string::size_type pos = line.find(',');
		if (pos == std::string::npos)
			continue;
		std::string date = line.substr(0, pos);
		float value = std::atof(line.substr(pos + 1).c_str());
		this->dataBase.insert(std::make_pair(date, value));
	}
	dt.close();
	if (empty)
		throw BitcoinExchangeException("Empty data base.");
}

BitcoinExchange::BitcoinExchangeException::BitcoinExchangeException(const std::string& message) : _message(message) {}

const char* BitcoinExchange::BitcoinExchangeException::what() const throw(){
	return _message.c_str();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy){
	*this = copy;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& copy) {
	if (this != &copy) {
		dataBase.clear();
		std::map<std::string, float>::const_iterator i;
		for (i = copy.dataBase.begin(); i != copy.dataBase.end(); ++i) {
			this->dataBase.insert(std::make_pair(i->first, i->second));
		}
	}
	return *this;
}

bool	leapYear(int year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool	validYear(int year) {
	return year >= 2009 && year <= 2024;
}

bool	validMonth(int month) {
	return month >= 1 && month <= 12;
}

bool	validDay(int year, int month, int day) {
	if (day < 1 || day > 31)
		return false;
	if (month == 2)
	{
		if (leapYear(year))
			return day <= 29;
		else
			return day <= 28;
	} 
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		return day <= 30;
	return true;
}

bool	validDate(const std::string& date) {
	std::istringstream ss(date);
	int year, month, day;
	char dash1, dash2;

	if (!(ss >> year >> dash1 >> month >> dash2 >> day))
		return false;
	if (dash1 != '-' || dash2 != '-')
		return false;
	return validYear(year) && validMonth(month) && validDay(year, month, day);
}

void	BitcoinExchange::validValue(const std::string& value_str) {
	std::stringstream ss(value_str);
	float	value;
	
	if (!(ss >> value) || !ss.eof())
		throw BitcoinExchangeException("Invalid number.");
	if (value < 0)
		throw BitcoinExchangeException("Is not a positive number.");
	if (value > 1000)
		throw BitcoinExchangeException("Too large number.");
}

std::string BitcoinExchange::getClosestDate(const std::string& target_date) const {
	std::string closest_date = "";
	std::map<std::string, float>::const_iterator it = dataBase.lower_bound(target_date);

	if (it == dataBase.end()) {
		if (!dataBase.empty()) {
			--it;
			closest_date = it->first;
		}
		else
			throw BitcoinExchangeException("No valid date found.");
	} else if (it->first != target_date && it != dataBase.begin()) {
		--it;
		closest_date = it->first;
	} else {
		closest_date = it->first;
	}
	return closest_date;
}

bool	all_of(const std::string::const_iterator& begin, const std::string::const_iterator& end, bool (*predicate)(int)) {
	for (std::string::const_iterator it = begin; it != end; ++it) {
		if (!predicate(static_cast<unsigned char>(*it))) {
			return false;
		}
	}
	return true;
}

bool	is_space(int c) {
	return std::isspace(c);
}

void	BitcoinExchange::processLine(const std::string& line) {
	std::string date, value_str;
	std::istringstream ss(line);

	if (line.empty() || all_of(line.begin(), line.end(), is_space))
		return ;
	if (!std::getline(ss, date, '|') || !std::getline(ss, value_str, '|')) {
		std::cout << "Error: bad input => " << line << std::endl;
		return ;
	}
	try {
		size_t start = date.find_first_not_of(" ");
		size_t end = date.find_last_not_of(" ");
		date = date.substr(start, end - start + 1);
		start = value_str.find_first_not_of(" ");
		end = value_str.find_last_not_of(" ");
		value_str = value_str.substr(start, end - start + 1);

		if (!validDate(date))
			throw BitcoinExchangeException("Invalid date format or out of range.");
		validValue(value_str);
		float value = std::atof(value_str.c_str());
		std::string closest_date = getClosestDate(date);
		float btc_price = dataBase.find(closest_date)->second;
		float result = value * btc_price;
		std::cout << date << " => " << value << " = " << std::fixed << std::setprecision(2) << result << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}

void BitcoinExchange::handleInput(const std::string& filename) {
	std::ifstream file(filename.c_str());
	std::string line;

	if (!file)
		throw BitcoinExchangeException("Could not open file.");
	if (!std::getline(file, line) || line != "date | value")
		throw BitcoinExchangeException("Invalid format first line of file.");
	while (std::getline(file, line))
		processLine(line);
}

void	BitcoinExchange::printDataBase() const {
	std::map<std::string, float>::const_iterator i;
	for (i = dataBase.begin(); i != dataBase.end(); ++i) {
		std::cout << i->first << " => " << i->second << std::endl;
	}
}

BitcoinExchange::~BitcoinExchange()
{
	if (!dataBase.empty())
		dataBase.clear();
}