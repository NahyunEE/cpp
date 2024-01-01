#include <stdio.h>
#include <memory.h>
#define LENGTH 20

int* stack();
bool push(int* buffer, int sig_in);
int  pop(int* buffer);
bool full(int* buffer);
bool empty(int* buffer);
void print_buffer(int* buffer);

int main() {

	static int* buffer = stack();

	for (int i = 0; i < 10; ++i) {
		bool sig = push(buffer, i);

		if (!sig) {
			printf("ERROR\n");
		}
		print_buffer(buffer);
	}


	for (int i = 0; i < 5; ++i) {
		pop(buffer);
		print_buffer(buffer);
	}


	

}

void print_buffer(int* buffer) {

	    printf("STACK: [ ");
		for (int i = 0; i < LENGTH; ++i) {
			if (buffer[i] != '\0') {
				printf("%d", buffer[i]);
			}
			else {
				printf(" ");
			}
			
		}
		printf(" ] \n");
}


int* stack(){
  
	int buffer[LENGTH];
    memset(buffer, '\0', LENGTH * sizeof(int));
    
	return buffer;

}

bool push(int* buffer, int sig_in) {

	int i = 0;
	while (buffer[i] != '\0') {
		
		if (i == (LENGTH - 1)) {
			return false;
		}
		++i;
	}

	buffer[i] = sig_in;
	printf("PUSH: %d \n", sig_in);

	return true;

}

int  pop(int* buffer) {

	size_t i = 0;
	while (buffer[i] != '\0')
	{
		++i;
	}
	
	size_t temp = buffer[i];
	buffer[i] = '\0';
	printf("POP: %d \n", (int)temp);
	
	return temp;

}

bool full(int *buffer) {

	if (buffer[LENGTH - 1] != '\0') {
		return true;
	}
	else {
		return false;
	}

}

bool empty(int* buffer) {
	if (buffer[0] == '\0') {
		return true;
	}
	else {
		return false;
	}
}







