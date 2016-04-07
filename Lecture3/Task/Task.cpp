// Task.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <random>
#include <time.h>

#include <algorithm>
#include <iostream>

void Task1() {
	std::vector<int> values;
	srand(time(NULL));
	for (int i = 0; i < 10; ++i) {
		values.push_back(rand());
	}

	int counter = std::count(values.begin(), values.end(), 10);

	std::cout << counter;
}

class GreaterThen : public std::unary_function<const int, bool> {

private:
	int num_;
public:
	GreaterThen(int num)
		: num_(num) {
	}

	bool operator()(const int value) {
		return value > num_;
	}

};


void Task2() {
	std::vector<int> values;
	srand(time(NULL));
	for (int i = 0; i < 10; ++i) {
		values.push_back(rand());
	}



	std::count_if(values.begin(), values.end(), GreaterThen(10));


}


int main()
{
	Task1();
    return 0;
}

