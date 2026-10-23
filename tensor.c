#include "tensor.h"


// Initialize a tensor of 0s
tensor_t create_tensor(uint64_t row, uint64_t col) {

    tensor_t newTensor;

    if(row == 0 || col == 0 || row > (SIZE_MAX / sizeof(float)) / col){
        newTensor.row = 0;
        newTensor.col = 0;
        newTensor.matrix = NULL;
        return newTensor;
    }

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
    for(uint64_t i = 0; i < row; i++){
        for(uint64_t j = 0; j < col; j++){
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

    if(tensor == NULL){
        return -1;
    }

    free(tensor -> matrix);

    tensor -> row = 0;
    tensor -> col = 0;
    tensor -> matrix = NULL;

    return 0;
}

tensor_t empty_tensor() {
    tensor_t newTensor = create_tensor(0 ,0);
    return newTensor;
}

// Tensor operations
bool isEmpty(tensor_t* tensor){
    if(tensor == NULL || tensor -> row == 0 || tensor -> col == 0 || tensor -> matrix == NULL){
        return true;
    }
    return false;
}

int set_value(tensor_t* tensor, uint64_t row, uint64_t col, float value){
    if(tensor == NULL || tensor -> matrix == NULL){
        return -1;
    }

    tensor -> matrix[row * tensor -> col + col] = value;

    return 0;
}

tensor_t add_tensors(tensor_t* tensor1, tensor_t* tensor2){
    
    if(isEmpty(tensor1) || isEmpty(tensor2)){
        return empty_tensor();
    }

    if(tensor1 -> row != tensor2 -> row || tensor1 -> col != tensor2 -> col){
        return empty_tensor();
    }

    tensor_t newTensor = create_tensor(tensor1 -> row, tensor1 -> col);

    if(newTensor.matrix == NULL){
        return newTensor;
    }

    float* ptr1 = tensor1 -> matrix;
    float* ptr2 = tensor2 -> matrix;
    float* ptr3 = newTensor.matrix;

    for(uint64_t i = 0; i < tensor1 -> row; i++){
        for(uint64_t j = 0; j < tensor1 -> col; j++){
            *ptr3 = *ptr1 + *ptr2;
            ptr1 += 1;
            ptr2 += 1;
            ptr3 += 1;
        }
    }

    return newTensor;
    
}

float multiply_scalar(tensor_t*, float);


