/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <thomasdelan2@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 22:33:38 by truello           #+#    #+#             */
/*   Updated: 2023/09/05 10:57:14 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_putstr(char *str);
int		ft_arg_valid(char *arg);
void	ft_get_sides(char *str, int *sides);
int		**ft_get_grid(char *arg, int *format);
void	ft_put_sides_in_grid(int **grid, int *sides, int *format);
void	ft_prefill_rows(int **grid, int format);
void	ft_prefill_cols(int **grid, int format);
char	itoc(int n);
char	ft_putchar(char c);

int		ft_is_valid(int **grid, int pos, int format, int grid_size);

void	print_grid(int **grid, int format)
{
	int		i;
	int		j;
	char	n;

	i = 1;
	j = 1;
	while (i <= format)
	{
		while (j <= format)
		{
			n = itoc(grid[i][j]);
			ft_putchar(n);
			if (j < format)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		j = 1;
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	**grid;
	int	format;
	int	i;

	i = -1;
	if (argc == 2)
	{
		grid = ft_get_grid(argv[1], &format);
		if (grid)
		{
			ft_prefill_rows(grid, format);
			ft_prefill_cols(grid, format);
			if (ft_is_valid(grid, format + 1, format - 2, format))
				print_grid(grid, format - 2);
			else
				ft_putstr("Error\n");
			while (++i < format)
				free(grid[i]);
			free(grid);
		}
		else
			ft_putstr("Error\n");
	}
	return (0);
}
