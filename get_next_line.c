/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuyamagu <kuyamagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:53:27 by kuyamagu          #+#    #+#             */
/*   Updated: 2024/07/06 20:30:24 by kuyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	ft_getchar(int fd)
{
	static char	buff[BUFFER_SIZE];
	static char	*ptr;
	static int	read_byte;

	if (read_byte == 0)
	{
		read_byte = read(fd, buff, BUFFER_SIZE);
		ptr = buff;
	}
	if (read_byte < 0)
		return (read_byte++, -2);
	if (--read_byte >= 0)
		return (*ptr++);
	return (read_byte++, EOF);
}

char	*ft_putchar(char *str, char c, int len)
{
	char	*output;
	size_t	i;

	i = 0;
	output = (char *)malloc(sizeof(char) * len);
	if (output == NULL)
		return (NULL);
	if (str == NULL)
	{
		output[0] = c;
		output[1] = '\0';
		return (output);
	}
	while (str[i])
	{
		output[i] = str[i];
		i++;
	}
	output[len - 2] = c;
	output[len - 1] = '\0';
	free(str);
	return (output);
}

char	*get_next_line(int fd)
{
	char	*output;
	char	c;
	int		output_len;

	output = NULL;
	output_len = 2;
	while (1)
	{
		c = ft_getchar(fd);
		if (c == EOF)
			break ;
		if (c == -2)
			return (free(output), NULL);
		output = ft_putchar(output, c, output_len++);
		if (c == '\n')
			break ;
	}
	return (output);
}
