#include "libft.h"

int	main(int argc, char **argv)
{
	char **buffer = ft_split(argv[1], ' ');
	printf("%s\n", buffer[0]);
}
