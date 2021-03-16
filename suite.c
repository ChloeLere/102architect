
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

    for(; i < 2; i++) {
        for (j = 0; j < 2; j++)
            res[i] += op[j] * s[i][j];
    }
    printf("Symetry about an axis inclined with an angle of %s degrees\n", a);
    printf("(%.2f, %.2f) => (%.2f, %.2f)\n", x, y, res[0], res[1]);
}
    

int main(int argc, char **argv)
{
    if (argc < 2) {
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
    float matrice[2][2] = { {1, 0, 0}, {0, 1, 0}, {0, 0, 1} };

    while ( c < argc) {
        if (argv[c][1] == 's') {
            c =+ 3;
        }
        if (argv[c][1] == 'h') {
            c =+ 3;
        }
        if (argv[c][1] == 't') {
            c += 2;
        }
        if (argv[c][1] == 'r') {
            printf("Rotation by a %d degree angle\n", my_getnbr(argv[c + 1]));
            c++;
        }
        c++;
    }

    return (0);
}
