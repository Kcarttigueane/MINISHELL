/*
** EPITECH PROJECT, 2021
** RUNNER
** File description:
** test.c
*/

#include "../include/lib.h"
#include <criterion/criterion.h>

Test(my_strlen0, test_my_strlen_1)
{
    int res = strlen("La vie est belle");
    int my_res = my_strlen("La vie est belle");
    cr_assert_eq(res, my_res);
}

Test(my_strlen1, test_my_strlen_2)
{
    int res = strlen("");
    int my_res = my_strlen("");
    cr_assert_eq(res, my_res);
}

Test(my_strlen2, test_my_strlen_3)
{
    int res = strlen(" ");
    int my_res = my_strlen(" ");
    cr_assert_eq(res, my_res);
}

Test(my_strlen3, test_my_strlen_4)
{
    int res = strlen("\n");
    int my_res = my_strlen("\n");
    cr_assert_eq(res, my_res);
}

Test(my_strlen4, test_my_strlen_4)
{
    int res = strlen("AZERTYUIOPQSDFGHJKLMWXCVBNazertyuiopqsdfghjklmwxcvbn\n");
    int my_res = my_strlen("AZERTYUIOPQSDFGHJKLMWXCVBNazertyuiopqsdfghjklmwxcvbn\n");
    cr_assert_eq(res, my_res);
}