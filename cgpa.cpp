#include <iostream>
#include <string>

using namespace std;

// Notes:
// i - Default Credit Hours per subject  = 3
// ii- Default Number of Subjects = 5
// iii- Highest CGPA = 4

string calculateGrade(float marks){
    if (marks < 100 && marks > 90){
        return "A";
    }
    else if (marks < 89 && marks > 86){
        return "A-";
    }
    else if (marks < 85 && marks > 81){
        return "B+";
    }
    else if (marks < 80 && marks > 77){
        return "B";
    }
    else if (marks < 76 && marks > 72){
        return "B-";
    }
    else if (marks < 71 && marks > 68){
        return "C+";
    }
    else if (marks < 67 && marks > 63){
        return "C";
    }
    else if (marks < 62 && marks > 58){
        return "C-";
    }
    else if (marks < 57 && marks > 54){
        return "D+";
    }
    else if (marks < 53 && marks > 50){
        return "D";
    }
    else if (marks < 50 && marks > 48){
        return "D-";
    }
    else {
        return "F";
    }
}

float gradePoints(string grade){
    if (grade == "A"){
        return 4.0;
    }
    if (grade == "A-"){
        return 3.67;
    }
    if (grade == "B+"){
        return 3.33;
    }
    if (grade == "B"){
        return 3;
    }
    if (grade == "B-"){
        return 2.67;
    }
    if (grade == "C+"){
        return 2.33;
    }
    if (grade == "C"){
        return 2.0;
    }
    if (grade == "C-"){
        return 1.67;
    }
    if (grade == "D+"){
        return 1.33;
    }
    if (grade == "D"){
        return 1.0;
    }
    if (grade == "D-"){
        return 0.67;
    }
    if (grade == "F"){
        return 0.0;
    }
}

float qualityPoints(int creditHours, float gradePoints){
    return creditHours * gradePoints;
}

float cgpa(float totalQualityPoints, int totalCreditHours){
    return totalQualityPoints / totalCreditHours;
}

int main(){
    string studentName;
    int creditHours = 3;
    int totalCreditHours = 15;
    float totalQualityPoints = 0.0;
    int subjectsMarks[5];
    string subjectsName[5];
    string grades[5];
    cout << "Welcome To CGPA Calculator Program.\n";
    cout << "Enter Student's Name.\n";
    getline(cin, studentName);

    for(int i=0; i<=4; i++){
        cout << "Enter Subject Name.\n";
        getline(cin, subjectsName[i]);
        cout << "Enter Subject Marks.\n";
        cin >> subjectsMarks[i];
        while(subjectsMarks[i] > 100){
            cout << "Please Enter marks in 0 - 100 range\n";
            cin >> subjectsMarks[i];
        }
    }

    cout << "Here is your Final Report Card:\n\n\n";
    cout << "Subjects\t" << "creditHours\t" << "Grade/GradePoints\t" << "Quality Points\n\n\n";
    for (int i=0; i<=4; i++){
        string subject_grade = calculateGrade(subjectsMarks[i]);
        float grade_Points = gradePoints(subject_grade);
        float quality_Points = qualityPoints(creditHours, grade_Points);
        totalQualityPoints += quality_Points;
        cout << subjectsName[i] << "\t" << creditHours << "\t";
        cout << subject_grade << "/" << grade_Points << "\t";
        cout << quality_Points << "\n\n";
    }

    cout << "Your CGPA is: " << cgpa(totalQualityPoints, totalCreditHours);
}
