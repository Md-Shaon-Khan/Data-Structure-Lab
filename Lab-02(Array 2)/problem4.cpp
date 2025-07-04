#include<bits/stdc++.h>
using namespace std;

struct Student {
    int id;
    string name;
    float marks;
};

void displayStudent(Student *stu) {
    cout << "Student name: " << stu->name << endl;
    cout << "Student id: " << stu->id << endl;
    cout << "Student marks: " << stu->marks << endl;
}

int main() {
    Student s1;
    Student *ptr;

    ptr = &s1;

    cout << "Enter the Student ID: ";
    cin >> ptr->id;

    cout << "Enter the Student Name: ";
    cin.ignore(); 
    getline(cin, ptr->name); 

    cout << "Enter the Student Marks: ";
    cin >> ptr->marks;

    cout << "_______Students Details_______" << endl;
    displayStudent(ptr);

    return 0;
}