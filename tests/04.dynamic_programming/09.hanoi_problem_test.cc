#include <gtest/gtest.h>

#include "04.dynamic_programming/09.hanoi_problem.h"

using namespace coding_interview_guide::dynamic_programming::hanoi_problem;

TEST(HANOI_PROBLEM, HANOI_PROBLEM_ORIGIN_EXAMPLE_TEST) {
    testing::internal::CaptureStdout();
    HanoiProblem::origin_problem(3);
    std::string truth =
        "move from left to right\nmove from left to mid\nmove from right to mid\nmove from left to right\n"
        "move from mid to left\nmove from mid to right\nmove from left to right\n";
    ASSERT_EQ(testing::internal::GetCapturedStdout(), truth);
}

TEST(HANOI_PROBLEM, HANOI_PROBLEM_ADVANCED_EXAMPLE_TEST) {
    ASSERT_EQ(HanoiProblem::advanced_problem({1, 1}), 0);
    ASSERT_EQ(HanoiProblem::advanced_problem({2, 1}), 1);
    ASSERT_EQ(HanoiProblem::advanced_problem({3, 3}), 3);
    ASSERT_EQ(HanoiProblem::advanced_problem({3, 2, 3}), -1);
}

TEST(HANOI_PROBLEM, HANOI_PROBLEM_ADVANCED_DP_EXAMPLE_TEST) {
    ASSERT_EQ(HanoiProblem::advanced_problem_dp({1, 1}), 0);
    ASSERT_EQ(HanoiProblem::advanced_problem_dp({2, 1}), 1);
    ASSERT_EQ(HanoiProblem::advanced_problem_dp({3, 3}), 3);
    ASSERT_EQ(HanoiProblem::advanced_problem_dp({3, 2, 3}), -1);
}
