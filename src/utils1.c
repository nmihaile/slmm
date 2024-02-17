
#include "../include/slmm.h"

int	is_wall(char c)
{
	if (c == '1')
		return (TRUE);
	return (FALSE);
}

int	has_moved(t_vec2 p1, t_vec2 p2)
{
	if (p1.x != p2.x || p1.y != p2.y)
		return (1);
	return (0);
}

int	is_valid_tile_coordinate(t_vec2 pos, t_ad *ad)
{
	if (pos.x >= 0 && pos.x < ad->map.width && pos.y >= 0 && pos.y < ad->map.height)
		return (1);
	return (0);
}

void	ft_freejoin(char **s1, char *s2)
{
	char	*buf;

	buf = ft_strjoin(*s1, s2);
	free(*s1);
	free(s2);
	*s1 = buf;
}
