#include "Contacts.hpp"

void	Contacts::change_fields(int type, std::string var)
{
	switch(type){
	case 1:
		this->first_name = var;
	case 2:
		this->last_name = var;
	case 3:
		this->nick_name = var;
	case 4:
		this->phone_number = var;
	case 5:
		this->darkest_secret = var;
	}
}

std::string Contacts::show_info(int n)
{
	switch(n){
	case 1:
		return(this->first_name);
	case 2:
		return(this->last_name);
	case 3:
		return(this->nick_name);
	case 4:
		return(this->phone_number);
	case 5:
		return(this->darkest_secret);
	}
	return ("");
}