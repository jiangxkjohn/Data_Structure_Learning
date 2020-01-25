#include "./include/stack.h"
#include <ctype.h>

#define MAXOP 10
#define INFINITY 1e9
typedef enum{num, opr, end} Type;

Type GetOp(char *Expr, int *start, char *str)
{
    int i = 0;
    while ((str[0]=Expr[(*start)++])==' ');//jump the blank in the begining

    while (str[i]!=' ' && str[i]!='\0')
        str[++i] = Expr[(*start)++];
    if (str[i]=='\0')
        (*start)--;
    str[i]='\0';

    if (i==0) return end;
    else if (isdigit(str[0]) || isdigit(str[1]))
        return num;
    else
        return opr;
}

ElementType PostfixExp(char * Expr)
{
    Stack S;
    Type T;
    ElementType Op1, Op2;
    char str[MAXOP];
    int start;

    S = CreateStack(MAXOP);

    Op1 = Op2 = 0;
    while((T=GetOp(Expr, &start, str))!=end)
    {
        //printf("%s\n", str);
        if (T==num)
            Push(S, atof(str));
        else{
            if (!IsEmpty(S)) Op2 = Pop(S);
            else Op2 = INFINITY;
            if (!IsEmpty(S)) Op1 = Pop(S);
            else Op2 = INFINITY;
            switch (str[0]){
                case '+': Push(S, Op1 + Op2); break;
                case '-': Push(S, Op1 - Op2); break;
                case '*': Push(S, Op1 * Op2); break;
                case '/': 
                    if (Op2!=0.0)
                        Push(S, Op1/Op2);
                    else{
                        printf("Wrong: Zero cannot be divided\n");
                        Op2 = INFINITY;
                    }
                    break;
                default:
                    printf("Wrong: Unknow symbol %s\n", str);
                    Op2 = INFINITY;
                    break;
            }
            if (Op2>=INFINITY) break;
        }
    }
    if (Op2<INFINITY)
        if (!IsEmpty(S))
            Op2 = Pop(S);
        else Op2 = INFINITY;
    free(S);
    return Op2;
}

int main()
{
    char Expr[MAXOP];
    ElementType f;

    //scanf("%s", &Expr);
    Expr[0] = '1';
    Expr[1] = ' ';
    Expr[2] = '3';
    Expr[3] = ' ';
    Expr[4] = '+';
    Expr[5] = '\0';
    f = PostfixExp(Expr);
    if (f<INFINITY)
        printf("%.4f\n", f);
    else
        printf("Wrong expression\n");
    return 0;
}