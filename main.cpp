#include <iostream>
#include <string>
using namespace std;

int studentID[100];
string studentName[100];
char attendance[100][100];

int studentCount = 0;
int totalDays = 0;

// Add Student
void addStudent() {
    int id;

    if (studentCount == 100) {
        cout << "\nStudent limit is full!\n";
        return;
    }

    cout << "\nEnter Student ID (1001-1100): ";
    cin >> id;

    if (id < 1001 || id > 1100) {
        cout << "Invalid Student ID!\n";
        return;
    }

    // Check duplicate ID
    for (int i = 0; i < studentCount; i++) {
        if (studentID[i] == id) {
            cout << "Student ID already exists!\n";
            return;
        }
    }

    studentID[studentCount] = id;

    cout << "Enter Student Name: ";
    cin.ignore();
    getline(cin, studentName[studentCount]);

    studentCount++;

    cout << "\nStudent added successfully!\n";
}

// View Students
void viewStudents() {
    if (studentCount == 0) {
        cout << "\nNo students registered!\n";
        return;
    }

    cout << "\n===== STUDENT LIST =====\n";

    for (int i = 0; i < studentCount; i++) {
        cout << "ID: " << studentID[i];
        cout << " | Name: " << studentName[i] << endl;
    }
}

// Record Attendance
void recordAttendance() {
    if (studentCount == 0) {
        cout << "\nNo students registered!\n";
        return;
    }

    if (totalDays == 100) {
        cout << "\nMaximum attendance days reached!\n";
        return;
    }

    cout << "\n===== RECORD ATTENDANCE =====\n";
    cout << "Day " << totalDays + 1 << endl;

    for (int i = 0; i < studentCount; i++) {
        char status;

        cout << "\n" << studentName[i] << endl;

        do {
            cout << "Present or Absent? (P/A): ";
            cin >> status;

            if (status != 'P' && status != 'p' &&
                status != 'A' && status != 'a') {
                cout << "Invalid input! Try again.\n";
            }

        } while (status != 'P' && status != 'p' &&
                 status != 'A' && status != 'a');

        if (status == 'p') {
            status = 'P';
        }

        if (status == 'a') {
            status = 'A';
        }

        attendance[i][totalDays] = status;
    }

    totalDays++;

    cout << "\nAttendance recorded successfully!\n";
}

// View Attendance Records
void viewAttendance() {
    if (studentCount == 0 || totalDays == 0) {
        cout << "\nNo attendance records available!\n";
        return;
    }

    cout << "\n===== ATTENDANCE RECORDS =====\n";

    for (int i = 0; i < studentCount; i++) {
        cout << "\n" << studentID[i]
             << " - " << studentName[i] << endl;

        for (int j = 0; j < totalDays; j++) {
            cout << "Day " << j + 1 << ": "
                 << attendance[i][j] << endl;
        }
    }
}

// Search Student - Linear Search
void searchStudent() {
    int id;
    int found = -1;

    cout << "\nEnter Student ID to search: ";
    cin >> id;

    for (int i = 0; i < studentCount; i++) {
        if (studentID[i] == id) {
            found = i;
            break;
        }
    }

    if (found != -1) {
        cout << "\nStudent Found!\n";
        cout << "ID: " << studentID[found] << endl;
        cout << "Name: " << studentName[found] << endl;
    } else {
        cout << "\nStudent not found!\n";
    }
}

// Sort Students - Bubble Sort
void sortStudents() {
    string tempName;
    int tempID;
    char tempAttendance;

    for (int i = 0; i < studentCount - 1; i++) {
        for (int j = 0; j < studentCount - i - 1; j++) {

            if (studentName[j] > studentName[j + 1]) {

                tempName = studentName[j];
                studentName[j] = studentName[j + 1];
                studentName[j + 1] = tempName;

                tempID = studentID[j];
                studentID[j] = studentID[j + 1];
                studentID[j + 1] = tempID;

                for (int k = 0; k < totalDays; k++) {
                    tempAttendance = attendance[j][k];
                    attendance[j][k] = attendance[j + 1][k];
                    attendance[j + 1][k] = tempAttendance;
                }
            }
        }
    }

    cout << "\nStudents sorted alphabetically!\n";
}

// Calculate Attendance Percentage
void attendancePercentage() {
    int id;
    int found = -1;
    int present = 0;
    double percentage;

    if (totalDays == 0) {
        cout << "\nNo attendance records available!\n";
        return;
    }

    cout << "\nEnter Student ID: ";
    cin >> id;

    for (int i = 0; i < studentCount; i++) {
        if (studentID[i] == id) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        cout << "\nStudent not found!\n";
        return;
    }

    for (int j = 0; j < totalDays; j++) {
        if (attendance[found][j] == 'P') {
            present++;
        }
    }

    percentage = (double)present / totalDays * 100;

    cout << "\nStudent Name: " << studentName[found];
     cout << "\nPresent Days: " << present;
    cout << "\nTotal Days: " << totalDays;
    cout << "\nAttendance Percentage: "
         << percentage << "%\n";
}

// Main Program
int main() {
    int choice;

    do {
        cout << "\n====================================\n";
        cout << " STUDENT ATTENDANCE MONITORING SYSTEM\n";
        cout << "====================================\n";

        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Record Attendance\n";
        cout << "4. View Attendance Records\n";
        cout << "5. Search Student\n";
        cout << "6. Sort Students\n";
        cout << "7. Attendance Percentage\n";
        cout << "8. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;

            case 2:
                viewStudents();
                break;

            case 3:
                recordAttendance();
                break;

            case 4:
                viewAttendance();
                break;

            case 5:
                searchStudent();
                break;

            case 6:
                sortStudents();
                break;

            case 7:
                attendancePercentage();
                break;

            case 8:
                cout << "\nThank you for using our system!\n";
                break;

            default:
                cout << "\nInvalid choice! Try again.\n";
        }

    } while (choice != 8);

    return 0;
}
