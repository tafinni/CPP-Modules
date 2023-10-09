#include <iostream>

int	main(int argc, char **argv)
{
	int	i;
	int	y;

	i = 1;
	if (argc > 1)
	{
		while (argv[i])
		{
			y = 0;
			while (argv[i][y])
			{
				std::cout << (char)std::toupper(argv[i][y]);
				y++;
			}
			i++;
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOICE *" << std::endl;
	return (0);
}
