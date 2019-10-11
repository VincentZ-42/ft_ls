/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 13:28:23 by vzhao             #+#    #+#             */
/*   Updated: 2019/08/23 16:50:58 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const t_types		g_dispatch_table[TYPE_NUM] =
{
	{'%', mod_funct},
	{'c', c_funct},
	{'s', s_funct},
	{'p', p_funct},
	{'d', id_funct},
	{'i', id_funct},
	{'u', u_funct},
	{'o', o_funct},
	{'x', x_funct},
	{'X', bigx_funct},
	{'f', f_funct},
	{'b', b_funct},
	{'U', bigu_funct},
	{'O', bigo_funct}
};
