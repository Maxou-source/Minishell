/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:53:56 by mparisse          #+#    #+#             */
/*   Updated: 2023/01/10 01:59:18 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;

	if (nmemb >= MAXOU || size >= MAXOU)
		return (NULL);
	if (nmemb * size / size != nmemb)
		return (NULL);
	mem = malloc(size * nmemb);
	if (!mem)
		return (NULL);
	ft_bzero(mem, size * nmemb);
	return (mem);
}
/*
#include <stdint.h>

int	ft_calloc_succeed()
{
	int i;
	
	i = 0;
	if (calloc(SIZE_MAX, 2) != NULL)
		i = 1;	
	return (i);
}

#include <stdio.h>

int main()
{
	printf("%lu \n",SIZE_MAX + SIZE_MAX);
	printf("%lu \n", SIZE_MAX);
	printf("%lu", sizeof(calloc(4, 4)));
	//printf("%lu \n", SIZE_MAX);
	//printf("%d", ft_calloc_succeed());
}*/
