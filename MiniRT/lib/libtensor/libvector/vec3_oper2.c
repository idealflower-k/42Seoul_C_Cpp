#include "tensor.h"

t_vec3	vec3_scalar_divide(t_vec3 vec3, double scalar)
{
	return (vec3_init(
			vec3.x * (1.0 / scalar),
			vec3.y * (1.0 / scalar),
			vec3.z * (1.0 / scalar)));
}

t_vec3	vec3_scalar_multi(t_vec3 vec3, double scalar)
{
	return (vec3_init(vec3.x * scalar, vec3.y * scalar, vec3.z * scalar));
}

t_vec3	vec3_scalar_minus(t_vec3 vec3, double scalar)
{
	return (vec3_init(vec3.x - scalar, vec3.y - scalar, vec3.z - scalar));
}
