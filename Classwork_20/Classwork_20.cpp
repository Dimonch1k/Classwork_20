#include <iostream>
#include <string>
using namespace std;


// Task 1
// Division
/*

void Division()
{
	int a;
	int b;
	cout << "Enter a: "; cin >> a;
	cout << "Enter b: "; cin >> b;
	
	if (b == 0)
	{
		throw invalid_argument("Can not division by zero.");
	}
	int c = a / b;
	cout << c << endl;
}



int main()
{
	try {
		Division();
	}
	catch (const invalid_argument& c)
	{
		cout << c.what() << "\n\n";
		Division();
	}
}*/






// Task 2
// Larger or Smaller index


/*
class positiveExeption : public exception 
{
public:
	positiveExeption(string message) : exception(message.c_str()) {}
};

class negativeExeption : public exception 
{
public:
	negativeExeption(string message) : exception(message.c_str()) {}
};

void getElement()
{
	int arr[5] = { 11, 22, 33, 44, 55 };
	int index;

	cout << "Input index to find element in array: "; cin >> index;

	for (int i = 0; i < 5; i++)
	{
		if (index > 4)
		{
			throw positiveExeption("The index is larger than array list.\n\n\n");
		}
		if (index < 0)
		{
			throw negativeExeption("The index is smaller than array list.\n\n\n");
		}

		if (index == i)
		{
			cout << "The element of index " << index << " is: " << arr[i] << "\n\n\n";
		}
	}
}

int main()
{
	try {
		getElement();
	}

	catch (const positiveExeption& posEx)
	{
		cout << posEx.what();
		getElement();
	}
	
	catch (const negativeExeption& negEx)
	{
		cout << negEx.what();
		getElement();
	}
}
*/






// Task 3
// Guess the number


/**/


class largerNum : public exception
{
public:
	largerNum(string message) : exception(message.c_str()){}
};

class smallerNum : public exception
{
public:
	smallerNum(string message) : exception(message.c_str()){}
};



void guessNum(int randNum)
{
	string number;
	int Num = 0;
	while (Num != randNum)
	{
		cout << "Enter the number: "; cin >> number;
		Num = stoi(number);
		cout << Num << "\n\n\n";
		
		

		if (Num > INT_MAX)
		{
			throw largerNum("The num is larger than range of permissible values.\n\n\n");
		}
		if (Num < 0)
		{
			throw smallerNum("The num is smaller than 0.\n\n");
		}

		if (Num == randNum)
		{
			cout << "You win!!!\n\n\n\n";
			break;
		}
		else if (Num > randNum)
		{
			cout << "Win number is smaller " << "\n\n";
		}
		else if (Num < randNum)
		{
			cout << "Win number is bigger " << "\n\n";
		}
	}
}


int main()
{
	cout << "Guess the number that the computer guessed!\n\n\n";

	srand(time(NULL));
	int randNum = rand() %  1000 + 0;
	cout << randNum << "\n\n";
	try {
		guessNum(randNum);
	}

	catch (const largerNum& larNum)
	{
		cout << larNum.what() << "\n\n";
		guessNum(randNum);
	}
	catch (const smallerNum& smallNum)
	{
		cout << smallNum.what() << "\n\n";
		guessNum(randNum);
	}
}