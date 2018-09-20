/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file Stats.c 
 * @brief Provide various printed stats of an array.
 *
 * The systems takes in an array and array size and will print out stats such 
 * as median, mean, minimum, maximum and print the array both unsorted and sorted. 
 *
 * @author Kaspar Jürgensen
 * @date 26/08/2018
 *
 */

void print_statistics(unsigned char * array, unsigned int arraySize);
void print_array(unsigned char * array, unsigned int arraySize);
char find_median(unsigned char * array, unsigned int arraySize);
char find_mean(unsigned char * array, unsigned int arraySize);
char find_min(unsigned char * array, unsigned int arraySize);
char find_max(unsigned char * array, unsigned int arraySize);
void * sort_array(unsigned char * array, unsigned int arraySize);

#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */

  /* Statistics and Printing Functions Go Here */
  print_statistics(test, SIZE);

}

void print_statistics(unsigned char * array, unsigned int arraySize){

	unsigned char min;
	unsigned char max;
	unsigned char mean;
	unsigned char median;

	// Print Inital Array
	print_array(array, arraySize);

  	// Print Median
	median = find_median(array,arraySize);
	printf("Median = %d\n\n",median);

	// Print Mean
	mean = find_mean(array,arraySize);
	printf("Mean = %d\n\n",mean);

	// Print Mean
	min = find_min(array,arraySize);
	printf("Minimum = %d\n\n",min);

	// Print Mean
	max = find_max(array,arraySize);
	printf("Maximum = %d\n\n",max);

	// Print Sorted Array
	printf("Sorted Array = ");

	for(int i = 0; i < arraySize; i++){
  		printf("%d ", array[i]);
  	}
  }

 void print_array(unsigned char * array, unsigned int arraySize){


 	printf("Initial array = ");

 	for(int i = 1; i <= arraySize-1; i++){
 		
 		printf("%d ",array[i]);
 	}

 	printf("\n\n");
 }

 char find_median(unsigned char * array, unsigned int arraySize){
 	
 	// Sort Array
	sort_array(array, arraySize);

	// Determine even or uneven array size
 	if(arraySize % 2 == 0){
 		return array[((arraySize/2)+(arraySize/2+1))/2];
 	} else {
 		return array[(arraySize+1)/2];
 	}
 }

 char find_mean(unsigned char * array, unsigned int arraySize){

 	int Sum = 0;

 	// Adding Sum
 	for(int i = 0; i < arraySize; i++){
 		Sum += array[i];
 	}

 	return Sum/arraySize;
 }

 char find_min(unsigned char * array, unsigned int arraySize){

 	char min = array[0];

 	for(int i = 0; i < arraySize-1; i++){

 		// Checks for minimum value in array
 		if(array[i] > array[i+1]){
 		 	min = array[i+1];
 		}
 	}
 	return min;
 }

 char find_max(unsigned char * array, unsigned int arraySize){

 	char max = array[0];

 	for(int i = 0; i < arraySize-1; i++){

 		// Checks for maximum value in array
 		if(array[i] < array[i+1]){
 		 	max = array[i+1];
 		}
 	}
 	return max;
 }

 void * sort_array(unsigned char * array, unsigned int arraySize){

 	if ( array == NULL){
    	return 0;
  	}

  	// Comparing all array indexes with highest found value 
  	for(int i = 0; i < arraySize; i++){
  		for(int j = i + 1; j < arraySize; j++){
  			
  			if(array[i] < array[j]){
  				char temporary = array[i];
  				array[i] = array[j];
  				array[j] = temporary;
  			}
  		}
  	}
 }

/* Add other Implementation File Code Here */
