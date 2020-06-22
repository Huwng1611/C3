//#include <iostream>
//#include <math.h>
//using namespace std;
//
//bool IsPrime(const int& n)
//{
//	if (n < 0)
//	{
//		return false;
//	}
//	for (int i = 2; i <= sqrt(n); i++)
//	{
//		if (n % i == 0)
//		{
//			return false;
//		}
//	}
//	return true;
//}
//
//int main()
//{
//	int n;
//	cout << "Nhap vao so n: ";
//	cin >> n;
//	int* ptr = new int[n];
//	for (int i = 0; i < n; i++)
//	{
//		cin >> *(ptr + i);
//		if (IsPrime(*(ptr + i)))
//		{
//			cout << "IsPrime = " << *(ptr + i) << endl;
//		}
//	}
//
//	//int* ptr;
//	//int value = 5;
//	//ptr = &value;
//	//cout << ptr << endl;
//	//cout << *ptr << endl;
//
//	return 0;
//}