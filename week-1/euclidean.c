/*Exercise 3:
Define a structure Point to describe a coordinate point (x,y). Write a program to
compute the Euclidean distance between two Points.*/

#include<stdio.h>
#include<math.h>

struct Point { float x, y; };

float euclidean(struct Point A, struct Point B){
	return sqrt(pow((A.x - B.x), 2) + pow((A.y - B.y), 2));
};

int main(){ 
	struct Point p1 = {1, 0};
	struct Point p2 = {0, 4};
	printf("%.2f", euclidean(p1, p2));
}

// reference to math.h
// gcc 1-3.c -o test -lm
	
