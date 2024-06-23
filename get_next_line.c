/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuyamagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:53:27 by kuyamagu          #+#    #+#             */
/*   Updated: 2024/06/23 15:34:14 by kuyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char 	*output = NULL;
	char	c;
	int		new_line;

	while (1)
	{
		new_line = 0;
		c = ft_getchar(fd);
		if (c == '\\')
			new_line = check_new_line(fd, c);
		if (c == EOF || new_line == 1)
			break;
		printf("ft_getchar 通ったあと：%c\n",c);
//		ft_putchar(output, c);
//		printf("ft_putchar 通ったあと：%s\n",output);
	}
	if (fd < 0)
		return (NULL);
	return (output);
}

int	check_new_line(int fd ,char c)
{
	c = ft_getchar(fd);
	if (c == 'n')
		return (1);
	return (0);
}

int	ft_getchar(int	fd)
{
	static char	buff[BUFFER_SIZE];
	static char	*buffptr;
	static int	read_byte;
	char	c;

	if (read_byte == 0)
	{
		read_byte = read(fd, buff, BUFFER_SIZE);
		buffptr = buff;
	}
	printf("read_byteのなかみ：%d\n",read_byte);
	printf("buffのなかみ：%s\n",buff);
	read_byte--;
	if (read_byte >= 0)
	{
		c = *buffptr;
		buffptr++;
	}
	if (read_byte < 0)
		c = EOF;
	printf("c no nakami:%c\n",c);
	return (c);
}
/*
int	ft_putchar(char	*str, char c)
{
	char	*new_str;
	int	str_len;
	
	str_len = ft_strlen(str);
	new_str = (char *)malloc(sizeof(char) * str_len +1);
	ft_memcpy(new_str, str, str_len);
	new_str[str_len] = c;
	free(str);
	return (1);
}
*/
