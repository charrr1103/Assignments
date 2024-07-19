#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <iomanip>
#include <cctype>
#include <windows.h>  //for decorations
using namespace std;

string choice;
struct movieInfo {
	string movieTitle, location, showtime, showtime1, showtime2, showtime3, showtime4;
	char day[20];
	string movieType, language, subtitle, synopsis;
	int duration;
	double ticketPrice;
};
struct movieDetails {
	string movieTitle, movieType, language, subtitle, synopsis;
	int duration;
	double ticketPrice;
};
struct tPrice {
	string movieTitle;
	double ticketPrice;
};
void addMovieInfo(movieInfo info[], int& numberOfMovies);
void addMovieDetails(movieDetails details[], int& numberOfMovies);
void deleteMovieInfo(movieInfo info[], int& numberOfMovies);
void adminLogin();
void aModule();
void adminAdd();
void adminDelete();
void cinemaLogo() {
	string lineCL;

	ifstream inFileCL("cinemaLogo.txt");

	if (inFileCL.fail()) {   //displays error message if text file fails to open
		cout << "ERROR: Unable to open file." << endl;
	}

	else {
		while (getline(inFileCL, lineCL)) {  //reads through line by line
			HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hc, 0x07);
			cout << "                                     ";

			SetConsoleTextAttribute(hc, 79);
			cout << lineCL << endl;

		}
		inFileCL.close();
	}
}
void welcomeMessage() {

	string lineM;

	ifstream inFileM("welcomemessage.txt");

	if (inFileM.fail()) {   //displays error message if text file fails to open
		cout << "ERROR: Unable to open file." << endl;
	}

	else {
		while (getline(inFileM, lineM)) {  //reads through line by line
			HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hc, 0x07);
			cout << "                                     ";
			
			SetConsoleTextAttribute(hc, 79);
			cout << lineM <<endl;

		}
		inFileM.close();
	}

	
}
void customerMenu() {
	string lineCM;

	ifstream inFileCM("customerMenu.txt");

	if (inFileCM.fail()) {   //displays error message if text file fails to open
		cout << "ERROR: Unable to open file." << endl;
	}

	else {
		while (getline(inFileCM, lineCM)) {  //reads through line by line
			HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hc, 0x07);
			cout << "                    ";

			SetConsoleTextAttribute(hc, 79);
			cout << lineCM << endl;

		}
		inFileCM.close();
	}
}
void customerChoice();
void customerRegister();
void customerLogin();
void receipt();
void movieDetail();
void book(string&, string&);
void cModule(string&, string&);
void showTime(string&, string&, int&);
void seat(string&, string&, int&, string&, string&, string&, string&, int&);
void typeOfTicket(string&, string&, int&, string&, string&, string&, string&, int&, int&, string&, string&, string&, string&, string&);

HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);   //for decoration: colour of text and console

int main() {
	system("cls");
	welcomeMessage();

	HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);   //for decoration: colour of text and console
	SetConsoleTextAttribute(hc, 6);

	cout << "                                     ";
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "                                     ";
	SetConsoleTextAttribute(hc, 228);
	cout << "                           Welcome to our login page!                           " ;
	SetConsoleTextAttribute(hc, 6);
	cout << "                                     " << endl;
	cout << "                                     ";
	cout << "--------------------------------------------------------------------------------" ;
	cout << "                                     " << endl;
	cout << "                                     ";
	cout << "                                   You are                                      " << endl;
	cout << "                                     ";
	cout << "                                1. a Customer                                   " << endl;
	cout << "                                     ";
	cout << "                                2. an Administrator                             " << endl;

	bool validChoice = false;

	while (!validChoice) {
		// prompt user for choice input
		cout << "                                                     ";
		cout << "            Please enter your choice:";
		cin >> choice;

		// check if choice is valid
		if (choice == "1") {
			validChoice = true;
			customerChoice();   //enter page to let customer choose whether to register or login
			break;
		}
		else if (choice == "2") {
			validChoice = true;
			adminLogin();   //enter admin login page
			break;
		}
		else {
			// choice is invalid
			validChoice = false;

			SetConsoleTextAttribute(hc, 0x07);
			cout << "                                                          ";
			SetConsoleTextAttribute(hc, 64);
			cout << "ERROR: Invalid choice. Please try again.\n";
			SetConsoleTextAttribute(hc, 6);
			cout << endl;
		}
	}
}

void customerChoice() {  //function for the user to choose between register or login
	
	system("cls");
	string cusChoice;  //customer's choice
	customerMenu();

	SetConsoleTextAttribute(hc, 0x07);
	cout << "                    ";
	SetConsoleTextAttribute(hc, 228);
	cout << "                                                                                                                 " << endl;
	SetConsoleTextAttribute(hc, 0x07);
	cout << "                    ";
	SetConsoleTextAttribute(hc, 228);
	cout << "                                               Would you like to                                                 " << endl; //prompt user to pick a choice
	SetConsoleTextAttribute(hc, 0x07);
	cout << "                    ";
	SetConsoleTextAttribute(hc, 228);
	cout << "                                                                                                                 " << endl;
	SetConsoleTextAttribute(hc, 0x07);
	cout << "                    ";
	SetConsoleTextAttribute(hc, 228);
	cout << "                                                 1. Register                                                     " << endl;
	SetConsoleTextAttribute(hc, 0x07);
	cout << "                    ";
	SetConsoleTextAttribute(hc, 228);
	cout << "                                                 2. Log in                                                       " << endl;
	SetConsoleTextAttribute(hc, 0x07);
	cout << "                    ";
	SetConsoleTextAttribute(hc, 228);
	cout << "                                                 3. View movie details                                           " << endl;
	SetConsoleTextAttribute(hc, 0x07);
	cout << "                    ";
	SetConsoleTextAttribute(hc, 228);
	cout << "                                                 4. Go back                                                      " << endl;
	SetConsoleTextAttribute(hc, 0x07);
	cout << "                    ";
	SetConsoleTextAttribute(hc, 228);
	cout << "                                                                                                                 " << endl;
	SetConsoleTextAttribute(hc, 0x07);
	cout << "                    ";
	SetConsoleTextAttribute(hc, 6);
	cout << "=================================================================================================================" << endl;
	SetConsoleTextAttribute(hc, 0x07);
	cout << "                    ";
	SetConsoleTextAttribute(hc, 6);

	bool checkChoice = false;
	while (!checkChoice) {
		cout << "                                              ";
		cout << "Enter your choice:";
		cin >> cusChoice;

		if (cusChoice == "1") {  //enters register page to sign up with new account
			bool checkChoice = true;
			customerRegister();
		}
		else if (cusChoice == "2") {  //enters login page to login with existing account
			customerLogin();
		}
		else if (cusChoice == "3") {
			bool checkChoice = true;
			system("cls");
			movieDetail();
			system("cls");
			customerChoice();
		}
		else if (cusChoice == "4") {  //exits and goes back to the main menu 
			bool checkChoice = true;
			system("cls");
			main();
		}
		else {  //error message if none of the options were chosen
			bool checkChoice = false;

			cout << "                                                   ";
			cout << "Please choose one of the options given.\n\n\n\n\n" << endl;
			SetConsoleTextAttribute(hc, 6);
			cout << endl;

			cout << "                                                          ";
			system("PAUSE");
			system("cls");
		}
	}
}

