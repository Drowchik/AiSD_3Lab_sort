#pragma once
#include <iostream>
#include <cmath>
#include <vector>
#include <stdexcept>
#include <complex>
#include <random>

using namespace std;
namespace method_sort {
	struct Person {
		size_t birth_year;
		string name;
		Person() : birth_year(0), name("") {}
		Person(size_t _birth_year, string _name) : birth_year(_birth_year), name(_name) {}
	};

	bool operator<(const Person& lhs, const Person& rhs) {
		return lhs.name < rhs.name;
	}
	bool operator>(const Person& lhs, const Person& rhs) {
		return lhs.name > rhs.name;
	}


	struct stats {
		size_t comparison_count = 0;
		size_t copy_count = 0;

		stats& operator+=(const stats a) {
			comparison_count += a.comparison_count;
			copy_count += a.copy_count;
			return *this;
		}
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
			os << data[i] << " ";
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
				stat.comparison_count += 1;
				while ((index >=d) && (data[index - d] > value)) {
					stat.comparison_count += 1;
					data[index] = data[index - d];
					stat.copy_count += 1;
					index-=d;
				}
				data[index] = value;
			}
		}
		return stat;
	}

	template<typename T>
	void merge_sort_left(vector<T>& a1, vector<T>& a2, vector<T>& temp, size_t start_index, stats& stat) {
		size_t i = 0;
		int j = 0;
		size_t k = start_index;
		while (i < a1.size() && j < a2.size()) {
			stat.comparison_count++;
			if (a1[i] <= a2[j]) {
				stat.copy_count++;
				temp[k] = a1[i];
				i++;
			}
			else {
				stat.copy_count++;
				temp[k] = a2[j];
				j++;
			}
			k++;
		}
		while (i < a1.size()) {
			stat.copy_count++;
			temp[k] = a1[i];
			i++;
			k++;
		}
		while (j < a2.size()) {
			stat.copy_count++;
			temp[k] = a2[j];
			j++;
			k++;
		}
	}
	template<typename T>
	void merge_sort_right(vector<T>& a1, vector<T>& a2, vector<T>& temp, size_t start_index, stats& stat) {
		size_t i = 0;
		int j = 0;
		size_t k = start_index+a1.size()+a2.size()-1;
		while (i < a1.size() && j < a2.size()) {
			stat.comparison_count++;
			if (a1[i] <= a2[j]) {
				temp[k] = a1[i];
				stat.copy_count++;
				i++;
			}
			else {
				temp[k] = a2[j];
				stat.copy_count++;
				j++;
			}
			k--;
		}
		while (i < a1.size()) {
			temp[k] = a1[i];
			stat.copy_count++;
			i++;
			k--;
		}
		while (j < a2.size()) {
			temp[k] = a2[j];
			stat.copy_count++;
			j++;
			k--;
		}
	}
	template<typename T>
	vector<T> merge(vector<T>& a, stats& stat) {
		vector<int> temp(a.size());
		size_t left_start = 0;
		size_t left_end = 0;
		
		size_t left = 0;
		size_t right = a.size();
		size_t right_start = a.size()-1;
		size_t right_end = right_start;
		
		size_t n = 0;
		while (left_end < right_end) {
			while (a[left_end] <= a[left_end + 1] && left_end + 1 != right_end) {
				stat.comparison_count++;
				left_end++;
			}
			while (a[right_end] <= a[right_end - 1] && right_end - 1 != left_end) {
				stat.comparison_count++;
				right_end--;
			}
			if (left_end == right_end) {
				break;
			}
			vector<int> subvector1(a.begin() + left_start, a.begin() + left_end+1);
			vector<int> subvector2(a.begin() + right_end, a.begin() + right_start+1);
			reverse(subvector2.begin(), subvector2.end());
			if (n % 2 == 0) {
				merge_sort_left(subvector1, subvector2, temp, left, stat);
				left += subvector1.size() + subvector2.size();
			}
			else {
				right -= subvector1.size() + subvector2.size();
				merge_sort_right(subvector1, subvector2, temp, right, stat);
			}
			left_end++;
			right_end--;
			left_start = left_end;
			right_start = right_end;
			n++;
		}
		return temp;
	}
	template<typename T>
	stats natural_merge_sort(vector<T>& a) {
        vector<int> a_prev;
		stats stat;
        do {
            a_prev = a;
            a = merge(a, stat);
        } while (a != a_prev);
		return stat;
    }
//2 вариант
//std::vector<int> merge_ascending(std::vector<int> left, std::vector<int> right, stats& stat) {
//	std::vector<int> result;
//
//	int i = 0, j = 0;
//
//	if (left.size() != right.size() && left.back() == right.back())
//		left.pop_back();
//
//	while (i < left.size() && j < right.size()) {
//		stat.comparison_count++;
//		if (left[i] <= right[j]) {
//			result.push_back(left[i]);
//			i++;
//		}
//		else {
//			result.push_back(right[j]);
//			j++;
//		}
//	}
//	while (i < left.size()) {
//		result.push_back(left[i]);
//		i++;
//	}
//	while (j < right.size()) {
//		result.push_back(right[j]);
//		j++;
//	}
//	return result;
//}
//
//std::vector<int> merge_descending(const std::vector<int>& left, const std::vector<int>& right, stats& stat) {
//	std::vector<int> result = merge_ascending(left, right, stat);
//	reverse(result.begin(), result.end());
//	return result;
//}
//stats natural_two_way_sort(std::vector<int>& list) {
//	stats stat;
//	while (true) {
//		std::vector<std::vector<int>> series;
//
//		int left = -1,
//			right = list.size();
//
//		while (left < right) {
//			std::vector<int> one_series;
//
//			do {
//				stat.comparison_count++;
//				left++;
//				one_series.push_back(list[left]);
//			} while (left + 1 < right && list[left] <= list[left + 1]);
//
//			series.push_back(one_series);
//
//			one_series.clear();
//
//			do {
//				stat.comparison_count++;
//				right--;
//				one_series.push_back(list[right]);
//			} while (left - 1 < right && list[right - 1] >= list[right]);
//
//			series.push_back(one_series);
//		}
//
//		if (series.size() == 2 && series[1].size() == 1)
//			break;
//
//		std::vector<std::vector<int>> result_left;
//		std::vector<std::vector<int>> result_right;
//
//		int current_series = 0;
//
//		while (current_series < series.size() - 1) {
//			result_left.push_back(merge_ascending(series[current_series], series[current_series + 1], stat));
//			current_series += 2;
//
//			if (current_series >= series.size() - 1)
//				break;
//
//			result_right.insert(result_right.begin(), merge_descending(series[current_series], series[current_series + 1], stat));
//			current_series += 2;
//		}
//
//		list.clear();
//		for (auto& s : result_left)
//			list.insert(list.end(), s.begin(), s.end());
//		for (auto& s : result_right)
//			list.insert(list.end(), s.begin(), s.end());
//	}
//
//	return stat;
//}
	template<typename T>
	std::vector<T> random(T a, T b, int n, size_t i) {
		std::vector<int> res;
		std::mt19937 gen(i);
		std::uniform_int_distribution<> distribution(a, b);
		for (size_t i = 0; i < n; i++) {
			size_t x = distribution(generator);
			res.push_back(x);
		}//добавить рандомное урпавление seed
		return res;
	}

}
