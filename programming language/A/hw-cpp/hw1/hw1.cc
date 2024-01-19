#include "hw1.h"
#include <algorithm>
#include <string>
#include <vector>

/**
 * is_older
 * evaluate to true if the first argument is a date that comes before the second
 */
auto is_older(const date_type& fs, const date_type& sd) -> bool {
  if (get_year(fs) > get_year(sd)) return false;
  else if (get_year(fs) == get_year(sd)) {
    if (get_month(fs) > get_month(sd)) return false;
    else if (get_month(fs) == get_month(sd)) {
      if (get_day(fs) >= get_day(sd)) return false;
      return true;
    } else return true;
  } else return true;
}

/**
 * number_in_month
 * take a list of dates and a list of months and return how many dates in
 */
auto number_in_month(const date_list_type& dates, int month) -> int {
  int count = 0; 
  for (const auto& date : dates) {
    if (std::get<1>(date) == month) count++;
  }
  return count;
}

/**
 * number_in_months 
 */
auto number_in_months(const date_list_type &dates, const std::vector<int> &m_list) -> int {
  auto check = [=](const date_type& date) -> bool {
    return std::find(m_list.cbegin(), m_list.cend(), get_month(date)) != m_list.end();
  };
  int count = 0;
  for (const auto& date :dates) {
    if (check(date)) count++;
  }

  return count;
}

/**
 * dates_in_month
 *  
 */
auto dates_in_month(const date_list_type &dates, int month) -> date_list_type {
  auto check = [=](const date_type& date) -> bool {
    return get_month(date) == month;
  };
  date_list_type ret;
  for (const auto& date : dates) {
    if (check(date)) ret.emplace_back(date); 
  }
  return ret;
}

auto dates_in_months(const date_list_type &dates, const std::vector<int> &m_list) -> date_list_type {
  auto check = [=](const date_type& date) -> bool {
    return std::find(m_list.cbegin(), m_list.cend(), get_month(date)) != m_list.cend();
  };
  date_list_type ret;
  for (const auto& date : dates) {
    if (check(date)) ret.emplace_back(date);
  }
  return ret;
}

auto get_nth(const std::vector<std::string> &datas, int n) -> const std::string& {
  if (n == 1) 
    return datas.front();
  return get_nth(std::vector<std::string>{datas.begin() + 1, datas.end()}, n - 1);
}

auto data_to_string(const date_type &date) -> const std::string& {

}
