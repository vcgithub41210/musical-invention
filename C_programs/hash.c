#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define CORE 1234

char* hashkey(int data){
    long i = data%200;
    i = i * CORE;

    char* hex_key = (char*)malloc(20 * sizeof(char));
    int length=0;
    while(i != 0){
        int remainder = i % 16;
        if (remainder < 10){
            hex_key[length] = ("%d",48+remainder);
        }
        else{
            hex_key[length] = ("%d",97+(remainder%10));
        }
        length += 1;
        i = i/16;
    }
    return hex_key;
}

int main(){
    int data;
    scanf("%d",&data);
    char* hex_key = hashkey(data);
    printf("%s\n",hex_key);

}

/*
41956 => 4 
2622 => e
163 => 3 
10 => a
0
*/