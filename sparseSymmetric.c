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
int sparseTranspose(int array[][3],int transpose[][3],int row,int column){
	for(int i = 0; i < row;i++){
		transpose[i][0] = array[i][1];
		transpose[i][1] = array[i][0];
		transpose[i][2] = array[i][2];
	}
	for(int j = 2; j < row;j++){
		int x = transpose[j][0];
		int y = transpose[j][1];
		int z = transpose[j][2];
		
		
		int k = j-1;
		while(k>=1 && transpose[k][0] > x)
		{
			transpose[k+1][0] = transpose[k][0];
			transpose[k+1][1] = transpose[k][1];
			transpose[k+1][2] = transpose[k][2];
			k--;
		}
		transpose[k+1][0] = x;
		transpose[k+1][1] = y;
		transpose[k+1][2] = z;
	}
}

int symmetricTest(int sparse[][3],int transpose[][3],int row){
	for(int i = 1; i < row; i++)
	{
		 if(sparse[i][2] != transpose[i][2])
		 {
		 	return printf("The matrix is non-symmetric!!\n");
		 }	
	}
	return printf("The matrix is symmetric!!\n");
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
	printf("Enter the number of rows/number of columns of the square matrix: ");
	scanf("%d",&row);
	
	printf("Enter the elements of the array:\n");
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < row; j++)
		{
			scanf("%d",&matrix[i][j]);
		}
	}
	int sparseform[10][3];
	int count = sparseRepresentation(matrix,sparseform,row,row);
	
	//finding transpose
	int transpose[10][3];
	sparseTranspose(sparseform,transpose,count+1,3);

	//displaying sparse and sparse transpose
	printf("***Sparse Matrix Representation***\n");
	Display(sparseform,count+1,3);
	printf("***Sparse Transpose***\n");
	Display(transpose,count+1,3);
	symmetricTest(sparseform,transpose,count+1);
}