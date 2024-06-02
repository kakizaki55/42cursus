#bin/bash
# for complining regular
# cc main.c get_next_line.c get_next_line_utils.c get_next_line.h

# for compliring bonues
cc main.c get_next_line_bonus.c get_next_line_utils_bonus.c get_next_line_bonus.h -D BUFFER_SIZE=10
