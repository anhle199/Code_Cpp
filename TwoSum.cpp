// Time complexity: O(n + r).
// r = max(a) - min(a) + 1.
int TwoSum(int a[], int n) {
	unsigned int maxAbsElement = abs(a[0]);
	unsigned int minAbsElement = abs(a[0]);
	for (int i = 1; i < n; i++) {
		if (maxAbsElement < abs(a[i]))
			maxAbsElement = abs(a[i]);
		else if (minAbsElement > abs(a[i]))
			minAbsElement = abs(a[i]);
	}
	
	unsigned int m = maxAbsElement - minAbsElement + 1;
	int* count = new int[m]] {0};
	for (int i = 0; i < n; ++i)
		++count[abs(a[i]) - minAbsElement];

	int result = 0;
	for (unsigned int i = 0; i < m; i++)
		if (count[i] == 2)
			++result;

	return result;
}