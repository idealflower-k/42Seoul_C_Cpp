#include "tensor.h"

t_vec3	vec3_init(double x, double y, double z)
{
	const t_vec3	vec3 = {x, y, z};

	return (vec3);
}

t_vec4	vec4_init(double x, double y, double z, double w)
{
	const t_vec4	vec4 = {x, y, z, w};

	return (vec4);
}
