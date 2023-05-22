#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>
#include<stdio.h>
#include<stdlib.h>
#include<cstring>
#include<iomanip>
#include<algorithm>
using namespace std;

/*-------------------------------------------------------------------------------------------------class----------------------------------------------------------------------------------------------------*/

class Grade {
public:
	char math[20] = { '\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0' };
	char computer[20] = { '\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0' };
	char english[20] = { '\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0' };
};

class Student {
public:
	char name[20] = { '\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0' };
	char classID[20] = { '\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0' };
	char gender[20] = { '\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0' };
	char age[20] = { '\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0' };
	Grade g;
};

class StudentFunction {
public:
	void IndividualView();
	friend void searchID();
};

class TeacherFunction {
public:
	void AddStudent();
	void ModifyStudent();
	void ShowAllStudent();
	void IndividualView();
	friend void searchname();
	friend void searchID();
	friend void searchmath();
	friend void searchenglish();
	friend void searchcomputer();
	void RemoveStudent();
	void SortStudent();
};


/*------------------------------------------------------------------------function declaration--------------------------------------------------------------------------------*/


void clear();//clear the screen
void error();//output error information
bool is_number(char* str);//judge if it's number
bool is_character();//judge if it's character
bool rangejudge();//enter information and test error
void finish();//when a menber function is finished, cout some information
void searchname();//search a student by name;
void searchID();//search a student by ID;
void searchmath();//search a student by math grade;
void searchenglish();//search a student by english grade;
void searchcomputer();//search a student by computer grade;
int lengthofchar();// judge the length of a char[]


/*--------------------------------------------------------------------------------main function-----------------------------------------------------------------------------------------------*/



