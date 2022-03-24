#include <iostream>
#include <vector>

using namespace std;

int QuickSelect(vector<int> A, int k)
{
	int x = A.back();

	vector<int>  L;
	vector<int> E;
	vector<int> G;
	
	for(int i = 0; i<A.size(); i++)
	{
		if(A[i] < x)
		{
			L.push_back(A[i]);
		}
		
		else if(A[i] == x)
		{
			E.push_back(A[i]);
		}
		
		else
		{
			G.push_back(A[i]);
		}
		
	}
	
	int elem = 0;
	
	if(k <= L.size())
	{
		elem = QuickSelect(L,k);
	}
	
	else if(k <= L.size() + E.size())
	{
		elem = x;
	}
	
	else
	{
		elem = QuickSelect(G,k-L.size()-E.size());
	}
	
	return elem;
}

int main()
{
	vector<int> v {-1,8,9,5,6,7};
	
	cout << QuickSelect(v,2) << endl;
	
	return EXIT_SUCCESS;
}
