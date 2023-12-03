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
            Scanner sc = new Scanner(System.in);
            FileOutputStream fout = new FileOutputStream(myObj);

            System.out.print("Enter the name of the person: ");
            fout.write(("Name: " + sc.nextLine() +"\n").getBytes());

            System.out.print("Enter the age of the person: ");
            fout.write(("Age: " + sc.nextLine() + "\n").getBytes());

            System.out.print("Enter the profession of the person: ");
            fout.write(("Profession: "+sc.nextLine() + "\n").getBytes());

            fout.close();

            FileInputStream fin = new FileInputStream(myObj);
            int a = fin.read();
            while(a != -1){
                System.out.print((char) a);
                a = fin.read();
            }
            // Scanner newScanner = new Scanner(myObj);
            // while(newScanner.hasNextLine()){
            //     String data = newScanner.nextLine();
            //     System.out.println(data);
            // }
            // newScanner.close();
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