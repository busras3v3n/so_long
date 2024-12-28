#include "so_long.h"
#include "stdio.h"


int	main(int argc, char **argv)
{
	if(argc == 2)
	{
		check_xpm();
		ber_file_check(argv[1]);
		handle_map(argv[1], game);
		printf("%d", game->map->start_x);
	}
	else
		write(1, "Error\nIncorrect number of arguments\n", 36);
}
