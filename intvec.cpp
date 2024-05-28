/*
 * intvec.cpp
 *
 *  Created on: 27.05.2024
 *      Author: swt
 */


#include "intvec.h"

void ivec_init(intvec* ivec, size_t cap)
{
	ivec -> capacity = cap;
	ivec -> size = 0;
	ivec -> arr =(int*) malloc (cap*sizeof(int));

}

void ivec_clear(intvec* ivec)
{
	ivec = free();
}
