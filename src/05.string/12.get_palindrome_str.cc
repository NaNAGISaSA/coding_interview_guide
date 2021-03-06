#include <algorithm>
#include <vector>

#include "05.string/12.get_palindrome_str.h"

namespace coding_interview_guide::string::get_palindrome_str {

namespace {
std::string recurse_get_palindrome_str(const std::vector<std::vector<size_t>>& dp_matrix,
                                       const std::string& str,
                                       size_t from,
                                       size_t to) {
    if (dp_matrix[from][to] == 0) {
        return str.substr(from, to - from + 1);
    }
    if (str[from] == str[to] && dp_matrix[from][to] == dp_matrix[from + 1][to - 1]) {
        return str[from] + recurse_get_palindrome_str(dp_matrix, str, from + 1, to - 1) + str[to];
    } else if (dp_matrix[from][to] == dp_matrix[from][to - 1] + 1) {
        return str[to] + recurse_get_palindrome_str(dp_matrix, str, from, to - 1) + str[to];
    } else {
        return str[from] + recurse_get_palindrome_str(dp_matrix, str, from + 1, to) + str[from];
    }
}
}  // namespace

std::string AddMinCharToGetPalindromeStr::get_palindrome_str(const std::string& str) {
    size_t str_size = str.size();
    std::vector<std::vector<size_t>> dp_matrix(str_size, std::vector<size_t>(str_size, 0));
    for (size_t i = str_size - 2; i < str_size; --i) {
        dp_matrix[i][i + 1] = str[i] == str[i + 1] ? 0 : 1;
        for (size_t j = i + 2; j < str_size; ++j) {
            dp_matrix[i][j] = std::min(dp_matrix[i + 1][j], dp_matrix[i][j - 1]) + 1;
            if (str[i] == str[j]) {
                dp_matrix[i][j] = std::min(dp_matrix[i + 1][j - 1], dp_matrix[i][j]);
            }
        }
    }
    return recurse_get_palindrome_str(dp_matrix, str, 0, str_size - 1);
}

std::string AddMinCharToGetPalindromeStr::get_palindrome_str_advanced(const std::string& str,
                                                                      const std::string& strlps) {
    std::string result(2 * str.size() - strlps.size(), '\0');
    size_t lstr = 0, rstr = str.size() - 1;
    size_t lstrlps = 0, rstrlps = strlps.size() - 1;
    size_t lres = 0, rres = result.size() - 1;
    while (lstr <= rstr) {
        if (str[lstr] != strlps[lstrlps]) {
            result[lres++] = str[lstr];
            result[rres--] = str[lstr++];
        }
        if (str[rstr] != strlps[rstrlps]) {
            result[lres++] = str[rstr];
            result[rres--] = str[rstr--];
        }
        if (str[lstr] == strlps[lstrlps] && str[rstr] == strlps[rstrlps]) {
            result[lres++] = str[lstr++];
            result[rres--] = str[rstr--];
            lstrlps++;
            rstrlps--;
        }
    }
    return result;
}

}  // namespace coding_interview_guide::string::get_palindrome_str
