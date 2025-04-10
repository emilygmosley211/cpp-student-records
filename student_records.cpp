#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
#include <vector>
#include <algorithm>

using namespace std;

// Enum to define grade levels
enum GradeLevel {
    FRESHMAN = 1,
    SOPHOMORE,
    JUNIOR,
    SENIOR
};

// Typedef or using for simplified data type definitions
using GPA = float;
using StudentName = string;

// Student structure to hold student details
struct Student {
    StudentName name;
    GradeLevel gradeLevel;
    GPA gpa;

    // Constructor for easier student creation
    Student(const StudentName& n, GradeLevel g, GPA gpa) : name(n), gradeLevel(g), gpa(gpa) {}
};
// Define a custom namespace for student-related functions
namespace StudentUtils {

    // Function to convert student name to uppercase
    void formatName(StudentName &name) {
        for (char &ch : name) {
            ch = toupper(ch); // Convert each character to uppercase
        }
    }

    // Function to display student information
    void displayStudentInfo(const Student& student) {
        string gradeStr;
        switch (student.gradeLevel) {
            case FRESHMAN: gradeStr = "Freshman"; break;
            case SOPHOMORE: gradeStr = "Sophomore"; break;
            case JUNIOR: gradeStr = "Junior"; break;
            case SENIOR: gradeStr = "Senior"; break;
            default: gradeStr = "Unknown"; break;
        }
           // Format GPA to two decimal places
           cout << fixed << setprecision(2);
           cout << "Student Record:" << endl;
           cout << "Name: " << student.name << endl;
           cout << "Grade Level: " << gradeStr << endl;
           cout << "GPA: " << student.gpa << endl;
       }
   
       // Function to compare students by name for sorting
       bool compareByName(const Student& a, const Student& b) {
           return a.name < b.name;
       }
   
       // Function to validate GPA (between 0.00 and 4.00)
       bool isValidGPA(GPA gpa) {
           return gpa >= 0.00 && gpa <= 4.00;
       }
   
   } // End of namespace StudentUtils
   int main() {
    vector<Student> students; // Vector to hold multiple students
    string name;
    int gradeLevelInput;
    GPA gpa;
    char addMoreStudents = 'y';

    // Loop to allow input of multiple students
    while (addMoreStudents == 'y' || addMoreStudents == 'Y') {
        // Student Data Input
        cout << "Enter student name: ";
        getline(cin, name); // Allow spaces in the name

        cout << "Enter grade level (1=Freshman, 2=Sophomore, 3=Junior, 4=Senior): ";
        cin >> gradeLevelInput;

        // Validate grade level input
        if (gradeLevelInput < 1 || gradeLevelInput > 4) {
            cout << "Invalid grade level! Please enter a value between 1 and 4." << endl;
            return 1;
        }

        GradeLevel gradeLevel = static_cast<GradeLevel>(gradeLevelInput);

        // GPA validation loop
        do {
            cout << "Enter GPA: ";
            cin >> gpa;
            if (!StudentUtils::isValidGPA(gpa)) {
                cout << "Invalid GPA! Please enter a GPA between 0.00 and 4.00." << endl;
            }
        } while (!StudentUtils::isValidGPA(gpa));

        // Process the student's name to uppercase
        StudentUtils::formatName(name);

        // Add the student to the vector
        students.emplace_back(name, gradeLevel, gpa);

        // Ask if the user wants to add another student
        cout << "Do you want to add another student? (y/n): ";
        cin >> addMoreStudents;
        cin.ignore(); // To discard the newline character left in the input buffer
    }

    // Sort the students by name using the custom comparison function
    sort(students.begin(), students.end(), StudentUtils::compareByName);

    // Display all students' information
    cout << "\nStudent Records:\n";
    for (const auto& student : students) {
        StudentUtils::displayStudentInfo(student);
        cout << endl;
    }

    return 0;
}