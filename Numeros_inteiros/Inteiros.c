//
// Created by migue on 28/10/2022.
//
#include<time.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "Inteiros.h"

short Rendom_number(int op){
    srand(time(NULL));
    long long  num ;
    if(op==0){
        num =  rand()%10;
    }else if (op == 1){
        num = rand()%100;
    }
   return num ;
}
void preeencher_matriz(short * mat[] , int size ){

    int num=0 , aux = 0 ;
    for( int i = 0 ; i < size ; i++){
        num = Rendom_number(0);
        for(int j =num - 1 ; j>=0 ; j--){
            mat[i][j] = Rendom_number(0);
        }
        printArray(**mat,num);
    }
}
/*void printArray(short *a, int N) {
    int i;
    for (i = 0; i < N; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}*/