#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contacts.hpp"
#include <string>
#include <iostream>

class PhoneBook
{
	public:
	void		add_contact(int id);
	void		show_contacts();

	private:
	Contacts	contacts[8];
	void 		fill_field(int type, Contacts *contact, std::string word);
	void		show_contact_fields(int id);
};
# endif