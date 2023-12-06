#include "Contact.hpp"

Contact::Contact(void) {}

std::string	Contact::get_firstName(void) {return (this->_firstName);}

void		Contact::set_firstName(std::string str) {this->_firstName = str;}

std::string	Contact::get_lastName(void) {return (this->_lastName);}

void		Contact::set_lastName(std::string str) {this->_lastName = str;}

std::string	Contact::get_nickName(void) {return (this->_nickName);}

void		Contact::set_nickName(std::string str) {this->_nickName = str;}

std::string	Contact::get_phone(void) {return (this->_phone);}

void		Contact::set_phone(std::string str) {this->_phone = str;}

std::string	Contact::get_secret(void) {return (this->_secret);}

void		Contact::set_secret(std::string str) {this->_secret = str;}

std::string	Contact::truncInfo(std::string str)
{
	if (str.size() > 9)
	{
		str.resize(9);
		return (str + ". ");
	}
	else
		return (" " + str + " ");
}

void		Contact::showInfo(int i) { std::cout << i << ")" << truncInfo(this->get_firstName()) << "|" << truncInfo(this->get_lastName()) << "|" << truncInfo(this->get_nickName()) << std::endl;}

Contact::~Contact(void) {}
