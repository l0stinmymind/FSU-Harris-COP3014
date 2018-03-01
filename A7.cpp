*******************************

#include <iostream>
#include <ostream>
#include <istream>
#include <ostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>

bool GetInputFileStream(std::ifstream * fin, std::string filename);
void GetOutputFileStream(std::ofstream * fout, std::string filename);
void SetGetPointer(std::istream & fin, int location);
void SetPutPointer(std::ostream & fout, int location);
void AnalyzeFile(std::istream & fin,
	int & numUsed,
	int & numNew,
	double & newTotalPrice,
	double & newTotalMileage,
	double & usedTotalPrice,
	double & usedTotalMileage);
void PrintLine(std::ostream & sout, std::string s);
void PrintNew(std::istream & fin, std::ostream & fout);
void PrintUsed(std::istream & fin, std::ostream & fout);
void PrintStatistics(std::ostream & fout,
	int numUsed,
	int numNew,
	double newTotalPrice,
	double newTotalMileage,
	double usedTotalPrice,
	double usedTotalMileage);
std::string FormatCarInfo(std::string year,
	std::string make,
	std::string model,
	double price,
	double mileage);

// DO NOT REMOVE THESE COMMENTS -- these comments are actually
// commands to the assessment tool.
//@include(main)
//@addRule(commentAll)
int main()
{
	// You will need to put the provided cars.txt into
	// the working directory of this program
	
	std::string year;
	std::string make;
	std::string model;
	double price;
	double mileage;
	std::string category;
	std::ifstream fin; // 'f'ile in - fin
	std::string filename = "cars.txt";
	bool isOpen = GetInputFileStream(&fin, filename);
	std::cout << filename << " open: ";
	std::cout << std::boolalpha << isOpen << std::endl;
	while (fin >> year &&
		fin >> make &&
		fin >> model &&
		fin >> price &&
		fin >> mileage &&
		fin >> category)
	{
		std::string s = FormatCarInfo(year, make, model, price, mileage);
		PrintLine(std::cout, s);
	}	std::cout << "Press ENTER to continue";
	std::cin.get();
	return 0;

}
// DO NOT REMOVE THESE COMMENTS -- these comments are actually
// commands to the assessment tool.
//@removeRule(commentAll)

// The function prototypes are provided above
// Copy them here, remove the semicolons at the end
// Add braces, and fill in the functionality

bool GetInputFileStream(std::ifstream * fin, std::string filename)
{
	std::cout << "Opening file " << filename << std::endl;
	// Prints out the string opening file and also tells user which file is opened. 
	(*fin).open(filename, std::ios::in);
	//pointer open filename for reading
	return (*fin).good();
	// returns true if file is opened successfully
}
void GetOutputFileStream(std::ofstream * fout, std::string filename)
{
	(*fout).open(filename, std::ios::out);
	// opens filename for writting
}void SetGetPointer(std::istream & fin, int location)
{
	fin.seekg(location, std::ios_base::beg);
	// sets the pointer position to location byte starting from the beginning
}void SetPutPointer(std::ostream & fout, int location)
{
	fout.seekp(location, std::ios::beg);
	//set the pointer to the beginning starting going forward at the location byte and overwrite
}void PrintStatistics(std::ostream & fout,
	int numUsed,
	int numNew,
	double newTotalPrice,
	double newTotalMileage,
	double usedTotalPrice,
	double usedTotalMileage)
{
	fout << std::right << std::setw(9) << "Category| "
		<< std::setw(5)
		<< " Number|" << " Total Price|" << " Total Mileage|"
		<< std::endl << std::fixed;
	// starting from right, setting the width of each column

	fout << std::right << std::setw(9) << "New|"
		<< std::setw(8) << numNew << "|"
		<< std::setprecision(0)
		// no decimals
		<< std::setw(12) << newTotalPrice << "|"
		<< std::setw(14) << newTotalMileage << "|"
		<< std::endl;
	//starting from right, sets the position of each character

	fout << std::right << std::setw(9) << "Used|"
		<< std::setw(8) << numUsed << "|"
		<< std::setprecision(0)
		// no decimals
		<< std::setw(12) << usedTotalPrice << "|"
		<< std::setw(14) << usedTotalMileage << "|"
		<< std::endl;
	//starting from right, sets the position of each character
}

void AnalyzeFile(std::istream & fin,
	int & numUsed,
	int & numNew,
	double & newTotalPrice,
	double & newTotalMileage,
	double & usedTotalPrice,
	double & usedTotalMileage)
{
	std::string modelYear, Make, Model, Condition;
	// declaring string variables
	double Price = 0;
	int Mileage = 0;
	// variable to hold each car prices and mileages
	numUsed = 0;
	numNew = 0;
	newTotalPrice = 0;
	newTotalMileage = 0;
	usedTotalPrice = 0;
	usedTotalMileage = 0;
	// initalizing all variables to 0; 
	do
	{
		Condition = "";
		fin >> modelYear >> Make >> Model >> Price >> Mileage >> Condition;
		// the condition sets apart the columns in the text file it is reading. 
		// data is then separated based on the spacing condition
		if (Condition == "used")
		{
			numUsed++;
			usedTotalPrice += Price;
			usedTotalMileage += Mileage;
		}
		// if the car is used, used variables will increase accordingly
		else if (Condition == "new")
		{
			numNew++;
			newTotalPrice += Price;
			newTotalMileage += Mileage;
		}
		// if the car is new, new variables will increase accordingly
	} 
	while (!fin.eof() && !fin.bad());
	// the loop will continue as long as it isnt the end of file and if file open is successful
}

void PrintLine(std::ostream & sout, std::string s)
{
	std::stringstream ss(s);
	// creates a stringstream object ss
	sout << s << std::endl;
	// print out string
}

void PrintNew(std::istream & fin, std::ostream & fout)
{
	std::string modelYear, Make, Model, Condition;
	// declaring string variables
	double Price = 0;
	int Mileage = 0;
	// variable to hold each car prices and mileages

	do
	{
		Condition = "";
		fin >> modelYear >> Make >> Model >> Price >> Mileage >> Condition;
		// see comment above under analyze file
		if (Condition == "new")
		{
			std::string s = FormatCarInfo(modelYear, Make, Model, Price, Mileage);
			PrintLine(fout, s);
			// if the condition matches, then a string in the format listed is created and printed
		}
	} 
	while (!fin.eof() && !fin.bad());

	SetGetPointer(fin, 0);
	// this sets the pointer back to the beginning of the file location
}

void PrintUsed(std::istream & fin, std::ostream & fout)
{
	std::string modelYear, Make, Model, Condition;
	// declaring string variables
	double Price = 0;
	int Mileage = 0;
	// variable to hold each car prices and mileages

	do
	{
		Condition = "";
		fin >> modelYear >> Make >> Model >> Price >> Mileage >> Condition;
		// see comment above under analyze file
		if (Condition == "used")
		{
			std::string s = FormatCarInfo(modelYear, Make, Model, Price, Mileage);
			PrintLine(fout, s);
			// if the condition matches, then a string in the format listed is created and printed
		}
	} while (!fin.eof() && !fin.bad());

	SetGetPointer(fin, 0);
}

std::string FormatCarInfo(std::string year,
	std::string make,
	std::string model,
	double price,
	double mileage)
{
	std::ostringstream out;
	out << year << " ";
	out << make << " ";
	out << model << " ";
	out << price << " ";
	out << mileage;
	return out.str();
	// formats each column as string 
}