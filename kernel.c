#include "console.h"
#include "keyboard.h"
const char prompt[]="shell>";
void main(void) 
{
	unsigned char byte;
	clear_terminal();
	print_line(" ");
	print_string_with_color(prompt,BLACK,LIGHT_CYAN);
	print_string("cursor position:");
	print_integer(get_cursor_position());
	print_character('\n');
        while (1) {
        update_cursor();
                while (byte = scan()) {

                        print_character(charmap[byte]);
                }
        }
	return;
}
