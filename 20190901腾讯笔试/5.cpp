#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>

using namespace std;

struct GivenPrice {
	int company;
	int price;
};
bool IsDeleted(int cmy, std::vector<int>& deletedComp)
{
	return find(deletedComp.begin(), deletedComp.end(), cmy) != deletedComp.end();
}
void PrintWinner(const std::vector<GivenPrice>& prices, std::vector<int>& deletedCompany)
{

	int cur = -1;
	for (int i = prices.size() - 1; i >= 0; --i)
	{
		if (!IsDeleted(prices[i].company, deletedCompany))
		{
			cur = i;
			for (int j = i - 1; j >= 0; --j)
			{
				if (prices[j].company == prices[cur].company)
					cur = j;
				else if (!IsDeleted(prices[j].company, deletedCompany))
				{
					cout << prices[cur].company << " " << prices[cur].price << endl;
					return;
				}
			}
		}
	}
	if (cur == -1)
		cout << "0 0" << endl;
	else
		cout << prices[cur].company << " " << prices[cur].price << endl;
}
int main()
{
	std::vector<GivenPrice>prices;
	int n;
	cin >> n;
	while (n--)
	{
		GivenPrice gp;
		cin >> gp.company >> gp.price;
		prices.push_back(gp);
	}
	int q;
	cin >> q;
	while (q--)
	{
		std::vector<int>coms;
		int m;
		cin >> m;
		while (m--)
		{
			int c;
			cin >> c;
			coms.push_back(c);
		}
		PrintWinner(prices, coms);
	}
	return 0;
}