int main() {

Start:cout << "\t\t\t\t----------Student Management System----------" << endl << endl;
	cout << "\t\t\t\t*********************************************" << endl << endl;
	cout << "\t\t\t\t\t\t1.Student Mode" << endl << endl;
	cout << "\t\t\t\t\t\t2.Teacher Mode" << endl << endl;
	cout << "\t\t\t\t\t\t3.Exit" << endl << endl;
	cout << "\t\t\t\t*********************************************" << endl << endl;



	/*------------------------------------------------------choose mode--------------------------------------------------------------*/
tryagain:string modechoice;
	cin >> modechoice;

	/*------------------Student mode----------------*/
	
	if (modechoice == "cmyNB") {/*just an easter egg*/
		clear();
		cout << "Author:Alan" << endl << endl << "Complete time:2020.4.25" << endl << endl << "The feeling of author when he completed it:REALLY COOL!!!" << endl;
		finish();
		return 0;
	}
	if (modechoice == "1") {
		clear();
	SM:cout << "\t\t\t\t----------Student Management System----------" << endl << endl;//show the basic mode choice
		cout << "\t\t\t\t*********************************************" << endl << endl;
		cout << "\t\t\t\t\t\tPlease enter password" << endl << endl;
		cout << "\t\t\t\t\t\t1.Go back" << endl << endl;
		cout << "\t\t\t\t*********************************************" << endl << endl;

		string Studentmodeexit = "0";//enter password or exit
		while (1) {
			cin >> Studentmodeexit;
			/*------------------------------Student memu-----------------------------*/
			if (Studentmodeexit == "666233") {//entet password
				clear();
				string Studentmodechoice = "0";
			studentmodestart:cout << "\t\t\t\t----------Student Management System----------" << endl;
				cout << "\t\t\t\t----------------Student Mode-----------------" << endl << endl;
				cout << "\t\t\t\t*********************************************" << endl << endl;
				cout << "\t\t\t\t\t\t1.Individual View" << endl << endl;
				cout << "\t\t\t\t\t\t2.Go back" << endl << endl;
				cout << "\t\t\t\t*********************************************" << endl << endl;
				while (1) {
					cin >> Studentmodechoice;//choose mode;
					if (Studentmodechoice == "1") {// choose 1 and go to view
						StudentFunction view;
						view.IndividualView();
						goto studentmodestart;
					}
					else if (Studentmodechoice == "2") {//choose 2 and exit
						system("cls");
						goto SM;
					}
					else {
						error();
						continue;
					}
				}
			}
			else if (Studentmodeexit == "1") {//go back to the superior menu;
				clear();
				goto Start;
			}//exit
			else if (Studentmodeexit != "666233" && Studentmodeexit != "1") {
				cout << "Password error! Please enter again!" << endl;//password error
				Studentmodeexit = "0";
			}
		}
	}

	/*--------------------Teacher mode---------------------*/
	else if (modechoice == "2") {
		clear();
	TM:cout << "\t\t\t\t----------Student Management System----------" << endl << endl;//show the basic mode choice
		cout << "\t\t\t\t*********************************************" << endl << endl;
		cout << "\t\t\t\t\t\tPlease enter password" << endl << endl;//need password;
		cout << "\t\t\t\t\t\t1.Go back" << endl << endl;
		cout << "\t\t\t\t*********************************************" << endl << endl;

		string Teachermodeexit = "0";//enter password or exit
		while (1) {
			cin >> Teachermodeexit;
			/*--------------------------------------Teacher memu-----------------------------------------*/
			if (Teachermodeexit == "233666") {//pass
				while (1) {
					clear();
					string Teachermodechoice = "0";
					cout << "\t\t\t\t----------Student Management System----------" << endl;
					cout << "\t\t\t\t----------------Teacher Mode-----------------" << endl << endl;
					cout << "\t\t\t\t*********************************************" << endl << endl;
					cout << "\t\t\t\t\t\t1.Add Student" << endl << endl;
					cout << "\t\t\t\t\t\t2.Modify Student" << endl << endl;
					cout << "\t\t\t\t\t\t3.Show All Student" << endl << endl;
					cout << "\t\t\t\t\t\t4.Individual View" << endl << endl;
					cout << "\t\t\t\t\t\t5.Remove Student" << endl << endl;
					cout << "\t\t\t\t\t\t6.Sort Student" << endl << endl;
					cout << "\t\t\t\t\t\t7.Go back" << endl << endl;
					cout << "\t\t\t\t*********************************************" << endl << endl;


					cin >> Teachermodechoice;
					/*Add Student*/
					if (Teachermodechoice == "1") {
						TeacherFunction add;
						add.AddStudent();
						continue;
					}
					/*Modify Student*/
					else if (Teachermodechoice == "2") {
						TeacherFunction modify;
						modify.ModifyStudent();
						continue;
					}
					/*Show All Student*/
					else if (Teachermodechoice == "3") {
						TeacherFunction showall;
						showall.ShowAllStudent();
						continue;
					}
					/*Individual View*/
					else if (Teachermodechoice == "4") {
						TeacherFunction view;
						view.IndividualView();
						continue;
					}
					/*Remove Student*/
					else if (Teachermodechoice == "5") {
						TeacherFunction remove;
						remove.RemoveStudent();
						continue;
					}
					/*Sort Student*/
					else if (Teachermodechoice == "6") {
						TeacherFunction sort;
						sort.SortStudent();
						continue;
					}
					/*Go back*/
					else if (Teachermodechoice == "7") {
						system("cls");
						goto TM;
					}
					else {
						error();
						continue;
					}
				}
			}
			else if (Teachermodeexit == "1") {
				system("cls");
				goto Start;//exit
			}
			else if (Teachermodeexit != "233666" && Teachermodeexit != "1") {
				cout << "Password error! Please enter again!" << endl;//password error
				Teachermodeexit == "0";
			}
		}
	}

	/*end and error test*/
	else if (modechoice == "3")
		goto endthis;
	else if (modechoice != "3" && modechoice != "2" && modechoice != "1") {
		cout << "error! Please enter again!" << endl;//password error
		goto tryagain;
	}

endthis:return 0;
}







/*-----------------------------------------------------------------------------------------------Function body----------------------------------------------------------------------------------------*/








/*--------------basic show function----------------*/
void error() {
	cout << "Error! Please enter again!" << endl;
}

void clear() {
	system("cls");
}

void finish() {
	cout << "Completed! Please enter 0 to go back" << endl;
	while (1) {
		char back[100] = { '\0','\0', '\0', '\0', '\0', '\0','\0', '\0', '\0', '\0','\0','\0', '\0', '\0', '\0', '\0','\0', '\0', '\0', '\0','\0','\0', '\0', '\0', '\0', '\0','\0', '\0', '\0', '\0','\0','\0', '\0', '\0', '\0', '\0','\0', '\0', '\0', '\0','\0','\0', '\0', '\0', '\0', '\0','\0', '\0', '\0', '\0','\0','\0', '\0', '\0', '\0', '\0','\0', '\0', '\0', '\0','\0','\0', '\0', '\0', '\0', '\0','\0', '\0', '\0', '\0','\0','\0', '\0', '\0', '\0', '\0','\0', '\0', '\0', '\0','\0','\0', '\0', '\0', '\0', '\0','\0', '\0', '\0', '\0','\0','\0', '\0', '\0', '\0', '\0','\0', '\0', '\0', '\0', };
		cin >> back;
		if (!is_number(back)) {
			error();
			continue;
		}
		int temp = atoi(back);
		if (temp == 0) {
			break;
		}
		else {
			error();
			continue;
		}
	}
}

