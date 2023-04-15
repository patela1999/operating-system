#include "../include/console.h"
int terminal_position = 0;
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


