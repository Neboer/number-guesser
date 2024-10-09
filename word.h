#pragma once
#include <string>
#include <array>

using namespace std;

struct compare_result {
    int correct = 0;
    int half = 0;

    bool operator==(const compare_result &another_result);
};

struct global_word_pattern {
    char min_char;
    char max_char;
    size_t item_count;
};


compare_result compare_with(const string &str1, const string &str2);