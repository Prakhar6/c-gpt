#include <stdio.h>

typedef struct tensor
{
    int64_t row;
    int64_t col;
    float* matrix;
}tensor_t;

// Allocate a tensor in memory
tensor_t create_tensor(int64_t, int64_t);


// Free a tensor from memory
int free_tensor(tensor_t*);