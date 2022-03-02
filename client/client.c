/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconchit <aconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 13:56:02 by aconchit          #+#    #+#             */
/*   Updated: 2021/11/19 16:56:36 by aconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_push(int pid, char massage, int bit)
{
	if (bit != 0)
		ft_push(pid, massage / 2, bit - 1);
	if (massage % 2 == 1)
	{
		if (kill(pid, SIGUSR1) == -1)
			ft_error("Error signal\n");
	}
	if (massage % 2 == 0)
	{
		if (kill(pid, SIGUSR2) == -1)
			ft_error("Error signal\n");
	}
	ft_optimization();
}

void	ft_send(int pid, char *massage)
{
	while (*massage)
		ft_push(pid, *(massage++), 7);
}

void	ft_handler(int signum, siginfo_t *siginfo, void *unsd)
{
	(void)signum;
	(void)siginfo;
	(void)unsd;
	write(1, "Signal received\n", 16);
}

int	ft_pars(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (1);
		++str;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		ft_error("Error arguments\n");
	if (ft_pars(argv[1]))
		ft_error("Error signal\n");
	ft_send(ft_atoi(argv[1]), argv[2]);
	return (0);
}