void customerRegister() { //function for the user to register a new account
	system("cls");
	string inUsernameC, inPasswordC;
	bool validAccount = false;  //initialization to check if the username exists in the text file

	cinemaLogo();
	cout << endl;
	SetConsoleTextAttribute(hc, 0x07);
	cout << "                                                          ";
	SetConsoleTextAttribute(hc, 207);
	cout << "==========================================" << endl;
	SetConsoleTextAttribute(hc, 0x07);
	cout << "                                                          ";
	SetConsoleTextAttribute(hc, 207);
	cout << "|        Customer Registration Page      |" << endl;
	SetConsoleTextAttribute(hc, 0x07);
	cout << "                                                          ";
	SetConsoleTextAttribute(hc, 207);
	cout << "==========================================" << endl;
	cout << endl << endl;
	SetConsoleTextAttribute(hc, 6);

	while (!validAccount) {  //continues to execute as long as it is not true (false), terminates when it is true
		int countR = 0;
		string inFirstnameC, inLastnameC, newUsernameC, newPasswordC, newEmailC, newphonenumC;  //variables for new information and details
		string lineC;  //lines to be read in the text file
		bool passAccept = false;  //boolean to check if the password is acceptable or not

		cout << "                                                       ";
		cout << "Please fill in the following details correctly." << endl;  //prompts users to fill in registration details
		cout << "                                                       ";
		cout << "-----------------------------------------------" << endl;
		cout << "                                                       ";
		cout << "First name: ";
		
		SetConsoleTextAttribute(hc, 112);
		cin >> inFirstnameC;
		SetConsoleTextAttribute(hc, 6);
		cout << "                                                       ";
		cout << "Last name: ";
		SetConsoleTextAttribute(hc, 112);
		cin.ignore();
		getline(cin, inLastnameC);
		SetConsoleTextAttribute(hc, 6);
		newUsernameC = inFirstnameC + " " + inLastnameC;  //combines first name and last name into new username
		cout << "                                                       ";
		cout << "E-mail: ";
		SetConsoleTextAttribute(hc, 112);
		getline(cin, newEmailC);
		SetConsoleTextAttribute(hc, 6);

		while (!passAccept) {  //continues to executes as long as it is not true (false)
			cout << "                                                       ";
			cout << "Password (must be at least 8 characters long): ";
			SetConsoleTextAttribute(hc, 112);
			cin >> newPasswordC;
			SetConsoleTextAttribute(hc, 6);

			if (newPasswordC.length() < 8) {  //checks password length

				SetConsoleTextAttribute(hc, 0x07);
				cout << "                                                       ";
				SetConsoleTextAttribute(hc, 64);
				cout << "Password is too short." << endl;
				SetConsoleTextAttribute(hc, 6);
				cout << endl;
				
				passAccept = false;
			}
			else {
				SetConsoleTextAttribute(hc, 6);

				SetConsoleTextAttribute(hc, 0x07);
				cout << "                                                       ";
				SetConsoleTextAttribute(hc, 175);
				cout << "Password accepted." << endl;
				SetConsoleTextAttribute(hc, 6);
				passAccept = true;  //terminates loop
			}
		}
		SetConsoleTextAttribute(hc, 6);
		cout << "                                                       ";
		cout << "Phone number: ";
		cin.ignore();
		SetConsoleTextAttribute(hc, 112);
		getline(cin, newphonenumC);
		SetConsoleTextAttribute(hc, 6);

		ifstream inputFileC("customers.txt");  //opens text file and read

		if (inputFileC.fail()) {   //displays error message if text file fails to open
			SetConsoleTextAttribute(hc, 0x07);
			cout << "                                                   ";
			SetConsoleTextAttribute(hc, 64);
			cout << "ERROR: Unable to open file." << endl;
			SetConsoleTextAttribute(hc, 6);
			cout << endl;
		}
		else {
			while (getline(inputFileC, lineC)) {  //reads through line by line
				size_t pos = lineC.find(",");     //finds the position of the comma,"," that separates the details
				string usernameC = lineC.substr(0, pos);

				if (usernameC == newUsernameC) {
					countR = 1;

					SetConsoleTextAttribute(hc, 0x07);
					cout << "                                                       ";
					SetConsoleTextAttribute(hc, 64);
					cout << "Sorry, username is already taken. Please choose another one." << endl;
					SetConsoleTextAttribute(hc, 6);
					cout << endl;
					cout << "                                                       ";
					system("PAUSE");
					system("cls");
				}
			}
			if (countR == 1) {
				customerRegister();
			}
			else {
				//append new customer details to text file
				ofstream outputFileC("customers.txt", ios::app);
				outputFileC << newUsernameC << ',' << newPasswordC << ',' << newEmailC << ',' << newphonenumC << endl;
				inputFileC.close();
				outputFileC.close();
				SetConsoleTextAttribute(hc, 0x07);
				cout << "                                                       ";
				SetConsoleTextAttribute(hc, 175);
				cout << "Registration is successful!" << endl;   //success message
				SetConsoleTextAttribute(hc, 6);
				cout << endl;
				cout << "                                                       ";
				system("PAUSE");
				customerChoice();  //go back to customer menu
				break;
			}
		}
	}
}

void customerLogin() {
	int countC = 0, attemptsC = 0, maxAttemptsC = 3;
	string inUsernameC, inPasswordC;   //input username and password
	string usernameC, passwordC;       //username and password from the text file for comparison
	string emailC, phonenumC;
	string lineC;
	bool validLoginC = false;

	system("cls");
	cinemaLogo();
	cout << endl;
	SetConsoleTextAttribute(hc, 0x07);
	cout << "                                                          ";
	SetConsoleTextAttribute(hc, 207);
	cout << "==========================================" << endl;
	SetConsoleTextAttribute(hc, 0x07);
	cout << "                                                          ";
	SetConsoleTextAttribute(hc, 207);
	cout << "|           Customer Login Page          |" << endl;
	SetConsoleTextAttribute(hc, 0x07);
	cout << "                                                          ";
	SetConsoleTextAttribute(hc, 207);
	cout << "==========================================" << endl;
	cout << endl << endl;
	SetConsoleTextAttribute(hc, 6);

	while (attemptsC < maxAttemptsC) {
		cout << "                                                          ";
		cout << "Please enter your username and password." << endl;   //prompt user to enter username and password
		cout << "                                                          ";
		cout << "Username: ";
		cin.ignore();
		SetConsoleTextAttribute(hc, 112);
		getline(cin, inUsernameC);  //getline to get the whole sentence
		SetConsoleTextAttribute(hc, 6);
		cout << "                                                          ";
		cout << "Password: ";
		SetConsoleTextAttribute(hc, 112);
		cin >> inPasswordC;
		SetConsoleTextAttribute(hc, 6);

		ifstream inputFileC("customers.txt");

		if (inputFileC.fail()) {  //error checking for file
			cout << "                                                          ";
			SetConsoleTextAttribute(hc, 64);
			cout << "ERROR: Unable to open file." << endl;
			SetConsoleTextAttribute(hc, 6);
			cout << endl;
		}
		else {
			while (getline(inputFileC, lineC)) { //searches file for username and password match
				size_t pos = lineC.find(",");
				string usernameC = lineC.substr(0, pos);
				size_t pos2 = lineC.find(",", pos + 1);
				string passwordC = lineC.substr(pos + 1, pos2 - pos - 1);
				size_t pos3 = lineC.find(",", pos2 + 1);
				string emailC = lineC.substr(pos2 + 1, pos3 - pos2 - 1);
				string phonenumC = lineC.substr(pos3 + 1);

				if (usernameC == inUsernameC && passwordC == inPasswordC) {
					countC = 1;
				}
			}
			if (countC == 1) { //if both username and password match
				cout << endl;
				SetConsoleTextAttribute(hc, 6);
				cout << "                                                          ";
				SetConsoleTextAttribute(hc, 175);
				cout << "Your login is successful. Welcome back, " << inUsernameC << "!" << endl;
				SetConsoleTextAttribute(hc, 6);
				cout << endl << endl << endl;
				cout << "                                                          ";
				system("PAUSE");
				
				validLoginC = true;
				cModule(inUsernameC, inPasswordC);
			}
			else { //if either one is a mismatch
				cout << "                                                          ";
				SetConsoleTextAttribute(hc, 64);
				cout << "ERROR: Username or password is incorrect." << endl;
				SetConsoleTextAttribute(hc, 6);
				cout << endl << endl << endl;
				validLoginC = false;
				attemptsC++;
			}
			inputFileC.close();
		}
		cout << endl;
		if (validLoginC) {
			break;
		}
		else if (attemptsC == maxAttemptsC) { //once the user reached the maximum number of attempts given
			SetConsoleTextAttribute(hc, 0x07);
			cout << "                                                    ";
			SetConsoleTextAttribute(hc, 64);
			cout << "You've tried to sign in too many times. Try again later." << endl;
			SetConsoleTextAttribute(hc, 6);
			cout << "                                                          ";
			system("PAUSE");
			system("cls");
			main();
		}
		inputFileC.clear();
		inputFileC.seekg(0, ios::beg);
	}
}

