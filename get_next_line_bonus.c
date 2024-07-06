/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuyamagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 21:12:56 by kuyamagu          #+#    #+#             */
/*   Updated: 2024/07/06 21:38:02 by kuyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	ft_getchar(int fd)
{
	static t_buffinfo	buffinfo[OPEN_MAX];

	if (buffinfo[fd].read_byte == 0)
	{
		buffinfo[fd].read_byte = read(fd, buffinfo[fd].buff, BUFFER_SIZE);
		buffinfo[fd].ptr = buffinfo[fd].buff;
	}
	if (buffinfo[fd].read_byte < 0)
		return (buffinfo[fd].read_byte++, -2);
	if (--buffinfo[fd].read_byte >= 0)
		return (*(buffinfo[fd].ptr)++);
	return (buffinfo[fd].read_byte++, EOF);
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
