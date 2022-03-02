/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconchit <aconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 14:25:33 by aconchit          #+#    #+#             */
/*   Updated: 2021/11/19 16:56:30 by aconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_handler(int signum, siginfo_t *siginfo, void *unsd)
{
	static int	ascii = 0;
	static int	byte = 0;

	(void)unsd;
	(void)siginfo;
	if (signum == SIGUSR1)
		ascii += 1 << (7 - byte);
	++byte;
	if (byte == 8)
	{
		write (1, &ascii, 1);
		byte = 0;
		ascii = 0;
	}
}

int	main(void)
{
	struct sigaction	sig;

	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = ft_handler;
	write(1, "Start server PID:\n", 13);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	if (sigaction(SIGUSR1, &sig, 0) == -1)
		ft_error("Error signal\n");
	if (sigaction(SIGUSR2, &sig, 0) == -1)
		ft_error("Error signal\n");
	while (1)
		pause();
	return (0);
}
