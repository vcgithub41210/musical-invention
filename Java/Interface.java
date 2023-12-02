import java.io.*;
import java.util.Scanner;

interface Sports{
    final float sportwt = 6.0F;
    void putwt();
}

class Student{
    int rollnumber;
    public void getNumber(){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the roll number of the student: ");
        rollnumber = sc.nextInt();
    }
    public void putNumber(){
        System.out.println("The roll number of the Student is: " + rollnumber + "\n");
    }
}

class Test extends Student{
    float term1;
    float term2;
    public void getMarks(){
        Scanner xy = new Scanner(System.in);
        System.out.println("Enter the marks of term1: ");
        term1 = xy.nextFloat();
        System.out.println("Enter the marks of term2: ");
        term2 = xy.nextFloat();
    }
    public void putMarks(){
        System.out.println("The marks of the Student\nTerm1: "+term1+ "\tTerm2: "+term2+"\n");
    }
}

class Result extends Test implements Sports{
    public void putwt(){
        System.out.println("Sports weightage: "+sportwt+"\n");
    }
}
class Interface{
    public static void main(String args[]){
        Result student = new Result();
        student.getNumber();
        student.getMarks();
        student.putNumber();
        student.putMarks();
        student.putwt();
        System.out.println("Total Score = "+(student.term1 + student.term2 + student.sportwt));
    }
}

//sample output
/*
Enter the roll number of the student: 2317
Enter the marks of term1: 
45
Enter the marks of term2: 
48
The roll number of the Student is: 2317

The marks of the Student
Term1: 45.0     Term2: 48.0

Sports weightage: 6.0

Total Score = 99.0
*/