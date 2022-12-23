// void	draw(t_img *img, t_coord *coord0, t_coord * coord1)
// {
// 	t_draw	draw;
// 	int		x[2];
// 	int		y[2];
// 	int		e2;

// 	x[0] = x0;
// 	y[0] = y0;
// 	x[1] = x1;
// 	y[1] = y1;
// 	draw.dx = abs(x1 - x0);
// 	draw.dy = -abs(y1 - y0);
// 	draw.error = draw.dx + draw.dy;
// 	draw.sx = -1;
// 	draw.sy = -1;
// 	if (x1 > x0)
// 		draw.sx = 1;
// 	if (y1 > y0)
// 		draw.sy = 1;
// 	while (1)
// 	{
// 		my_mlx_pixel_put(img, x[0], y[0], 0x000FF000);
// 		if (x[0] == x[1] && y[0] == y[1])
// 			break ;
// 		e2 = 2 * draw.error;
// 		if (e2 >= draw.dy)
// 		{
// 			if (x[0] == x[1])
// 				break ;
// 			draw.error += draw.dy;
// 			x[0] += draw.sx;
// 		}
// 		else if (e2 <= draw.dx)
// 		{
// 			if (y[0] == y[1])
// 				break ;
// 			draw.error += draw.dx;
// 			y[0] += draw.sy;
// 		}
// 	}
// }
