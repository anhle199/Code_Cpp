#include "functions.h"

int sumDigits(int n) {
    int sum = 0;

    while (n != 0) {
        sum += (n % 10);
        n /= 10;
    }

    return sum;
}

bool isPrime(const int &n) {
    if (n < 2)
        return false;

    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    
    return true;
}

bool copyFile(string file_input, string file_output)
{
    ifstream in(file_input);
    ofstream out(file_output);

    if ((in.is_open() == false) && (out.is_open() == false))
        return false;

    string line;

    while (!in.eof())
    {
        getline(in, line);
        out << line;

        if (in.eof())
            break;

        out << endl;
    }

    in.close();
    out.close();

    return true;
}

bool convertFile60CharsperLine(string file_input, string file_output)
{
    ifstream in(file_input);
    ofstream out(file_output);

    if ((in.is_open() == false) && (out.is_open() == false))
        return false;

    string line, data;
    vector<string> result;
    int count = 0;

    while (!in.eof())
    {
        getline(in, line);
        data += line;

        if (data.length() >= 60) {
            result.push_back(data);
            data = "";
        }
    }

    //---------------------------------------

    for (string &str : result) {
        for (int j = 0; j < str.length(); j++) {
            out << str[j];
            count++;

            if (count == 60) {
                out << endl;
                count = 0;
            }
        }
    }

    if (count > 0 && count < 60) {
        for (int i = count; i < 60; i++)
            out << " ";
    }

    in.close();
    out.close();

    return true;
}

float countAverageChar(string file_input) {
    ifstream in(file_input);

    if (!in.is_open())
        return -1.0f;

    string line;
    int count_char = 0, count_line = 0;

    while (!in.eof()) {
        getline(in, line);
        count_char += line.length();
        count_line++;
    }

    in.close();

    if (count_line == 0) 
        return 0.0f;
    
    return ((float)count_char / count_line);
}

void printSource(string file_input) {
    ifstream in(file_input);

    if (!in.is_open()) {
        cout << "File does not exist." << endl;
        return;
    }

    string line;

    while (!in.eof()) {
        getline(in, line);
        cout << line;

        if (in.eof())
            break;

        cout << endl;
    }

    in.close();
}

bool deleteLastLine(string file_input) {
    ifstream in(file_input);

    if (!in.is_open())
        return false;
    
    string line;
    vector<string> data;

    while (!in.eof()) {
        getline(in, line);
        data.push_back(line + "\n");
    }

    data.pop_back(); // Xóa dòng cuối
    data[data.size() - 1].pop_back(); // Xóa kí tự '\n' ở dòng cuối (hiện tại).

    in.close();

    //---------------------------------------

    ofstream out(file_input);

    if (!out.is_open())
        return false;

    for (string &str : data)
        out << str;

    out.close();

    return true;
}

bool deleteEmptyLines(string file_input) {
    ifstream in(file_input);

    if (!in.is_open())
        return false;
    
    string line;
    vector<string> data;

    while (!in.eof()) {
        getline(in, line);

        if (line == "" || line[0] == '\n')
            continue;

        data.push_back(line);

        if (in.eof())
            break;
        
        data[data.size() - 1] += '\n';
    }

    in.close();

    //---------------------------------------

    ofstream out(file_input);

    if (!out.is_open())
        return false;

    int number_of_lines = data.size();

    for (string &str : data) {
        out << str;
        number_of_lines--;
    }

    out.close();

    return true;
}

bool insert7thLine(string file_input) {
    ifstream in(file_input);

    if (!in.is_open())
        return false;
    
    string line;
    vector<string> data;

    while (!in.eof()) {
        getline(in, line);   
        data.push_back(line + "\n");
    }

    data[data.size() - 1].pop_back(); // Xóa kí tự '\n' ở dòng cuối (hiện tại).
    if (data.size() >= 7) 
        data.insert(data.begin() + 7, "\n");

    in.close();

    //---------------------------------------

    ofstream out(file_input);

    if (!out.is_open())
        return false;

    for (string &str : data)
        out << str;

    out.close();

    return true;
}

