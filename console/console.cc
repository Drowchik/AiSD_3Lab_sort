#include <iostream>
#include <sort_aisd/sort_aisd.h>

using namespace std;
using namespace method_sort;

int main() {
	std::vector a = { 7, 6, 9, 4, 1, 2, 8, 0, 3 };
	std::vector a2 = { 7, 6, 9, 4, 1, 2, 8, 0, 3 };
	stats b, c;
	b = shell_sort(a);
	cout << a<<endl;
	cout << endl << b.comparison_count << endl << b.copy_count << endl;
	c = sorting_choice(a2);
	cout << a2 << endl;
	cout << endl << c.comparison_count << endl << c.copy_count << endl;
	return 0;
}