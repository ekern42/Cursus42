/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fc_dec_to_binary.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekern <ekern@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:43:12 by ekern             #+#    #+#             */
/*   Updated: 2022/04/05 14:12:26 by ekern            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*fc_dec_to_binary(int dec)
{
	int	*tab;
	int	a;
	int	b;

	b = 1;
	a = -1;
	tab = malloc(sizeof(int *) * 32);
	while (++a < 32)
		tab[a] = 0;
	if (dec < 0)
	{
		tab[0] = 1;
		dec *= -1;
	}
	while (dec != 0)
	{
	//	printf("%d\n", dec);
		tab[--a] = dec % 2;
		dec /= 2; 
	}
	return (tab);
}

int	main(void)
{
	int	a;
	int	*b;
	int	c;
	
	a = 2147483647;
	c = -1;
	b = fc_dec_to_binary(a);
	while (++c < 32)
		printf("%d ", b[c]);
	free(b);
}