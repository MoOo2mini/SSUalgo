#include <vector>
long long sum(std::vector<int> &a) {
	long long ans = 0;
	int size = 0;

	size = a.size();
	while (size > 0)
	{
		ans += a[size - 1];
		size--;
	}
	return ans;
}
