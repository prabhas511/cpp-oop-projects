#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

class Student {
private:
    int rollNo;
    string name;
    float marks;

public:
    Student(int r, const string& n, float m) : rollNo(r), name(n), marks(m) {}

    int getRollNo() const { return rollNo; }
    string getName() const { return name; }
    float getMarks() const { return marks; }

    char getGrade() const {
        if (marks >= 90) return 'A';
        if (marks >= 75) return 'B';
        if (marks >= 60) return 'C';
        if (marks >= 50) return 'D';
        return 'F';
    }

    void display() const {
        cout << "Roll No: " << rollNo
             << " | Name: " << name
             << " | Marks: " << marks
             << " | Grade: " << getGrade() << '\n';
    }
};

class StudentManager {
private:
    vector<Student> students;

public:
    void addStudent() {
        int roll;
        string name;
        float marks;

        cout << "Enter roll number: ";
        cin >> roll;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter name: ";
        getline(cin, name);

        cout << "Enter marks: ";
        cin >> marks;

        students.emplace_back(roll, name, marks);
        cout << "Student added successfully.\n";
    }

    void displayAll() const {
        if (students.empty()) {
            cout << "No students available.\n";
            return;
        }

        for (const Student& student : students)
            student.display();
    }

    void searchStudent() const {
        int roll;
        cout << "Enter roll number to search: ";
        cin >> roll;

        for (const Student& student : students) {
            if (student.getRollNo() == roll) {
                student.display();
                return;
            }
        }

        cout << "Student not found.\n";
    }
};

int main() {
    StudentManager manager;
    int choice;

    do {
        cout << "\n--- Student Management System ---\n";
        cout << "1. Add Student\n2. Display All\n3. Search Student\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: manager.addStudent(); break;
            case 2: manager.displayAll(); break;
            case 3: manager.searchStudent(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}
