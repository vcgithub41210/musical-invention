/**
 * This is a program to demonstrate how to handle with files
 * Files are the main source of storing data and it is important to know the ways of manipulating files and its data
 * In Java, to use files we have to create an object of the class File
 * The File class is present inside the io package and can be imported using the following syntax;
 * syntax -  import java.io.File
 * Additionally you can also use '*' operator to import everything inside the io package as we would be needing more than just File object to deal with Files
 * 
 * A File object is created using the 'new' keyword and the File() constructor, passing the name of the file or the directory of the file
 * The syntax is as follows -  File name_of_object = new File("filename or directory of file")
 * It is important to create this object inside a try block as the program may file to create the object and throw errors
 * The file need not necessarily exist in your computer, if not you can create the file using the object.. which is one of the reason to use the File class
 * One error that could be thrown is IOException due to passing non-existent directory
 * so even though passing non-existent filename is possible, it is not possible to pass non-existent directory
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