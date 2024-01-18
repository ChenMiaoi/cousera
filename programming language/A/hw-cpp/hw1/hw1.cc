#include "hw1.h"

/**
 * is_older
 * evaluate to true if the first argument is a date that comes before the second
 */
auto is_older(const date_type& fs, const date_type& sd) -> decltype(auto) {
  if (std::get<0>(fs) >= std::get<0>(sd) || 
    std::get<1>(fs) >= std::get<1>(sd) ||
    std::get<2>(fs) >= std::get<2>(sd)) 
    return false;

  return true;
}

/**
 * number_in_month
 * take a list of dates and a list of months and return how many dates in
 */
auto number_in_month(const date_list_type& dates, int month) {
  int count = 0; 
  for (const auto& date : dates) {
    if (std::get<1>(date) == month) count++;
  }
  return count;
}