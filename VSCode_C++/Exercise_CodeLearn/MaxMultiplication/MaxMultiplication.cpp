// tìm 2 số có tích lớn nhất (>=0);

int maxMultiplication(std::vector<int> a)
{
    set<int> temp;

    for (int &item : a) {
        temp.insert(item);
    }

    int result_1, result_2, size = temp.size();
    set<int>::iterator it = temp.begin();

    result_1 = (*it) * (*(++it));
    
    if (size == 2 && result_1 > 0)
        return result_1;
    else if (size == 3) {
        result_2 = (*it) * (*(++it));

        if (result_1 > 0 && result_2 > 0) {
            if (result_1 > result_2)
                return result_1;
            else return result_2;
        }
        else if (result_2 > 0)
            return result_2;
        else if (result_1 > 0)
            return result_1;
    } else if (size >= 4) {
        it = temp.end();
        it--;
        result_2 = (*it) * (*(--it));

        if (result_1 > 0 && result_2 > 0) {
            if (result_1 > result_2)
                return result_1;
            else return result_2;
        }
        else if (result_2 > 0)
            return result_2;
        else if (result_1 > 0)
            return result_1;
    }

    return 0;
}
