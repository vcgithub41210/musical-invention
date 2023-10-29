/*
 this program is used for adding two sparse matrices and displaying the result
 Time complexity ⏰️ :- i dont know honestly
 Space complexity 🎮️ :- i dont know honestly
*/

#include <stdio.h>

//Display function
int Display(int array[][3],int row,int column){
    for(int i =0;i < row;i++)
    {
        for(int j = 0; j < column;j++)
        {
            printf("%d\t",array[i][j]);
        }
        printf("\n");
    }
}

int sparseRepresentation(int array[][10],int sparse[][3],int row,int column){
	int count = 0;
	sparse[0][0] = row;
	sparse[0][1] = column;
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < column; j++)
		{
			if(array[i][j] != 0)
			{
				count++;
				sparse[count][0] = i;
				sparse[count][1] = j;
				sparse[count][2] = array[i][j];
			}
		}
	}
	sparse[0][2] = count;
	return count;
}

int sparseAddition(int finalsparse[][3],int sparse1[][3],int sparse2[][3],int row1 ,int column1,int count1,int count2){
	finalsparse[0][0] = row1;
	finalsparse[0][1] = column1;
	int current = 1;
	int x = 1;
	int y = 1;
	int add_left(){
		finalsparse[current][0] = sparse1[x][0];
		finalsparse[current][1] = sparse1[x][1];
		finalsparse[current][2] = sparse1[x][2];
		x++;
	}
	int add_right(){
		finalsparse[current][0] = sparse2[y][0];
		finalsparse[current][1] = sparse2[y][1];
		finalsparse[current][2] = sparse2[y][2];
		y++;
	}
	int add_both(){
		finalsparse[current][0] = sparse2[y][0];
		finalsparse[current][1] = sparse2[y][1];
		finalsparse[current][2] = sparse2[y][2] + sparse1[x][2];
		y++;
		x++;
	}
	while(x< count1 || y< count2)
	{
		if(x == count1 || y == count2)
		{
			if(x==count1){
				add_right();
			}
			else{
				add_left();
			};
		}else if(sparse1[x][0] == sparse2[y][0])
		{
			if(sparse1[x][1] == sparse2[y][1])
			{
				add_both();
			}
			else if(sparse1[x][1] > sparse2[y][1]){
				add_right();
			}else
			{
				add_left();
			}
		}else if(sparse1[x][0] > sparse2[y][0])
		{
			add_right();
		}else
		{
			add_left();
		}
		current++;
	}
	finalsparse[0][2] = current-1;
	return current;
	
}

int main()
{
    //FIRST MATRIX
    int row1,column1;
    printf("Enter the number of rows: ");
    scanf("%d",&row1);
    printf("Enter the number of columns: ");
    scanf("%d",&column1);
    int matrix1[10][10];
    //inputing first matrix
    printf("Enter the elements of the first matrix:\n");
    for(int i = 0;i<row1;i++)
    {
        for(int j=0; j < column1;j++)
        {
            scanf("%d",&matrix1[i][j]);
        }
    }
    //converting to sparse representation
    int sparseForm1[10][3];
    int count1 = sparseRepresentation(matrix1,sparseForm1,row1,column1);
    //SECOND MATRIX
    int row2 = row1,column2 = column1;
    int matrix2[10][10];
    //inputing second matrix
    printf("Enter the elements of the second matrix:\n");
    for(int i = 0;i<row2;i++)
    {
        for(int j=0; j < column2;j++)
        {
            scanf("%d",&matrix2[i][j]);
        }
    }
    //converting to sparse representation
    int sparseForm2[10][3];
    int count2 = sparseRepresentation(matrix2,sparseForm2,row2,column2); 
    //ADDITION
    int finalsparseForm[20][3];
    int current = sparseAddition(finalsparseForm,sparseForm1,sparseForm2,row1,column1,count1+1,count2+1);
    //DISPLAY OUTPUT   
    printf("***FINAL SPARSE MATRIX****\n");
    Display(finalsparseForm,current,3);
}