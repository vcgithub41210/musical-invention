/**
 * In this program we learn the concept of method overloading which is a feature similar to constructor overloading
 * The constructor of a class is used to create an instance of the class (object)
 * If a constructor is not defined inside a class, the default constructor will only just create an object of the class
 * But one can create a constructor inside a class (must have the same name as the class) and instruct what the constructor does
 * Many constructors can be defined inside the class with the same name and can perform differently based on the number of inputs
 * This phenomenon is called constructor overloading
 * 
 * In simple words, depending on the number of inputs passed, a constructor can behave differently
 * This is called constructor overloading
 * 
 * Similarly a particular method can be defined many times in a class with different number of inputs
 * When the method is called, depending on the amount of parameters passed, the method performs different tasks
 * This is called Method Overloading
 * 
 * Method Overloading and Constructor Overloading are examples of polymorphism
 * 
 * In this example, the class FindArea has different definitions of the same function 'area'
 * Each declaration differs from each other in the number of formal parameters
 * All the definitions are completely different from each other in what task they perform
 * 
 * Since we need one parameter to find Area of a circle which is the radius, we can design the area method
 * such that when the method is called and 1 parameter is passed, it uses the equation of area of circle to find area and return it
 * 
 * But passing 2 parameters during method call will process the task of finding area of rectangle
 * Similarly passing 3 parameters during method call will help find area of triangle
 * (technically there is only 2 parameters required to find area of triangle but this example
 * uses 3 parameters to help understand method overloading (2 user parameters and 1 constant parameter))
 */

import java.io.*;
import java.util.Scanner;

class FindArea{
  float area(float radius)
  {
    return (float)3.14 * radius * radius;
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

//sample output
/*
Enter the shape;
Circle(c)       Rectangle(r)    Triangle(t)     Quit(q)
c
Enter the radius: 
12.5
The Area of the Circle is: 490.625
Enter the shape;
Circle(c)       Rectangle(r)    Triangle(t)     Quit(q)
t
Enter the baselength: 
12
Enter the height: 
4
The Area of the Triangle is: 24.0
Enter the shape;
Circle(c)       Rectangle(r)    Triangle(t)     Quit(q)
r
Enter the length: 
10
Enter the breadth: 
5
The Area of the Rectangle is: 50.0
Enter the shape;
Circle(c)       Rectangle(r)    Triangle(t)     Quit(q)
q
 */