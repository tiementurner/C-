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
	std::regex delimiter{","};
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

bool PriceConverter::validate(std::string filename)
{
	std::cout << filename;

	
	return(true);
}

void PriceConverter::process()
{
	std::string line;
	std::size_t pipe;

	std::getline(this->file, line);
	while(std::getline(this->file, line))
	{
		pipe = line.find("|");
		if (pipe == std::string::npos)
		{
			std::cout << "invalid input => " << line << std::endl;
			continue;
		}
		std::cout << line << "---" << pipe << std::endl;
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */