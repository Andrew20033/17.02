#include <iostream> 
#include <fstream> 
#include <time.h> 
using namespace std;
void main()
{
	char oldn[10], newn[10];
	srand(time(0));
	int ms, i;
	cout << "input file name\n";
	cin >> oldn;
	ofstream fz(oldn);
	cout << "content written to file " << oldn << endl;
	for (i = 1; i <= 9; i++)
	{
		ms = rand() % 100;
		fz << ms << ' ';
		cout << ms << ' ';
	}
	ms = rand() % 100;
	fz << ms;
	cout << ms << ' ';
	fz.close();
	cout << endl;
	ifstream fz0(oldn);
	cout << "content read from file " << oldn << endl;
	while (!fz0.eof())
	{
		fz0 >> ms;
		cout << ms << ' ';
	}
	cout << endl;
	fz0.close();
	cout << "input new name of file\n";
	cin >> newn;
	cout << "file rename " << oldn << " to " << newn << endl;
	if (rename(oldn, newn) == -1)
		cout << "error!\n";
	else cout << "rename successfully completed\n";
	ifstream fz2(newn);
	while (!fz2.eof())
	{
		fz2 >> ms;
		cout << ms << ' ';
	}
	cout << endl;
	fz2.close();
	cout << "file remove " << newn << endl;
	if (remove(newn) == -1)
		cout << "error!\n";
	else cout << "remove successfully completed\n";
}