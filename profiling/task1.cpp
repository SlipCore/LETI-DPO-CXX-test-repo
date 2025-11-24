#include <iostream>
#include <vector>
#include <chrono>
#include <random>

using namespace std;
using namespace std::chrono;

vector<int> findCommonElements(const vector<int>& arr1, const vector<int>& arr2) {
    vector<int> result;
    for (size_t i = 0; i < arr1.size(); i++) {
        for (size_t j = 0; j < arr2.size(); j++) {
            if (arr1[i] == arr2[j]) {
                bool exists = false;
                for (size_t k = 0; k < result.size(); k++) {
                    if (result[k] == arr1[i]) {
                        exists = true;
                        break;
                    }
                }
                if (!exists) {
                    result.push_back(arr1[i]);
                }
            }
        }
    }
    for (size_t i = 0; i < result.size(); i++) {
        for (size_t j = 0; j < result.size() - 1; j++) {
            if (result[j] > result[j + 1]) {
                int temp = result[j];
                result[j] = result[j + 1];
                result[j + 1] = temp;
            }
        }
    }
    
    return result;
}
vector<int> generateLargeArray(int size) {
    vector<int> arr(size);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, size * 2);
    
    for (int i = 0; i < size; i++) {
        arr[i] = dis(gen);
    }
    
    return arr;
}

int main() {
    vector<int> arr1 = generateLargeArray(20000);
    vector<int> arr2 = generateLargeArray(20000);
    cout << "Массивы созданы. Начинается поиск общих элементов..." << endl;
    auto start = high_resolution_clock::now();
    vector<int> result = findCommonElements(arr1, arr2);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(end - start);
    cout << "Выполнение заняло: " << duration.count() << " секунд" << endl;
    cout << "Найдено общих элементов: " << result.size() << endl;
    cout << "Повторный поиск для проверки..." << endl;
    vector<int> result2 = findCommonElements(arr1, arr2);
    
    return 0;
}
