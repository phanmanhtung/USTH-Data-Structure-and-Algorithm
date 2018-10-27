/*Exercise 4:
Use the structure Point defined in the previous exercise to define a Rectangle. A
rectangle can be determined by two points P1(x 1 , y 1 ) and P2(x 2 , y 2 ) as in the fol-
lowing figure:
Write a function to verify whether a rectangle can be constructed from the two given
points. If we cannot construct a rectangle, re-enter new two points. If we can get a
rectangle, calculate its area.
Write a function that returns 1 if a point falls within a rectangle, 0 otherwise.*/

#include<stdio.h>
#include<math.h>

struct Point { float x, y; };
float euclidean(struct Point A, struct Point B){
	return sqrt(pow((A.x - B.x), 2) + pow((A.y - B.y), 2));
};

int isReg(struct Point A, struct Point B){
	if(A.x == B.x || A.y == B.y){ return 0; }
	else{ return 1; };
}

int main(){ 
	
	struct Point p1 = {0, 0};
	struct Point p2 = {0, 0};
	
	printf("Enter x and y value for point 1: ");
	scanf("%f", &p1.x);
	scanf("%f", &p1.y);
		
	printf("Enter x and y value for point 2: ");
	scanf("%f", &p2.x);
	scanf("%f", &p2.y);

	while (isReg(p1, p2) != 1){
		printf("There is no rectangle, please enter again\n");
		printf("Enter x and y value for point 1:");
		scanf("%f", &p1.x);
		scanf("%f", &p1.y);
		
		printf("Enter x and y value for point 2:");
		scanf("%f", &p2.x);
		scanf("%f", &p2.y);
	};
	
	struct Point pa = {p1.x, p2.y};
	printf("The Area : %.2f\n", euclidean(p1, pa) * euclidean(pa, p2));
}

// p1(x1,y1) p2(x2, y2) p1'(x1, y2) p2'(x2, y1)
