#pragma once
#include <iostream>
#include <string>
#include <sstream> //convert datatypes like address, double into string
#include <ctype.h> //for input validation: isdigit()
#include <ctime> //for date format validation
#include <algorithm> //for uppercase the input for easing future search
#include <vector> //for the usage of splitting string by delimiter

//sleep functions
#include <chrono>
#include <thread>

// to avoid error in line 520 due to Visual Studio suggesting the other alternative and halt the system when the code is working well
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
// to define a macro to call out the length of the array
#define arrayLength(array) (sizeof((array))/sizeof((array)[0]))

/* global variables */
// array for displaying rating description
std::string ratingdescription[5] = { "Very Poor Performance", "Below Average", "Average", "Above Average", "Excellent Performance" };

// array for displaying numbers in english
std::string numberenglish[11] = { "one", "two", "three", "four", "five",
								  "six", "seven", "eight", "nine", "ten",
								  "eleven" };

// array for table titles
std::string tabletitle[11] = { "Tutor ID", "Name", "Date Joined", "Date Terminated", "Hourly Rate (RM)",
							   "Phone", "Address", "Tuition Centre Code", "Tuition Centre Name", "Subject",
							   "Rating" };

// pointer format on those array so we can call the value within them
// pointer format of table titles
std::string * tabletitlepointer = new std::string[11]{ "Tutor ID", "Name", "Date Joined", "Date Terminated", "Hourly Rate (RM)",
													   "Phone", "Address", "Tuition Centre Code", "Tuition Centre Name", "Subject",
													   "Rating" };

// array for options
std::string * optionsmain = new std::string [9]{ "Insert", "Display", "Search", "Sort", 
												 "Modify", "Delete", "Reset", "Report",
												 "Exit" };

// array for insert options
std::string * optionsinsert = new std::string[3]{ "Insert (End)", "Insert (Sort)", "Back"};

// array for display options
std::string * optiondisplay = new std::string[3]{ "Display Table (Normal/Ascending Order)", "Display Table (Descending Order)", "Back" };

// array for search options
std::string * optionsearch = new std::string[2]{ "Search (Specific Value)", "Back" };

// array for sort options
std::string * optionsort = new std::string[5]{ "Sort (ID)", "Sort (Location)", "Sort (Hourly Rate)", "Sort (Rating)", "Back" };

// array for modify options
std::string * optionmodify = new std::string[2]{ "Modify (Specific Data)", "Back" };

// array for data types of modify option
std::string* modifytypes = new std::string[11]{  "Name", "Date Joined", "Date Terminated", "Hourly Rate (RM)",
												 "Phone", "Address", "Tuition Centre Code", "Tuition Centre Name", "Subject",
												 "Rating", "Back" };

// array for delete options
std::string * optiondelete = new std::string[3]{ "Delete (Row)", "Delete (All)", "Back" };

// array for true false option
std::string* truefalseoption = new std::string[2]{ "Yes", "No" };

// array for asc/desc option
std::string* ascdescoption = new std::string[2]{ "Ascending Order", "Descending Order" };

// vaiables for holding the values to form the table
int idL;
int nameL;
int datejL;
int datetL;
int rateL;
int phoneL;
int addressL;
int tccodeL;
int tcnameL;
int subjectL;
int ratingL;

// to identify which type of the user you are
int role = NULL;

struct tms {
	tms* id;
	tms* prev;
	tms* next;

	std::string name;
	std::string dateJ;
	std::string dateT;
	double hourlyrate;
	std::string phone;
	std::string address;
	int tccode;
	std::string tcname;
	std::string subject;
	int rating;

}*head, *tail, *temp, *sorthead, *sorttail, *sorttemp, *reporthead, *reporttail, *reporttemp, *holdhead, *holdtail, *holdtemp;

/* function */
// assign global variable value by address
// assign role value
void assignrole(int input);

// all at once: assigning the global variable total char length all at once
void globes(int idN, int nameN, int datejN, int datetN, int rateN, int phoneN, int addressN, int tccodeN, int tcnameN, int subjectN, int ratingN);

// situational: assigning the global variable total char length based on the situation
void globe(int type, int input);

// input validation
// integer only
int intValidate(std::string input);

// double only
int doubleValidate(std::string input);

// receiving inputs and perform input validation
int inputValidation(int optionsnum);

// date format validation
// function expects the string in format yyyy/mm/dd:
bool extractDate(const std::string& s, int& y, int& m, int& d);

// validate the legitimacy of the date value
bool legitDate(std::string inputdate, std::string comparingdate);

// get the current date value
std::string currentDate();

// count the total days of the date format based on the time given
int diffDays(std::string inputdate, std::string comparingdate);

// perform the date validation on deletion requirement based on the address/ID given
bool checkDatesDiff(std::string addressSTR);

// space validation, allowing only one space for inserting NULL
int spaceValidate(std::string input);

// split the string specifically
void tokenize(std::string const& str, const char delim, std::vector<std::string>& out);

// call out a specific value of the array(pointer form)
std::string arrayOption(std::string* arr, int index);

// count the number of char within the data of the list, and find the highest value
bool totalChar();

// table lines: horizontal 
void horizontalLine();

// table lines: titles
void titleLine();

// table lines: data
void dataLine();

// reversed table lines: data
void reversedDataLine();

// sorted table lines: data
void sortedDataLine();

// report table lines: data
void reportDataLine();

// display table
void displayTable();

// display table in reverse order
void displayReverseTable();

// display sorted table
void displaySortedTable();

// display report table
void displayReportTable();

// display specific table data only
void displayRow(tms * address);

// showing available options
void displayOption();

// assign and display option value for space alignment
// P.S: the arrlength will be needed to manually assign if the array is a pointer form instead of normal one since it can't be used by the macro arrayLength() to calculate the total length of the array
// showing available action within option
void displayAction(std::string* arr, int arrlength);

// verify role
void verifyrole();

// create new node
tms* createnewnode(std::string name, std::string datej, std::string datet, double hourlyrate, std::string phone, std::string address, int tccode, std::string tcname, std::string subject, int rating);

// count total nodes within the list
int totalNodes();

// insertions
// insert last
void insertLast(std::string name, std::string datej, std::string datet, double hourlyrate, std::string phone, std::string address, int tccode, std::string tcname, std::string subject, int rating);

// insert sort
void insertSort(std::string name, std::string datej, std::string datet, double hourlyrate, std::string phone, std::string address, int tccode, std::string tcname, std::string subject, int rating);

// insert into sorted list: ID
void sortedlistID(int order);

// insert into sorted list: Location
void sortedlistLocation(int order);

// insert into sorted list: Rating
void sortedlistRating(int order, tms* listtype);

// insert into sorted list: Hourly Rate
void sortedlistHourly(int order);

// search specific row based on the data
bool searchRow(int type, std::string value);

/* perform option function based on the selected option */
// main option to perform selected action
void mainOption(int option);

// insert option to perform selected action
void insertOption(int option);

// display table option to perform selected action
void displayTBLOption(int option);

// search option to perform selected action
void searchOption(int option);

// sort option to perform selected action
void sortOption(int option);

// sort option by specific data in ascending or descending order, based on the specific option
void sortData(int type, int order);

// modify option to perform selected action
void modifyOption(int option);

// delete option to perform selected action
void deleteOption(int option);

// modify
// modify specific value
void modifySpecific(std::string addressSTR);

// modify process based on the input types
bool modifyData(int type, std::string value, tms * address);

// delete specific row
void deleteRow(std::string addressSTR, tms* listtype);

// delete all
void deleteAll(tms* listtype);

// generate report
void generateReport();

// verify deletion
bool confirmDel();

// exit the system
void exitSystem();

/* function algorithms */
void assignrole(int input) {
	int* address;

	address = &role;
	*address = input;
}

void globes(int idN, int nameN, int datejN, int datetN, int rateN, int phoneN, int addressN, int tccodeN, int tcnameN, int subjectN, int ratingN) {
	int* address;

	address = &idL;
	*address = idN;
	
	address = &nameL;
	*address = nameN;

	address = &datejL;
	*address = datejN;

	address = &datetL;
	*address = datetN;

	address = &rateL;
	*address = rateN;

	address = &phoneL;
	*address = phoneN;

	address = &addressL;
	*address = addressN;

	address = &tccodeL;
	*address = tccodeN;

	address = &tcnameL;
	*address = tcnameN;

	address = &subjectL;
	*address = subjectN;

	address = &ratingL;
	*address = ratingN;
}

void globe(int type, int input) {
	int* address;

	switch (type) {
	case 0:
		address = &idL;
		*address = input;
		break;

	case 1:
		address = &nameL;
		*address = input;
		break;
	
	case 2:
		address = &datejL;
		*address = input;
		break;

	case 3:
		address = &datetL;
		*address = input;
		break;

	case 4:
		address = &rateL;
		*address = input;
		break;

	case 5:
		address = &phoneL;
		*address = input;
		break;

	case 6:
		address = &addressL;
		*address = input;
		break;

	case 7:
		address = &tccodeL;
		*address = input;
		break;

	case 8:
		address = &tcnameL;
		*address = input;
		break;

	case 9:
		address = &subjectL;
		*address = input;
		break;

	case 10:
		address = &ratingL;
		*address = input;
		break;
	}
}

int intValidate(std::string input) {
	// check whether there are any character other than integer exist or not
	int i = 0;
	int character = 0;
	while (input[i])
	{
		if (isalpha(input[i])) {
			// count the total number of alphabet character within the input
			character++;
		}
		if (ispunct(input[i])) {
			// count the total number of symbol character within the input
			character++;
		}
		if (isspace(input[i])) {
			// count the total number of space within the input
			character++;
		}

		i++;
	}

	return character;
}

int doubleValidate(std::string input) {
	// check whether there are any character other than integer exist or not
	int i = 0;
	int character = 0;
	int numeric = 0;
	int dot = 0;
	std::string searchPunct = ",-;:'\"()?!#%&+/<=>@[]^_`{|}~";
	std::string searchDouble = ".";

	while (input[i])
	{
		if (isdigit(input[i])) {
			// count the total number of numeric within the input
			numeric++;
		}

		if (isalpha(input[i])) {
			// count the total number of alphabet character within the input
			character++;
		}

		// count the total number of symbol character except "." within the input
		static const std::string searchPunct = ",-;:'\"()?!#%&+/<=>@[]^_`{|}~";
		if (searchPunct.find(input[i]) != std::string::npos) {
			character++;
		}

		// count the total number of dot character within the input
		static const std::string searchDouble = ".";;
		if (searchDouble.find(input[i]) != std::string::npos) {
			dot++;
		}

		if (isspace(input[i])) {
			// count the total number of space within the input
			character++;
		}

		i++;
	}

	// if dot is more than one then add it into character
	if (dot > 1) {
		character = character + dot;
	}

	// if dot is one and while numeric is 0 or less than 2, means the input is only a dot, and we can't allow that
	if ((dot == 1) && ((numeric == 0) || (numeric < 2))) {
		character = character + dot;
	}

	return character;
}

int inputValidation(int optionsnum) {
	std::string input;
	bool validate = false;
	int option = NULL;
	int character = NULL;

	while (validate == false) {
		// validate whether the input is numeric or not
		std::getline(std::cin, input);
		// check whether there are any character other than input exist or not
		character = intValidate(input);

		// if its more than 0 then go in to the loop
		while (character > 0) {
			// show the message if the input is invalid
			character = 0;

			std::cout << "System Notice: Invalid input, please try again." << std::endl;
			validate = false;
			std::cout << "User Input: ";
			// validate whether the input is numeric or not
			std::getline(std::cin, input);
			// check whether there are any character other than input exist or not
			character = intValidate(input);
		}

		if (character == 0) {
			// object from the class stringstream 
			std::stringstream geek(input);

			// stream it to the integer 
			geek >> option;
			if ((option < (optionsnum + 1)) && (option != 0) && (option > 0)) {
				validate = true;

				return option;
			}
			else {
				validate = false;

				std::cout << "System Notice: There is only " << numberenglish[(optionsnum - 1)] << " options available, please try again." << std::endl;
				std::cout << "User Input: ";
			}
		}
	}
}

bool extractDate(const std::string& s, int& y, int& m, int& d) {
	std::istringstream is(s);
	char delimiter;
	if (is >> y >> delimiter >> m >> delimiter >> d) {
		struct tm t = { 0 };
		t.tm_year = y - 1900;
		t.tm_mon = m - 1;
		t.tm_mday = d;
		t.tm_isdst = -1;

		// normalize:
		time_t when = mktime(&t);
		const struct tm* norm = localtime(&when);
		// the actual date would be:
		// m = norm->tm_mon + 1;
		// d = norm->tm_mday;
		// y = norm->tm_year;
		// e.g. 29/02/2013 would become 01/03/2013

		// validate (is the normalized date still the same?):
		return (norm->tm_year == y - 1900 &&
			norm->tm_mon == m - 1 &&
			norm->tm_mday == d);
	}
	return false;
}

bool legitDate(std::string inputdate, std::string comparingdate) {
	std::string comparing;
	int n = 1;
	int tempM = NULL;

	int inputY = 0;
	int inputM = 0;
	int inputD = 0;
	int y = 0;
	int m = 0;
	int d = 0;

	int differTotal = 0;
	int intdata = NULL;
	int febDay = NULL;

	// get the date you want to compare
	comparing = comparingdate;

	// then use the comparing date to compare
	// first seperate the date format specifically and assign them into specific variable
	const char delim = '/';
	std::vector<std::string> out;

	tokenize(inputdate, delim, out);
	for (auto& inputdate : out) {
		// convert string into int
		intdata = stoi(inputdate);
		if (n == 1) {
			inputY = intdata;
		}
		else if (n == 2) {
			inputM = intdata;
		}
		else if (n == 3) {
			inputD = intdata;
		}
		n++;
	}
	// reset the n variable back to 1 for future uses
	n = 1;

	std::vector<std::string> outcompare;
	// first seperate the current date format specifically and assign them into specific variable
	tokenize(comparing, delim, outcompare);
	for (auto& comparing : outcompare) {
		// convert string into int
		intdata = stoi(comparing);
		if (n == 1) {
			y = intdata;
		}
		else if (n == 2) {
			m = intdata;
		}
		else if (n == 3) {
			d = intdata;
		}
		n++;
	}
	// reset the n variable back to 1 just in case
	n = 1;

	// perform calculation and comparison now
	// before perform the calculation we will check whether its leap year or not based on the current date
	if (y % 4 == 0) {
		febDay = 29;
	}
	else {
		febDay = 28;
	}

	if (y >= inputY) {
		// first we calculate the differences of year
		y = y - inputY;

		// then we compare which of the month value is bigger, then calculate it if possible
		if (m >= inputM) {
			// assign the comparing month into temporary month before calculation for future uses
			tempM = m;
			m = m - inputM;

			// finally we compare the days of the dateformat to calculate
			if (d >= inputD) {
				d = d - inputD;

				// even if its more than a day than the comparing date, its legitimate
				if (d >= 0) {
					return true;
				}
				// if its zero, then its unacceptable
				else {
					return false;
				}
			}
			else {
				// check the value of the month is possible to countinue the calculation or not
				if (m > 0) {
					m = m - 1;
					// if the current month is february then assign the specific days into it
					if (tempM == 2) {
						d = ((d + febDay) - inputD);
					}
					else if ((tempM == 1) || (tempM == 3) || (tempM == 5) || (tempM == 7) || (tempM == 8) || (tempM == 10) || (tempM == 12)) {
						d = ((d + 31) - inputD);
					}
					else if ((tempM == 4) || (tempM == 6) || (tempM == 9) || (tempM == 11)) {
						d = ((d + 30) - inputD);
					}

					// even if its more than a day than the comparing date, its legitimate
					if (d >= 0) {
						return true;
					}
					// if its zero, then its unacceptable
					else {
						return false;
					}
				}
				else {
					// if not then return false already since the input date format is larger than the comparing date
					return false;
				}
			}
		}
		else {
			// check the value of year is possible to continue the calculation or not
			if (y > 0) {
				y = y - 1;
				m = ((m + 12) - inputM);

				// this is where we 100% confirmed the comparing date format is bigger than the input date format due to the capability of adding another 12 months to perform calculation, so we straight away return true instead
				return true;
			}
			else {
				// if not then return false already since the input date format is larger than the comparing date
				return false;
			}
		}
	}
	else {
		// since from the year we already know which date is actually bigger so we straight return false to notify the input date is larger than comparing date
		return false;
	}
}

std::string currentDate() {
	std::string now;
	// getting the current time
	std::time_t rawtime;
	std::tm* timeinfo;
	char buffer[80];

	std::time(&rawtime);
	timeinfo = std::localtime(&rawtime);

	std::strftime(buffer, sizeof(buffer), "%Y/%m/%d", timeinfo);
	std::string str(buffer);

	now = buffer;

	return now;
}

