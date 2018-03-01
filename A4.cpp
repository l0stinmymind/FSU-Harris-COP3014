#include <iostream>
#include <iomanip>
#include <ctime>

// DO NOT REMOVE THESE COMMENTS -- comments that start with @ are actually
// commands to the assessment tool.
//@include(main)
//@addRule(commentAll)

int main()
{
	// You can do whatever tests you want in here. When we compile
	// your code we are actually going to remove this main function
	// and substitute our own. Then we are going to test your functions
	// individually.
	std::cout << "Press ENTER to exit\n";
	std::cin.ignore(80, '\n');
	std::cin.get();
	return 0;
}
// DO NOT REMOVE THESE COMMENTS -- these comments are actually
// commands to the assessment tool.
//@removeRule(commentAll)

// Oops! I accidentally did this one for you.
// Don't forget to copy the prototype down here,
// remove the semicolon, add the curly braces,
// and implement the functionality.

void seedRNG(int seed)
{
	srand(seed);
}

int getRand(int min, int max)
{
	int randNum = rand() % (max - min + 1) + min;
	return randNum;
}

int getMin(int a, int b, int c)
{
	int minNum;
	if (a > c && b > c)
	{
		minNum = c;
	}
	else if (a > b && c > b)
	{
		minNum = b;
	}
	else
	{
		minNum = a;
	}
	return minNum;
}

void getMin(int a, int b, int c, int & min)
{
	if (a > c && b > c)
	{
		min = c;
	}
	else if (a > b && c > b)
	{
		min = b;
	}
	else
	{
		min = a;
	}
}


int getMax(int a, int b, int c)
{
	int maxNum;
	if (a < c && b < c)
	{
		maxNum = c;
	}
	else if (a < b && c < b)
	{
		maxNum = b;
	}
	else
	{
		maxNum = a;
	}
	return maxNum;
}

void getMax(int a, int b, int c, int & max)
{
	if (a < c && b < c)
	{
		max = c;
	}
	else if (a < b && c < b)
	{
		max = b;
	}
	else
	{
		max = a;
	}
}

void getMinMax(int a, int b, int c, int & min, int & max)
{
	if (a > c && b > c)
	{
		min = c;
	}
	else if (a > b && c > b)
	{
		min = b;
	}
	else
	{
		min = a;
	}
	if (a < c && b < c)
	{
		max = c;
	}
	else if (a < b && c < b)
	{
		max = b;
	}
	else
	{
		max = a;
	}

}

void formatDouble(double d, int numDecimals)
{
	numDecimals++;
	std::cout << std::setprecision(numDecimals) << d;
}

bool isEven(int x)
{
	bool even;
	if (x % 2 == 0)
	{
		even = true;
	}
	else
	{
		even = false;
	}
	return even;
}

void printChar(char c, int numTimes)
{
	for (int counter = 0; counter <= numTimes; counter++)
	{
		std::cout << c;
	}
}

double fToC(double f)
{
	double celsius = (f - 32) * 5 / 9;
	return celsius;
}

double cToF(double c)
{
	double fahrenheit = c * 9 / 5 + 32;
	return fahrenheit;
}
// You must implement every single function requested or your
// code will not compile. If you cannot figure out how to
// get it to work, implement it anyway with dummy values.
// We can't test your code if it doesn't compile.