#ifndef CONSOLE_H
#define CONSOLE_H
static char* const VGA_BUFFER = (char*) 0xb8000;
#define VGA_WIDTH 80
#define VGA_HEIGHT 25
#define VGA_BYTES_PER_CHARACTER 2
void clear_terminal();
void print_character(char c);
void print_string(char* s);
void print_line(char* s);
#endif

