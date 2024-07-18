// to read two polynomials and find the sum of the polynomials

#include <stdio.h>

//array of structures

struct Term{
    int coefficient;
    int varpower;
};

void Selection_Sort_Structure(struct Term *polynomial,int size){
    struct Term temp;
    for(int i = 0; i < size-1; i++)
    {
        int min = i;
        for(int j = i+1; j < size;j++)
        {
            if(polynomial[j].varpower < polynomial[min].varpower) min = j;
        }
        temp = polynomial[min];
        polynomial[min] = polynomial[i];
        polynomial[i] = temp;
    }
}

int Polynomial_Addition(struct Term *result,struct Term *poly1,struct Term *poly2,int size1, int size2)
{
for(int i = 0; i < size1;i++) result[i] = poly1[i];
    int length = size1;
    for(int i = 0; i < size2; i++)
    {
	int power = poly2[i].varpower;
	int start = 0;
	int end = size1-1;
	int middle;
	while(start <= end)
	{
   	 	middle = (start+end)/2;
    		if(result[middle].varpower == power) break;
   		else if(result[middle].varpower > power) end = middle-1;
    		else start = middle+1;
	}
	if(result[middle].varpower == power) result[middle].coefficient += poly2[i].coefficient;
	else{
    		result[length].coefficient = poly2[i].coefficient;
    		result[length].varpower = poly2[i].varpower;
    		length++;
	}
    }
    return length;
}
int main(){

    //input the sizes and polynomials


    int size1,size2;
    printf("Enter the no of terms of polynomial 1: ");
    scanf("%d",&size1);
    struct Term poly1[size1];
    printf("Enter the terms of the polynomial in the form:=> coefficient,degree:\n");
    for(int i = 0; i < size1;i++)
    {
        scanf("%d,%d",&poly1[i].coefficient,&poly1[i].varpower);
    }
    Selection_Sort_Structure(poly1,size1);
    printf("Enter the no of terms of polynomial 2: ");
    scanf("%d",&size2);
    struct Term poly2[size2];
    printf("Enter the terms of the polynomial in the form:=> coefficient,degree:\n");
    for(int i = 0; i < size2;i++)
    {
        scanf("%d,%d",&poly2[i].coefficient,&poly2[i].varpower);
    }
    Selection_Sort_Structure(poly2,size2);



    //initialising result array


    struct Term result[size1+size2];



    //adding polynomial 1 to result
    int length = Polynomial_Addition(result,poly1,poly2,size1,size2);
    
    Selection_Sort_Structure(result,length);
    printf("***SUM OF THE TWO POLYNOMIALS***\n\t"); 
    for(int i = length-1; i > -1;i--)
    {
        result[i].varpower!=0?printf("%dx^%d",result[i].coefficient,result[i].varpower):printf("%d",result[i].coefficient);
        if(i!=0) printf(" + ");
    }
    printf("\n");
}