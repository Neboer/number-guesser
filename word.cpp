#pragma once

#include "word.h"


bool compare_result::operator==(const compare_result &another_result) {
    return (correct == another_result.correct) && (half == another_result.half);
}

// compare str2 with str1
compare_result compare_with(const string &str1, const string &str2) {
    compare_result current_compare_result = {0, 0};
    int str_length = str1.length();
    for (int it = 0; it < str_length; it++) {
        if (str1.at(it) == str2.at(it)) {
            current_compare_result.correct++;
        } else if (find(str1.begin(), str1.end(), str2.at(it)) != str1.end()) {
            // 找到了
            current_compare_result.half++;
        }
    }
    return current_compare_result;
}

