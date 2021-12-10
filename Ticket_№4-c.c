/*
    3 Вычислить корень нелинейного уровнения на отрезке a b с определённой точностью
      епсилон методом половинного деления вычисление функции надо оформить как подпрограмму; 
    4 отображать промежуточные вычисления на каждом шаге и показывать количество шагов;
    5 требуется вывести все промежуточные и итоговые вычисления в текстовый файл.
*/

#include <stdio.h>
#include <math.h>

double f(double x)
{
    return -3.0 * cos(x);
}

int main()
{
    FILE *p = fopen("calculating.txt", "w+");

    double a, b;
    printf("a, b: ");
    scanf("%lf %lf", &a, &b);

    double e;
    printf("e: ");
    scanf("%lf", &e);
    putchar('\n');
    printf("    x\t\t     y\n");

    fprintf(p, "a, b: %lf %lf\n", a, b);
    fprintf(p, "e: %lf\n", e);
    fprintf(p, "\n");
    fprintf(p, "    x\t\t     y\n");
    
    while(1)
    {
        double c = (a + b) / 2.0;

        double fa = f(a);
        double fc = f(c);

        printf("%f\t%lf\n", c, fc);
        fprintf(p, "%f\t%lf\n", c, fc);
        
        if (fabs (fc) <= e)
        {
            printf("----------------------------\n");
            printf("Answer:\n");
            printf("x: %lf\n", c);
            printf("y: %lf\n", fc);

            fprintf(p, "----------------------------\n");
            fprintf(p, "Answer:\n");
            fprintf(p, "x: %lf\n", c);
            fprintf(p, "y: %lf\n", fc);
            break;
        }

        if (fa * fc > 0.0 )
        {
            a = c;
        }
        else
        {
            b = c;
        }    
    }

    fclose(p);

    return 0;    
}