import java.util.*;

public class StudentMain {
    static class Student {
        String name;
        int roll;
        double mark;

        void setStudentDetails() {
            Scanner sc = new Scanner(System.in);
            while (sc.hasNextLine()) {
                name = sc.nextLine();
                roll = sc.nextInt();
                mark = sc.nextDouble();
            }

        }

        void displayStudent() {
            System.out.println("Student Name: " + name);
            System.out.println("Student Roll NO: " + roll);
            System.out.println("Student Marks: " + mark);
        }
    }

    static class SinglyLinkedList {

        Node start;

        class Node {
            Student stud;
            Node link;

            Node() {
                stud = new Student();
                stud.setStudentDetails();
                link = null;
            }
        }

        Scanner sc = new Scanner(System.in);

        void create() {
            Node new_node = new Node();
            new_node.link = start;
            start = new_node;
        }

        void displayLinkedList() {
            Node tnode = start;
            while (tnode != null) {
                tnode.stud.displayStudent();
                tnode = tnode.link;
            }
        }

        void findTopper() {

        }

        void displayFailedList() {

        }

        void sort() {

        }
    }

    public static void main(String[] args) {
        SinglyLinkedList singlyLinkedList = new SinglyLinkedList();
        singlyLinkedList.create();
        singlyLinkedList.create();
        singlyLinkedList.displayLinkedList();
    }
}