
#include <fdf.h>

void print_img(t_data img)
{
	ft_printf("bits per pixel is: %d\n", img.bits_per_pixel);
	ft_printf("line length: %d\n", img.line_length);
	ft_printf("img: %p\n", img.img);
	ft_printf("addr: %p\n", img.addr);
}