/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   good_backtrack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <thomasdelan2@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 22:41:05 by truello           #+#    #+#             */
/*   Updated: 2023/09/03 23:21:18 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_verify_line(int **grid, int line, int format);
int	ft_verify_column(int **grid, int column, int format);
int	ft_is_grid_valid(int **grid, int format);
int	ft_is_valid(int **grid, int pos, int format, int grid_size);

int	test(int **grid, int pos, int gs, int val)
{
	while (val >= 1)
	{
		grid[pos / gs][pos % gs] = val;
		if (pos / gs == gs - 2 && pos % gs == gs - 2)
		{
			if (ft_is_grid_valid(grid, gs - 2))
				return (1);
		}
		else if (pos % gs == gs - 2)
		{
			if (ft_verify_line(grid, pos / gs, gs - 2))
				return (ft_is_valid(grid, pos + 1, gs - 2, gs));
		}
		else if (pos / gs == gs - 2)
		{
			if (ft_verify_column(grid, pos % gs, gs - 2))
				return (ft_is_valid(grid, pos + 1, gs - 2, gs));
		}
		else if (ft_is_valid(grid, pos + 1, gs - 2, gs))
			return (1);
		grid[pos / gs][pos % gs] = 0;
		val--;
	}
	return (0);
}

int	ft_is_valid(int **grid, int pos, int format, int grid_size)
{
	int	i;
	int	j;
	int	val;

	if (pos == grid_size * grid_size)
		return (1);
	i = pos / grid_size;
	j = pos % grid_size;
	val = format;
	if (i == 0 || i == grid_size - 1 || j == 0 || j == grid_size - 1)
	{
		return (ft_is_valid(grid, pos + 1, format, grid_size));
	}
	if (grid[i][j] != 0)
	{
		if (ft_is_valid(grid, pos + 1, format, grid_size))
			return (1);
	}
	if (test(grid, pos, grid_size, format))
		return (1);
	return (0);
}
