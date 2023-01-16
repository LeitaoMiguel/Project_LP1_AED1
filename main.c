#include "Numeros_inteiros/Inteiros.h"
#include "Numeros_inteiros/Parte1.h"


#include <stdlib.h>
#include <stdio.h>
#include<time.h>
void test1();
int main() {
    test1();

    return 0 ;
}
void test1(){
    short** m1= alloc_matrix_int(10,100);
    bulk_populate_public_keys_int(m1,10);
    short** m2= alloc_matrix_int(10,100);
    bulk_compute_private_keys_int(m1,m2,10);
    short** m3= alloc_matrix_int(10,100);
    bulk_compute_runlengths_int(m2 ,m3 , 10 );
    save_txt_keys_int(m1 , m2, m3 , 10 , "../test1.txt");
}