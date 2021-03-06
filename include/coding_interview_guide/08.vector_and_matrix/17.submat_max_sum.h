#ifndef _CODING_INTERVIEW_GUIDE_VECTOR_AND_MATRIX_SUBMAT_MAX_SUM_H_
#define _CODING_INTERVIEW_GUIDE_VECTOR_AND_MATRIX_SUBMAT_MAX_SUM_H_

/*
【题目】
给定一个矩阵，返回子矩阵的最大累加和。
【要求】
时间复杂度为O(m*n^2)，空间复杂度为O(m)。
*/

#include <vector>

namespace coding_interview_guide::vector_and_matrix::submat_max_sum {

class SubmatMaxSum {
public:
    static int max_sum(const std::vector<std::vector<int>>& vec);
};

}  // namespace coding_interview_guide::vector_and_matrix::submat_max_sum

#endif
