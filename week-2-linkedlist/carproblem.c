/*Exercise 1: Assume that a railway train has N railroad cars attached together
such as: car 1 , car 2 , car 3 , ..., car N .
• Each car carries a number of passengers (int type) and has a name (char type).
Both variables are user-defined values.
• If there is any cars that don’t have any passengers, they should be removed
from the train.
• It is possible to add new cars into the train.
• A function is available to display all cars’ information or the length of the
train.*/

#include<stdio.h>
#include<stdlib.h> 
#include<string.h>

typedef struct car{
	char name[30]; 
	int passengers;
	struct car *nextStruct; }car;
 
car *frstPtr = NULL; 
car *lastPtr = NULL;

void Insert_car(int num, char * name){
	car *oneCar = (car *) malloc(sizeof(car));	
	strcpy(oneCar->name, name);
	oneCar->passengers = num;

	oneCar->nextStruct = NULL;

	if (frstPtr == NULL){	// add the car at the end
		frstPtr = oneCar;
	 	lastPtr = oneCar;}
	else{ lastPtr->nextStruct = oneCar; lastPtr = oneCar; } } 

// function to check whether there is any passenger in the car -> perform "Insert_car"
void add_car(){
	char name[30];
	int num;
	printf("Enter the name of the car: ");
	scanf("%s",name);
	printf("Enter the number of passengers of the car: ");
	scanf("%d", &num);
	if(num==0){;}	// no passenger -> not add
	else{Insert_car(num, name);}
}

void Display(){
	car* curCar = frstPtr;
	int count = 0; // count number of trains available
	// traverse the Linked List
	while(curCar != NULL){
		printf("Car '%s' has %d passengers\n", curCar->name, curCar->passengers);
		count = count + 1;
		// keep going to the next node
		curCar = curCar->nextStruct;
	}
	printf("There are %d cars on the train\n", count);
}

void main(){
	int i,n;
	printf("Enter the number of cars: ");
	scanf("%d", &n);
	for(i=0;i<n;i++){ add_car(); }
	Display();
	
	int next = 1;
	printf("Do you want to add more cars? (yes - 1, no - 0): ");
	scanf("%d",&next);
	while(next==1){
		add_car();
		printf("Do you want to add more cars? (yes - 1, no - 0): "); 
		scanf("%d",&next);
	} 
	
	Display();
}