/*-----------------------judge function---------------------*/
int lengthofchar(char* str) {
	int count = 0;
	for (int i = 0; i < 20; i++) {
		if ((str[i] != '\0')&&(str[i] != '0')) count++;
	}
	return count;
}

bool is_number(char* str) {
	int L = lengthofchar(str);
	for (int i = 0; i < L; i++) {
		int tmp = (int)str[i];
		if (tmp >= 48 && tmp <= 57) {
			continue;
		}
		else {
			return false;
		}
	}
	return true;
}

bool is_character(char* str) {
	int L = lengthofchar(str);
	for (int i = 0; i < L; i++) {
		int tmp = (int)str[i];
		if ((tmp >= 65 && tmp <= 90) || (tmp >= 97 && tmp <= 122)) {
			continue;
		}
		else {
			return false;
		}
	}
	return true;
}

bool rangejudge(int up, int down, char* teststr) {//the number needed to be judged, Upper Bound, Lower bound
	int number;
	while (1) {
		number = atoi(teststr);
		if (up >= number && down <= number) {//if it go out of the bound, cout error
			break;
		}
		else {
			error();
			return false;
		}
	}
	return true;
}

/*--------------------------search function-----------------------*/
void searchname(char* str) {
	int flag = 0;
	fstream file("student.txt", ios::binary | ios::in);
	while (!file.eof()) {
		Student stu;
		file.read((char*)&stu, sizeof(Student));//open the file
		if (strcmp(stu.name, str) == 0) {//if the same, find it and output
			flag = 1;
			cout << left << setw(10) << "name" << setw(10) << "classID" << setw(10) << "age" << setw(10) << "gender";
			cout << setw(15) << "math grade" << setw(15) << "english grade" << setw(15) << "computer grade" << endl;
			cout << setw(10) << stu.name << setw(10) << stu.classID << setw(10) << stu.age << setw(10) << stu.gender;
			cout << setw(15) << stu.g.math << setw(15) << stu.g.english << setw(15) << stu.g.computer << endl << endl;
		}
	}
	if (flag != 1)cout << "No found!" << endl;
	file.close();
}

void searchID(char* str) {
	int flag = 0;
	fstream file("student.txt", ios::binary | ios::in);
	while (!file.eof()) {
		Student stu;
		file.read((char*)&stu, sizeof(Student));
		if (strcmp(stu.classID, str) == 0) {
			flag = 1;
			cout << left << setw(10) << "name" << setw(10) << "classID" << setw(10) << "age" << setw(10) << "gender";
			cout << setw(15) << "math grade" << setw(15) << "english grade" << setw(15) << "computer grade" << endl;
			cout << setw(10) << stu.name << setw(10) << stu.classID << setw(10) << stu.age << setw(10) << stu.gender;
			cout << setw(15) << stu.g.math << setw(15) << stu.g.english << setw(15) << stu.g.computer << endl << endl;
			break;
		}
	}
	if (flag != 1)cout << "No found!" << endl;
	file.close();
}

void searchmath(char* str) {
	int flag = 0;
	fstream file("student.txt", ios::binary | ios::in);
	while (!file.eof()) {
		Student stu;
		file.read((char*)&stu, sizeof(Student));
		if (strcmp(stu.g.math, str) == 0) {
			flag = 1;
			cout << left << setw(10) << "name" << setw(10) << "classID" << setw(10) << "age" << setw(10) << "gender";
			cout << setw(15) << "math grade" << setw(15) << "english grade" << setw(15) << "computer grade" << endl;
			cout << setw(10) << stu.name << setw(10) << stu.classID << setw(10) << stu.age << setw(10) << stu.gender;
			cout << setw(15) << stu.g.math << setw(15) << stu.g.english << setw(15) << stu.g.computer << endl << endl;
		}
	}
	if (flag != 1)cout << "No found!" << endl;
	file.close();
}

