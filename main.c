/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include <math.h>
#include "include/mymath.h"
#include <stdio.h>

void translation(float x, float y , char *nb1, char *nb2)
{
    float opp[2] = {my_getfloat(nb1), my_getfloat(nb2)};
    float op[2] = {x, y};
    float res[2] = {0, 0};
    float matrice[3][3] = { {1, 0, 0}, {0, 1, 0}, {0, 0, 1} };

    for (int c = 0; c < 2; c++) {
        res[c] = op[c] + opp[c];
    }
    matrice[0][2] = opp[0];
    matrice[1][2] = opp[1];
    printf("Translation along vector (%.0f, %.0f)\n", opp[0], opp[1]);
    printf("%.2f\t%.2f\t%.2f\n", matrice[0][0], matrice[0][1], matrice[0][2]);
    printf("%.2f\t%.2f\t%.2f\n", matrice[1][0], matrice[1][1], matrice[1][2]);
    printf("%.2f\t%.2f\t%.2f\n", matrice[2][0], matrice[2][1], matrice[2][2]);
    printf("(%.2f, %.2f) => (%.2f, %.2f)\n", x, y, res[0], res[1]);
}

void homothety(float x, float y , char *nb1, char *nb2) //ok
{
    float opp[2] = {my_getfloat(nb1), my_getfloat(nb2)};
    float op[2] = {x, y};
    float res[2] = {0, 0};
    float matrice[3][3] = { {1, 0, 0}, {0, 1, 0}, {0, 0, 1} };

    for (int c = 0; c < 2; c++) 
        res[c] = op[c] + opp[c];
    matrice[0][0] = opp[0];
    matrice[1][1] = opp[1];
    printf("Translation along vector (%.0f, %.0f)\n", opp[0], opp[1]);
    printf("%.2f\t%.2f\t%.2f\n", matrice[0][0], matrice[0][1], matrice[0][2]);
    printf("%.2f\t%.2f\t%.2f\n", matrice[1][0], matrice[1][1], matrice[1][2]);
    printf("%.2f\t%.2f\t%.2f\n", matrice[2][0], matrice[2][1], matrice[2][2]);
    printf("(%.2f, %.2f) => (%.2f, %.2f)\n", x, y, res[0], res[1]);
}

void symetry(float x, float y , char *a)
{
    float res[2] = {0, 0};
    float op[2] = {x, y};
    float pi = 3.141592;
    float angle = my_getfloat(a);
    float angle_rad = (angle * pi) / 180;
    float s[2][2] = { {cosf(angle_rad * 2), sinf(angle_rad * 2)}, {sinf(angle_rad * 2), -cos(angle_rad * 2)}};
    int i = 0;
    int j = 0;
    float matrice_first[3][3] = { {1, 0, 0}, {0, 1, 0}, {0, 0, 1} };
    float matrice[3][3] = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };

    for(; i < 2; i++) {
        for (j = 0; j < 2; j++)
            res[i] += op[j] * s[i][j];
    }
    float matrice_res[3][3] = { {res[0], res[1], 0}, {res[1], -res[0], 0}, {0, 0, 1} };

    for (int a = 0; a < 3; a++) {
        for (int b = 0; b < 3; b++) {
            for (int k = 0; k < 3; k++)
                matrice[a][b] += matrice_res[a][b] * matrice_first[k][b];
        }
    }
    printf("Reflection over an axis with an inclination angle of %s degrees\n", a);
    printf("%.2f\t%.2f\t%.2f\n", matrice[0][0], matrice[0][1], matrice[0][2]);
    printf("%.2f\t%.2f\t%.2f\n", matrice[1][0], matrice[1][1], matrice[1][2]);
    printf("%.2f\t%.2f\t%.2f\n", matrice[2][0], matrice[2][1], matrice[2][2]);
    printf("(%.2f, %.2f) => (%.2f, %.2f)\n", x, y, res[0], res[1]);
}

void scaling(float x, float y, char *nb1, char *nb2)
{
    float opp[2][2] = {{my_getfloat(nb1), 0}, {0, my_getfloat(nb2)}};
    float op[2] = {x, y};
    float res[2] = {0 , 0};
    int i = 0;
    int j = 0;
    float matrice_first[3][3] = { {1, 0, 0}, {0, 1, 0}, {0, 0, 1} };
    float matrice[3][3] = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };

    printf("Scaling by factors %d and %d\n", my_getnbr(nb1), my_getnbr(nb2));
    for (; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            res[i] += opp[i][j] * op[j];
        }
    }
    float matrice_res[3][3] = {{res[0], res[1], 0}, {res[1], res[0], 0}, {0, 0, 1}};
    for (int a = 0; a < 3; a++) {
        for (int b = 0; b < 3; b++) {
            for (int k = 0; k < 3; k++)
                matrice[a][b] += matrice_res[a][b] * matrice_first[k][b];
        }
    }
    printf("%.2f\t%.2f\t%.2f\n", matrice[0][0], matrice[0][1], matrice[0][2]);
    printf("%.2f\t%.2f\t%.2f\n", matrice[1][0], matrice[1][1], matrice[1][2]);
    printf("%.2f\t%.2f\t%.2f\n", matrice[2][0], matrice[2][1], matrice[2][2]);
    printf("(%.2f, %.2f) => (%.2f, %.2f)\n", x, y ,res[0], res[1]);
}

