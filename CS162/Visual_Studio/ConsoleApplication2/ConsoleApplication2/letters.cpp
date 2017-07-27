/*********************************************************************************************
** Program name: letters.cpp is the letters function implementation file.
** Author:  Byron Kooima
** Date: 2017/07/08
** Description: CS162 Week2 Lab2
** The letters program allows the user to select an existing text file. The program 
** reads the file and runs the count_letters function to read in the paragraphs one 
** character at a time. It then counts the frequency of each letter in each individual
** paragraph. The letter frequency numbers for a single paragraph are then passed to 
** the output_letters function to create a separate output file for each paragraph.
**
** Citation: Sections of this code were referenced from
** https://stackoverflow.com/questions/17628657/function-to-count-all-characters-in-a-string-c
***********************************************************************************************/

#include<iostream>
#include<fstream>
#include<string>
#include<array>
#include<vector>

// Function prototypes
void count_letters(std::ifstream &, int *);
void output_letters(std::ofstream &, int *);

int main() {

	// Initialize the count array with 0's
	int cntArray[256] = { 0 };
	std::string inFileName;

	// Prompt the user for an input file name
	std::cout << "Please enter the name of the txt input file: \n";
	std::cin >> inFileName;

	// Set ifstream parameter to user file name
	std::ifstream inFile(inFileName);

	// Check to see if the file can be opened
	if (inFile.is_open()) {
		
		// Send file and array to function
		count_letters(inFile, cntArray);

		// Close the input file
		inFile.close();
	}
	// Exit program if the file cannot be opened
	else std::cout << inFileName << " cannot be opened. Please try again\n";

	return 0;
}

// count_letters function to determine frequency of letters in a paragraph
void count_letters(std::ifstream &inFile, int *asciiArray) {
	std::string outFileName;
	int pCount = 0;

	// Use getline to parse the input file for each paragraph
	for (std::string line; std::getline(inFile, line);)
	{
		// Step through the paragraph (line)
		for (auto i = line.begin(); i != line.end(); ++i)
		{
			// Increment the corresponding ascii array cell using a pointer to the current i letter
			asciiArray[tolower((unsigned char)*i)]++;
		}
		
		// Increment the paragraph counter
		pCount++;

		// Prompt the user for the output file name
		std::cout << "For paragraph: " << pCount << " Please enter the name for the output file:\n";
		std::cin >> outFileName;
		
		// Set ofstream parameter to user file name
		std::ofstream outFile(outFileName);

		// Send the file name and array to the output_letters function
		output_letters(outFile,asciiArray);

		// Re-initialize the array back to 0's
		for (int j = 0; j<256;j++)
			asciiArray[j] = 0;
	}
}

void output_letters(std::ofstream &outFile, int *asciiArray) {
	// Store the alphabet to a string
	std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
	// Create a vector to capture just the lower case ascii letters
	std::vector<size_t> countLetters;

	// Make sure the file can be opened
	if (outFile.is_open()) {
		// Step through the alphabet string
		for (auto i = alphabet.begin(); i != alphabet.end(); ++i)
		// Push the ascii counts to the vector starting at 'a'
		countLetters.push_back(asciiArray[(unsigned char)*i]);
	}
	// Output the 26 values to the user defined file
	for (int i = 0; i < 26; i++)
	outFile << alphabet[i] << " " << countLetters[i] << "\n";

	// Clear the vector
	countLetters.clear();

	// Close the output file
	outFile.close();
}
