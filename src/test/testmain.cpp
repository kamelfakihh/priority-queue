#ifdef TEST

#include"PriorityQueue/MaxPQ.h"
#include"PriorityQueue/MinPQ.h"

#include <iostream>
#include <cassert>
#include <cmath>
#include <ctime>
#include <vector>

#define TEST_SIZE 100
#define TEST_MIN 0
#define TEST_MAX 10e5

bool isAsc(std::vector<int> c);
bool isDesc(std::vector<int> c);
void test1();
void test2();

int main(){

	test1();
	test2();

	std::cout << "all tests passed successfuly !" << std::endl;

	return 0;
}

bool isAsc(std::vector<int> c){

	for(unsigned int i=0; i<c.size()-1; i++){
		if(c[i] < c[i+1]) 
			return false;
	}

	return true;
}

bool isDesc(std::vector<int> c){

	for(unsigned int i=0; i<c.size()-1; i++){
		if(c[i] > c[i+1]) 
			return false;
	}

	return true;
}

void test1(){

	std::vector<int> k;
	MaxPQ<int> mp = MaxPQ<int>();

	for(unsigned int i=0; i<TEST_SIZE; i++){

		int temp = TEST_MIN + rand()/TEST_MAX;
		mp.insert(temp);
	}
	
	for(unsigned int i=0; i<TEST_SIZE; i++){

		k.push_back( mp.delMax() );
	}

	assert(isDesc(k) == true);

	std::cout << "test1" << std::endl;
}

void test2(){

	std::vector<int> k;
	MinPQ<int> mp = MinPQ<int>();

	for(unsigned int i=0; i<TEST_SIZE; i++){

		int temp = TEST_MIN + rand()/TEST_MAX;
		mp.insert(temp);
	}
	
	for(unsigned int i=0; i<TEST_SIZE; i++){

		k.push_back( mp.delMin() );
	}

	assert(isAsc(k) == true);

	std::cout << "test2" << std::endl;
}

#endif