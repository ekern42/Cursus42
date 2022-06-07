/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekern <ekern@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:34:45 by ekern             #+#    #+#             */
/*   Updated: 2022/05/20 16:03:31 by ekern            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	fc_info_return(int sig)
{
	static int	rec_signal;

	if (sig == SIGUSR1)
		rec_signal++;
	else
		ft_printf("%d signals recieved by the server\n", rec_signal);
}

static void	fc_convert(char *str, char *pib)
{
	int		a;
	int		b;
	char	c;

	a = -1;
	while (str[++a] != '\0')
	{
		b = 8;
		c = str[a];
		while (b-- > 0)
		{
			if (c >> b & 1)
				kill(ft_atoi(pib), SIGUSR2);
			else
				kill(ft_atoi(pib), SIGUSR1);
			usleep(50);
		}
	}
	while (b++ < 7)
	{
		kill(ft_atoi(pib), SIGUSR2);
		usleep(50);
	}
}

int	main(int ac, char **av)
{
	if (ac != 3 || av[2] == NULL)
		return (1);
	signal(SIGUSR1, fc_info_return);
	signal(SIGUSR2, fc_info_return);
	fc_convert(av[2], av[1]);
	return (0);
}
