/* ************************************************************************** */
/*	*/
/*	:::	  ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*	+:+ +:+	 +:+	 */
/*   By: averdejo <averdejo@student.42madrid.com>   +#+  +:+	   +#+	*/
/*	+#+#+#+#+#+   +#+	   */
/*   Created: 2023/03/20 17:00:13 by averdejo	  #+#	#+#	 */
/*   Updated: 2023/04/11 15:48:19 by averdejo         ###   ########.fr       */
/*	*/
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*tmp;

	tmp = malloc(count * size);
	if (!tmp)
		return (NULL);
	ft_bzero(tmp, count * size);
	return (tmp);
}
