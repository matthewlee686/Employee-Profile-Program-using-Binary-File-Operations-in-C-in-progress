#include <iostream>
#include <fstream>
#include <stdlib.h> //Allows use of 'exit'
#include <algorithm> //Allows use of 'sort()'
#include <string>
#include <iomanip>

using namespace std;

/* The File will include Employee Information: Employee ID Number, First and Last Name, Contact Number, and Email */


//Structure
//---------------------------------------------------------------------
struct Info
{
	int id_num;
	char first_name[20];
	char last_name[20];
	char phone[12]; //Format: xxx - xxx - xxxx (x = digit)
	char email[30];
	string add;

}one_emp; 


//Function Prototypes
//---------------------------------------------------------------------
void write_file();
void display_file();
void append_file();
void delete_content();
void search_file();
void modify_file();
void sort_file();
void wipe_file();
void check_if();
void create_file();
void goodbye_fun();


//Main
//---------------------------------------------------------------------
int main() {

	//Declaring Variables for Menu Choice Input
	int menu_choice;
	string continue_choice;

	//Menu ------------------------------------

	do {

		cout << "       Menu      " << endl;
		cout << "----------------------------" << endl;
		cout << "1.) Add Employee Information" << endl; //Will populate the File
		cout << "2.) Display Employee Information" << endl; //Will display the File
		cout << "3.) Append Employee Information" << endl; //Will append the File
		cout << "4.) Remove part of Employee Profile" << endl; //Will delete a record from File 
		cout << "5.) Search Employee Profile" << endl; //Will search File
		cout << "6.) Modify Employee Profile" << endl; //Will modify File
		cout << "7.) Sort File " << endl; //Will sort File
		cout << "8.) Delete Employee Profile" << endl; //Will wipe entire File
		cout << "9.) Check if Employee Profile Exists" << endl; //Will check if File exists
		cout << "10.) Create File" << endl; //Will create File
		cout << "11.) Exit " << endl; //Ends Program
		cout << "----------------------------" << endl << endl;
		cout << "Please select which action you would like to perform: ";
		cin >> menu_choice;

		if (menu_choice == 1) {

			write_file();

		}

		else if (menu_choice == 2) {

			display_file();
		}

		else if (menu_choice == 3) {

			append_file();

		}

		else if (menu_choice == 4) {

			delete_content();

		}

		else if (menu_choice == 5) {

			search_file();

		}

		else if (menu_choice == 6) {

			modify_file();

		}

		else if (menu_choice == 7) {

			sort_file();

		}

		else if (menu_choice == 8) {

			wipe_file();

		}

		else if (menu_choice == 9) {

			check_if();

		}

		else if (menu_choice == 10) {

			create_file();

		}

		else if (menu_choice == 11) {
			break;
		}

		else {
			cout << "Invalid choice, please Enter 1, 2 or 3: ";
		}

		cout << endl << "Would you like to perform another action -- Please input 'Y' or 'y': ";
		cin >> continue_choice;

		cout << endl;

	} while(continue_choice == "Y" || continue_choice == "y" || continue_choice == "Yes" || continue_choice == "yes");


	goodbye_fun();
}


//Functions
//---------------------------------------------------------------------

//All Functions will first Open the Binary File, execute their specific Function, then close the File


/*Write/Populate File Function*/
void write_file() {

	char choice;

	fstream employee_info;

	//Open
	employee_info.open("one_emp.dat", ios::in | ios::binary); //Flags used: Input and open in Binary


	//Populating Binary File
	cout << endl;
	cout << setw(5) << "Add Employee Information" << endl;
	cout << "----------------------------------------------" << endl;
	cout << endl << "Please enter the Employee ID Number: ";
	cin >> one_emp.id_num;

		/*Input Validation*/
		if (one_emp.id_num <= 0 || one_emp.id_num > 1000) {
			cout << "Error -- Please enter a valid value: ";
			cin >> one_emp.id_num;
			cout << endl;
		}

	cout << endl << "Please enter the Employee's First Name: ";
	cin >> one_emp.first_name;
	cout << endl << "Please enter the Employee's Last Name: ";
	cin >> one_emp.last_name;
	cout << endl << "Please enter the Employee's Contact Number: ";
	cin >> one_emp.phone;
	cout << endl << "Please enter the Employee's Email Address: ";
	cin >> one_emp.email;
	cout << endl;

	//Writing inputted information to the File
	employee_info.write((char*)&one_emp, sizeof(one_emp));

	cout << endl << "Employee Information has been added" << endl << endl;
	cout << endl;


	//Close
	employee_info.close();

}


