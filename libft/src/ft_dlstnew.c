#include "libft.h"

t_dlist	*ft_dlstnew(const void *content, size_t content_size)
{
	t_dlist	*new;

	if (!content || !content_size)
		return (NULL);
	if (!(new = (t_dlist*)ft_memalloc(sizeof(*new))))
		return (NULL);
	if (!(new->content = ft_memalloc(content_size)))
	{
		free(new);
		return (NULL);
	}
	ft_memcpy(new->content, content, content_size);
	new->content_size = content_size;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
