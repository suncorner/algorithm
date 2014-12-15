#include <iostream>
#include <algorithm>

using namespace std;

#define N 8

bool Place(int current);

bool IsValid(int);

int solutionCount = 0;
int queen[N + 1];

template<typename T>
void printArr(T *A, int arrSize)
{
	std::cout << ++solutionCount << " Solution: " << std::endl;

	for (int row = 0; row < arrSize; ++row){
		for (int col = 0; col < arrSize; ++col){
			if (A[col] == row){
				std::cout << "Q ";
			}
			else{
				std::cout << "X ";
			}
		}
		std::cout << endl;
	}

	std::cout << std::endl;
}
template<typename T>
void foo(T *a, int i)
{
	std::cout << a[i] << std::endl;
}

int main(){

	std::fill_n(queen, sizeof(queen) / sizeof(int), -1);

	Place(0);
	
	return 0;
}

bool IsValid(int current)
{
	for (int i = 0; i < current; ++i){
		if (queen[current] == queen[i] ||
			abs(queen[current] - queen[i]) == abs(current - i)){
			return false;
		}
	}
	return true;
}

bool Place(int current)
{
	for (int i = 0; i <= N - 1; ++i){
		queen[current] = i;
		if (current < N - 1){
			if (IsValid(current)){
				bool success = Place(current + 1);
				if (!success)
					continue;
			}
		}
		else{
			if (IsValid(current)){
				printArr(queen, N);
				return true;
			}
		}
	}
	return false;
}
