// Name        : Data.cpp

#include <iostream>
#include <cmath>
#include <functional>   // std::modulus, std::bind2nd
#include <algorithm>    // std::transform
const float pi = 3.1415;
const float euler = 2.718281828459;
using namespace std;

/*
 =========================================================================================================
 Exercises:

 1.  Declare one of every type of variable that you know, give all of them values using keyboard input,
 and finally try to print their values to the screen.
 2.  Make a kilograms to pounds converter; given an input in kilograms,
 the programme should print the corresponding number of pounds.
 Try to do the same for meters to feet and liters to gallons.
 3.  Calculate the area and circumference of a circle, given its radius as input.
 4.  Calculate and print f(1), f(2), f(3), f(4), and f(5) for f(x) = e^x(e is Euler's number).
 5.  Make a programme that solves equations of the form ax+b=0, given a and b as input.
 6.  Find out what you would need to make a programme that solves quadratic equations (ax^2+bx+c=0) instead.
 If this is your first venture into programming, then you don't know all that you need yet,
 but try to find out what you are missing.
 7.  Make a programme that, given a year as input, prints the century as output.
 E.g. given 2014 as input, the output should be 21, given 1945 as input, the output should be 20.
 8.  Make a programme that, given an even number as input, prints the number 0 as output,
 and given an odd number as input prints 1 as output.
 9.  Can you also reverse it, such that you get 0 for odd numbers and 1 for even numbers.
 Hint: Both things are perfectly doable only using things that you learned today.
 ==========================================================================================================
 */

void declareDataType() {

	int firstInteger;
	char secondInteger;
	float firstFloat;
	double firstDouble;
	string firstString;

	//Asks user to input a int, outputs inserted int.
	cout << "Insert an integer of type int: ";
	cin >> firstInteger;
	cout << "The int input was: " << firstInteger << endl;

	//Asks user to input a char, outputs inserted char.
	cout << "Insert a integer of type char: ";
	cin >> secondInteger;
	cout << "The char input is was: " << secondInteger << endl;

	//Asks user to enter a float, outputs inserted float
	cout << "Insert a float: ";
	cin >> firstFloat;
	cout << "The float is now: " << firstFloat << endl;

	//Asks user to enter a double float, outputs inserted double float
	cout << "Insert a double: ";
	cin >> firstDouble;
	cout << "The double input is now: " << firstDouble << endl;

	//Asks user to enter a string, outputs inserted string
	cout << "Insert a string: ";
	cin >> firstString;
	cout << "The string input is now: " << firstString << endl;

	cout << "The end" << endl << endl;

}

int askForSelection() {
	cout << "Enter your choice: ";

	int selection;
	cin >> selection;
	return selection;
}

void converter(string from, string to, float factor) {

	cout << "Enter " << from << ": ";

	float input;
	cin >> input;

	float result;
	result = input * factor;
	cout << input << " " << from << " is " << result << " " << to << "." << endl
			<< endl;
}


void yearToCentury() {
		float year;
		int result;
		
		cout << "Enter year you want to converted: ";
		cin >> year;
		cout << endl;

		result = ceil((year+1)/100);
		cout << "Result = " << result << ".  Century" << endl;
}

void printConverterMenu() {
	cout << endl << "=======================================" << endl
			<< "Converter menu" << endl
			<< "Enter 1 to convert kilograms to pounds" << endl
			<< "Enter 2 to convert meters to feet" << endl
			<< "Enter 3 to convert liters to gallons" << endl
			<< "Enter 4 to convert year to century" << endl
			<< "Enter 5 to EXIT to parent menu" << endl
			<< "=======================================" << endl << endl;

}

bool chooseConverter(int selection) {
	switch (selection) {
	case 1:
		converter("kilogram", "pound", 2.20462262);
		break;
	case 2:
		converter("meters", "feet", 3.2808399);
		break;
	case 3:
		converter("liters", "gallons", 0.2641072052);
		break;
	case 4:
		yearToCentury();
		break;
	case 5:
		cout << "Back to main menu" << endl << endl;
		return true;
		break;
	default:
		cout << "Wrong selection" << endl;
		break;
	}
	return false;
}

void converterMenu() {
	bool quit = false;
	int selection;

	while (!quit) {

		printConverterMenu();

		selection = askForSelection();
		quit = chooseConverter(selection);

	}
}

void rTAAC() {
	float radius, circumference, diameter, area;
	cout << "enter radius: ";
	cin >> radius;

	diameter = radius * 2;
	circumference = 2 * pi * radius;
	area = pi * pow(radius, 2);

	cout << "The circle has a radius of " << radius << ", a diameter of "
			<< diameter << ", an area of " << area << " and a circumference of "
			<< circumference << endl;

}

void printMainMenu() {
	cout << "=====================================" << endl << "Main menu"
			<< endl << "Enter 1 Declare types of variables." << endl
			<< "Enter 2 Converter menu." << endl << "Enter 3 Math menu." << endl
			<< "Enter 4 EXIT program." << endl
			<< "=====================================" << endl << endl;
}

void printMathMenu() {
	cout << "==============================================================="
			<< endl << "Math menu" << endl
			<< "Enter 1 to calculate the area and circumference of a circle." << endl
			<< "Enter 2 to calculate and print f(x) = e^x(e is Euler's number)." << endl 
			<< "Enter 3 to solve equations of the form ax+b=0" << endl
			<< "Enter 4 to solve quadratic equations (ax^2+bx+c=0)" << endl
			<< "Enter 5 odd or even number check" << endl
			<< "Enter 6 to EXIT to main menu." << endl
			<< "==============================================================="
			<< endl << endl;
}

void eulerProblem() {
	float x, result;
	cout << "Enter x value: ";
	cin >> x;

	result = pow(euler, x);

	cout << "Result of f(" << x << ") = " << result << endl << endl;
}

void simpleLinearEquation() {
	float a, b, result;

	cout << "Enter a value: " << endl;
	cin >> a;

	cout << "Enter b value: " << endl;
	cin >> b;

	/*
	 0 = a*x+b
	 -b = a*x
	 -b/a = x
	 */
	result = -b / a;
	cout << "The result of equation: " << result << endl;
}

void quadraticEquations() {

	{
		float a, b, c;
		float discriminant;
		float x1, x2;

		cout << "enter the value of a: " << endl;
		cin >> a;

		cout << "enter the value of b: " << endl;
		cin >> b;

		cout << "enter the value of c: " << endl;
		cin >> c;

		cout << endl;

		discriminant = ((b * b) - 4 * a * c);

		if (discriminant > 0) {
			x1 = (-1 * b + sqrt(discriminant)) / (2 * a);
			x2 = (-1 * b - sqrt(discriminant)) / (2 * a);
		} else if (discriminant == 0) {
			x1 = x2 = (-1 * b) / (2 * a);
		} else {
			discriminant = -1 * discriminant;
			cout << "x1 = x2 = " << (-1 * b) / (2 * a) << "+ i"
					<< sqrt(discriminant) / (2 * a) << endl;
			return;
		}

		cout << "x1 = " << x1 << endl;
		cout << "x2 = " << x2 << endl;
	}
}

void oddOrEvenNumber() {
 
		cout <<  "odd or even" << endl;
}

bool chooseMathProblem(int selection) {
	switch (selection) {
	case 1:
		rTAAC();
		break;

	case 2:
		eulerProblem();
		break;

	case 3:
		simpleLinearEquation();
		break;

	case 4:
		quadraticEquations();
		break;

	case 5:
		oddOrEvenNumber();
		break;

	case 6:
		cout << "Back to main menu" << endl << endl;
		return true;
		break;
	default:
		cout << "Wrong selection" << endl;
		break;
	}
	return false;
}

void mathMenu() {
	bool quit = false;
	int selection;

	while (!quit) {
		printMathMenu();

		selection = askForSelection();
		quit = chooseMathProblem(selection);
	}
}

int main() {
	bool quit = false;

	int selection;
	while (!quit) {
		printMainMenu();

		selection = askForSelection();

		switch (selection) {

		case 1:
			declareDataType();
			break;

		case 2:
			converterMenu();
			break;

		case 3:
			mathMenu();
			break;

		case 4:
			cout << "Program terminated" << endl;
			quit = true;
			break;

		default:
			cout << "Wrong choice, try again" << endl;
			break;
		}

	}

}

