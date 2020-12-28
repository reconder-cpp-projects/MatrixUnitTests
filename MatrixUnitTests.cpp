// MatrixUnitTests.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Matrix.h"
#include <iostream>
#include <string>

using namespace std;

static struct MatrixTests {

    static void PrintMatrix(Matrix<double>& m) 
    {
        pair<int, int> size = m.GetSize();
		for (int i = 0; i < size.first; i++)
		{
			for (int j = 0; j < size.second; j++)
				cout << m[{i, j}] << " ";
			cout << endl;
		}
    }


	static void Assert(string testname, Matrix<double>& result, Matrix<double>& expected)
	{
		string output = testname + ": ";
		if (result == expected) { output += "Success!"; }
		else { output += "Failed!"; }
		cout << output << endl;
	}
	static void Assert(string testname, bool result)
	{
		string output = testname + ": ";
		if (result) { output += "Success!"; }
		else { output += "Failed!"; }
		cout << output << endl;
	}


	static void Test1()
	{
		Matrix<double> m1(2, 2, { 1, 2,
								  1, 2 });
		Matrix<double> result = m1 * m1;

		Matrix<double> expected(2, 2, {3, 6,
			                           3, 6});

		Assert("Test1", result, expected);
	}

	static void Test2()
	{
		Matrix<double> m1(2, 1, { 1,
								  1});

		Matrix<double> m2(1, 2, { 1, 2});
		Matrix<double> result = m1 * m2;

		Matrix<double> expected(2, 2, { 1, 2,
									   1, 2 });

		Assert("Test2", result, expected);
	}

	static void Test3()
	{
		Matrix<double> m1(4, 4, { 1, 4, 6, 1,
								  1, 9, 10, 32,
			                      19, 32, 54, 12,
			                      9, 13, 12, 1});

		Matrix<double> m2(4, 4, { 1, 2, 18, 32,
			                      91, 23, 11, 2,
			                      5, 5, 6, 11,
			                      22, 12, 8, 17});
		Matrix<double> result = m1 * m2;

		Matrix<double> expected(4, 4, 
			{417, 136, 106, 123,
			1574, 643, 433, 704,
			3465, 1188, 1114, 1470,
			1274, 389, 385, 463});

		Assert("Test3", result, expected);
	}

	static void Test4()
	{
		Matrix<double> m1(4, 2, 
			{ 9.9, 2.1, 
			  4, 0.4,
			  8.1, 4.4, 
			  3.14, 2});

		Matrix<double> m2(2, 1, { 1.5,
			                      6.8});
		Matrix<double> result = m1 * m2;

		Matrix<double> expected(4, 1,
			{ 29.13,
			   8.72,
			  42.07,
			  18.31});

		Assert("Test4", result, expected);
	}

	static void Test5()
	{
		Matrix<double> m1(2, 3, { 1, 4, 6,
								  1, 9, 10});

		Matrix<double> m2(2, 3, { 1, 2, 18,
								  91, 23, 11});
		Matrix<double> result = m1 * m2;

		Matrix<double> expected(-1, -1);

		bool r = result.GetSize() == expected.GetSize();
		Assert("Test5", r);
	}

	static void Test6()
	{
		Matrix<double> m1(4, 4, { 1, 4, 6, 1,
								  1, 9, 10, 32,
								  19, 32, 54, 12,
								  9, 13, 12, 1 });

		Matrix<double> m2(4, 4, { 1, 4, 6, 1,
								  1, 9, 10, 32,
								  19, 32, 54, 12,
								  9, 13, 12, 1 });
		bool r = m1 == m2;
		Assert("Test6", r);
	}

};

int main()
{
	MatrixTests test;
	test.Test1();
	test.Test2();
	test.Test3();
	test.Test4();
	test.Test5();
	test.Test6();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
