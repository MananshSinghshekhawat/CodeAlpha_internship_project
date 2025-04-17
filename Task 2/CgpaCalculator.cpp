/* class to calculte cgpa of each subject the user will enter and The user’s input is used to compute the CGPA, which
includes information like the number of courses taken and
the grades earned in each one. The program also shows each
student’s overall course grade. CGPA Calculator calculates a
student’s Cumulative Grade Point Average (CGPA) from the
given exam results. The program can show the individual
grades of each course, calculate total credits and total grade
points achieved, determine the GPA for the semester, and
based on all the data, it can generate and present the CGPA
of the student.*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

struct Details
{
    string courseName;
    double gradePoint;
    int credit;
};

class Student
{
private:
    string name;
    string rollnumber;
    int numberofcourses;
    vector<Details> courses;

public:
    void StudentInfo()
    {
        std::cout << "Enter the student name : ";
        std::getline(cin, name);
        std::cout << "Enter the student roll number :";
        std::getline(cin, rollnumber);
        std::cout << "Enter the number of courses : ";
        std::cin >> numberofcourses;
        std::cout << endl;

        for (int i = 0; i < numberofcourses; i++)
        {
            inputcourse(i);
            std::cout << endl;
        }
        std::cout << endl;
    }

    void inputcourse(int courseIndex)
    {
        Details course;
        std::cout << "Enter the course name :";
        std::cin >> course.courseName;
        std::cout << "Enter the grade point :";
        std::cin >> course.gradePoint;
        std::cout << "Enter the credit : ";
        std::cin >> course.credit;
        courses.push_back(course);
    }

    int calculateTotalCredits()
    {
        int totalCredits = 0;
        for (const auto& course : courses) {
            totalCredits += course.credit;
        }
        return totalCredits;
    }

    float calculateTotalGradePoints()
    {
        float totalGradePoints = 0;
        for (const auto& course : courses) {
            totalGradePoints += course.gradePoint * course.credit;
        }
        return totalGradePoints;
    }
    float calculateGPA()
    {
        float totalgradepoints = calculateTotalGradePoints();
        float totalcredits = calculateTotalCredits();
        return totalgradepoints / totalcredits;
    }

    void displayAllDetails()
    {
        std::cout << "The details below to know your grade and CGPA : \n";
        std::cout << "Student Name :" << name << endl;
        std::cout << "Roll Number :" << rollnumber << endl;
        std::cout << "Number of courses :" << numberofcourses << endl;

        for(const auto& courses : courses) {
            std::cout << "Course Name : " << courses.courseName << endl;
            std::cout << "Grade Point : " << courses.gradePoint << endl;
            std::cout << "Credit : " << courses.credit << endl;
            std::cout << "-------------------------------" << endl;
            float grade = (courses.gradePoint / courses.credit) * 100;
            std::cout << "Grade for this course : " << grade << "%" << endl;
            std::cout << "-------------------------------" << endl;
            std::cout << endl;
            float overallGrade = calculateGPA() * 100;
            std::cout << "Overall Grade for this student : " << overallGrade << "%" << endl;
            std::cout << "-------------------------------" << endl;
            std::cout << endl;

        }
        std::cout << "CGPA for this student : " << calculateGPA() << endl;
        std::cout << "-------------------------------" << endl;
        std::cout << endl;
        std::cout << "Press any key to exit..." << endl;
        getchar();
        return ;
        
    }

    
};

int main()
{
    Student student;
    student.StudentInfo();
    student.displayAllDetails();

    return 0;
}