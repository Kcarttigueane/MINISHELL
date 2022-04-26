/*
** EPITECH PROJECT, 2021
** MINI-SHELL-REPOT
** File description:
** test_get_number_of_row.c
*/

#include "../include/lib.h"
#include <criterion/criterion.h>

Test(get_number_of_row1, test_my_strlen_1)
{
    int my_res = get_number_of_row("la vie est belle", ' ');
    cr_assert_eq (4, my_res);
}

Test(get_number_of_row2, test_my_strlen_2)
{
    int my_res = get_number_of_row("        oups", ' ');
    cr_assert_eq (1, my_res);
}

Test(get_number_of_row3, test_my_strlen_3)
{
    int my_res = get_number_of_row("      c'est chaud         ", ' ');
    cr_assert_eq (2, my_res);
}

Test(get_number_of_row4, test_my_strlen_4)
{
    int my_res = get_number_of_row("coup      dur     la  ", ' ');
    cr_assert_eq (3, my_res);
}

Test(get_number_of_row5, test_my_strlen_4)
{
    int my_res = get_number_of_row("o n g a l e r e", ' ');
    cr_assert_eq (8, my_res);
}
