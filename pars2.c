/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:12:05 by mteffahi          #+#    #+#             */
/*   Updated: 2025/05/16 17:21:31 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    invalid_sqnc(char *input)
{
    int size;

    size = ft_strlen(input) - 1;
    if (input[0] == '|' || input[size] == '|')
        ft_putstr_fd("syntax error near unexpected token\n", 2);
}
