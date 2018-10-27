/*Exercise2:
Write a program to calculate the sum of an array of n elements declared with any
data type using references and/or pointers.*/

#include<stdio.h>
// the program is written with 'integer' data type

int main(){
	int n, i;
	printf("Enter the value n: ");
	scanf("%d", &n);
	int arr[100];
	for(i=0;i<n;i=i+1){
		int a = 0;
		printf("Enter a number in the array: ");
		scanf("%d", &a);
		arr[i] = a;
	};
	int *p = arr;
	
	int sum, k;
	for(k=0;k<n;k++){sum = sum + *(p + k);}
	printf("%d\n", sum); 
}
