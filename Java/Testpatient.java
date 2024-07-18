import java.io.*;
import java.util.Scanner;

class Patient{
	int id;
	int age;
	String blood_data;
	Patient(){
		id = 0;
		age = 0;
		blood_data = "0";
	}
	Patient(int id,int age, String blood_data){
		this.id = id;
		this.age = age;
		this.blood_data = blood_data;
	}
	void get_id(){
		System.out.println("Id: " + this.id);
	}
	void get_age(){
		System.out.println("Age: " + this.age);
	}
	void get_blood_data(){
		System.out.println("Blood Data: " + this.blood_data);	
	}
}

class Testpatient{
	public static void main(String args[]){
		
		Scanner sc = new Scanner(System.in);
		Scanner str = new Scanner(System.in);
		System.out.print("Enter the patients id number: ");
		int id = sc.nextInt();
		System.out.print("\nEnter the patients age: ");
		int age = sc.nextInt();
		System.out.print("\nEnter the patients blood type: ");
		String data = str.nextLine();
		
		Patient patient1 = new Patient();
		Patient patient2 = new Patient(id,age,data);
		patient2.get_id();
		patient2.get_age();
		patient2.get_blood_data();
	}
}
