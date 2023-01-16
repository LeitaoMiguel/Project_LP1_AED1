//
// Created by migue on 07/12/2022.
//
#include<time.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "Parte1.h"
unsigned long long new_public_key_int(void){
    unsigned long long num ;
    num =  rand()%100 +1 ;
    return num;
}
short* key_long_2_digits_int(unsigned long long key){
    short *aux;
    short *array;
    unsigned long long num;
    int i =  0;
    while( key != 0 ){
        num = key%10;
        key  = key /10;
        *(aux+i)=num;
        i++;
    }
    for(int j = 0 ; i<0 ; j++,i--){
        *(array+j)=*(aux+i);
    }
    return array;
}
unsigned long long key_digits_2_long_int(const short* keydigits){
    int size = keydigits[0];
    unsigned long long key ;
    for (int i = 1 ; i < size ; i ++){
        key=key* 10;
        key=key+ keydigits[i];
    }
    return key ;
}
unsigned long long calc_private_key_int(unsigned long long pubkey){

    unsigned long long num = pubkey ;
    while(1){
        num = num + pubkey;
        if (Bipolar_chueq(num)== num ){
            break;
        }
    }
    return num ;
}
unsigned long long Bipolar_chueq(unsigned long long  num){
    int  count = 0 ;
    unsigned long long i = -1 ;
    unsigned long long aux = 0 ;
    while (num > 0 && count > 1) {
        aux = num % 10;
        num = num / 10;
        if (i == -1) {
            i = aux;
        } else if (aux != i && count == 0 || aux != i && count != 0 ) {
            count++;
            if(count > 1 ){
                break;// return -1
            }
        }
    }
    if (count > 1) {
        return -1;
    } else {
        return num;
    }
}
unsigned long long fazer_valor_runlength(int count , unsigned  long long  valor ){
    unsigned long long num= 0 ;
    num = num +count ;
    num = num * 10;
    num+=valor;
    return num ;
}
unsigned long long calc_runlength_int(unsigned long long privkey){
    // so tem em conta que cada metade da chave privada n tenha mais de 9 digitos
    unsigned long long aux = 0  , aux2=-1 , valor =0 , valoraux=0  ;
    int count =0 ,change=0;
    while ( privkey != 0 ){
        aux = privkey%10;
        privkey = privkey/10;
        if(aux2 == -1){
            aux2= aux ;
        }
        if(aux == aux2 ){
            count++;
        }else if (aux != aux2 && change <1 ){
            valor = fazer_valor_runlength(count , aux);
            count = 0 ;
            aux2 = aux ;
            change++;
        }else{
            valoraux = fazer_valor_runlength(count , aux );
            valoraux= valoraux*100;
            valor = valor+ valoraux;
            break;
        }
    }
    return  valor ;
}
unsigned long long private_key_from_runlength_int(unsigned long long runlengthkey){
    unsigned long long rep1= 0 , num1=0 , rep2=0 , num2=0 , aux=0;
    int count = 0 ;
    while ( runlengthkey != 0 ){
        aux = runlengthkey%10;
        runlengthkey=runlengthkey/10;
        if (count == 0 ){
            num2= aux;
            count ++;
        }else if ( count ==1){
            rep2= aux;
            count ++;
        }else if (count == 2 ){
            num1=aux;
            count ++;
        }else {
            rep1=aux ;
            aux= 0 ;
            break;
        }
    }
    while (rep1!=0){
        aux= aux + num1 ;
        aux= aux *10 ;
        rep1--;
    }
    while (rep2!=0){
        aux = aux + num2;
        aux= aux *10 ;
        rep2--;
    }
    return aux ;
}
short** alloc_matrix_int(int nlines, int ncolumns){

    short** mat = (short**) malloc(nlines* sizeof(short*));
    for (int i = 0 ; i < ncolumns ; i++){
        mat[i]= calloc(ncolumns, sizeof(short));
    }
    return mat ;
}
void store_key_int(short **matrix, int lines, unsigned long long key){
    unsigned long long aux = key ;
    short tam = 0 ;
    int j = 1 ;
    while (aux != 0 ){
        aux = aux / 10;
        tam ++;
    }
    aux = 0 ;
    for(int i = 0 ; i < lines ;i++){
        if ( matrix[i][0]==0 ){
            matrix[i][0]= tam ;
            while ( key != 0 ){
                aux = key % 10 ;
                key = key / 10 ;
                matrix[i][j]=aux;
                j++;
            }
            break;
        }
    }
}
int exists_key_int(short **matrix, int lines, unsigned long long key){
    unsigned long long aux = key;
    for(int i = 0 ; i < lines ; i++){
        for (int j = matrix[i][0] ; j > 0 ; j--){
            if ( aux%10 != matrix[i][j]){
                break;
            }else {
                aux = aux / 10 ;
                if ( j -1 == 0 ){
                    return 1 ;
                }
            }

        }
        aux = key;
    }
    return  0 ;
}
unsigned long long get_private_key_int(short **matrix_kpub, short **matrix_kpriv, int lines, unsigned long long pubkey){
    unsigned long long aux = 0 , privt=0;
    int indice = -1 ;
    for (int i = 0 ; i < lines ; i++ ){
        aux= pubkey;
        for ( int j = matrix_kpub[i][0]; j > 0 ; j--){
            if ( aux%10 == matrix_kpub[i][j]){
                aux = aux / 10 ;
                if ( j-1 == 0 ){
                    indice = i ;
                }
            }else {
                break;
            }
        }
        if ( indice != -1 ){
            for(int k = 1 ; i < matrix_kpriv[indice][0]; i++){
                privt= privt *10 ;
                privt = privt + matrix_kpriv[indice][i];
            }
            return privt;
        }
    }

    return -1;
}
unsigned long long get_runlength_int(short **matrix_kpriv, short **matrix_kcod, int lines, unsigned long long privkey){
    unsigned long long runlength= calc_runlength_int(privkey),aux =0 , run = 0 ;
    int indice = -1 ;
    for (int i = 0 ; i < lines ; i++ ){
        aux= runlength;
        for ( int j = matrix_kcod[i][0]; j > 0 ; j--){
            if ( aux%10 == matrix_kcod[i][j]){
                aux = aux / 10 ;
                if ( j-1 == 0 ){
                    indice = i ;
                }
            }else {
                break;
            }
        }
        if ( indice != -1 ){
            for(int k = 1 ; i < matrix_kcod[indice][0]; i++){
                run= run *10 ;
                run = run + matrix_kcod[indice][i];
            }
            return run ;
        }
    }
    return -1;
}
unsigned long long delete_key_int(short **matrix_kpub, short **matrix_kpriv, short **matrix_kcod, int lines, short pubkey){
    // encontrar o indice da pub key e dps zerar todas os indices das outras matries
    short aux = pubkey;
    if(exists_key_int(matrix_kpub,lines , pubkey)== 0 ){
        return 0 ;
    }else{
        for(int i = 0 ; i < lines ; i++){
            for (int j = matrix_kpub[i][0] ; j > 0 ; j--){
                if ( aux%10 != matrix_kpub[i][j]){
                    break;
                }else {
                    aux = aux / 10 ;
                    if ( j -1 == 0 ){
                        matrix_kpub[i][0]=0;
                        matrix_kcod[i][0]=0;
                        matrix_kpriv[i][0]=0;
                        return pubkey;
                    }
                }

            }
            aux = pubkey;
        }
    }
    return -1 ;
}
void bulk_populate_public_keys_int(short **matrix_kpub, int lines){
    matrix_kpub = alloc_matrix_int(lines, 100);
    for ( int i =  0 ; i < lines ; i ++){
        store_key_int(matrix_kpub,i , new_public_key_int());
    }
}
void bulk_compute_private_keys_int(short **matrix_kpub, short **matrix_kpriv, int lines){
    unsigned long long key = 0 , priv_key = 0 ;
    for(int i = 0 ; i  < lines ; i ++){
        key = key_digits_2_long_int(matrix_kpub[i]);
        priv_key= calc_private_key_int(key);
        store_key_int(matrix_kpriv,lines , priv_key);
    }
}
void bulk_compute_runlengths_int(short **matrix_kpriv, short **matrix_kcod, int lines){
    unsigned priv_key = 0 , run_length = 0 ;
    for(int i = 0 ; i < lines ;i++){
        priv_key = key_digits_2_long_int(matrix_kpriv[i]);
        run_length= get_runlength_int(matrix_kpriv,matrix_kcod ,lines, priv_key );
        store_key_int(matrix_kcod,lines,run_length);
    }
}
void save_txt_keys_int(short **matrix_kpub, short **matrix_kpriv, short **matrix_kcod, int lines, char filename[]){
    FILE *fp;
    unsigned  long long aux = 0  , aux_priv , aux_cod ;
    fp= fopen(filename, "w" );
    for(int i = 0 ; i < lines ; i ++){
        aux_cod =  0;
        aux_priv = 0 ;
        aux = 0 ;
        for ( int j= matrix_kpub[i][0]; j > 0 ; j --){
            aux = aux * 10;
            aux = aux + matrix_kpub[i][j];
        }
        aux_priv= get_private_key_int(matrix_kpub,matrix_kpriv,lines , aux );
        aux_cod = get_runlength_int(matrix_kpriv , matrix_kcod , lines , aux_priv);
        fprintf(fp, "%llu;%llu;%llu \n",aux , aux_priv ,aux_cod);
    }
    fclose(fp);
}
void load_txt_keys_int(short **matrix_kpub, short **matrix_kpriv, short **matrix_kcod, int lines, char filename[]){
    FILE *fp;
    unsigned long long aux = 0 ;
    int i = 0 ;
    fp = fopen(filename, "r");
    while(feof(fp)!= 0 ){
        i++;
        fscanf(fp,"%llu",&aux);
        store_key_int(matrix_kpub,i,aux);
    }
    fclose(fp);
}