/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbinti-m <dbinti-m@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 00:19:58 by dbinti-m          #+#    #+#             */
/*   Updated: 2025/11/06 00:20:19 by dbinti-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

/* Utils functions */
void	ft_putchar(char c);
void	ft_putnbr(int n);
void	ft_putstr(char *str);
void	ft_putstr_fd(char *str, int fd);

/* Conversion functions */
int		ft_atoi(const char *str);

#endif
