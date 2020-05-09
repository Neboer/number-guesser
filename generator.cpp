#include "generator.h"

using namespace std;

void insert_words_with_more_item_to_list(shared_ptr<string> &generator_word, const global_word_pattern &pattern,
                                         list<shared_ptr<string>> *dest_list) {
    int generate_word_length = generator_word->size();
    char highest = generator_word->at(generate_word_length - 1);
    if (highest == pattern.max_char) return;
    else {
        for (char i = ++highest; i <= pattern.max_char; i++) {
            shared_ptr<string> current_generate_string = make_shared<string>(*generator_word);
            current_generate_string->push_back(i);
            dest_list->push_back(current_generate_string);
        }
    }
}

list<shared_ptr<string>> *generate_unique_combination_list(global_word_pattern &pattern) {
    list<shared_ptr<string>> *previous_list;
    auto deepest_list = new list<shared_ptr<string>>();
    for (char a = pattern.min_char; a <= pattern.max_char; a++) {
        auto item_str = make_shared<string>(1, a);
        deepest_list->push_back(item_str);
    }
    for (int current_depth = 1; current_depth < pattern.item_count; current_depth++) {
        previous_list = deepest_list;
        deepest_list = new list<shared_ptr<string>>();
        for (auto &prev_str_item:*previous_list) {
            insert_words_with_more_item_to_list(prev_str_item, pattern, deepest_list);
        }
        delete previous_list;
    }
    return deepest_list;
}

void generate_full_arrange_word(shared_ptr<string> input_str, list<shared_ptr<string>> &dest_list) {
    int input_size = input_str->size();
    if (input_size == 2) {
        dest_list.push_back(input_str);
        shared_ptr<string> another_str = make_shared<string>();
        (*another_str) += input_str->at(1);
        (*another_str) += input_str->at(0);
        dest_list.push_back(another_str);
        return;
    } else {
        list<shared_ptr<string>> detached_head_arrange_result = list<shared_ptr<string>>();
        char head = input_str->at(0);
        string temp_detached = input_str->substr(1, string::npos);
        auto rest_str = make_shared<string>(temp_detached);
        generate_full_arrange_word(rest_str, detached_head_arrange_result);
        for (auto &detached_head_str:detached_head_arrange_result) {
            for (int pos = 0; pos < input_size; pos++) {
                auto answer_string = make_shared<string>();
                *answer_string = *detached_head_str;
                answer_string->insert(pos, 1, head);
                dest_list.push_back(answer_string);
            }
        }
    }
}

list<shared_ptr<string>> *generate_full_arrange_list(list<shared_ptr<string>> *combination_list) {
    auto result_list = new list<shared_ptr<string>>();
    for (auto &word:*combination_list) {
        generate_full_arrange_word(word, *result_list);
    }
    return result_list;
}