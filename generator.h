#pragma once

#include "word.h"

#include <list>
#include <string>
#include <memory>


list<shared_ptr<string>> *generate_unique_combination_list(global_word_pattern &pattern);

list<shared_ptr<string>> *generate_full_arrange_list(list<shared_ptr<string>> *combination_list);