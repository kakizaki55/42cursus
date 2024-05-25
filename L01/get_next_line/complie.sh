#bin/bash

# cc main.c get_next_line.c get_next_line_utils.c get_next_line.h
cc main.c get_next_line.c get_next_line_utils.c get_next_line.h -D BUFFER_SIZE=10
# cc main.c get_next_line.c get_next_line_utils.c get_next_line.h -D BUFFER_SIZE=10 -g -fsanitize=address