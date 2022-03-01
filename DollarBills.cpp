#include <iostream> 
#include <cmath>
using namespace std;

int dollarbills (double amount, double& tendered);
int quarters (double& remaining);
int dimes (double& remaining);
int nickels (double& remaining);
int pennies (double& remaining);

int main(){
	cout << endl;
	int dollarsG, quartersG, dimeG, pennyG, nickelsG;
	double checkoutAmount, tenderedAmount, remainder;

	cout << "What is the checkout amount ? $";
	cin >> checkoutAmount;
	//checkoutAmount = 12.49;
	// cout << checkoutAmount << endl;

	cout << "What is the amount tendered ? $";
	cin >> tenderedAmount;
	//tenderedAmount = 20;
	// cout << tenderedAmount << endl;

	cout << endl;

	// Calculates the amout of dollars that should be returned
	dollarsG = dollarbills(checkoutAmount, tenderedAmount);
	// cout << "The amount of dollars is: " << dollarsG << endl;

	// To midigate the floating point problem lets mutiple the coins by 100
	tenderedAmount = tenderedAmount * 100;
	checkoutAmount = checkoutAmount * 100;
	// cout << "The tendered amount for coin shit is: " << tenderedAmount << endl;
	// cout << "The checkout amount for coin shit is: " << checkoutAmount << endl;


	remainder = tenderedAmount - checkoutAmount - (dollarsG * 100);
	// cout << "Is this correct? " << (remainder == (tenderedAmount - checkoutAmount - dollarsG)) << endl;
	// cout << "Now the amount left that needs to be given back is: " << remainder << endl;
	
	// Calculates the amount of quarters that should be returned
	quartersG = quarters(remainder);
	// cout << "We will now give back " << quartersG << " quarters or " << quartersG * 25 << " cents" << endl;
	// cout << "The remainder that still needs to be given back is: " << remainder << endl;
	
	// Calculates the amouhnt of dimes that should be returned
	dimeG = dimes(remainder);
	// cout << "We will now give back " << dimeG << " dimes or " << dimeG * 10 << " cents" << endl;
	// cout << "The remainder that still needs to be given back is: " << remainder << endl;

	// Calculates the amount of nickels that should be returned
	nickelsG = nickels(remainder);
	// cout << "We will now give back " << nickelsG << " nickels or " << nickelsG * 5 << " cents" << endl;
	// cout << "The remainder that still needs to be given back is: " << remainder << endl;

	// Calculates the amount of nickels that shoudl be returned
	pennyG = pennies(remainder);
	// cout << "The remainder that still needs to be given back is: " << remainder << endl;
	
	// cout << "We will now give back " << pennyG << " pennies or " << pennyG << " cents" << endl;
	// cout << "The remainder that still needs to be given back is: " << remainder << endl;

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
	
	// cout << remaining << endl;
	// cout << (remaining == remaining) << endl;
	// cout << (remaining == 0.01) << endl;


	// if(remaining == 0.01){
	// 	// cout << "This has been printed" << endl;
	// 	remaining = 0;
	// 	return pennies2return + 1;
	// }	

	while(remaining - 1 >= 0){
		remaining = remaining - 1;
		++pennies2return;

		// if(remaining == .01){
		// 	remaining = 0;
		// 	return pennies2return + 1;
		// }	
		
	}

	return pennies2return;
}

int nickels(double& remaining) {
	
	int nickels2return = 0;
	
	// if(remaining == 5){
	// 	remaining = 0;
	// 	return nickels2return + 1;
	// }

	while(remaining - 5 >= 0){
		remaining = remaining - 5;
		++nickels2return;
		
		// if(remaining == 5){
		// 	remaining = 0;
		// 	return nickels2return + 1;
		// }
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



