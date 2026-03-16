#include <stdio.h>

#define USD_TO_GTQ 7.75   // 1 USD ≈ 7.75 GTQ
#define EUR_TO_GTQ 8.25   // 1 EUR ≈ 8.25 GTQ

typedef enum { GTQ = 1, USD = 2, EUR = 3 } Currency;

/* Convierte desde la moneda "from" a GTQ */
double to_gtq(double amount, Currency from) {
    switch (from) {
        case GTQ: return amount;
        case USD: return amount * USD_TO_GTQ;
        case EUR: return amount * EUR_TO_GTQ;
        default: return 0.0;
    }
}

/* Convierte desde GTQ a la moneda "to" */
double from_gtq(double amount_gtq, Currency to) {
    switch (to) {
        case GTQ: return amount_gtq;
        case USD: return amount_gtq / USD_TO_GTQ;
        case EUR: return amount_gtq / EUR_TO_GTQ;
        default: return 0.0;
    }
}

/* Obtiene el nombre de la moneda para imprimir */
const char* currency_name(Currency c) {
    switch (c) {
        case GTQ: return "GTQ";
        case USD: return "USD";
        case EUR: return "EUR";
        default: return "";
    }
}

int main(void) {
    int from = 0, to = 0;
    double amount = 0.0;

    printf("Conversor de Monedas: GTQ <-> USD <-> EUR\n");
    printf("Opciones:\n  1) GTQ  2) USD  3) EUR\n");

    printf("Moneda de origen (1-3): ");
    if (scanf("%d", &from) != 1 || from < 1 || from > 3) {
        printf("Entrada invalida.\n");
        return 1;
    }

    printf("Moneda de destino (1-3): ");
    if (scanf("%d", &to) != 1 || to < 1 || to > 3) {
        printf("Entrada invalida.\n");
        return 1;
    }

    printf("Cantidad a convertir: ");
    if (scanf("%lf", &amount) != 1 || amount < 0.0) {
        printf("Entrada invalida.\n");
        return 1;
    }

    Currency from_cur = (Currency)from;
    Currency to_cur   = (Currency)to;

    double amount_gtq = to_gtq(amount, from_cur);
    double result = from_gtq(amount_gtq, to_cur);

    printf("%.2f %s = %.2f %s\n",
           amount, currency_name(from_cur),
           result, currency_name(to_cur));

    return 0;
}
