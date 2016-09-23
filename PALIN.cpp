#include <iostream>
#include <string>
using namespace std;

string copy(string, int, int, int, int);

string palin(string);

int num(string);

int main()
{
	int k;
	string input;

	cin >> k;

	/*while(k > 0)
	{
		--k;

		input.clear();
		cin >> input;

		int n = input.size();

		int i = (n-1)/2, j = n-1-i;

		if(i == j)
		{
			if(input[i] != '9')
			{
				input[i]++;
				input = copy(input, 0, i-1, n-i, n-1);
			}
			else
			{
				while(i >= 0 && input[i] == '9' && input[j] == '9')
				{	
					input[i] = '0';
					input[j] = '0';
					i--;
					j++;
				}
				if(i >= 0)
				{
					input[i]++;
					input = copy(input, 0, i, j, n-1);
				}
				else
				{
					input.push_back('1');
					input[0] = '1';
				}
			}
		}
		else
		{
			if(input[i] > input[j])
			{
				input = copy(input, 0, i, j, n-1);
			}
			else if(input[i] < input[j])
			{
				input[i]++;
				input = copy(input, 0, i, j, n-1);
			}
			else
			{
				if(input[i] != '9')
				{
					input[i]++;
					input[j]++;
					input = copy(input, 0, i-1, j+1, n-1);
				}
				else
				{
					while(i >= 0 && input[i] == '9' && input[j] == '9')
					{
						input[i] = '0';
						input[j] = '0';
						i--;
						j++;
					}
					if(i >= 0)
					{
						input[i]++;
						input = copy(input, 0, i, j, n-1);
					}
					else
					{
						input.push_back('1');
						input[0] = '1';
					}
				}
			}
		}

		PRINT:
		cout << input << endl;
	}*/

	while(k > 0)
	{
		--k;

		input.clear();

		cin >> input;

		int n = input.size();

		input = palin(input);

		if(k != 0)
		{
			cout << input << endl;
		}
		else
		{
			cout << input;
		}	
	}

	return 0;
}

string copy(string input, int a, int b, int c, int d)
{
	int i,j;

	for(i = a, j = d; i <= b; i++, j--)
	{
		input[j] = input[i];
	}
	return input;
}

string palin(string input)
{
	int n = input.size();
	int i = 0,j = n-1;

	while(1)
	{
		if(input[i] != '0')
			break;
		input.erase(0,1);
	}

	if(input.size() == 0)
	{
		input.push_back('1');
		return input;
	}

	n = input.size();
	i = 0;
	j = n-1;

	if(input[i] > input[j])
	{
		input[j] = input[i];
		string temp = input;
		temp.pop_back();
		temp.erase(0,1);

		if(num(temp) == -1)
		{
			temp = palin(temp);
		}
		else
		{
			return copy(input, i, (i+j)/2, i+j-(i+j)/2, j);
		}
		temp.insert(0, string(1,input[i]));
		temp.push_back(input[j]);
		return temp;
	}
	else
	{
		while(input[i] <= input[j] && i<=j)
		{
			i++;
			j--;
		}
		if(i < j)
		{
			return copy(input, 0, (n-1)/2, n-1-(n-1)/2, n-1);
		}
		else
		{
			i--;
			j++;
			if(input[i] < input[j])
			{
				input[i]++;
				return copy(input, 0, i, j, n-1);
			}
			else
			{
				if(i == j)
				{
					if(input[i] != '9')
					{
						input[i]++;
						return copy(input, 0, i-1, n-i, n-1);
					}
					else
					{
						while(i >= 0 && input[i] == '9' && input[j] == '9')
						{	
							input[i] = '0';
							input[j] = '0';
							i--;
							j++;
						}
						if(i >= 0)
						{
							input[i]++;
							return copy(input, 0, i, j, n-1);
						}
						else
						{
							input.push_back('1');
							input[0] = '1';
							return input;
						}
					}
				}
				else
				{
					if(input[i] != '9')
					{
						input[i]++;
						input[j]++;
						return copy(input, 0, i-1, j+1, n-1);
					}
					else
					{
						while(i >= 0 && input[i] == '9' && input[j] == '9')
						{
							input[i] = '0';
							input[j] = '0';
							i--;
							j++;
						}
						if(i >= 0)
						{
							input[i]++;
							return copy(input, 0, i, j, n-1);
						}
						else
						{
							input.push_back('1');
							input[0] = '1';
							return input;
						}	
					}
				}
			}
		}
	}
}

int num(string input)
{
	int j = input.size() - 1;
	int flag = 1;
	for(int i = 0; i<=j; i++, j--)
	{
		if(input[i] < input[j])
		{
			return -1;
		}
		if(input[i] == input[j])
		{
			flag = 0;
		}
	}
	return flag;
}