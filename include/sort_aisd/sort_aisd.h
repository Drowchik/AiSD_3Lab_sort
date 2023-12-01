#pragma once
#include <iostream>
#include <cmath>
#include <vector>
#include <stdexcept>
#include <complex>

using namespace std;
namespace method_sort {
	struct stats {
		size_t comparison_count = 0;
		size_t copy_count = 0;
	};
	stats sorting_choice(vector<int>& data) {
		stats stat;
		size_t size = data.size();
		for (size_t i = 0; i < size-1; i++) {
			size_t min_index = i;
			for (size_t j = i+1; j < size; j++) {
				stat.comparison_count += 1;
				if (data[j] < data[min_index]) {
					min_index = j;
				}
			}
			if (min_index != i) {
				stat.copy_count += 1;
				std:swap(data[min_index], data[i]);
			}
		}
		return stat;
	}
	ostream& operator<<(ostream& os, vector<int> data) {
		size_t size = data.size();
		for (size_t i = 0; i < size; i++) {
			cout << data[i] << " ";
		}
		return os;
	}
	stats shell_sort(vector<int>& data) {
		stats stat;
		size_t size = data.size();
		for (size_t d = size / 2; d > 0; d /= 2) {
			for (size_t i = d; i < size; i++) {
				size_t value = data[i];
				size_t index = i;
				while ((index >=d) && (data[index - d] > value)) {
					stat.comparison_count += 1;
					data[index] = data[index - d];
					stat.copy_count += 1;
					index-=d;
				}
				data[index] = value;
				stat.copy_count += 1;
			}
		}
		return stat;
	}
	
}
