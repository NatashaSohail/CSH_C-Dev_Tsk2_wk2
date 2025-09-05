#include <iostream>
#include <string>
using namespace std;


struct Student {
    int roll;
    string name;
    float gpa;
    Student* next;
};

// Head pointer for the linked list
Student* head = nullptr;

// Add a new student at the end
void addStudent(int roll, string name, float gpa) {
    Student* newStudent = new Student;
    newStudent->roll = roll;
    newStudent->name = name;
    newStudent->gpa = gpa;
    newStudent->next = nullptr;

    if (head == nullptr) {
        head = newStudent;
    } else {
        Student* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newStudent;
    }
    cout << "Student added successfully!\n";
}

// Delete a student by roll number
void deleteStudent(int roll) {
    if (head == nullptr) {
        cout << "No students to delete!\n";
        return;
    }

    if (head->roll == roll) {
        Student* temp = head;
        head = head->next;
        delete temp;
        cout << "Student deleted successfully!\n";
        return;
    }

    Student* prev = head;
    Student* curr = head->next;
    while (curr != nullptr && curr->roll != roll) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == nullptr) {
        cout << "Student not found!\n";
    } else {
        prev->next = curr->next;
        delete curr;
        cout << "Student deleted successfully!\n";
    }
}

// Search a student by roll number
void searchStudent(int roll) {
    Student* temp = head;
    while (temp != nullptr) {
        if (temp->roll == roll) {
            cout << "Student Found: Roll: " << temp->roll
                 << ", Name: " << temp->name
                 << ", GPA: " << temp->gpa << "\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Student not found!\n";
}

// Display all students
void displayAll() {
    if (head == nullptr) {
        cout << "No students available!\n";
        return;
    }

    Student* temp = head;
    cout << "\n--- Student List ---\n";
    while (temp != nullptr) {
        cout << "Roll: " << temp->roll
             << " | Name: " << temp->name
             << " | GPA: " << temp->gpa << "\n";
        temp = temp->next;
    }
}

int main() {
    int choice;
    while (true) {
        cout << "\n=== Student Management System ===\n";
        cout << "1. Add Student\n";
        cout << "2. Delete Student\n";
        cout << "3. Search Student\n";
        cout << "4. Display All Students\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int roll;
            string name;
            float gpa;
            cout << "Enter Roll Number: ";
            cin >> roll;
            cin.ignore();
            cout << "Enter Name: ";
            getline(cin, name);
            cout << "Enter GPA: ";
            cin >> gpa;
            addStudent(roll, name, gpa);
        } 
        else if (choice == 2) {
            int roll;
            cout << "Enter Roll Number to delete: ";
            cin >> roll;
            deleteStudent(roll);
        } 
        else if (choice == 3) {
            int roll;
            cout << "Enter Roll Number to search: ";
            cin >> roll;
            searchStudent(roll);
        } 
        else if (choice == 4) {
            displayAll();
        } 
        else if (choice == 5) {
            cout << "Exiting...\n";
            break;
        } 
        else {
            cout << "Invalid choice! Try again.\n";
        }
    }

    // Free all memory before exit
    while (head != nullptr) {
        Student* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