int diffDays(std::string inputdate, std::string comparingdate) {
	int total = 0;
	std::string comparing;
	int n = 1;
	bool check = false;
	int tempM = NULL;
	int tempY = NULL;
	int calcY = NULL;
	int used = 0;

	int inputY = 0;
	int inputM = 0;
	int inputD = 0;
	int y = 0;
	int m = 0;
	int d = 0;

	int differTotal = 0;
	int intdata = NULL;
	int febDay = NULL;
	int yearlyDay = NULL;

	// get the date you want to compare
	comparing = comparingdate;

	// then use the comparing date to compare
	// first seperate the date format specifically and assign them into specific variable
	const char delim = '/';
	std::vector<std::string> out;

	tokenize(inputdate, delim, out);
	for (auto& inputdate : out) {
		// convert string into int
		intdata = stoi(inputdate);
		if (n == 1) {
			inputY = intdata;
		}
		else if (n == 2) {
			inputM = intdata;
		}
		else if (n == 3) {
			inputD = intdata;
		}
		n++;
	}
	// reset the n variable back to 1 for future uses
	n = 1;

	std::vector<std::string> outcompare;
	// first seperate the current date format specifically and assign them into specific variable
	tokenize(comparing, delim, outcompare);
	for (auto& comparing : outcompare) {
		// convert string into int
		intdata = stoi(comparing);
		if (n == 1) {
			y = intdata;
		}
		else if (n == 2) {
			m = intdata;
		}
		else if (n == 3) {
			d = intdata;
		}
		n++;
	}
	// reset the n variable back to 1 just in case
	n = 1;

	// perform calculation and comparison now
	// before perform the calculation we will check whether its leap year or not based on the current date
	if (y % 4 == 0) {
		febDay = 29;
		yearlyDay = 366;
	}
	else {
		febDay = 28;
		yearlyDay = 365;
	}

	tempY = y;
	if (y >= inputY) {
		// first we calculate the differences of year
		y = y - inputY;

		// then we compare which of the month value is bigger, then calculate it if possible
		if (m >= inputM) {
			// assign the comparing month into temporary month before calculation for future uses
			tempM = m;
			m = m - inputM;

			// finally we compare the days of the dateformat to calculate
			if (d >= inputD) {
				d = d - inputD;

				// even if its more than a day than the comparing date, its legitimate
				if ((d > 0) || (y > 0) || (m > 0)) {
					// start to count the total days of between the two date format
					check = true;
				}
				// if its zero, then its unacceptable
				else {
					return false;
				}
			}
			else {
				// check the value of the month is possible to countinue the calculation or not
				// if m is 0 while y is not, then we can substract and add 12 on m
				if ((y != 0) & (m == 0)) {
					y = y - 1;
					m = m + 12;
				}
				if (m > 0) {
					m = m - 1;
					// if the current month is february then assign the specific days into it
					if (tempM == 2) {
						d = ((d + febDay) - inputD);
					}
					else if ((tempM == 1) || (tempM == 3) || (tempM == 5) || (tempM == 7) || (tempM == 8) || (tempM == 10) || (tempM == 12)) {
						d = ((d + 31) - inputD);
					}
					else if ((tempM == 4) || (tempM == 6) || (tempM == 9) || (tempM == 11)) {
						d = ((d + 30) - inputD);
					}

					// even if its more than a day than the comparing date, its legitimate
					if ((d > 0) || (y > 0) || (m > 0)) {
						check = true;
					}
					// if its zero, then its unacceptable
					else {
						return false;
					}
				}
				else {
					// if not then return false already since the input date format is larger than the comparing date
					return false;
				}
			}
		}
		else {
			// check the value of year is possible to continue the calculation or not
			if (y > 0) {
				y = y - 1;
				tempM = m;
				m = ((m + 12) - inputM);

				// finally we compare the days of the dateformat to calculate
				if (d >= inputD) {
					d = d - inputD;

					// even if its more than a day than the comparing date, its legitimate
					if ((d > 0) || (y > 0) || (m > 0)) {
						// start to count the total days of between the two date format
						check = true;
					}
					// if its zero, then its unacceptable
					else {
						return false;
					}
				}
				else {
					// check the value of the month is possible to countinue the calculation or not
					if (m > 0) {
						m = m - 1;
						// if the current month is february then assign the specific days into it
						if (tempM == 2) {
							d = ((d + febDay) - inputD);
						}
						else if ((tempM == 1) || (tempM == 3) || (tempM == 5) || (tempM == 7) || (tempM == 8) || (tempM == 10) || (tempM == 12)) {
							d = ((d + 31) - inputD);
						}
						else if ((tempM == 4) || (tempM == 6) || (tempM == 9) || (tempM == 11)) {
							d = ((d + 30) - inputD);
						}

						// even if its more than a day than the comparing date, its legitimate
						if ((d > 0) || (y > 0) || (m > 0)) {
							check = true;
						}
						// if its zero, then its unacceptable
						else {
							return false;
						}
					}
					else {
						// if not then return false already since the input date format is larger than the comparing date
						return false;
					}
				}
			}
			else {
				// if not then return false already since the input date format is larger than the comparing date
				return false;
			}
		}
	}
	else {
		// since from the year we already know which date is actually bigger so we straight return false to notify the input date is larger than comparing date
		return false;
	}

	// if once we know the calculation can be done then we start the calculation
	if (check != false) {
		// count the total number of the days
		// if after calculation the year is only 1 or 0 then calculate it straightforwardly
		if ((y == 1) || (y == 0)) {
			total = total + ((y * yearlyDay) + (d));
			// if after calculation the number of months is not equal 0 then
			if (m != 0) {
				// in descending order for accuracy, e.g: 10, 9, 8, 7, 6 month
				for (int i = m; i > 0; i--) {
					tempM--;

					if ((tempM == 0) && (((tempY - inputY) - used) > 0)) {
						tempM = tempM + 12;
						used++;
					}

					// add the specific total days based on the specific month
					if (tempM == 2) {
						total = total + febDay;
					}
					else if ((tempM == 1) || (tempM == 3) || (tempM == 5) || (tempM == 7) || (tempM == 8) || (tempM == 10) || (tempM == 12)) {
						total = total + 31;
					}
					else if ((tempM == 4) || (tempM == 6) || (tempM == 9) || (tempM == 11)) {
						total = total + 30;
					}
				}
			}
		}
		// else if after calculation the year is more than 1, means we need to calculate it accordingly, by checking whether its leap year or not
		else if (y > 1) {
			// first we add the current total with the day we have
			total = total + d;
			// assign the tempY value to calcY
			calcY = tempY;
			// then we put into a while loop by constantly check the leap year and add it specifically
			if (y != 0) {
				// in descending order for accuracy, e.g: 2020, 2019, 2018 year, etc
				for (int i = y; i >= 0; i--) {
					tempY = tempY - 1;
					// before perform the calculation we will check whether its leap year or not based on the current date
					if (tempY % 4 == 0) {
						febDay = 29;
						yearlyDay = 366;
					}
					else {
						febDay = 28;
						yearlyDay = 365;
					}
					// if after calculation the number of months is not equal 0 then
					if (m != 0) {
						// in descending order for accuracy, e.g: 10, 9, 8, 7, 6 month
						for (int i = m; i > 0; i--) {
							tempM--;

							if ((tempM == 0) && (((calcY - inputY) - used) > 0)) {
								tempM = tempM + 12;
								used++;
							}

							// add the specific total days based on the specific month
							if (tempM == 2) {
								total = total + febDay;
							}
							else if ((tempM == 1) || (tempM == 3) || (tempM == 5) || (tempM == 7) || (tempM == 8) || (tempM == 10) || (tempM == 12)) {
								total = total + 31;
							}
							else if ((tempM == 4) || (tempM == 6) || (tempM == 9) || (tempM == 11)) {
								total = total + 30;
							}
						}
					}
					// make the m as 12 (count from December descendingly) since we've count the remaining months and proceed to the remaining year's month
					m = 12;
				}
			}
		}
	}

	return total;
}

bool checkDatesDiff(std::string addressSTR) {
	// this deletion function that required us to check the date requirement is based on the main list: head
	// so we call head into the temp for calling the date value (date joined and terminated)
	temp = head;
	std::string tempSTR;
	int datediff = NULL;
	bool found = false;
	bool legit = false;

	// convert address into string
	std::ostringstream get_the_address;

	while (temp != NULL) {
		// convert addresses into string
		get_the_address << temp;
		tempSTR = get_the_address.str();

		// break when we found the exact ID 
		// no checking of the ID whether exist within the list required as we did that in the previous function
		if (tempSTR == addressSTR) {
			found = true;

			break;
		}

		temp = temp->next;
		found = false;
		get_the_address.str("");
		get_the_address.clear();
	}

	// if we have found the related ID, the we will start to compare whether the date has reached 6 months or not
	if (found == true) {
		// check if date terminated is NULL or not
		if ((temp->dateT) != " ") {
			datediff = diffDays(temp->dateT, currentDate());
			// according to business terms, 6 month duration should be "180 days", regardless of factors like leap-year
			if (datediff >= 180) {
				legit = true;
			}
			else {
				legit = false;
			}
		}
		else {
			std::cout << "System Notice: Date Terminated of Tutor ID: " << temp << " is NULL, deletion halted." << std::endl;
			legit = false;
		}
	}
	else {
		legit = false;
	}

	return legit;
}

int spaceValidate(std::string input) {
	// check whether there are any character other than integer exist or not
	int i = 0;
	int space = 0;
	int character = 0;
	while (input[i])
	{
		if (isalpha(input[i])) {
			// count the total number of alphabet character within the input
			character++;
		}
		if (ispunct(input[i])) {
			// count the total number of symbol character within the input
			character++;
		}
		if (isdigit(input[i])) {
			// count the total number of digit within the input
			character++;
		}
		if (isspace(input[i])) {
			// count the total number of space within the input
			space++;
		}
		
		i++;
	}

	// assuming if there are other characters like symbol or alphabets not exist, means the user intend to enter an empty string
	if (character == 0) {
		// check the number of space
		if (space > 1) {
			character = character + space;
		}
	}

	return character;
}

void tokenize(std::string const& str, const char delim, std::vector<std::string>& out) {
	size_t start;
	size_t end = 0;

	while ((start = str.find_first_not_of(delim, end)) != std::string::npos)
	{
		end = str.find(delim, start);
		out.push_back(str.substr(start, end - start));
	}
}

std::string arrayOption(std::string* arr, int index) {
	std::string dataTemp;

	dataTemp = arr[(index - 1)];

	return dataTemp;
}

