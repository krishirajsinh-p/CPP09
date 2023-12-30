/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 23:51:05 by kpuwar            #+#    #+#             */
/*   Updated: 2023/12/30 06:32:26 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	*this = src;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
	(void)rhs;
	return *this;
}

static map<string, float> getDatabase()
{
	map<string, float> csvData;
	std::ifstream file("data.csv");

	if (!file.is_open())
	{
		cout << "Error: could not open file." << endl;
		return csvData;
	}

	string line;
	std::getline(file, line);
	if (line != "date,exchange_rate")
	{
		cout << "Error: improper heading." << endl;
		file.close();
		return csvData;
	}

	while (std::getline(file, line))
	{
		std::istringstream iss(line);
		string date;
		float rate;

		std::getline(iss, date, ',') >> rate;

		csvData[date] = rate;
	}

	file.close();
	return csvData;
}

static bool checkDate(const string &date)
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	int year = std::stoi(date.substr(0, 4));
	int month = std::stoi(date.substr(5, 2));
	int day = std::stoi(date.substr(8, 2));

	if (month < 1 || month > 12 || year < 2009 || year > 2023 || day < 1)
		return false;
	switch (month)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		if (day > 31)
			return false;
		break;

	case 2:
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		{
			if (day > 29)
				return false;
		}
		else if (day > 28)
			return false;
		break;

	case 4: case 6: case 9: case 11:
		if (day > 30)
			return false;
		break;
	}
	return true;
}

static bool checkValue(const float &value)
{
	if (value < 0)
	{
		cout << "Error: not a positive number." << endl;
		return false;
	}
	if (value > 1000)
	{
		cout << "Error: too large a number." << endl;
		return false;
	}
	return true;
}

void BitcoinExchange::calculateBtc(const string &fileName)
{
	map<string, float> csvData = getDatabase();
	if (csvData.size() == 0)
		return;

	std::ifstream file(fileName);
	if (file.is_open() == false)
	{
		cout << "Error: could not open file." << endl;
		return;
	}

	string line;
	std::getline(file, line);
	if (line != "date | value")
	{
		cout << "Error: improper heading for " << fileName << endl;
		file.close();
		return;
	}

	while (std::getline(file, line))
	{
		std::istringstream iss(line);
		string date;
		float value;
		char delimiter;

		iss >> date >> delimiter >> value;
		if (delimiter != '|')
		{
			cout << "Error: Invalid data format in file: " << fileName << endl;
			file.close();
			return;
		}

		bool ret;
		if ((ret = checkDate(date)) && checkValue(value))
			cout << date << " => " << value << " = " << (value * csvData.lower_bound(date)->second) << endl;

		if (ret == false)
			cout << "Error: bad input => " << date << endl;
	}

	file.close();
}
