import java.io.*;
import java.util.Scanner;

class Node{
    int data;
    Node next;
    Node prev;
    Node(){
        this.data = -1000;
    }
    Node(int data){
        this.data = data;
        this.next = null;
        this.prev = null;
    }
    void DeleteNode(){
        Scanner ab = new Scanner(System.in);
        if(this.data == -1000){
            System.out.println("List is empty!");
            return;
        }
        System.out.print("Enter the data of the node to be deleted: ");
        int value = ab.nextInt();
        Node temp = this;
        while(temp != null){
            if(temp.data == value){
                if(temp == this){
                    if(this.next == null){
                        this.data = -1000;
                        return;
                    }
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
        if(this.data != -1000){
            Node new_node = new Node(xy.nextInt());
            Node temp = this;
            while(temp.next != null){
                temp = temp.next;
            }
            temp.next = new_node;
            new_node.prev = temp;
        }
        else{
            this.data = xy.nextInt();
            return;
        }
    }
    void Display(){
        if(this.data == -1000){
            System.out.println("List is empty!");
            return;
        }
        else{
            Node temp = this;
            while(temp != null){
                System.out.print("<-["+temp.data+"]->");
                temp = temp.next;
            }
            System.out.println();
        }
    }
}

class DLL{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        Node head = new Node();
        System.out.println("Enter the operation to perform\n(1)Insert at end\n(2)Delete Node\n(3)Quit");
        int operand;

        do{
            System.out.print("=> ");
            operand = sc.nextInt();
            switch(operand){
                case 1:
                    head.InsertEnd();
                    break;
                case 2:
                    head.DeleteNode();
                    break;
                case 3:
                    continue;
                default:
                    System.out.println("Invalid operation!");
            }
            if (head.data != -1000)head.Display();
        }
        while(operand != 3);
    }
}