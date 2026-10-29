#include "tensor.h"


int main(void){
    // Create a 3x3 Tensor
    tensor_t newTensor = create_tensor(10, 10);

    float count = 1;
    for(uint64_t i = 0; i < newTensor.row;  i++){
        for(uint64_t j = 0; j < newTensor.col; j++){
            int set = set_value(&newTensor, i, j, count);
            printf("%f", count);
            count++;
        }
        printf("\n");
    }

    printf("\n");

    
    tensor_t transposeTensor = blocked_transpose(&newTensor, 3);

    for(uint64_t i = 0; i < transposeTensor.row;  i++){
        for(uint64_t j = 0; j < transposeTensor.col; j++){
            printf("%f", transposeTensor.matrix[i * transposeTensor.col + j]);
        }
        printf("\n");
    }

    free_tensor(&newTensor);
    free_tensor(&transposeTensor);


    return 0;
}