void book(string& inUsernameC, string& inPasswordC) {
	int noMovie = 1, movie;

	system("cls");
	cinemaLogo();
	SetConsoleTextAttribute(hc, 0x07);
	cout << "                                                       ";
	SetConsoleTextAttribute(hc, 79);
	cout << "These are the movies that are currently available." << endl;
	SetConsoleTextAttribute(hc, 6);
	cout << endl;

	ifstream movieFile;
	string movieName, movieType, language, subtitle, synopsis, purchase;
	int duration;
	double ticketPrice, priceCOS;

	movieFile.open("movie.txt");//check movie details
	while (getline(movieFile, movieName))
	{
		for (int i = 0; i < 6; i++) {
			string notName;
			getline(movieFile.ignore(), notName);//only display the movie name
		}
		SetConsoleTextAttribute(hc, 0x07);
		cout << "                                                       ";
		SetConsoleTextAttribute(hc, 207);
		cout << noMovie << ". " << movieName << endl;

		noMovie++;

		if (movieFile.peek() == '\n') {
			movieFile.ignore();
		}
	}
	movieFile.close();

	cout << endl;
	SetConsoleTextAttribute(hc, 0x07);
	cout << "                                                       ";
	SetConsoleTextAttribute(hc, 228);
	cout << "Enter [0] to go back." << endl;
	SetConsoleTextAttribute(hc, 0x07);
	cout << endl;
	cout << "                                                       ";
	SetConsoleTextAttribute(hc, 6);
	cout << "Please select a movie: ";
	cin >> movie;

	while (movie != 0 && (movie < 1 || movie > noMovie - 1)) {
		SetConsoleTextAttribute(hc, 0x07);
		cout << "                                                       ";
		SetConsoleTextAttribute(hc, 64);
		cout << "ERROR: Invalid movie number, please enter again: ";//display error meesage if invalid input
		SetConsoleTextAttribute(hc, 6);
		cin >> movie;
	}
	if (movie == 0) {
		system("cls");
		cModule(inUsernameC, inPasswordC);
	}
	system("cls");
	cinemaLogo();

	movieFile.open("movie.txt");//check the movie chosen
	while (!movieFile.eof()) {
		for (int i = 1; i != movie; i++) {//when movie != i, ignore i times 6 lines(6 lines is 1 set movie detail, which means ignore the movie details that not the movie chosen)
			for (int i = 0; i < 7; i++) {
				string notchoice;
				getline(movieFile.ignore(), notchoice);
			}
		}
		getline(movieFile, movieName);//display the movie details of movie chosen
		movieFile >> ticketPrice;
		movieFile >> duration;
		movieFile.ignore();
		getline(movieFile, movieType);
		movieFile >> language;
		movieFile.ignore();
		getline(movieFile, subtitle);
		getline(movieFile, synopsis);
		SetConsoleTextAttribute(hc, 0x07);
		cout << "                                                           ";
		SetConsoleTextAttribute(hc, 79);
		cout << movieName << endl;
		SetConsoleTextAttribute(hc, 6);
		cout << endl;
		cout << "Ticket price(adult): RM " << fixed << setprecision(2) << ticketPrice << endl;
		priceCOS = ticketPrice - 4;
		cout << endl;
		cout << "Ticket price (Child/OKU/Senior citizen): RM " << fixed << setprecision(2) << priceCOS << endl;
		cout << endl;
		cout << "Duration: " << duration << "min" << endl;
		cout << endl;
		cout << "Type: " << movieType << endl;
		cout << endl;
		cout << "Language: " << language << endl;
		cout << endl;
		cout << "Subtitle: " << subtitle << endl;
		cout << endl;
		cout << "Synopsis: " << synopsis << "\n" << endl;

		while (!movieFile.eof()) { //ignore the rest since they are not movie chosen
			string notchoice;
			getline(movieFile.ignore(), notchoice);
		}
		showTime(inUsernameC, inPasswordC, movie);
	}
	movieFile.close();
}

void showTime(string& inUsernameC, string& inPasswordC, int& movie) {//select the showtime movie chosen
	string purchase;
	bool validPurchase = false;
	while (!validPurchase) {
		SetConsoleTextAttribute(hc, 4);
		cout << "                                                          ";
		cout << "Do you want to buy the ticket? (y/n):";
		cin >> purchase;

		if (purchase == "y" || purchase == "Y") {
			validPurchase = false;

			system("cls");
			cinemaLogo();
			SetConsoleTextAttribute(hc, 6);

			ifstream showtimeFile;
			showtimeFile.open("showtime.txt"); //check the showtime movie chosen

			int showtimeChoice;
			string moviename[100], ticketPrice[100], theater[100], day[100];
			int showtime[100][4], i = 0;

			while (!showtimeFile.eof()) {
				for (int i = 1; i != movie; i++) {//when movie != i, ignore i times 6 lines(6 lines is 1 set showtime detail, which means ignore the showtime details that not the movie chosen)
					for (int i = 0; i < 7; i++) {
						string notchoice;
						getline(showtimeFile.ignore(), notchoice);
					}
				}
				getline(showtimeFile, moviename[i]);//read moviename, theater and day of the movie chosen
				getline(showtimeFile, theater[i]);
				showtimeFile >> day[i];

				cout << endl;
				cout << "                                                       ";
				SetConsoleTextAttribute(hc, 6);
				cout << "Movie name: " << moviename[i] << endl;
				cout << endl;
				cout << "                                                       ";
				cout << "Location: " << theater[i] << endl;
				cout << endl;
				cout << "                                                       ";
				cout << "Day: " << day[i] << endl;
				cout << endl;

				for (int j = 0; j < 4; j++) { //Read the 4 showtime in textfile
					showtimeFile >> showtime[i][j];
					cout << "                                                       ";
					cout << "Showtime " << j + 1 << ": " << showtime[i][j] << endl;
					cout << endl;
				}
				SetConsoleTextAttribute(hc, 0x07);
				cout << "                                                       ";
				SetConsoleTextAttribute(hc, 228);
				cout << "Enter [0] to go back." << endl;
				SetConsoleTextAttribute(hc, 0x07);
				cout << endl;
				SetConsoleTextAttribute(hc, 4);

				bool validChoice = false;
				while (!validChoice) {
					SetConsoleTextAttribute(hc, 4);
					cout << "                                                       ";
					cout << "Select showtime (1-4): ";
					cin >> showtimeChoice;
					SetConsoleTextAttribute(hc, 6);
					if (showtimeChoice == 0) {
						validChoice = true;
						system("cls");
						book(inUsernameC, inPasswordC);
					}
					else if (showtimeChoice >= 1 && showtimeChoice <= 4) {
						validChoice = true;
						
						cout << endl;
						cout << "                                                       ";
						cout << moviename[i] << endl;
						string movienameSelected = moviename[i]; //store the moviename of movie chosen for the seat()
						SetConsoleTextAttribute(hc, 6);
						cout << "                                                       ";
						cout << "Location: " << theater[i] << endl;
						string theaterSelected = theater[i]; //store the theater of movie chosen for the seat()
						cout << "                                                       ";
						cout << "Day: " << day[i] << endl;
						string daySelected = day[i]; //store the day of movie chosen for the seat()
						cout << "                                                       ";
						cout << "You selected showtime: " << showtime[i][showtimeChoice - 1] << endl;
						int showtimeSelected = showtime[i][showtimeChoice - 1]; //store the showtime chosen for the seat()
						cout << endl;
						cout << "                                                       ";
						system("PAUSE");

						seat(inUsernameC, inPasswordC, movie, purchase, movienameSelected, theaterSelected, daySelected, showtimeSelected);
					}
					else {
						validChoice = false;
						SetConsoleTextAttribute(hc, 0x07);
						cout << "                                                       ";
						SetConsoleTextAttribute(hc, 64);
						cout << "ERROR: Invalid showtime selection." << endl;
						SetConsoleTextAttribute(hc, 6);
					}
					i++;

					showtimeFile.ignore();
					cout << endl;

					while (!showtimeFile.eof()) { //ignore the rest which not the movie chosen
						string notchoice;
						getline(showtimeFile.ignore(), notchoice);
					}
				}
			}
			showtimeFile.close();
		}
		else if (purchase == "n" || purchase == "N") {
			validPurchase = false;
			system("cls");
			book(inUsernameC, inPasswordC);
		}
		else {
			validPurchase = true;

			SetConsoleTextAttribute(hc, 6);
			SetConsoleTextAttribute(hc, 0x07);
			cout << "                                                       ";
			SetConsoleTextAttribute(hc, 64);
			cout << "ERROR: Invalid input. Please enter 'y' or 'n'." << endl;//display error message if invalid input
			SetConsoleTextAttribute(hc, 6);
		}
	}
}

void seat(string& inUsernameC, string& inPasswordC, int& movie, string& purchase, string& movienameSelected, string& theaterSelected,
	string& daySelected, int& showtimeSelected){
	system("cls");
	cinemaLogo();
	SetConsoleTextAttribute(hc, 6);

	string seatChoice, askMoreSeat;
	bool moreSeat = false;
	int totalSeat = 0;
	string movieSeat[6][8] = { {"A1","A2","A3","A4","A5","A6","A7","A8"},
		{"B1","B2","B3","B4","B5","B6","B7","B8"},
		{"C1","C2","C3","C4","C5","C6","C7","C8"},
		{"D1","D2","D3","D4","D5","D6","D7","D8"},
		{"E1","E2","E3","E4","E5","E6","E7","E8"},
		{"F1","F2","F3","F4","F5","F6","F7","F8"} };
	ifstream RbookingFile;
	RbookingFile.open("booking.txt");//Check the booked seat
	string bookedMoviename[100], bookedTheater[100], bookedDay[100], bookedSeatLine, bookedSeat[100][50];
	int bookedtime[100], a = 0;

	while (!RbookingFile.eof()) {
		getline(RbookingFile, bookedMoviename[a]);
		getline(RbookingFile, bookedTheater[a]);
		RbookingFile >> bookedDay[a];
		RbookingFile >> bookedtime[a];

		for (int b = 0; b < 5; b++) {
			RbookingFile >> bookedSeat[a][b];
			if (bookedMoviename[a] == movienameSelected && bookedTheater[a] == theaterSelected
				&& bookedDay[a] == daySelected && bookedtime[a] == showtimeSelected) {
				//if the data in booking.txt is same with movie name, theater, day and showtime that store from showtime(), show "XX" to the booked seat
				for (int i = 0; i < 6; i++) {
					for (int j = 0; j < 8; j++) {
						if (bookedSeat[a][b] == movieSeat[i][j]) {
							movieSeat[i][j] = "XX";
						}
					}
				}
			}
		}
		RbookingFile.ignore();
		a++;
	}
	RbookingFile.close();

	cout << endl;
	cout << movienameSelected << endl;
	cout << "Theater: " << theaterSelected << endl;
	cout << "Day: " << daySelected << endl;
	cout << "Showtime: " << showtimeSelected << endl;
	cout << endl;
	cout << "\n\t\t\t\t\t\t\t\t   Screen\n\n" << endl;
	for (int i = 0; i < 6; i++){
		for (int j = 0; j < 8; j++) {
			cout << "          ";
			cout << setw(6) << movieSeat[i][j];// display the seat, the booked seat will showed with "XX" and not allowed to choose
		}
		cout << endl << endl;
	}
	cout << endl;
	cout << "[B]ack" << endl;

	string seatSelectedLine[5] = { "N/A","N/A","N/A","N/A","N/A" };//start with empty 5 seat
	int z = 0;
	do {
		bool validSeat = false;
		cout << endl;
		cout << "Please enter the seat you want (max 5 seats to book): ";
		while (validSeat == false) {
			cin >> seatChoice;
			if (seatChoice == "B" || seatChoice == "b") {
				system("cls");
				showTime(inUsernameC, inPasswordC, movie);
			}
			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 8; j++) {
					if (seatChoice == movieSeat[i][j]) {
						if (movieSeat[i][j] == "XX") {
							validSeat = false;//"XX" seat is not allowed to choose
						}
						else {
							validSeat = true;
							seatSelectedLine[z] = seatChoice;//change "N/A" in the list to the seat number chosen
							z++;//z+1 after seat booked successfully
							totalSeat++;//use for the typeOfTicket()
						}
					}
				}
			}
			if (validSeat == false) {
				SetConsoleTextAttribute(hc, 64);
				cout << "You have either entered an invalid seat number or the seat number you entered was booked. Please choose other seat(s): ";
				//wrong input of seatChoice or choose the "XX" seat will get an error message
				SetConsoleTextAttribute(hc, 6);
			}
		}
		if (totalSeat == 5) {
			moreSeat = false; //maximum 5 seats for once, when 5 seats selected go to typeOfTicket()
		}
		else {
			cout << "Do you want to book more seat? (y/n): ";
			cin >> askMoreSeat;
			if (askMoreSeat == "B" || askMoreSeat == "b") {
				cout << endl;
				system("cls");
				showTime(inUsernameC, inPasswordC, movie);
			}
			while (askMoreSeat != "y" && askMoreSeat != "n") {
				cout << endl;
				SetConsoleTextAttribute(hc, 64);
				cout << "ERROR: Invalid input. Please enter 'y' or 'n': ";//error message if input is not "y" or "n"
				SetConsoleTextAttribute(hc, 6);
				cin >> askMoreSeat;
			}
			if (askMoreSeat == "y") {
				moreSeat = true;//go to select the next seat
			}
			else {
				moreSeat = false;//go to typeOfTicket()
			}
		}
	} while (moreSeat == true);
	string firstSeatSelected;
	firstSeatSelected = seatSelectedLine[0];
	string secondSeatSelected;
	secondSeatSelected = seatSelectedLine[1];
	string thirdSeatSelected;
	thirdSeatSelected = seatSelectedLine[2];
	string fourthSeatSelected;
	fourthSeatSelected = seatSelectedLine[3];
	string fifthSeatSelected;
	fifthSeatSelected = seatSelectedLine[4];
	//store the seat selected to display the receipt
	system("cls");
	typeOfTicket(inUsernameC, inPasswordC, movie, purchase, movienameSelected, theaterSelected, daySelected, showtimeSelected,
		totalSeat, firstSeatSelected, secondSeatSelected, thirdSeatSelected, fourthSeatSelected, fifthSeatSelected);
}

void typeOfTicket(string& inUsernameC, string& inPasswordC, int& movie, string& purchase,
	string& movienameSelected, string& theaterSelected, string& daySelected, int& showtimeSelected,
	int& totalSeat, string& firstSeatSelected, string& secondSeatSelected, string& thirdSeatSelected, string& fourthSeatSelected, string& fifthSeatSelected){
	//choose the type of ticket: adult, child, oku or senior
	system("cls");
	cinemaLogo();
	SetConsoleTextAttribute(hc, 6);

	int ticketType, noticket = 1, adultTicket = 0, childTicket = 0, okuTicket = 0, seniorTicket = 0;
	double price, totalPrice = 0;
	string movieNameinPrice;
	cout << endl;
	cout << "                                                       ";
	cout << "You have selected " << totalSeat << " seat(s)." << endl;
	cout << "                                                       ";
	cout << "Which ticket do you want to buy ? " << endl;
	cout << "                                                       ";
	cout << "1. Adult" << endl;
	cout << "                                                       ";
	cout << "2. Children" << endl;
	cout << "                                                       ";
	cout << "3.OKU" << endl;
	cout << "                                                       ";
	cout << "4.Seniors" << endl;

	ifstream priceFile;
	priceFile.open("price.txt");//check the adult price of movie selected
	while (!priceFile.eof()) {
		for (int i = 1; i != movie; i++) {//when movie != i, ignore i times 2 lines(2 lines is 1 set movie price, which means ignore the movie price that not the movie chosen)
			for (int i = 0; i < 2; i++) {
				string notchoice;
				getline(priceFile.ignore(), notchoice);
			}
		}
		getline(priceFile, movieNameinPrice);//Read the adult price of movie selected
		priceFile >> price;
		while (!priceFile.eof()) { //ignore the rest
			string notchoice;
			getline(priceFile.ignore(), notchoice);
		}
	}
	priceFile.close();

	for (int i = 0; i < totalSeat; i++) {//Input the type of ticket wanted, times to input according to the totalSeat stored from seat()
		cout << endl;
		cout << "                                                       ";
		cout << "Ticket " << noticket << ": ";
		noticket++;
		cin >> ticketType;
		while (ticketType < 1 || ticketType >4) {
			SetConsoleTextAttribute(hc, 0x07);
			cout << "                                                       ";
			SetConsoleTextAttribute(hc, 64);
			cout << "ERROR: Invalid ticket type. Please enter again: ";//display error message if invalid input
			SetConsoleTextAttribute(hc, 6);
			cin >> ticketType;
		}
		switch (ticketType){
			//child, OKU and senior ticket price is cheaper RM4 than the adult ticket price
		case 1:
			totalPrice = totalPrice + price;
			adultTicket++;
			break;
		case 2:
			totalPrice = totalPrice + (price - 4);
			childTicket++;
			break;
		case 3:
			totalPrice = totalPrice + (price - 4);
			okuTicket++;
			break;
		case 4:
			totalPrice = totalPrice + (price - 4);
			seniorTicket++;
			break;
		}
	}
	string confirm;
	bool validConfirm = false;

	while (!validConfirm) {
		system("cls");
		cinemaLogo();
		SetConsoleTextAttribute(hc, 6);

		//display the ticket chosen and the price
		cout << endl;
		cout << fixed << setprecision(2);
		cout << "                                                       ";
		cout << "Type\t" << "noTicket\t" << "Price\t" << "Total Price" << endl;
		cout << "                                                       ";
		cout << "Adult\t" << adultTicket << "\t\t" << price << "\t" << adultTicket * price << endl;
		cout << "                                                       ";
		cout << "Child\t" << childTicket << "\t\t" << price - 4 << "\t" << childTicket * (price - 4) << endl;
		cout << "                                                       ";
		cout << "OKU\t" << okuTicket << "\t\t" << price - 4 << "\t" << okuTicket * (price - 4) << endl;
		cout << "                                                       ";
		cout << "Senior\t" << seniorTicket << "\t\t" << price - 4 << "\t" << seniorTicket * (price - 4) << endl;
		cout << "                                                       ";
		cout << "-------------------------------------------" << endl;
		cout << "                                                       ";
		cout << "\t\t\t\t" << totalPrice << endl;
		cout << endl;
		cout << "                                                       ";
		cout << "-------------------------------------------" << endl;
		cout << "                                                       ";
		cout << "[P]rocess\t\t[R]eset seat" << endl;
		cout << "                                                       ";
		cout << "Choice: ";
		cin >> confirm;

		if (confirm == "R" || confirm == "r") {//back to seat()
			validConfirm = true;
			system("cls");
			seat(inUsernameC, inPasswordC, movie, purchase, movienameSelected, theaterSelected, daySelected, showtimeSelected);
		}
		else if (confirm == "P" || confirm == "p") {//go to payment interface
			validConfirm = true;

			system("cls");
			cinemaLogo();
			SetConsoleTextAttribute(hc, 6);
			cout << endl;
			SetConsoleTextAttribute(hc, 0x07);
			cout << "                                                          ";
			SetConsoleTextAttribute(hc, 207);
			cout << "==========================================" << endl;
			SetConsoleTextAttribute(hc, 0x07);
			cout << "                                                          ";
			SetConsoleTextAttribute(hc, 207);
			cout << "|         Payment Confirmation Page      |" << endl;
			SetConsoleTextAttribute(hc, 0x07);
			cout << "                                                          ";
			SetConsoleTextAttribute(hc, 207);
			cout << "==========================================" << endl;
			SetConsoleTextAttribute(hc, 6);

			string paymentUserName, paymentUserPassword;
			bool payment = false;
			int chance = 3;
			do {  //enter again the username and password to pay
				cout << endl;
				cout << "                                                       ";
				cout << "Please enter your username and password to pay." << endl;
				cout << "                                                       ";
				cout << "Username: ";
				cin.ignore();
				SetConsoleTextAttribute(hc, 112);
				getline(cin, paymentUserName);
				SetConsoleTextAttribute(hc, 6);
				cout << "                                                       ";
				cout << "Password: ";
				SetConsoleTextAttribute(hc, 112);
				cin >> paymentUserPassword;
				SetConsoleTextAttribute(hc, 6);

				if (paymentUserName == inUsernameC && paymentUserPassword == inPasswordC) {
					payment = true;
					//accept payment if input and password is same with the username and password which used to login
				}
				else { //give 3 more chance to enter the correct username and password
					SetConsoleTextAttribute(hc, 0x07);
					cout << "                                                       ";
					SetConsoleTextAttribute(hc, 4);
					cout << "Wrong Username or Password. You have " << chance << " times left to insert the correct username and password.\n" << endl;
					SetConsoleTextAttribute(hc, 0x07);
					cout << "                                                       ";
					cout << "-----------------------------------------------------------------------------------------------" << endl;
					SetConsoleTextAttribute(hc, 6);

					chance--;
					payment = false;
					if (chance < 0) {
						cout << endl;
						SetConsoleTextAttribute(hc, 6);
						SetConsoleTextAttribute(hc, 0x07);
						cout << "                                                       ";
						SetConsoleTextAttribute(hc, 4);
						cout << "You reached the maximum fail times. Payment failed, back to movie show interface.\n" << endl;
						SetConsoleTextAttribute(hc, 6);
						cout << endl << endl;
						cout << "                                                       ";
						system("PAUSE");
						system("cls");
						cModule(inUsernameC, inPasswordC);
						//send to cModule if enter the wrong username and password too many times
					}
				}
			} while (payment == false);

			system("cls");
			//display receipt
			cout << endl;
			SetConsoleTextAttribute(hc, 0x07);
			cout << "                                                       ";
			SetConsoleTextAttribute(hc, 47);
			cout << "Payment successful! Please take your receipt!" << endl;
			SetConsoleTextAttribute(hc, 0x07);
			cout << "                                                       ";
			SetConsoleTextAttribute(hc, 47);
			cout << "---------------------------------------------" << endl;
			SetConsoleTextAttribute(hc, 6);
			cout << "                                                       ";
			cout << "Movie: " << movienameSelected << endl;
			cout << "                                                       ";
			cout << "Theater: " << theaterSelected << endl;
			cout << "                                                       ";
			cout << "Day: " << daySelected << endl;
			cout << "                                                       ";
			cout << "Time: " << showtimeSelected << endl;
			cout << "                                                       ";

			//only display the seat that's not "N/A"
			cout << "Seat(s): " << firstSeatSelected << " ";
			if (secondSeatSelected != "N/A")
				cout << secondSeatSelected << " ";
			if (thirdSeatSelected != "N/A")
				cout << thirdSeatSelected << " ";
			if (fourthSeatSelected != "N/A")
				cout << fourthSeatSelected << " ";
			if (fifthSeatSelected != "N/A")
				cout << fifthSeatSelected << " ";

			cout << endl;
			cout << "                                                       ";
			cout << "Ticket(s): " << totalSeat << endl;
			cout << "                                                       ";
			cout << "Adult: RM" << price << " x " << adultTicket << " = " << adultTicket * price << endl;
			cout << "                                                       ";
			cout << "Child: RM" << price - 4 << " x " << childTicket << " = " << childTicket * (price - 4) << endl;
			cout << "                                                       ";
			cout << "OKU: RM" << price - 4 << " x " << okuTicket << " = " << okuTicket * (price - 4) << endl;
			cout << "                                                       ";
			cout << "Senior: RM" << price - 4 << " x " << seniorTicket << " = " << seniorTicket * (price - 4) << endl;
			cout << "                                                       ";
			cout << "Total Price: RM" << totalPrice << endl;
			cout << "                                                       ";
			cout << endl;
			cout << "                                                       ";
			cout << "Name: " << inUsernameC << endl;
			cout << "                                                       ";
			cout << "--------------------------------------------" << endl;
			cout << "                                                       ";
			cout << "Thank you! Please enjoy your movie!" << endl;
			cout << "                                                          ";
			cout << endl << endl << endl << endl;
			cout << "                                                       ";
			system("PAUSE");
			system("cls");

			//write the detail into the booking.txt to show "XX" to the booked seat
			ofstream bookingFile;
			bookingFile.open("booking.txt", ios::app);
			bookingFile << movienameSelected << "\n" << theaterSelected << "\n" << daySelected << "\n" << showtimeSelected << "\n";
			bookingFile << firstSeatSelected << " " << secondSeatSelected << " " << thirdSeatSelected << " " << fourthSeatSelected << " " << fifthSeatSelected << "\n";
			bookingFile.close();

			//write the detail into receipt.txt for the view booked movie module
			ofstream receiptFile;
			receiptFile.open("receipt.txt", ios::app);
			receiptFile << inUsernameC << "\n" << movienameSelected << "\n" << theaterSelected << "\n" << daySelected << "\n" << showtimeSelected << "\n";
			receiptFile << firstSeatSelected << " " << secondSeatSelected << " " << thirdSeatSelected << " " << fourthSeatSelected << " " << fifthSeatSelected << "\n";
			receiptFile.close();

			cModule(inUsernameC, inPasswordC);
		}
		else {
			validConfirm = false;
			SetConsoleTextAttribute(hc, 0x07);
			cout << "                                                       ";
			SetConsoleTextAttribute(hc, 64);
			cout << "ERROR: Invalid input, please enter 'P' or 'R': " << endl;//show the error message if invalid input
			SetConsoleTextAttribute(hc, 6);
			cout << endl << endl << endl;
			cout << "                                                       ";
			system("PAUSE");
		}
	}
}

void cModule(string& inUsernameC, string& inPasswordC){
	system("cls");
	string customerModule;
	bool correctModule = false;

	cinemaLogo();
	SetConsoleTextAttribute(hc, 6);
	cout << endl;
	SetConsoleTextAttribute(hc, 0);
	cout << "                                                            ";
	SetConsoleTextAttribute(hc, 6);
	cout << "Welcome!" << endl;
	cout << endl;
	cout << "                                                            ";
	cout << "1. Book a ticket" << endl;
	cout << "                                                            ";
	cout << "2. View movie details" << endl;
	cout << "                                                            ";
	cout << "3. View booked movie" << endl;
	cout << "                                                            ";
	cout << "4. Exit" << endl;

	while (!correctModule) {
		cout << endl;
		cout << "                                                            ";
		cout << "Choice: ";
		cin >> customerModule;

		if (customerModule == "1") {//booking
			book(inUsernameC, inPasswordC);
		}
		else if (customerModule == "2") {//view the movie detail
			movieDetail();
			system("cls");
			cModule(inUsernameC, inPasswordC);
		}
		else if (customerModule == "3") {//view booked movie
			string userNameR, movienameR, theaterR, dayR, RfirstSeatSelected, RsecondSeatSelected, RthirdSeatSelected, RfourthSeatSelected, RfifthSeatSelected;
			int showtimeR;
			double TadultPriceR, TchildPriceR, TokuPriceR, TseniorPriceR, totalPriceR;
			ifstream RreceiptFile;
			RreceiptFile.open("receipt.txt");//check the booked movie details

			system("cls");
			cinemaLogo();
			SetConsoleTextAttribute(hc, 6);
			cout << endl;
			SetConsoleTextAttribute(hc, 0x07);
			cout << "                                                          ";
			SetConsoleTextAttribute(hc, 207);
			cout << "==========================================" << endl;
			SetConsoleTextAttribute(hc, 0x07);
			cout << "                                                          ";
			SetConsoleTextAttribute(hc, 207);
			cout << "|           View Booked Movie(s)         |" << endl;
			SetConsoleTextAttribute(hc, 0x07);
			cout << "                                                          ";
			SetConsoleTextAttribute(hc, 207);
			cout << "==========================================" << endl;
			SetConsoleTextAttribute(hc, 6);

			while (!RreceiptFile.eof()) {
				getline(RreceiptFile, userNameR);
				if (userNameR == inUsernameC) {//display only the booked movie details of the user logged in
					getline(RreceiptFile, movienameR);
					getline(RreceiptFile, theaterR);
					RreceiptFile >> dayR;
					RreceiptFile >> showtimeR;
					RreceiptFile >> RfirstSeatSelected >> RsecondSeatSelected >> RthirdSeatSelected >> RfourthSeatSelected >> RfifthSeatSelected;
					RreceiptFile >> TadultPriceR >> TchildPriceR >> TokuPriceR >> TseniorPriceR >> totalPriceR;

					cout << endl;
					cout << "                                                          ";
					cout << "Customer: " << userNameR << endl;
					cout << "                                                          ";
					cout << "Movie name: " << movienameR << endl;
					cout << "                                                          ";
					cout << "Theater: " << theaterR << endl;
					cout << "                                                          ";
					cout << "Day: " << dayR << endl;
					cout << "                                                          ";
					cout << "Time: " << showtimeR << endl;
					cout << "                                                          ";
					cout << "Seat(s): " << RfirstSeatSelected << " ";
					//display only the seat those not "N/A"
					if (RsecondSeatSelected != "N/A")
						cout << RsecondSeatSelected << " ";
					if (RthirdSeatSelected != "N/A")
						cout << RthirdSeatSelected << " ";
					if (RfourthSeatSelected != "N/A")
						cout << RfourthSeatSelected << " ";
					if (RfifthSeatSelected != "N/A")
						cout << RfifthSeatSelected << " ";
					cout << endl;
					cout << "                                                          ";
					cout << "Ticket(s):" << endl;
					cout << fixed << setprecision(2);
					//display only the ticketprice those not 0;
					if (TadultPriceR != 0) {
						cout << "                                                          ";
						cout << "\tAdult: RM" << TadultPriceR << endl;
					}
					if (TchildPriceR != 0) {
						cout << "                                                          ";
						cout << "\tChild: RM" << TchildPriceR << endl;
					}
					if (TokuPriceR != 0) {
						cout << "                                                          ";
						cout << "\tOKU: RM" << TokuPriceR << endl;
					}
					if (TseniorPriceR != 0) {
						cout << "                                                          ";
						cout << "\tSenior: RM" << TseniorPriceR << endl;
					}
					cout << "                                                          ";
					cout << "Total price: RM" << totalPriceR << endl;
					cout << endl;
				}
			}
			RreceiptFile.close();

			cout << endl << endl;
			cout << "                                                          ";
			system("pause");
			system("cls");
			cModule(inUsernameC, inPasswordC);
		}
		else if (customerModule == "4") {
			main();//exit
		}
		else {
			cout << "                                                          ";
			SetConsoleTextAttribute(hc, 64);
			cout << "ERROR: Invalid input." << endl;//error message when get an invalid input
			SetConsoleTextAttribute(hc, 6);
			cout << "                                                          ";
			system("PAUSE");
			cModule(inUsernameC, inPasswordC);//send back to cModule
		}
	}
}

void receipt() {
	string userNameR, movienameR, theaterR, dayR, RfirstSeatSelected, RsecondSeatSelected, RthirdSeatSelected, RfourthSeatSelected, RfifthSeatSelected;
	int showtimeR;
	double TadultPriceR, TchildPriceR, TokuPriceR, TseniorPriceR, totalPriceR;
	ifstream RreceiptFile;
	RreceiptFile.open("receipt.txt");  //open file for reading

	system("cls");
	cinemaLogo();
	SetConsoleTextAttribute(hc, 6);
	cout << endl;
	SetConsoleTextAttribute(hc, 0x07);
	cout << "                                                          ";
	SetConsoleTextAttribute(hc, 207);
	cout << "==========================================" << endl;
	SetConsoleTextAttribute(hc, 0x07);
	cout << "                                                          ";
	SetConsoleTextAttribute(hc, 207);
	cout << "|        View Customer Transactions      |" << endl;
	SetConsoleTextAttribute(hc, 0x07);
	cout << "                                                          ";
	SetConsoleTextAttribute(hc, 207);
	cout << "==========================================" << endl;
	SetConsoleTextAttribute(hc, 6);

	while (getline(RreceiptFile, userNameR)) {  //read through line by line
		getline(RreceiptFile, movienameR);
		getline(RreceiptFile, theaterR);
		RreceiptFile >> dayR;
		RreceiptFile >> showtimeR;
		RreceiptFile >> RfirstSeatSelected >> RsecondSeatSelected >> RthirdSeatSelected >> RfourthSeatSelected >> RfifthSeatSelected;
		RreceiptFile >> TadultPriceR >> TchildPriceR >> TokuPriceR >> TseniorPriceR >> totalPriceR;
		RreceiptFile.ignore();
		
		//display receipt details
		cout << "                                                          ";
		cout << "Customer: " << userNameR << endl;
		cout << "                                                          ";
		cout << "Movie name: " << movienameR << endl;
		cout << "                                                          ";
		cout << "Theater: " << theaterR << endl;
		cout << "                                                          ";
		cout << "Day: " << dayR << endl;
		cout << "                                                          ";
		cout << "Time: " << showtimeR << endl;
		cout << "                                                          ";
		cout << "Seat(s): " << RfirstSeatSelected << " ";    //if the seat in the text file is stored as "N/A", then replace with " "
		if (RsecondSeatSelected != "N/A")
			cout << RsecondSeatSelected << " ";
		if (RthirdSeatSelected != "N/A")
			cout << RthirdSeatSelected << " ";
		if (RfourthSeatSelected != "N/A")
			cout << RfourthSeatSelected << " ";
		if (RfifthSeatSelected != "N/A")
			cout << RfifthSeatSelected << " ";
		cout << endl;
		cout << "                                                          ";
		cout << "Ticket(s):" << endl;
		cout << fixed << setprecision(2);
		if (TadultPriceR != 0) {
			cout << "                                                          ";
			cout << "\tAdult: RM" << TadultPriceR << endl;
		}
		if (TchildPriceR != 0) {
			cout << "                                                          ";
			cout << "\tChild: RM" << TchildPriceR << endl;
		}
		if (TokuPriceR != 0) {
			cout << "                                                          ";
			cout << "\tOKU: RM" << TokuPriceR << endl;
		}
		if (TseniorPriceR != 0) {
			cout << "                                                          ";
			cout << "\tSenior: RM" << TseniorPriceR << endl;
		}
		cout << "                                                          ";
		cout << "Total price: RM" << totalPriceR << endl;
		cout << endl;
	}
	RreceiptFile.close();
	system("PAUSE");
	system("cls");
	aModule();
}

void movieDetail(){
	system("cls");
	cinemaLogo();
	SetConsoleTextAttribute(hc, 6);
	cout << endl;
	SetConsoleTextAttribute(hc, 0x07);
	cout << "                                                          ";
	SetConsoleTextAttribute(hc, 207);
	cout << "==========================================" << endl;
	SetConsoleTextAttribute(hc, 0x07);
	cout << "                                                          ";
	SetConsoleTextAttribute(hc, 207);
	cout << "|               Movie Details            |" << endl;
	SetConsoleTextAttribute(hc, 0x07);
	cout << "                                                          ";
	SetConsoleTextAttribute(hc, 207);
	cout << "==========================================" << endl;
	cout << endl;
	SetConsoleTextAttribute(hc, 0x07);
	cout << "                                                       ";
	SetConsoleTextAttribute(hc, 79);
	cout << "These are the movies that are currently available." << endl;
	SetConsoleTextAttribute(hc, 6);
	cout << endl << endl;

	ifstream movieFile("movie.txt");
	string movieName, movieType, language, subtitle, synopsis;
	int duration;
	double ticketPrice, priceCOS;

	while (getline (movieFile, movieName)){  //read movie details from the text file 
		movieFile >> ticketPrice;
		movieFile >> duration;
		movieFile.ignore();
		getline(movieFile, movieType);
		movieFile >> language;
		movieFile.ignore();
		getline(movieFile, subtitle);
		getline(movieFile, synopsis);

		//display movie details
		cout << movieName << endl;
		cout << "Ticket price (Adult): RM " << fixed << setprecision(2) << ticketPrice << endl;
		priceCOS = ticketPrice - 4;
		cout << "Ticket price (Child/OKU/Senior citizen): RM " << fixed << setprecision(2) << priceCOS << endl;
		cout << "Duration: " << duration << "min" << endl;
		cout << "Type: " << movieType << endl;
		cout << "Language: " << language << endl;
		cout << "Subtitle: " << subtitle << endl;
		cout << "Synopsis: " << synopsis << "\n" << endl;
		cout << endl;
	}
	movieFile.close();
	system("pause");
}

