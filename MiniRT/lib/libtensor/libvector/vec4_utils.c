#include "tensor.h"

t_vec3	vec4_to_vec3(t_vec4 from)
{
	return (vec3_init(from.x, from.y, from.z));
}
