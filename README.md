modern
======

modern is an experimental programming language built with ANTLR and LLVM in C++ for educational purposes.

modern currently supports syntax like:

    extern getchar();

    int f(double x, int y) {
        double p = x+y,
               z = x*y;
        int r = p/z;
        return r*(1+3*r);
    }
    
    int main() {
        int i = f(0, 1) + 3*f(f(3, 4), 8);
        getchar();
    }
