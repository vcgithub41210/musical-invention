import java.io.*;
import java.util.Scanner;


class Employee{
  String name;
  long phone_no;
  String address;
  int salary;
  void print_Salary(){
    System.out.println("The salary of "+ this.name + " is: "+ this.salary);
    System.out.println("Phone-number: "+ this.phone_no);
    System.out.println("Address: "+ this.address);
  };
};

class Officer extends Employee{
  String specialization;
  Officer(String name, long phone_no, String address, int salary,String specialization){
    this.name = name;
    this.phone_no = phone_no;
    this.address = address;
    this.salary  = salary;
    this.specialization = specialization;
  };
}

class Manager extends Employee{
  String department;
  Manager(String name, long phone_no, String address, int salary,String department){
    this.name = name;
    this.phone_no = phone_no;
    this.address = address;
    this.salary  = salary;
    this.department = department;
  };
}

class EmployeeData{
  public static void main(String args[])
  {
    Scanner string = new Scanner(System.in);
    Scanner integer = new Scanner(System.in);
    System.out.println("Enter the name of the officer: ");
    String name = string.nextLine();
    System.out.println("Enter the call number of the officer: ");
    long number = integer.nextLong();
    System.out.println("Enter the address of the officer: ");
    String address = string.nextLine();
    System.out.println("Enter the salary of the officer: ");
    int salary = integer.nextInt();
    System.out.println("Enter the specialization of the officer: ");
    String specialization = string.nextLine();
    Officer person1 = new Officer(name,number,address,salary,specialization);
    
    System.out.println("Enter the name of the manager: ");
    String Name = string.nextLine();
    System.out.println("Enter the call number of the manager: ");
    long Number = integer.nextLong();
    System.out.println("Enter the address of the manager: ");
    String Address = string.nextLine();
    System.out.println("Enter the salary of the manager: ");
    int Salary = integer.nextInt();
    System.out.println("Enter the department of the manager: ");
    String Department = string.nextLine();
    Manager person2 = new Manager(Name,Number,Address,Salary,Department);

    System.out.println("OfficerDetails***");
    person1.print_Salary();
    System.out.println("specialization: "+ person1.specialization + "\n\n");
    
    System.out.println("ManagerDetails***");
    person2.print_Salary();
    System.out.println("department: "+ person2.department);
  }
}

//sample output
/*
Enter the name of the officer: 
Nisha Lotus
Enter the call number of the officer: 
+14126226624
Enter the address of the officer: 
Suite 320 60288 Dong Ridges, Treychester, IL 80644
Enter the salary of the officer: 
7554
Enter the specialization of the officer: 
Data Science
Enter the name of the manager: 
Michelle Montgomery
Enter the call number of the manager: 
+18025143551
Enter the address of the manager: 
70626 Mante Forge, Carystad, WV 23636-1986
Enter the salary of the manager: 
7851
Enter the department of the manager: 
Software Engineering
OfficerDetails***
The salary of Nisha Lotus is: 7554
Phone-number: 14126226624
Address: Suite 320 60288 Dong Ridges, Treychester, IL 80644
specialization: Data Science


ManagerDetails***
The salary of Michelle Montgomery is: 7851
Phone-number: 18025143551
Address: 70626 Mante Forge, Carystad, WV 2364636-1986
department: Software Engineering
 */