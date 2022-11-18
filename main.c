#include <stdio.h>
#include <math.h>

typedef double (*IFun) (double);


double S (double);
double V (double);
double Y (double);
void Out_Rez (IFun, double, double, double);

double S ( double x) {
    return log(fabs(sqrt(pow(x, 3))));
}
double V (double x) {
    if (x>1){
        return sqrt(tan(pow(x, 2)-1));
    }
    if (x>=0 && x<=1){
        return -2*x;
    }
    if (x<0){
    return exp(cos(x));
    }
    return -1;
}
double Y (double r){
    return (r - 1) / (r + 1) + 1. / 3 * pow((r - 1) / (r + 1), 3) + 1. / 5 * pow((r - 1) / (r + 1), 5) + 1. / 7 * pow((r - 1) / (r + 1), 7);
    }
void t_rez (IFun f, double xn, double xk, double h)
{
        printf("┏━━━━━━━━━━━┳━━━━━━━━━━━━━┓\n");
    for (double x=xn; x<=xk; x+=h){
        printf("┃ x = %5.2lf ┃ y = %8.4lf┃\n", x, f(x));
        
    }
        printf("┗━━━━━━━━━━━┻━━━━━━━━━━━━━┛\n");
}

void plot(double x0, double x1, IFun f)
{
    int SCREENW=60, SCREENH=40;//размеры поля вывода в символах
    char screen[SCREENW][SCREENH];
    double x, y[SCREENW];
    double ymin=0, ymax=0;
    double hx, hy;
    int i, j;
    int xz,yz;
    hx=(x1-x0)/(SCREENW-1);
    for(i=0, x=x0;i<SCREENW; ++i, x+=hx){
        y[i]=f(x); //расчет значений функции для каждой точки поля вывода графика
        if(y[i]<ymin) ymin=y[i];
        if(y[i]>ymax) ymax=y[i];
    }
    hy=(ymax-ymin)/(SCREENH-1);
    yz=(int)floor(ymax/hy+0.5);
    xz=(int)floor((0.-x0)/hx+0.5);
    //построение осей и заполнение массива отображения пробелами
    for(j=0;j<SCREENH; ++j)
         for(i=0;i<SCREENW; ++i) {
          if(j==yz && i==xz) screen[i][j]='+';
          else if (j==yz) screen[i][j]='-';
           else if (i==xz) screen[i][j]='|';
           else screen[i][j]=' ';
         }
    //определение положения значения функции на поле вывода
    for(i=0;i<SCREENW; ++i){
        j=(int)floor((ymax-y[i])/hy+0.5);
        screen[i][j]='*';
    }
    for(j=0;j<SCREENH; ++j){
             for(i=0;i<SCREENW; ++i)  putchar(screen[i][j]);
              putchar('\n');
        }
}

void mn(k,a,b,h){
    switch (k) {
        case 1:
            t_rez(V, a, b, h);
            break;
        case 2:
            t_rez(S, a, b, h);
            break;
        case 3:
            t_rez(Y, a, b, h);
            break;
        default:
            break;
    }
}
    
void main ()
{
    int n;
    int k;
    double a, b, h;
    
    printf("1-Функция\n2-Табуляция\n3-График\n");
    scanf("%i",&n);
    switch (n) {
        case 2:
            printf("1-Функция V\n2-Функция S\n3-Функция Y\n");
            scanf("%i",&k);
            puts ("Input a,b, h");
            scanf("%lf%lf%lf", &a, &b, &h);
            mn(k,a,b,h);
            break;
        case 1:
            printf("1-Функция V\n2-Функция S\n3-Функция Y\n");
            scanf("%i",&k);
            puts ("Input a");
            scanf("%lf", &a);
            b=a;
            h=a;
            mn(k,a,b,h);
            break;
        case 3:
            printf("1-Функция V\n2-Функция S\n3-Функция Y\n");
            scanf("%i",&k);
            puts ("Input a,b");
            scanf("%lf%lf", &a, &b);
            h=1;
            switch (k) {
                case 1:
                    plot(a, b, V);
                    break;
                case 2:
                    plot(a, b, S);
                    break;
                case 3:
                    plot(a, b, Y);
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }

}
