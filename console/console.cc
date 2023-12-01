#include <iostream>
#include <sort_aisd/sort_aisd.h>

using namespace std;
using namespace method_sort;

int main() {
	std::vector a = { 7, 6, 9, 4, 1, 2, 8, 0, 3 };
	stats b;
	b = shell_sort(a);
	cout << a;
	//b = sorting_choice(a);
	//for (size_t i = 0; i < a.size(); i++) {
	//	cout << a[i]<<" ";
	//}
	//cout << endl << b.comparison_count << endl << b.copy_count << endl;
	return 0;
}