#include <algorithm>

#include "08.vector_and_matrix/12.max_subarr_len_le_k.h"

namespace coding_interview_guide::vector_and_matrix::max_subarr_len_le_k {

unsigned int MaxSubarrLenLeK::max_len(const std::vector<int>& vec, int k) {
    size_t vec_size = vec.size();
    if (vec_size == 0) {
        return 0U;
    }
    std::vector<int> sum_vec(vec_size + 1, 0), help_vec(vec_size + 1, 0);
    for (size_t i = 1; i <= vec_size; ++i) {
        sum_vec[i] = sum_vec[i - 1] + vec[i - 1];
        help_vec[i] = std::max(help_vec[i - 1], sum_vec[i]);
    }

    auto get_leftmost = [&help_vec](int right, int number) {
        int left = 0, middle = 0;
        int left_most = -1;
        while (left <= right) {
            middle = left + (right - left) / 2;
            if (help_vec[middle] >= number) {
                left_most = middle;
                right = middle - 1;
            } else {
                left = middle + 1;
            }
        }
        return left_most;
    };

    unsigned int max_length = 0U;
    for (size_t i = 1; i <= vec_size; ++i) {
        int left_most = get_leftmost(static_cast<int>(i), sum_vec[i] - k);
        if (left_most != -1) {
            max_length = std::max(max_length, static_cast<unsigned int>(i - left_most));
        }
    }
    return max_length;
}

unsigned int MaxSubarrLenLeK::max_len_sliding_window(const std::vector<int>& vec, int k) {
    size_t vec_size = vec.size();
    if (vec_size == 0) {
        return 0U;
    }
    std::vector<int> min_sum_vec(vec_size, vec[vec_size - 1]);
    std::vector<size_t> min_sum_index_vec(vec_size, vec_size - 1);
    for (size_t i = vec_size - 2; i < vec_size; --i) {
        if (min_sum_vec[i + 1] > 0) {
            min_sum_vec[i] = vec[i];
            min_sum_index_vec[i] = i;
        } else {
            min_sum_vec[i] = vec[i] + min_sum_vec[i + 1];
            min_sum_index_vec[i] = min_sum_index_vec[i + 1];
        }
    }
    size_t right_index = 0;
    int curr_sum = 0;
    unsigned int max_length = 0U;
    for (size_t i = 0; i < vec_size; ++i) {
        while (right_index < vec_size && curr_sum + min_sum_vec[right_index] <= k) {
            curr_sum += min_sum_vec[right_index];
            right_index = min_sum_index_vec[right_index] + 1;
        }
        max_length = std::max(max_length, static_cast<unsigned int>(right_index - i));
        if (right_index == vec_size) {
            return max_length;
        }
        if (right_index == i) {
            ++right_index;
        } else {
            curr_sum -= vec[i];
        }
    }
    return max_length;
}

}  // namespace coding_interview_guide::vector_and_matrix::max_subarr_len_le_k
