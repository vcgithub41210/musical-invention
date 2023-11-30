import java.io.*;
import java.util.Scanner;

abstract class Shape{
    abstract void number_of_sides();
}

class Rectangle extends Shape{
    void number_of_sides(){
        System.out.println("The number of sides of the rectangle is 4 ");
    }
}

class Triangle extends Shape{
    void number_of_sides(){
        System.out.println("The number of sides of the triangle is 3 ");
    }
}

class Hexagon extends Shape{
    void number_of_sides(){
        System.out.println("The number of sides of the triangle is 6 ");
    }
}

class Abstract{
    public static void main(String args[]){
        Rectangle rct = new Rectangle();
        Triangle trc = new Triangle();
        Hexagon hex = new Hexagon();
        rct.number_of_sides();
        trc.number_of_sides();
        hex.number_of_sides();
    }
}

//sample output
/*
The number of sides of the rectangle is 4 
The number of sides of the triangle is 3 
The number of sides of the triangle is 6 
*/