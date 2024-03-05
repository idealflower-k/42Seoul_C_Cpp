#ifndef LIGHT_H
# define LIGHT_H

// phong_lighting.c
t_rgb	phong_lighting(t_meta *meta, t_record *record, const t_ray *ray);

// lighting_utils.c
t_vec3	reflect(t_vec3 a, t_vec3 b);
bool	in_shadow(t_obj *objs, t_record *_record, t_vec3 light_dir,
			double light_len);

#endif