bool totalChar() {
	std::string tempSTR;
	int tempN = 0;
	int holdN = 0;
	int calcN = 0;
	int charN = 0;

	globes(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

	if (head != NULL) {
		temp = head;

		while (temp != NULL) {
			std::string strvar;
			int rating = 0;
			int intvar = 0;
			double dblvar = 0;

			// calculate the number of char within, by using calcN
			// get the global variable value into tempN
			for (int n = 0; n < arrayLength(tabletitle); n++) {
				// memory address/id
				if (n == 0) {
					//convert address into string
					std::ostringstream get_the_address;
					get_the_address << temp;
					tempSTR = get_the_address.str();

					tempN = idL;
				}
				// name
				else if (n == 1) {
					strvar = temp->name;

					if (strvar != " ") {
						tempSTR = temp->name;
					}
					else {
						tempSTR = "NULL";
					}

					tempN = nameL;
				}
				// date joined
				else if (n == 2) {
					strvar = temp->dateJ;

					if (strvar != " ") {
						tempSTR = temp->dateJ;
					}
					else {
						tempSTR = "NULL";
					}

					tempN = datejL;
				}
				// date terminated
				else if (n == 3) {
					strvar = temp->dateT;

					if (strvar != " ") {
						tempSTR = temp->dateT;
					}
					else {
						tempSTR = "NULL";
					}

					tempN = datetL;
				}
				// hourly rate
				else if (n == 4) {
					dblvar = temp->hourlyrate;

					if (dblvar != NULL) {
						//convert double into string
						std::ostringstream get_the_double;
						get_the_double << temp->hourlyrate;
						tempSTR = get_the_double.str();
					}
					else {
						tempSTR = "NULL";
					}

					tempN = rateL;
				}
				// phone
				else if (n == 5) {
					strvar = temp->phone;

					if (strvar != " ") {
						tempSTR = temp->phone;
					}
					else {
						tempSTR = "NULL";
					}

					tempN = phoneL;
				}
				// address name
				else if (n == 6) {
					strvar = temp->address;

					if (strvar != " ") {
						tempSTR = temp->address;
					}
					else {
						tempSTR = "NULL";
					}

					tempN = addressL;
				}
				// tuition center code
				else if (n == 7) {
					intvar = temp->tccode;

					if (intvar != NULL) {
						//convert int into string
						std::ostringstream get_the_int;
						get_the_int << temp->tccode;
						tempSTR = get_the_int.str();
					}
					else {
						tempSTR = "NULL";
					}
				
					tempN = tccodeL;
				}
				// tuition center name
				else if (n == 8) {
					strvar = temp->tcname;

					if (strvar != " ") {
						tempSTR = temp->tcname;
					}
					else {
						tempSTR = "NULL";
					}
					
					tempN = tcnameL;
				}
				// subject
				else if (n == 9) {
					strvar = temp->subject;

					if (strvar != " ") {
						tempSTR = temp->subject;
					}
					else {
						tempSTR = "NULL";
					}

					tempN = subjectL;
				}
				// rating
				else if (n == 10) {
					//convert int into string
					rating = temp->rating;

					if (rating != NULL) {
						tempSTR = ratingdescription[(rating - 1)];
					}
					else {
						tempSTR = "NULL";
					}
					
					tempN = ratingL;
				}

				// calculate the total char within the data
				for (int i = 0; tempSTR[i]; i++) {
					charN++;
				}
				calcN = charN;

				// since rating have some extra description so we need to add by 8 to align the space properly
				if (n == 10) {
					calcN = calcN + 8;
				}
				//reset the charN: the number of char within the string to 0 to perform further calculation
				charN = 0;

				//then compare with calcN. If holdN is smaller, then assign the value of tempN into global variable
				if (calcN >= tempN) {
					globe(n, calcN);
				}
			}
			//reset calcN into 0 for upcoming calculation	
			calcN = 0;

			temp = temp->next;
		}
	}
	else {
		// by default all data value will be 4 since NULL is 4 char
		globes(4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4);

		// if the list is empty, return false to notify that the list is empty
		return false;
	}
}

void horizontalLine() {
	// during the construction of the table we will calculate the number of char of the title like "No.", "Artist", etc to compare with our upcoming data value length to determine the space
	// by default the table should be this "+--+"
										//  |  |
										// "+--+"
	// 2 space remain around the word in the cell to make it alligned
	// in order to properly allign the table we need to by first calculate every single char within the string, and take the largest number as base
	int charN = 0;
	int tempSpaceT = 0;
	int assignSpace = 0;
	int dataSpace = 0;
	int calcSpace = 0;

	std::string charTitles;

	std::cout << "   ";
	for (int i = 0; i < arrayLength(tabletitle); i++) {
		// assign the value of the array to a variable
		charTitles = tabletitle[i];
		// to calculate the length
		for (int j = 0; charTitles[j]; j++) {
			charN++;
		}
		// after obtained the length we will start to calculate the space of the cell
		tempSpaceT = (charN + 2);

		// check if the length of the data is longer than its title or not
		// assigning the value into a common variable to perform latter calculation
		if (i == 0) {
			calcSpace = idL;
		}
		else if (i == 1) {
			calcSpace = nameL;
		}
		else if (i == 2) {
			calcSpace = datejL;
		}
		else if (i == 3) {
			calcSpace = datetL;
		}
		else if (i == 4) {
			calcSpace = rateL;
		}
		else if (i == 5) {
			calcSpace = phoneL;
		}
		else if (i == 6) {
			calcSpace = addressL;
		}
		else if (i == 7) {
			calcSpace = tccodeL;
		}
		else if (i == 8) {
			calcSpace = tcnameL;
		}
		else if (i == 9) {
			calcSpace = subjectL;
		}
		else if (i == 10) {
			calcSpace = ratingL;
		}

		// performing calculation
		if ((calcSpace + 2) > tempSpaceT) {
			assignSpace = (calcSpace + 2);
		}
		else if ((calcSpace + 2) < tempSpaceT) {
			assignSpace = tempSpaceT;
		}
		else {
			assignSpace = (calcSpace + 2);
		}

		for (int k = 1; k <= assignSpace; k++) {
			if (k == 1) {
				std::cout << "+";
			}
			std::cout << "-";
		}

		// reset charN, tempSpaceT, calcSpace, and assignSpace to 0 for further uses
		charN = 0;
		tempSpaceT = 0;
		calcSpace = 0;
		assignSpace = 0;
	}
	// put extra "+" at the end because normally it only start at the begining
	std::cout << "+" << std::endl;
}

void titleLine() {
	// during the construction of the table we will calculate the number of char of the title like "No.", "Artist", etc to compare with our upcoming data value length to determine the space
	// by default the table should be this "+--+"
										//  |  |
										// "+--+"
	// 2 space remain around the word in the cell to make it alligned
	// in order to properly allign the table we need to by first calculate every single char within the string, and take the largest number as base
	int charN = 0;
	int tempSpaceT = 0;
	int assignSpace = 0;
	int dataSpace = 0;
	int calcSpace = 0;

	std::string charTitles;

	// begin to assign the value accordingly with spatial concern
	std::cout << "   ";
	for (int i = 0; i < arrayLength(tabletitle); i++) {
		std::cout << "|";

		// calculate the length of the data, then determine the space base on that
		// assign the value of the array to a variable
		charTitles = tabletitle[i];
		// to calculate the length
		for (int j = 0; charTitles[j]; j++) {
			charN++;
		}
		// after obtained the length we will start to calculate the space of the cell
		tempSpaceT = (charN + 2);
		dataSpace = charN;

		// check if the length of the data is longer than its title or not
		// assigning the value into a common variable to perform latter calculation
		if (i == 0) {
			calcSpace = idL;
		}
		else if (i == 1) {
			calcSpace = nameL;
		}
		else if (i == 2) {
			calcSpace = datejL;
		}
		else if (i == 3) {
			calcSpace = datetL;
		}
		else if (i == 4) {
			calcSpace = rateL;
		}
		else if (i == 5) {
			calcSpace = phoneL;
		}
		else if (i == 6) {
			calcSpace = addressL;
		}
		else if (i == 7) {
			calcSpace = tccodeL;
		}
		else if (i == 8) {
			calcSpace = tcnameL;
		}
		else if (i == 9) {
			calcSpace = subjectL;
		}
		else if (i == 10) {
			calcSpace = ratingL;
		}

		// performing calculation
		if ((calcSpace + 2) > tempSpaceT) {
			assignSpace = (calcSpace + 2);
		}
		else if ((calcSpace + 2) < tempSpaceT) {
			assignSpace = tempSpaceT;
		}
		else {
			assignSpace = (calcSpace + 2);
		}

		// then, begin to insert the data inside the table
		std::cout << " ";
		std::cout << charTitles;
		assignSpace = ((assignSpace - 1) - dataSpace);
		for (int l = 0; l < assignSpace; l++) {
			std::cout << " ";
		}

		// reset charN, tempSpaceT, calcSpace, and assignSpace to 0 for further uses
		charN = 0;
		tempSpaceT = 0;
		calcSpace = 0;
		assignSpace = 0;
	}
	// put extra "|" at the end because normally it only start at the begining
	std::cout << "|" << std::endl;
}

void dataLine() {
	// during the construction of the table we will calculate the number of char of the title like "No.", "Artist", etc to compare with our upcoming data value length to determine the space
	// by default the table should be this "+--+"
										//  |  |
										// "+--+"
	// 2 space remain around the word in the cell to make it alligned
	// in order to properly allign the table we need to by first calculate every single char within the string, and take the largest number as base
	int charN = 0;
	int tempSpaceT = 0;
	int assignSpace = 0;
	int dataSpace = 0;
	int calcSpace = 0;

	std::string charTitles;

	if (totalChar() == false) {
		// begin to assign the value accordingly with spatial concern
		std::cout << " X ";
		// now begin to insert the data into the table accordingly //
		// begin to assign the value accordingly with spatial concern
		std::string tempData[11] = {"NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL"};
		std::string charData;
		for (int i = 0; i < arrayLength(tabletitle); i++) {
			std::cout << "|";

			// calculate the length of the data, then determine the space base on that
			// assign the value of the array to a variable
			charTitles = tabletitle[i];
			charData = tempData[i];

			// to calculate the length
			for (int j = 0; charTitles[j]; j++) {
				charN++;
			}
			// after obtained the length we will start to calculate the space of the cell
			tempSpaceT = (charN + 2);
			// reset charN to 0 so when calculating the length of the data can use this again
			charN = 0;

			// to calculate the length of the data
			for (int j = 0; charData[j]; j++) {
				charN++;
			}
			// after obtained the length we will start to calculate the space of the cell
			dataSpace = charN;
			charN = 0;

			// check if the length of the data is longer than its title or not
			// assigning the value into a common variable to perform latter calculation
			if (i == 0) {
				calcSpace = idL;
			}
			else if (i == 1) {
				calcSpace = nameL;
			}
			else if (i == 2) {
				calcSpace = datejL;
			}
			else if (i == 3) {
				calcSpace = datetL;
			}
			else if (i == 4) {
				calcSpace = rateL;
			}
			else if (i == 5) {
				calcSpace = phoneL;
			}
			else if (i == 6) {
				calcSpace = addressL;
			}
			else if (i == 7) {
				calcSpace = tccodeL;
			}
			else if (i == 8) {
				calcSpace = tcnameL;
			}
			else if (i == 9) {
				calcSpace = subjectL;
			}
			else if (i == 10) {
				calcSpace = ratingL;
			}

			// performing calculation
			if ((calcSpace + 2) > tempSpaceT) {
				assignSpace = (calcSpace + 2);
			}
			else if ((calcSpace + 2) < tempSpaceT) {
				assignSpace = tempSpaceT;
			}
			else {
				assignSpace = (calcSpace + 2);
			}

			// then, begin to insert the data inside the table
			std::cout << " ";
			std::cout << charData;
			assignSpace = ((assignSpace - 1) - dataSpace);
			for (int l = 0; l < assignSpace; l++) {
				std::cout << " ";
			}

			// reset charN, tempSpaceT, calcSpace, and assignSpace to 0 for further uses
			charN = 0;
			tempSpaceT = 0;
			calcSpace = 0;
			assignSpace = 0;
		}
		// put extra "|" at the end because normally it only start at the begining
		std::cout << "|" << std::endl;

		horizontalLine();
	}
	else {
		// if link list got value then :	
		// now begin to insert the data into the table accordingly //
		temp = head;
		std::string charData;
		
		while (temp != NULL) {
			int rating = 0;

			// "pointer" for pointing the head of the list //
			if (temp == head) {
				std::cout << " > ";
			}
			else {
				std::cout << "   ";
			}

			for (int i = 0; i < arrayLength(tabletitle); i++) {
				std::cout << "|";

				// calculate the length of the data, then determine the space base on that
				// assign the value of the array to a variable
				charTitles = tabletitle[i];

				// assigning the value specifically based on the data of the list
				// memory address/id
				if (i == 0) {
					if (temp != NULL) {
						//convert address into string
						std::ostringstream get_the_address;
						get_the_address << temp;
						charData = get_the_address.str();
					}
					else {
						charData = "NULL";
					}
				}
				// name
				else if (i == 1) {
					charData = temp->name;
				}
				// date joined
				else if (i == 2) {
					charData = temp->dateJ;
				}
				// date terminated
				else if (i == 3) {
					charData = temp->dateT;
				}
				// hourly rate
				else if (i == 4) {
					if (temp->hourlyrate != NULL) {
						//convert double into string
						std::ostringstream get_the_double;
						get_the_double << temp->hourlyrate;
						charData = get_the_double.str();
					}
					else {
						charData = "NULL";
					}
				}
				// phone
				else if (i == 5) {
					charData = temp->phone;
				}
				// address name
				else if (i == 6) {
					charData = temp->address;
				}
				// tuition center code
				else if (i == 7) {
					if (temp->tccode != NULL) {
						//convert int into string
						std::ostringstream get_the_int;
						get_the_int << temp->tccode;
						charData = get_the_int.str();
					}
					else {
						charData = "NULL";
					}
				}
				// tuition center name
				else if (i == 8) {
					charData = temp->tcname;
				}
				// subject
				else if (i == 9) {
					charData = temp->subject;
				}
				// rating
				else if (i == 10) {
					rating = temp->rating;

					if (rating != NULL) {
						charData = ratingdescription[(rating - 1)];
					}
					else {
						charData = "NULL";
					}
				}

				// to calculate the length
				for (int j = 0; charTitles[j]; j++) {
					charN++;
				}
				
				// after obtained the length we will start to calculate the space of the cell
				tempSpaceT = (charN + 2);
				// reset charN to 0 so when calculating the length of the data can use this again
				charN = 0;

				// check if the data is NULL or not (aka empty string since in std::string its impossible to assign NULL)
				// if its not then proceed to the normal procedure
				if (charData != " ") {
					// to calculate the length of the data
					for (int j = 0; charData[j]; j++) {
						charN++;
					}
				}
				// otherwise set the charData as NULL and set the charN as four character numbers
				else {
					charData = "NULL";
					charN = 4;
				}

				// after obtained the length we will start to calculate the space of the cell
				dataSpace = charN;
				charN = 0;

				// check if the length of the data is longer than its title or not
				// assigning the value into a common variable to perform latter calculation
				if (i == 0) {
					calcSpace = idL;
				}
				else if (i == 1) {
					calcSpace = nameL;
				}
				else if (i == 2) {
					calcSpace = datejL;
				}
				else if (i == 3) {
					calcSpace = datetL;
				}
				else if (i == 4) {
					calcSpace = rateL;
				}
				else if (i == 5) {
					calcSpace = phoneL;
				}
				else if (i == 6) {
					calcSpace = addressL;
				}
				else if (i == 7) {
					calcSpace = tccodeL;
				}
				else if (i == 8) {
					calcSpace = tcnameL;
				}
				else if (i == 9) {
					calcSpace = subjectL;
				}
				else if (i == 10) {
					calcSpace = ratingL;
				}

				// performing calculation
				if ((calcSpace + 2) > tempSpaceT) {
					assignSpace = (calcSpace + 2);
				}
				else if ((calcSpace + 2) < tempSpaceT) {
					assignSpace = tempSpaceT;
				} 
				else {
					assignSpace = (calcSpace + 2);
				}

				// then, begin to insert the data inside the table
				std::cout << " ";
				std::cout << charData;
				if (i == 10) {
					if (charData != "NULL") {
						std::cout << " (" << rating << " / 5" << ")";
						assignSpace = assignSpace - 8;
					}
				}
				assignSpace = ((assignSpace - 1) - dataSpace);
				for (int l = 0; l < assignSpace; l++) {
					std::cout << " ";
				}

				// reset charN, tempSpaceT, calcSpace, and assignSpace to 0 for further uses
				charN = 0;
				tempSpaceT = 0;
				calcSpace = 0;
				assignSpace = 0;
			}
			// put extra "|" at the end because normally it only start at the begining
			std::cout << "|" << std::endl;

			horizontalLine();
			temp = temp->next;
		}
	}
}

void reversedDataLine() {
	// during the construction of the table we will calculate the number of char of the title like "No.", "Artist", etc to compare with our upcoming data value length to determine the space
	// by default the table should be this "+--+"
										//  |  |
										// "+--+"
	// 2 space remain around the word in the cell to make it alligned
	// in order to properly allign the table we need to by first calculate every single char within the string, and take the largest number as base
	int charN = 0;
	int tempSpaceT = 0;
	int assignSpace = 0;
	int dataSpace = 0;
	int calcSpace = 0;
	int option = NULL;

	std::string charTitles;

	if (totalChar() == false) {
		std::cout << "System Notice: The list is currently empty, please insert something before try to arrange the table in reversed/descending order." << std::endl;
		displayOption();
		std::cout << "User Input: ";
		option = inputValidation(9);
		mainOption(option);
	}
	else {
		// if link list got value then :	
		// now begin to insert the data into the table accordingly //
		temp = tail;
		std::string charData;

		while (temp != NULL) {
			int rating = 0;

			// "pointer" for pointing the head of the list //
			if (temp == head) {
				std::cout << " > ";
			}
			else {
				std::cout << "   ";
			}

			for (int i = 0; i < arrayLength(tabletitle); i++) {
				std::cout << "|";

				// calculate the length of the data, then determine the space base on that
				// assign the value of the array to a variable
				charTitles = tabletitle[i];

				// assigning the value specifically based on the data of the list
				// memory address/id
				if (i == 0) {
					if (temp != NULL) {
						//convert address into string
						std::ostringstream get_the_address;
						get_the_address << temp;
						charData = get_the_address.str();
					}
					else {
						charData = "NULL";
					}
				}
				// name
				else if (i == 1) {
					charData = temp->name;
				}
				// date joined
				else if (i == 2) {
					charData = temp->dateJ;
				}
				// date terminated
				else if (i == 3) {
					charData = temp->dateT;
				}
				// hourly rate
				else if (i == 4) {
					if (temp->hourlyrate != NULL) {
						//convert double into string
						std::ostringstream get_the_double;
						get_the_double << temp->hourlyrate;
						charData = get_the_double.str();
					}
					else {
						charData = "NULL";
					}
				}
				// phone
				else if (i == 5) {
					charData = temp->phone;
				}
				// address name
				else if (i == 6) {
					charData = temp->address;
				}
				// tuition center code
				else if (i == 7) {
					if (temp->tccode != NULL) {
						//convert int into string
						std::ostringstream get_the_int;
						get_the_int << temp->tccode;
						charData = get_the_int.str();
					}
					else {
						charData = "NULL";
					}
				}
				// tuition center name
				else if (i == 8) {
					charData = temp->tcname;
				}
				// subject
				else if (i == 9) {
					charData = temp->subject;
				}
				// rating
				else if (i == 10) {
					rating = temp->rating;

					if (rating != NULL) {
						charData = ratingdescription[(rating - 1)];
					}
					else {
						charData = "NULL";
					}
				}

				// to calculate the length
				for (int j = 0; charTitles[j]; j++) {
					charN++;
				}

				// after obtained the length we will start to calculate the space of the cell
				tempSpaceT = (charN + 2);
				// reset charN to 0 so when calculating the length of the data can use this again
				charN = 0;

				// check if the data is NULL or not (aka empty string since in std::string its impossible to assign NULL)
				// if its not then proceed to the normal procedure
				if (charData != " ") {
					// to calculate the length of the data
					for (int j = 0; charData[j]; j++) {
						charN++;
					}
				}
				// otherwise set the charData as NULL and set the charN as four character numbers
				else {
					charData = "NULL";
					charN = 4;
				}

				// after obtained the length we will start to calculate the space of the cell
				dataSpace = charN;
				charN = 0;

				// check if the length of the data is longer than its title or not
				// assigning the value into a common variable to perform latter calculation
				if (i == 0) {
					calcSpace = idL;
				}
				else if (i == 1) {
					calcSpace = nameL;
				}
				else if (i == 2) {
					calcSpace = datejL;
				}
				else if (i == 3) {
					calcSpace = datetL;
				}
				else if (i == 4) {
					calcSpace = rateL;
				}
				else if (i == 5) {
					calcSpace = phoneL;
				}
				else if (i == 6) {
					calcSpace = addressL;
				}
				else if (i == 7) {
					calcSpace = tccodeL;
				}
				else if (i == 8) {
					calcSpace = tcnameL;
				}
				else if (i == 9) {
					calcSpace = subjectL;
				}
				else if (i == 10) {
					calcSpace = ratingL;
				}

				// performing calculation
				if ((calcSpace + 2) > tempSpaceT) {
					assignSpace = (calcSpace + 2);
				}
				else if ((calcSpace + 2) < tempSpaceT) {
					assignSpace = tempSpaceT;
				}
				else {
					assignSpace = (calcSpace + 2);
				}

				// then, begin to insert the data inside the table
				std::cout << " ";
				std::cout << charData;
				if (i == 10) {
					if (charData != "NULL") {
						std::cout << " (" << rating << " / 5" << ")";
						assignSpace = assignSpace - 8;
					}
				}
				assignSpace = ((assignSpace - 1) - dataSpace);
				for (int l = 0; l < assignSpace; l++) {
					std::cout << " ";
				}

				// reset charN, tempSpaceT, calcSpace, and assignSpace to 0 for further uses
				charN = 0;
				tempSpaceT = 0;
				calcSpace = 0;
				assignSpace = 0;
			}
			// put extra "|" at the end because normally it only start at the begining
			std::cout << "|" << std::endl;

			horizontalLine();
			temp = temp->prev;
		}
	}
}

void sortedDataLine() {
	// during the construction of the table we will calculate the number of char of the title like "No.", "Artist", etc to compare with our upcoming data value length to determine the space
	// by default the table should be this "+--+"
										//  |  |
										// "+--+"
	// 2 space remain around the word in the cell to make it alligned
	// in order to properly allign the table we need to by first calculate every single char within the string, and take the largest number as base
	int charN = 0;
	int tempSpaceT = 0;
	int assignSpace = 0;
	int dataSpace = 0;
	int calcSpace = 0;

	std::string charTitles;

	// if link list got value then :	
	// now begin to insert the data into the table accordingly //
	temp = sorthead;
	std::string charData;

	while (temp != NULL) {
		int rating = 0;

		// "pointer" for pointing the head of the list //
		if (temp == head) {
			std::cout << " > ";
		}
		else {
			std::cout << "   ";
		}

		for (int i = 0; i < arrayLength(tabletitle); i++) {
			std::cout << "|";

			// calculate the length of the data, then determine the space base on that
			// assign the value of the array to a variable
			charTitles = tabletitle[i];

			// assigning the value specifically based on the data of the list
			// memory address/id
			if (i == 0) {
				if (temp != NULL) {
					//convert address into string
					std::ostringstream get_the_address;
					get_the_address << temp;
					charData = get_the_address.str();
				}
				else {
					charData = "NULL";
				}
			}
			// name
			else if (i == 1) {
				charData = temp->name;
			}
			// date joined
			else if (i == 2) {
				charData = temp->dateJ;
			}
			// date terminated
			else if (i == 3) {
				charData = temp->dateT;
			}
			// hourly rate
			else if (i == 4) {
				if (temp->hourlyrate != NULL) {
					//convert double into string
					std::ostringstream get_the_double;
					get_the_double << temp->hourlyrate;
					charData = get_the_double.str();
				}
				else {
					charData = "NULL";
				}
			}
			// phone
			else if (i == 5) {
				charData = temp->phone;
			}
			// address name
			else if (i == 6) {
				charData = temp->address;
			}
			// tuition center code
			else if (i == 7) {
				if (temp->tccode != NULL) {
					//convert int into string
					std::ostringstream get_the_int;
					get_the_int << temp->tccode;
					charData = get_the_int.str();
				}
				else {
					charData = "NULL";
				}
			}
			// tuition center name
			else if (i == 8) {
				charData = temp->tcname;
			}
			// subject
			else if (i == 9) {
				charData = temp->subject;
			}
			// rating
			else if (i == 10) {
				rating = temp->rating;

				if (rating != NULL) {
					charData = ratingdescription[(rating - 1)];
				}
				else {
					charData = "NULL";
				}
			}

			// to calculate the length
			for (int j = 0; charTitles[j]; j++) {
				charN++;
			}
			// after obtained the length we will start to calculate the space of the cell
			tempSpaceT = (charN + 2);
			// reset charN to 0 so when calculating the length of the data can use this again
			charN = 0;

			// check if the data is NULL or not (aka empty string since in std::string its impossible to assign NULL)
			// if its not then proceed to the normal procedure
			if (charData != " ") {
				// to calculate the length of the data
				for (int j = 0; charData[j]; j++) {
					charN++;
				}
			}
			// otherwise set the charData as NULL and set the charN as four character numbers
			else {
				charData = "NULL";
				charN = 4;
			}

			// after obtained the length we will start to calculate the space of the cell
			dataSpace = charN;
			charN = 0;

			// check if the length of the data is longer than its title or not
			// assigning the value into a common variable to perform latter calculation
			if (i == 0) {
				calcSpace = idL;
			}
			else if (i == 1) {
				calcSpace = nameL;
			}
			else if (i == 2) {
				calcSpace = datejL;
			}
			else if (i == 3) {
				calcSpace = datetL;
			}
			else if (i == 4) {
				calcSpace = rateL;
			}
			else if (i == 5) {
				calcSpace = phoneL;
			}
			else if (i == 6) {
				calcSpace = addressL;
			}
			else if (i == 7) {
				calcSpace = tccodeL;
			}
			else if (i == 8) {
				calcSpace = tcnameL;
			}
			else if (i == 9) {
				calcSpace = subjectL;
			}
			else if (i == 10) {
				calcSpace = ratingL;
			}

			// performing calculation
			if ((calcSpace + 2) > tempSpaceT) {
				assignSpace = (calcSpace + 2);
			}
			else if ((calcSpace + 2) < tempSpaceT) {
				assignSpace = tempSpaceT;
			}
			else {
				assignSpace = (calcSpace + 2);
			}

			// then, begin to insert the data inside the table
			std::cout << " ";
			std::cout << charData;
			if (i == 10) {
				if (charData != "NULL") {
					std::cout << " (" << rating << " / 5" << ")";
					assignSpace = assignSpace - 8;
				}
			}
			assignSpace = ((assignSpace - 1) - dataSpace);
			for (int l = 0; l < assignSpace; l++) {
				std::cout << " ";
			}

			// reset charN, tempSpaceT, calcSpace, and assignSpace to 0 for further uses
			charN = 0;
			tempSpaceT = 0;
			calcSpace = 0;
			assignSpace = 0;
		}
		// put extra "|" at the end because normally it only start at the begining
		std::cout << "|" << std::endl;

		horizontalLine();
		temp = temp->next;
	}
}

void reportDataLine() {
	// during the construction of the table we will calculate the number of char of the title like "No.", "Artist", etc to compare with our upcoming data value length to determine the space
	// by default the table should be this "+--+"
										//  |  |
										// "+--+"
	// 2 space remain around the word in the cell to make it alligned
	// in order to properly allign the table we need to by first calculate every single char within the string, and take the largest number as base
	int charN = 0;
	int tempSpaceT = 0;
	int assignSpace = 0;
	int dataSpace = 0;
	int calcSpace = 0;

	std::string charTitles;

	// if link list got value then :	
	// now begin to insert the data into the table accordingly //
	temp = reporthead;
	std::string charData;

	while (temp != NULL) {
		int rating = 0;

		// "pointer" for pointing the head of the list //
		if (temp == head) {
			std::cout << " > ";
		}
		else {
			std::cout << "   ";
		}

		for (int i = 0; i < arrayLength(tabletitle); i++) {
			std::cout << "|";

			// calculate the length of the data, then determine the space base on that
			// assign the value of the array to a variable
			charTitles = tabletitle[i];

			// assigning the value specifically based on the data of the list
			// memory address/id
			if (i == 0) {
				if (temp != NULL) {
					//convert address into string
					std::ostringstream get_the_address;
					get_the_address << temp;
					charData = get_the_address.str();
				}
				else {
					charData = "NULL";
				}
			}
			// name
			else if (i == 1) {
				charData = temp->name;
			}
			// date joined
			else if (i == 2) {
				charData = temp->dateJ;
			}
			// date terminated
			else if (i == 3) {
				charData = temp->dateT;
			}
			// hourly rate
			else if (i == 4) {
				if (temp->hourlyrate != NULL) {
					//convert double into string
					std::ostringstream get_the_double;
					get_the_double << temp->hourlyrate;
					charData = get_the_double.str();
				}
				else {
					charData = "NULL";
				}
			}
			// phone
			else if (i == 5) {
				charData = temp->phone;
			}
			// address name
			else if (i == 6) {
				charData = temp->address;
			}
			// tuition center code
			else if (i == 7) {
				if (temp->tccode != NULL) {
					//convert int into string
					std::ostringstream get_the_int;
					get_the_int << temp->tccode;
					charData = get_the_int.str();
				}
				else {
					charData = "NULL";
				}
			}
			// tuition center name
			else if (i == 8) {
				charData = temp->tcname;
			}
			// subject
			else if (i == 9) {
				charData = temp->subject;
			}
			// rating
			else if (i == 10) {
				rating = temp->rating;

				if (rating != NULL) {
					charData = ratingdescription[(rating - 1)];
				}
				else {
					charData = "NULL";
				}
			}

			// to calculate the length
			for (int j = 0; charTitles[j]; j++) {
				charN++;
			}
			// after obtained the length we will start to calculate the space of the cell
			tempSpaceT = (charN + 2);
			// reset charN to 0 so when calculating the length of the data can use this again
			charN = 0;

			// check if the data is NULL or not (aka empty string since in std::string its impossible to assign NULL)
			// if its not then proceed to the normal procedure
			if (charData != " ") {
				// to calculate the length of the data
				for (int j = 0; charData[j]; j++) {
					charN++;
				}
			}
			// otherwise set the charData as NULL and set the charN as four character numbers
			else {
				charData = "NULL";
				charN = 4;
			}

			// after obtained the length we will start to calculate the space of the cell
			dataSpace = charN;
			charN = 0;

			// check if the length of the data is longer than its title or not
			// assigning the value into a common variable to perform latter calculation
			if (i == 0) {
				calcSpace = idL;
			}
			else if (i == 1) {
				calcSpace = nameL;
			}
			else if (i == 2) {
				calcSpace = datejL;
			}
			else if (i == 3) {
				calcSpace = datetL;
			}
			else if (i == 4) {
				calcSpace = rateL;
			}
			else if (i == 5) {
				calcSpace = phoneL;
			}
			else if (i == 6) {
				calcSpace = addressL;
			}
			else if (i == 7) {
				calcSpace = tccodeL;
			}
			else if (i == 8) {
				calcSpace = tcnameL;
			}
			else if (i == 9) {
				calcSpace = subjectL;
			}
			else if (i == 10) {
				calcSpace = ratingL;
			}

			// performing calculation
			if ((calcSpace + 2) > tempSpaceT) {
				assignSpace = (calcSpace + 2);
			}
			else if ((calcSpace + 2) < tempSpaceT) {
				assignSpace = tempSpaceT;
			}
			else {
				assignSpace = (calcSpace + 2);
			}

			// then, begin to insert the data inside the table
			std::cout << " ";
			std::cout << charData;
			if (i == 10) {
				if (charData != "NULL") {
					std::cout << " (" << rating << " / 5" << ")";
					assignSpace = assignSpace - 8;
				}
			}
			assignSpace = ((assignSpace - 1) - dataSpace);
			for (int l = 0; l < assignSpace; l++) {
				std::cout << " ";
			}

			// reset charN, tempSpaceT, calcSpace, and assignSpace to 0 for further uses
			charN = 0;
			tempSpaceT = 0;
			calcSpace = 0;
			assignSpace = 0;
		}
		// put extra "|" at the end because normally it only start at the begining
		std::cout << "|" << std::endl;

		horizontalLine();
		temp = temp->next;
	}
}

void displayTable() {
	if (totalChar() == false) {
		std::cout << "System Notice: The list is currently empty." << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}

	std::cout << "System Notice: Generating table, please wait a moment..." << std::endl;
	// sleep 5 seconds to improve the accuracy of the code
	std::this_thread::sleep_for(std::chrono::milliseconds(2500));

	// begin the design of the table //
	// titles //
	horizontalLine();
	titleLine();
	horizontalLine();

	// values //
	dataLine();
}

void displayReverseTable() {
	int option = NULL;

	if (totalChar() == false) {
		std::cout << "System Notice: The list is currently empty, please insert something before try to arrange the table in reversed/descending order." << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		std::cout << std::endl;
		displayOption();
		std::cout << "User Input: ";
		option = inputValidation(9);
		mainOption(option);
	}
	else {
		std::cout << "System Notice: Generating reversed table, please wait a moment..." << std::endl;
		// sleep 5 seconds to improve the accuracy of the code
		std::this_thread::sleep_for(std::chrono::milliseconds(2500));

		// begin the design of the table //
		// titles //
		horizontalLine();
		titleLine();
		horizontalLine();

		// values //
		reversedDataLine();
	}
}

void displaySortedTable() {
	int option = NULL;

	std::cout << "System Notice: Checking... " << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	
	if (sorthead != NULL) {
		std::cout << "System Notice: Sorted List found! " << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		std::cout << "System Notice: Generating sorted list, please wait a moment..." << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));

		// begin the design of the table //
		// titles //
		horizontalLine();
		titleLine();
		horizontalLine();

		// values //
		sortedDataLine();

	}
	// if theres still no Sorted List yet, ask the user whether he wants to generate now or not
	else {
		int truefalse = NULL;
		int sortoption = NULL;
		int sortorder = NULL;

		std::cout << "System Notice: Sort List is still not made yet, do you want to make a Sort List now? " << std::endl;
		displayAction(truefalseoption, 2);
		std::cout << "User Input: ";

		truefalse = inputValidation(2);

		switch (truefalse) {
		case 1:
			std::cout << "System Notice: You've chosen Option " << truefalse << ": Generate a Sorted List. " << std::endl;
			std::cout << "System Notice: Which type of data you want the table to be sort on?" << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
			displayAction(optionsort, 4);
			std::cout << "User Input: ";

			sortoption = inputValidation(4);

			std::cout << "System Notice: You've chosen Option " << sortoption << ": " << arrayOption(optionsort, sortoption) << std::endl;
			std::cout << "System Notice: In what order? " << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
			displayAction(ascdescoption, 2);
			std::cout << "User Input: ";

			sortorder = inputValidation(2);

			std::cout << "System Notice: You've chosen Option " << sortorder << ": " << arrayOption(ascdescoption, sortorder) << std::endl;
			std::cout << "System Notice: Generating sorted list, please wait a moment..." << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			sortData(sortoption, sortorder);
				
			break;

		case 2:
			std::cout << "System Notice: You've chosen Option " << truefalse << ": Not to generate a Sorted List. " << std::endl;
			std::cout << "System Notice: Returning to main menu now..." << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			displayOption();
			std::cout << "User Input: ";
			option = inputValidation(9);
			mainOption(option);

			break;
		}
	}
}

