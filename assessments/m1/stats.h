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
 * @file Stats.h
 * @brief The stats header file declare the various functions in stats.c.
 *
 * The stats header file declare the various functions with thorough descriptions 
 * in stats.c and make them available to share with other subsystems.
 *
 * @author Kaspar Jürgensen
 * @date 26/08/2018
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/**
 * @brief Collects and print stats.
 *
 * Collects various stats from other functions and print them to the terminal.
 *
 * @param test An unsigned char array of 1 byte per index, which hold the numbers to create stats about.
 * @param SIZE An constant unsigned interger describing the size of the above mentioned array.
 */

void print_statistics(unsigned char * array, unsigned int arraySize);

/**
 * @brief Prints the array
 *
 * Prints the array in a desired way.
 *
 * @param test An unsigned char array of 1 byte per index, which hold the numbers to create stats about.
 * @param SIZE An constant unsigned interger describing the size of the above mentioned array.
 */

void print_array(unsigned char * array, unsigned int arraySize);

/**
 * @brief Find median of array
 *
 * Sort the array and checks if the array size is a even or uneven, to determine the median. 
 *
 * @param test An unsigned char array of 1 byte per index, which hold the numbers to create stats about.
 * @param SIZE An constant unsigned interger describing the size of the above mentioned array.
 *
 * @return median An char describing the median of the array. 
 */

char find_median(unsigned char * array, unsigned int arraySize);

/**
 * @brief Find mean of array
 *
 * Sum all numbers of the array and calculate the mean.
 *
 * @param test An unsigned char array of 1 byte per index, which hold the numbers to create stats about.
 * @param SIZE An constant unsigned interger describing the size of the above mentioned array.
 *
 * @return mean An char describing the mean of the array. 
 */

char find_mean(unsigned char * array, unsigned int arraySize);

/**
 * @brief Find minimum of array
 *
 * Check all numbers of the array and store the lowest value.
 *
 * @param test An unsigned char array of 1 byte per index, which hold the numbers to create stats about.
 * @param SIZE An constant unsigned interger describing the size of the above mentioned array.
 *
 * @return min An char describing the minimum value of the array. 
 */

char find_min(unsigned char * array, unsigned int arraySize);

/**
 * @brief Find maximum of array
 *
 * Check all numbers of the array and store the highest value.
 *
 * @param test An unsigned char array of 1 byte per index, which hold the numbers to create stats about.
 * @param SIZE An constant unsigned interger describing the size of the above mentioned array.
 *
 * @return max An char describing the maximum value of the array. 
 */

char find_max(unsigned char * array, unsigned int arraySize);

/**
 * @brief Sort the array in descending order
 *
 * Uses a nested loop to check each value of the array and compare it with the highest value found.
 *
 * @param test An unsigned char array of 1 byte per index, which hold the numbers to create stats about.
 * @param SIZE An constant unsigned interger describing the size of the above mentioned array.
 */

void * sort_array(unsigned char * array, unsigned int arraySize);

#endif /* __STATS_H__ */
