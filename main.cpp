#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student {
    int rollNumber;
    string name;
    int age;
};

void insertStudent(vector<Student>& students) {
    Student newStudent;
    cout << "Enter roll number: ";
    cin >> newStudent.rollNumber;
    cin.ignore();
    cout << "Enter name: ";
    getline(cin, newStudent.name);
    cout << "Enter age: ";
    cin >> newStudent.age;

    students.push_back(newStudent);
    cout << "STUDENT INSERTED SUCCESSFULLY!.." << endl;
}

void updateStudent(vector<Student>& students) {
    int rollNumber;
    cout << "Enter roll number of the student to update: ";
    cin >> rollNumber;
    cin.ignore(); 
  
    for (auto& student : students) {
        if (student.rollNumber == rollNumber) {
            cout << "What do you want to update?" << endl;
            cout << "1. Name" << endl;
            cout << "2. Age" << endl;
            cout << "0. Menu" << endl;

            int choice;
            cin >> choice;
            cin.ignore(); 

            switch (choice) {
                case 1:
                    cout << "Enter updated name: ";
                    getline(cin, student.name);
                    cout << "STUDENT UPDATED SUCCESSFULLY!.." << endl;
                    break;
                case 2:
                    cout << "Enter updated age: ";
                    cin >> student.age;
                    cout << "STUDENT UPDATED SUCCESSFULLY!.." << endl;
                    break;
                case 0:
                    cout << "Returning to the main menu." << endl;
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
            return;
        }
    }

    cout << "Student with roll number " << rollNumber << " not found." << endl;
}

void deleteStudent(vector<Student>& students) {
    int rollNumber;
    cout << "Enter roll number of the student to delete: ";
    cin >> rollNumber;
    cin.ignore(); 

    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->rollNumber == rollNumber) {
            students.erase(it);
            cout << "Student with roll number " << rollNumber << " deleted successfully!" << endl;
            return;
        }
    }

    cout << "Student with roll number " << rollNumber << " not found." << endl;
}


void showStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students in the database." << endl;
        return;
    }

    cout << "--- Student Records ---" << endl;
    for (const auto& student : students) {
        cout << "Roll Number: " << student.rollNumber << endl;
        cout << "Name: " << student.name << endl;
        cout << "Age: " << student.age << endl;
        cout << "-----------------------" << endl;
    }
}


void searchStudent(const vector<Student>& students) {
    int rollNumber;
    cout << "Enter roll number of the student to search: ";
    cin >> rollNumber;
    cin.ignore();

    for (const auto& student : students) {
        if (student.rollNumber == rollNumber) {
            cout << "--- Student Details ---" << endl;
            cout << "Roll Number: " << student.rollNumber << endl;
            cout << "Name: " << student.name << endl;
            cout << "Age: " << student.age << endl;
            cout << "-----------------------" << endl;
            return;
        }
    }

    cout << "Student with roll number " << rollNumber << " not found." << endl;
}

int main() {
    vector<Student> students;
    int choice;

    while (true) {
        cout << "<<<<<<< Student Management System >>>>>>>>" << endl;
        cout << "1. Insert Student" << endl;
        cout << "2. Update Student" << endl;
        cout << "3. Delete Student" << endl;
        cout << "4. Show Students" << endl;
        cout << "5. Search Student" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1:
                insertStudent(students);
                break;
            case 2:
                updateStudent(students);
                break;
            case 3:
                deleteStudent(students);
                break;
            case 4:
                showStudents(students);
                break;
            case 5:
                searchStudent(students);
                break;
            case 0:
                cout << "*************************************** EXIT PROGRAM ***************************************" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << "<<<<<<< Student Management System >>>>>>>>" << endl;
    }

    return 0;
}
