#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#define LENGTH 5
#define CHAR_A  65

char* stack();
bool push(char* buffer, char sig_in);
char  pop(char* buffer);
bool full(char* buffer);
bool empty(char* buffer);
void print_buffer(char* buffer);
void freeStack(char* buffer);

int main() {

	//Define One-Array Integer Stack
	static char* buffer = stack();
	if (buffer == NULL) {
		fprintf(stderr, "Memory allocation error\n");
		exit(EXIT_FAILURE);
	}

	print_buffer(buffer);

	//Push One Element to Stack
	bool sig = push(buffer, 'A');
	if (!sig) {
		printf("ERROR");
	}

	//Print Stack
	print_buffer(buffer);

	//Pop One Element from Stack
	pop(buffer);

	//Print Stack
	print_buffer(buffer);

	//Push Element until Stack is full
	for(int i = CHAR_A; i <= CHAR_A + LENGTH; ++i) {
		sig = push(buffer, char(i));
		print_buffer(buffer);
		
	}

	//Pop Element until Stack is Empty
	for (int i = CHAR_A + LENGTH; i >= CHAR_A; --i) {
		char temp = pop(buffer);

		print_buffer(buffer);

	}


	//Free Stack Memory
	freeStack(buffer);


}

void print_buffer(char* buffer) {

	printf("STACK: [ ");
	for (int i = 0; i < LENGTH; i++) {

		printf("%c ", *(buffer + i));
	}
	printf(" ] \n");
}


void freeStack(char* buffer) {
	free(buffer);
}

char* stack() {

	char* buffer = (char*)calloc(LENGTH, sizeof(char));
	char temp = '0';
	memset(buffer,temp , LENGTH * sizeof(char));

	return buffer;

}

bool push(char* buffer, char sig_in) {


	int i = 0;
	if (full(buffer)) {
		return false;
	}
	else {

		while (buffer[i] != '0') {
			++i;
		}

		*(buffer + i) = sig_in;

		printf("PUSH: %c\n", sig_in);

		return true;

	}


}

char pop(char* buffer) {

	int i = 0;

	if (empty(buffer)) {
		return -1;
	}
	else {
		while (*(buffer + i) != '0')
		{
			++i;
			if (i >= LENGTH) {
				i = LENGTH;
				break;
			}

		}
	}

	char temp = *(buffer + (i - 1));

	*(buffer + (i - 1)) = '0';
	printf("POP: %c \n", (char)temp);

	return temp;

}

bool full(char* buffer) {

	if (buffer[LENGTH - 1] != '0') {
		printf("Stack is Full\n");
		return true;
	}
	else {
		return false;
	}

}

bool empty(char* buffer) {
	if (*(buffer + 0) == '0') {
		printf("Stack is Empty\n");
		return true;
	}
	else {
		return false;
	}
}