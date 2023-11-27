/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorteixe <jorteixe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:31:23 by jorteixe          #+#    #+#             */
/*   Updated: 2023/11/22 16:43:52 by jorteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	main(void)
{
	struct sigaction	s_action;

	s_action.sa_sigaction = signal_handler;
	sigemptyset(&s_action.sa_mask);
	s_action.sa_flags = SA_RESTART | SA_SIGINFO;
	sigaction(SIGUSR1, &s_action, NULL);
	sigaction(SIGUSR2, &s_action, NULL);
	ft_printf("Receiver PID: %d\n", getpid());
	while (1)
	{
	}
	return (0);
}

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static int	bits_received;
	static char	c;

	(void)context;
	(void)info;
	c = 0;
	bits_received = 0;
	c = c << 1;
	if (signum == SIGUSR1)
		c = c | 1;
	bits_received++;
	if (bits_received == 8)
	{
		write(1, &c, 1);
		if (c == '\0')
		{
			kill(info->si_pid, SIGUSR1);
		}
		bits_received = 0;
		c = 0;
	}
}