void displayReportTable() {
	std::cout << "System Notice: Checking... " << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));

	// check if the report head is empty or not, if not we will delete first to maintain accuracy of the report
	if (reporthead != NULL) {
		std::cout << "System Notice: Existing Report List found, deleting the old report data to maintain accuracy..." << std::endl;

		deleteAll(reporthead);
		reporthead = NULL;

		std::cout << "System Notice: Now generating a new Report List... " << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		generateReport();
		if (reporthead != NULL) {
			std::cout << "System Notice: New report generated. " << std::endl;
		}
	}

	if (reporthead != NULL) {
		std::cout << "System Notice: Report List found! " << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		std::cout << "System Notice: Generating report, please wait a moment..." << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));

		// begin the design of the table //
		// titles //
		horizontalLine();
		titleLine();
		horizontalLine();

		// values //
		reportDataLine();
	}
	// if theres still no Report List yet, generate the report now
	else {
		std::cout << "System Notice: Report list not found, now generating a report list... " << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		generateReport();
		if (reporthead != NULL) {
			std::cout << "System Notice: Report generated, now reloading the Report Table function... " << std::endl;
			std::cout << "System Notice: Report List found! " << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			std::cout << "System Notice: Generating report, please wait a moment..." << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));

			// begin the design of the table //
			// titles //
			horizontalLine();
			titleLine();
			horizontalLine();

			// values //
			reportDataLine();
		}	
	}
}

