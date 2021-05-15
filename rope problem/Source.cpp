/*
Written by MarkisJr 15/05/2021
My personal solution to the rope problem (common coding challenge/interview question)
*/

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<float> factors;
int result = 1;

int main()
{
	float input = 0;
	vector<float> current;
	cin >> input;
	current.push_back(input);
	int i = 1;
	
	for(;;)
	{
		for (int j = 0; j < current.size(); j++)
		{
			factors.push_back(floor(current[j] / 2));
			factors.push_back(ceil(current[j] / 2));
		}
		if (factors.back() <= 3) break;
		else
		{
			current.clear();
			current = factors;
			factors.clear();
		}
	}

	for (const auto& e : factors) result *= e;
	if (result == 1) result = 2;
	if (result == 0) result = 1;
	cout << result << endl;
}