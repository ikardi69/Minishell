/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikardi <ikardi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:19:32 by mteffahi          #+#    #+#             */
/*   Updated: 2025/05/08 15:58:23 by ikardi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strdup(const char *s)
{
	size_t	size;
	char	*result;

	size = ft_strlen(s) + 1;
	result = (char *)malloc(size);
	if (!result)
		return (NULL);
	ft_memcpy(result, s, ft_strlen(s));
	result[ft_strlen(s)] = '\0';
	return (result);
}