void displayRow(tms* address) {
	temp = head;
	int rating = 0;

	while (temp->id != address) {
		temp = temp->next;
	}

	// if temp becomes NULL, means there are no existing address
	if (temp == NULL) {
		std::cout << "System Notice: There are no existing address within the table, please try again." << std::endl;
	}
	// if found the existing data, then start to call it out specifically
	else if (temp->id == address) {
		int charN = 0;
		int tempSpaceT = 0;
		int assignSpace = 0;
		int dataSpace = 0;
		int calcSpace = 0;

		std::string charTitles;
		std::string charData;

		// "pointer" for pointing the head of the list //
		if (temp == head) {
			std::cout << " > ";
		}
		else {
			std::cout << "   ";
		}

		for (int i = 0; i < arrayLength(tabletitle); i++) {
			std::cout << "|";

			// calculate the length of the data, then determine the space base on that
			// assign the value of the array to a variable
			charTitles = tabletitle[i];

			// assigning the value specifically based on the data of the list
			// memory address/id
			if (i == 0) {
				if (temp != NULL) {
					//convert address into string
					std::ostringstream get_the_address;
					get_the_address << temp;
					charData = get_the_address.str();
				}
				else {
					charData = "NULL";
				}
			}
			// name
			else if (i == 1) {
				charData = temp->name;
			}
			// date joined
			else if (i == 2) {
				charData = temp->dateJ;
			}
			// date terminated
			else if (i == 3) {
				charData = temp->dateT;
			}
			// hourly rate
			else if (i == 4) {
				if (temp->hourlyrate != NULL) {
					//convert double into string
					std::ostringstream get_the_double;
					get_the_double << temp->hourlyrate;
					charData = get_the_double.str();
				}
				else {
					charData = "NULL";
				}
			}
			// phone
			else if (i == 5) {
				charData = temp->phone;
			}
			// address name
			else if (i == 6) {
				charData = temp->address;
			}
			// tuition center code
			else if (i == 7) {
				if (temp->tccode != NULL) {
					//convert int into string
					std::ostringstream get_the_int;
					get_the_int << temp->tccode;
					charData = get_the_int.str();
				}
				else {
					charData = "NULL";
				}
			}
			// tuition center name
			else if (i == 8) {
				charData = temp->tcname;
			}
			// subject
			else if (i == 9) {
				charData = temp->subject;
			}
			// rating
			else if (i == 10) {
				rating = temp->rating;

				if (rating != NULL) {
					charData = ratingdescription[(rating - 1)];
				}
				else {
					charData = "NULL";
				}
			}

			// to calculate the length
			for (int j = 0; charTitles[j]; j++) {
				charN++;
			}
			// after obtained the length we will start to calculate the space of the cell
			tempSpaceT = (charN + 2);
			// reset charN to 0 so when calculating the length of the data can use this again
			charN = 0;

			// check if the data is NULL or not (aka empty string since in std::string its impossible to assign NULL)
			// if its not then proceed to the normal procedure
			if (charData != " ") {
				// to calculate the length of the data
				for (int j = 0; charData[j]; j++) {
					charN++;
				}
			}
			// otherwise set the charData as NULL and set the charN as four character numbers
			else {
				charData = "NULL";
				charN = 4;
			}

			// after obtained the length we will start to calculate the space of the cell
			dataSpace = charN;
			charN = 0;

			// check if the length of the data is longer than its title or not
			// assigning the value into a common variable to perform latter calculation
			if (i == 0) {
				calcSpace = idL;
			}
			else if (i == 1) {
				calcSpace = nameL;
			}
			else if (i == 2) {
				calcSpace = datejL;
			}
			else if (i == 3) {
				calcSpace = datetL;
			}
			else if (i == 4) {
				calcSpace = rateL;
			}
			else if (i == 5) {
				calcSpace = phoneL;
			}
			else if (i == 6) {
				calcSpace = addressL;
			}
			else if (i == 7) {
				calcSpace = tccodeL;
			}
			else if (i == 8) {
				calcSpace = tcnameL;
			}
			else if (i == 9) {
				calcSpace = subjectL;
			}
			else if (i == 10) {
				calcSpace = ratingL;
			}

			// performing calculation
			if ((calcSpace + 2) > tempSpaceT) {
				assignSpace = (calcSpace + 2);
			}
			else if ((calcSpace + 2) < tempSpaceT) {
				assignSpace = tempSpaceT;
			} 
			else {
				assignSpace = (calcSpace + 2);
			}

			// then, begin to insert the data inside the table
			std::cout << " ";
			std::cout << charData;
			if (i == 10) {
				if (charData != "NULL") {
					std::cout << " (" << rating << " / 5" << ")";
					assignSpace = assignSpace - 8;
				}
			}
			assignSpace = ((assignSpace - 1) - dataSpace);
			for (int l = 0; l < assignSpace; l++) {
				std::cout << " ";
			}

			// reset charN, tempSpaceT, calcSpace, and assignSpace to 0 for further uses
			charN = 0;
			tempSpaceT = 0;
			calcSpace = 0;
			assignSpace = 0;
		}
		// put extra "|" at the end because normally it only start at the begining
		std::cout << "|" << std::endl;

		horizontalLine();
	}
}

void displayOption() {
	std::cout << "   " << "Choose the option that you want to perform: " << std::endl;
	displayAction(optionsmain, 9);
}

void displayAction(std::string* arr, int arrlength) {
	int row = 0;
	int collumn = 0;
	int charN = 0;
	int dataSpace = 0;
	int assignSpace = 0;
	int tempN = 0;
	int holdN = 0;
	int cycle = 0;
	std::string dataTemp;

	// check the char number within each array to assign space
	for (int i = 0; i < arrlength; i++) {
		// begin the calculation of the array
		// start to count the longest of char num within the array, and set as a base
		dataTemp = arr[i];

		// to calculate the length
		for (int j = 0; dataTemp[j]; j++) {
			charN++;
		}
		tempN = (charN + 5);
		dataSpace = charN;

		// reset to 0 for future uses
		charN = 0;

		if (tempN > holdN) {
			holdN = tempN;
		}
	}

	// then once we decide the largest num of char within the arrays, we will start to determine how many rows or collumns there are
	// if its divide-able by 4, and the answer is more than 1 then assign it into variable for future uses
	if (((arrlength % 4) == 0) && ((arrlength / 4) > 1)) {
		collumn = 4;
		row = (arrlength / 4);
	}
	else if (((arrlength % 2) == 0) && ((arrlength / 2) > 0)) {
		collumn = 2;
		row = (arrlength / 2);
	}
	// if over 10 then set it 5 per line
	else if (arrlength >= 10) {
		collumn = 5;
	}
	// which mostly means there is only one option
	else {
		// set the minimum as 3 for prevention
		collumn = 3;
	}

	// begin to assign space accordingly by the format of the table
	for (int i = 0; i < arrlength; i++) {
		if ((cycle == 0) || (cycle == collumn)) {
			if (cycle == collumn) {
				std::cout << std::endl;
				cycle = 0;
			}
			std::cout << "   ";
		}

		if (i < 9) {
			std::cout << "0" << (i + 1) << ". " << arr[i];
		}
		else if (i >= 9) {
			std::cout << (i + 1) << ". " << arr[i];
		}
			

		// start to count the num of char within the array to allign the space later
		dataTemp = arr[i];

		// to calculate the length
		for (int j = 0; dataTemp[j]; j++) {
			charN++;
		}
		dataSpace = charN;
		assignSpace = ((holdN - 4) - dataSpace);
		for (int k = 0; k < assignSpace; k++) {
			std::cout << " ";
		}
		// putting 16 spaces instead of two \t because of the inconsistencies
		std::cout << "                ";

		// reset to 0 for future uses
		charN = 0;

		cycle++;
	}
	std::cout << std::endl;
}

void verifyrole() {
	std::string rolename;
	int rolen = NULL;

	std::cout << "System Notice: Please identify your role." << std::endl;
	std::cout << "1. HR" << std::endl << "2. Admin" << std::endl;
	std::cout << "User Input: ";

	rolen = inputValidation(2);

	if (rolen == 1) {
		rolename = "HR";
		assignrole(rolen);
	}
	else if (rolen == 2) {
		rolename = "Admin";
		assignrole(rolen);
	}
	else {
		rolename = "ERROR";
		exit;
	}

	if (rolen != NULL) {
		std::cout << "System Notice: Role identified, welcome back " << rolename << "." << std::endl;
	}
}

tms* createnewnode(std::string name, std::string datej, std::string datet, double hourlyrate, std::string phone, std::string address, int tccode, std::string tcname, std::string subject, int rating) {
	// create an empty structure
	tms* createnewnode = new tms;

	createnewnode->id = createnewnode;
	createnewnode->name = name;
	createnewnode->dateJ = datej;
	createnewnode->dateT = datet;
	createnewnode->hourlyrate = hourlyrate;
	createnewnode->phone = phone;
	createnewnode->address = address;
	createnewnode->tccode = tccode;
	createnewnode->tcname = tcname;
	createnewnode->subject = subject;
	createnewnode->rating = rating;
	createnewnode->next = NULL;

	createnewnode->prev = NULL;

	return createnewnode;
}

int totalNodes() {
	int n = 0;
	temp = head;

	while(temp != NULL) {
		temp = temp->next;
		n++;
	}

	return n;
}

void insertLast(std::string name, std::string datej, std::string datet, double hourlyrate, std::string phone, std::string address, int tccode, std::string tcname, std::string subject, int rating) {
	tms* newnode = createnewnode(name, datej, datet, hourlyrate, phone, address, tccode, tcname, subject, rating);

	if (head == NULL) {
		head = newnode;
		tail = newnode;
	}
	else {
		temp = head;

		while (temp->next != NULL) {
			temp = temp->next;
		}
		// once we found the last address, assign the address accordingly
		newnode->prev = temp;
		temp->next = newnode;
		tail = newnode;
	}

	// "refresh" the global variable to maintain accuracy of the data
	totalChar();
}

void insertSort(std::string name, std::string datej, std::string datet, double hourlyrate, std::string phone, std::string address, int tccode, std::string tcname, std::string subject, int rating) {
	// sort based on rating
	tms* newnode = createnewnode(name, datej, datet, hourlyrate, phone, address, tccode, tcname, subject, rating);

	// situation 1: check list empty or not
	if (head == NULL) {
		head = tail = newnode;
	}
	// situation 2: if list is not empty but value smaller than first value
	// use insert into beginning function
	else if (newnode->rating <= head->rating) {
		newnode->next = head;
		newnode->prev = head->prev;
		head->prev = newnode;
		head = newnode;
	}
	// situation 3: list if not empty but bigger than the first value
	else {
		temp = head;
		while (temp->next != NULL) {
			if (newnode->rating <= temp->next->rating) {
				break;
			}
			temp = temp->next;
		}
		if (temp->next == NULL) {
			tail = newnode;
		}
		else {
			newnode->next = temp->next;
		}
		newnode->prev = temp;
		temp->next = newnode;
	}

	// "refresh" the global variable to maintain accuracy of the data
	totalChar();
}

void sortedlistID(int order) {
	if (sorthead != NULL) {
		deleteAll(sorthead);
		sorthead = NULL;
		sorttail = NULL;
	}
	sorttemp = sorthead;

	if (order == 1) {
		temp = head;

		// by default the ID already in an order so we just make sorthead have the head of the list
		while (temp != NULL) {
			tms* newnode = createnewnode(temp->name, temp->dateJ, temp->dateT, temp->hourlyrate, temp->phone, temp->address, temp->tccode, temp->tcname, temp->subject, temp->rating);

			// if its inserting the first value into the list, define both prev and next as NULL
			if (sorttemp == NULL) {
				sorttemp = newnode;
				sorthead = newnode;
				sorttemp->prev = NULL;
				sorttemp->next = NULL;
			}
			// if its inserting the common value into the list, define both prev and next in the usual way
			else {
				holdtemp = sorttemp;

				sorttemp->next = newnode;
				sorttemp = newnode;
				sorttemp->prev = holdtemp;
				sorttemp->next = NULL;
			}

			sorttail = newnode;
			temp = temp->next;
		}
	}
	else if (order == 2) {
		temp = tail;

		// if its descending order then we need to explicitly insert with an algo
		while (temp != NULL) {
			tms* newnode = createnewnode(temp->name, temp->dateJ, temp->dateT, temp->hourlyrate, temp->phone, temp->address, temp->tccode, temp->tcname, temp->subject, temp->rating);

			// if its inserting the first value into the list, define both prev and next as NULL
			if (sorttemp == NULL) {
				sorttemp = newnode;
				sorthead = newnode;
				sorttemp->prev = NULL;
				sorttemp->next = NULL;
				sorttail = newnode;
			}
			// if its inserting the common value into the list, define both prev and next in the usual way
			else {
				holdtemp = sorttemp;

				sorttemp->next = newnode;
				sorttemp = newnode;
				sorttemp->prev = holdtemp;
				sorttemp->next = NULL;
			}

			sorttail = newnode;
			temp = temp->prev;
		}
	}
}

void sortedlistLocation(int order) {
	std::string location;
	std::string holdSTR;
	int n = 0;
	int found = 0;
	if (sorthead != NULL) {
		deleteAll(sorthead);
		sorthead = NULL;
		sorttail = NULL;
	}

	// first make the sort list only appear a certain location
	std::cout << "System Notice: Which location do you want to sort on?" << std::endl;
	std::cout << "User Input: ";
	// get the input along together with white space
	std::getline(std::cin >> std::ws, location);
	std::transform(location.begin(), location.end(), location.begin(), ::toupper);
	
	std::cout << "System Notice: Checking..." << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(500));

	holdtemp = head;

	// time to search and sort into the sort list accordingly
	while (found < 1) {
		while (n != totalNodes()) {
			while (holdtemp != NULL) {
				holdSTR = holdtemp->address;
				std::transform(holdSTR.begin(), holdSTR.end(), holdSTR.begin(), ::toupper);

				if (holdSTR == location) {
					found++;
					// if found the related location value then start to insert into sorted list
					tms* newnode = createnewnode(holdtemp->name, holdtemp->dateJ, holdtemp->dateT, holdtemp->hourlyrate, holdtemp->phone, holdtemp->address, holdtemp->tccode, holdtemp->tcname, holdtemp->subject, holdtemp->rating);

					sorttemp = holdhead;
					// if its inserting the first value into the list, define both prev and next as NULL
					if (sorttemp == NULL) {
						sorttemp = newnode;
						sorttemp->prev = NULL;
						sorttemp->next = NULL;
						holdhead = newnode;
						holdtail = newnode;
					}
					// if its inserting the common value into the list, define both prev and next in the usual way, insert at the back
					else {
						newnode->prev = sorttemp;
						newnode->next = sorttemp->next;
						sorttemp->next = newnode;
						holdtail = newnode;
					}
				}

				holdtemp = holdtemp->next;
				n++;
			}
		}

		if (found < 1) {
			std::cout << "System Notice: Location not found within the list, please try again." << std::endl;
			std::cout << "User Input: ";
			holdtemp = head;
			n = 0;

			// get the input along together with white space
			std::getline(std::cin >> std::ws, location);
			std::transform(location.begin(), location.end(), location.begin(), ::toupper);
			
			std::cout << "System Notice: Checking..." << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
		}
		else {
			std::cout << "System Notice: Found total of " << found << " similar results within the list." << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
			std::cout << "System Notice: Arranging in " << arrayOption(ascdescoption, order) << " based on rating now..." << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
			sortedlistRating(order, holdhead);
		}
	}

}

void sortedlistRating(int order, tms* listtype) {
	// before that we will delete everything in the sorted list, then only assign into it
	if (sorthead != NULL) {
		deleteAll(sorthead);
		sorthead = NULL;
		sorttail = NULL;
		holdhead = NULL;
		holdtail = NULL;
	}
	// using holdtemp to temporary hold the new sorted list
	holdhead = NULL;
	holdtemp = holdhead;
	sorttemp = listtype;

	// use the sorting algorithm to make the sorting order of the rating
	while (sorttemp != NULL) {
		tms* newnode = createnewnode(sorttemp->name, sorttemp->dateJ, sorttemp->dateT, sorttemp->hourlyrate, sorttemp->phone, sorttemp->address, sorttemp->tccode, sorttemp->tcname, sorttemp->subject, sorttemp->rating);

		// ascending order
		if (order == 1) {
			if (holdtemp == NULL) {
				holdtemp = holdhead = holdtail = newnode;
			}
			//insert at the beginning
			else if (newnode->rating <= holdtemp->rating) { 
				newnode->next = holdtemp;
				holdtemp->prev = newnode;
				holdtemp = newnode;

				holdhead = newnode;
			}
			//insert at the end
			else {
				tms* newtemp = holdtemp;

				while (newtemp->next != NULL) {
					if (newnode->rating <= newtemp->next->rating) {
						break;
					}
					newtemp = newtemp->next;
				}
				newnode->next = newtemp->next;
				newnode->prev = newtemp;

				if (newtemp->next != NULL) {
					newtemp->next->prev = newnode;
				}
				else {
					holdtail = newnode;
				}
				newtemp->next = newnode;
			}
		}
		else if (order == 2) {
			if (holdtemp == NULL) {
				holdtemp = holdhead = holdtail = newnode;
			}
			//insert at the end
			else if (newnode->rating <= holdtemp->rating) {
				tms* newtemp = holdtemp;

				while (newtemp->next != NULL) {
					if (newnode->rating >= newtemp->next->rating) {
						break;
					}
					newtemp = newtemp->next;
				}
				newnode->next = newtemp->next;
				newnode->prev = newtemp;

				if (newtemp->next != NULL) {
					newtemp->next->prev = newnode;
				}
				else {
					holdtail = newnode;
				}
				newtemp->next = newnode;
			}
			//insert at the beginning
			else {
				newnode->next = holdtemp;
				holdtemp->prev = newnode;
				holdtemp = newnode;

				holdhead = newnode;
			}
		}
		sorttemp = sorttemp->next;
	}

	// assign holdhead into sorthead; holdtail into sorttail
	sorthead = holdhead;
	sorttail = holdtail;
}

