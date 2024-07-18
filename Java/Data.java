import java.io.*;
import java.util.Scanner;

class Employee{
    void Display(){
        System.out.println("Employee class");
    }
    void cal_salary(){
        System.out.println("The salary is 10000");
    }
}

class Engineer extends Employee{
    void Display(){
        System.out.println("Engineer class");
    }
    void cal_salary(){ 
        System.out.println("The salary is 20000");
        super.Display();
        super.cal_salary();
    }
}

class Data{
    public static void main(String args[])
    {
        Engineer engg = new Engineer();
        engg.Display();
        engg.cal_salary();
    }
}