#include "PriceConverter.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PriceConverter::PriceConverter()
{
	std::fstream database_file;
	database_file.open("data.csv", std::ios::in);
	if(database_file)
	{
		std::cout << "Error: Failed to open data.csv." << std::endl;
		this->is_open = false;
		return ;
	}
	std::string line;
	std::regex delimiter{","};
	while (getline(database_file, line))
	{
		std::vector<std::string> c(std::sregex_token_iterator(line.begin(), line.end(), delimiter, -1), {});
		this->database[*c.begin()] = *std::next(c.begin(), 1);
	}
}


PriceConverter::PriceConverter(std::string filename)
{
	open_file(filename);
	std::fstream database_file;
	database_file.open("data.csv", std::ios::in);
	if(!database_file)
	{
		std::cout << "Error: Failed to open data.csv." << std::endl;
		this->is_open = false;
		return ;
	}
	std::string line;
	std::regex delimiter{",{1}"};
	while (getline(database_file, line))
	{
		std::vector<std::string> c(std::sregex_token_iterator(line.begin(), line.end(), delimiter, -1), {});
		this->database[*c.begin()] = *std::next(c.begin(), 1);
	}
}

PriceConverter::PriceConverter( const PriceConverter & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PriceConverter::~PriceConverter()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PriceConverter &				PriceConverter::operator=( PriceConverter const & rhs )
{
	if (this != &rhs)
        return(*this);
    return (*this);
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void PriceConverter::open_file(std::string filename)
{


	this->file.open(filename.c_str(), std::ios::in);
	if(!this->file)
	{
		std::cout << "Error: Failed to open file." << std::endl;
		this->is_open = false;
	}
	this->is_open =true;
}

bool PriceConverter::validate_date(std::string date)
{
	std::regex delimiter{"-"};
	std::vector<std::string> c(std::sregex_token_iterator(date.begin(), date.end(), delimiter, -1), {});

	if (c.size() != 3)
		return(false);
	
	for (int i = 0; i < 3; i++)
	{
		std::string checkdate = c[i];
		
		for (int i = 0; checkdate[i]; i++)
			if (!isdigit(checkdate[i]))
				return(false);
		
		if (i == 0)
			year = stoi(checkdate);

		if (i == 1)
		{
			month = stoi(checkdate);
			if(month < 1 || month > 12)
				return(false);
		}

		if (i == 2)
		{
			day = stoi(checkdate);
			if(day < 1)
				return(false);
			if(day > 31)
				return(false);
			if(day == 31 && stoi(c[i-1]) % 2 == 0)
				return(false);	
		}
	}
	return (true);
}

bool PriceConverter::validate_amount(std::string amount)
{

	for (int i = 0; amount[i]; i++)
		if (!isdigit(amount[i]) && !(amount[i] == '.'))
		{
			std::cout << "Error: invalid input => " << amount << std::endl;
			return (false);
		}
	if (stod(amount) < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return (false);
	}
	if (stod(amount) > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return (false);
	}
	this->amount = stof(amount);
	return (true);
}

void PriceConverter::convert_price()
{
	// std::map<std::string, std::string>::iterator it;
	std::string key = "";
	if (year < 2009)
		key += "2009";
	else if (year > 2022)
		key += "2022";
	else
		key = std::to_string(year);
	key = key + "-" + std::to_string(month) + "-" + std::to_string(day);
	//key vinden in database

}

void PriceConverter::process()
{
	std::string line;
	std::size_t pipe;

	std::getline(this->file, line);
	while(std::getline(this->file, line))
	{
		line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
		pipe = line.find("|");
		if (pipe == std::string::npos || pipe == line.length() - 1)
		{
			std::cout << "Error: invalid input => " << line << std::endl;
			continue;
		}
		std::string date = line.substr(0, pipe);
		std::string amount = line.substr(pipe + 1, line.length());
		if (!validate_amount(amount))
			continue;
		if (!validate_date(date))
		{
			std::cout << "Error: bad input => " + date << std::endl;
			continue;
		}
		else
			std::cout << date << " => " << amount << std::endl;
		
		convert_price();
		//break;
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */