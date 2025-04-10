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