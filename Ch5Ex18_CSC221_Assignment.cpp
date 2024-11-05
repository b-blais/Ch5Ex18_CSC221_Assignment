/*
Title: Chapter 5 Exercise 18 - Population Bar Chart
File Name : Ch5Ex18_CSC221_Assignment
Programmer : Brion Blais
Date : 11 / 2024
Requirements :
    Write a program that produces a bar chart showing the population growth of Prairieville, a small town in the Midwest,
    at 20-year intervals during the past 100 years. The program should read in the population figures (rounded to the nearest
    1,000 people) for 1900, 1920, 1940, 1960, 1980, and 2000 from a file. For each year, it should display the date and a bar
    consisting of one asterisk for each 1,000 people. The data can be found in the People.txt file.
 */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void openFile();
int flagValidation(string);
void readFile();
void buildBar(int);

ifstream fileStreamObject;

int main()
{
    int population;

    openFile();
    cout << "\nPRAIRIEVILLE POPULATION GROWTH\n";
    cout << "(each * represents 1,000 people)\n";
    for (int year = 1900; year < 2001; year += 20) {
        fileStreamObject >> population;
        cout << year << " ";
        buildBar(population);
        cout << endl;
    }
    return 0;
}

void openFile() {
    string fileName;
    string localFileFlag;
    bool fileFlag;
    cout << "What is the name of the file you are opening? \t";
    cin >> fileName;
    cout << "Is the file you are trying to open in the same folder as this program? \t";
    cin >> localFileFlag;
    fileFlag = flagValidation(localFileFlag);
    if (fileFlag == false) {
        string filePath;
        cout << "Please enter the path to the folder where the file you are trying to open is located.\n";
        cout << "Use the following format:  " << R"(C:\Users\myname\Desktop)" << "\n";
        cin >> filePath;
        fileName = filePath + R"(\)" + fileName;
    }
    if (fileFlag == true) {
        cout << "Finding the file ... ";

        fileStreamObject.open(fileName);
        if (fileStreamObject) {
            cout << "file open.\n";
        }
        else {
            cout << "The file was not found or could not be opened. \n";
            cout << "Please check to see if the file is in the correct folder and rerun the program. Exiting ...\n";
            exit(0);
        }
    }
    else {
        cout << "Finding the file at the following at " << fileName << " ... ";
        fileStreamObject.open(fileName);
        if (fileStreamObject) {
            cout << "file open.\n";
        }
        else {
            cout << "the file was not found or could not be opened. \n";
            cout << "Please check to see if the file is in the correct location and rerun the program. Exiting ...\n";
            exit(0);
        }
    }
}

void readFile() {
}

int flagValidation(string input) {
    int output = 2;
    do {
        if (input == "True" || input == "true" || input == "TRUE" ||
            input == "Yes" || input == "yes" || input == "YES") {
            output = 1;
        }
        else if (input == "False" || input == "false" || input == "FALSE" ||
            input == "No" || input == "no" || input == "NO") {
            output = 0;
        }
        else {
            cout << R"(You must anwser either "true / false or yes / no" to continue.)" << endl;
            cout << "Is the file you are trying to open in the same folder as this program?\t";
            cin >> input;
        }
    } while (output != 0 && output != 1);
    return output;
}

void buildBar(int input) {
    string output;
    for (int count = 0; count < input; count += 1000)
        cout << "*";
}