/*
Author: My Tran
Filename:	tribonacci.cpp
Description:	Taking an integer input, outputs that number of tribonacci digits
*/
#include<iostream>
#include<vector>

/*Prototypes*/
std::vector<long long> tribonacci(long long);//wrapper

void rTribonacci(std::vector<long long> &, long long, long long);//recursive


int main()
{
	long long digits;
	std::cout << "Please enter amount of tribonacci digits: ";

	std::cin >> digits;

	std::endl(std::cout);

	std::vector<long long> trib = tribonacci(digits);

	for (long long i : trib)
	{
		std::cout << i << " ";
	}

	std::endl(std::cout);

	return 0;
}

/*
Purpose:	Calculates n number of tribonacci digits and stores it in a vector
Pre:		Takes integer argument
Post:		Returns vector with n trib digits
*/
std::vector<long long> tribonacci(long long n)
{

	std::vector<long long> trib;//vector to store values in

	switch (n)//cover the base cases being the first three ones
	{
		case 0:
			break;
		case 1:
			trib = { 0 };
			return trib;
			break;
		case 2:
			trib = { 0, 0 };
			return trib;
			break;
		case 3:
			trib = { 0, 0, 1 };
			return trib;
			break;
		default:
			trib = { 0, 0, 1 };
			break;
	}

	//code only makes it here if given n is greater than 3. Calc. the rest
	rTribonacci(trib, n - 3, trib.size()-1);

	return trib;

}

/*
Purpose:	Recursively calculates tribonacci digits
Pre:		Takes vector, and two integers as arguments
Post:		Tribonacci digit is appended to vector
*/
void rTribonacci(std::vector<long long>& s, long long n, long long end)
{
	if (n != 0)//terminating condition
	{
		//tribonacci is the current digit is the sum of the three subsequent
		long long newValue = s[end] + s[end - 1] + s[end - 2];

		s.push_back(newValue);//append new value

		rTribonacci(s, n - 1, end + 1);//next recursive call
	}
}
