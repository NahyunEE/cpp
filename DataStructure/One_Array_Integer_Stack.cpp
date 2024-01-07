#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#define LENGTH 5

int* stack();
bool push(int* buffer, int sig_in);
int  pop(int* buffer);
bool full(int* buffer);
bool empty(int* buffer);
void print_buffer(int* buffer);
void freeStack(int* buffer);

int main() {

	//Define One-Array Integer Stack
	static int* buffer = stack();
	if (buffer == NULL) {
		fprintf(stderr, "Memory allocation error\n");
		exit(EXIT_FAILURE);
	}


	//Push One Element to Stack
	bool sig =push(buffer, 1);
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
	for (int i = 0; i < LENGTH+1; ++i) {
		sig=push(buffer, i * 10);
		print_buffer(buffer);
		if (!sig) {
			printf("Stack is full\n");
		}
	}

	//Pop Element until Stack is Empty
	for (int i = LENGTH; i >=0; --i) {
		int temp = pop(buffer);
		
		print_buffer(buffer);
		
	}

	
	//Free Stack Memory
	freeStack(buffer);
	

}

void print_buffer(int* buffer) {

	    printf("STACK: [ ");
		for (int i = 0; i < LENGTH  ; i++) {
			
			printf("%d ",*(buffer+i));
		}
		printf(" ] \n");
}


void freeStack(int* buffer) {
	free(buffer);
}

int* stack(){
  
	int* buffer = (int*)calloc(LENGTH, sizeof(int));
    memset(buffer, -1, LENGTH * sizeof(int));
    
	return buffer;

}

bool push(int* buffer, int sig_in) {

	
	int i = 0;
	if (full(buffer)) {
		return false;
	}
	else {

		while (buffer[i] != -1) {
			++i;
		}

		*(buffer + i) = sig_in;
		
		printf("PUSH: %d\n", sig_in);

		return true;

	}


}

int  pop(int* buffer) {

	int i = 0;

	if (empty(buffer)) {
		return -1;
	}
	else {
		while (*(buffer + i) != -1)
		{
			++i;
			if (i >= LENGTH) {
				i = LENGTH;
				break;
			}

		}
	}
		
	int temp = *(buffer + (i-1));
	
	*(buffer + (i-1)) = -1;
	printf("POP: %d \n", (int)temp);
	
	return temp;

}

bool full(int *buffer) {

	if (buffer[LENGTH - 1] != -1) {
		return true;
	}
	else {
		return false;
	}

}

bool empty(int* buffer) {
	if (*(buffer+0)== -1) {
		printf("Stack is Empty\n");
		return true;
	}
	else {
		return false;
	}
}