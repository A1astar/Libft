/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dynarray_push.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alacroix <alacroix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:36:10 by alacroix          #+#    #+#             */
/*   Updated: 2025/03/01 18:46:33 by alacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_dynarray_push(t_dinnaray *arr, void *elem)
{
	void *new_data;

	new_data = NULL;
	if(arr->len >= arr->capacity)
	{
		new_data = malloc(arr->element_size * arr->capacity * 2);
		if(!new_data)
			return (-1);
		ft_memcpy(new_data, arr->data, arr->capacity * arr->len);
		free(arr->data);
		arr->data = new_data;
		arr->capacity *= 2;
	}
	ft_memcpy((char *)arr->data + (arr->len * arr->element_size), elem, arr->element_size);
	arr->len++;
	return (0);
}
