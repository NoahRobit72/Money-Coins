#include <iostream> 
#include <cmath>
using namespace std;

//
// Script to calculate the denominatinos for a transaction
//

int dollarbills (double amount, double& tendered);
int quarters (double& remaining);
int dimes (double& remaining);
int nickels (double& remaining);
int pennies (double& remaining);

int main(){
	cout << endl;
	int dollarsG, quartersG, dimeG, pennyG, nickelsG;
	double checkoutAmount, tenderedAmount, remainder;
	
	// Command Prompts
	cout << "What is the checkout amount ? $";
	cin >> checkoutAmount;
	cout << "What is the amount tendered ? $";
	cin >> tenderedAmount;

	cout << endl;

	// Calculates the amout of dollars that should be returned
	dollarsG = dollarbills(checkoutAmount, tenderedAmount);

	// To midigate the floating point problem lets mutiple the coins by 100
	tenderedAmount = tenderedAmount * 100;
	checkoutAmount = checkoutAmount * 100;

	remainder = tenderedAmount - checkoutAmount - (dollarsG * 100);

	// Calculates the amount of quarters that should be returned
	quartersG = quarters(remainder);
	// Calculates the amouhnt of dimes that should be returned
	dimeG = dimes(remainder);
	// Calculates the amount of nickels that should be returned
	nickelsG = nickels(remainder);
	// Calculates the amount of nickels that shoudl be returned
	pennyG = pennies(remainder);

	cout << "You should return ";
	if(dollarsG != 0) {
		cout << dollarsG << " dollar bills";
		if(nickelsG != 0 || pennyG != 0 || dimeG != 0 || quartersG != 0) cout << ", ";
	}
	if(quartersG != 0) {
		cout << quartersG << " quarters";
		if(nickelsG != 0 || pennyG != 0 || dimeG != 0) cout << ", ";
	}
	if(dimeG != 0) {
		cout << dimeG << " dimes";
		if(nickelsG != 0 || pennyG != 0) cout << ", ";
	}	
	if(nickelsG != 0){
		 cout << nickelsG << " nickels"; 
		if(pennyG != 0) cout << ", ";
	}
	if(pennyG != 0) cout << pennyG << " pennies"; 
	cout << "." << endl;

	cout << endl;
	return 0;
}

int pennies(double& remaining) {
	
	int pennies2return = 0;

	while(remaining - 1 >= 0){
		remaining = remaining - 1;
		++pennies2return;
	}

	return pennies2return;
}

int nickels(double& remaining) {
	
	int nickels2return = 0;
	while(remaining - 5 >= 0){
		remaining = remaining - 5;
		++nickels2return;
	}

	return nickels2return;
}

int dimes(double& remaining) {

	int dimes2return = 0;
	while(remaining - 10 >= 0){
		remaining = remaining - 10;
		++dimes2return;
	}
	
	return dimes2return;	
}

int quarters(double& remaining){
	
	int quarters2return = 0;
	while(remaining - 25 >= 0){
		remaining = remaining - 25;
		++quarters2return;
	}	

	return quarters2return;
}

int dollarbills(double amount, double& tendered){
	
	double tempten = tendered;
	double dollar2return;
	
	dollar2return = floor(tempten - amount); 

	return dollar2return;
}



