#include "so_long.h"
#include "stdio.h"


int	main(int argc, char **argv)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if(argc == 2)
	{
		check_xpm();
		ber_file_check(argv[1]);
		handle_map(argv[1], game);
	}
	else
		write(1, "Incorrect number of arguments\n", 30);
}