#include <stdio.h>
#include <stdlib.h>
#include "tensor.h"


// Initialize a tensor of 0s
tensor_t create_tensor(uint64_t row, uint64_t col) {

    tensor_t newTensor;

    newTensor.row = row;
    newTensor.col = col;

    float *matrix = malloc(row * col * sizeof(float));

    if(matrix == NULL){
        tensor_t nullTensor;
        nullTensor.row = 0;
        nullTensor.col = 0;
        nullTensor.matrix = NULL;
        return nullTensor;
    }

    float *curr = matrix;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            *curr = 0.0f;
            curr++;
        }
    }

    newTensor.matrix = matrix;
    curr = NULL;
    
    return newTensor;
}

// Fetch items
float get_value(tensor_t* tensor, uint64_t row, uint64_t col){
    float* matrix = tensor -> matrix;

    return *(matrix + (row * tensor -> col + col));
}


// Destroy tensor
int free_tensor(tensor_t* tensor){

    if(tensor -> matrix == NULL){
        return -1;
    }

    free(tensor -> matrix);

    tensor -> row = 0;
    tensor -> col = 0;
    tensor -> matrix = NULL;

    return 0;
}


