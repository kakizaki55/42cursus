
#include <fdf.h>

void print_img(t_data img)
{
	ft_printf("bits per pixel is: %d\n", img.bits_per_pixel);
	ft_printf("line length: %d\n", img.line_length);
	ft_printf("img: %p\n", img.img);
	ft_printf("addr: %p\n", img.addr);
}

//make sure i need to delet change this in to a while loop

void print_matrix(int **matrix, int rows, int cols)
{
    int i, j;

    for (i = 0; i < rows; i++) {
        printf("[%d] ", i);

        for (j = 0; j < cols; j++) {
				printf("[%d]", matrix[i][j]);
        }
        printf("\n");
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