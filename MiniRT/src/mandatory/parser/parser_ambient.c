#include "parser.h"
#include "utils.h"
#include "design_patterns.h"

static inline bool	_vaildation_ambient(t_ambient amb)
{
	if (amb.type != AMB || !check_0_to_1(amb.ratio) || !check_rgb(&amb.rgb))
		return (false);
	return (true);
}

static inline void	_set_ambient_info(t_ambient *amb, char **line)
{
	amb->type = AMB;
	amb->ratio = check_to_double(line[1]);
	amb->rgb = parser_vec3(line[2], RGB_ERR);
}

void	parser_ambient(char **line)
{
	t_meta		*meta;
	t_ambient	amb;

	if (ft_arrlen((void **)line) != 3)
		error_handler(AMB_ERR);
	_set_ambient_info(&amb, line);
	meta = singleton();
	if (!_vaildation_ambient(amb) || meta->ambient.type == AMB)
	{
		ft_free_all_arr(line);
		error_handler(AMB_ERR);
	}
	meta->ambient = amb;
}
