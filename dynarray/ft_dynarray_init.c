/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dynarray_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alacroix <alacroix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 15:05:58 by alacroix          #+#    #+#             */
/*   Updated: 2025/03/01 18:26:28 by alacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_dynarray_init(t_dinnaray *arr, size_t elem_size, size_t init_capacity)
{
	arr->data = malloc(elem_size * init_capacity);
	if(!arr->data)
		return (-1);
	arr->element_size = elem_size;
	arr->len = 0;
	arr->capacity = init_capacity;
	return (0);
}
