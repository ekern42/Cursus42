/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekern <ekern@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:34:50 by ekern             #+#    #+#             */
/*   Updated: 2022/05/20 15:57:46 by ekern            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	fc_data_recieved(int sig, siginfo_t *info, void *context)
{
	static unsigned char	c;
	static int				a;
	int						pid_sender;

	(void)context;
	if (sig == SIGUSR2)
		c |= 1;
	a++;
	if (a == 8)
	{
		pid_sender = info->si_pid;
		if (c == 255)
		{
			ft_putendl_fd("", 1);
			kill(pid_sender, SIGUSR2);
		}
		else
		{
			ft_putchar_fd(c, 1);
			kill(pid_sender, SIGUSR1);
		}
		a = 0;
		c = 0;
	}
	c <<= 1;
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("PID : %d\n", getpid());
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = fc_data_recieved;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
