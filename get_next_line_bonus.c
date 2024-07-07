/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuyamagu <kuyamagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 21:12:56 by kuyamagu          #+#    #+#             */
/*   Updated: 2024/07/07 23:07:30 by kuyamagu         ###   ########.fr       */
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
	if (fd >= 10240)
		return (NULL);
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


#include <libc.h>

__attribute__((destructor))
static void destructor() {
    system("leaks -q a.out");
}

int	main() {
	int fd, i;
//	int fd2;
	char *line;
//	char *line2;

	i = 0;
	//fd = open("test.txt", O_RDONLY);
	//fd2 = open("test2.txt", O_RDONLY);
	//write(1, "im here\n", 8);
	while (++i < 10)
	{
		line = get_next_line(30000);
		if (line == NULL)
			printf("NULL\n");
		else
			printf("%s\n", line);

		//line2 = get_next_line(fd2);
		//printf("%s\n", line2);
		free(line);
		//free(line2);
	}
//	printf("1\n");
	//close(fd);
	//close(fd2);
//
//printf("2\n");
	// return 0;
}
