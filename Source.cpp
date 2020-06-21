#include <iostream>
#include <string>
#include <sstream> //convert datatypes like address, double into string

#include "linkedlist.h"

int main() {
	int option = NULL;

	// preparing the program
	std::cout << "System Notice: Preparing the program..." << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));

	// verify the user role first
	verifyrole();

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
	
	// display out the data
	displayTable();
	displayOption();
	
	// beginning of the input
	std::cout << "User Input: ";
	option = inputValidation(9);
	mainOption(option);

	return 0;
}