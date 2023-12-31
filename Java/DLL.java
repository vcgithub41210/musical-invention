import java.io.*;
import java.util.Scanner;

class Node{
    int data;
    Node next;
    Node prev;
    Node(int data){
        this.data = data;
        this.next = null;
        this.prev = null;
    }
    void DeleteNode(){
        Scanner ab = new Scanner(System.in);
        System.out.print("Enter the data of the node to be deleted: ");
        int value = ab.nextInt();
        Node temp = this;
        while(temp != null){
            if(temp.data == value){
                if(temp == this){
                    this.data = (this.next).data;
                    this.next = (this.next).next;
                    this.prev = null;
                    return;
                }
                (temp.prev).next = temp.next;
                if(temp.next != null){
                    (temp.next).prev = temp.prev;
                }
                return;
            }
            temp = temp.next;
        }
        System.out.println("The Node is not found!");
    }
    void InsertEnd(){
        Scanner xy = new Scanner(System.in);
        System.out.print("Enter the data of the new node: ");
        Node new_node = new Node(xy.nextInt());
        Node temp = this;
        while(temp.next != null){
            temp = temp.next;
        }
        temp.next = new_node;
        new_node.prev = temp;
    }
    void Display(){
        Node temp = this;
        while(temp != null){
            System.out.print("<-["+temp.data+"]->");
            temp = temp.next;
        }
        System.out.println();

    }
}

class DLL{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        Node head = null;
        System.out.println("Enter the operation to perform\n(1)Insert at end\n(2)Delete Node\n(3)Quit");
        int operand;

        do{
            System.out.print("=> ");
            operand = sc.nextInt();
            switch(operand){
                case 1:
                    if(head == null){
                        System.out.println("Enter the data of the new node: ");
                        head = new Node(sc.nextInt());
                        break;
                    }
                    head.InsertEnd();
                    break;
                case 2:
                    if(head != null) {
                        if(head.next == null){
                            System.out.println("Enter the data of the node to be deleted: ");
                            if(sc.nextInt() != head.data){
                                System.out.println("The Node is not found!");
                                break;
                            }
                            else head = null;
                        }
                        else head.DeleteNode();
                    }
                    else System.out.println("List is empty!");
                    break;
                case 3:
                    continue;
                default:
                    System.out.println("Invalid operation!");
            }
            if (head != null) head.Display();
        }
        while(operand != 3);
    }
}

//sample output
/*
Enter the operation to perform
(1)Insert at end
(2)Delete Node
(3)Quit
=> 1
Enter the data of the new node: 
10
<-[10]->
=> 1
Enter the data of the new node: 45
<-[10]-><-[45]->
=> 1
Enter the data of the new node: 208
<-[10]-><-[45]-><-[208]->
=> 2
Enter the data of the node to be deleted: 45
<-[10]-><-[208]->
=> 2
Enter the data of the node to be deleted: 10
<-[208]->
=> 2
Enter the data of the node to be deleted: 
208
=> 2
List is empty!
=> 3
*/