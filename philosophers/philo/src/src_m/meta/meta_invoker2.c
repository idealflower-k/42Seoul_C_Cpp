#include "philosophers.h"
#include "defines.h"
#include "meta.h"

void	set_err(t_err err)
{
	t_meta	*meta;

	meta = get_meta(0, NULL);
	meta->error = err;
}
