(* data is (int, int, int) present (year, month, day) *)
(* year is positive, and month is 1 ~ 12, day depend on month *)
(* ignore leap years, a day of year is a number from 1 to 365 *)

(* (1, 2, 3) < (2, 3, 4) *)
fun is_older(fs: (int * int * int), sc: (int * int * int)) =
    if #1 fs >= #1 sc orelse #2 fs >= #2 sc orelse #3 fs >= #3 sc
    then false
    else true

(* [(2012, 2, 2), (2013, 1, 2), 2] = 1 *)
fun number_in_month(data_list: (int * int * int) list, month: int) =
    if #2 (hd data_list) <> month
    then 0
    else 1 + number_in_month(tl data_list, month)

(* [(2012,2,28),(2013,12,1),(2011,3,31),(2011,4,28)],[2,3,4] = 3 *)
fun number_in_months(data_list: (int * int * int) list, m_list: int list) = 
    let
        fun data_in_month(d_month: int, dm_list: int list) = 
            if null dm_list
            then false
            else if d_month = (hd dm_list)
            then true
            else data_in_month(d_month, tl dm_list)
    in
        if null data_list
        then 0
        else if not (data_in_month(#2 (hd data_list), m_list))
        then 0 + number_in_months(tl data_list, m_list)
        else 1 + number_in_months(tl data_list, m_list)
    end
    
(* use number_in_month *)
(*! BUG *)
(* fun number_in_months(data_list: (int * int * int) list, m_list: int list) = 
    let
        fun number_in_month(data_list: (int * int * int) list, month: int) =
            if #2 (hd data_list) <> month
            then 0
            else 1 + number_in_month(tl data_list, month)
    in
        if null m_list
        then 0 + number_in_months(data_list, tl m_list)
        else number_in_month(data_list, hd m_list) + number_in_months(data_list, tl m_list)
    end *)
    
(* [(2012, 2, 2), (2013, 2, 1), (2011, 1, 3)], 2 = [(2012, 2, 2), (2013, 2, 1)] *)
(*! we need to note that the return list should contain data in the order they were originally given *)
fun dates_in_month(data_list: (int * int * int) list, month: int) =
    if null data_list
    then []
    else if #2 (hd data_list) <> month
    then dates_in_month(tl data_list, month)
    else (hd data_list) :: dates_in_month(tl data_list, month)

(* [(2012, 2, 2), (2013, 2, 1), (2011, 1, 3)], [2, 3, 1] = [(2012, 2, 2), (2013, 2, 1), (2011, 1, 3)] *)
fun dates_in_months(data_list: (int * int * int) list, m_list: int list) = 
    let
        fun data_in_month(d_month: int, dm_list: int list) = 
            if null dm_list
            then false
            else if d_month = (hd dm_list)
            then true
            else data_in_month(d_month, tl dm_list) 
    in
        if null data_list
        then []
        else if not (data_in_month(#2 (hd data_list), m_list))
        then dates_in_months(tl data_list, m_list)
        else (hd data_list) :: dates_in_months(tl data_list, m_list)
    end

(* ["hi", "there", "how", "are", "you"], 2) = "there" *)
fun get_nth(data_list: string list, n: int) = 
    if n = 1
    then hd data_list
    else get_nth(tl data_list, n - 1)

(* (2013, 6, 1) = "June 1, 2013" *)
fun date_to_string(data: (int * int * int)) = 
    let 
        val month_list = [
            "January", "February", "March", "April", "May", "June", "July",
            "August", "September", "October", "November", "December"
        ]
    in
        let
            fun get_month(n: int) = get_nth(month_list, n)
        in 
            get_month(#2 data) ^ " " ^ 
            Int.toString(#3 data) ^ ", " ^ 
            Int.toString(#1 data)
        end
    end

(* 10, [1,2,3,4,5] = 3 *)
fun number_before_reaching_sum(n: int, data_list: int list) = 
    let
        fun sum_list(sum: int, data_list: int list) = 
            if null data_list
            then 0
            else hd data_list + sum_list(tl data_list)
    in
        if xxx() < n
        then number_before_reaching_sum(n, tl data_list)
        else 1 + xxx()
    end