void rotation(float x, float y, char *a) //ok ?
{
    float angle = my_getfloat(a);
    float pi = 3.141592;
    float v[2] = {x , y};
    float angle_rad = (angle * pi) / 180;
    float m[2][2] = { {cosf(angle_rad), -sinf(angle_rad)}, {sinf(angle_rad), cos(angle_rad)}};
    int i = 0;
    int j = 0;
    float res[2] = {0, 0};
    float matrice_first[3][3] = { {1, 0, 0}, {0, 1, 0}, {0, 0, 1} };
    float matrice[3][3] = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };

    for (; i < 2; i++) {
        for (j = 0; j < 2; j++)
            res[i] += m[i][j] * v[j];
    }

    if (angle == 360 && y == 0)
        res[1] = 0;
    
    float matrice_res[3][3] = {{res[0], -res[1], 0}, {res[1], res[0], 0}, {0, 0, 1}};
    
    for (int a = 0; a < 3; a++) {
        for (int b = 0; b < 3; b++) {
            for (int k = 0; k < 3; k++)
                matrice[a][b] += matrice_res[a][b] * matrice_first[k][b];
        }
    }
    
    printf("%.2f\t%.2f\t%.2f\n", matrice[0][0], matrice[0][1], matrice[0][2]);
    printf("%.2f\t%.2f\t%.2f\n", matrice[1][0], matrice[1][1], matrice[1][2]);
    printf("%.2f\t%.2f\t%.2f\n", matrice[2][0], matrice[2][1], matrice[2][2]);
    printf("(%.2f, %.2f) => (%.2f, %.2f)\n", x, y ,res[0], res[1]);
}

int error(int argc, char **argv)
{
    int i = 1;
    int j = 0;

    for (; i < 3; i++) {
        j = 0;
        for (; argv[i][j] != '\0'; j++) {
            if (!(argv[i][j] < '9' && argv[i][j] > '0')) {
                if (!(argv[i][j] == '-' || argv[i][j] == '.'))
                    return (84);
                }
            }
        }
    i++;
    for (; i < argc; i++) {
        j = 0;
        for (; argv[i][j] != '\0'; j++) {
            if (!(argv[i][j] < '9' && argv[i][j] > '0')) {
                if (!(argv[i][j] == '-' || argv[i][j] == '.'))
                    return (84);
            }
        }
    }
    return (0);
}

int main(int argc, char **argv)
{
    if (argc < 2 || argc == 3) {
        write(2, "Error", 5);
        return (84);
    }
    if (argc == 2) {
        char *test = argv[1];
        if (test[0] == '-' && test[1] == 'h') {
            printf("USAGE\n    ./102architect x y transfo1 arg11 [arg12] [transfo2 arg12 [arg22]] ...\n\n");
            printf("DESCRITPION\n    x   abscissa of the original point\n    y   ordinate of the original point");
            printf("\n\n    transfo arg1 [arg2]\n    -t i j  translation along vector (i, j)\n");
            printf("    -h m n homothety with center 0 and scale factors m along c-axis and n along y-axis\n");
            printf("    -z m n  scaling by factors m (x-axis) and n (y-axis)\n");
            printf("    -r d    rotation centered in 0 by a d degree angle\n");
            printf("    -s d    reflection over the axis passing through 0 with an inclination\n");
            printf("            angle of d degrees\n");
            return (0);
        } else {
            write(2, "Error", 5);
            return (84);
        }
    }

    float x = my_getfloat(argv[1]);
    float y = my_getfloat(argv[2]);
    int c = 3;
    if (argv[c][1] == 'z') {
        if (argc < 6 || argc > 6 || error(argc, argv) == 84) {
            write(2, "Error", 5);
            return (84);
        }
        scaling(x, y, argv[c + 1], argv[c + 2]);
        c += 2;
    }
    if (argv[c][1] == 'h') {
        if (argc < 6 || argc > 6 || error(argc, argv) == 84) {
            write(2, "Error", 5);
            return (84);
        }
        homothety(x, y, argv[c + 1], argv[c + 2]);
        c += 2;
    }
    if (argv[c][1] == 't') {
        if (argc < 6 || argc > 6 || error(argc, argv) == 84) {
            write(2, "Error", 5);
            return (84);
        }
        translation(x, y, argv[c + 1], argv[c + 2]);
        c += 2;
    }
    if (argv[c][1] == 'r') {
        if (argc < 5 || argc > 5 || error(argc, argv) == 84) {
            write(2, "Error", 5);
            return (84);
    }
        printf("Rotation by a %d degree angle\n", my_getnbr(argv[c + 1]));
        rotation(x, y, argv[c + 1]);
        c++;
    }
    if (argv[c][1] == 's') {
        if (argc < 5 || argc > 5 || error(argc, argv) == 84) {
            write(2, "Error", 5);
            return (84);
        }
        symetry(x, y, argv[c + 1]);
        c++;
    }
    if (c == 3) {
    write(2, "Error", 5);
    return (84);
    }
    return (0);
}
