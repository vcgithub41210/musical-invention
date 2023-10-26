import java.io.*;
import java.util.Scanner;

class FindArea{
	double area(float radius)
	{
		return 3.14 * radius * radius;
	}
	float area(float length,float breadth)
	{
		return length * breadth;
	}
	double area(float baselength,float height,int dummy)
	{
		return 0.5 * baselength * height;
	}
}

class AreaOfShape{
	public static void main(String args[])
	{
		char Shape;
		Scanner value = new Scanner(System.in);
		Scanner character = new Scanner(System.in);
		FindArea object = new FindArea();
		do{
			System.out.println("Enter the shape;\nCircle(c)\tRectangle(r)\tTriangle(t)\tQuit(q)");
			Shape = character.next().charAt(0);
			if(Shape == 'c'){
				System.out.println("Enter the radius: ");
				float radius = value.nextFloat();
				System.out.println("The Area of the Circle is: "+ object.area(radius));			
			}
			else if(Shape == 'r'){
				System.out.println("Enter the length: ");
				float length = value.nextFloat();
				System.out.println("Enter the breadth: ");
				float breadth = value.nextFloat();
				System.out.println("The Area of the Rectangle is: "+ object.area(length,breadth));			
			}
			else if(Shape == 't'){
				System.out.println("Enter the baselength: ");
				float baselength = value.nextFloat();
				System.out.println("Enter the height: ");
				float height = value.nextFloat();
				System.out.println("The Area of the Triangle is: "+ object.area(baselength,height,1));			
			}
		}
		while(Shape != 'q');
	}
}