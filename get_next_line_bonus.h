/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuyamagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 21:30:18 by kuyamagu          #+#    #+#             */
/*   Updated: 2024/07/06 21:40:04 by kuyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <limits.h> //OPEN_MAX 10240
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_buffinfo
{
	char	buff[BUFFER_SIZE];
	char	*ptr;
	int		read_byte;
}			t_buffinfo;

char		ft_getchar(int fd);
char		*ft_putchar(char *str, char c, int output_len);
char		*get_next_line(int fd);

#endif
