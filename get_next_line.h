/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuyamagu <kuyamagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:55:04 by kuyamagu          #+#    #+#             */
/*   Updated: 2024/06/23 15:30:19 by kuyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
//# define EOF -1
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

char *get_next_line(int fd);
int	ft_getchar(int	fd);
int	ft_putchar(char	*str, char c);
int	check_new_line(int fd, char c);

void	*ft_memcpy(void	*dst, const void *src, size_t n);
size_t	ft_strlen(const char *s);
#endif
