#include <iostream>
#include <vector>
#include <string>
#include <cmath>

int main(void) {

    int N, M;
    std::string S;
    std::cin >> N >> M;
    std::cin >> S;
    
    std::vector<int> num_1(N);
    std::vector<int> num_2(N);
    int sequence_count = 0;

    for (std::size_t i = 0; i < N; ++i) {
        if (S[i] == '0') {
            sequence_count++;
        }
        else if (S[i] == '1') {
            num_1[sequence_count]++;
        }
        else {
            num_2[sequence_count]++;
        }
    }

    int max_num = 0;
    for (std::size_t i = 0; i < N; ++i) {
        int ans = std::max(num_1[i] - M, 0) + num_2[i];
        if (max_num < ans) {
            max_num = ans;
        }
    }
    std::cout << max_num << std::endl;

    return 0;
}