void sortedlistHourly(int order) {
	// before that we will delete everything in the sorted list, then only assign into it
	if (sorthead != NULL) {
		deleteAll(sorthead);
		sorthead = NULL;
		sorttail = NULL;
		holdhead = NULL;
		holdtail = NULL;
	}
	// using holdtemp to temporary hold the new sorted list
	sorthead = NULL;
	holdtemp = sorthead;
	sorttemp = head;

	// use the sorting algorithm to make the sorting order of the rating
	while (sorttemp != NULL) {
		tms* newnode = createnewnode(sorttemp->name, sorttemp->dateJ, sorttemp->dateT, sorttemp->hourlyrate, sorttemp->phone, sorttemp->address, sorttemp->tccode, sorttemp->tcname, sorttemp->subject, sorttemp->rating);

		// ascending order
		if (order == 1) {
			if (holdtemp == NULL) {
				sorthead = newnode;
				sorttail = newnode;
				holdtemp = newnode;
			}
			//insert at the beginning
			else if (newnode->hourlyrate <= holdtemp->hourlyrate) {
				newnode->next = holdtemp;
				holdtemp->prev = newnode;
				holdtemp = newnode;

				sorthead = newnode;
			}
			//insert at the end
			else {
				tms* newtemp = holdtemp;

				while (newtemp->next != NULL) {
					if (newnode->hourlyrate <= newtemp->next->hourlyrate) {
						break;
					}
					newtemp = newtemp->next;
				}
				newnode->next = newtemp->next;
				newnode->prev = newtemp;

				if (newtemp->next != NULL) {
					newtemp->next->prev = newnode;
				}
				else {
					sorttail = newnode;
				}
				newtemp->next = newnode;
			}
		}
		else if (order == 2) {
			if (holdtemp == NULL) {
				sorthead = newnode;
				sorttail = newnode;
				holdtemp = newnode;
			}
			//insert at the end
			else if (newnode->hourlyrate <= holdtemp->hourlyrate) {
				tms* newtemp = holdtemp;

				while (newtemp->next != NULL) {
					if (newnode->hourlyrate >= newtemp->next->hourlyrate) {
						break;
					}
					newtemp = newtemp->next;
				}
				newnode->next = newtemp->next;
				newnode->prev = newtemp;

				if (newtemp->next != NULL) {
					newtemp->next->prev = newnode;
				}
				else {
					sorttail = newnode;
				}
				newtemp->next = newnode;
			}
			//insert at the beginning
			else {
				newnode->next = holdtemp;
				holdtemp->prev = newnode;
				holdtemp = newnode;

				sorthead = newnode;
			}
		}
		sorttemp = sorttemp->next;
	}
}

bool searchRow(int type, std::string value) {
	tms* resultaddress = NULL;
	holdtemp = head;
	int found = 0;
	int character = NULL;

	std::string data;
	std::string stringinput;
	double dbldata;
	double dblinput;
	int intdata;
	int intinput;
	std::ostringstream conversion;

	while (holdtemp != NULL) {
		switch (type) {
		case 1:
			// convert address into string
			conversion << holdtemp->id;
			data = conversion.str();

			break;
		case 2:
			data = holdtemp->name;

			break;
		case 3:
			data = holdtemp->dateJ;

			break;
		case 4:
			data = holdtemp->dateT;

			break;
		case 5:
			// double
			dbldata = holdtemp->hourlyrate;

			break;
		case 6:
			data = holdtemp->phone;

			break;
		case 7:
			data = holdtemp->address;

			break;
		case 8:
			// int
			intdata = holdtemp->tccode;

			break;
		case 9:
			data = holdtemp->tcname;

			break;
		case 10:
			data = holdtemp->subject;

			break;
		case 11:
			// int
			intdata = holdtemp->rating;

			break;
		}

		// if the data is equal with the search value, then return the address, else return NULL
		if ((type == 8) || (type == 11)) {
			// for int data
			// check the input is NULL or not
			character = spaceValidate(value);
			if (character == 0) {
				resultaddress = NULL;
			}
			else {
				// check the input is valid or not
				character = intValidate(value);

				// if its valid then we start to convert and compare
				if (character == 0) {
					// convert the input string to int, and compare
					intinput = stoi(value);
					if (intdata == intinput) {
						resultaddress = holdtemp;
						found++;
					}
					else {
						resultaddress = NULL;
					}
				}
				else {
					resultaddress = NULL;
				}
			}
		}
		else if (type == 5) {
			// for double data
			// check the input is NULL or not
			character = spaceValidate(value);
			if (character == 0) {
				resultaddress = NULL;
			}
			else {
				// check the input is valid or not
				character = doubleValidate(value);

				// if its valid then we start to convert and compare
				if (character == 0) {
					// convert the input string to double, and compare
					dblinput = stod(value);
					if (dbldata == dblinput) {
						resultaddress = holdtemp;
						found++;
					}
					else {
						resultaddress = NULL;
					}
				}
				else {
					resultaddress = NULL;
				}
			}
		}
		else if (type == 1) {
			// for string data: address
			stringinput = value;

			if (data == stringinput) {
				resultaddress = holdtemp;
				found++;
			}
			else {
				resultaddress = NULL;
			}
		}
		else {
			// for string data
			stringinput = value;

			// capitalize the strings for search convenience
			transform(data.begin(), data.end(), data.begin(), ::toupper);
			transform(stringinput.begin(), stringinput.end(), stringinput.begin(), ::toupper);

			if (data == stringinput) {
				resultaddress = holdtemp;
				found++;
			}
			else {
				resultaddress = NULL;
			}
		}

		// if found the result and the address is not null, procees to call it out
		if ((found > 0) && (resultaddress != NULL)) {
			if (found == 1) {
				// if its the first value we found then we call it out along with the table titles
				std::cout << "System Notice: Search record exist, generating table now..." << std::endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));

				// begin the design of the table //
				// titles //
				horizontalLine();
				titleLine();
				horizontalLine();
			}

			displayRow(resultaddress);
		}

		holdtemp = holdtemp->next;

		conversion.str("");
		conversion.clear();
	}

	// to inform the search result have found none
	if (found < 1) {
		return false;
	}
	else if (found > 0) {
		return true;
	}

	// reset holdtemp to NULL
	holdtemp = NULL;
}

void mainOption(int option) {
	int optionchosen = NULL;
	int order = NULL;
	int optionmain = NULL;

	// now determine data that will be used to sort and insert into the main menu option list function
	switch (option) {
	case 1:
		// insertion
		if (role == 1) {
			std::cout << "   " << "Choose the insertion option that you want to perform: " << std::endl;
			displayAction(optionsinsert, 3);
			std::cout << "User Input: ";
			optionchosen = inputValidation(3);
			insertOption(optionchosen);
		}
		else {
			std::cout << "System Notice: Your role is not authorized to perform insertion, returning to main menu now..." << std::endl;
			displayTable();
			displayOption();
			std::cout << "User Input: ";
			optionmain = inputValidation(9);
			mainOption(optionmain);
		}

		break;
	case 2:
		// displaying types of table
		if (head != NULL) {
			std::cout << "   " << "Choose the table types that you want to display: " << std::endl;
			displayAction(optiondisplay, 3);
			std::cout << "User Input: ";
			optionchosen = inputValidation(3);
			displayTBLOption(optionchosen);
		}
		else {
			std::cout << "System Notice: List is still empty, returning to main menu now... " << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(300));
			displayTable();
			displayOption();
			std::cout << "User Input: ";
			optionmain = inputValidation(9);
			mainOption(optionmain);
		}

		break;
	case 3:
		// search
		if (head != NULL) {
			std::cout << "   " << "Choose the search option available to perform your search function: " << std::endl;
			displayAction(optionsearch, 2);
			std::cout << "User Input: ";
			optionchosen = inputValidation(2);
			searchOption(optionchosen);
		}
		else {
			std::cout << "System Notice: List is still empty, returning to main menu now... " << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(300));
			displayTable();
			displayOption();
			std::cout << "User Input: ";
			optionmain = inputValidation(9);
			mainOption(optionmain);
		}

		break;
	case 4:
		// sort
		if (head != NULL) {
			std::cout << "   " << "Choose the sorting option that you want to perform: " << std::endl;
			displayAction(optionsort, 5);
			std::cout << "User Input: ";
			optionchosen = inputValidation(5);
			sortOption(optionchosen);
		}
		else {
			std::cout << "System Notice: List is still empty, returning to main menu now... " << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(300));
			displayTable();
			displayOption();
			std::cout << "User Input: ";
			optionmain = inputValidation(9);
			mainOption(optionmain);
		}

		break;
	case 5:
		// modify
		if (head != NULL) {
			if (role == 1) {
				std::cout << "   " << "Choose the modify option that you want to perform: " << std::endl;
				displayAction(optionmodify, 2);
				std::cout << "User Input: ";
				optionchosen = inputValidation(2);
				modifyOption(optionchosen);
			}
			else {
				std::cout << "System Notice: Your role is not authorized to perform modification, returning to main menu now..." << std::endl;
				displayTable();
				displayOption();
				std::cout << "User Input: ";
				optionmain = inputValidation(9);
				mainOption(optionmain);
			}
		}
		else {
			std::cout << "System Notice: List is still empty, returning to main menu now... " << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(300));
			displayTable();
			displayOption();
			std::cout << "User Input: ";
			optionmain = inputValidation(9);
			mainOption(optionmain);
		}

		break;
	case 6:
		// deletion
		if (head != NULL) {
			if (role == 1) {
				std::cout << "   " << "Choose the deletion option that you want to perform: " << std::endl;
				displayAction(optiondelete, 3);
				std::cout << "User Input: ";
				optionchosen = inputValidation(3);
				deleteOption(optionchosen);
			}
			else {
				std::cout << "System Notice: Your role is not authorized to perform deletion, returning to main menu now..." << std::endl;
				displayTable();
				displayOption();
				std::cout << "User Input: ";
				optionmain = inputValidation(9);
				mainOption(optionmain);
			}
		}
		else {
			std::cout << "System Notice: List is still empty, returning to main menu now... " << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(300));
			displayTable();
			displayOption();
			std::cout << "User Input: ";
			optionmain = inputValidation(9);
			mainOption(optionmain);
		}

		break;
	case 7:
		// reset
		if (role == 1) {
			std::cout << "System Notice: Do you wish to reset the table back to pre-determined data?" << std::endl;
			displayAction(truefalseoption, 2);
			std::cout << "User Input: ";
			optionchosen = inputValidation(2);
			if (optionchosen == 1) {
				std::this_thread::sleep_for(std::chrono::milliseconds(500));
				std::cout << "System Notice: Resetting now..." << std::endl;
				if (head != NULL) {
					deleteAll(head);
				}
				std::this_thread::sleep_for(std::chrono::milliseconds(500));
				std::cout << "System Notice: Data Deleted, now restoring default data..." << std::endl;
				// pre-determined codes
				insertLast("BEN LOO", "2020/01/30", " ", 50.28, "0104558888", "Johor Bahru", 51000, "Pusat Ben", "Financial", 4);
				insertLast("OOI JOE SHERN", "2010/04/30", " ", 60.8, "0104583800", "Bukit Jalil", 52100, "Pusat Tuition", "Philosophy", 3);
				insertLast("LIM YE HAN", "2016/03/20", " ", 70.1, "0104558999", "Bukit Jalil", 32000, "Pusat Lee", "Gaming", 2);
				insertLast("OH SZE HONG", "2018/05/30", "2019/05/30", 57.2, "0124567888", "Klang", 18900, "Pusat Berjaya", "Memes", 1);
				insertSort("LIM QING YUAN", "2012/12/31", "2013/01/30", 53.98, "0124967988", "Johor Bahru", 11777, "Pusat Lim", "Financial", 5);
				insertLast("TING FENG YUAN", "2015/08/30", "2016/01/30", 56.28, "0104578988", "Klang", 51300, "Pusat Ting", "Memes", 3);
				insertLast("TAN JIE SHEN", "2009/04/30", "2013/03/30", 70.8, "0134583800", "Johor Bahru", 32100, "Pusat Tan", "Gaming", 2);
				insertLast("TAN JIE HUI", "2009/04/30", "2010/03/30", 50.1, "0106558999", "Johor Bahru", 31000, "Pusat Secret", "Gaming", 4);
				insertLast("BILL GATES", "2007/02/10", " ", 79.99, "0103567888", "KL", 18880, "Pusat Rich", "Financial", 5);
				insertSort("DONALD TRUMP", "2016/08/10", " ", 50.98, "0124117988", "Klang", 12337, "Pusat Trump", "Financial", 1);

				std::this_thread::sleep_for(std::chrono::milliseconds(500));
				std::cout << "System Notice: Data Reset-ed, returning to main menu now..." << std::endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(500));
				displayTable();
				displayOption();
				std::cout << "User Input: ";
				optionmain = inputValidation(9);
				mainOption(optionmain);
			}
			else if (optionchosen == 2) {
				std::cout << "System Notice: You have choose not to reset the table, returning to main menu now..." << std::endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(500));
				displayTable();
				displayOption();
				std::cout << "User Input: ";
				optionmain = inputValidation(9);
				mainOption(optionmain);
			}
		}
		else {
			std::cout << "System Notice: Your role is not authorized to perform data reset, returning to main menu now..." << std::endl;
			displayTable();
			displayOption();
			std::cout << "User Input: ";
			optionmain = inputValidation(9);
			mainOption(optionmain);
		}

		break;
	case 8:
		// report
		if (head != NULL) {
			displayReportTable();
			displayOption();
			std::cout << "User Input: ";
			optionmain = inputValidation(9);
			mainOption(optionmain);
		}
		else {
			std::cout << "System Notice: List is still empty, returning to main menu now... " << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(300));
			displayTable();
			displayOption();
			std::cout << "User Input: ";
			optionmain = inputValidation(9);
			mainOption(optionmain);
		}
		
		break;
	case 9:
		// exit
		exitSystem();

		break;
	}
}

