#include <iostream>
#include <string>
using namespace std;

// ==================== FUNCTION DECLARATIONS ====================

// Student Operations
void addStudent(int ids[], string names[], int &count);
int searchStudent(int ids[], int count, int key);
void inputMarks(int marks[][10], int index, int subjects);
void displayStudent(int ids[], string names[], int marks[][10], int numSubjects[], int index);

// Analytics & Reports
float calculateStudentAverage(int marks[], int subjects);
float calculateClassAverage(int marks[][10], int numSubjects[], int count);
int findTopScorer(int ids[], string names[], int marks[][10], int numSubjects[], int count);
char calculateGrade(float avg);
bool isPass(int marks[], int subjects);

// Menu Functions
void displayMainMenu();
void displayStudentMenu();
void displayReportsMenu();
void handleStudentOperations(int ids[], string names[], int marks[][10], int numSubjects[], int &count);
void handleReports(int ids[], string names[], int marks[][10], int numSubjects[], int count);
void displayStudentSummary(int ids[], string names[], int marks[][10], int numSubjects[], int count);

// Bonus Functions
bool isDuplicateID(int ids[], int count, int id);
void displayRankList(int ids[], string names[], int marks[][10], int numSubjects[], int count);
void displaySubjectToppers(int ids[], string names[], int marks[][10], int numSubjects[], int count);

// ==================== MAIN FUNCTION ====================

int main() {
    // Parallel arrays for student data
    int studentIDs[50];
    string studentNames[50];
    int studentMarks[50][10];  // [student][subject]
    int numSubjects[50];       // number of subjects per student
    int studentCount = 0;
    
    int mainChoice;
    
    cout << "\n========================================\n";
    cout << "  STUDENT PERFORMANCE MANAGEMENT SYSTEM\n";
    cout << "========================================\n";
    
    do {
        displayMainMenu();
        cout << "Enter your choice: ";
        cin >> mainChoice;
        
        switch(mainChoice) {
            case 1:
                handleStudentOperations(studentIDs, studentNames, studentMarks, numSubjects, studentCount);
                break;
            case 2:
                handleReports(studentIDs, studentNames, studentMarks, numSubjects, studentCount);
                break;
            case 3:
                cout << "\nThank you for using the system. Goodbye!\n";
                break;
            default:
                cout << "\nInvalid choice! Please try again.\n";
        }
    } while(mainChoice != 3);
    
    return 0;
}

// ==================== MENU DISPLAY FUNCTIONS ====================

void displayMainMenu() {
    cout << "\n======== MAIN MENU ========\n";
    cout << "1. Student Operations\n";
    cout << "2. Reports & Analytics\n";
    cout << "3. Exit\n";
    cout << "===========================\n";
}

void displayStudentMenu() {
    cout << "\n==== STUDENT OPERATIONS ====\n";
    cout << "1. Add New Student\n";
    cout << "2. Enter / Update Marks\n";
    cout << "3. View Student Details\n";
    cout << "4. Back to Main Menu\n";
    cout << "============================\n";
}

void displayReportsMenu() {
    cout << "\n==== REPORTS & ANALYTICS ====\n";
    cout << "1. Class Average\n";
    cout << "2. Top Scorer\n";
    cout << "3. Student-wise Result Summary\n";
    cout << "4. Rank List (Bonus)\n";
    cout << "5. Subject-wise Toppers (Bonus)\n";
    cout << "6. Back to Main Menu\n";
    cout << "=============================\n";
}

// ==================== MENU HANDLER FUNCTIONS ====================

void handleStudentOperations(int ids[], string names[], int marks[][10], int numSubjects[], int &count) {
    int choice;
    
    do {
        displayStudentMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                addStudent(ids, names, count);
                break;
            case 2: {
                int id;
                cout << "\nEnter Student ID: ";
                cin >> id;
                int index = searchStudent(ids, count, id);
                if(index != -1) {
                    cout << "Enter number of subjects: ";
                    cin >> numSubjects[index];
                    if(numSubjects[index] > 10) {
                        cout << "Maximum 10 subjects allowed!\n";
                        numSubjects[index] = 10;
                    }
                    inputMarks(marks, index, numSubjects[index]);
                } else {
                    cout << "Student not found!\n";
                }
                break;
            }
            case 3: {
                int id;
                cout << "\nEnter Student ID: ";
                cin >> id;
                int index = searchStudent(ids, count, id);
                if(index != -1) {
                    displayStudent(ids, names, marks, numSubjects, index);
                } else {
                    cout << "Student not found!\n";
                }
                break;
            }
            case 4:
                cout << "\nReturning to Main Menu...\n";
                break;
            default:
                cout << "\nInvalid choice! Please try again.\n";
        }
    } while(choice != 4);
}

