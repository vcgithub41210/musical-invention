/*
This is a program to demonstrate how to handle with files
*/

import java.io.*;

class FileHandling{
    public static void main(String args[]){
        try{
            File myObj = new File("content.txt");
            if(myObj.createNewFile()){
                System.out.println("File created!");
            }else{
                System.out.println("File Already Exists");
            }
        }
        catch(IOException e){
            System.out.println("Some error has occured! " + e);
            e.printStackTrace();
        }
        finally{
            try{
                File newObj = new File("/anonymous/Data.txt");
                if(newObj.createNewFile()){
                    System.out.println("File created!");
                }else{
                    System.out.println("File Already Exists");
                }
            }
            catch(IOException e){
                System.out.println("Some error must definetly occur!");
                e.printStackTrace();
            }
        }
        System.out.println("End of program...");
    }
}

//sample output

//RUNNING FIRST TIME
/*
File created!
Some error must definetly occur!
java.io.IOException: No such file or directory
        at java.base/java.io.UnixFileSystem.createFileExclusively(Native Method)
        at java.base/java.io.File.createNewFile(File.java:1035)
        at FileHandling.main(FileHandling.java:24)
End of program...
*/

//RUNNING SECOND TIME
/*
File Already Exists
Some error must definetly occur!
java.io.IOException: No such file or directory
        at java.base/java.io.UnixFileSystem.createFileExclusively(Native Method)
        at java.base/java.io.File.createNewFile(File.java:1035)
        at FileHandling.main(FileHandling.java:24)
End of program...
*/