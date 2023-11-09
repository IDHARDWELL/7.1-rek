#include "pch.h"
#include "CppUnitTest.h"
#include "../FileName.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace YourNamespace
{
	TEST_CLASS(Test_Metod)
	{
	public:

		TEST_METHOD(TestCalc)
		{
			const int rowCount = 3;
			const int colCount = 3;
			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				a[i] = new int[colCount];

			a[0][0] = 1; a[0][1] = 2; a[0][2] = 3;
			a[1][0] = 4; a[1][1] = 5; a[1][2] = 6;
			a[2][0] = 7; a[2][1] = 8; a[2][2] = 9;

			int S = 0;
			int k = 0;
			Calc(a,0,0, rowCount, colCount, S, k);
	
			Assert::AreEqual(1 + 3 + 5 + 7 + 9, S);  
			Assert::AreEqual(5, k);  	
			for (int i = 0; i < rowCount; i++)
				delete[] a[i];
			delete[] a;
		}
	};
}
