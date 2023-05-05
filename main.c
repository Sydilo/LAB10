#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COUNTRIES 100
#define MAX_STR_LEN 50

struct Country {
    char name[MAX_STR_LEN];
    char capital[MAX_STR_LEN];
    int population;
    int area;
    int num_cities;
};

int compare_countries(const void *a, const void *b) {
    const struct Country *country_a = (const struct Country*)a;
    const struct Country *country_b = (const struct Country*)b;

    if (country_a->population < country_b->population) {
        return -1;
    } else if (country_a->population > country_b->population) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    struct Country countries[MAX_COUNTRIES];
    int num_countries;

    // Ввід даних про країни
    printf("Введіть кількість країн: ");
    scanf("%d", &num_countries);

    printf("Введіть дані про країни:\n");

    for (int i = 0; i < num_countries; i++) {
        printf("Країна %d:\n", i+1);

        printf("Назва: ");
        scanf("%s", countries[i].name);

        printf("Столиця: ");
        scanf("%s", countries[i].capital);

        printf("Кількість населення: ");
        scanf("%d", &countries[i].population);

        printf("Площа: ");
        scanf("%d", &countries[i].area);

        printf("Кількість міст: ");
        scanf("%d", &countries[i].num_cities);

        printf("\n");
    }

    qsort(countries, num_countries, sizeof(struct Country), compare_countries);

    printf("Країни у порядку зростання кількості населення:\n");

    for (int i = 0; i < num_countries; i++) {
        printf("Назва: %s\n", countries[i].name);
        printf("Столиця: %s\n", countries[i].capital);
        printf("Кількість населення: %d\n", countries[i].population);
        printf("Площа: %d\n", countries[i].area);
        printf("Кількість міст: %d\n", countries[i].num_cities);
        printf("\n");
    }

    return 0;
}
