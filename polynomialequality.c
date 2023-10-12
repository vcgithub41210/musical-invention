// to read two polynomials and find the sum of the polynomials

#include <stdio.h>

//array of structures

struct Term{
    int coefficient;
    int varpower;
};

void Insertion_Sort_Structure(struct Term *polynomial,int size){
    for(int i = 1; i < size;i++)
    {
        struct Term temp = polynomial[i];
        int j = i-1;
        while(j>=0 && polynomial[j].varpower > temp.varpower)
        {
            polynomial[j+1] = polynomial[j];
            j--;
        }
        polynomial[j+1] = temp;
    }
}
int Polynomial_Evaluation(struct Term *poly,int size,int x)
{
	int sum = 0;
	for(int i = 0; i < size; i++)
    	{
        	int power = poly[i].varpower;
        	int product = poly[i].coefficient;
        	for(int j = 0; j < power;j++)
        	{
            	product *= x;
        	}
        	sum += product;
    	}
	return sum;
}

int main(){

    //input the sizes and polynomials
    int size,x;
    printf("Enter the no of terms of polynomial 1: ");
    scanf("%d",&size);
    struct Term poly[size];
    printf("Enter the terms of the polynomial in the form:=> coefficient,degree:\n");
    for(int i = 0; i < size;i++)
    {
        scanf("%d,%d",&poly[i].coefficient,&poly[i].varpower);
    }
    Insertion_Sort_Structure(poly,size);
    printf("Enter the value of x: ");
    scanf("%d",&x);
    int sum = Polynomial_Evaluation(poly,size,x);
    
    printf("***Value of polynomial for x = %d***\n\t\t%d\n",x,sum);
}