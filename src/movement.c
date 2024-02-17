
#include "../include/slmm.h"

void	move_cursor(t_vec2 p, t_ad *ad)
{
	ad->cpos.x = p.x;
	ad->cpos.y = p.y;
	if (ad->cimg)
	{
		ad->cimg->instances[0].x = ad->cpos.x * TS;
		ad->cimg->instances[0].y = ad->cpos.y * TS;
	}
}
