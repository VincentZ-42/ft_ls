/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 11:14:51 by vzhao             #+#    #+#             */
/*   Updated: 2019/08/28 17:14:51 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"

/*
** Add system("leaks testing");
** to check for leaks;
*/

int			main(void)
{
	char	*ex1;
	char	*ex2;

	ex1 = ft_strdup("Hello my name is Vincent");
	ex2 = ft_strdup("I really hope this workds");
	ft_printf("ex1 = %s\nex2 = %s\n", ex1, ex2);
	ft_strsdel(2, &ex1, &ex2);
	ft_printf("ex1 = %s\nex2 = %s\n", ex1, ex2);
	return (0);
}
