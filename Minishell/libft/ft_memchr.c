/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtosun <rtosun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 13:37:08 by rtosun            #+#    #+#             */
/*   Updated: 2022/02/07 15:18:58 by rtosun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *ptr, int c, size_t n)
{
	char	*p;

	p = (char *)ptr;
	while (n--)
	{
		if (*p == c)
			return (p);
		p++;
	}
	return (NULL);
}
