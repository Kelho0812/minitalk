/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorteixe <jorteixe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:33:40 by jorteixe          #+#    #+#             */
/*   Updated: 2023/10/02 14:33:41 by jorteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int ch)
{
	if (ch >= 65 && ch <= 90)
	{
		ch = ch + 32;
		return (ch);
	}
	else
	{
		return (ch);
	}
}
