
#include <fdf.h>

void print_img(t_vars img)
{
	ft_printf("bits per pixel is: %d\n", img.bits_per_pixel);
	ft_printf("line length: %d\n", img.line_length);
	ft_printf("img: %p\n", img.img);
	ft_printf("addr: %p\n", img.addr);
}

void print_matrix(int **matrix, int col, int row)
{
	int i;
	int j;

	i = 0;
	j = 0;
    while (i < col) {
        ft_printf("i[%d] ", i);

        while(j < row)
		{
			ft_printf("%d\n[%d]", j, matrix[i][j]);
			j++;
        }
        ft_printf("\n");
		i++;
    }
}

void	free_all(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int color_hex(int t, unsigned r, unsigned int g, unsigned int b)
{
	int color;
	color = 0x000000;
	if(r > 256 || g > 256 || b > 256)
		return (0x000000);
	return (t << 24 | r << 16 | g << 8 | b);
}
int get_color(int z_value)
{
	int color;
	int r;
	int g;
	int b;

	if(z_value < 0)
		z_value *= -1;

	r = 0;
	g = 0;
	b = 0;

	z_value *= 10;
    z_value = z_value % 1530;  // Ensure z_value wraps around
    if (z_value < 255) {
        r = z_value;
        g = 200;
        b = 0;
    } else if (z_value < 510) {
        r = 255;
        g = 510 - z_value;
        b = 0;
    } else if (z_value < 765) {
        r = 255;
        g = 0;
        b = z_value - 510;
    } else if (z_value < 1020) {
        r = 1020 - z_value;
        g = 0;
        b = 255;
    } else if (z_value < 1275) {
        r = 0;
        g = z_value - 1020;
        b = 255;
    } else {
        r = 0;
        g = 255;
        b = 1530 - z_value;
    }

	// color = 0x00000000;

	// if(z_value > 0)
	// {
	// 	return (0x00FFCC66 + (z_value * 100));
	// } else if (z_value < 0)
	// {
	// 	return (0x00FFFF00 + (z_value * -100));
	// }

	color = color_hex(100, r, g, b);
	return (color);
}


int str_arr_length(char **array)
{
	int i;

	if(array == NULL || *array == NULL)
		return (0);

	i = 0;
	while(array[i])
	{
		i++;
	}
	return (i);
}

int int_arr_length(int *array)
{
	int i;

	if(array == NULL)
		return (0);

	i = 0;
	while(array[i])
	{
		i++;
	}
	return (i);
}