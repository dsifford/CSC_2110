/**
 * Program Name: main.cpp
 * Developer: Derek P Sifford
 * Date: 18.10.2016
 * Description: Prints all and highest test scores for a fictional class
 */
 #include <iostream>
 #include <fstream>
 #include <iomanip>
 #include <string>
 using namespace std;

 struct studentType {
     string studentFName;
     string studentLName;
     uint testScore;
     char grade;
 };

 int readData(studentType[20]);
 void assignGrade(studentType[20]);
 int findHighestScore(studentType[20]);
 void printData(studentType[20], int);

 int main() {

     studentType students[20];
     int err = readData(students);
     if (err != 0) {
         cout << "An error has occurred. Exiting..." << endl;
     }
     assignGrade(students);
     int highestScore = findHighestScore(students);
     printData(students, highestScore);

     return 0;
 }

 /**
  * Reads data from the students.txt file to the students array and returns
  * 	an error if the file can't be found
  *
  * @param arr  Students array.
  * @return     Status code.
  */
 int readData(studentType arr[20]) {

     ifstream file;
     file.open("students.txt");
     if (!file.is_open()) {
         return 1;
     }

     for (int i = 0; i < 20; i++) {
         file >> arr[i].studentLName;
         file >> arr[i].studentFName;
         file >> arr[i].testScore;
     }

     file.close();

     return 0;
 }

 /**
  * Iterates through the students array and assigns a letter grade according to
  * 	the students' test score.
  *
  * @param  arr  Students array
  * @return void
  */
 void assignGrade(studentType arr[20]) {
     for (int i = 0; i < 20; i++) {
         int score = arr[i].testScore;
         if (score > 89) {
             arr[i].grade = 'A';
             continue;
         }

         if (79 < score && score < 90) {
             arr[i].grade = 'B';
             continue;
         }

         if (69 < score && score < 80) {
             arr[i].grade = 'C';
             continue;
         }

         if (59 < score && score < 70) {
             arr[i].grade = 'D';
             continue;
         }

         arr[i].grade = 'F';
     }
 }

 /**
  * Iterates through the students array and returns the highest score.
  *
  * @param arr  Students array.
  * @return     Highest score.
  */
 int findHighestScore(studentType arr[20]) {
     int highest = 0;

     for (int i = 0; i < 20; i++) {
         if (arr[i].testScore > highest)
             highest = arr[i].testScore;
     }

     return highest;
 }

 /**
  * Prints the required information to std out according to the format specified.
  *
  * First, the function iterates the students array to find all students who have
  * 	a test score that matches highScore. If a match is found, then that student's
  * 	name is added to the honorStudents variable. Once all students are added, a
  * 	substring is taken from honorStudents to correct for the trailing comma. Finally,
  * 	the other required information is printed to the console as specified.
  *
  * @param arr       Student array
  * @param highScore The highest score in the class
  * @return void
  */
 void printData(studentType arr[20], int highScore) {

     string honorStudents = "";

     for (int i = 0; i < 20; i++) {
         if (arr[i].testScore == highScore) {
             honorStudents += arr[i].studentFName + " " + arr[i].studentLName + ", ";
         }
     }

     honorStudents = honorStudents.substr(0, honorStudents.length() - 2);

     cout
         << "The students with the highest test score (" << highScore << "%) are: \n"
         << honorStudents << endl;

     cout << "\n\n" << "Student Grade Summary:" << "\n\n";
     cout << setw(30) << left << "Name" << setw(10) << "Score" << setw(10) << "Grade" << endl;

     for (int i = 0; i < 20; i++) {
         cout
             << setw(15) << arr[i].studentLName + ", " << setw(15) << arr[i].studentFName
             << setw(10) << arr[i].testScore << setw(10) << arr[i].grade << endl;
     }

 }
