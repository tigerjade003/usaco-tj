#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    unordered_set<int> mentioned;
    vector<int> nums(N, -1);
    vector<int> nums2(K);

    for (int i = 0; i < K; ++i) {
        int k;
        cin >> k;
        --k;
        nums[k] = i;
        mentioned.insert(k);
    }

    vector<int> test1(N, -1);
    for (int i = 0; i < K; ++i) {
        cin >> nums2[i];
        --nums2[i];
        mentioned.insert(nums2[i]);
        test1[nums2[i]] = i;
    }

    vector<int> test2(N, -1);
    vector<int> nums3(K);
    for (int i = 0; i < K; ++i) {
        nums3[i] = nums2[K - i - 1];
        test2[nums3[i]] = i;
    }

    int count = N - mentioned.size();
    vector<int> differences(N, 0);
    vector<int> differences2(N, 0);

    for (int i = 0; i < N; ++i) {
        if (test1[i] != -1 && nums[i] != -1) {
            differences[(test1[i] - nums[i] + N) % K]++;
            differences2[(test2[i] - nums[i] + N) % K]++;
        }
    }

    int maxVal = 0;
    for (int i = 0; i < N; ++i) {
        maxVal = max(maxVal, differences[i]);
        maxVal = max(maxVal, differences2[i]);
    }

    cout << maxVal + count << endl;

    return 0;
}
