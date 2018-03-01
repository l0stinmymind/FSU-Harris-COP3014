

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>

void MainMenu();
void Login();
void ShowInbox(std::string username, std::ostream & sout);
void LoggedInMenu(std::string username);
void RegisterNewUser();
void DeleteUser();
std::string GetUserFile(std::string username);
std::string GetInboxFile(std::string username);
std::string GetLine(std::istream & sin);
bool DoesUserExist(std::string username);
int GetInboxCount(std::string username);
std::string FormatEmailString(std::string from, std::string to, std::string subject, std::string msg);
void SendEmail(std::string username);
std::string GetPassword(std::string username);

int main()
{
	MainMenu();
	std::cin.get();
	return 0;
}

void MainMenu()
{
	std::string input = "";
	int menuItem = 0;

	while (input != "99")
	{
		std::cout << " 1) Login" << "\n";
		std::cout << " 2) Register new user" << "\n";
		std::cout << " 3) Delete user" << "\n";
		std::cout << "99) Exit" << "\n";
		std::cout << "Selection: ";

		std::cin >> input;
		try
		{
			menuItem = stoi(input);
			switch (menuItem)
			{
			case 1:
				Login();
				break;
			case 2:
				RegisterNewUser();
				break;
			case 3:
				DeleteUser();
				break;
			}
		}
		catch (std::invalid_argument & ia)
		{
			std::cout << "Bad option!" << std::endl;
			std::cout << ia.what() << std::endl;
		}
	}
}

// Now you fill in the rest

void RegisterNewUser()
{
	std::string username, password;
	// declared 2 variables of string type
	std::cout << "Enter username: ";
	// requests user to input in a username
	std::cin >> username;
	// computer takes in user input and store it into username variable
	
	if (username.length() < 3) 
	{
		std::cout << "Username must be at least 3 characters!\n";
		//when the length of the username is less than 3 characters, an error message is shown to user
	}
	
	else 
	{
		
		if (DoesUserExist(username))
		{
			std::cout << "User already exists!\n";
			// calls the doesuserexist function to see if the username entered is already in existance, if so an error message is shown to user
		}
		
		else 
		{
			std::cout << "Enter Password: ";
			// if all the above 2 tests are passed, then the user is prompted to enter a password
			std::cin >> password;
			// the computer takes in user input and store is into password variable
			
			if (password.length() < 6) 
			{
				std::cout << "Password must be at least 6 characters\n";
				// if the password length is less than 6 characters, an error message is shown to user
			}
			
			else 
			{
				std::ofstream fout;
				// declares a variable of type ofstream
				fout.open(username + ".txt");
				// creates a file with username
				fout << "username " << username << std::endl << "password " << password;
				// edits the file with details on username and password
				fout.close();
				// closes th efile
				fout.open(username + "-inbox.txt");
				//creates a file with username-inbox
				fout << "#email\n" << "mailservice\n" << username << std::endl;
				//inputs in the first 3 lines in the file with #email, mailservice, and username
				fout << "Intro\n" << "Hello, " << username << "! Welcome to our service\n";
				// inputs in the 4th and 5th line of the file
				fout.close();
				// closes the file
			}
		}
	}
}

void Login()
{
	std::string username, password;
	// creates string variables, asks user to input in username
	std::cout << "Enter username: ";
	std::cin >> username;

	if (GetUserFile(username) == username + ".txt") 
	{
		// test to show if the username entered was created already, if so user is to input password
		std::cout << "Enter password: ";
		std::cin >> password;
		
		if (password == GetPassword(username)) 
		{
			//if correct password is entered, logged in menu function is called
			LoggedInMenu(username);
		}
		
		else std::cout << "Incorrect password!\n";
		// wrong password entered gives user such notification
	}
	
	else std::cout << "User does not exist!\n";
	// if username hasn't been created, an error message
}

void DeleteUser()
{
	std::string username, password, deletefile;
	// creates string variables, asks user to input in username
	std::cout << "Enter user to delete: ";
	std::cin >> username;

	if (GetUserFile(username) == username + ".txt")
	{
			// if the username matches a file, the filename of the username is saved into deletefile string
			deletefile = username + ".txt";
			std::remove(deletefile.c_str());
			// removes the c string deletefile which contains name of the username text
			deletefile = username + "-inbox.txt";
			// same process repeated for username-inbonx text
			std::remove(deletefile.c_str());
			std::cout << username << ": User Deleted!\n";
			// informs user the username is deleted
	}
	
	else
	{
		std::cout << "User does not exist!\n";
	}
}

