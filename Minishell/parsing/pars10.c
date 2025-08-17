/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars10.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 18:02:01 by mteffahi          #+#    #+#             */
/*   Updated: 2025/08/17 18:50:46 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/exec.h"

static int	calculate_num_len(int n)
{
	int	len;

	len = (n <= 0);
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	fill_number_string(char *str, long nb, int len)
{
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		str[--len] = (nb % 10) + '0';
		nb /= 10;
	}
}

char	*ft_itoa1(t_ptr **head, int n)
{
	char	*str;
	long	nb;
	int		len;

	nb = n;
	len = calculate_num_len(n);
	str = ft_mall(head, len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	fill_number_string(str, nb, len);
	return (str);
}

char	*gt_nm(char *input, int *i, t_ptr **head)
{
	int		pos;
	int		len;
	char	*v_name;

	pos = *i;
	len = 0;
	while (input[pos] && ft_isalnum(input[pos]))
	{
		pos++;
		len++;
	}
	v_name = ft_mall(head, (len + 1));
	pos = 0;
	while (input[*i] && ft_isalnum(input[*i]) && pos < len)
	{
		v_name[pos] = input[*i];
		pos++;
		(*i)++;
	}
	v_name[len] = '\0';
	return (v_name);
}

int	ft_strcmp_vr(char *env_var, char *name, size_t name_len)
{
	size_t	i;

	if (!env_var || !name)
		return (-1);
	i = 0;
	while (i < name_len && env_var[i] && name[i] && env_var[i] != '=')
	{
		if (env_var[i] != name[i])
			return (env_var[i] - name[i]);
		i++;
	}
	if (i == name_len && (env_var[i] == '=' || env_var[i] == '\0')
		&& name[i] == '\0')
		return (0);
	return (1);
}
