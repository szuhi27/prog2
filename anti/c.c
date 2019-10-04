#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char hexLetters[] = {'A','B','C','D','E', 'F'};
long nMod(int n, int k){
    int t = 1;
    while(t <= n){
        t = 2*t;
    }
    long r = 1;
    while(1){
        if(n >= t){
            r = 16*r % k;
            n = n - t;
        }
        t/=2;
        if(t < 1)
            break;
        if(t>=1){
            r = r*r % k;
        }
    }
return r;
}

double getS(int d, int j){
    double ret = 0.0;
    for(int i=0; i<d; i++){
        ret+= (nMod(d-i, 8*i+j))/(double)(8*i+j);
    }
    return ret - floor(ret);
}

void calculate(int n){
    double pi = 0.0;
    double pi1 = 4* getS(n,1);
    double pi2 = 2*getS(n,4);
    double pi3 = getS(n,5);
    double pi4 = getS(n,6);
    pi = pi1-pi2-pi3-pi4;
    pi = pi-floor(pi);
    int hex = floor(16.0*pi);
    printf("%c\n",((hex < 10) ? (char)((hex) + '0') : hexLetters[hex-10]));
}

int main(int argc, char* argv[]){
    if(argc == 1){
        printf("Usage: ./BPP <exponent>\n");
        exit(-1);
    }
    int exponent = atoi(argv[1]);
    if(!exponent){
        printf("Usage: ./BPP <exponent>\n");
        exit(-1);
    }
    printf("10^%d\n", exponent);
    int limit = pow(10,exponent);
    calculate(limit);
}