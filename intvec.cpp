/*
 * intvec.cpp
 *
 *  Created on: 27.05.2024
 *      Author: swt
 */

#include <cstdlib>
#include <cstring>  // Für memcpy
#include "intvec.h"

void ivec_init(intvec* ivec, size_t cap)
{
	ivec -> capacity = cap;
	ivec -> size = 0;
	ivec -> arr =(int*) malloc (cap*sizeof(int));
		if(ivec->arr == nullptr)
		{
				throw bad_alloc();
		}

}

void ivec_clear(intvec* ivec)
{
	free(ivec->arr);
	ivec->arr = nullptr;
	ivec->capacity = 0;
	ivec->size=0;
}

void ivec_pushback(intvec* ivec, int ele)
{
    // Überprüfen, ob ausreichend Kapazität vorhanden ist
    if (ivec->size == ivec->capacity) {
        // Verdoppeln der Kapazität
        size_t new_capacity = ivec->capacity * 2;
        if (new_capacity == 0) {
            new_capacity = 1; // Fallback für den Fall, dass die ursprüngliche Kapazität 0 ist
        }

        int* new_arr = (int*) malloc(new_capacity * sizeof(int));

        // Kopieren der alten Werte in das neue Array
        memcpy(new_arr, ivec->arr, ivec->size * sizeof(int));

        // Freigeben des alten Arrays
        free(ivec->arr);

        // Aktualisieren der Zeiger und Kapazität
        ivec->arr = new_arr;
        ivec->capacity = new_capacity;

    }

    ivec->arr[ivec->size] = ele;
    ivec->size++;
}

int& ivec_at(intvec* ivec, size_t idx)
{
	if(ivec->arr[idx] != nullptr)
	{
		return ivec->arr[idx];
	}

	else if (ivec->arr[idx] == nullptr)
	{
		throw runtime_error("ungültiger wert");
	}

}

int ivec_sum(intvec* ivec)
{
	int summe;
	for(int i = 0; i < (ivec->capacity); i++)
	{
		summe += ivec->arr[i];
	}

	return summe;
}