void insertOption(int option) {
	std::string nameSTR;
	std::string datejSTR;
	std::string datetSTR;
	double hourlyrateDBL;
	std::string phoneSTR;
	std::string addressSTR;
	int tccodeINT;
	std::string tcnameSTR;
	std::string subjectSTR;
	int ratingINT;

	int character = 0;
	std::string input;
	bool legit = false;
	int intdata = NULL;

	int d = 0;
	int m = 0;
	int y = 0;

	int optionmain = NULL;

	if ((option > 0) && (option < 3)) {
		for (int i = 1; i < arrayLength(tabletitle); i++) {
			std::cout << std::endl;
			std::cout << "Enter the Tutor " << tabletitle[i] << ": " << std::endl;
			if (i == 2) {
				std::cout << "User Input (YYYY/MM/DD): ";
			}
			else if (i == 3) {
				std::cout << "System Notice: You can leave it NULL by leaving an empty string (' ')." << std::endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(500));
				std::cout << "User Input (YYYY/MM/DD): ";
			}
			else if (i == 10) {
				std::cout << "User Input (1 ~ 5): ";
			}
			else {
				std::cout << "User Input: ";
			}
			// get the input along together with white space
			std::getline(std::cin, input);

			// give input validation and specific variable assigning accordingly
			switch (i) {
			case 1:
				character = spaceValidate(input);
				// tutor name
				while (character == 0) {
					std::cout << std::endl;
					std::cout << "System Notice: You can't leave a null value for Tutor Name, please try again." << std::endl;
					std::this_thread::sleep_for(std::chrono::milliseconds(500));
					std::cout << "User Input: ";
					// get the input along together with white space
					std::getline(std::cin, input);
					character = spaceValidate(input);
				}
				// if there are something in the input then we only assign into the variable
				if (character > 0) {
					nameSTR = input;
				}

				// reset the character back to 0 for further uses
				character = 0;
				break;

			case 2:
				// date joined
				while (legit != true) {
					// if able to extract the date format as YYYY/MM/DD
					if (extractDate(input, y, m, d)) {
						// if its the proper format then we will compare whether the date is later than current date or not
						if ((legitDate(input, currentDate())) == true) {
							// if its not later than the current date then assign to the variable
							datejSTR = input;
							legit = true;
						}
						else {
							std::cout << std::endl;
							std::cout << "System Notice: Tutor Date Joined can't be later than today, please try again." << std::endl;
							std::this_thread::sleep_for(std::chrono::milliseconds(500));
							std::cout << "User Input (YYYY/MM/DD): ";
							// get the input along together with white space
							std::getline(std::cin, input);
							legit = false;
						}
					}
					else {
						std::cout << std::endl;
						std::cout << "System Notice: Invalid format for Tutor Date Joined, please try again." << std::endl;
						std::this_thread::sleep_for(std::chrono::milliseconds(500));
						std::cout << "User Input (YYYY/MM/DD): ";
						// get the input along together with white space
						std::getline(std::cin, input);
						legit = false;
					}
				}

				// reset legit back to false for future uses
				legit = false;
				break;

			case 3:
				// date terminated
				while (legit != true) {
					// date terminate can be set as NULL on this matter to show it as "active" Tutor
					character = spaceValidate(input);
					// if the input is not an empty string then
					if (character != 0) {
						// if able to extract the date format as YYYY/MM/DD
						if (extractDate(input, y, m, d)) {
							// if its the proper format then we will compare whether the date is earlier than date joined or not
							if ((legitDate(datejSTR, input)) == true) {
								// if its not earlier than date joined then assign to the variable
								datetSTR = input;
								legit = true;
							}
							else {
								std::cout << std::endl;
								std::cout << "System Notice: Tutor Date Joined can't be earlier than Tutor Date Joined, please try again." << std::endl;
								std::this_thread::sleep_for(std::chrono::milliseconds(500));
								std::cout << "User Input (YYYY/MM/DD): ";
								// get the input along together with white space
								std::getline(std::cin, input);
								legit = false;
							}
						}
						else {
							std::cout << std::endl;
							std::cout << "System Notice: Invalid format for Tutor Date Terminated, please try again." << std::endl;
							std::this_thread::sleep_for(std::chrono::milliseconds(500));
							std::cout << "System Notice: You can leave it NULL by leaving an empty string (' ')." << std::endl;
							std::this_thread::sleep_for(std::chrono::milliseconds(500));
							std::cout << "User Input (YYYY/MM/DD): ";
							// get the input along together with white space
							std::getline(std::cin, input);
							legit = false;
						}
					}
					else {
						// if its empty string then assign into the variable
						datetSTR = " ";
						legit = true;
					}
				}

				// reset character back to 0 for future uses
				character = 0;
				// reset legit back to false for future uses
				legit = false;
				break;

			case 4:
				// hourly rate
				while (legit != true) {
					// check if the input is NULL or not
					character = spaceValidate(input);
					while (character == 0) {
						std::cout << std::endl;
						std::cout << "System Notice: You can't leave a null value for Tutor Hourly Rate, please try again." << std::endl;
						std::this_thread::sleep_for(std::chrono::milliseconds(500));
						std::cout << "User Input: ";
						// get the input along together with white space
						std::getline(std::cin, input);
						character = spaceValidate(input);
					}
					// if there are something in the input then we only assign into the variable
					if (character > 0) {
						// verify double integrity
						character = doubleValidate(input);
						if (character == 0) {
							// convert into double if the string is a double
							hourlyrateDBL = stod(input);

							// check if hourly rate is between 40 and 80 or not
							if ((hourlyrateDBL >= 40) && (hourlyrateDBL <= 80)) {
								legit = true;
							}
							else {
								std::cout << std::endl;
								std::cout << "System Notice: Tutor Hourly Rate must be around the range of RM 40.00 and RM 80.00, please try again." << std::endl;
								std::this_thread::sleep_for(std::chrono::milliseconds(500));
								std::cout << "User Input: ";
								// get the input along together with white space
								std::getline(std::cin, input);
								legit = false;
							}
						}
						else {
							std::cout << std::endl;
							std::cout << "System Notice: Invalid format for Tutor Hourly Rate, please try again." << std::endl;
							std::this_thread::sleep_for(std::chrono::milliseconds(500));
							std::cout << "User Input: ";
							// get the input along together with white space
							std::getline(std::cin, input);
							legit = false;
						}
					}
				}

				// reset character back to 0 for future uses
				character = 0;
				// reset legit back to false for future uses
				legit = false;
				break;

			case 5:
				// phone
				while (legit != true) {
					// check if the input is NULL or not
					character = spaceValidate(input);
					while (character == 0) {
						std::cout << std::endl;
						std::cout << "System Notice: You can't leave a null value for Tutor Phone, please try again." << std::endl;
						std::this_thread::sleep_for(std::chrono::milliseconds(500));
						std::cout << "User Input: ";
						// get the input along together with white space
						std::getline(std::cin, input);
						character = spaceValidate(input);
					}
					// if there are something in the input then we only assign into the variable
					if (character > 0) {
						// verify integer integrity
						character = intValidate(input);
						if (character == 0) {
							// no need to convert into int due to the data type
							phoneSTR = input;

							legit = true;
						}
						else {
							std::cout << std::endl;
							std::cout << "System Notice: Invalid format for Tutor Phone, only integer allowed, please try again." << std::endl;
							std::this_thread::sleep_for(std::chrono::milliseconds(500));
							std::cout << "User Input: ";
							// get the input along together with white space
							std::getline(std::cin, input);
							legit = false;
						}
					}
				}

				// reset character back to 0 for future uses
				character = 0;
				// reset legit back to false for future uses
				legit = false;
				break;

			case 6:
				// address
				character = spaceValidate(input);
				while (character == 0) {
					std::cout << std::endl;
					std::cout << "System Notice: You can't leave a null value for Tutor Address, please try again." << std::endl;
					std::this_thread::sleep_for(std::chrono::milliseconds(500));
					std::cout << "User Input: ";
					// get the input along together with white space
					std::getline(std::cin, input);
					character = spaceValidate(input);
				}
				// if there are something in the input then we only assign into the variable
				if (character > 0) {
					addressSTR = input;
				}

				// reset the character back to 0 for further uses
				character = 0;
				break;

			case 7:
				// tuition centre code
				while (legit != true) {
					// check if the input is NULL or not
					character = spaceValidate(input);
					while (character == 0) {
						std::cout << std::endl;
						std::cout << "System Notice: You can't leave a null value for Tution Center Code, please try again." << std::endl;
						std::this_thread::sleep_for(std::chrono::milliseconds(500));
						std::cout << "User Input: ";
						// get the input along together with white space
						std::getline(std::cin, input);
						character = spaceValidate(input);
					}
					// if there are something in the input then we only assign into the variable
					if (character > 0) {
						// verify integer integrity
						character = intValidate(input);
						if (character == 0) {
							// convert string to int
							tccodeINT = stoi(input);

							legit = true;
						}
						else {
							std::cout << std::endl;
							std::cout << "System Notice: Invalid format for Tution Center Code, only integer allowed, please try again." << std::endl;
							std::this_thread::sleep_for(std::chrono::milliseconds(500));
							std::cout << "User Input: ";
							// get the input along together with white space
							std::getline(std::cin, input);
							legit = false;
						}
					}
				}

				// reset character back to 0 for future uses
				character = 0;
				// reset legit back to false for future uses
				legit = false;
				break;

			case 8:
				// tuition centre name
				character = spaceValidate(input);
				while (character == 0) {
					std::cout << std::endl;
					std::cout << "System Notice: You can't leave a null value for Tuition Centre Name, please try again." << std::endl;
					std::this_thread::sleep_for(std::chrono::milliseconds(500));
					std::cout << "User Input: ";
					// get the input along together with white space
					std::getline(std::cin, input);
					character = spaceValidate(input);
				}
				// if there are something in the input then we only assign into the variable
				if (character > 0) {
					tcnameSTR = input;
				}

				// reset the character back to 0 for further uses
				character = 0;
				break;

			case 9:
				// subject
				character = spaceValidate(input);
				while (character == 0) {
					std::cout << std::endl;
					std::cout << "System Notice: You can't leave a null value for Tutor Subject, please try again." << std::endl;
					std::this_thread::sleep_for(std::chrono::milliseconds(500));
					std::cout << "User Input: ";
					// get the input along together with white space
					std::getline(std::cin, input);
					character = spaceValidate(input);
				}
				// if there are something in the input then we only assign into the variable
				if (character > 0) {
					subjectSTR = input;
				}

				// reset the character back to 0 for further uses
				character = 0;
				break;

			case 10:
				// rating
				while (legit != true) {
					// check if the input is NULL or not
					character = spaceValidate(input);
					while (character == 0) {
						std::cout << std::endl;
						std::cout << "System Notice: You can't leave a null value for Tutor Rating, please try again." << std::endl;
						std::this_thread::sleep_for(std::chrono::milliseconds(500));
						std::cout << "User Input: ";
						// get the input along together with white space
						std::getline(std::cin, input);
						character = spaceValidate(input);
					}
					// if there are something in the input then we only assign into the variable
					if (character > 0) {
						// verify integer integrity
						character = intValidate(input);
						if (character == 0) {
							// if integer integrity is confirmed, then we need to verify whether the value is more than 5 or not
							// convert string to temporary int variable
							intdata = stoi(input);
							// if its less than or equal 5 then its acceptable
							if ((intdata <= 5) && (intdata > 0)) {
								// convert string to int
								ratingINT = stoi(input);
								legit = true;
							}
							else {
								std::cout << std::endl;
								std::cout << "System Notice: Rating can't be more than five or less than one, please try again." << std::endl;
								std::this_thread::sleep_for(std::chrono::milliseconds(500));
								std::cout << "User Input (1 ~ 5): ";
								// get the input along together with white space
								std::getline(std::cin, input);
								legit = false;
							}
						}
						else {
							std::cout << std::endl;
							std::cout << "System Notice: Invalid format for Rating, only integer allowed, please try again." << std::endl;
							std::this_thread::sleep_for(std::chrono::milliseconds(500));
							std::cout << "User Input: ";
							// get the input along together with white space
							std::getline(std::cin, input);
							legit = false;
						}
					}
				}

				// reset intdata back to NULL for future uses
				intdata = NULL;
				// reset character back to 0 for future uses
				character = 0;
				// reset legit back to false for future uses
				legit = false;
				break;
			}
		}
	}

	switch (option) {
	case 1:
		// insert at the end of the list
		insertLast(nameSTR, datejSTR, datetSTR, hourlyrateDBL, phoneSTR, addressSTR, tccodeINT, tcnameSTR, subjectSTR, ratingINT);
		break;

	case 2:
		// insertsort into the list
		insertSort(nameSTR, datejSTR, datetSTR, hourlyrateDBL, phoneSTR, addressSTR, tccodeINT, tcnameSTR, subjectSTR, ratingINT);
		break;
	
	case 3:
		// back to main menu
		std::cout << "System Notice: You have choose Option " << option << ": " << arrayOption(optionsinsert, option) << ", returning to main menu now..." << std::endl;

		break;
	}

	displayTable();
	displayOption();
	std::cout << "User Input: ";
	optionmain = inputValidation(9);
	mainOption(optionmain);
}

void displayTBLOption(int option) {
	int optionmain = NULL;

	// now determine which type of the table choose to display
	switch (option) {
	case 1:
		// display table in normal way
		displayTable();
		break;

	case 2:
		// display table in reversed way
		displayReverseTable();
		break;

	case 3:
		// return to main menu since user chose back
		std::cout << "System Notice: You have choose Option " << option << ": " << arrayOption(optiondisplay, option) << ", returning to main menu now..." << std::endl;
		displayTable();

		break;
	}

	displayOption();
	std::cout << "User Input: ";
	optionmain = inputValidation(9);
	mainOption(optionmain);
}

void searchOption(int option) {
	int optionchoose = NULL;
	int optionmain = NULL;
	bool exist = false;
	std::string input;

	// now to determine the action of the user choose to do
	switch (option) {
	case 1:
		// search
		// ask the user which type of data did they want to search
		std::cout << "   " << "Select the type of the data you wished to search: " << std::endl;
		displayAction(tabletitlepointer, 11);
		std::cout << "User Input: ";
		optionchoose = inputValidation(11);

		// then ask the user for the value that they want to search
		std::cout << std::endl;
		std::cout << "Enter the value that you want to search (to search NULL you can leave it ' '): " << std::endl;
		std::cout << "User Input: ";
		// since we are just searching the exact string or value we will just assign the value without input validiation 
		// input validation done specifically in the search algorithm based on the type of tutor data the user choose the search
		// get the input along together with white space
		std::getline(std::cin, input);

		exist = searchRow(optionchoose, input);

		// if the result return from searchRow algo is false, we will ask the user to try to input the value again
		while (exist != true) {
			std::cout << "System Notice: Value not found within the list, please try again." << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
			std::cout << "Enter the value that you want to search (to search NULL you can leave it an empty space ' '): " << std::endl;
			std::cout << "User Input: ";
			std::getline(std::cin, input);

			// if it found the value it will automatically generate out the table in the function
			exist = searchRow(optionchoose, input);
		}

		break;

	case 2:
		// return to main menu since user chose back
		std::cout << "System Notice: You have choose Option " << option << ": " << arrayOption(optionsearch, option) << ", returning to main menu now..." << std::endl;
		displayTable();

		break;
	}

	displayOption();
	std::cout << "User Input: ";
	optionmain = inputValidation(9);
	mainOption(optionmain);
}

void sortOption(int option) {
	int optionmain = NULL;
	int optionorder = NULL;
	std::string input;

	// if the user choose 5 (Back), we will return to main menu instead
	if (option == 5) {
		// return to main menu since user chose back
		std::cout << "System Notice: You have choose Option " << option << ": " << arrayOption(optionsort, option) << ", returning to main menu now..." << std::endl;
		displayTable();

		displayOption();
		std::cout << "User Input: ";
		optionmain = inputValidation(9);
		mainOption(optionmain);
	}
	// otherwise we will perform the sorting algorithim, by first asking in what order the user want to sort
	else {
		displayAction(ascdescoption, 2);
		std::cout << "User Input: ";
		optionorder = inputValidation(2);

		// then perform the sorting algorithm
		sortData(option, optionorder);
	}
}

void sortData(int type, int order) {
	int optionmain = NULL;

	if (reporthead != NULL) {
		deleteAll(reporthead);
	}

	// now determine data that will be used to sort and insert into the sort list function
	switch (type) {
	case 1:
		// id
		sortedlistID(order);
		displaySortedTable();

		break;
	case 2:
		// location
		sortedlistLocation(order);
		displaySortedTable();

		break;
	case 3:
		// hourly rate
		sortedlistHourly(order);
		displaySortedTable();

		break;
	case 4:
		// rating
		temp = head;
		sortedlistRating(order, temp);
		displaySortedTable();

		break;

	case 5:
		// return to main menu
		std::cout << "System Notice: You have choose Option " << type << ": " << arrayOption(optionsort, type) << ", returning to main menu now..." << std::endl;
		displayTable();
	}

	displayOption();
	std::cout << "User Input: ";
	optionmain = inputValidation(9);
	mainOption(optionmain);
}

void modifyOption(int option) {
	int optionmain = NULL;
	bool exist = false;
	std::string input;

	// now to determine the action of the user choose to do
	switch (option) {
	case 1:
		// modifying the data
		// first we ask the user to input the ID of the Tutor
		std::cout << std::endl;
		std::cout << "Enter the Tutor ID that you wish to modify: " << std::endl;
		std::cout << "User Input: ";
		std::getline(std::cin, input);

		// the search algorithm to check whether the ID is within the list or not is already inside the function
		modifySpecific(input);

		break;

	case 2:
		// return to main menu since user chose back
		std::cout << "System Notice: You have choose Option " << option << ": " << arrayOption(optionmodify, option) << ", returning to main menu now..." << std::endl;
		displayTable();
		displayOption();
		std::cout << "User Input: ";
		optionmain = inputValidation(9);
		mainOption(optionmain);

		break;
	}
}

void deleteOption(int option) {
	int optionmain = NULL;
	bool exist = false;
	std::string input;

	// now to determine the action of the user choose to do
	switch (option) {
	case 1:
		// delete a specific address/table row
		// first we ask the user to input the ID of the Tutor
		std::cout << std::endl;
		std::cout << "Enter the Tutor ID that you wish to delete: " << std::endl;
		std::cout << "User Input: ";
		std::getline(std::cin, input);
		
		// then search whether the list have the ID or not
		exist = searchRow(1, input);

		// if the result return from searchRow algo is false, we will ask the user to try to input the value again
		while (exist != true) {
			std::cout << "System Notice: ID not found within the list, please try again." << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
			std::cout << "Enter the Tutor ID that you wish to delete: " << std::endl;
			std::cout << "User Input: ";
			std::getline(std::cin, input);

			exist = searchRow(1, input);
		}

		// if we found the existing ID then we will start to perform the deletion on it
		if (exist == true) {
			std::cout << "System Notice: Now checking deletion requirement fulfilled or not (6 months)..." << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			// we will now check whether the date terminated has reached 6 months duration or not
			if (checkDatesDiff(input) == true) {
				std::cout << "System Notice: Deletion requirement is fulfilled." << std::endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(500));
				if (confirmDel() == true) {
					deleteRow(input, head);
					std::cout << "System Notice: Deletion of Tutor ID: " << input << " is succeeded." << std::endl;
					std::this_thread::sleep_for(std::chrono::milliseconds(500));
				}
				else {
					std::cout << "System Notice: You choose not to delete. Deletion process halted." << std::endl;
					std::this_thread::sleep_for(std::chrono::milliseconds(500));
				}
			}
			else {
				std::cout << "System Notice: Date Terminated has not reached the minimum requirement of 6 months yet. Deletion is not granted." << std::endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(500));
			}

			std::cout << "System Notice: Returning to main menu now..." << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
		}

		break;

	case 2:
		// delete all
		// ask the user whether he wants to perform the deletion or not
		// if condition fulfilled and the user choose to perform, then perform the function
		if (confirmDel() == true) {
			deleteAll(head);
		}

		std::cout << "System Notice: Returning to main menu now..." << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(500));

		break;

	case 3:
		// return to main menu since user chose back
		std::cout << "System Notice: You have choose Option " << option << ": " << arrayOption(optiondelete, option) << ", returning to main menu now..." << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(500));

		break;
	}

	displayTable();
	displayOption();
	std::cout << "User Input: ";
	optionmain = inputValidation(9);
	mainOption(optionmain);
}

