/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaboya <algaboya@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 20:46:57 by algaboya          #+#    #+#             */
/*   Updated: 2024/07/16 16:57:53 by algaboya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
}

static long	ft_abs(long n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

void	ft_putnbr(int n)
{
	int		i;
	long	nbr;
	char	buf[10];

	if (n == 0)
	{
		write (1, "0", 1);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
	}
	nbr = ft_abs(n);
	i = 10;
	while (nbr != 0 && i > 0)
	{
		i--;
		buf[i] = nbr % 10 + '0';
		nbr /= 10;
	}
	write(1, &buf[i], 10 - i);
}

void	btoa(int signal, siginfo_t *info, void *context)
{
	static int	bit;
	static int	i;

	(void)info;
	(void)context;
	if (signal == SIGUSR1)
		i |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		write(1, &i, 1);
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	action;

	(void)argv;
	if (argc > 1)
	{
		ft_putstr("Error\n");
		return (1);
	}
	ft_putstr("PID > ");
	ft_putnbr(getpid());
	ft_putstr("\n");
	action.sa_sigaction = btoa;
	while (argc == 1)
	{
		sigaction(SIGUSR1, &action, NULL);
		sigaction(SIGUSR2, &action, NULL);
		pause ();
	}
	return (0);
}