void searchenglish(char* str) {
	int flag = 0;
	fstream file("student.txt", ios::binary | ios::in);
	while (!file.eof()) {
		Student stu;
		file.read((char*)&stu, sizeof(Student));
		if (strcmp(stu.g.english, str) == 0) {
			flag = 1;
			cout << left << setw(10) << "name" << setw(10) << "classID" << setw(10) << "age" << setw(10) << "gender";
			cout << setw(15) << "math grade" << setw(15) << "english grade" << setw(15) << "computer grade" << endl;
			cout << setw(10) << stu.name << setw(10) << stu.classID << setw(10) << stu.age << setw(10) << stu.gender;
			cout << setw(15) << stu.g.math << setw(15) << stu.g.english << setw(15) << stu.g.computer << endl << endl;
		}
	}
	if (flag != 1)cout << "No found!" << endl;
	file.close();
}

void searchcomputer(char* str) {
	int flag = 0;
	fstream file("student.txt", ios::binary | ios::in);
	while (!file.eof()) {
		Student stu;
		file.read((char*)&stu, sizeof(Student));
		if (strcmp(stu.g.computer, str) == 0) {
			flag = 1;
			cout << left << setw(10) << "name" << setw(10) << "classID" << setw(10) << "age" << setw(10) << "gender";
			cout << setw(15) << "math grade" << setw(15) << "english grade" << setw(15) << "computer grade" << endl;
			cout << setw(10) << stu.name << setw(10) << stu.classID << setw(10) << stu.age << setw(10) << stu.gender;
			cout << setw(15) << stu.g.math << setw(15) << stu.g.english << setw(15) << stu.g.computer << endl << endl;
		}
	}
	if (flag != 1)cout << "No found!" << endl;
	file.close();
}



/*----------------------sort function-------------------*/
static bool IDCompare(const Student& a, const Student& b) {
	return strcmp(a.classID, b.classID) <= 0;
}
static bool MathGradeCompare(const Student& a, const Student& b) {
	return strcmp(a.g.math, b.g.math) <= 0;
}
static bool EnglishGradeCompare(const Student& a, const Student& b) {
	return strcmp(a.g.english, b.g.english) <= 0;
}
static bool ComputerGradeCompare(const Student& a, const Student& b) {
	return strcmp(a.g.computer, b.g.computer) <= 0;
}






/*---------------------------------------------------------------------------------Teacher Number Function------------------------------------------------------------------------------------------*/






