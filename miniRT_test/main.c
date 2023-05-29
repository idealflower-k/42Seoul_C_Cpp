#include <stdio.h>

int	main(void)
{
	int	i;
	int	j;
	double	r;
	double	g;
	double	b;
	int	canv_width;
	int	canv_height;

	canv_width = 500;
	canv_height = 500;

	printf("P3\n%d %d\n255\n", canv_width, canv_height);
	j = canv_height - 1;
	while (j >= 0)
	{
		i = 0;
		while (i <canv_width)
		{
			r = (double)i / (canv_width - 1);
			g = (double)j / (canv_height - 1);
			b = 0.25;
			printf("%d %d %d\n", (int)(255.999 * r), (int)(255.999 * g), (int)(255.999 *b));
			++i;
		}
		--j;
	}
	return (0);
}
