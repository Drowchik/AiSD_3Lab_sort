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
	template<typename T>
	stats sorting_choice(vector<T>& data) {
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
			stat.comparison_count += 1;
			if (min_index != i) {
				stat.copy_count += 1;
				std:swap(data[min_index], data[i]);
			}
		}
		return stat;
	}
	template<typename T>
	ostream& operator<<(ostream& os, const vector<T>& data) {
		size_t size = data.size();
		for (size_t i = 0; i < size; i++) {
			cout << data[i] << " ";
		}
		return os;
	}
	template<typename T>
	stats shell_sort(vector<T>& data) {
		stats stat;
		size_t size = data.size();
		for (size_t d = size / 2; d > 0; d /= 2) {
			for (size_t i = d; i < size; i++) {
				T value = data[i];
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

	void merge_sort_left(vector<int>& a1, vector<int>& a2, vector<int>& temp, size_t start_index) {
		size_t i = 0;
		int j = a2.size()-1;
		size_t k = start_index;
		while (i < a1.size() && j >= 0) {
			if (a1[i] <= a2[j]) {
				temp[k] = a1[i];
				i++;
			}
			else {
				temp[k] = a2[j];
				j--;
			}
			k++;
		}
		while (i < a1.size()) {
			temp[k] = a1[i];
			i++;
			k++;
		}
		while (j >= 0) {
			temp[k] = a2[j];
			j--;
			k++;
		}
	}
	void merge_sort_right(vector<int>& a1, vector<int>& a2, vector<int>& temp, size_t start_index) {
		size_t i = 0;
		int j = a2.size() - 1;
		size_t k = start_index;
		while (i < a1.size() && j >= 0) {
			if (a1[i] <= a2[j]) {
				temp[k] = a1[i];
				i++;
			}
			else {
				temp[k] = a2[j];
				j--;
			}
			k--;
		}
		while (i < a1.size()) {
			temp[k] = a1[i];
			i++;
			k--;
		}
		while (j >= 0) {
			temp[k] = a2[j];
			j--;
			k--;
		}
	}
	void merge(vector<int>& a) {
		vector<int> temp(a.size());
		size_t left_start = 0;
		size_t left_end = 0;

		size_t right_start = a.size()-1;
		size_t right_end = right_start;
		
		size_t n = 0;
		while (left_end < right_end) {
			while (a[left_end] <= a[left_end + 1] && left_end + 1 != right_end) {
				left_end++;
			}
			while (a[right_end] <= a[right_end - 1] && right_end - 1 != left_end) {
				right_end--;
			}
			vector<int> subvector1(a.begin() + left_start, a.begin() + left_start + left_end+1);
			vector<int> subvector2(a.begin() + right_end, a.begin() + right_start+1);
			size_t la = left_end - left_start + right_start - right_end-1;
			if (n % 2 == 0) {
				merge_sort_left(subvector1, subvector2, temp, la);
			}
			else {
				merge_sort_right(subvector1, subvector2, temp, temp.size()-la-1);
			}
			left_end++;
			right_end--;

			left_start = left_end;
			right_start = right_end;

			n++;
		}

	}
    void natural_merge_sort(vector<int>& a) {
        vector<int> a_prev;
        do {
            a_prev = a;
            merge(a);
        } while (a != a_prev);
    }


}
