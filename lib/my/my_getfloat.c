/*
** EPITECH PROJECT, 2020
** my_getfloat
** File description:
** my_getfloat
*/

float my_getfloat(char const *str)
{
    int size = my_strlen(str);
    int entier = my_getnbr(str);
    int c = 0;
    float decimal = 0.0;

    for (;str[c] >=  '0' && str[c] <= '9'; c++, size--);
    if (str[c] != '\0' && str[0] != '-') {
        c++;
        size--;
    }
    for (;str[c] != '\0' && str[c] <= '9' && str[c] >= '0'; c++)
        decimal = (decimal * 10) + (str[c] - '0');
    for (;size > 0; size--)
        decimal /= 10;
    decimal = entier + decimal;
    return (decimal);
}