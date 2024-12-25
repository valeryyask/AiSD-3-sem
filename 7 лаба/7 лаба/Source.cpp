#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>


std::vector<int> Finding(const std::vector<int>& sequence) {
    if (sequence.empty()) return {};

    std::vector<int> lengths(sequence.size(), 1);
    std::vector<int> prev(sequence.size(), -1);

    for (size_t i = 1; i < sequence.size(); ++i) {
        for (size_t j = 0; j < i; ++j) {
            if (sequence[i] > sequence[j] && lengths[i] < lengths[j] + 1) {
                lengths[i] = lengths[j] + 1;
                prev[i] = j;
            }
        }
    }

    int maxLength = 0;
    std::vector<int> candidates;
    for (size_t i = 0; i < lengths.size(); ++i) {
        if (lengths[i] > maxLength) {
            maxLength = lengths[i];
            candidates.clear(); 
            candidates.push_back(i);
        } else if (lengths[i] == maxLength) {
            candidates.push_back(i);
        }
    }

    int minValueIndex = candidates[0];
    for (int index : candidates) {
        if (sequence[index] < sequence[minValueIndex]) {
            minValueIndex = index;
        }
    }

    std::vector<int> subsequence;
    for (int i = minValueIndex; i != -1; i = prev[i]) {
        subsequence.push_back(sequence[i]);
    }
    std::reverse(subsequence.begin(), subsequence.end());

    return subsequence;
}

int main() {
    setlocale(LC_ALL, "Ru");
    int N;
    std::cout << "Введите число элементов последовательности: ";
    std::cin >> N;

    std::vector<int> sequence; 
    sequence.reserve(N);

    std::cout << "Введите элементы последовательности: ";
    for (int i = 0; i < N; ++i) {
        int element;
        std::cin >> element;
        sequence.push_back(element);
    }

    std::vector<int> longestSubsequence = Finding(sequence);

    std::cout << "Длина максимальной возрастающей подпоследовательности: "
              << longestSubsequence.size() << std::endl;
    std::cout << "Минимальная по значению возрастающая подпоследовательность: ";
    for (int num : longestSubsequence) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}