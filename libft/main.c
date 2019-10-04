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

int		main(void)
{
	char *ex1 = ft_strdup("Hello my name is Vincent");
	char *ex2 = ft_strdup("I really hope this workds");

	ft_printf("ex1 = %s\nex2 = %s\n", ex1, ex2);
	ft_strsdel(2, &ex1, &ex2);
	ft_printf("ex1 = %s\nex2 = %s\n", ex1, ex2);
//	system("leaks testing");
	return (0);
}
