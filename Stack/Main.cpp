#include "Stack.h"
#include"List.h"

int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::cout.setf(std::ios_base::boolalpha);

	locale loc(cout.getloc(), new ::numpunct);
	cout.imbue(loc);

	int count = 0; 
	int countchar = 0; 

	string str;

	cout << "Enter the string(\x1b[31;1mIMPORTANT! The string must end with a character ';')\x1b[0m: ";
	getline(cin, str, ';');

	DynamicStack<char, 100> dst;

	List<char> lst;

	if (str[0] == ')' || str[0] == '}' || str[0] == ']')
	{
		cout << "The entered string contains an error in the first character: " << str[0];

	}

	else
	{
		for (size_t i = 0; i < str.length(); i++)
		{

			if (str[i] == '(' || str[i] == '{' || str[i] == '[')
			{
				dst.push(str[i]);
				count++;
			}

			else if (str[i] == ')')
			{
				count++;

				if (dst.peek() == '(')
					dst.pop();
				else
				{
					countchar++;
					break;
				}
			}

			else if (str[i] == '}')
			{
				count++;

				if (dst.peek() == '{')
					dst.pop();
				else
				{
					countchar++;
					break;
				}
			}

			else if (str[i] == ']')
			{
				count++;

				if (dst.peek() == '[')
					dst.pop();
				else
				{
					countchar++;
					break;
				}
			}

			countchar++;
		}

		if (!count)
		{

			cout << "The entered string does not contain parentheses ";

		}


		else if (dst.isEmpty())
			cout << "The entered string does not contain errors: " << str;

		else if (str.length() == countchar)
		{
			reverse(str.begin(), str.end());

			int counti = 0;

			for (size_t i = 0; i < countchar; i++)
			{
				if (str[i] == '{' || str[counti] == '}' || str[counti] == '[' || str[counti] == ']' || str[counti] == '(' || str[counti] == ')' || str[counti] == '<' || str[counti] == '>')
					break;

				else
					counti++;
			}

			reverse(str.begin(), str.end());

			cout << setw(countchar - counti + 27) << "\x1b[32;1m^\x1b[0m";
			cout << endl;
			cout << "The string you entered contains errors: ";

			for (size_t i = 0; i < countchar - counti; i++)
			{
				lst.push_back(str[i]);
			}
			cout << lst;

		}

		else
		{
			cout << setw(countchar + 27) << "\x1b[32;1m^\x1b[0m";
			cout << endl;

			cout << "The string you entered contains errors: ";

			for (size_t i = 0; i < countchar; i++)
			{
				lst.push_back(str[i]);
			}
			cout << lst;
		}
	}


	cout << endl;
	system("pause");
}