/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuyamagu <kuyamagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 20:57:59 by kuyamagu          #+#    #+#             */
/*   Updated: 2024/06/13 21:46:28 by kuyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

int main (void)
{
	int	fd;
	char *line;

	fd = open("test", O_RDONLY);

	line = NULL;

	line = get_next_line(fd);
	//if(!line)
	//	break;
	printf("%s",line);
	free(line);
	close(fd);
	return (0);
}
