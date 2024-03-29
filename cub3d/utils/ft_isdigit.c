/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:37:49 by azaghlou          #+#    #+#             */
/*   Updated: 2023/09/01 15:06:33 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int     ft_isdigit(int c)
{
        if (c <= '9' && c >= '0')
                return (1);
        return (0);
}
