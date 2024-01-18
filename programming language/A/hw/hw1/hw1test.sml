(* Homework1 Simple Test *)
(* These are basic test cases. Passing these tests does not guarantee that your code will pass the actual homework grader *)
(* To run the test, add a new line to the top of this file: use "homeworkname.sml"; *)
(* All the tests should evaluate to true. For example, the REPL should say: val test1 = true : bool *)


val test1_1 = is_older ((1,2,3),(2,3,4)) = true
val test1_2 = is_older ((2,3,4),(2,3,4)) = false
val test1_3 = is_older ((3,2,2),(2,3,4)) = false

val test2 = number_in_month ([(2012,2,28),(2013,12,1)],2) = 1

val test3_1 =
    number_in_months ([(2012,2,28),(2013,12,1),(2011,3,31),(2011,4,28)],[2,3,4]) = 3

val test3_2 =
    number_in_months ([
        (2012,2,28),(2013,12,1),(2011,3,31),(2011,4,28),
        (2012,2,28),(2013,12,1),(2011,3,31),(2011,4,28),
        (2012,2,28),(2013,12,1),(2011,3,31),(2011,4,28),
        (2012,2,28),(2013,12,1),(2011,3,31),(2011,4,28),
        (2012,2,28),(2013,12,1),(2011,3,31),(2011,4,28),
        (2012,2,28),(2013,12,1),(2011,3,31),(2011,4,28)
    ],[2,3,4]) = 18

val test4_1 = dates_in_month ([(2012,2,28),(2013,12,1)],2) = [(2012,2,28)]
val test4_2 = dates_in_month ([
        (2012,2,28),(2012,2,28),(2012,2,28),(2013,12,1)
    ],2) = [(2012,2,28),(2012,2,28),(2012,2,28)]
val test4_3 = dates_in_month ([
        (2012,2,28),(2013,12,1),(2012,2,28),(2012,2,28)
    ],2) = [(2012,2,28),(2012,2,28),(2012,2,28)]

val test5 = dates_in_months ([(2012,2,28),(2013,12,1),(2011,3,31),(2011,4,28)],[2,3,4]) = [(2012,2,28),(2011,3,31),(2011,4,28)]

val test6_1 = get_nth (["hi", "there", "how", "are", "you"], 1) = "hi"
val test6_2 = get_nth (["hi", "there", "how", "are", "you"], 2) = "there"
val test6_3 = get_nth (["hi", "there", "how", "are", "you"], 3) = "how"
val test6_4 = get_nth (["hi", "there", "how", "are", "you"], 4) = "are"
val test6_5 = get_nth (["hi", "there", "how", "are", "you"], 5) = "you"

val test7_1 = date_to_string (2013, 6, 1) = "June 1, 2013"
val test7_2 = date_to_string (2013, 2, 1) = "February 1, 2013"
val test7_3 = date_to_string (2013, 4, 1) = "April 1, 2013"
val test7_4 = date_to_string (2013, 8, 1) = "August 1, 2013"

val test8 = number_before_reaching_sum (10, [1,2,3,4,5]) = 3

(* val test9 = what_month 70 = 3

val test10 = month_range (31, 34) = [1,2,2,2]

val test11 = oldest([(2012,2,28),(2011,3,31),(2011,4,28)]) = SOME (2011,3,31) *)