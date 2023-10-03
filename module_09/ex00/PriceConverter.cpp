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
		std::cout << this->database[*c.begin()];
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
	// std::map<std::string, std::string>::iterator it;
	// int i = 0;
	// for(it = this->database.begin(); i < 10; i++)
	// {
	// 	std::cout << it->first << "---" << it->second << std::endl;
	// 	it++;
	// }
	// std::string test = "2009-01-02";
	// it = this->database.find(test);
	// std::cout << it->second << std::endl;
	// if (it == this->database.end())
	// 	std::cout << "BS\n" << std::endl;
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
		//Date valideren
		std::string date = "2009-01-02";
		std::cout << line.substr(0, pipe - 1) << std::endl;
		std::cout << "substr" << this->database.find(date)->second << std::endl;
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */