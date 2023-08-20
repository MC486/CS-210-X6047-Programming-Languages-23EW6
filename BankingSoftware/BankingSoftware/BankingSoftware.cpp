/**	Name: Michael Crevier
*	Date: 07/30/23
*	Prog: Banking Software
*	Desc: This program will take input from the user to get details on an investment account.  It will receive the
*		  initial deposit, the interest rate, the monthly deposit amount and the length in years from the user and
*		  calculate the compound interest for the input parameters, and will then output a chart detailing the
*		  yield schedule for the user's account.
**/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

/* Declare Variables */
double initialInvestment, monthlyDeposit, annualInterest, // these variables will hold the user inputs for the investment terms
	   amountInterest, amountTotal, yearToDateInterest,   // these variables will hold the calculated values for output to user
	   months, years;									  // these variables will hold the user input for the length of the investment
bool   keepGoing = true;								  // keepGoing will hold the choice of the user to repeat the program or not


// This function will create new line for whitespace purposes (slightly redundant but easier to read in main())
void whiteSpace() {
	cout << endl;
}

// This function converts input from years to months
void yearsToMonths(int t_years) {
	months = t_years * 12;	// t_years is a function parameter to bring in years variable from other functions
}

// This function will print the header for the user input table
void dataInputHeader() {
	int m_columns = 36;	// this will set the number of columns where ASCII * lines will be drawn

	string str = " Data Input "; // str will hold the header text to be embedded into lower ASCII * line

	double m_equation = (m_columns / 2) - (str.length() / 2); // m_equation will hold a formula to calculate length of one half of the ASCII * line minus half length of embedded text

	whiteSpace();
	whiteSpace();
	for (int i = 0; i < m_columns; ++i) {	// first * line is drawn at length m_columns
		cout << "*";
	}
	whiteSpace();
	for (int i = 0; i < m_equation; ++i) { // second * line has half drawn prior to the header text
		cout << "*";
	}
	cout << str;	// header text is printed in the middle

	for (int i = 0; i < m_equation; ++i) { // second * line has another half drawn after the header text
		cout << "*";
	}
	whiteSpace();
}

// This function will display the initial format of input to educate user
void dataInputInitDisp() {
	dataInputHeader(); // dataInputHeader() prints the header for the data input display

	cout << "Initial Investment Amount: $"; // print text prompting Starting balance of the account
	whiteSpace();

	cout << "Monthly Deposit: $"; // print text prompting monthly addition to balance
	whiteSpace();

	cout << "Annual Interest: %"; // print text prompting the annual rate of interest to be accumulated to balance
	whiteSpace();

	cout << "Number of years: "; // print text prompting the length of the investment
	whiteSpace();

	system("PAUSE"); // will keep information on the screen and await any input from user to continue
}

// this function will take an input prompt as a parameter and validate the input from the user as a non-negative number
double inputValidation(string t_str) {
	double t_input;
	cout << t_str;
	while (!(cin >> t_input)) { // if input does not successfully assign to double variable

		cin.clear(); // clear the input buffer
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "Enter a valid, positive number\n"; // display error message asking for valid input
		whiteSpace();
		cout << t_str; cout << t_str; // re-print prompt and loop back to input
	}
	while (t_input < 0) { // if input is negative

		cin.clear(); // clear the input buffer
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "Enter a valid, positive number\n"; // display error message asking for valid input
		whiteSpace();
		cout << t_str; // re-print prompt
		cin >> t_input; // take new input for t_input
	}
	
	return t_input; // return the user input
}

// this function will call inputValidation() function to prompt user and get validated input for each input variable
void dataInput() {
	dataInputHeader(); // dataInputHeader() prints the header for the data input display

	initialInvestment = inputValidation("Initial Investment Amount: $"); // initialInvestment is assigned to the returned validated double input from user for starting $ amount

	monthlyDeposit = inputValidation("Monthly Deposit: $"); // monthlyDeposit is assigned to the returned validated double input from user for continual $ amount added to account

	annualInterest = inputValidation("Annual Interest: %"); // annualInterest is assigned to the returned validated double input from user for interest rate multiplier

	years = inputValidation("Number of years: "); // years is assigned to the returned validated double input from user for length of investment (in years)

	// not used // yearsToMonths(years); // yearsToMonths takes the validated input years and multiplies it by 12, then assigns that value to months variable

	system("PAUSE"); // will keep information on the screen and await any input from user to continue
}

