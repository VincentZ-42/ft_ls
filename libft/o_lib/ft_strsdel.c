/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 11:10:36 by vzhao             #+#    #+#             */
/*   Updated: 2019/08/23 11:38:53 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strsdel(size_t nbr, ...)
{
	va_list ap;
	char **str;

	va_start(ap, nbr);
	while (nbr--)
	{
		str = va_arg(ap, char **);
		free(*str);
		*str = NULL;
	}
	va_end(ap);
}
