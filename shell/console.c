#include "../include/console.h"
#include "portmap.h"
#include <stdint.h>
#include "string.h"


int terminal_position = 0;
char* const VGA_BUFFER = (char*) 0xb8000;

void update_cursor(int terminal_position)
{
              uint16_t cursor_position = terminal_position >> 1;
              outb(0x3D4, 0x0F);
              outb(0x3D5, (uint8_t) (cursor_position));
              outb(0x3D4, 0x0E);
              outb(0x3D5, (uint8_t) (cursor_position >> 8));
}

uint16_t get_cursor()
{ 
              uint16_t cursor_position = 0;
              outb(0x3D4, 0x0F);
              cursor_position |=inb(0x3D5);
              outb(0x3D4, 0x0E);
              cursor_position |= ((uint16_t)inb(0x3D5)) << 8;
              return cursor_position;
}

void clear_terminal(){
	for(int i=0; i<VGA_WIDTH*VGA_HEIGHT*VGA_BYTES_PER_CHARACTER; i+=2){
		VGA_BUFFER[i] = 0;
		VGA_BUFFER[i+1] = 0X07;
	}
}
void handle_newline_character(){
	terminal_position = terminal_position + 160 - (terminal_position % (VGA_WIDTH*VGA_BYTES_PER_CHARACTER));
}

void handle_special_character(char c){
	switch(c){
		case '\n':
		handle_newline_character();
		break;
		
	}
}
int is_special_character(char c) {
	if(c >= '0' && c <= '9'){
    		return  0;
	}else if(c >= 'A' && c <= 'Z'){
    		return  0;
    	}else if(c >= 'a' && c <= 'z'){
    		return  0;
    	}else{
    		return 1;
    	} 
}
void print_character(char c){
	if(is_special_character(c)){
		handle_special_character(c);
		return;	
	}
	VGA_BUFFER[terminal_position++] = c;
	VGA_BUFFER[terminal_position++] = 0X07;
}
void print_string(char* str){
	for(int i=0; str[i] != '\0'; i++){
		print_character(str[i]);
	}
}

void print_line(char* str){
	print_string(str);
	print_character('\n');
}
int len(int toPrint)
{
        if(toPrint == 0)
        	return 1;
        
        int num_digits =0;
        while (toPrint > 0)
        {
        	toPrint /=10;
        	num_digits ++;
        }
                
	return num_digits;
}


void strrev(char *arr, int start, int end)
{
      char temp;
      if(start >= end)
         return;
         temp = *(arr + start);
         *(arr + start) = *(arr + end);
         *(arr + end) = temp;
         start++;
         end--;
         strrev(arr,start,end);
}
char* itoa(int number, char *arr)
{
    int i = 0, r, negative = 0;
    if (number == 0)
    {
         arr[i] = '0';
         arr[i + 1] = '\0';
         return arr;
     }
     if(number < 0)
     {
           number *= -1;
           negative = 1;
     }
     
     while (number !=0)
     {
          r= number % 10;
          arr[i++] = r+48;
          number /= 10;
     }
     
     strrev(arr , 0 , i-1);
     arr[i] = '\0';
     return arr;
}
      
void print_integer(int toPrint)
{
      int l= len(toPrint);
      char buffer[l];
      buffer= itoa(toPrint, buffer);
      print_string(buffer);
}           