void TeacherFunction::AddStudent() {
	clear();
	cout << "\t\t\t\t----------Student Management System----------" << endl;
	cout << "\t\t\t\t----------------Teacher Mode-----------------" << endl;
	cout << "\t\t\t\t----------------Add Student------------------" << endl << endl;
	cout << "\t\t\t\t*********************************************" << endl << endl;
	Student zhangsan;//a student menber, don't think that he's the person who out of law!

	int pStudentNumber;
	cout << "Please enter the number of student:" << endl;
	cout << "If you want to go back ,please enter'0'" << endl;
	while (1) {
		char StudentNumber[20] = { '\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0' };
		cin >> StudentNumber;
		if (!is_number(StudentNumber)) {//error test,whether it is number
			error();
			continue;
		}
		else {
			pStudentNumber = atoi(StudentNumber);//if it's number, change it to int;
			break;
		}
	}
	if (pStudentNumber == 0) {//1 and go back;
		finish();
		return;
	}
	for (int i = 1; i <= pStudentNumber; i++) {
		cout << "Please enter the name of the No." << i << " student(only character):" << endl;
		while (1) {
			for (int i = 0; i < 20; i++) {
				zhangsan.name[i] = '0';
			}
			cin >> zhangsan.name;
			if (!is_character(zhangsan.name)) {//test whether it's character
				error();
			}
			else { break; }
		}
		cout << "Please enter the classID of the No." << i << " student(4 digits):" << endl;
		while (1) {
			for (int i = 0; i < 20; i++) {
				zhangsan.classID[i] = '0';
			}
			cin >> zhangsan.classID;
			if (!is_number(zhangsan.classID)) {//test whether it's number
				error();
				continue;
			}
			if (!rangejudge(9999, 1000, zhangsan.classID)) {//test whether it's out of range
				continue;
			}
			else break;
		}
		cout << "Please enter the age of the No." << i << " student(1~100):" << endl;
		while (1) {
			for (int i = 0; i < 20; i++) {
				zhangsan.age[i] = '0';
			}
			cin >> zhangsan.age;
			if (!is_number(zhangsan.age)) {//test whether it's number
				error();
				continue;
			}
			if (!rangejudge(100, 1, zhangsan.age)) {//test whether it's out of range
				continue;
			}
			else break;
		}
		cout << "Please enter the gender of the No." << i << "student（man or woman）:" << endl;
		while (1) {//error test
			for (int i = 0; i < 20; i++) {
				zhangsan.gender[i] = '0';
			}
			cin >> zhangsan.gender;
			if (strcmp(zhangsan.gender, "man") != 0 && strcmp(zhangsan.gender, "woman") != 0) {
				error();
			}
			else {
				break;
			}
		}
		cout << "Please enter the computer grade of the No." << i << "student(0~100):" << endl;
		while (1) {
			for (int i = 0; i < 20; i++) {
				zhangsan.g.computer[i] = '0';
			}
			cin >> zhangsan.g.computer;
			if (!is_number(zhangsan.g.computer)) {//test whether it's number
				error();
				continue;
			}
			if (!rangejudge(100, 0, zhangsan.g.computer)) {//test whether it's out of range
				continue;
			}
			else break;
		}
		cout << "Please enter the english grade of the No." << i << "student(0~100):" << endl;
		while (1) {
			for (int i = 0; i < 20; i++) {
				zhangsan.g.english[i] = '0';
			}
			cin >> zhangsan.g.english;
			if (!is_number(zhangsan.g.english)) {//test whether it's number
				error();
				continue;
			}
			if (!rangejudge(100, 0, zhangsan.g.english)) {//test whether it's out of range
				continue;
			}
			else break;
		}
		cout << "Please enter the math grade of the No." << i << "student(0~100):" << endl;
		while (1) {
			for (int i = 0; i < 20; i++) {
				zhangsan.g.math[i] = '0';
			}
			cin >> zhangsan.g.math;
			if (!is_number(zhangsan.g.math)) {//test whether it's number
				error();
				continue;
			}
			if (!rangejudge(100, 0, zhangsan.g.math)) {//test whether it's out of range
				continue;
			}
			else break;
		}
		fstream file("student.txt", ios::out | ios::binary | ios::app);
		file.write((char*)&zhangsan, sizeof(Student));//write the information into the file
		file.close();
	}
	finish();
	clear();
	return;
}




