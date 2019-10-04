using System;

namespace CSHARP{
    class Program{
        public static double getS(int d, int j){       
            double ret = 0.0d;
            for(int k=0; k<=d; ++k)
            ret += (double)nMod(d-k, 8*k + j) / (double)(8*k + j);
            return ret - Math.Floor(ret);
        }
        public static long nMod(int n, int k){
            int t = 1;
            while(t <= n)
            t *= 2;
            long r = 1;
            while(true) {
                if(n >= t) {
                    r = (16*r) % k;
                    n = n - t;
                }
                t = t/2;
                if(t < 1)
                    break;
                r = (r*r) % k;
            }
            return r;
        }           
        public static void calculate(int n){
            char[] hexLetters = {'A','B','C','D','E','F'};
            double pi = 0.0;
            double pi1 = 4* getS(n,1);
            double pi2 = 2*getS(n,4);
            double pi3 = getS(n,5);
            double pi4 = getS(n,6);
            pi = pi1-pi2-pi3-pi4;
            pi = pi-Math.Floor(pi);
            int hex = (int)Math.Floor(16.0*pi);
            Console.WriteLine("A {0}. pozíción lévő jegye {1}",n, ((hex < 10) ? (char)((hex) + '0') : hexLetters[hex-10]));
        }
        public static void Main(String[] args){
            if(args.Length == 0){
                Console.WriteLine("Usage: dotnet run <exponent>");
                Environment.Exit(-1);
            }
            try{
                Console.WriteLine("10^" + Convert.ToInt32(args[0]));
                calculate((int)Math.Pow(10,Convert.ToInt32(args[0])));
            }
            catch (FormatException e){
                Console.WriteLine(e);
                Console.WriteLine("Usage: dotnet run <exponent>");
                Environment.Exit(-1);
            }
        }
    }
}