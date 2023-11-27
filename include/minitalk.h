/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorteixe <jorteixe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:51:23 by jorteixe          #+#    #+#             */
/*   Updated: 2023/11/22 16:17:38 by jorteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define _XOPEN_SOURCE 500

# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"
# include <limits.h>
# include <signal.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

void	signal_handler(int signum, siginfo_t *info, void *context);
void	signal_handler_client(int signum, siginfo_t *info, void *context);
void	send_message(const char *message, int pid);
void	s_handler(int signum, siginfo_t *info, void *context);

#endif