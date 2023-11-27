/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorteixe <jorteixe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:59:42 by jorteixe          #+#    #+#             */
/*   Updated: 2023/11/22 16:40:22 by jorteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	main(int argc, char *argv[])
{
	int					pid;
	const char			*message;
	struct sigaction	s_action;

	s_action.sa_sigaction = s_handler;
	sigemptyset(&s_action.sa_mask);
	s_action.sa_flags = SA_RESTART | SA_SIGINFO;
	sigaction(SIGUSR1, &s_action, NULL);
	if (argc != 3)
	{
		ft_printf("You should write: %s <pid> <message>\n", argv[0]);
		return (1);
	}
	message = argv[2];
	pid = ft_atoi(argv[1]);
	if (pid == 0 || message[0] == '\0')
		return (-1);
	send_message(message, pid);
	while (sigaction(SIGUSR1, &s_action, NULL) != 0)
	{
	}
	return (0);
}

void	send_message(const char *message, int pid)
{
	size_t	i;
	int		bit;
	int		signum;

	i = 0;
	while (i <= ft_strlen(message))
	{
		bit = 7;
		while (bit >= 0)
		{
			if (message[i] & (1 << bit))
				signum = SIGUSR1;
			else
				signum = SIGUSR2;
			kill(pid, signum);
			usleep(300);
			bit--;
		}
		i++;
	}
}

void	s_handler(int signum, siginfo_t *info, void *context)
{
	(void)signum;
	(void)info;
	(void)context;
	write(1, "Message Received\n", 17);
}
