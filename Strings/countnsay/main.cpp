/*
 *	Author: Suraj Bennur
 * The count-and-say sequence is the sequence of integers beginning as follows:	
 * 1, 11, 21, 1211, 111221,...
 * 1 is read off as one 1 or 11.
 * 11 is read off as two 1s or 21.
 * 21 is read off as one 2, then one 1 or 1211.
 * Given an integer n, generate the nth sequence.
 * Note: The sequence of integers will be represented as a string.
 * compiler version: 
 */
#include <iostream>

using namespace std;

string countnsay(int n)
{
	
}

// driver function
int main(int argc, char* argv[])
{
	// perform sanity checks
	if(argc != 3)
	{
		printf("Usage = %s arg 1 arg 2\n",argv[0]);
		return 0;
	}
	
	int n = 2;
	string sol = countnsay(n);
	cout << sol << endl;
	return 0;
}
