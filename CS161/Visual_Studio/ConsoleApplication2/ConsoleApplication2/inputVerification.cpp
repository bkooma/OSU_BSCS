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
#include <iostream>
template <class InputType>
void SafeInput(InputType & InputVar, std::function <bool (InputType &)>	Predicate, char s[]) {
	for (;; ) {
		std::cin >> InputVar;

//		if (!isdigit(InputVar)) std::cout << "This in not an int.";

		if (std::cin.good() && Predicate(InputVar)) return;

		std::cerr << s;

		std::cin.clear();
		std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
	}
}