#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int rn;
    float cgpa;
    vector<string> courses;

public:
    Student() : name("Unknown"), rn(0000), cgpa(0.0) {}

    Student(string n, int r, float c) {
        name = n;
        rn = r;
        if (c >= 0.0 && c <= 10.0)
            cgpa = c;
        else {
            cgpa = 0.0;
            cout << "Invalid CGPA. GCGPA is Set to 0.0" << endl;
        }
    }

    Student(const Student &other) {
        name = other.name;
        rn = other.rn;
        cgpa = other.cgpa;
        courses = other.courses;
    }

    void addCourse(const string &course) {
        if (!course.empty()) {
            courses.push_back(course);
        } else {
            cout << "Invalid course name." << endl;
        }
    }

    void updateCGPA(float newCGPA) {
        if (newCGPA >= 0.0 && newCGPA <= 10.0) {
            cgpa = newCGPA;
        } else {
            cout << "Invalid CGPA. Please enter a value between 0.0 and 10.0" << endl;
        }
    }

    void displayInfo() const {
        cout << "Name: " << name << "\nRoll Number: " << rn
             << "\nCGPA: " << cgpa << "\nCourses: ";
        if (courses.empty()) {
            cout << "None";
        } else {
            for (const auto &course : courses)
                cout << course << ", ";
        }
        cout << "\n------------------------" << endl;
    }

    int getRn() const {
        return rn;
    }
};

class StudentManagementSystem {
private:
    vector<Student> students;

public:
    void addStudent(const Student &student) {
        students.push_back(student);
    }

    Student* searchStudent(int rollNumber) {
        for (auto &student : students) {
            if (student.getRn() == rollNumber)
                return &student;
        }
        return nullptr;
    }

    void displayStudents() const {
        if (students.empty()) {
            cout << "No student records available." << endl;
            return;
        }
        for (const auto &student : students) {
            student.displayInfo();
        }
    }
};

int main() {
    StudentManagementSystem sms;

    Student s1("alice", 101, 9.5);
    Student s2("bob", 102, 8.7);
    Student s3 = s1;

    s1.addCourse("Mathematics");
    s1.addCourse("Physics");
    s2.addCourse("Chemistry");

    s1.updateCGPA(9.8);

    sms.addStudent(s1);
    sms.addStudent(s2);
    sms.addStudent(s3);

    sms.displayStudents();

    int roll;
    cout << "Enter roll number to search: ";
    cin >> roll;
    Student* result = sms.searchStudent(roll);
    if (result)
        result->displayInfo();
    else
        cout << "Student not found." << endl;

    return 0;
}