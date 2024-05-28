/*
 * intvec.h
 *
 *  Created on: 27.05.2024
 *      Author: swt
 */

#include <iostream>
using namespace std;
#include "pbma.h"
#include <vector>
#include <cstdlib>
#include <bitset>
#include <map>

#ifndef INTVEC_H_
#define INTVEC_H_

struct intvec {
	size_t capacity;
	size_t size;
	int *arr;
};



#endif /* INTVEC_H_ */
