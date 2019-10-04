class BPP{
    static char[] hexLetters = {'A','B','C','D','E', 'F'};
    public static long nMod(int n, int k){
        int t = 1;
        while(t <= n){
            t = 2*t;
        }
        long r = 1;
        while(true){
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
    public static double getS(int d, int j){
        double ret = 0.0;
        for(int i=0; i<d; i++){
            ret+= (nMod(d-i, 8*i+j))/(double)(8*i+j);
        }
        return ret - Math.floor(ret);
    }
    public static void calculate(int n){
        double pi = 0.0;
        double pi1 = 4* getS(n,1);
        double pi2 = 2*getS(n,4);
        double pi3 = getS(n,5);
        double pi4 = getS(n,6);
        pi = pi1-pi2-pi3-pi4;
        pi = pi-Math.floor(pi);
        int hex = (int)StrictMath.floor(16.0*pi);
        System.out.print(((hex < 10) ? String.valueOf(hex) : hexLetters[hex -10]));
    }
    public static void main(String[] args){
        if(args.length == 0){
            System.out.println("Usage: java BPP <exponent>");
            System.exit(-1);
        }
        try{
            System.out.println("10^" + args[0]);
            int limit = (int)Math.pow(10,Integer.parseInt(args[0]));
            calculate(limit);
        }
        catch(Exception e){
            System.out.println("Usage: java BPP <exponent>");
        }
    }
}