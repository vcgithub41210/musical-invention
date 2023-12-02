import java.io.*;
import java.util.Scanner;

class FileWriting{
    public static void main(String args[]){
        File myObj = new File("content.txt");
        try{
            if (myObj.createNewFile()){
                System.out.println("File successfully created!");
            }
            else{
                System.out.println("File already exists!");
            }
        }
        catch(IOException e){
            System.out.println("Some error has occured!");
            e.printStackTrace();
        }
        try{
            Scanner sc = new Scanner(System.in);
            FileWriter newWrite = new FileWriter(myObj);
            System.out.print("Enter the name of the person: ");
            newWrite.write("Name: "+ sc.nextLine()+"\n");
            System.out.print("Enter the age of the person: ");
            newWrite.write("Age: "+ sc.nextLine()+"\n");
            System.out.print("Enter the profession of the person: ");
            newWrite.write("Profession: "+ sc.nextLine()+"\n");
            newWrite.close();
        }
        catch(IOException e){
            System.out.println("Failed to write into the file!");
            e.printStackTrace();
        }
        try{
            Scanner newScanner = new Scanner(myObj);
            while(newScanner.hasNextLine()){
                String data = newScanner.nextLine();
                System.out.println(data);
            }
            newScanner.close();
        }
        catch(IOException e){
            System.out.println("Some error has occured!");
            e.printStackTrace();
        }
    }
}

//sample output
/*
File successfully created!
Enter the name of the person: Brad Ortiz
Enter the age of the person: 23
Enter the profession of the person: Data Analyst
Name: Brad Ortiz
Age: 23
Profession: Data Analyst
*/