#include <stdio.h>
#include <stdlib.h>
#include "tensor.c"


int main(void){
    // Create a 3x3 Tensor
    tensor_t newTensor = create_tensor(3, 3);

    float* curr = newTensor.matrix;
    for(int i = 0; i < newTensor.row; i++){
        for(int j = 0; j < newTensor.col; j++){
            printf("%f", *curr);
            curr++;
        }
        printf("\n");
    }

    printf("%d", &newTensor);

    free_tensor(&newTensor);
    return 0;
}
