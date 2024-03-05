#include "defs_bonus.h"
#include "minirt_bonus.h"

double	clamp(const double x, const double min, const double max)
{
	if (x < min)
		return (min);
	else if (x > max)
		return (max);
	else
		return (x);
}

float	float_modulo(const float x)
{
	return (x - floorf(x));
}
