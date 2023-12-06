#include "PhoneBook.hpp"
#include "Contact.hpp"

int	parseInt(std::string str)
{
	int	i;
	int	ret;

	i = 0;
	while (str[i]==32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	ret = 0;
	while (str[i])
	{
		if (!isdigit(str[i]))
			return (-1);
		ret = ret * 10 + str[i++] - '0';
	}
	return (ret);
}

PhoneBook::PhoneBook (void) {}

void	PhoneBook::addContact(int i)
{
	std::string	temp;

	std::cout << INSERT_FIRST_NAME;
	std::getline(std::cin, temp);
	this->_cont[i].set_firstName(temp);
	std::cout << INSERT_LAST_NAME;
	std::getline(std::cin, temp);
	this->_cont[i].set_lastName(temp);
	std::cout << INSERT_NICK_NAME;
	std::getline(std::cin, temp);
	this->_cont[i].set_nickName(temp);
	std::cout << INSERT_PHONE_NUMBER;
	std::getline(std::cin, temp);
	while (1)
	{
		long unsigned int j = -1;
		while (temp[++j])
		{
			if (temp==""||!isdigit(temp[j]))
			{
				std::cout << PHONE_NUMBER_LOOP;
				std::getline(std::cin, temp);
				j = -1;
			}
			if (j == temp.size())
				break ;
		}
		break ;
	}
	this->_cont[i].set_phone(temp);
	std::cout << INSERT_SECRET;
	std::getline(std::cin, temp);
	this->_cont[i].set_secret(temp);
	if (this->_cont[i].get_firstName()=="" || this->_cont[i].get_lastName()==""||(this->_cont[i].get_nickName()=="")||(this->_cont[i].get_phone()=="")|(this->_cont[i].get_secret()==""))
	{
		std::cout << EMPTY_FIELD << std::endl;
		this->_cont[i].set_firstName("");
		this->_cont[i].set_lastName("");
		this->_cont[i].set_nickName("");
		this->_cont[i].set_phone("");
		this->_cont[i].set_secret("");
	}
}

void	PhoneBook::showContacts(void)
{
	int	i;

	std::cout << CONTACT_INFO << std::endl;
	i = -1;
	while (++i < 8)
	{
		if (this->_cont[i].get_firstName() == "")
			i++;
		else
			this->_cont[i].showInfo(i);
	}
}

void	PhoneBook::searchContact(void)
{
	std::string	index;
	int		real_index;
	int		check;

	real_index = -1;
	check = -1;
	while (++real_index < 8)
	{
		if (this->_cont[real_index].get_firstName()=="")
			check++;
	}
	if (check == 7)
	{
		std::cout << EMPTY_PHONEBOOK;
		return ;
	}
	while (1)
	{
		this->showContacts();
		std::cout << INDEX_RESEARCH << std::endl;
		std::getline(std::cin, index);
		if (std::cin.eof())
			std::cout << INVALID_INDEX_RESEARCH;
		else
		{
			real_index = 0;
			real_index = parseInt(index);
			if (real_index == -1)
				std::cout << INVALID_INDEX_RESEARCH;
			else if (real_index < 9 && this->_cont[real_index].get_firstName() != "")
			{
				std::cout << FIRST_NAME << this->_cont[real_index].get_firstName() << std::endl;
				std::cout << LAST_NAME << this->_cont[real_index].get_lastName() << std::endl;
				std::cout << NICKNAME << this->_cont[real_index].get_nickName() << std::endl;
				std::cout << PHONE_NUMBER << this->_cont[real_index].get_phone() << std::endl;
				std::cout << DARKEST_SECRET << this->_cont[real_index].get_secret() << std::endl;
				break ;
			}
			else
				std::cout << INVALID_INDEX_RESEARCH;
		}
	}
}

void	PhoneBook::phoneBookLoop(void)
{
	std::string	user_input;
	int		n_contacts;

	n_contacts = 0;
	while (1)
	{
		std::cout << INSERT_OPERATION;
		std::getline(std::cin, user_input);
		if (user_input == "ADD")
		{
			if (n_contacts == 8)
				n_contacts = 0;
			this->addContact(n_contacts);
			n_contacts++;
		}
		else if (user_input == "SEARCH")
			this->searchContact();
		else if (user_input == "EXIT")
			break ;
		else
			std::cout << INVALID_OPERATION;
	}
}

PhoneBook::~PhoneBook (void) {}
