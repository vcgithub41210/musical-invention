#include <stdio.h>

//Structure
struct Student
{
	char name[30];
	int chemistry_marks;
	int maths_marks;
	int oops_marks;
	int ds_marks;
	int lsd_marks;
	int Total_Marks;
} batch[50],temp;

//function definition section

int Calculate_Marks(struct Student *batch,int number)
{
	for(int i = 0; i < number; i++)
	{
		batch[i].Total_Marks = batch[i].chemistry_marks + batch[i].maths_marks + batch[i].oops_marks + batch[i].ds_marks + batch[i].lsd_marks;
	}
}

int Sort(struct Student *batch,int number)
{
	for(int i = number; i > 1; i--)
	{
		for(int j = 0; j < i-1; j++)
		{
			if(batch[j].Total_Marks < batch[j+1].Total_Marks)
			{
				temp = batch[j+1];
				batch[j+1] = batch[j];
				batch[j] = temp;
			}
		}
	}
}

int Display(struct Student *batch,int number)
{
	for(int i = 0; i < number; i++)
	{
		printf("%s\t",batch[i].name);
	}
}

//Main function

int main()
{
	int number;
	printf("Enter the number of students in the class: ");
	scanf("%d",&number);
	printf("Enter the following details of the student;\n");
	printf("name,chemistry marks, maths marks, oops marks, ds marks, lsd marks:\n\n");
	
	for(int i = 0; i < number; i++)
	{
		printf("Enter the name: ");
		scanf("%s",&batch[i].name);
		printf("Enter the 5 marks of the student: ");
		scanf("%d,%d,%d,%d,%d",&batch[i].chemistry_marks,&batch[i].maths_marks,&batch[i].oops_marks,&batch[i].ds_marks,&batch[i].lsd_marks);
	}
	Calculate_Marks(batch,number);	
	Sort(batch,number);
	Display(batch,number);
}
