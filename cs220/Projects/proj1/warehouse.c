#include "order.h"
#include "bench.h"
#include <stdio.h>
#include <stdbool.h>

int leastPopular(int [], int[]);/*takes two arrays. One array is of the most popular slots, and the other is an array of recent slots. The old ones go in the front
																	and the new ones go in the back.*/
int arrMoveSlot(int [], int);/*moves the newly used slots index to the back of this array and then exlcudes the last three entries and then calculates the last two
															and determines which array was used the least*/
int main(int argc, char **argv) {
	if (argc<2) {
		printf("Please invoke as %s <order_file>\n",argv[0]);
		return 1;
	}
	if (!openOrder(argv[1])) {
		return 1;
	}
	/* Counters for all 5 slots (to determine statistics of popularity)*/
	int s0 = 0;
	int s1 = 0;
	int s2 = 0;
	int s3 = 0;
	int s4 = 0;
/*Array to hold popularity of slots in their respective position...(i.e slot 0 == arr[0])*/
	int arr[5] ;//= {s0,s1,s2,s3,s4};
	/*Array to hold recent pickings(end of the array means new, and front means old.)*/
	int arrOrderedUsed[5]={-1,-1,-1,-1,-1};
	int leastUsedSlot = -1;
	do {
		int pn=nextPartNumber();	// will give you next part number that ranges 0-999
		int bin=pn/10; //this will give you a bin from 0-99....(Note: int math)

		if (binInSlot(0) != bin && s0 == 0){	//The if statements that check for a specific bin inside their slots get initialized to their respective slot.
			 s0 ++;	//increments the slot counter (how many times have i used it. )
			 arr[0] = s0;	//inserts the popularity counter in index 0
			 fetchBin(bin, 0);	//fetches the bin from slot zero.
			 arrOrderedUsed[0] = 0;	//the array to contain the slot positions respective to each iteration of the while loop.
			 //assigns the return value to the end of
 			arrOrderedUsed[4] = arrMoveSlot(arrOrderedUsed, 0);
		 }
		 else if (binInSlot(0) == bin){	//if we have the bin, then execute
			 s0++;
			 arr[0] = s0;
			 //we will loop until we find the zero slot in the array (integer 0 is saved at some element)
			//assign the new slot number to the end (in this case it is zero)
			 arrOrderedUsed[4] = arrMoveSlot(arrOrderedUsed, 0);
			}

///////////*REPEAT*///////////////////////////////////
		else if (binInSlot(1) !=bin && s1 == 0){
 			s1++;
			arr[1] = s1;
		  fetchBin(bin, 1);
			arrOrderedUsed[1] = 1;
			arrOrderedUsed[4] = arrMoveSlot(arrOrderedUsed, 1);
		}
		else if (binInSlot(1) == bin){
 		  s1 ++;
			arr[1] = s1;
			arrOrderedUsed[4] = arrMoveSlot(arrOrderedUsed, 1);
		}
		/////////////////////////////////////////
		else if (binInSlot(2) != bin && s2 == 0){
			s2 ++;
			arr[2] = s2;
			fetchBin(bin, 2);
			arrOrderedUsed[2] = 2;
 			arrOrderedUsed[4] = arrMoveSlot(arrOrderedUsed, 2);
		 }
		 else if (binInSlot(2) == bin){
 		  s2 ++;
 			arr[2] = s2;
			arrOrderedUsed[4] = arrMoveSlot(arrOrderedUsed, 2);
 		}
		//////////////////////////////////////
		else if (binInSlot(3) !=bin && s3 == 0){
			s3++;
			arr[3] = s3;
			fetchBin(bin, 3);
			arrOrderedUsed[0] = 3;
			arrOrderedUsed[4] = arrMoveSlot(arrOrderedUsed, 3);
		}
		else if (binInSlot(3) == bin){
 			s3++;
			arr[3] = s3;
			arrOrderedUsed[4] = arrMoveSlot(arrOrderedUsed, 3); // newly used in the end
		}
		////////////////////////////////////////////
		else if (binInSlot(4) !=bin && s4 == 0) {
 			s4++;
			arr[4] = s4;
			fetchBin(bin, 4);
		  arrOrderedUsed[0] = 4;
			arrOrderedUsed[4] = arrMoveSlot(arrOrderedUsed, 4);
		}
		else if (binInSlot(4) == bin){
			s4++;
			arr[4] = s4;
			arrOrderedUsed[4] = arrMoveSlot(arrOrderedUsed, 4);
		}
		/*If all slots are full then we send the array into a function which takes the array of popularity, the last bin slot used and the slot activity array*/
		else{
				leastUsedSlot = leastPopular(arr, arrOrderedUsed);
				if(leastUsedSlot == 0) {s0 = 0; s0++;}	//if the leastUsedSlot is slot 0, then we reset the counter due to it being sent back
				else if(leastUsedSlot == 1) {s1 = 0; s1++;}	//if the leastUsedSlot is slot 1, then we reset the counter then we reset the counter due to it being sent back
				else if(leastUsedSlot == 2) {s2 = 0; s2++;}	//if the leastUsedSlot is slot 2, then we reset the counter then we reset the counter due to it being sent back
				else if(leastUsedSlot == 3) {s3 = 0; s3++;}	//if the leastUsedSlot is slot 3, then we reset the counter then we reset the counter due to it being sent back
				else if(leastUsedSlot == 4) {s4 = 0; s4++;}	//if the leastUsedSlot is slot 4, then we reset the counter then we reset the counter due to it being sent back
				//gets the bin with the least used slot determined by my algorithm
				fetchBin(bin, leastUsedSlot);
				arrOrderedUsed[4] = arrMoveSlot(arrOrderedUsed, leastUsedSlot);
		}
} while(fetchNextPart()); //will put current part into the kit if it doesnt belong there then halts
	closeOrder();
	return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
int leastPopular(int arr [], int arrOrderedUsed[]){
//making a copy array of original array so we dont mess with the original by accident.
int arrCopy[5] = {arr[0], arr[1], arr[2], arr[3], arr[4]};

/*Looping through and as soon as i is equal to lastUsedSlot, then it will overwrite that element
	to exclude the last 3 slots used from the calculations due to there being a possibility of future use of this bin.*/
int i;
for(i=0; i < 5; i++)
{
	if(i == arrOrderedUsed[4]) break;	//the lastUsedSlot (could have used arrOrderedUsed[4])
}

if(i < 5)	//making sure we found something
{
	for(int j = i; j < 4; j++)
	{
		 arrCopy[j] = arrCopy[j+1];	//transfer and overwrite to previous element
	 }
}

for(i=0; i < 5; i++)
	{
	 	if(i == arrOrderedUsed[2]) break;	//exclude
	}

if(i < 4)
{
	 	for(int j = i; j < 3; j++)
		{
	 		 arrCopy[j] = arrCopy[j+1];
	 	}
}

for(i=0; i < 5; i++)
	{
		 if(i == arrOrderedUsed[3]) break;	//exclude
	}
if(i < 3)
{
	for(int j = i; j < 2; j++)
		{
		 	arrCopy[j] = arrCopy[j+1];
		}
}

//determening what the least popular slot was. (note that size is 2 due to the exlusion of slots used)
int minValue = arrCopy[0];
int minSlot = 0;
int z;
	for ( z =0; z < 2; z++)
	{
			if (arrCopy[z] < minValue)	//determining the minimum counter
			{
				minValue = arrCopy[z];
				minSlot = z;	//assigning least used slot (index)
			}
		}

/*due to the size difference (2 vs 5) we have to make sure the index matches up with the original (slot)
for example: if i have an array 1,2,4,5 and i want to exclude 1,4 then now i have 2,5........2 is less than 5 so according to this new array its index 0, but
if we return index zero, we are now reffering to the original arrays index which has an element 1 opposed to the 2 we where looking for*/
		for(int j = 0; j< 5; j++)
		{
			if (minValue == arr[j])
				{
					minSlot = j;
					break;
				}
		}
return minSlot;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
int arrMoveSlot(int arrOrderedUsed[], int slot){
	int i;
	int temp;
	for(i = 0; i < 5; i++)
 {
	 if(arrOrderedUsed[i] == slot){
		 temp = arrOrderedUsed[i]; //slot num
		break;
	}
}

for(int j=i; j < 4; j++)
{
	arrOrderedUsed[j] = arrOrderedUsed[j+1];
}
return temp;
}
