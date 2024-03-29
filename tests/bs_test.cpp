#include "st_test/simtools/binary_sum_search.hh"
#include <iostream>
#include <cmath>

using std::cout;
using std::cerr;
using std::abs;
using namespace simtools;

int main(int argc, char* argv[])
{
	long unsigned worked = 1;
	long unsigned failed = 0;
	
	bool all_ok = true;
	
	vector<double> input;
	input.push_back(1.);
	input.push_back(2.);
	input.push_back(3.);
	input.push_back(4.);
	binary_sum_search<double> mybin(input);
	
	if (abs(mybin.get_propensity() - double(10)) > 1e-10)
	{
		cerr << "Wrong probensity in first binary tree."<< endl;
		all_ok = false;
	}
	
	mybin.rebuild(2, 5.);
	
	long unsigned ind = mybin.get_index(12.);
	
	if (ind != 3)
	{
		cerr << "Wrong index returned in first index test." << endl;
		all_ok = false;
	}
	
	ind = mybin.get_index(5);
	
	if (ind != 2)
	{
		cerr << "Wrong index returned in second index test." << endl;
		all_ok = false;
	}
	
	ind = mybin.get_index(0.);
	
	if (ind != 0)
	{
		cerr << "Wrong index returned in third index test." << endl;
		all_ok = false;
	}
	
	vector<double> input2;
	input2.push_back(1.);
	input2.push_back(2.);
	input2.push_back(3.);
	input2.push_back(4.);
	input2.push_back(5.);
	binary_sum_search<double> mybin2(input2);
	
	if (abs(mybin2.get_propensity() - double(15)) > 1e-10)
	{
		cerr << "Wrong propensity in second binary tree. Is " << mybin.get_propensity() << " but should be " << double(15) << endl;
		all_ok = false;
	}
	
	ind = mybin2.get_index(mybin.get_propensity());
	if (ind != 4)
	{
		cerr << "Wrong index returned in third index test." << endl;
		all_ok = false;
	}
	
	if (not all_ok)
		return failed;
	return worked;
}