/*Exercise 1:
Write a program in C/C++ that uses only addition, subtraction, and comparison
to multiply two numbers using recursion.*/

#include<stdio.h>

int mult(int x, int y){ // idea: x+x+x+...+x (y times)
	if(x==0 || y==0) return 0;
	if(y==1) return x;
	return mult(x, y-1) + x; // Recursive call
}

int main(){
	printf("This is the program multiply 2 integers\n");
	int x, y;
	printf("Enter the value of x: ");
	scanf("%d", &x);
	printf("Enter the value of y: ");
	scanf("%d", &y);
	printf("%d * %d = %d\n",x,y,mult(x,y));
}
