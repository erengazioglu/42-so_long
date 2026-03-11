#include "include/libft.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	char **map = read_n_lines(argv[1], 5);
	if (!map)
		return (1);
	for (int i = 0; i < 5; i++)
	{
		ft_printf("%s\n", map[i]);
		free(map[i]);
	}
	free(map);
	return (0);
}