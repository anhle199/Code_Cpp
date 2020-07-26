std::vector<int> linearTimeSort(std::vector<int> arr)
{
    vector<int> count(*max_element(arr.begin(), arr.end()) + 1, 0);

    for (const int &item : arr)
        count[item]++;

    for (int i = 1; i < count.size(); i++)
        count[i] += count[i - 1];

    vector<int> result;
    int tmp = 0;

    for (int i = 0; i < count.size(); i++) {
        tmp = count[i];
        if (i != 0) 
            tmp = count[i] - count[i - 1];

        while (tmp-- > 0)
            result.push_back(i);
    }

    return result;
}