void TeacherFunction::ModifyStudent() {
	vector<Student> stuarray;//an array to store the modified information temporarily;
	clear();
	char protectname[20] = { '\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0' };
	/*for some interesting reason(i don't know why), the loop will have one more cycle,and in the last loop it will read the last data one more time, so i use protectname to aovid it have one more cycle*/
	int choice, gobreak = 0;
	Student stu;
	int flag = 0;//a mark to judge whether it can find the student
	char str[20] = { '\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0' };
	char strname[20] = { '\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0' };//array to store the /information temporarily;
	cout << "Please enter the classID of the student you want to modify:" << endl;
	while (1) {
		cin >> str;
		if (!is_number(str)) {
			error();
			continue;
		}
		break;
	}
	fstream file("student.txt", ios::binary | ios::in);
	while (!file.eof())
	{
		file.read((char*)&stu, sizeof(Student));
		if (strcmp(stu.classID, str) == 0)//the same means find it
		{
			flag = 1;
			if (stu.name[0] != '\0') {
				cout << left << setw(10) << "name" << setw(10) << "classID" << setw(10) << "age" << setw(10) << "gender";//setw to set the width of the output
				cout << setw(15) << "math grade" << setw(15) << "english grade" << setw(15) << "computer grade" << endl;
			}
			cout << setw(10) << stu.name << setw(10) << stu.classID << setw(10) << stu.age << setw(10) << stu.gender;
			cout << setw(15) << stu.g.math << setw(15) << stu.g.english << setw(15) << stu.g.computer << endl << endl;
			cout << "\t\t\t\t----------Student Management System----------" << endl;
			cout << "\t\t\t\t----------------Teacher Mode-----------------" << endl;
			cout << "\t\t\t\t---------------Modify Student----------------" << endl << endl;
			cout << "\t\t\t\t*********************************************" << endl << endl;
			cout << "\t\t\t\t\t\t1.Modify name" << endl << endl;
			cout << "\t\t\t\t\t\t2.Modify age" << endl << endl;
			cout << "\t\t\t\t\t\t3.Modify gender" << endl << endl;
			cout << "\t\t\t\t\t\t4.Modify math grade" << endl << endl;
			cout << "\t\t\t\t\t\t5.Modify english grade" << endl << endl;
			cout << "\t\t\t\t\t\t6.Modify computer grade" << endl << endl;
			cout << "\t\t\t\t\t\t7.Go back" << endl << endl;
			cout << "\t\t\t\t*********************************************" << endl << endl;
			while (1)
			{
				if (gobreak == 1)break;//to break
				cout << "Please choose an option!" << endl;
				cin >> choice;
				switch (choice)
				{
				case 1:
					cout << "Please input new name:" << endl;
					cin >> strname;
					strcpy_s(stu.name, strname);//copy the information from strname to stu.name
					cout << "Modification completed!" << endl;
					break;
				case 2:
					cout << "Please input new age:" << endl;
					cin >> str;
					strcpy_s(stu.age, str);
					cout << "Modification completed!" << endl;
					break;
				case 3:
					cout << "Please input new gender:" << endl;
					cin >> str;
					strcpy_s(stu.gender, str);
					cout << "Modification completed!" << endl;
					break;
				case 4:
					cout << "Please input new math grade" << endl;
					cin >> str;
					strcpy_s(stu.g.math, str);
					cout << "Modification completed!" << endl;
					break;
				case 5:
					cout << "Please input new english grade:" << endl;
					cin >> str;
					strcpy_s(stu.g.english, str);
					cout << "Modification completed!" << endl;
					break;
				case 6:
					cout << "Please input new computer grade:" << endl;
					cin >> str;
					strcpy_s(stu.g.computer, str);
					cout << "Modification completed!" << endl;
					break;
				case 7: {
					gobreak = 1;
					break;
				}
				default:error();
				}
			}
		}
		if (strcmp(protectname, stu.name) != 0) {//put the other students' information into the vector
			stuarray.push_back(stu);
			strcpy_s(protectname, stu.name);
		}
	}
	file.close();
	if (flag != 1) {//can't found the student
		cout << "No found!" << endl;
		finish();
		return;
	}
	fstream pfile("student.txt", ios::out | ios::binary);
	for (int i = 0; i < stuarray.size(); i++) {//write the modified information into the file
		pfile.write((char*)&stuarray[i], sizeof(Student));
	}
	pfile.close();
	finish();
	return;
}






void TeacherFunction::ShowAllStudent() {
	clear();
	int flag = 0;
	fstream file("student.txt", ios::binary | ios::in);
	/*in this function, it will alse have one more cycle, so i use "if" judge to aovid it*/
	while (!file.eof()) {
		Student stu;
		for (int i = 0; i < 5; i++) {//initialization
			stu.name[i] = '\0';
		}
		file.read((char*)&stu, sizeof(Student));
		flag = 1;
		if (stu.name[0] != '\0') {//show the students' information
			cout << left << setw(10) << "name" << setw(10) << "classID" << setw(10) << "age" << setw(10) << "gender";
			cout << setw(15) << "math grade" << setw(15) << "english grade" << setw(15) << "computer grade" << endl;
		}
		cout << setw(10) << stu.name << setw(10) << stu.classID << setw(10) << stu.age << setw(10) << stu.gender;
		cout << setw(15) << stu.g.math << setw(15) << stu.g.english << setw(15) << stu.g.computer << endl << endl;
	}
	if (flag != 1)cout << "No found!" << endl;//there no student in the database
	file.close();
	finish();
}






