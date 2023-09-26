#include "PriceConverter.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PriceConverter::PriceConverter()
{
}


PriceConverter::PriceConverter(std::string filename)
{
	open_file(filename);
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

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */