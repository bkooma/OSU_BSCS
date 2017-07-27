/*************************************************************************************
** Function name: inputVerification.cpp is the inputVerification function 
** implementation file.
** Author:  Byron Kooima
** Date: 2017/07/02
** Description: CS162 Reusable Input Verification Function
** The inputVerification function bounds the inputs allowed from the user. The function
** requires the cpp file calling it to pass the (InputType, input constraints, failed
** verification message)
**
** Citation: Sections of this code were referenced from
** https://stackoverflow.com/questions/23043210/how-to-have-a-good-validation-to-check-input-is-numeric
***************************************************************************************/

#include <functional>
#include <limits>
#include <cctype>
#include <iostream>
template <class InputType>

/*********************************************************************
** Function:		SafeInput()
** Description:		Modifiable input verification that allows the user
** 					to pass in different data types and verification
** 					arguments (Predicate).
** Parameters:		InputVar			The user entered variable
** 					InputType			Variable type
** 					Predicate			Verification arguments
** 										(i.e. <, >, ==)\
** 					s[]					Passed in error message
** Pre-Conditions:	N/A
** Post-Conditions: Passes by reference the verified value entered by
** 					the user.
*********************************************************************/
void SafeInput(InputType & InputVar, std::function <bool (InputType &)>	Predicate, char s[]) {
	for (;; ) {
		std::cin >> InputVar;

//		if (std::cin.fail()) std::cout << "This is not an int.";

		// Check to see if the input is verified against the arguments
		if (std::cin.good() && Predicate(InputVar)) return;

		// If not, print out the passed in error message
		std::cerr << s;

		std::cin.clear();
		std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
	}
}