/*Display Binary File Function*/ 
void display_file() {

	int choice;

	fstream employee_info;

	//Open
	employee_info.open("one_emp.dat", ios::binary); //Flags used: Output and open in Binary

	//File Search Validation
	if (!employee_info) exit;

	cout << endl;
	cout << setw(5) << "Display Employee Information" << endl;
	cout << "----------------------------------------------" << endl;

	cout << endl << "Please enter the Employee ID Number: ";
	cin >> choice;

	if (choice == one_emp.id_num) {

		//Read
		employee_info.read((char*)&one_emp, sizeof(one_emp));

		if (one_emp.id_num > 0) {
			cout << endl << "Employee ID Number: " << one_emp.id_num << endl;
		}


		cout << "First Name: " << one_emp.first_name << endl;
		cout << "Last Name: " << one_emp.last_name << endl;
		cout << "Contact Number: " << one_emp.phone << endl;
		cout << "Email Address: " << one_emp.email << endl;

		//Checks if any appended information has been added -- will output 'Not available' if nothing
		if (one_emp.add.length() == 0) {
			cout << endl << "Additional Comments: N/A" << endl; 
		}
		else {
			cout << endl << "Additional Comments: " << one_emp.add << endl; //Appended Information -- must select Option 4 in Menu to add
		}


		//Close
		employee_info.close();
	}
	else {
		cout << endl << "Employee ID not found -- returning to Menu" << endl;
	}

}


/*Append Binary File Function*/ 
void append_file() {

	/*This Append Function will add additional comments to an Employee's File*/

		fstream employee_info;

		//User input variable for Employee ID search
		int choice;

		//Open
		employee_info.open("one_emp.data", ios::binary | ios::app); //Using 'app' flag to allow for appending


		//Validation
		if (!employee_info)
			exit;

		cout << endl << setw(5) << "Append Employee Information" << endl;
		cout << "----------------------------------------------" << endl;


		cout << endl << "Please enter the Employee ID Number: ";
		cin >> choice;

		if (choice == one_emp.id_num) {

			//Append
			cout << endl;
			cout << endl << "Please enter additional information you would like to add to Employee's File: ";
			cin >> one_emp.add;

			//Additional Information saved to File
			employee_info.write((char*)&one_emp, sizeof(one_emp));

			//Close
			employee_info.close();

			cout << endl << "Information appended to Employee's Profile" << endl;
			
		}
		else {
			cout << endl << "Employee ID not found -- returning to Menu" << endl;
			exit;
		}


}


/*Delete Binary File Function*/ 
void delete_content() {
	
	fstream employee_info;

	//Search Variable Declaration
	int search_num;

	//Open
	employee_info.open("one_emp.dat", ios::in | ios::binary);

	//New File create and open to overrite previous without desired record
	fstream new_file;
	new_file.open("temp.dat", ios::out | ios::binary);

	//Input for User's desired record to delete
	cout << "Please enter the Employee ID Number of the Profile you wish to delete: ";
	cin >> search_num;
	cout << endl;

	
	//Copying of old file to new file
	if (one_emp.id_num == search_num) {
		while (!employee_info.eof()) {
			employee_info.read((char*)&one_emp, sizeof(one_emp));
			new_file.write((char*)&one_emp, sizeof(one_emp));
	

		}
	}

	//Close of old and new file
	employee_info.close();
	new_file.close();

	remove("one_emp.dat");
	rename("temp.dat", "one_emp.dat");

}


/*Search for Record in Binary File Function*/ //-----------------------------------Fix input validation for File search
void search_file() {

	/*This Function will search for an Employee's ID Number
	  If found, it will display their Full Name*/

	fstream employee_info;

	//Search Variable Declarations
	int search_num;
	int choice;

	//Open
	employee_info.open("one_emp.dat", ios::in | ios::binary);

	if (!employee_info.eof()) {

		//Input for Search
		cout << "Please enter the Employee ID Number for the Search: ";
		cin >> search_num;
		cout << endl;

		if (!one_emp.id_num) {
			cout << "Employee Profile not found -- Please enter a valid ID Number: ";
			cin >> search_num;
			cout << endl;
		} 
		
		else if (one_emp.id_num) {



		//File Read to allow for Search
		employee_info.read((char*)&one_emp, sizeof(one_emp));

		cout << "Select which Information you would like to Search for" << endl;
		cout << "------------------------------------------------------------------" << endl;
		cout << "1 for Employee ID Number" << endl;
		cout << "2 for First Name" << endl;
		cout << "3 for Last Name" << endl;
		cout << "4 for Contact Number" << endl;
		cout << "5 for Email Address" << endl;
		cout << endl << "Enter choice: ";
		cin >> choice;
		cout << endl;

		//Input Validation
		if (choice <= 0 || choice > 6) {
			cout << "Error -- Please input a valid value: ";
			cin >> choice;
			cout << endl;
		}

		//Choosing which Info to Modify
		switch (choice) {

		case 1:
			cout << "Employee's ID Number is: " << one_emp.id_num;
			break;

		case 2:
			cout << "Employee's First Name is: " << one_emp.first_name;
			break;

		case 3:
			cout << "Employee's Last Name is: " << one_emp.last_name;
			break;

		case 4:
			cout << "Employee's Phone Number is: " << one_emp.phone;
			break;

		case 5:
			cout << "Employee's Email Address is: " << one_emp.email;
			break;
		}

		//Close
		//employee_info.close();
	}
	else {
		cout << "Error -- Employee not found -- Returning to Menu" << endl;
		exit;
	}

		//Close
		employee_info.close();
}

		cout << endl;
		
}


