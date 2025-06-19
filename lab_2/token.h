enum TokenType
{
    TOKEN_NUMBER,   // 2.5, 42
    TOKEN_VARIABLE, // a, b, x
    TOKEN_OPERATOR, // + - * / ^ !
    TOKEN_FUNCTION, // sin, cos, sqrt
    TOKEN_LPAREN,   // (
    TOKEN_RPAREN,   // )
};

struct Token
{
    enum TokenType type;
    char str[16];    // строковое представление токена
    double value;   // если это число - его значение
};