void adminLogin() {
	int countA = 0, attemptsA = 0, maxAttemptsA = 3;
	string inUsernameA, inPasswordA;   //input admin username and password
	string usernameA, passwordA;       //admin username and password from the text file for comparison
	string lineA;
	string adminSelect;
	bool validLoginA = false;

	system("cls");
	cinemaLogo();
	SetConsoleTextAttribute(hc, 6);
	SetConsoleTextAttribute(hc, 0x07);
	cout << endl;
	SetConsoleTextAttribute(hc, 0x07);
	cout << "                                                          ";
	SetConsoleTextAttribute(hc, 207);
	cout << "==========================================" << endl;
	SetConsoleTextAttribute(hc, 0x07);
	cout << "                                                          ";
	SetConsoleTextAttribute(hc, 207);
	cout << "|          Administrator Login Page      |" << endl;
	SetConsoleTextAttribute(hc, 0x07);
	cout << "                                                          ";
	SetConsoleTextAttribute(hc, 207);
	cout << "==========================================" << endl;
	cout << endl << endl;
	SetConsoleTextAttribute(hc, 6);
	cout << "                                                          ";
	cout << "------------------------------------------" << endl;
	cout << "                                                          ";
	cout << "|                1. Login                |" << endl;
	cout << "                                                          ";
	cout << "------------------------------------------" << endl;
	cout << "                                                          ";
	cout << "|                2. Go back              |" << endl;
	cout << "                                                          ";
	cout << "------------------------------------------" << endl;
	cout << "                                                          ";
	cout << "                 Choice: ";
	cin >> adminSelect;

	if (adminSelect == "1") {
		system("cls");
		cinemaLogo();
		SetConsoleTextAttribute(hc, 6);
		SetConsoleTextAttribute(hc, 0x07);
		cout << endl;
		SetConsoleTextAttribute(hc, 0x07);
		cout << "                                                          ";
		SetConsoleTextAttribute(hc, 207);
		cout << "==========================================" << endl;
		SetConsoleTextAttribute(hc, 0x07);
		cout << "                                                          ";
		SetConsoleTextAttribute(hc, 207);
		cout << "|          Administrator Login Page      |" << endl;
		SetConsoleTextAttribute(hc, 0x07);
		cout << "                                                          ";
		SetConsoleTextAttribute(hc, 207);
		cout << "==========================================" << endl;
		cout << endl << endl;
		SetConsoleTextAttribute(hc, 6);

		while (attemptsA < maxAttemptsA) {
			cout << "                                                          ";
			cout << "Please enter your username and password." << endl;   //prompt user to enter username and password
			cout << "                                                          ";
			cout << "Username: ";
			cin.ignore();
			SetConsoleTextAttribute(hc, 112);
			getline(cin, inUsernameA);  //getline to get the whole sentence
			SetConsoleTextAttribute(hc, 6);
			cout << "                                                          ";
			cout << "Password: ";
			SetConsoleTextAttribute(hc, 112);
			cin >> inPasswordA;
			SetConsoleTextAttribute(hc, 6);

			ifstream inputFileA("admin.txt");

			if (inputFileA.fail()) {
				cout << "                                                       ";
				SetConsoleTextAttribute(hc, 64);
				cout << "ERROR: Unable to open file." << endl;
				SetConsoleTextAttribute(hc, 6);
			}
			else {
				while (getline(inputFileA, lineA)) {   //find username and password in admin.txt file
					size_t pos = lineA.find(",");
					string usernameA = lineA.substr(0, pos);
					string passwordA = lineA.substr(pos + 1);

					if (usernameA == inUsernameA && passwordA == inPasswordA) {   //find username and password match
						countA = 1;
					}
				}
				if (countA == 1) {
					cout << endl;
					SetConsoleTextAttribute(hc, 6);
					cout << "                                                          ";
					SetConsoleTextAttribute(hc, 175);
					cout << "Your login is successful. Welcome back, " << inUsernameA << "!" << endl;
					SetConsoleTextAttribute(hc, 6);
					cout << endl << endl << endl;
					cout << "                                                          ";
					system("PAUSE");

					aModule();

					validLoginA = true;
				}
				else {
					SetConsoleTextAttribute(hc, 6);
					cout << "                                                          ";
					SetConsoleTextAttribute(hc, 64);
					cout << "ERROR: Username or password is incorrect.";     //check validity of username and password
					SetConsoleTextAttribute(hc, 6);
					cout << endl << endl << endl;
					
					validLoginA = false;
					attemptsA++;        //increase number of attempts done until maximum limit of 3 attempts
				}
				inputFileA.close();
			}
			cout << endl;

			if (validLoginA) {
				break;       //stop once both username and password is correct
			}
			else if (attemptsA == maxAttemptsA) {   //when exceeded the limit of attempts
				SetConsoleTextAttribute(hc, 6);
				SetConsoleTextAttribute(hc, 0x07);
				cout << "                                                          ";
				SetConsoleTextAttribute(hc, 64);
				cout << "You've tried to sign in too many times. Try again later.";
				SetConsoleTextAttribute(hc, 6);
				cout << endl;
				cout << "                                                          ";
				system("PAUSE");
				system("cls");
				main();
			}
			inputFileA.clear();
			inputFileA.seekg(0, ios::beg);
		}
	}
	else if (adminSelect == "2") {    //go back to main menu
		system("cls"); 
		main();
	}
	else {    //error checking for invalid input
		SetConsoleTextAttribute(hc, 0x07);  
		cout << "                                                                ";
		SetConsoleTextAttribute(hc, 64);
		cout << "Invalid choice. Please try again." << endl;
		SetConsoleTextAttribute(hc, 6);
		cout << endl;
		cout << "                                                       ";
		system("PAUSE");
		cout << "                                                                ";
		adminLogin();
	}
}

void aModule() {
	system("cls");
	cinemaLogo();
	SetConsoleTextAttribute(hc, 6);

	bool adminValidChoice = false;
	string adminChoice;

	cout << endl;
	cout << "                                                       ";
	cout << "Would you like to" << endl;
	cout << "                                                       ";
	cout << "1. Add movie(s)" << endl;
	cout << "                                                       ";
	cout << "2. Delete movie(s)" << endl;
	cout << "                                                       ";
	cout << "3. View movie details" << endl;
	cout << "                                                       ";
	cout << "4. View customer transactions" << endl;
	cout << "                                                       ";
	cout << "5. Exit" << endl;

	while (!adminValidChoice) { //prompt user to input choice
		cout << endl;
		cout << "                                                       ";
		cout << "Please enter your choice: ";
		cin >> adminChoice;
		if (adminChoice == "1") {
			adminValidChoice = true;
			adminAdd();    //go to add movie page
			break;
		}
		else if (adminChoice == "2") {
			adminValidChoice = true;
			adminDelete();    //go to delete movie page
			break;
		}
		else if (adminChoice == "3") {
			adminValidChoice = true;
			movieDetail();    //go to view movie details page
			system("cls");
			aModule();
		}
		else if (adminChoice == "4") {
			adminValidChoice = true;
			system("cls");
			receipt();      //go to view customer transactions page
			break;
		}
		else if (adminChoice == "5") {
			adminValidChoice = true;
			main();      //go back to main menu
			break;
		}
		else {   //error checking
			adminValidChoice = false;
			SetConsoleTextAttribute(hc, 0x07);
			cout << "                                                       ";
			SetConsoleTextAttribute(hc, 64);
			cout << "ERROR: Invalid choice. Please try again.\n";
			SetConsoleTextAttribute(hc, 6);
		}
	}
}

void addMovieInfo(movieInfo info[], int& numberOfMovies) {
	//to append new details to the following files
	ofstream movieInfoFile("showtime.txt", ios::app);
	ofstream movieFile("movie.txt", ios::app);
	ofstream priceFile("price.txt", ios::app);

	char adminAddChoice;
	movieDetails details[100];

	if (movieInfoFile.fail() || movieFile.fail() || priceFile.fail()) {  //error checking for text files
		SetConsoleTextAttribute(hc, 0x07);
		cout << "                                                       ";
		SetConsoleTextAttribute(hc, 64);
		cout << "ERROR: Unable to open file." << endl;
		SetConsoleTextAttribute(hc, 6);
	}
	else {
		cin.ignore();
		do {
			//input new movie details and write to file
			cout << "Enter new movie title: ";
			getline(cin, info[numberOfMovies].movieTitle);
			movieInfoFile << info[numberOfMovies].movieTitle << endl;
			movieFile << info[numberOfMovies].movieTitle << endl;
			priceFile << info[numberOfMovies].movieTitle << endl;
			cout << endl;
		
			cout << "Enter adult ticket price for the movie: ";
			cin >> details[numberOfMovies].ticketPrice;
			movieFile << fixed << setprecision(2) << details[numberOfMovies].ticketPrice << endl;
			priceFile << fixed <<setprecision(2) << details[numberOfMovies].ticketPrice << endl;
			cout << endl;

			cin.ignore();
			cout << "Enter location: ";
			getline(cin, info[numberOfMovies].location);
			movieInfoFile << info[numberOfMovies].location << endl;
			cout << endl;

			cout << "Enter day: ";
			cin.getline(info[numberOfMovies].day, 20);
			movieInfoFile << info[numberOfMovies].day << endl;
			cout << endl;

			cout << "Enter 1st showtime: ";
			getline(cin, info[numberOfMovies].showtime1);
			movieInfoFile << info[numberOfMovies].showtime1 << endl;
			cout << endl;

			cout << "Enter 2nd showtime: ";
			getline(cin, info[numberOfMovies].showtime2);
			movieInfoFile << info[numberOfMovies].showtime2 << endl;
			cout << endl;

			cout << "Enter 3rd showtime: ";
			getline(cin, info[numberOfMovies].showtime3);
			movieInfoFile << info[numberOfMovies].showtime3 << endl;
			cout << endl;

			cout << "Enter 4th showtime: ";
			getline(cin, info[numberOfMovies].showtime4);
			movieInfoFile << info[numberOfMovies].showtime4 << endl;
			cout << endl;

			addMovieDetails(details, numberOfMovies);  //go to another function to input and write other details related to another file

			//increase number of movies
			//keeps track of how many movies there are in the file
			numberOfMovies++;

			SetConsoleTextAttribute(hc, 0x07);
			cout << "                                                       ";
			SetConsoleTextAttribute(hc, 175);
			cout << "New movie added! Do you want to continue adding movies?: ";  //ask user to continue or stop
			SetConsoleTextAttribute(hc, 6);
			cin >> adminAddChoice;
			cin.ignore();
			cout << endl;
		} while (toupper(adminAddChoice) == 'Y');   //continues to add details if 'Y'
		movieInfoFile.close();
		movieFile.close();
		priceFile.close();

		system("cls");
		aModule();
	}
}

