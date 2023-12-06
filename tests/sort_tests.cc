#include <gtest/gtest.h>
#include <sort_aisd/sort_aisd.h>

using namespace std;
using namespace method_sort;

TEST(sort_test, shell_sort1) {
	vector<double> randomValues = { 0.12, 0.45, 0.78, 0.32, 0.91, 0.55, 0.23, 0.67, 0.88, 0.72, };
	vector<double> res = { 0.12, 0.23, 0.32, 0.45, 0.55, 0.67 ,0.72, 0.78, 0.88, 0.91 };
	stats stat = shell_sort(randomValues);
	EXPECT_EQ(randomValues, res);
}

TEST(sort_test, sorting_choice1) {
	vector<double> randomValues = { 0.12, 0.45, 0.78, 0.32, 0.91, 0.55, 0.23, 0.67, 0.88, 0.72, };
	vector<double> res = { 0.12, 0.23, 0.32, 0.45, 0.55, 0.67 ,0.72, 0.78, 0.88, 0.91 };
	stats stat = sorting_choice(randomValues);
	EXPECT_EQ(randomValues, res);
}

TEST(sort_test, shell_sort2) {
	vector<Person> persons;
	persons.push_back(Person(1963, "Lester Olsen"));
	persons.push_back(Person(1964, "Lee Levy"));
	persons.push_back(Person(1963, "Libby Malone"));
	persons.push_back(Person(1967, "Maja Shannon"));

	vector<Person> person;
	person.push_back(Person(1963, "Libby Malone"));
	person.push_back(Person(1967, "Maja Shannon"));
	person.push_back(Person(1963, "Lester Olsen"));
	person.push_back(Person(1964, "Lee Levy"));


}