/*
1088 Rational Arithmetic (20)（20 分）

For two rational numbers, your task is to implement the basic arithmetics, that is, to calculate their sum, difference, product and quotient.

Input Specification:

Each input file contains one test case, which gives in one line the two rational numbers in the format "a1/b1 a2/b2". The numerators and the denominators are all in the range of long int. If there is a negative sign, it must appear only in front of the numerator. The denominators are guaranteed to be non-zero numbers.

Output Specification:

For each test case, print in 4 lines the sum, difference, product and quotient of the two rational numbers, respectively. The format of each line is "number1 operator number2 = result". Notice that all the rational numbers must be in their simplest form "k a/b", where k is the integer part, and a/b is the simplest fraction part. If the number is negative, it must be included in a pair of parentheses. If the denominator in the division is zero, output "Inf" as the result. It is guaranteed that all the output integers are in the range of long int.

Sample Input 1:

2/3 -4/2
Sample Output 1:

2/3 + (-2) = (-1 1/3)
2/3 - (-2) = 2 2/3
2/3 * (-2) = (-1 1/3)
2/3 / (-2) = (-1/3)
Sample Input 2:

5/3 0/6
Sample Output 2:

1 2/3 + 0 = 1 2/3
1 2/3 - 0 = 1 2/3
1 2/3 * 0 = 0
1 2/3 / 0 = Inf
*/

#include<iostream>
#include<string>

using namespace std;
/*
 计算结果都采用分数形式，输出时再变换格式
 为了代码易读性和低耦合性，牺牲了代码长度
 */

//n为整数部分，a/b为分数部分,sign为false时为负
struct Numform{
    bool sign;
    long n,a,b;
};

//辗转相除法求最大公约数
long gcd(long a,long b){
    while(b){
        long r = b;
        b = a % b;
        a = r;
    }
    return a;
}

//将分数格式化、最简化
Numform simplify(long a, long b){
    //a=0时原样输出
    bool sign = true;
    Numform form = {true,0,0,0};
    if(!a) return form;
    long fa = a,fb = b;
    if(a < 0){
        sign = false;
        a = -a;
        fa = a;
    }
    if(a > b){
        form.n = a / b;
        fa = a % b;
    }
    form.sign = sign;
    //简化fa/fb
    long gmax = gcd(fa,fb);
    fa = fa/gmax;
    fb = fb/gmax;
    form.a = fa;
    form.b = fb;
    return form;
}

Numform sum(long a1,long b1,long a2,long b2){
    Numform form = {true,0,0,0};
    long ra,rb;
    if(a1 == 0){
        ra = a2;
        rb = b2;
    }else if(a2 == 0){
        ra = a1;
        rb = b1;
    }else{  //a1 a2均不为0
        long gmax = gcd(b1, b2);
        ra = (a1 * b2 + a2 * b1)/gmax;
        rb = (b1 * b2)/gmax;
    }
    form = simplify(ra, rb);
    return form;
}

//a1/b1 - a2/b2 = a1/b1 + (-a2/b2)
Numform sub(long a1,long b1,long a2,long b2){
    return sum(a1,b1,-a2,b2);
}

Numform multiply(long a1,long b1,long a2,long b2){
    long ra = a1 * a2;
    long rb = b1 * b2;
    return simplify(ra, rb);
}

Numform division(long a1,long b1,long a2,long b2){
    if(a2 < 0){
        b2 = -b2;
        a2 = -a2;
    }
    //1 2/3 / 0 = Inf
    if(a2 == 0) {
        //若a2=0，则结果一定是Inf,用n位<0来表示（n本来一定大于0，因为符号是sign表示的）
        return {true,-1,0,0};
    }
    return multiply(a1, b1, b2, a2);
}

//打印单个form
void printForm(Numform form, bool brackets){
    if(brackets) printf("(");
    if(!form.sign) printf("-");
    if(form.a == form.b) printf("1");
    else if(form.n){
        printf("%ld",form.n);
        if(form.a) printf(" %ld/%ld",form.a,form.b);
    }else if(form.a) printf("%ld/%ld",form.a,form.b);
    if(brackets) printf(")");
}
/*
1234对应+-*/
void printFinform(Numform form1,Numform form2,Numform outputForm,int flag){
    //print form1，按需加括号
    if(form1.n == 0 && form1.a == 0) printf("0");
    else if(!form1.sign) printForm(form1,true);
    else printForm(form1,false);
    //print operation
    if(flag == 1) printf(" + ");
    else if(flag == 2) printf(" - ");
    else if(flag == 3) printf(" * ");
    else printf(" / ");
    //print form2，按需加括号
    if(form2.n == 0 && form2.a == 0) printf("0");
    else if(!form2.sign) printForm(form2, true);
    else printForm(form2, false);
    //print =
    printf(" = ");
    //print 结果
    if(outputForm.n < 0) printf("Inf");
    else if(outputForm.n == 0 && outputForm.a == 0) printf("0");
    else if(!outputForm.sign) printForm(outputForm, true);
    else printForm(outputForm, false);
    printf("\n");
}

int main(){
    long a1,b1;
    int a2,b2;
    char tmp;
    cin >> a1 >> tmp >> b1;
    cin >> a2 >> tmp >> b2;
    Numform form1 = simplify(a1, b1);
    Numform form2 = simplify(a2, b2);
    Numform sumform = sum(a1,b1,a2,b2);
    Numform subform = sub(a1,b1,a2,b2);
    Numform mulform = multiply(a1,b1,a2,b2);
    Numform divform = division(a1,b1,a2,b2);
    printFinform(form1,form2,sumform, 1);
    printFinform(form1,form2,subform, 2);
    printFinform(form1,form2,mulform, 3);
    printFinform(form1,form2,divform, 4);
    return 0;
}