void LoggedInMenu(std::string username)
{
	std::string input = "";
	int menuItem = 0;
	// declaring and initializing variables for later usage
	while (input != "99") 
	{
		std::cout << " 1) Inbox[" << GetInboxCount(username) << "] \n";
		std::cout << " 2) Send Email\n";
		std::cout << "99) Logout \n";
		std::cout << "Selection: ";
		std::cin >> input;
		//while input isnt 99, the system will output above 
		try 
		{
			menuItem = stoi(input);
			switch (menuItem)
			{
			case 1: 
				ShowInbox(username, std::cout);
				break;
			case 2: 
				SendEmail(username);
				break;
			}
		}
		//  determines which function to call based on user input
		catch (std::invalid_argument & ia) 
		{
			std::cout << "Bad option!" << std::endl;
			std::cout << ia.what() << std::endl;
		}
	}
}


void ShowInbox(std::string username, std::ostream & sout)
{
		std::string line;
		std::ifstream f(username + "-inbox.txt");
		// reads the username inbox file
		while (std::getline(f, line)) 
		{

			if (line == "#email") 
			{
				std::cout << "\nFrom: " << GetLine(f);
				std::cout << "\nTo: " << GetLine(f);
				std::cout << "\nSubject: " << GetLine(f);
				std::cout << "\nMessage: " << GetLine(f);
			}
		}
		std::cout << "\n";
		// prints out the readed file in format above if line == #email
}

std::string GetUserFile(std::string username)
{
	if (DoesUserExist(username)) 
	{
		return (username + ".txt");
		// returns username if it exists
	}
	else 
	{
		return "No";
	}
}

std::string GetInboxFile(std::string username)
{
	if (DoesUserExist(username)) 
	{
		return (username + "-inbox.txt");
		// returns user inbox file name
	}
	else
	{
		return "No";
	}
}

std::string GetLine(std::istream & sin)
{
	std::string line;
	std::getline(sin, line);
	return line;
	// reads the next line
}

bool DoesUserExist(std::string username)
{
	std::ifstream f(username + ".txt");
	return f.good();
	// if file exists, returns positively
}
int GetInboxCount(std::string username)
{
	std::string line;
	int count = 0;
	if (DoesUserExist(username)) 
	{
		std::ifstream f(username + "-inbox.txt");
		while (std::getline(f, line)) 
		{
			if (line == "#email") 
			{
				count++;
			}
		}
		f.close();
		return count;
	}
	// reads the file username inbox, reads the lines that contains #email and adds it, returns the sum
	else return 0;	
}

std::string FormatEmailString(std::string from, std::string to, std::string subject, std::string msg)
{
	return ("#email\n" + from + "\n" + to + "\n" + subject + "\n" + msg + "\n");
	// formas that string in the particular format above
}

void SendEmail(std::string username)
{
	std::string to, subject, msg;
	std::cout << "Send email to who: ";
	std::cin >> to;
	// gets input for username to write it to; 

	if (GetInboxFile(to) == to + "-inbox.txt") 
	{
		// if the to user exists
		std::cout << "Subject: ";
		std::cin >> subject;
		std::cout << "Message: ";
		std::cin >> msg;
		std::cout << "Sending:\n";
		// inputs the email content 

		std::ofstream writer;
		writer.open(to + "-inbox.txt", std::fstream::app);
		std::string formattedEmail = FormatEmailString(username, to, subject, msg);
		std::cout << formattedEmail;
		writer << formattedEmail;
		writer.close();
		// saves a copy of the email into reciepent inbox, formats it, closes writer
	}
	else
	{
		std::cout << "No such user!\n";
	}
}

std::string GetPassword(std::string username)
{
	std::string finfile = username + ".txt";

	// creates a string containing username text file

	if (GetUserFile(username) == finfile) 
		// if the username exists
	{

		std::ifstream f(finfile);
		//read the file, 
		GetLine(f);
		finfile = GetLine(f).substr(9);
		//down to 2nd line (password line), and skips first 9 characters to read the password
		f.close();
		return (finfile);
	}
	else
	{
		return "No";
	}
}