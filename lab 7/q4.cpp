#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class Person {
protected:
    string name;
    int id;
    string address;
    string phoneNumber;
    string email;

public:
    Person(string name, int id, string address, string phoneNumber, string email)
        : name(name), id(id), address(address), phoneNumber(phoneNumber), email(email) {}

    virtual void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Address: " << address << endl;
        cout << "Phone: " << phoneNumber << endl;
        cout << "Email: " << email << endl;
    }

    void updateInfo(string newAddress, string newPhoneNumber, string newEmail) {
        address = newAddress;
        phoneNumber = newPhoneNumber;
        email = newEmail;
    }

    virtual ~Person() {}

    int getId() const {
        return id;
    }

    string getName() const {
        return name;
    }
};

class Student : public Person {
private:
    vector<string> coursesEnrolled;
    double GPA;
    int enrollmentYear;

public:
    Student(string name, int id, string address, string phoneNumber, string email, double GPA, int enrollmentYear)
        : Person(name, id, address, phoneNumber, email), GPA(GPA), enrollmentYear(enrollmentYear) {}

    void enrollInCourse(const string& courseName) {
        coursesEnrolled.push_back(courseName);
    }

    void displayInfo() override {
        Person::displayInfo();
        cout << "Courses Enrolled: ";
        for (const string& course : coursesEnrolled) {
            cout << course << " ";
        }
        cout << endl;
        cout << "GPA: " << GPA << endl;
        cout << "Enrollment Year: " << enrollmentYear << endl;
    }

    ~Student() {}
};

class Professor : public Person {
private:
    string department;
    vector<string> coursesTaught;
    double salary;

public:
    Professor(string name, int id, string address, string phoneNumber, string email, string department, double salary)
        : Person(name, id, address, phoneNumber, email), department(department), salary(salary) {}

    void addCourseTaught(const string& courseName) {
        coursesTaught.push_back(courseName);
    }

    void displayInfo() override {
        Person::displayInfo();
        cout << "Department: " << department << endl;
        cout << "Courses Taught: ";
        for (const string& course : coursesTaught) {
            cout << course << " ";
        }
        cout << endl;
        cout << "Salary: " << salary << endl;
    }

    ~Professor() {}
};

class Staff : public Person {
private:
    string department;
    string position;
    double salary;

public:
    Staff(string name, int id, string address, string phoneNumber, string email, string department, string position, double salary)
        : Person(name, id, address, phoneNumber, email), department(department), position(position), salary(salary) {}

    void displayInfo() override {
        Person::displayInfo();
        cout << "Department: " << department << endl;
        cout << "Position: " << position << endl;
        cout << "Salary: " << salary << endl;
    }

    ~Staff() {}
};

class Course {
private:
    int courseId;
    string courseName;
    int credits;
    Professor* instructor;
    string schedule;
    vector<Student*> studentsRegistered;

public:
    Course(int courseId, string courseName, int credits, Professor* instructor, string schedule)
        : courseId(courseId), courseName(courseName), credits(credits), instructor(instructor), schedule(schedule) {}

    void registerStudent(Student* student) {
        studentsRegistered.push_back(student);
    }

    void calculateGrades() {
        cout << "Grades for course: " << courseName << endl;
        for (Student* student : studentsRegistered) {
            cout << "Student ID: " << student->getId() << " - Grade: A" << endl;
        }
    }

    void displayCourseInfo() {
        cout << "Course Name: " << courseName << endl;
        cout << "Credits: " << credits << endl;
        cout << "Instructor: " << instructor->getName() << endl;
        cout << "Schedule: " << schedule << endl;
    }

    int getCourseId() const { return courseId; }
    string getCourseName() const { return courseName; }

    ~Course() {}
};

int main() {
    Professor prof("Dr. Emily Chen", 110, "45 Scholar Ln", "555-1122", "e.chen@university.edu", "Mathematics", 92000);
    Student student("Alicia Torres", 215, "89 Dorm Rd", "555-3344", "alicia.t@student.edu", 3.6, 2022);
    Staff staff("Marcus Lee", 330, "21 Admin Plaza", "555-7788", "m.lee@university.edu", "Facilities", "Manager", 58000);

    Course math101(205, "Calculus I", 4, &prof, "TTh 10:00-11:30 AM");

    math101.registerStudent(&student);

    cout << "\n--- Professor Info ---\n";
    prof.displayInfo();
    cout << "\n--- Student Info ---\n";
    student.displayInfo();
    cout << "\n--- Staff Info ---\n";
    staff.displayInfo();

    cout << "\n--- Course Info ---\n";
    math101.displayCourseInfo();

    cout << "\n--- Course Grades ---\n";
    math101.calculateGrades();

    return 0;
}