bool insertDoubleSpaced(string file_input) {
    ifstream in(file_input);

    if (!in.is_open())
        return false;
    
    string line;
    vector<string> data;

    while (!in.eof()) {
        getline(in, line);   
        data.push_back(line + "\n\n" );
    }

    // Xóa 2 kí tự '\n' ở dòng cuối (hiện tại).
    data[data.size() - 1].pop_back();
    data[data.size() - 1].pop_back();

    in.close();

    //---------------------------------------

    ofstream out(file_input);

    if (!out.is_open())
        return false;

    for (string &str : data)
        out << str;

    out.close();

    return true;
}

bool insert2thLine(string file_input) {
    ifstream in(file_input);

    if (!in.is_open())
        return false;
    
    string line, line_2;
    vector<string> data;

    while (!in.eof()) {
        getline(in, line);   
        data.push_back(line + "\n" );
    }

    
    line_2 = data[1];
    for (vector<string>::iterator it = data.begin(); it != data.end(); it += 2) {
        it = data.insert(it, line_2);
    }

    data[data.size() - 1].pop_back(); // Xóa kí tự '\n' ở dòng cuối (hiện tại).

    in.close();

    //---------------------------------------

    ofstream out(file_input);

    if (!out.is_open())
        return false;

    for (string &str : data) 
        out << str;

    out.close();

    return true;
}

bool delete2FirstChars(string file_input) {
    ifstream in(file_input);

    if (!in.is_open())
        return false;
    
    string line;
    vector<string> data;

    while (!in.eof()) {
        getline(in, line);

        if (line.size() < 2) // Những dòng ít hơn 2 kí tự thì không cần giữ lại.
            continue;

        line.erase(line.begin(), line.begin() + 1); // Xoá 2 kí tự đầu mỗi dòng.
        data.push_back(line + "\n");
    }

    data[data.size() - 1].pop_back(); // Xóa kí tự '\n' ở dòng cuối (hiện tại).

    in.close();

    //---------------------------------------

    ofstream out(file_input);

    if (!out.is_open())
        return false;

    for (string &str : data)
        out << str;

    out.close();

    return true;
}

bool writeListOddNumbers(string file_output, const int &n) {
    ofstream out(file_output);

    if (!out.is_open())
        return false;

    for (int i = 11; i < n; i += 2) {
        if (sumDigits(i) % 2 == 0)
            out << i << " ";
    }    

    out.close();

    return true;
}

int countPrimes(string file_input) {
    ifstream in(file_input);

    if (!in.is_open())
        return -1;

    int number, count_prime = 0;

    while (!in.eof()) {
        in >> number;

        if (isPrime(number))
            count_prime++;
    }

    in.close();

    return count_prime;
}

int sumMatrix(string file_input) {
    ifstream in(file_input);

    if (!in.is_open())
        return -1;

    int rows, cols, item, sum = 0;

    in >> rows >> cols;

    while (!in.eof()) {
        in >> item;
        sum += item;
    }

    in.close();

    return sum;
}

void sortListNameV1(string file_input) {
    ifstream in(file_input);

    if (!in.is_open()) {
        cout << "File does not exist." << endl;
        return;
    }

    int number_of_names;
    string name;
    set<string> list_names;

    in >> number_of_names;
    in.ignore();

    while (!in.eof()) {
        getline(in, name);
        list_names.insert(name);
    }

    in.close();

    cout << "Danh sach ten cac thi sinh sau khi sap xep la: " << endl;
    for (set<string>::iterator it = list_names.begin(); it != list_names.end(); it++)
        cout << *it << endl;
}

void sortListNameV2(string file_input) {
    ifstream in(file_input);

    if (!in.is_open()) {
        cout << "File does not exist." << endl;
        return;
    }

    string name;
    set<string> list_names;

    while (!in.eof()) {
        getline(in, name);
        list_names.insert(name);
    }

    in.close();

    cout << "Danh sach ten cac thi sinh sau khi sap xep la: " << endl;
    for (set<string>::iterator it = list_names.begin(); it != list_names.end(); it++)
        cout << *it << endl;
}