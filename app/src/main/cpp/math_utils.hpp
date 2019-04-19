//
// Created by simonppg on 4/19/19.
//

#ifndef BREAK_IT_ALL_MATH_UTILS_H
#define BREAK_IT_ALL_MATH_UTILS_H

#include <vector>

using std::vector;

class Math {
public:
    static vector<float> get_grid(float width, float height, float row, float col);
    static float get_sections_size(float segment, float spaces);
};

#endif //BREAK_IT_ALL_MATH_UTILS_H
