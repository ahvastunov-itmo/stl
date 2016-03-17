// Task.cpp : Defines the entry point for the console application.
//

#include <vector>

#include <fstream>
#include <iostream>
#include <string>
#include <list>


std::vector<int> readIntVectorFromFile(const std::string& path){
	std::vector<int> result;

	std::fstream stream(path, std::fstream::in);
	if(stream.is_open()){		
		while(!stream.eof()){
			int i;
			stream >> i;
			result.push_back(i);
		}
		stream.close();
	}
	else{
		std::cout << "Can not open file: " << path;
	}

	return result;
}

void task1(const std::string& path){	
	std::vector<int> values = readIntVectorFromFile(path);
	
	int count = 0;
	for(std::vector<int>::iterator it = values.begin(); it != values.end(); ++it){
		int v = *it;
		if(v == 1)
			count++;
	}

	std::cout << "Task1! Count is " << count << std::endl;
}

void task2(const std::string& path){
	std::vector<int> values = readIntVectorFromFile(path);

	std::list<int> listValues;
	for(std::vector<int>::iterator it = values.begin(); it != values.end(); ++it){
		int v = *it;
		if(v != 1)
			listValues.push_back(v);
	}

}

int _tmain(int argc, _TCHAR* argv[])
{
	const std::string inputFilePath("input.txt");
	task1(inputFilePath);
	task2(inputFilePath);
	return 0;
}

