#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

/********* YÄ±ÄŸÄ±n (Stack) Ä°ÅŸlemleri iÃ§in Global DeÄŸiÅŸkenler *********/
// Karakter yÄ±ÄŸÄ±nÄ± (dÃ¶nÃ¼ÅŸÃ¼m iÅŸlemleri iÃ§in)
char stackChar[MAX];
int topChar = -1;

// TamsayÄ± yÄ±ÄŸÄ±nÄ± (deÄŸerlendirme iÅŸlemleri iÃ§in)
int stackInt[MAX];
int topInt = -1;

/********* Fonksiyon Prototipleri *********/
void pushChar(char c);
char popChar();
char peekChar();
int isOperator(char c);
int precedence(char op);
void reverseString(char str[]);
void swapChars(char *a, char *b);

void infixToPostfix(const char* infix, char* postfix);
void infixToPrefix(const char* infix, char* prefix);
int evaluatePostfix(const char* postfix);
int evaluatePrefix(const char* prefix);

void pushInt(int num);
int popInt();

void clearCharStack();
void clearIntStack();

/********* YÄ±ÄŸÄ±n Ä°ÅŸlemleri (Karakter) *********/
void pushChar(char c) {
    if (topChar < MAX - 1) {
        stackChar[++topChar] = c;
    }
}

char popChar() {
    if (topChar >= 0)
        return stackChar[topChar--];
    return '\0';
}

char peekChar() {
    if (topChar >= 0)
        return stackChar[topChar];
    return '\0';
}

void clearCharStack() {
    topChar = -1;
}

/********* YÄ±ÄŸÄ±n Ä°ÅŸlemleri (TamsayÄ±) *********/
void pushInt(int num) {
    if (topInt < MAX - 1) {
        stackInt[++topInt] = num;
    }
}

int popInt() {
    if (topInt >= 0)
        return stackInt[topInt--];
    return 0;
}

void clearIntStack() {
    topInt = -1;
}

