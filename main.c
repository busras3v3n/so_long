#include "so_long.h"
#include "stdio.h"

void	check_xpm()
{
	check_img();
	check_img2();
	check_img3();
}

void	ber_file_check(char *path)
{
	extension_check(path);
	open_check(path);
}


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