void handleReports(int ids[], string names[], int marks[][10], int numSubjects[], int count) {
    int choice;
    
    if(count == 0) {
        cout << "\nNo students in the system yet!\n";
        return;
    }
    
    do {
        displayReportsMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1: {
                float avg = calculateClassAverage(marks, numSubjects, count);
                cout << "\nClass Average: " << avg << "%\n";
                break;
            }
            case 2: {
                int topIndex = findTopScorer(ids, names, marks, numSubjects, count);
                if(topIndex != -1) {
                    cout << "\n========== TOP SCORER ==========\n";
                    displayStudent(ids, names, marks, numSubjects, topIndex);
                }
                break;
            }
            case 3:
                displayStudentSummary(ids, names, marks, numSubjects, count);
                break;
            case 4:
                displayRankList(ids, names, marks, numSubjects, count);
                break;
            case 5:
                displaySubjectToppers(ids, names, marks, numSubjects, count);
                break;
            case 6:
                cout << "\nReturning to Main Menu...\n";
                break;
            default:
                cout << "\nInvalid choice! Please try again.\n";
        }
    } while(choice != 6);
}

// ==================== STUDENT OPERATIONS ====================

void addStudent(int ids[], string names[], int &count) {
    if(count >= 50) {
        cout << "\nError: Maximum student limit (50) reached!\n";
        return;
    }
    
    int id;
    cout << "\nEnter Student ID: ";
    cin >> id;
    
    // Check for duplicate ID (Bonus feature)
    if(isDuplicateID(ids, count, id)) {
        cout << "Error: Student ID already exists!\n";
        return;
    }
    
    cin.ignore(); // Clear input buffer
    cout << "Enter Student Name: ";
    getline(cin, names[count]);
    
    ids[count] = id;
    count++;
    
    cout << "Student added successfully!\n";
}

int searchStudent(int ids[], int count, int key) {
    for(int i = 0; i < count; i++) {
        if(ids[i] == key) {
            return i;
        }
    }
    return -1;
}

void inputMarks(int marks[][10], int index, int subjects) {
    cout << "\nEnter marks for " << subjects << " subjects:\n";
    for(int i = 0; i < subjects; i++) {
        int mark;
        do {
            cout << "Subject " << (i+1) << ": ";
            cin >> mark;
            if(mark < 0 || mark > 100) {
                cout << "Invalid! Marks must be between 0 and 100.\n";
            }
        } while(mark < 0 || mark > 100);
        marks[index][i] = mark;
    }
    cout << "Marks entered successfully!\n";
}

void displayStudent(int ids[], string names[], int marks[][10], int numSubjects[], int index) {
    cout << "\n========================================\n";
    cout << "Student ID: " << ids[index] << endl;
    cout << "Name: " << names[index] << endl;
    cout << "Number of Subjects: " << numSubjects[index] << endl;
    cout << "----------------------------------------\n";
    
    if(numSubjects[index] > 0) {
        cout << "Marks:\n";
        for(int i = 0; i < numSubjects[index]; i++) {
            cout << "  Subject " << (i+1) << ": " << marks[index][i] << endl;
        }
        
        float avg = calculateStudentAverage(marks[index], numSubjects[index]);
        char grade = calculateGrade(avg);
        bool pass = isPass(marks[index], numSubjects[index]);
        
        cout << "----------------------------------------\n";
        cout << "Average: " << avg << "%\n";
        cout << "Grade: " << grade << endl;
        cout << "Status: " << (pass ? "PASS" : "FAIL") << endl;
    }
    cout << "========================================\n";
}

// ==================== ANALYTICS FUNCTIONS ====================

float calculateStudentAverage(int marks[], int subjects) {
    if(subjects == 0) return 0.0;
    
    int sum = 0;
    for(int i = 0; i < subjects; i++) {
        sum += marks[i];
    }
    return (float)sum / subjects;
}

float calculateClassAverage(int marks[][10], int numSubjects[], int count) {
    if(count == 0) return 0.0;
    
    float totalAvg = 0.0;
    for(int i = 0; i < count; i++) {
        totalAvg += calculateStudentAverage(marks[i], numSubjects[i]);
    }
    return totalAvg / count;
}

int findTopScorer(int ids[], string names[], int marks[][10], int numSubjects[], int count) {
    if(count == 0) return -1;
    
    int topIndex = 0;
    float maxAvg = calculateStudentAverage(marks[0], numSubjects[0]);
    
    for(int i = 1; i < count; i++) {
        float avg = calculateStudentAverage(marks[i], numSubjects[i]);
        if(avg > maxAvg) {
            maxAvg = avg;
            topIndex = i;
        }
    }
    return topIndex;
}

char calculateGrade(float avg) {
    if(avg >= 90) return 'A';
    else if(avg >= 75) return 'B';
    else if(avg >= 60) return 'C';
    else if(avg >= 40) return 'D';
    else return 'F';
}

bool isPass(int marks[], int subjects) {
    for(int i = 0; i < subjects; i++) {
        if(marks[i] < 40) {
            return false;
        }
    }
    return true;
}