void TeacherFunction::IndividualView() {
viewstart:clear();
	string choice;
	cout << "\t\t\t\t----------Student Management System----------" << endl;
	cout << "\t\t\t\t----------------Teacher Mode-----------------" << endl;
	cout << "\t\t\t\t---------------Individual View---------------" << endl << endl;
	cout << "\t\t\t\t*********************************************" << endl << endl;
	cout << "\t\t\t\t\t\t1.Search by name" << endl << endl;
	cout << "\t\t\t\t\t\t2.Search by classID" << endl << endl;
	cout << "\t\t\t\t\t\t3.Search by math grade" << endl << endl;
	cout << "\t\t\t\t\t\t4.Search by english grade" << endl << endl;
	cout << "\t\t\t\t\t\t5.Search by computer grade" << endl << endl;
	cout << "\t\t\t\t\t\t6.Go back" << endl << endl;
	cout << "\t\t\t\t*********************************************" << endl << endl;
	while (1) {
		cin >> choice;
		/*input some information ,and search by it*/
		if (choice == "1") {
			clear();
			cout << "Please enter the name of student you want to view:" << endl;
			char inputname[20] = { '\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0' };
			while (1) {
				cin >> inputname;
				if (!is_character(inputname)) {
					error();
					continue;
				}
				searchname(inputname);
				finish();
				goto viewstart;
			}
		}
		else if (choice == "2") {
			clear();
			cout << "Please enter the classID of student you want to view:" << endl;
			char inputID[20] = { '\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0' };
			while (1) {
				cin >> inputID;
				if (!is_number(inputID)) {
					error();
					continue;
				}
				searchID(inputID);
				finish();
				goto viewstart;
			}
		}
		else if (choice == "3") {
			clear();
			cout << "Please enter the math grade of student you want to view:" << endl;
			char inputmath[20] = { '\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0' };
			while (1) {
				cin >> inputmath;
				if (!is_number(inputmath)) {
					error();
					continue;
				}
				searchmath(inputmath);
				finish();
				goto viewstart;
			}
		}
		else if (choice == "4") {
			clear();
			cout << "Please enter the english grade of student you want to view:" << endl;
			char inputenglish[20] = { '\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0' };
			while (1) {
				cin >> inputenglish;
				if (!is_number(inputenglish)) {
					error();
					continue;
				}
				searchenglish(inputenglish);
				finish();
				goto viewstart;
			}
		}
		else if (choice == "5") {
			clear();
			cout << "Please enter the computer grade of student you want to view:" << endl;
			char inputcomputer[20] = { '\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0' };
			while (1) {
				cin >> inputcomputer;
				if (!is_number(inputcomputer)) {
					error();
					continue;
				}
				searchcomputer(inputcomputer);
				finish();
				goto viewstart;
			}
		}
		else if (choice == "6") {
			clear();
			return;
		}
		else {
			error();
			continue;
		}
	}
}








void TeacherFunction::RemoveStudent() {
	vector<Student> temp;//a vector to store modified information
	Student stu;
	clear();
	/*"protect" to do the same thing*/
	cout << "Please input the classID of the student you want to remove:" << endl;
	cout << "(if you want to remove all students, please enter '0')" << endl;
	cout << "(if you want to go back, please enter '1')" << endl;
	while (1) {
		char tempID[20] = { '\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0' };
		char protect[20] = { '\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0' };
		cin >> tempID;
		if (!is_number(tempID)) {
			error();
			continue;
		}
		int tmp = atoi(tempID);
		if (tmp == 0) {// 0 and remove all
			fstream file("student.txt", ios::binary | ios::out);
			file.write((char*)&stu, sizeof(Student));//it's empty,so the file will be empty; 
			file.close();
			finish();
			return;
		}
		if (tmp == 1) {//1 and return
			finish();
			return;
		}
		int flag = 0;
		fstream file("student.txt", ios::binary | ios::in);
		while (!file.eof()) {
			file.read((char*)&stu, sizeof(Student));//if it's not the student we want to remove, add it to the vector; if it's, won't do it
			if ((strcmp(stu.classID, tempID) != 0) && (strcmp(stu.classID, protect) != 0)) {
				flag = 1;
				temp.push_back(stu);
				strcpy_s(protect, stu.classID);
			}
		}
		fstream pfile("student.txt", ios::out | ios::trunc);//write the corrected infromation to the file
		for (int i = 0; i < temp.size(); i++) {
			pfile.write((char*)&temp[i], sizeof(Student));
		}
		file.close();
		pfile.close();
		finish();
		break;
	}
}








