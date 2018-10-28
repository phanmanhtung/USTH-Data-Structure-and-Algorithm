/*Exercise 1:
In this problem, we would like to implement a variation of the Bubble Sort algorithm.
The algorithm differs from a bubble sort in that it sorts in both directions on each
pass through the list. The algorithm is illustrated as in the following figure:
• For the first step, we perform bubble sort from the index 1 to n (n is the
number of elements in the array).
• The next step, we perform a reserved bubble sort from the index n to 1.
• The process is repeated until all the array is sorted.
Implement and test this algorithm in C/C++. Analyze and compute the complexity
of this algorithm in the best, average and worst scenarios.*/

#include<stdio.h>

void swap(int *x, int *y){
   int c;
   c=*x; *x=*y; *y=c;
}

void Print(int *list, int n){
   int i;
   for(i = 0; i<n; i++){ printf("%d ", list[i]); }
   printf("\n");
}

void bubblesort(int *list, int n){
   int pass = 0; // printing reason
   int k = 1; // reduce number of comparisions -> decrease time complexity
   int flag = 0; // checking to get out of the loop
   while(flag==0){
	int i;
	for(i=k-1; i<n-k; i++){
	   if(list[i]>list[i+1]){ swap(&list[i], &list[i+1]); flag = 1; }
	}

	if(flag == 0) break; // there is no swap -> we are done!

	pass++;
	printf("Pass %d: ", pass);
	Print(list, n);
	
	for(i=n-k-1; i>=k-1; i--){
	   if(list[i]>list[i+1]){ swap(&list[i], &list[i+1]); flag = 1; }
	}
	pass++;
	printf("Pass %d: ", pass);
	Print(list, n);

	k++;
	flag = 0; // reset flag for the next round
   }
}

int main(){
   int A[8] = {99,55,44,22,66,88,33,11};
   printf("Input list: ");
   Print(A, 8);
   bubblesort(A, 8);
}


/* Both space and time complexity are the same as that of the normal bubble sort:
- Time complexity: Best Case O(n); Worst Case O(n^2); Average Case O(n^2)
- Space complexity: In-place sorting O(1)
*/
