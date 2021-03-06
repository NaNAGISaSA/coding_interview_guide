#include "08.vector_and_matrix/18.find_local_minimum.h"

namespace coding_interview_guide::vector_and_matrix::find_local_minimum {

int FindLocalMinimum::find(const std::vector<int>& vec) {
    int vec_size = static_cast<int>(vec.size());
    if (vec_size == 0) {
        return -1;
    } else if (vec_size == 1 || vec[0] < vec[1]) {
        return 0;
    } else if (vec[vec_size - 1] < vec[vec_size - 2]) {
        return vec_size - 1;
    }
    // 这道题可以使用二分查找，是因为当数组每一个数都不同，N>2且局部最小不在
    //   头尾时，一定存在一个局部最小在除头尾之外的中部位置
    int left = 1, right = vec_size - 2;
    int mid = 0;
    while (left < right) {
        mid = (left + right) / 2;
        if (vec[mid] > vec[mid - 1]) {
            right = mid - 1;
        } else if (vec[mid] > vec[mid + 1]) {
            left = mid + 1;
        } else {
            return mid;
        }
    }
    return left;
}

}  // namespace coding_interview_guide::vector_and_matrix::find_local_minimum