void TeacherFunction::SortStudent() {
sortstart:clear();

	cout << "\t\t\t\t----------Student Management System----------" << endl;
	cout << "\t\t\t\t----------------Teacher Mode-----------------" << endl;
	cout << "\t\t\t\t---------------Sort Student---------------" << endl << endl;
	cout << "\t\t\t\t*********************************************" << endl << endl;
	cout << "\t\t\t\t\t\t1.Sort by classID" << endl << endl;
	cout << "\t\t\t\t\t\t2.Sort by math grade" << endl << endl;
	cout << "\t\t\t\t\t\t3.Sort by english grade" << endl << endl;
	cout << "\t\t\t\t\t\t4.Sort by computer grade" << endl << endl;
	cout << "\t\t\t\t\t\t5.Back" << endl << endl;
	cout << "\t\t\t\t*********************************************" << endl << endl;
	while (1) {
		char choice[20] = { '\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0' };
		cin >> choice;
		if (!is_number(choice)) {
			error();
			continue;
		}
		int tmp = atoi(choice);
		vector<Student> temp;//to store the sorted information
		Student stu;
		if (tmp == 1) {
			fstream file("student.txt", ios::binary | ios::in);
			while (!file.eof())
			{
				file.read((char*)&stu, sizeof(Student));
				temp.push_back(stu);//put all the student into the vector
			}
			temp.pop_back();
			sort(temp.begin(), temp.end(), IDCompare);//sort the vector
			fstream file1("student.txt", ios::out | ios::trunc);
			for (int i = 0; i < temp.size(); i++)
			{
				file1.write((char*)&temp[i], sizeof(Student));//write the sorted information into the file
			}
			file.close();
			file1.close();
			finish();
			break;
		}
		else if (tmp == 2) {
			fstream file("student.txt", ios::binary | ios::in);
			while (!file.eof())
			{
				file.read((char*)&stu, sizeof(Student));
				temp.push_back(stu);
			}
			temp.pop_back();
			sort(temp.begin(), temp.end(), MathGradeCompare);
			fstream file1("student.txt", ios::out | ios::trunc);
			for (int i = 0; i < temp.size(); i++)
			{
				file1.write((char*)&temp[i], sizeof(Student));
			}
			file.close();
			file1.close();
			finish();
			break;
		}
		else if (tmp == 3) {
			fstream file("student.txt", ios::binary | ios::in);
			while (!file.eof())
			{
				file.read((char*)&stu, sizeof(Student));
				temp.push_back(stu);
			}
			temp.pop_back();
			sort(temp.begin(), temp.end(), EnglishGradeCompare);
			fstream file1("student.txt", ios::out | ios::trunc);
			for (int i = 0; i < temp.size(); i++)
			{
				file1.write((char*)&temp[i], sizeof(Student));
			}
			file.close();
			file1.close();
			finish();
			break;
		}
		else if (tmp == 4) {
			fstream file("student.txt", ios::binary | ios::in);
			while (!file.eof())
			{
				file.read((char*)&stu, sizeof(Student));
				temp.push_back(stu);
			}
			temp.pop_back();
			sort(temp.begin(), temp.end(), ComputerGradeCompare);
			fstream file1("student.txt", ios::out | ios::trunc);
			for (int i = 0; i < temp.size(); i++)
			{
				file1.write((char*)&temp[i], sizeof(Student));
			}
			file.close();
			file1.close();
			finish();
			break;
		}
		else if (tmp == 5) {
			finish();
			break;
		}
		else {
			error();
			continue;
		}
	}
	return;
}





/*-----------------------------------------------------------------------------Student Number Function----------------------------------------------------------------------------*/






void StudentFunction::IndividualView() {
viewstart:clear();

	cout << "\t\t\t\t----------Student Management System----------" << endl;
	cout << "\t\t\t\t----------------Teacher Mode-----------------" << endl;
	cout << "\t\t\t\t---------------Individual View---------------" << endl << endl;
	cout << "\t\t\t\t*********************************************" << endl << endl;
	cout << "\t\t\t\t\t\t1.Search by classID" << endl << endl;
	cout << "\t\t\t\t\t\t2.Go back" << endl << endl;
	cout << "\t\t\t\t*********************************************" << endl << endl;
	while (1) {
		char choice[20] = { '\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0' };
		cin >> choice;
		if (!is_number(choice)) {
			error();
			continue;
		}
		int temp = atoi(choice);
		if (temp == 1) {
			clear();
			cout << "Please enter the classID of student you want to view:" << endl;
			char inputID[20] = { '\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0' };
			while (1) {
				cin >> inputID;
				if (!is_number(inputID)) {
					error();
					continue;
				}
				break;
			}
			searchID(inputID);
			finish();
			goto viewstart;
		}
		if (temp == 2) {
			clear();
			return;
		}
		else {
			error();
			continue;
		}
	}
}