void addMovieDetails(movieDetails details[], int& numberOfMovies) {
	ofstream movieFile("movie.txt", ios::app);

	if (movieFile.fail()) { //error checking for text files
		SetConsoleTextAttribute(hc, 0x07);
		cout << "                                                       ";
		SetConsoleTextAttribute(hc, 64);
		cout << "ERROR: Unable to open file." << endl;
		SetConsoleTextAttribute(hc, 6);
	}
	else { //add other details
		movieFile << details[numberOfMovies].movieTitle;
		cout << "Enter movie duration: ";
		cin >> details[numberOfMovies].duration;
		movieFile << details[numberOfMovies].duration << endl;
		cout << endl;

		cin.ignore();
		cout << "Enter movie type: ";
		getline(cin, details[numberOfMovies].movieType);
		movieFile << details[numberOfMovies].movieType << endl;
		cout << endl;

		cout << "Enter language: ";
		getline(cin, details[numberOfMovies].language);
		movieFile << details[numberOfMovies].language << endl;
		cout << endl;

		cout << "Enter subtitle: ";
		getline(cin, details[numberOfMovies].subtitle);
		movieFile << details[numberOfMovies].subtitle << endl;
		cout << endl;

		cout << "Enter synopsis: ";
		getline(cin, details[numberOfMovies].synopsis);
		movieFile << details[numberOfMovies].synopsis << endl;
		cout << endl;
	}
	movieFile.close();
}

void adminAdd() {//add new movie
	string movie;
	movieInfo info[100];
	int numberOfMovies = 0;

	system("cls");
	cinemaLogo();
	SetConsoleTextAttribute(hc, 6);
	cout << endl;
	SetConsoleTextAttribute(hc, 0x07);
	cout << "                                                          ";
	SetConsoleTextAttribute(hc, 207);
	cout << "==========================================" << endl;
	SetConsoleTextAttribute(hc, 0x07);
	cout << "                                                          ";
	SetConsoleTextAttribute(hc, 207);
	cout << "|                Add a movie             |" << endl;
	SetConsoleTextAttribute(hc, 0x07);
	cout << "                                                          ";
	SetConsoleTextAttribute(hc, 207);
	cout << "==========================================" << endl;
	cout << endl << endl;
	SetConsoleTextAttribute(hc, 6);

	addMovieInfo(info, numberOfMovies); //function to add movies
}

void deleteMovieInfo(movieInfo info[], int& numberOfMovies) {
	string movieTitle, lineM;
	bool movieFound = false;
	bool movieExists = false;
	bool adminDeleteChoice = false;
	char continueDelete;

	while (!movieExists) { //while loop to search for movies that exist and do not exist
		cin.ignore();
		cout << endl;
		SetConsoleTextAttribute(hc, 0x07);
		cout << "                                                                ";
		SetConsoleTextAttribute(hc, 207);
		cout << "Enter movie title to delete: ";
		SetConsoleTextAttribute(hc, 6);
		getline(cin, movieTitle);

		//open text files for reading and writing
		ifstream movieInfoFile("showtime.txt");
		ofstream outMovieInfoFile("temp1.txt");
		ifstream movieDetailsFile("movie.txt");
		ofstream outMovieDetailsFile("temp2.txt");
		ifstream priceListFile("price.txt");
		ofstream outPriceListFile("temp3.txt");

		//1st text file
		while (getline(movieInfoFile, lineM)) {
			if (lineM == movieTitle) {
				movieFound = true;

				//skip the next three lines (price, location and day)
				getline(movieInfoFile, lineM);
				getline(movieInfoFile, lineM);
				getline(movieInfoFile, lineM);

				//read the showtimes
				for (int i = 0; i < 4; i++) {
					getline(movieInfoFile, lineM);
					//do not write the showtime to the output file
				}
			}
			else {
				//store the movies that are not to be deleted in a temporary file, temp1.txt
				outMovieInfoFile << lineM << endl;
			}
		}
		movieInfoFile.close();
		outMovieInfoFile.close();

		//2nd text file
		while (getline(movieDetailsFile, lineM)) {
			if (lineM == movieTitle) {
				movieFound = true;

				//ignore the next 6 lines
				getline(movieDetailsFile, lineM);
				getline(movieDetailsFile, lineM);
				getline(movieDetailsFile, lineM);
				getline(movieDetailsFile, lineM);
				getline(movieDetailsFile, lineM);
				getline(movieDetailsFile, lineM);
			}
			else {
				//store the movies that are not to be deleted in a temporary file, temp2.txt
				outMovieDetailsFile << lineM << endl;
			}
		}
		movieDetailsFile.close();
		outMovieDetailsFile.close();

		//3rd text file
		while (getline(priceListFile, lineM)) {
			if (lineM == movieTitle) {
				movieFound = true;

				//ignore the next line
				getline(priceListFile, lineM);
			}
			else {
				//store the movies that are not to be deleted in a temporary file, temp3.txt
				outPriceListFile << lineM << endl;
			}
		}
		priceListFile.close();
		outPriceListFile.close();

		//check if the movie that is to be deleted is found
		if (movieFound) {

			//replace the old file with the new file
			remove("showtime.txt");
			rename("temp1.txt", "showtime.txt");

			remove("movie.txt");
			rename("temp2.txt", "movie.txt");

			remove("price.txt");
			rename("temp3.txt", "price.txt");

			//success message
			SetConsoleTextAttribute(hc, 0x07);
			cout << "                                                                ";
			SetConsoleTextAttribute(hc, 47);
			cout << "Movie deleted successfully." << endl;
			SetConsoleTextAttribute(hc, 6);

			//ask user to continue or stop
			cout << endl;
			cout << "                                                                ";
			SetConsoleTextAttribute(hc, 4);
			cout << "Do you want to delete another movie?: ";
			cin >> continueDelete;
			cout << endl;

			//if yes then continue
			if (toupper(continueDelete) == 'Y') {
				deleteMovieInfo(info, numberOfMovies);
				break;
			}
			else {
				//if no then go back to admin menu
				movieExists = true;
				system("cls");
				aModule();
			}
		}
		else {
			//let the user know that the movie to be deleted does not exist
			cout << endl;
			SetConsoleTextAttribute(hc, 0x07);
			cout << "                                                                ";
			SetConsoleTextAttribute(hc, 64);
			cout << "Movie not found." << endl;
			SetConsoleTextAttribute(hc, 0x07);
			cout << "                                                                ";
			SetConsoleTextAttribute(hc, 64);
			cout << "Please enter a movie that exists." << endl;
			SetConsoleTextAttribute(hc, 0x07);
			cout << "                                                                ";
			SetConsoleTextAttribute(hc, 64);
			cout << "Do you want to continue deleting the movie? [Y/N]: ";
			SetConsoleTextAttribute(hc, 6);
			cin >> continueDelete;
			cout << endl;

			//if yes then continue deleting
			if (toupper(continueDelete) == 'Y') {
				movieExists = false;
			}
			else {
				//if no then go back to admin menu
				movieExists = true;
				aModule();
			}
		}
	}
}

void adminDelete() {
	movieInfo info[100];
	int numberOfMovies = 0;

	system("cls");
	cinemaLogo();
	SetConsoleTextAttribute(hc, 6);
	cout << endl;
	SetConsoleTextAttribute(hc, 0x07);
	cout << "                                                          ";
	SetConsoleTextAttribute(hc, 207);
	cout << "==========================================" << endl;
	SetConsoleTextAttribute(hc, 0x07);
	cout << "                                                          ";
	SetConsoleTextAttribute(hc, 207);
	cout << "|              Delete a movie            |" << endl;
	SetConsoleTextAttribute(hc, 0x07);
	cout << "                                                          ";
	SetConsoleTextAttribute(hc, 207);
	cout << "==========================================" << endl;
	cout << endl << endl;
	SetConsoleTextAttribute(hc, 6);

	deleteMovieInfo(info, numberOfMovies);  //function to delete movies
}

