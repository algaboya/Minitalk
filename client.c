/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaboya <algaboya@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 20:41:02 by algaboya          #+#    #+#             */
/*   Updated: 2024/07/16 16:31:52 by algaboya         ###   ########.fr       */
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

int	ft_atoi(const char *str)
{
	int	i;
	int	j;
	int	val;

	j = 1;
	i = 0;
	val = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			j *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		val = val * 10 + (str[i] - '0');
		i++;
	}
	val *= j;
	return (val);
}

void	atob(int pid, char symb)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((symb & (1 << bit)))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(80);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			atob(pid, argv[2][i]);
			i++;
		}
		atob(pid, '\n');
	}
	else
	{
		ft_putstr("Error!\n");
		return (1);
	}
	return (0);
}
