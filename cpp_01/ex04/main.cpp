#include "includes/sed.hpp"

void	replaceStr (std::string *out, std::string s1, std::string s2)
{
	size_t start;

	while ((start = (*out).find(s1)) != std::string::npos)
	{
		(*out).erase(start, s1.length());
		(*out).insert(start, s2);
	}
}

int main (int argc, char **argv)
{
	std::string	s1;
	std::string	s2;
	std::string	buff;
	char		*fileName;
	char		str[1523];
	int		i;
	int		j;

	if (argc != 4)
		std::cout << BAD_N_INPUT;
	else
	{
		s1 = argv[2];
		s2 = argv[3];
		if (!s1.length() || !s2.length())
		{
			std::cout << EMPTY_STRINGS;
			return (-1);
		}
		std::ifstream	ifs(argv[1]);
		if (!ifs.is_open())
		{
			std::cout << IN_FILE_ERROR;
			return (-2);
		}
		if (strchr(argv[1], '.'))
		{
			i = 0;
			j = 0;
			while (argv[1][i])
			{
				if (argv[1][i] == '.')
					break;
				str[j++] = argv[1][i++];
			}
			str[j] = 0;
			fileName = strcat(str, ".replace");
			std::ofstream	ofs(fileName);
			if (!ofs.is_open())
			{
				std::cout << OUT_FILE_ERROR;
				return (-3); 
			}
			while (std::getline(ifs, buff))
			{
				replaceStr(&buff, s1, s2);
				if (!ifs.eof())
					ofs << buff << std::endl;
			}
			ofs.close();
			ifs.close();
		}
		else
		{
			fileName = strcat(argv[1], "replace");
			std::ofstream	ofs(fileName);
			if (!ofs.is_open())
			{
				std::cout << OUT_FILE_ERROR;
				return (-3);
			}
			while (std::getline(ifs, buff))
			{
				replaceStr(&buff, s1, s2);
				if (!ifs.eof())
					ofs << buff << std::endl;
			}
			ofs.close();
			ifs.close();
		}
	}
	return (0);
}
