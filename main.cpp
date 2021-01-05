#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <chrono>

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	auto start = std::chrono::high_resolution_clock::now();

	int n;
	std::cin >> n;

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

	bool multiple = false;
	for (int i = 2; i <= n; ++i) {
		if (numbers[i]) {
			if (multiple) {
				std::cout << ", ";
			}
			std::cout << i;
			multiple = true;
		}
	}

	delete[] numbers;

	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

	std::cout << std::endl << "Elapsed time: " << duration.count() << " ms";

	return 0;
}