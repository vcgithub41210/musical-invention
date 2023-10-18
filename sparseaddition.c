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


int main()
{
    //FIRST MATRIX+++++++++++
    
    
    
    int row1,column1;
    printf("Enter the number of rows: ");
    scanf("%d",&row1);
    printf("Enter the number of columns: ");
    scanf("%d",&column1);
    int mat1[10][10];

    //inputing first matrix
    printf("Enter the elements of the first matrix:\n");
    for(int i = 0;i<row1;i++)
    {
        for(int j=0; j < column1;j++)
        {
            scanf("%d",&mat1[i][j]);
        }
    }

    //converting to sparse representation
    int sparse1[10][3];
    int count1 = 1;
    sparse1[0][0] = row1;
    sparse1[0][1] = column1;

    for(int i = 0; i < row1; i++)
    {
        for(int j = 0; j < column1; j++)
        {
            if(mat1[i][j] != 0)
            {
                sparse1[count1][0] = i;
                sparse1[count1][1] = j;
                sparse1[count1][2] = mat1[i][j];
                count1++;
            }
        }
        printf("\n");
    }
    sparse1[0][2] = count1-1;

    //SECOND MATRIX******************





    int row2 = row1,column2 = column1;
    int mat2[10][10];

    //inputing first matrix
    printf("Enter the elements of the first matrix:\n");
    for(int i = 0;i<row2;i++)
    {
        for(int j=0; j < column2;j++)
        {
            scanf("%d",&mat2[i][j]);
        }
    }
    int sparse2[10][3];
    //converting to sparse representation
    int count2 = 1;
    sparse2[0][0] = row2;
    sparse2[0][1] = column2;
    for(int i = 0; i < row2; i++)
    {
        for(int j = 0; j < column2; j++)
        {
            if(mat2[i][j] != 0)
            {
                sparse2[count2][0] = i;
                sparse2[count2][1] = j;
                sparse2[count2][2] = mat2[i][j];
                count2++;
            }
        }
        printf("\n");
    }
    sparse2[0][2] = count2-1;
    //Addition of matrices
    int finalsparse[count1+count2][3];
    finalsparse[0][0] = row1;
    finalsparse[0][1] = column1;
    int current = 1;
    int x = 1,y=1;
    while(x < count1 || y < count2)
    {
        if(x == count1 || y == count2)
        {
            if(x == count1){
                finalsparse[current][0] = sparse2[y][0];
                finalsparse[current][1] = sparse2[y][1];
                finalsparse[current][2] = sparse2[y][2];
                y++;
            }
            else{
                finalsparse[current][0] = sparse1[x][0];
                finalsparse[current][1] = sparse1[x][1];
                finalsparse[current][2] = sparse1[x][2];
                x++;
            };
        }
        else if (sparse1[x][0] == sparse2[y][0])
        {
            if(sparse1[x][1] == sparse2[y][1])
            {
                finalsparse[current][0] = sparse1[x][0];
                finalsparse[current][1] = sparse1[x][1];
                finalsparse[current][2] = sparse1[x][2] + sparse2[y][2];
                x++;
                y++;
            }
            else if(sparse1[x][1] > sparse2[y][1]){
                finalsparse[current][0] = sparse2[y][0];
                finalsparse[current][1] = sparse2[y][1];
                finalsparse[current][2] = sparse2[y][2];
                y++;
            }else{
                finalsparse[current][0] = sparse1[x][0];
                finalsparse[current][1] = sparse1[x][1];
                finalsparse[current][2] = sparse1[x][2];
                x++;
            }
        }
        else if(sparse1[x][0] > sparse2[y][0])
        {
            finalsparse[current][0] = sparse2[y][0];
            finalsparse[current][1] = sparse2[y][1];
            finalsparse[current][2] = sparse2[y][2];
            y++;
        }
        else{
            finalsparse[current][0] = sparse1[x][0];
            finalsparse[current][1] = sparse1[x][1];
            finalsparse[current][2] = sparse1[x][2];
            x++;
        }
        current++;
    }
    finalsparse[0][2] = current-1;
    
    printf("The final sparse matrix is:\n");
    Display(finalsparse,current,3);
}