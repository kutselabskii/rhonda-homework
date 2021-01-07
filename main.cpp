#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <chrono>
#include <fstream>

int main() {
	auto start = std::chrono::high_resolution_clock::now();

	int n;
	std::ifstream input;
	input.open("input.txt");
	input >> n;
	input.close();

	bool* numbers = new bool[n + 1];
	for (int i = 0; i <= n; ++i) {
		numbers[i] = true;
	}

	for (int i = 2; i * i <= n; ++i) {
		if (numbers[i]) {
			for (int j = i * i; j <= n; j += i) {
				numbers[j] = false;
			}
		}
	}

	std::ofstream output;
	output.open("output.txt");
	bool multiple = false;
	for (int i = 2; i <= n; ++i) {
		if (numbers[i]) {
			if (multiple) {
				output << ", ";
			}
			output << i;
			multiple = true;
		}
	}
	output.close();

	delete[] numbers;

	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

	std::cout << "Elapsed time: " << duration.count() << " ms";

	return 0;
}