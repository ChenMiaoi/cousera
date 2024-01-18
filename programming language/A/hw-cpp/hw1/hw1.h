/**
 * @file hw1.h
 * @author Chen Miao (chenmiao.ku@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2024-01-18
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef __HW1_H
#define __HW1_H

#include <iostream>
#include <tuple>
#include <string>
#include <vector>

using date_type = std::tuple<int, int, int>;
using date_list_type = std::vector<date_type>;

template <int pos = 0>
constexpr auto get_year(const date_type& date) {
    return std::get<pos>(date);
}

template <int pos = 1>
constexpr auto get_month(const date_type& date) {
    return std::get<pos>(date);
}

template <int pos = 2>
constexpr auto get_day(const date_type& date) {
    return std::get<pos>(date);
}

auto is_older(const date_type& fs, const date_type& sd) -> decltype(auto);

#endif //! __HW1_H
