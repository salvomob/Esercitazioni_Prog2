#include<fstream>
#include"cerchio.h"
#include"cerchio.cpp"

using namespace std;

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	
	for(int task = 0; task < 1000 ; task ++)
	{
		int n;
		in>>n;
		for(int i = 0; i < n; i++)
		{
			float x;
			in>>x;
			Cerchio c(x);
			c.stampa(out);
		}
		out << "\n";
	}
	in.close();
	out.close();
}


