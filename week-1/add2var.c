/*Exercise 1:
Write a program to add two variables of any data type using references and/or
pointers.*/

#include<stdio.h>
// the program is written with 'integer' data type

int main(){
	int a = 2, b = 5, sum;
	int *p, *q;
	p = &a;
	q = &b;
	sum = *p + *q;
	printf("%d", sum);
}
