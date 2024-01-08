#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int** stack( int n, int m);
void printStack(int** buffer, int n, int m);
void freeStack(int** _buffer, int n, int m);
int pop(int** _buffer, int n, int m);
bool push(int** _buffer, int n, int m, int sig);
bool full(int** _buffer, int n, int m);
bool empty(int** _buffer);


int main() {

	int n, m;

    //Insert N x M Array
	scanf("%d %d", &n, &m);

    //Stack Pointer
	int** buffer;

    //Make 2D Integer Stack
	buffer=stack(n, m);	

    //Print Deafult Condition of 2D Stack
    printStack(buffer,n,m);

    //Push Value to Stack
   
    for (int i = 0; i <= n*m; i++) {
        push(buffer, n, m, i * 10);
        printStack(buffer, n, m);
    }

    //POP Value from Stack

    for (int i = n * m; i >= 0; --i) {
        pop(buffer, n, m);
        printStack(buffer,n,m);
    }
  

    freeStack(buffer,n,m);

}

int** stack(int n, int m) {
    int** buffer = (int**)calloc(n, sizeof(int*));

    for (int i = 0; i < n; ++i) {
        buffer[i] = (int*)calloc(m, sizeof(int));
        memset(buffer[i], -1, m * sizeof(int));
    }

    return buffer;
}

void freeStack(int** _buffer, int n, int m) {
    for (int i = 0; i < n; ++i) {
        free(_buffer[i]);
    }

    free(_buffer);
}

void printStack(int** _buffer, int n, int m) {

    printf("########Stack#########\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%d ", _buffer[i][j]);
        }
        printf("\n");
    }
    
}

bool push(int** _buffer, int n , int m, int sig) {

    if (full(_buffer,n,m)) {
        return false;
    }
    else {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (_buffer[i][j] == -1) { _buffer[i][j] = sig; return true; }
            }
        }
    }


}


int pop(int** _buffer, int n, int m) {
  
    int temp=0;
    if (empty(_buffer)) {
       
        return temp;
    }
    else {
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (_buffer[i][j] == -1) {
                   
                    if (j == 0) {
                        temp = _buffer[i - 1][m-1];
                        _buffer[i - 1][m-1] = -1;
                    }
                    else {
                        
                        temp = _buffer[i][j - 1];
                        _buffer[i][j - 1] = -1;
                    }

                }
                else if (i == (n-1) && j == (m-1)) {
                   
                    temp = _buffer[i][j];
                    _buffer[i][j] = -1;
                }
            }
        }

        return temp;
    }
    
   
}





bool full(int** _buffer, int n, int m) {
    if (_buffer[n-1][m-1] != -1) {
        printf("Stack is Full\n");
        return true;
    }
    else {
        return false;
    }
}

bool empty(int** _buffer) {

    if (_buffer[0][0] == -1) {
        printf("Stack is Empty\n"); return true;
    }
    else {
        return false;
    }


}