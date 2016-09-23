#include <iostream>
#include <vector>
using namespace std;

bool zeroDiff(vector<int>);

int main()
{
	int k;
	cin >> k;
	while(k > 0)
	{
		--k;

		int s,c;
		cin >> s >> c;

		vector<int> input;

		vector<vector<int>> diff(s);

		for(int i = 0; i < s; i++)
		{
			int temp;
			scanf("%d", &temp);
			//cout << "x" << endl;
			diff[0].push_back(temp);
		}

		//cerr << diff[0].size();

		//cout << "aa" << endl;

		int degree = 0;

		//cout << "bb" << endl;

		//cerr << diff[degree].size();

		while(zeroDiff(diff[degree]) == false)
		{
			degree++;
			//cerr << "c";
			//diff[degree].resize(diff[degree-1].size() - 1);
			//cerr << "d";
			for(int i = 0; i < diff[degree-1].size() - 1; i++)
			{
				diff[degree].push_back(diff[degree-1][i+1] - diff[degree-1][i]); 
			}			
		}

		/*for(int i = 0; i <= degree; i++)
		{
			for(int j = 0; j < diff[i].size(); j++)
			{
				cout << diff[i][j];
			}
			cout << endl;
		}*/

		//cout << degree << endl;

		if(degree == 0)
		{
			int temp = diff[degree][0];
			while(c > 0)
			{
				cout << temp << " ";
				c--;
			}
		}
		else
		{

			int temp1 = diff[degree][0];
			int c1 = 0;
			while(c1 < c)
			{
				diff[degree].push_back(temp1);
				c1++;
			}

			while(degree > 0)
			{
				int temp;
				int last;
				int n;
				int count = 0;

				temp = diff[degree][count];
				n = diff[degree-1].size();
				last = diff[degree-1][n-1];

				diff[degree-1].clear();

				while(count < c)
				{
					diff[degree-1].push_back(temp+last);

					count++;

					temp = diff[degree][count];
					n = diff[degree-1].size();
					last = diff[degree-1][n-1];
				}

				/*for(int i = 0; i < diff[degree-1].size(); i++)
				{
					cout << diff[degree-1][i];
				}
				cout << endl;*/

				degree--;
			}
			
			int count = 0;
			while(count < c)
			{
				cout << diff[degree][count] << " ";
				count++;
			}	
		}

		cout << endl;
	}
}

bool zeroDiff(vector<int> input)
{
	//cerr << "e";
	//cerr << input.size();
	for(int i = 0; i < (input.size() - 1); i++)
	{
		//cerr << "f";
		if(input.at(i) != input.at(i+1))
		{
			//cerr << "f";
			return false;
		}
	}
	return true;
}