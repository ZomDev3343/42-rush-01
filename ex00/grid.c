/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaldias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 17:54:28 by tsaldias          #+#    #+#             */
/*   Updated: 2023/09/03 23:34:24 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_arg_valid(char *arg)
{
	int	i;
	int	r;

	i = 0;
	r = 0;
	while (arg[i])
	{
		if (i % 2 == 1 && arg[i] != ' ')
			return (0);
		if (arg[i] >= '0' && arg[i] <= '9')
			r++;
		else if (arg[i] != ' ')
			return (0);
		i++;
	}
	if (r % 4 > 0)
		return (0);
	return (r);
}

void	ft_get_sides(char *str, int *sides)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			sides[j] = str[i] - '0';
			j++;
		}
		i++;
	}
}

void	ft_put_sides_in_grid(int **grid, int *sides, int *format)
{
	int	x;

	x = 0;
	while (x < *format - 2)
	{
		grid[0][x + 1] = sides[x];
		grid[*format - 1][x + 1] = sides[*format - 2 + x];
		grid[x + 1][0] = sides[(*format - 2) * 2 + x];
		grid[x + 1][*format - 1] = sides[(*format - 2) * 3 + x];
		x++;
	}
}

int	**ft_get_grid(char *arg, int *format)
{
	int	**grid;
	int	*sides;
	int	i;

	*format = ft_arg_valid(arg);
	if (*format > 0)
	{
		*format /= 4;
		sides = (int *) malloc(sizeof(int) * (*format) * 4);
		ft_get_sides(arg, sides);
		*format += 2;
		grid = (int **) malloc(sizeof(int *) * (*format));
		i = 0;
		while (i < *format)
		{
			grid[i] = (int *) malloc(sizeof(int) * (*format));
			i++;
		}
		ft_put_sides_in_grid(grid, sides, format);
		return (grid);
	}
	return (0);
}
