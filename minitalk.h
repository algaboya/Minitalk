/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaboya <algaboya@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 12:39:19 by algaboya          #+#    #+#             */
/*   Updated: 2024/07/16 16:45:57 by algaboya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

int		ft_atoi(const char *str);
void	atob(int pid, char symb);
void	ft_putstr(char *s);
void	ft_putnbr(int n);
void	btoa(int signal, siginfo_t *info, void *context);

#endif