void displayStudentSummary(int ids[], string names[], int marks[][10], int numSubjects[], int count) {
    cout << "\n========================================\n";
    cout << "     STUDENT-WISE RESULT SUMMARY\n";
    cout << "========================================\n";
    
    // Manual column headers
    cout << "ID        Name                Average   Grade   Status\n";
    cout << "----------------------------------------\n";
    
    for(int i = 0; i < count; i++) {
        float avg = calculateStudentAverage(marks[i], numSubjects[i]);
        char grade = calculateGrade(avg);
        bool pass = isPass(marks[i], numSubjects[i]);
        
        // Manual formatting with spacing
        cout << ids[i];
        
        // Pad ID to 10 characters
        int idLen = 0;
        int tempId = ids[i];
        do { idLen++; tempId /= 10; } while(tempId > 0);
        for(int j = 0; j < 10 - idLen; j++) cout << " ";
        
        // Print name and pad to 20 characters
        cout << names[i];
        int nameLen = names[i].length();
        for(int j = 0; j < 20 - nameLen; j++) cout << " ";
        
        // Print average
        cout << avg;
        int avgLen = 0;
        int tempAvg = (int)avg;
        do { avgLen++; tempAvg /= 10; } while(tempAvg > 0);
        avgLen += 3; // account for decimal point and 2 digits
        for(int j = 0; j < 10 - avgLen; j++) cout << " ";
        
        // Print grade
        cout << grade << "       ";
        
        // Print status
        cout << (pass ? "PASS" : "FAIL") << endl;
    }
    cout << "========================================\n";
}

// ==================== BONUS FEATURES ====================

bool isDuplicateID(int ids[], int count, int id) {
    return searchStudent(ids, count, id) != -1;
}

void displayRankList(int ids[], string names[], int marks[][10], int numSubjects[], int count) {
    if(count == 0) {
        cout << "\nNo students to rank!\n";
        return;
    }
    
    // Create temporary arrays for sorting
    float averages[50];
    int indices[50];
    
    // Calculate averages and initialize indices
    for(int i = 0; i < count; i++) {
        averages[i] = calculateStudentAverage(marks[i], numSubjects[i]);
        indices[i] = i;
    }
    
    // Bubble sort (descending order)
    for(int i = 0; i < count - 1; i++) {
        for(int j = 0; j < count - i - 1; j++) {
            if(averages[j] < averages[j + 1]) {
                // Swap averages
                float tempAvg = averages[j];
                averages[j] = averages[j + 1];
                averages[j + 1] = tempAvg;
                
                // Swap indices
                int tempIdx = indices[j];
                indices[j] = indices[j + 1];
                indices[j + 1] = tempIdx;
            }
        }
    }
    
    // Display rank list
    cout << "\n========================================\n";
    cout << "           RANK LIST\n";
    cout << "========================================\n";
    cout << "Rank  ID        Name                Average   Grade\n";
    cout << "----------------------------------------\n";
    
    for(int i = 0; i < count; i++) {
        int idx = indices[i];
        char grade = calculateGrade(averages[i]);
        
        // Print rank
        int rank = i + 1;
        cout << rank;
        int rankLen = 0;
        int tempRank = rank;
        do { rankLen++; tempRank /= 10; } while(tempRank > 0);
        for(int j = 0; j < 6 - rankLen; j++) cout << " ";
        
        // Print ID
        cout << ids[idx];
        int idLen = 0;
        int tempId = ids[idx];
        do { idLen++; tempId /= 10; } while(tempId > 0);
        for(int j = 0; j < 10 - idLen; j++) cout << " ";
        
        // Print name
        cout << names[idx];
        int nameLen = names[idx].length();
        for(int j = 0; j < 20 - nameLen; j++) cout << " ";
        
        // Print average
        cout << averages[i];
        int avgLen = 0;
        int tempAvg = (int)averages[i];
        do { avgLen++; tempAvg /= 10; } while(tempAvg > 0);
        avgLen += 3; // account for decimal point
        for(int j = 0; j < 10 - avgLen; j++) cout << " ";
        
        // Print grade
        cout << grade << endl;
    }
    cout << "========================================\n";
}

void displaySubjectToppers(int ids[], string names[], int marks[][10], int numSubjects[], int count) {
    if(count == 0) {
        cout << "\nNo students in the system!\n";
        return;
    }
    
    // Find maximum number of subjects
    int maxSubjects = 0;
    for(int i = 0; i < count; i++) {
        if(numSubjects[i] > maxSubjects) {
            maxSubjects = numSubjects[i];
        }
    }
    
    cout << "\n========================================\n";
    cout << "       SUBJECT-WISE TOPPERS\n";
    cout << "========================================\n";
    
    for(int sub = 0; sub < maxSubjects; sub++) {
        int topperIdx = -1;
        int maxMark = -1;
        
        // Find topper for this subject
        for(int i = 0; i < count; i++) {
            if(numSubjects[i] > sub && marks[i][sub] > maxMark) {
                maxMark = marks[i][sub];
                topperIdx = i;
            }
        }
        
        if(topperIdx != -1) {
            cout << "Subject " << (sub + 1) << ":\n";
            cout << "  Topper: " << names[topperIdx] 
                 << " (ID: " << ids[topperIdx] << ")\n";
            cout << "  Marks: " << maxMark << "/100\n";
            cout << "----------------------------------------\n";
        }
    }
    cout << "========================================\n";
}