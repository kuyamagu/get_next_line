/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuyamagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 22:51:42 by kuyamagu          #+#    #+#             */
/*   Updated: 2024/06/13 23:11:26 by kuyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void	*dst, const void *src, size_t n)
{
	unsigned char	*uns_dst;
	const	unsigned char	*cuns_src;
	size_t	i;

	uns_dst = (unsigned char *)dst;
	cuns_src = (const unsigned char *)src;

	i = 0;
	if (!dst && !src)
		return (dst);
	while (i++ < n)
		uns_dst[i] = cuns_src[i];
	return (dst);
}

size_t	ft_strlen(const	char *s)
{
	size_t	num;
	
	num = 0;
	while (s[num] != '\0')
		num++;
	return (num);
}
