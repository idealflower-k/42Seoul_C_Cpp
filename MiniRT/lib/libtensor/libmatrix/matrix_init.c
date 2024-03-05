#include "tensor.h"

t_mat3	mat3_init(t_vec3 a, t_vec3 b, t_vec3 c)
{
	const t_mat3	mat3 = {a, b, c};

	return (mat3);
}
