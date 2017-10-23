/*
 * main.h
 *
 *  Created on: Oct 16, 2017
 *      Author: OD
 */
#ifndef MAIN_H_
#define MAIN_H_

#include <iostream>
#include <fstream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <iomanip>
#include <time.h>
#include <fstream>
#include <sstream>
using namespace std;

#define PI 3.14159265

float distanceBetweenTwo(float lat1, float lon1, float lat2, float lon2){
	float R = 6373  ; //R in meters
	float dlon = (lon2 - lon1) * PI / 180;
	float dlat = (lat2 - lat1) * PI / 180;
	float a = (sin(dlat/2) * sin(dlat/2) + cos(lat1 * PI/180) * cos(lat2 * PI/180) * sin(dlon/2)* sin(dlon/2)) ;
	float c = 2 * atan2(sqrt(a), sqrt(1-a));
	return R*c;
}

template<typename T> void merge(T begin, T middle, T end, T res){
	T a = begin, b = middle, r = res;

	while (a < middle && b < end)
		if (*a < *b) *r++ = *a++;
		else *r++ = *b++;

	while (a < middle) *r++ = *a++;
	while (b < end) *r++ = *b++;
	while (begin < end) *begin++ = *res++;
}

template<typename T> void mergesort(T begin, T end, T res){
	int s = end-begin;
	if (s > 1)
	{
		T middle = begin+s/2;
		mergesort(begin, middle, res);
		mergesort(middle, end, res);
		merge(begin, middle, end, res);
	}
}

template<typename T> void swap(T *xp, T *yp){
    T temp = *xp;
    *xp = *yp;
    *yp = temp;
}

template<typename T> void bubblesort(T a, int n){
   int i, j;
   for (i = 0; i < n-1; i++)
       for (j = 0; j < n-i-1; j++)
           if (a[j] > a[j+1]){
        	   swap(&a[j], &a[j+1]);
           }
}

#endif /* MAIN_H_ */
