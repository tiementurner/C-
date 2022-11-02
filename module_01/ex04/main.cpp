#include "Sed.hpp"

int	main(int ac, char **argv)
{
	if (ac != 4)
	{
		std::cout << "please give exactly 3 arguments.";
		return (0);
	}
	Sed sedder(argv[1], argv[2], argv[3]);
	sedder.start_sedding();
}