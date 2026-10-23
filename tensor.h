#ifndef TENSOR_H
#define TENSOR_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct tensor
{
    uint64_t row;
    uint64_t col;
    float* matrix;
}tensor_t;

// Allocate a tensor in memory
tensor_t create_tensor(uint64_t, uint64_t);

// Fetch items from tensor
float get_value(tensor_t*, uint64_t, uint64_t);

// Free a tensor from memory
int free_tensor(tensor_t*);


// Tensor operations
bool isEmpty(tensor_t*);
tensor_t empty_tensor();


int set_value(tensor_t*, uint64_t, uint64_t, float);

tensor_t add_tensors(tensor_t*, tensor_t*);
tensor_t multiply_scalar(tensor_t*, float);
tensor_t transpose_tensor(tensor_t*);

#endif