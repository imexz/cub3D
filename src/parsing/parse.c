/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprzybyl <kprzybyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 17:11:01 by kprzybyl          #+#    #+#             */
/*   Updated: 2022/02/20 17:11:02 by kprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	parse(char *file)
{
	int	fd;

	if (ft_strncmp(get_ext(file), "cub", 4) != 0)
	{
		write(2, "Error\nInvalid extension\n", 24);
		exit(1);
	}
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error\nCannot open the map\n", 26);
		exit(1);
	}
	if (parse_info(fd) == 1)
	{
		write(1, "Error\nInvalid information\n", 26);
		exit(1);
	}
	if (parse_map(fd) == 1)
	{
		write(1, "Error\nInvalid map\n", 18);
		exit(1);
	}
	close(fd);
	return (0);
}
