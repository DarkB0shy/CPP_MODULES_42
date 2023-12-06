#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact
{
	private:

		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_phone;
		std::string	_secret;

	public:

		std::string	get_firstName(void);
		void		set_firstName(std::string str);
		std::string	get_lastName(void);
		void 		set_lastName(std::string str);
		std::string 	get_nickName(void);
		void 		set_nickName(std::string str);
		std::string	get_phone(void);
		void		set_phone(std::string str);
		std::string	get_secret(void);
		void		set_secret(std::string str);

		std::string	truncInfo(std::string str);
		void		showInfo(int i);

		Contact();
		~Contact();
};

#endif
