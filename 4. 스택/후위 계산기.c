//후위 계산기 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 50

typedef struct {

    char stk[MAX];
    int top;
}Stack_type;

Stack_type s;

void init(Stack_type* s) {
    s->top = -1;
}

int is_empty(Stack_type* s) {
    return s->top < 0;
}

int is_full(Stack_type* s) {
    return s->top == MAX - 1;
}

void push(Stack_type* s, char ch) {
    if (!is_full(s)) {
        s->stk[++s->top] = ch;
    }
}

char pop(Stack_type* s) {
    if (!is_empty(s)) {
        return s->stk[s->top--];
    }
    return -1;
}

char peek(Stack_type* s) {
    if (!is_empty(s)) return s->stk[s->top];
    else return -1;
}


//우선순위 반환 함수
//배열 우선순위 함수 pie
//거듭제곱의 우선순위가 가장 높다
int pie(char operator) {
    if (operator=='^') return 3;
    else if (operator=='*' || operator=='/') return 2;
    else if (operator=='+' || operator=='-') return 1;
    else return 0;
}
//스택 안에 연산자 우선순위 함수 pis
int pis(char operator) {
    if (operator=='^') return 3;
    else if (operator=='*' || operator=='/') return 2;
    else if (operator=='+' || operator=='-') return 1;
    else return 0;
}

char get_token(char exp[]) {
    static int i = -1;
    return exp[i++];

}

//후위식으로 변경 함수
void postfix(char infix_exp[], char postfix_exp[]) {
    char ch;
    int k = 0;

    while ((ch = get_token(infix_exp)) != '\0') {
        switch (ch)
        {
        case '(':
            push(&s, ch);
            break;
        case ')':
            while (s.stk[s.top] != '(') {
                postfix_exp[k++] = pop(&s);
            }
            pop(&s); //남아있는 괄호 빼기
            break;

        case '[':
            push(&s, ch);
            break;

        case ']':
            while (s.stk[s.top] != '[') {
                postfix_exp[k++] = pop(&s);
            }
            pop(&s);
            break;
        case '{':
            push(&s, ch);
            break;
        case '}':
            while (s.stk[s.top] != '{') {
                postfix_exp[k++] = pop(&s);
            }
            pop(&s);
            break;
        default:
            if (isspace(ch) == 0) { //공백 문자가 아닐 때
                if (isdigit(ch) == 0) { //문자라면
                    if (!is_empty(&s)) { // 스택이 비어있지 않을 경우 우선순위 비교
                        if (pie(ch) <= pis(peek(&s))) {  //만약 스택안에 있는 연산자의 우선순위가 같거나 더 클 경우
                            while (!is_empty(&s)) {  //스택안에 있는 연산자를 모두 pop()
                                postfix_exp[k++] = pop(&s);
                            }
                        }
                    }
                    push(&s, ch); //연산자를 스택에 저장
                }
                else { // 숫자라면 배열에 저장
                    postfix_exp[k++] = ch;
                }
            }

        }

    }
    //스택안에 남아있는 것들 전부 pop
    while (!is_empty(&s)) {
        postfix_exp[k++] = pop(&s);
    }
    postfix_exp[k] = '\0';

    int n = 0;
    //결과 배열 출력
    //while ((ch = postfix_exp[n++]) != '\0') {
    //   printf("%c \n\n", ch);

    //}
}

//연산 함수
int cal(int op1, int op2, char cal) {
    int sum = 1;
    switch (cal) {
    case '*':
        return op1 * op2;
        break;
    case '/':
        return op1 / op2;
        break;
    case '+':
        return op1 + op2;
        break;
    case '-':
        return op1 - op2;
        break;
    case '^':
        while ((op2--) != 0) {
            sum *= op1;
        }
        return sum;
        break;
    }

}

//후위식 평가 함수
//숫자 나오면 push -> 문자 나오면 위의 두개 pop 계산 후 다시 push
void eval(char postfix_exp[]) {
    char ch;
    int k = 0;
    while ((ch = postfix_exp[k++]) != '\0') {
        if (isdigit(ch) != 0) { //숫자일 경우
            push(&s, ch - '0'); //아스키 코드로 저장 돼서 빼주고 저장 해야 연산 결과가 올바르게 나온다.
        }
        else { //문자일 때
            push(&s, cal(pop(&s), pop(&s), ch));
        }
    }
    printf("=%d", pop(&s));

}


char get_exp(char exp[]) {
    gets(exp);
    return exp;
}


int main(void) {
    init(&s);
    //사용자로 부터 입력 받기
    char exp[MAX] = "";
    get_exp(exp);
    get_token(exp);
    //exp: 사용자로 부터 입력 받은 중위식 배열
    char infix_exp[MAX] = "";
    strcpy(infix_exp, exp);

    char postfix_exp[MAX] = "";
    printf("%s", infix_exp);
    //중위식을 후의식으로 변경
    postfix(infix_exp, postfix_exp);
    //후위식 평가
    eval(postfix_exp);

    return 0;
}
