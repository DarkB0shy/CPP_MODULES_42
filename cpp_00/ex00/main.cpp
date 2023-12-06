#include <iostream>

char upper_c(char c)
{return (c -= 32);}

int main (int argc, char **argv)
{
	int i;
	int j;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		i = 0;
		while (++i < argc)
		{
			j = -1;
			while (argv[i][++j])
			{
				if (argv[i][j] >= 'a' && argv[i][j] <= 'z')
					std::cout << upper_c(argv[i][j]);
				else
					std::cout << argv[i][j];
			}
			if (argv[i+1])
				std::cout << " ";
		}
	}
	std::cout << std::endl;
	return (0);
}
