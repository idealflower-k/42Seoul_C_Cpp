#include "tensor.h"

t_vec4	vec4_plus(t_vec4 a, t_vec4 b)
{
	return (vec4_init(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w));
}

t_vec4	vec4_scalar_multi(t_vec4 vec4, double scalar)
{
	return (vec4_init(
			vec4.x * scalar,
			vec4.y * scalar,
			vec4.z * scalar,
			vec4.w * scalar));
}
