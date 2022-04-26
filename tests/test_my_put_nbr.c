/*
** EPITECH PROJECT, 2021
** TEST
** File description:
** test_my_put_nbr.c
*/

#include "../include/lib.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
}

Test(my_put_nbr, exit_code, .init=redirect_all_stdout)
{
    my_put_nbr(1);
    cr_assert_stdout_eq_str("1");
}

Test(my_put_nbr2, exit_code, .init=redirect_all_stdout)
{
    my_put_nbr(246633);
    cr_assert_stdout_eq_str("246633");
}

Test(my_put_nbr3, exit_code, .init=redirect_all_stdout)
{
    my_put_nbr(-246633);
    cr_assert_stdout_eq_str("-246633");
}

Test(my_put_nbr4, exit_code, .init=redirect_all_stdout)
{
    my_put_nbr(-0);
    cr_assert_stdout_eq_str("0");
}

Test(my_put_nbr5, exit_code, .init=redirect_all_stdout)
{
    my_put_nbr(1654346653);
    cr_assert_stdout_eq_str("1654346653");
}