/*Modify Function*/
void modify_file() {

	fstream employee_info;

	//Open 
	employee_info.open("one_emp.dat", ios::in | ios::out);

	//File Search Validation
	if (!employee_info) exit;

	//Employee ID Number Search Variable Declaration
	int search_num;

	//Input for Search
	cout << "Please enter the Employee ID Number you wish to search for: ";
	cin >> search_num;
	cout << endl;

	if (!employee_info.eof()) {

		if (one_emp.id_num == search_num) {

		int choice;

		//File Read to allow for Search
		employee_info.read((char*)&one_emp, sizeof(one_emp));

		cout << "Select which Information you would like to Modify for the Employee" << endl;
		cout << "------------------------------------------------------------------" << endl;
		cout << "1 for Employee ID Number" << endl;
		cout << "2 for First Name" << endl;
		cout << "3 for Last Name" << endl;
		cout << "4 for Contact Number" << endl;
		cout << "5 for Email Address" << endl;
		cout << endl << "Enter choice: ";
		cin >> choice;
		cout << endl;

		//Input Validation
		if (choice <= 0 || choice > 6) {
			cout << "Error -- Please input a valid value: ";
			cin >> choice;
			cout << endl;
		}

		//Choosing which Info to Modify
		switch (choice) {

		case 1:
			cout << "Please enter Employee's new ID Number: ";
			cin >> one_emp.id_num;
			employee_info.write((char*)&one_emp, sizeof(one_emp)); //Write modified info to File
			cout << endl << "Information Modified" << endl;
			break;

		case 2:
			cout << "Please enter Employee's new First Name: ";
			cin >> one_emp.first_name;
			employee_info.write((char*)&one_emp, sizeof(one_emp));
			cout << endl << "Information Modified" << endl;
			break;

		case 3:
			cout << "Please enter Employee's new Last Name: ";
			cin >> one_emp.last_name;
			employee_info.write((char*)&one_emp, sizeof(one_emp));
			cout << endl << "Information Modified" << endl;
			break;

		case 4:
			cout << "Please enter Employee's new Phone Number: ";
			cin >> one_emp.phone;
			employee_info.write((char*)&one_emp, sizeof(one_emp));
			cout << endl << "Information Modified" << endl;
			break;

		case 5:
			cout << "Please enter Employee's new Email Address: ";
			cin >> one_emp.email;
			employee_info.write((char*)&one_emp, sizeof(one_emp));
			cout << endl << "Information Modified" << endl;
			break;
		}

		}

		//Close
		employee_info.close();
	}
}


/*Sort Function*/
void sort_file() {

	fstream employee_info;

	//Open
	employee_info.open("one_emp.dat", ios::out | ios::binary);

	//Read
	employee_info.read((char*)&one_emp, sizeof(one_emp));

	//While not end of File, Sort Function will sort the File based on their Character Length
	while (!employee_info.eof()) {

		//Sort Function which will take the beginning of the One Employee Binary File and sort it by the length of it

		//sort(one_emp.begin(sizeof(one_emp)), one_emp.end(sizeof(one_emp)));

		//Write to File once Strings have been stored
		employee_info.write((char*)&one_emp, sizeof(one_emp));

	}

	//Close
	employee_info.close();

}


/*Wipe out Contents w/ Notification to User Function*/
void wipe_file() {

	string choice;

	fstream employee_info;

	cout << endl << "WARNING -- PROCEEDING WILL DELETE THE EMPLOYEE PROFILE" << endl;
	cout << "..." << endl;
	cout << "If you would like to continue, please input 'Proceed': ";
	cin >> choice;

	if (choice == "proceed" || choice == "Proceed") {
		
		//File is first closed then reopened - upon opening, trunc flag deletes contents of the file
		employee_info.close();
		employee_info.open("one_emp.dat", ios::trunc); 

		cout << endl << "FILE HAS BEEN DELETED" << endl;

	}
	else {
		cout << "Invalid input -- returning to Menu" << endl;
	}
}


/*Check if Employee Record Exists*/ 
void check_if() {

	fstream employee_info;

	//Open
	employee_info.open("one_emp.dat", ios::in | ios::binary); 

	//Check File exists -- Condition is check if file is not found
	//If found it will tell User File is available
	if (employee_info.fail()) {

		cout << endl << "File not found" << endl;

	} else if (employee_info.good()) {
		cout << endl << "File has been found" << endl;
	}
	else {
		exit;
	}
	
	//Close
	employee_info.close();

}

/*Create File*/
void create_file() {

	//Creating Binary File of Employee Information
	fstream employee_info("one_emp.dat", ios::out | ios::binary);

	if (employee_info) {
		cout << "File successfully created" << endl;
	}
	else {
		cout << "File not successfully created" << endl;
	}


}


/*Goodbye Function*/
void goodbye_fun() {
	cout << endl << "Thank you and have a great day!" << endl;
}