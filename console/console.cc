#include <iostream>
#include <fstream>
#include <sort_aisd/sort_aisd.h>

using namespace std;
using namespace method_sort;

int main() {
	//stats b, c;
	//b = shell_sort(a3);
	//cout << a<<endl;
	//cout << endl << b.comparison_count << endl << b.copy_count << endl;
	/*c = sorting_choice(a3);
	cout << a3 << endl;
	cout << endl << c.comparison_count << endl << c.copy_count << endl;*/
	//std::vector hard = { 503, 87, 512, 61, 908, 170, 897, 275, 653, 426, 154, 509, 612, 677, 765, 703 };
	//stats stat = natural_merge_sort(hard);
	//cout << stat.comparison_count << endl << stat.copy_count << endl;
	//int a[] = { 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 25000, 50000, 100000 };
	//ofstream fout;
	//fout.open("C:\\Users\\natal\\aisd_sort\\algoritm_shell.txt");
	//for (size_t i = 0; i < 13; i++) {
	//	stats b;
	//	for (size_t j = 0; j < 100; j++) {
	//		auto c = random(-55000, 55000, a[i]);
	//		b+=(shell_sort(c));
	//	}
	//	cout << i << endl;
	//	fout << a[i] << ' ' << b.comparison_count/100 << ' ' << b.copy_count/100 << endl;
	//}
	//fout.close();

	//int a[] = { 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 25000, 50000, 100000 };
	//ofstream fout;
	//fout.open("C:\\Users\\natal\\aisd_sort\\algoritm_choice.txt");
	//for (size_t i = 0; i < 13; i++) {
	//	stats b;
	//	for (size_t j = 0; j < 100; j++) {
	//		auto c = random(-55000, 55000, a[i]);
	//		cout << "Iteration i = " << i << "Iteration j = " << j << endl;
	//		b += (sorting_choice(c));
	//	}
	//	fout << a[i] << ' ' << b.comparison_count / 100 << ' ' << b.copy_count / 100 << endl;
	//}
	//fout.close();

	//int a[] = { 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 25000, 50000, 100000 };
	//ofstream fout;
	//fout.open("C:\\Users\\natal\\aisd_sort\\algoritm_choice_best.txt");
	//for (size_t i = 0; i < 13; i++) {
	//	stats b;
	//	vector<int> temp(a[i]);
	//	for (size_t j = 0; j < a[i]; j++) {
	//		temp[j] = j;
	//	}
	//	b = sorting_choice(temp);
	//	fout << a[i] << ' ' << b.comparison_count << ' ' << b.copy_count << endl;
	//}
	//fout.close();


	//int a[] = { 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 25000, 50000, 100000 };
	//ofstream fout;
	//fout.open("C:\\Users\\natal\\aisd_sort\\algoritm_shell_best.txt");
	//for (size_t i = 0; i < 13; i++) {
	//	stats b;
	//	vector<int> temp(a[i]);
	//	for (size_t j = 0; j < a[i]; j++) {
	//		temp[j] = j;
	//	}
	//	b = shell_sort(temp);
	//	fout << a[i] << ' ' << b.comparison_count << ' ' << b.copy_count << endl;
	//}
	//fout.close();

	//int a[] = { 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 25000, 50000, 100000 };
	//ofstream fout;
	//fout.open("C:\\Users\\natal\\aisd_sort\\algoritm_choice_worse.txt");
	//for (size_t i = 0; i < 13; i++) {
	//	stats b;
	//	vector<int> temp(a[i]);
	//	for (size_t j = 0; j < a[i]; j++) {
	//		temp[j] = j;
	//	}
	//	reverse(temp.begin(), temp.end());
	//	b = sorting_choice(temp);
	//	fout << a[i] << ' ' << b.comparison_count << ' ' << b.copy_count << endl;
	//}
	//fout.close();

	//int a[] = { 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 25000, 50000, 100000 };
	//ofstream fout;
	//fout.open("C:\\Users\\natal\\aisd_sort\\algoritm_shell_worse.txt");
	//for (size_t i = 0; i < 13; i++) {
	//	stats b;
	//	vector<int> temp(a[i]);
	//	for (size_t j = 0; j < a[i]; j++) {
	//		temp[j] = j;
	//	}
	//	reverse(temp.begin(), temp.end());
	//	b = shell_sort(temp);
	//	fout << a[i] << ' ' << b.comparison_count << ' ' << b.copy_count << endl;
	//}
	//fout.close();

	return 0;
}