#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

#define CONTACT_INFO "Contact info: index first name last name nick name"
#define INSERT_FIRST_NAME "New contact first name: "
#define INSERT_LAST_NAME "New contact last name: "
#define INSERT_NICK_NAME "New contact nick name: "
#define INSERT_PHONE_NUMBER "New contact phone number: "
#define INSERT_SECRET "New contact secwet: "
#define PHONE_NUMBER_LOOP "You are now gonna enter a valid number. "
#define EMPTY_FIELD "You left an empty field. You need to restart the procedure."
#define EMPTY_PHONEBOOK "The phonbonk is empty."
#define INDEX_RESEARCH "Enter index of contact you wish to know all you need to know about: "
#define INVALID_INDEX_RESEARCH "You entered an invalid index. I am unhappy.\n"
#define FIRST_NAME "First name: "
#define LAST_NAME "Last name: "
#define NICKNAME "Nickname: "
#define PHONE_NUMBER "Number: "
#define DARKEST_SECRET "Dawkest secwet: "
#define INVALID_OPERATION "Only commands are: ADD, SEARCH, EXIT\n"
#define INSERT_OPERATION "PhoneBook Main Menu\nPlease enter one of the following commands: ADD | SEARCH | EXIT\n"

class PhoneBook
{
	private:
		Contact _cont[8];

	public:
		void	addContact(int i);
		void	searchContact(void);
		void	showContacts(void);
		void	phoneBookLoop(void);
		PhoneBook(void);
		~PhoneBook(void);
};

#endif
