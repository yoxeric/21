/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 00:33:39 by yhachami          #+#    #+#             */
/*   Updated: 2023/03/19 01:33:52 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "signal.h"
# include "stdlib.h"
# include "unistd.h"
# include "stdarg.h"

int		ft_power(int n, int x);
int		ft_strlen(const char *s);
int		ft_atoi(const char *str);
int		ft_printf(const char *s, ...);

#endif