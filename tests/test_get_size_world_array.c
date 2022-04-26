/*
** EPITECH PROJECT, 2021
** MINI-SHELL-REPOT
** File description:
** test_get_size_world_array.c
*/

#include "lib.h"
#include <criterion/criterion.h>

Test(get_size_world_array0, test_get_size_world_array0)
{
    char world[][10] = {"la"};
    int my_res = get_size_world_array(world);
    cr_assert_eq(1, my_res);
}

Test(get_size_world_array1, test_get_size_world_array1)
{
    char world[][10] = {"la", "vie", "est"};
    int my_res = get_size_world_array(world);
    cr_assert_eq(3, my_res);
}

Test(get_size_world_array2, test_get_size_world_array2)
{
    char world[][10] = {"la", "vie", "est", "belle", "mais", "oups"};
    int my_res = get_size_world_array(world);
    cr_assert_eq(7, my_res);
}

// Test(get_size_world_array3, test_get_size_world_array3)
// {
//     char world[][10] =};
//     int my_res = get_size_world_array(world);
//     cr_assert_eq(6, my_res);
// }

// Test(my_strlen4, test_my_strlen_4)
// {
//     char world[][10] = {"la", "vie", "est", "belle", "mais", "oups"};
//     int my_res = get_size_world_array(world);
//     cr_assert_eq(6, my_res);
// }