/*
Written by MarkisJr 15/05/2021
My personal solution to the rope problem (common coding challenge/interview question)
*/

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<float> factors;
long result = 1;

int main()
{
	float input = 0;
	vector<float> current;
	cin >> input;
	if (input == 0)
	{
		cout << "Cannot accept 0 as input" << endl;
		goto end;
	}
	input = floor(input);
	current.push_back(input);
	
	for(;;)
	{
		for (int i = 0; i < current.size(); i++)
		{
			factors.push_back(floor(current[i] / 2));
			factors.push_back(ceil(current[i] / 2));
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
end:;
}