/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dynarray_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alacroix <alacroix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:48:12 by alacroix          #+#    #+#             */
/*   Updated: 2025/04/07 11:12:18 by alacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dynarray_free(t_dinnaray *arr)
{
	free(arr->data);
	arr->data = NULL;
	arr->len = 0;
	arr->capacity = 0;
}