/********* OperatÃ¶r ve Ã–ncelik FonksiyonlarÄ± *********/
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char op) {
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

/********* YardÄ±mcÄ± Fonksiyonlar *********/
void swapChars(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void reverseString(char str[]) {
    int i, len = strlen(str);
    for (i = 0; i < len / 2; i++) {
        swapChars(&str[i], &str[len - i - 1]);
    }
}

/********* Infix -> Postfix DÃ¶nÃ¼ÅŸÃ¼mÃ¼ *********/
void infixToPostfix(const char* infix, char* postfix) {
    int i, k = 0;
    char c;
    clearCharStack(); // YÄ±ÄŸÄ±nÄ± temizle

    for (i = 0; infix[i] != '\0'; i++) {
        c = infix[i];

        if (isdigit(c)) {
            // RakamlarÄ± direkt ekle, burada sayÄ±lar arasÄ± boÅŸluk bÄ±rakÄ±yoruz.
            postfix[k++] = c;
            postfix[k++] = ' ';
        }
        else if (c == '(') {
            pushChar(c);
        }
        else if (c == ')') {
            // '(' bulunana kadar yÄ±ÄŸÄ±ndan Ã§Ä±kart
            while (topChar != -1 && peekChar() != '(') {
                postfix[k++] = popChar();
                postfix[k++] = ' ';
            }
            popChar(); // '(' karakterini at
        }
        else if (isOperator(c)) {
            // OperatÃ¶rlerin Ã¶nceliÄŸini kontrol et, yÄ±ÄŸÄ±ndaki operatÃ¶rleri Ã§Ä±kart
            while (topChar != -1 && precedence(peekChar()) >= precedence(c)) {
                postfix[k++] = popChar();
                postfix[k++] = ' ';
            }
            pushChar(c);
        }
    }
    // Kalan operatÃ¶rleri yÄ±ÄŸÄ±ndan boÅŸalt
    while (topChar != -1) {
        postfix[k++] = popChar();
        postfix[k++] = ' ';
    }
    if (k > 0) postfix[k - 1] = '\0'; // sondaki boÅŸluÄŸu kaldÄ±r
}

/********* Infix -> Prefix DÃ¶nÃ¼ÅŸÃ¼mÃ¼ *********/
void infixToPrefix(const char* infix, char* prefix) {
    // AdÄ±m 1: Orijinal infix ifadesini ters Ã§evir ve parantezleri deÄŸiÅŸtir.
    char revInfix[MAX];
    strcpy(revInfix, infix);
    reverseString(revInfix);
    for (int i = 0; revInfix[i] != '\0'; i++) {
        if (revInfix[i] == '(')
            revInfix[i] = ')';
        else if (revInfix[i] == ')')
            revInfix[i] = '(';
    }

    // AdÄ±m 2: Ters Ã§evrilmiÅŸ ifadeyi postfixe Ã§evir.
    char revPostfix[MAX];
    infixToPostfix(revInfix, revPostfix);

    // AdÄ±m 3: Elde edilen postfix ifadesini ters Ã§evirerek prefix elde et.
    strcpy(prefix, revPostfix);
    reverseString(prefix);
}

/********* Postfix Ä°fadenin DeÄŸerlendirilmesi *********/
int evaluatePostfix(const char* postfix) {
    clearIntStack();
    int i;
    for (i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];

        if (isdigit(c)) {
            // Karakteri tamsayÄ±ya dÃ¶nÃ¼ÅŸtÃ¼r ve yÄ±ÄŸÄ±na ekle
            pushInt(c - '0');
        }
        else if (isOperator(c)) {
            int b = popInt();
            int a = popInt();
            switch (c) {
                case '+': pushInt(a + b); break;
                case '-': pushInt(a - b); break;
                case '*': pushInt(a * b); break;
                case '/': pushInt(a / b); break;
            }
        }
    }
    return popInt();
}

/********* Prefix Ä°fadenin DeÄŸerlendirilmesi *********/
int evaluatePrefix(const char* prefix) {
    clearIntStack();
    int len = strlen(prefix);
    for (int i = len - 1; i >= 0; i--) {
        char c = prefix[i];
        if (isspace(c))
            continue;
        if (isdigit(c)) {
            pushInt(c - '0');
        }
        else if (isOperator(c)) {
            int a = popInt();
            int b = popInt();
            switch (c) {
                case '+': pushInt(a + b); break;
                case '-': pushInt(a - b); break;
                case '*': pushInt(a * b); break;
                case '/': pushInt(a / b); break;
            }
        }
    }
    return popInt();
}

/********* Ana Fonksiyon ve MenÃ¼ *********/
int main() {
    int secim;
    char expression[MAX];
    char resultStr[MAX];
    int result;

    while (1) {
        printf("\n-------------------------\n");
        printf("Menu:\n");
        printf("1) Infix -> Postfix DÃ¶nÃ¼ÅŸÃ¼mÃ¼\n");
        printf("2) Infix -> Prefix DÃ¶nÃ¼ÅŸÃ¼mÃ¼\n");
        printf("3) Postfix Ä°fade DeÄŸerlendirme\n");
        printf("4) Prefix Ä°fade DeÄŸerlendirme\n");
        printf("5) CÄ±kÄ±ÅŸ\n");
        printf("Seciminizi yapin: ");
        scanf("%d", &secim);
        getchar(); // newline karakterini temizle

        switch(secim) {
            case 1:
                printf("Infix ifade girin (Ã¶rn: (3+4)*2): ");
                fgets(expression, MAX, stdin);
                expression[strcspn(expression, "\n")] = '\0'; // newline sil
                infixToPostfix(expression, resultStr);
                printf("Postfix ifade: %s\n", resultStr);
                break;
            case 2:
                printf("Infix ifade girin (Ã¶rn: (3+4)*2): ");
                fgets(expression, MAX, stdin);
                expression[strcspn(expression, "\n")] = '\0';
                infixToPrefix(expression, resultStr);
                printf("Prefix ifade: %s\n", resultStr);
                break;
            case 3:
                printf("Postfix ifade girin (Ã¶rn: 3 4 + 2 *): ");
                fgets(expression, MAX, stdin);
                expression[strcspn(expression, "\n")] = '\0';
                result = evaluatePostfix(expression);
                printf("SonuÃ§: %d\n", result);
                break;
            case 4:
                printf("Prefix ifade girin (Ã¶rn: * + 3 4 2): ");
                fgets(expression, MAX, stdin);
                expression[strcspn(expression, "\n")] = '\0';
                result = evaluatePrefix(expression);
                printf("SonuÃ§: %d\n", result);
                break;
            case 5:
                printf("Program sonlandÄ±rÄ±lÄ±yor...\n");
                exit(0);
            default:
                printf("Yanlis secim, tekrar deneyin.\n");
        }
    }

    return 0;
}