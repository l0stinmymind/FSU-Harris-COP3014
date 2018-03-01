#include <iostream>

// Function Prototypes=========================================================
// Do NOT change the signature of these function prototypes.
// If you do, your code will not compile with my altered main() function
// I suggest that you copy the prototypes below and then fill them in.
// ----------------------------------------------------------------------------
// Read in a line of text INCLUDING SPACES into a string.
// You may assume that the input will NOT exceed the maxLength available.
// Keep in mind that cin stops reading at a whitespace. See page 318.
void ReadString(char * c, int maxLength);

// Get the length of the string and store it in length
// Hint: How does C++ terminate a string? Look for that character!
void GetStringLength(char * c, int * length);

// PrintString - Just print the string in forward order using cout
void PrintString(char * const c);

// PrintStringBackwards - Print the string in reverse order using cout
void PrintStringBackwards(char * const c);

// Search the string for the test character. Return -1 if not found
int FindIndexOfCharacter(char * c, char testVal);

// Return a pointer to the character at the index given
char * GetValueAtIndex(char * const c, int index);

// Return the ascii integer value of the character at requested index
int GetIntegerValueOfIndex(char * c, int index);

// Print the hexadecimal value of the character at the requested index
void PrintHexValueAtIndex(char * c, int index);

// Make the entire string uppercase
void MakeUpperCase(char * c);

// Make the entire string lowercase
void MakeLowerCase(char * c);

// ============================================================================

// DO NOT REMOVE THESE COMMENTS -- comments that start with @ are actually
// commands to the assessment tool.
//@include(main)
//@addRule(commentAll)
int main()
{
	// Use these variables to test.
	// SIZE could change so make sure your code works with different sizes.
	const int SIZE = 80;
	char ca[SIZE];
	char * pc = ca;
	int fPrints = 0;
	int bPrints = 0;
	int lengthChecks = 0;

	// Your code below
	// =========================



	// =========================
	// Your code above

	std::cout << "Press ENTER";
	std::cin.get();
	return 0;
}
// DO NOT REMOVE THESE COMMENTS -- these comments are actually
// commands to the assessment tool.
//@removeRule(commentAll)

void ReadString(char * c, int maxLength)
{
	std::cout << "Enter a string less than " << maxLength << " characters." << std::endl;
	// computer output requesting user to input in a string
	std::cin.getline(c, maxLength);
	//getline allows for conversion of an entire line of text into a character array
}

void GetStringLength(char * c, int * length)
{
	while (*c != '\0')
	{
		(*length)++;
		c++;
	}
	//since null '\0' signals the end of the string, the while loop will keep going to
	//ensure all characters in the string is read, giving accurate length
	//the incremental increase in pointer length and c helps ensure the right character
	//is read 

}

// You need to provide the rest of the functions
// See Function Prototypes at the top.

void PrintString(char * const c)
{
	std::cout << c;
	// cout the c pointer to be shown on monitor
}

void PrintStringBackwards(char * const c)
{
	if (*c == '\0')
	{
		return;
	}
	// if the counter reaches the end/null character, return will terminate the function
	PrintStringBackwards(c + 1);
	//recursive process to the end of string
	std::cout << *c;
	// pointer c printout
}

int FindIndexOfCharacter(char * c, char testVal)
{
	int i = 0;
	while (*c != '\0') 
	{
		if (*c == testVal) 
		{
			return i;
		}
		i++;
		c++;
	}
	//while c isnt null, the i will come up if a testval matches anywhere in string c
	// if not then -1 is returned
	return -1;
}

char * GetValueAtIndex(char * const c, int index)
{
	return &c[index];
	// returns the value at a specific character in string c 
}

int GetIntegerValueOfIndex(char * c, int index)
{
	int i = c[index];
	return i;
	// returns the value of each character in integer format
}

void PrintHexValueAtIndex(char * c, int index)
{
	std::cout << "HEX= " << std::hex << (int)*(c + index) << std::endl;
	// cout the hex values of characters to monitor
}

void MakeUpperCase(char * c)
{
	while (*c != '\0') 
	{
		if (*c >= 'a' && *c <= 'z') 
		{
			*c = *c - 'a' + 'A';
		}
		c++;
	}
	// while c isnt null and is in between a and z
	// c pointer is replacing lower case a with upper case A
	// incremental increases does this for the rest of the string
}

void MakeLowerCase(char * c)
{
	while (*c != '\0') 
	{
		if (*c >= 'A' && *c <= 'Z') 
		{
			*c = *c - 'A' + 'a';
		}
		c++;
	}
	// while c isnt null and is in between a and z
	// c pointer is replacing upper case A with lower case a
	// incremental increases does this for the rest of the string
}