// this function will display the calculated investment yield schedule according to user inputted parameters
void monthlyReturnChart(double t_monthlyDeposit) {

	/* Header */
	int m_columns = 75; // this will set the number of columns where ASCII lines will be drawn

	whiteSpace();
	whiteSpace();

	if (t_monthlyDeposit != 0) {  // if there is a monthly deposit, t_monthlyDeposit != 0 and we will print 'With Additional Monthly Deposits'
		cout << "\t" << "Balance and Interest With Additional Monthly Deposits";
	}
	else {						// if there is not a monthly deposit, t_monthlyDeposit = 0 and we will print 'Without Additional Monthly Deposits'
		cout << "\t" << "Balance and Interest Without Additional Monthly Deposits";
	}
	whiteSpace();

	for (int i = 0; i < m_columns; ++i) { // first = line is drawn at length m_columns
		cout << "=";					
	}
	whiteSpace();

	// print out headers for data columns for length of investment, balance at year end, and interest at year end, spaced out evenly across ASCII lines
	// this will go between ASCII lines
	cout << " Year" << "\t\t" << "Year End Balance" << "\t\t" << "Year End Earned Interest"; 
	whiteSpace();

	for (int i = 0; i < m_columns; ++i) { // second - line is drawn at length columns
		cout << "-";
	}
	whiteSpace();

	/* Yearly Outputs*/

	amountTotal = initialInvestment; // set the initial amountTotal to intialInvestment
	yearToDateInterest = 0; // initialize yearToDateInterest to 0 for start of calculations

	// print out starting values for year 0 for each data column (with consistent tab spacing)
	cout << "0" << "\t\t" << "$" << fixed << setprecision(2) << amountTotal << " \t\t\t\t " << "$" << yearToDateInterest;
	whiteSpace();
	whiteSpace();

	for (int i = 0; i < years; i++) {  // first for loop will iterate every year of the investment

		for (int j = 0; j < 12; j++) { // second for loop will iterate for each month within each year for length of investment

			// formula for monthly compounding interest is 1/12th of annualInterest multiplied by the current total investment plus this month's deposit
			amountInterest = (amountTotal + monthlyDeposit) * ((annualInterest / 100) / 12); 

			yearToDateInterest += amountInterest; // interest earned this month is added to total accumulated interest

			amountTotal += monthlyDeposit + amountInterest; // this month's deposit and this month's earned interest added to total balance of account 
		}
		// at end of every yearly iteration, print calculated values for year i+1 at consistent tab-spacing with header columns
		cout << (i + 1) << "\t\t" << "$" << fixed << setprecision(2) << amountTotal << " \t\t\t\t " << "$" << yearToDateInterest;
		whiteSpace();
		whiteSpace();
	}

}

// this function will print a farewell message to the user upon successful completion of program
void goodbye() { 
	whiteSpace();
	cout << "You have successfully completed the program.  Thank you and come again soon!";  // print farewell message to user
	whiteSpace();
}

// this function will validate a user choice to continue or end program
void endProgram() {
	string userInput; // userInput will hold user choice
	whiteSpace();

	cout << "Press any key to test another investment or type 'q' to quit."; // prompt user to continue program or press q to quit
	whiteSpace(); 

	cin >> userInput; // get userInput from user

		// validate the user input
		if (userInput == "q" || userInput == "Q") { // if user input is the letter q
			keepGoing = false;						// set keepGoing to false and will end the main() loop
			goodbye();								// call goodbye() function to display farewell to user
		}
		else {				  // if userInput is anything but the letter q
			keepGoing = true; // set keepGoing to true and continue main() loop
		}
}

/*
*	main() function executes the program
*/
int main() {

	dataInputInitDisp();  // call function to display the initial data input form to educate user on input

	do { // do-while loop will run until user presses q when prompted and sets keepGoing to false

		dataInput(); // call dataInput() function to get and validate user input for each of the user input variables

		// call monthlyReturnChart() to use input variables to calculate and display yearly investment yield chart
		// monthlyDeposits parameter will be validated to change display from "without monthly deposits" to "with monthly deposits" as appropriate
		monthlyReturnChart(monthlyDeposit);

		endProgram(); // call endProgram() function to prompt and validate user choice to continue or end program

	} while (keepGoing == true); // when keepGoing is false, loop will end, otherwise user will be able to start again to test more input values

	return 0;
}