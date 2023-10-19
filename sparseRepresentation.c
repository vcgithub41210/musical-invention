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

int main()
{
	int row,column,matrix[10][10];
	printf("Enter the number of rows: ");
	scanf("%d",&row);
	printf("Enter the number of columns: ");
	scanf("%d",&column);
	
	printf("Enter the elements of the array:\n");
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < column; j++)
		{
			scanf("%d",&matrix[i][j]);
		}
	}
	int sparseform[10][3];
	int count = sparseRepresentation(matrix,sparseform,row,column);
	printf("***Sparse Representation***\n\n");
	Display(sparseform,count+1,3);
}