void modifySpecific(std::string addressSTR) {
	holdtemp = head;
	bool found = false;
	int modifyoption = 0;
	bool modifyresult = false;
	std::string modifyinput;
	int option = NULL;

	std::string inputTEMP;
	std::string addressTEMP;

	// convert input address into string
	std::ostringstream get_the_address;

	inputTEMP = addressSTR;

	// check if the address exist within the list or not
	while (found != true) {
		while (holdtemp != NULL) {
			// convert addresses into string
			get_the_address << holdtemp;
			addressTEMP = get_the_address.str();

			if (addressTEMP == inputTEMP) {
				found = true;

				break;
			}
			else {
				found = false;
				get_the_address.str("");
				get_the_address.clear();
			}

			holdtemp = holdtemp->next;
		}

		// if found is not true, and holdtemp is NULL, means we cant find the address in the list
		// we will want the user try to input again
		if ((found != true) && (holdtemp == NULL)) {
			std::cout << "System Notice: ID not found, please try again." << std::endl;
			std::cout << "User Input: ";
			// get the input along together with white space
			std::getline(std::cin, inputTEMP);
			
			// reset holdtemp to head for continuing the search later
			holdtemp = head;
			found = false;
			get_the_address.str("");
			get_the_address.clear();
		}
	}

	// if it exists then proceed to modification process based on the input type
	if (found == true) {
		std::cout  << "System Notice: Tutor ID " << addressSTR << ": " << holdtemp->name << " found within the list." << std::endl;
		std::cout << "   " << "Please choose the data type you want to modify: " << std::endl;
		displayAction(modifytypes, 11);
		std::cout << "User Input: ";
		modifyoption = inputValidation(11);

		// option 11 is return to main menu, so when the user choose option 11 we will halt the modification process and send him back to the main menu
		if (modifyoption == 11) {
			std::cout << "System Notice: You choose to return back to menu instead of modifying, now returning back to main menu..." << std::endl;
		}
		else {
			while (modifyresult != true) {
				std::cout << "Please type the value that you wish replace with (leave it a space ' ' if you want to place it as NULL): " << std::endl;
				std::cout << "User Input: ";
				// get the input along together with white space
				std::getline(std::cin, modifyinput);

				modifyresult = modifyData(modifyoption, modifyinput, holdtemp);

				if (modifyresult == false) {
					std::cout << "System Notice: Modification failed, please try again." << std::endl;
				}
				else {
					std::cout << "System Notice: Modification complete, now returning to main menu..." << std::endl;
				}
			}
		}
		// displaying option
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		displayTable();
		displayOption();
		std::cout << "User Input: ";
		option = inputValidation(9);
		mainOption(option);
	}
	else {
		std::cout << "System Notice: ID not found, please try again." << std::endl;
		// reset holdtemp back to head for future uses in loop
		holdtemp = head;
		found = false;
	}
}

bool modifyData(int type, std::string value, tms * address) {
	bool modified = false;
	holdtemp = address;
	int character = 0;
	int space = 0;
	int d = 0;
	int m = 0;
	int y = 0;
	double dbldata = NULL;
	int intdata = NULL;

	// determining the data type and covert into it before perform the actual modification
	switch (type) {
	case 1:
		// check if the user intended to make it as NULL or not
		space = spaceValidate(value);
		if (space == 0) {
			std::cout << "System Notice: You can't modify Tutor Name as NULL." << std::endl;
			modified = false;
		}
		else {
			holdtemp->name = value;
			modified = true;
		}

		break;
	case 2:
		// check if the user intended to make it as NULL or not
		space = spaceValidate(value);
		if (space == 0) {
			std::cout << "System Notice: You can't modify Tutor Date Joined as NULL." << std::endl;
			modified = false;
		}
		else {
			// verify date format
			// if able to extract the date format as YYYY/MM/DD
			if (extractDate(value, y, m, d)) {
				// we will check whether the date is legit or not
				if ((legitDate(value, currentDate())) == true) {
					// if its not later than the current date then allow the modification
					holdtemp->dateJ = value;
					modified = true;
				}
				else {
					std::cout << "System Notice: Tutor Date Joined can't be later than current date, please try again." << std::endl;
					modified = false;
				}
			}
			else {
				std::cout << "System Notice: Tutor Date Joined format is invalid." << std::endl;
				modified = false;
			}
		}

		break;
	case 3:
		// check if the user intended to make it as NULL or not
		space = spaceValidate(value);
		if (space == 0) {
			holdtemp->dateT = " ";
			modified = true;
		}
		else {
			// verify date format
			// if able to extract the date format as YYYY/MM/DD
			if (extractDate(value, y, m, d)) {
				// if its the proper format then we will compare whether the date is earlier than date joined or not
				if ((legitDate(holdtemp->dateJ, value)) == true) {
					// if its not earlier than date joined then allow the modification
					holdtemp->dateT = value;
					modified = true;
				}
				else {
					std::cout << "System Notice: Tutor Date Terminated can't be earlier than Tutor Date Joined, please try again." << std::endl;
					modified = false;
				}
			}
			else {
				std::cout << "System Notice: Tutor Date Terminated format is invalid." << std::endl;
				modified = false;
			}
		}

		break;
	case 4:
		// check if the user intended to make it as NULL or not
		space = spaceValidate(value);
		if (space == 0) {
			std::cout << "System Notice: You can't modify Tutor Hourly Rate as NULL." << std::endl;
			modified = false;
		}
		else {
			// verify double integrity
			character = doubleValidate(value);
			if (character == 0) {
				// convert into double if the string is a double
				dbldata = stod(value);
				// check if hourly rate is between 40 and 80 or not
				if ((dbldata >= 40) && (dbldata <= 80)) {
					holdtemp->hourlyrate = dbldata;

					modified = true;
				}
				else {
					std::cout << "System Notice: Tutor Hourly Rate must be around the range of RM 40.00 and RM 80.00." << std::endl;
					modified = false;
				}
			}
			else {
				std::cout << "System Notice: Tutor Hourly Rate must be in double format." << std::endl;
				modified = false;
			}
		}

		break;
	case 5:
		// check if the user intended to make it as NULL or not
		space = spaceValidate(value);
		if (space == 0) {
			std::cout << "System Notice: You can't modify Tutor Phone as NULL." << std::endl;
			modified = false;
		}
		else {
			// verify integer integrity
			character = intValidate(value);
			if (character == 0) {
				// no need to convert into int due to the data type
				holdtemp->phone = value;

				modified = true;
			}
			else {
				std::cout << "System Notice: Tutor Phone must be integer only." << std::endl;
				modified = false;
			}
		}

		break;
	case 6:
		// check if the user intended to make it as NULL or not
		space = spaceValidate(value);
		if (space == 0) {
			std::cout << "System Notice: You can't modify Tutor Address as NULL." << std::endl;
			modified = false;
		}
		else {
			holdtemp->address = value;
			modified = true;
		}

		break;
	case 7:
		// check if the user intended to make it as NULL or not
		space = spaceValidate(value);
		if (space == 0) {
			std::cout << "System Notice: You can't modify Tuition Center Code as NULL." << std::endl;
			modified = false;
		}
		else {
			// verify integer integrity
			character = intValidate(value);
			if (character == 0) {
				// convert string to int
				intdata = stoi(value);
				holdtemp->tccode = intdata;

				modified = true;
			}
			else {
				std::cout << "System Notice: Tuition Center Code must be integer only." << std::endl;
				modified = false;
			}
		}

		break;
	case 8:
		// check if the user intended to make it as NULL or not
		space = spaceValidate(value);
		if (space == 0) {
			std::cout << "System Notice: You can't modify Tuition Center Name as NULL." << std::endl;
			modified = false;
		}
		else {
			holdtemp->tcname = value;
			modified = true;
		}
		
		break;
	case 9:
		// check if the user intended to make it as NULL or not
		space = spaceValidate(value);
		if (space == 0) {
			std::cout << "System Notice: You can't modify Tutor Subject as NULL." << std::endl;
			modified = false;
		}
		else {
			holdtemp->subject = value;
			modified = true;
		}

		break;
	case 10:
		// check if the user intended to make it as NULL or not
		space = spaceValidate(value);
		if (space == 0) {
			std::cout << "System Notice: You can't modify Tutor Rating as NULL." << std::endl;
			modified = false;
		}
		else {
			// verify integer integrity
			character = intValidate(value);
			if (character == 0) {
				intdata = stoi(value);
				// as the highest rating is only 5 we need to verify whether the data is around 5 or not
				if ((0 < intdata) && (intdata < 6)) {
					holdtemp->rating = intdata;

					modified = true;
				}
				else {
					std::cout << "System Notice: Tutor Rating must be only around the range of 1 to 5." << std::endl;
					modified = false;
				}
			}
			else {
				std::cout << "System Notice: Tutor Rating must be integer only." << std::endl;
				modified = false;
			}
		}

		break;
	}

	return modified;
}

void deleteRow(std::string addressSTR, tms * listtype) {
	bool integrity = false;

	// if holdhead is NULL means the function is not executed from deleteAll() function, but manually executed one by one
	if (holdhead == NULL) {
		// we will only assign the address if the holdhead is NULL, to avoid overwrite of the address
		holdhead = listtype;
		integrity = true;
	}
	// listtype exp: sorthead, head, reporthead that are the starting point of the linked list
	reporttemp = listtype;
	std::string tempSTR;

	// convert address into string
	std::ostringstream get_the_address;

	while (reporttemp != NULL) {
		// convert addresses into string
		get_the_address << reporttemp;
		tempSTR = get_the_address.str();

		// if met with the same address, then perform the deletion
		if (tempSTR == addressSTR) {
			// reconnect the link list as deletion will proceed
			if (reporttemp->prev != NULL) {
				reporttemp->prev->next = reporttemp->next;
			}
			// the temp->prev is NULL, it must be a head, so assign the head to the next one
			else {
				if (holdhead == head) {
					head = reporttemp->next;
				}
				else if (holdhead == sorthead) {
					sorthead = reporttemp->next;
				}
				else if (holdhead == reporthead) {
					reporthead = reporttemp->next;
				}
			}
			
			if (reporttemp->next != NULL) {
				reporttemp->next->prev = reporttemp->prev;
			// if the temp->next is a null then means the tail need to be changed as the last item temp will be deleted
			} else {
				if (holdhead == head) {
					tail = NULL;
				}
				else if (holdhead == sorthead) {
					sorttail = NULL;
				}
				else if (holdhead == reporthead) {
					reporttail = NULL;
				}
			}

			if (holdtemp == NULL) {
				holdtemp = reporttemp->next;
			}
			delete reporttemp;
			reporttemp = holdtemp;
			// if its false we know this function is executed from the deleteAll function, so we make it NULL to break the loop
			if (integrity == false) {
				reporttemp = NULL;
			}
		}
		else if ((tempSTR != addressSTR) && (integrity == true)) {
			reporttemp = reporttemp->next;
		}

		get_the_address.str("");
		get_the_address.clear();
	}

	// reset holdhead to NULL for future uses
	holdhead = NULL;
}

void deleteAll(tms* listtype) {
	tms* oldhead = NULL;
	sorttemp = listtype;
	// holding the listtype head for a awhile (normally will be head address in the function parameter)
	holdhead = listtype;
	int pointer = NULL;
	std::string tempSTR;

	// convert address into string
	std::ostringstream get_the_address;

	// set the value of pointer based on the type of input, then we will assign NULL value based on the pointer's value
	if (head == listtype) {
		pointer = 0;
	}
	else if (sorthead == listtype) {
		pointer = 1;
	}
	else if (reporthead == listtype) {
		pointer = 2;
	}

	while (sorttemp != NULL) {
		holdtemp = sorttemp->next;
		oldhead = sorttemp;
		// convert addresses into string
		get_the_address << sorttemp;
		tempSTR = get_the_address.str();

		deleteRow(tempSTR, oldhead);

		sorttemp = holdtemp;

		get_the_address.str("");
		get_the_address.clear();
	}

	if (sorttemp == NULL) {
		std::cout << "System Notice: The entire list has deleted." << std::endl;

		// reset all to NULL
		if (pointer == 0) {
			head = NULL;
			temp = NULL;
			tail = NULL;
		}
		else if (pointer == 1) {
			sorthead = NULL;
			sorttemp = NULL;
			sorttail = NULL;
		}
		else if (pointer == 2) {
			reporthead = NULL;
			reporttemp = NULL;
			reporttail = NULL;
		}
	}
	holdhead = NULL;
	holdtail = NULL;
	holdtemp = NULL;
}

void generateReport() {
	std::string holdSTR;
	int n = 0;
	int found = 0;
	int option = NULL;

	holdtemp = head;

	while (n != totalNodes()) {
		while (holdtemp != NULL) {
			holdSTR = holdtemp->dateT;
			
			// if date terminated is empty string means its currently active
			if (holdSTR == " ") {
				// if found the active tutors then start to insert into report list
				tms* newnode = createnewnode(holdtemp->name, holdtemp->dateJ, holdtemp->dateT, holdtemp->hourlyrate, holdtemp->phone, holdtemp->address, holdtemp->tccode, holdtemp->tcname, holdtemp->subject, holdtemp->rating);

				reporttemp = reporthead;
				// if its inserting the first value into the list, define both prev and next as NULL
				if (reporttemp == NULL) {
					reporttemp = newnode;
					reporttemp->prev = NULL;
					reporttemp->next = NULL;
					reporthead = newnode;
				}
				// if its inserting the common value into the list, define both prev and next in the usual way
				else {
					newnode->next = reporttemp->next;
					reporttemp->next = newnode;
					newnode->prev = reporttemp;
				}

				found++;
				reporttail = newnode;
			}

			holdtemp = holdtemp->next;
			n++;
		}
	}

	if (found > 0) {
		// then allign them all based on the rating in descending order
		sortedlistRating(2, reporthead);
		// because the sortedlistRating function by default will assign into sorthead, sorttail, etc, so we need to redirect the allignment into reporthead, reporttail, etc
		// assign sorthead into reporthead, sorttail into reporttail; and make sorthead and sorttail as NULL
		reporthead = sorthead;
		reporttail = sorttail;
		sorthead = NULL;
		sorttail = NULL;
	}
	else {
		std::cout << "System Notice: No active user found, now returning to main menu..." << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		displayOption();
		std::cout << "User Input: ";
		option = inputValidation(9);
		mainOption(option);
	}
}

bool confirmDel() {
	int deloption = NULL;
	bool confirm = false;

	std::cout << "System Notice: Are you sure you want to perform the deletion process?" << std::endl;
	displayAction(truefalseoption, 2);
	std::cout << "User Input: ";
	deloption = inputValidation(2);

	if (deloption == 1) {
		// now check whether the requirements fulfilled or not
		// check role is suitable for performing the deletion or not
		if (role == 1) {
			confirm = true;
		}
		else {
			std::cout << "System Notice: Your role is not authorized to perform deletion, returning to main menu now..." << std::endl;
			confirm = false;
		}
	}
	else if (deloption == 2) {
		std::cout << "System Notice: You have choose not to perform deletion, returning to main menu now..." << std::endl;
		confirm = false;
	}

	return confirm;
}

void exitSystem() {
	int exitoption = NULL;
	int option = NULL;

	std::cout << "System Notice: Are you sure you want to exit the system?" << std::endl;
	displayAction(truefalseoption, 2);
	std::cout << "User Input: ";
	exitoption = inputValidation(2);

	if (exitoption == 1) {
		std::cout << "System Notice: System exiting..." << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		exit;
	}
	else if (exitoption == 2) {
		std::cout << "System Notice: You have choose not to exit the system, returning to main menu now..." << std::endl;
		displayTable();
		displayOption();
		std::cout << "User Input: ";
		option = inputValidation(9);
		mainOption(option);
		exitoption = NULL;
	}
}