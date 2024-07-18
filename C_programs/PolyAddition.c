#include <stdio.h>
#define MAX_TERMS 100


typedef struct{
    int coefficient;
    int power;
}polynomial;

polynomial terms[MAX_TERMS];

int add(int coefficient,int power, int *endC){
    terms[*endC].coefficient = coefficient;
    terms[*endC].power = power;
    *endC += 1; // this could be a root cause for an error
}
int Sort(polynomial terms[],int start,int end){
    for(int i = start+1; i < end+1;i++)
    {
        int coefficient = terms[i].coefficient;
        int power = terms[i].power;
        int j = i-1;
        while(j>=0 && terms[j].power > power)
        {
            terms[j+1].coefficient = terms[j].coefficient;
            terms[j+1].power = terms[j].power;
            j--;
        }
        terms[j+1].coefficient = coefficient;
        terms[j+1].power = power;
    }
}
int Polynomial_addition(polynomial terms[],int startA,int endA, int startB, int endB,int *endC){
    while(startA <= endA && startB <= endB)
    {
        if(terms[startA].power < terms[startB].power)
        {
            add(terms[startA].coefficient,terms[startA].power,endC);
            startA++;
        }
        else if(terms[startA].power > terms[startB].power)
        {
            add(terms[startB].coefficient,terms[startB].power,endC);
            startB++;
        }
        else{
            int coefficient = terms[startA].coefficient + terms[startB].coefficient;
            add(coefficient,terms[startA].power,endC);
            startA++;
            startB++;
        }
    }
    while(startA <= endA)
    {
        add(terms[startA].coefficient,terms[startA].power,endC);
        startA++;
    }
    while(startB <= endB)
    {
        add(terms[startB].coefficient,terms[startB].power,endC);
        startB++;
    }
}

int input_terms(int start,int end){
    printf("Enter the coefficient and power of each term of the polynomial:\n");
    for(int i=start;i<=end;i++)
    {
        scanf("%d,%d",&terms[i].coefficient,&terms[i].power);
    }
}
int main(){
    int avail,startA,length1,endA,startB,length2,endB,startC,endC;
    startA = 0;
    printf("Enter the size of the first polynomial: ");
    scanf("%d",&length1);
    startB = length1;
    endA = length1-1;
    input_terms(startA,endA);
    Sort(terms,startA,endA);

    printf("Enter the size of the second polynomial: ");
    scanf("%d",&length2);
    endB = startB+length2-1;
    startC = endB+1;
    endC = startC;
    input_terms(startB,endB);
    Sort(terms,startB,endB);

    Polynomial_addition(terms,startA,endA,startB,endB,&endC);
    
    for(int i = endA; i>=startA;i--)
    {
        printf("{coefficient: %d,power: %d}\n",terms[i].coefficient,terms[i].power);
    }
    for(int i = endB; i>=startB;i--)
    {
        printf("{coefficient: %d,power: %d}\n",terms[i].coefficient,terms[i].power);
    }
    
}