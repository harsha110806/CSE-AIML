#include <stdio.h>

void create(int row, int col, int arr[row][col]){
    printf("Enter matrix elements:\n");
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            scanf("%d", *(arr+i)+j);
        }
    }
}

void display(int row, int col, int arr[row][col]){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            printf("%d ", *(*(arr+i)+j));
        }
        printf("\n");
    }
}

void add(int row, int col, int arr1[row][col], int arr2[row][col], int arr3[row][col]){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            *(*(arr3+i)+j) = *(*(arr1+i)+j) + *(*(arr2+i)+j);
        }
    }
}

void subtract(int row, int col, int arr1[row][col], int arr2[row][col], int arr3[row][col]){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            *(*(arr3+i)+j) = *(*(arr1+i)+j) - *(*(arr2+i)+j);
        }
    }
}

void transpose(int row, int col, int arr[row][col], int trans[col][row]){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            *(*(trans+j)+i) = *(*(arr+i)+j);
        }
    }
}

void multiply(int r1, int c1, int arr1[r1][c1],
              int r2, int c2, int arr2[r2][c2],
              int result[r1][c2]){

    for(int i = 0; i < r1; i++){
        for(int j = 0; j < c2; j++){
            *(*(result+i)+j) = 0;
            for(int k = 0; k < c1; k++){
                *(*(result+i)+j) += (*(*(arr1+i)+k)) * (*(*(arr2+k)+j));
            }
        }
    }
}

int main(){

    int row, col;

    printf("Enter number of rows: ");
    scanf("%d", &row);

    printf("Enter number of columns: ");
    scanf("%d", &col);

    int arr1[row][col];
    int arr2[row][col];
    int arr3[row][col];
    int trans[col][row];
    int mul[row][col];

    printf("\nEnter Matrix 1\n");
    create(row, col, arr1);

    printf("\nEnter Matrix 2\n");
    create(row, col, arr2);

    printf("\nMatrix 1:\n");
    display(row, col, arr1);

    printf("\nMatrix 2:\n");
    display(row, col, arr2);

    printf("\nAddition:\n");
    add(row, col, arr1, arr2, arr3);
    display(row, col, arr3);

    printf("\nSubtraction:\n");
    subtract(row, col, arr1, arr2, arr3);
    display(row, col, arr3);

    printf("\nTranspose of Matrix 1:\n");
    transpose(row, col, arr1, trans);
    display(col, row, trans);

    if(row == col){
        printf("\nMultiplication:\n");
        multiply(row, col, arr1, row, col, arr2, mul);
        display(row, col, mul);
    }
    else{
        printf("\nMultiplication is only possible when both matrices are square and of the same order in this program.\n");
    }

    return 0;
}
