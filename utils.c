/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconchit <aconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:16:17 by aconchit          #+#    #+#             */
/*   Updated: 2021/11/19 16:56:23 by aconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_optimization(void)
{
	usleep(2);
	usleep(2);
	usleep(2);
	usleep(2);
	usleep(2);
	usleep(2);
	usleep(2);
	usleep(2);
	usleep(2);
	usleep(2);
	usleep(2);
	usleep(2);
	usleep(2);
	usleep(2);
	usleep(2);
	usleep(2);
	usleep(2);
	usleep(2);
	usleep(2);
	usleep(2);
	usleep(2);
	usleep(2);
	usleep(2);
	usleep(2);
	usleep(2);
}

void	ft_error(char *str)
{
	while (*str)
	{
		write(2, str, 1);
		++str;
	}
	exit(0);
}

int	ft_atoi(const char *str)
{
	unsigned int	res;
	int				sign;

	res = 0;
	sign = 1;
	while ((*str == ' ' || *str == '\t' || *str == '\v' || *str == '\f' \
	|| *str == '\r' || *str == '\n' || *str == '\f') && *str)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		res = (*str - '0') + (res * 10);
		str++;
	}
	if (res > 2147483647 && sign > 0)
		return (-1);
	if (res > 2147483648 && sign < 0)
		return (0);
	return (res * sign);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;

	nb = n;
	if (n < 0)
	{
		nb = -n;
		ft_putchar_fd('-', fd);
	}
	else
		nb = n;
	if (nb >= 10)
		ft_putnbr_fd(nb / 10, fd);
	ft_putchar_fd((nb % 10) + '0', fd);
}
