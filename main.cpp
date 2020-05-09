#include <iostream>
#include "generator.h"
#include <array>
#include <sstream>

#define readable_enum_count 60

global_word_pattern settings = {
        '0', '9', 4
};

struct parse_result {
    string user_input_word;
    compare_result user_input_compare_result;
};

parse_result user_input_parser(istringstream &input_stream) {
    parse_result input_parse_result{};
//    array<char, max_item_count> word_content{};
//    compare_result input_compare_result{};
    input_stream >> input_parse_result.user_input_word;
    input_stream >> input_parse_result.user_input_compare_result.correct;
    input_stream >> input_parse_result.user_input_compare_result.half;
    return input_parse_result;
}


int main(int argc, char **argv) {
    stringstream length_stream(argv[1]);
    length_stream >> settings.item_count;
    auto global_word_list = generate_full_arrange_list(generate_unique_combination_list(settings));
    cout << "prepare finished, total " << global_word_list->size() << endl;
    while (global_word_list->size() > 1) {
        string user_input_string;
        getline(cin, user_input_string);
        istringstream user_input_stream(user_input_string);
        parse_result user_input_result = user_input_parser(user_input_stream);
        auto match_func = [user_input_result](shared_ptr<string> &str_in_list) {
            return !(compare_with(user_input_result.user_input_word, *str_in_list) == user_input_result.user_input_compare_result);
        };
        global_word_list->remove_if(match_func);
        cout << global_word_list->size() << " ";
        if (global_word_list->size() < readable_enum_count) {
            for (auto &item:*global_word_list) {
                cout << *item << " ";
            }
        }
        cout << endl;
    }
}
