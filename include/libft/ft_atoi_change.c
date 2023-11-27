/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_change.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorteixe <jorteixe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 09:04:51 by jorteixe          #+#    #+#             */
/*   Updated: 2023/11/15 10:38:32 by jorteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	skip_spaces(unsigned char *str, int *ptr);
static int	check_plus_minus(unsigned char *str, int *ptr);

long	ft_atoi_change(const char *str)
{
	unsigned char	*s;
	int				i;
	int				minus_count;
	long			n;

	s = (unsigned char *)str;
	i = 0;
	n = 0;
	minus_count = 0;
	skip_spaces(s, &i);
	minus_count = check_plus_minus(s, &i);
	while (s[i] >= '0' && s[i] <= '9' && s[i] != '\0')
	{
		n = n * 10;
		n = n + (s[i] - '0');
		i++;
	}
	if (minus_count == -1)
		n = n * (-1);
	return (n);
}

static void	skip_spaces(unsigned char *str, int *ptr)
{
	while ((str[*ptr] >= 9 && str[*ptr] <= 13) || str[*ptr] == ' ')
	{
		(*ptr)++;
	}
}

static int	check_plus_minus(unsigned char *str, int *ptr)
{
	if (str[*ptr] == '+')
	{
		(*ptr)++;
	}
	else if (str[*ptr] == '-')
	{
		(*ptr)++;
		return (-1);
	}
	return (0);
}
