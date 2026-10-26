#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "sort.h"
#include "generate.h"

#define NB_ALGOS 6
#define NB_SIZES 14
#define REPEATS 3

const char *names[NB_ALGOS] = {
    "bubble_sort", "insertion_sort", "selection_sort",
    "quick_sort", "merge_sort", "heap_sort"
};

long limits[NB_ALGOS] = {
    100000, 100000, 100000,
    10000000, 10000000, 10000000
};

long sizes[NB_SIZES] = {
    10000, 20000, 30000, 50000, 75000, 100000,
    250000, 500000, 750000,
    1000000, 2500000, 5000000, 7500000, 10000000
};

void run_sort(int index, int *arr, long n)
{
    switch (index)
    {
        case 0:
            bubble_sort(arr, n);
            break;
        case 1:
            insertion_sort(arr, n);
            break;
        case 2:
            selection_sort(arr, n);
            break;
        case 3:
            quick_sort(arr, n);
            break;
        case 4:
            merge_sort(arr, n);
            break;
        case 5:
        default:
            heap_sort(arr, n);
            break;
    }
}

int is_sorted(int *arr, long n)
{
    long i;

    for (i = 1; i < n; i++)
    {
        if (arr[i - 1] > arr[i])
            return 0;
    }
    return 1;
}

int main(void)
{
    FILE *files[NB_ALGOS];
    FILE *csv;
    char filename[100];
    int *base = NULL;
    long old_n = 0;
    int total_steps = 0;
    int done_steps = 0;
    int a, s, r;
    int status;

    srand(time(NULL));

    system("mkdir data 2>nul");
    system("mkdir graphs 2>nul");

    for (s = 0; s < NB_SIZES; s++)
    {
        for (a = 0; a < NB_ALGOS; a++)
        {
            if (sizes[s] <= limits[a])
                total_steps++;
        }
    }

    printf("Benchmark des tris - cela peut prendre plusieurs minutes...\n\n");

    csv = fopen("data/results.csv", "w");
    if (csv == NULL)
    {
        printf("Impossible de creer data/results.csv\n");
        return 1;
    }
    fprintf(csv, "algorithm,n,time_ms\n");

    for (a = 0; a < NB_ALGOS; a++)
    {
        sprintf(filename, "data/%s.dat", names[a]);
        files[a] = fopen(filename, "w");
        if (files[a] == NULL)
        {
            printf("Impossible de creer %s\n", filename);
            return 1;
        }
    }

    for (s = 0; s < NB_SIZES; s++)
    {
        long n = sizes[s];

        if (base == NULL)
            base = generate_array(n);
        else
        {
            int *new_base = grow_array(base, old_n, n);

            if (new_base == NULL)
            {
                free(base);
                base = NULL;
            }
            else
                base = new_base;
        }

        if (base == NULL)
        {
            printf("Erreur : pas assez de memoire pour n = %ld\n", n);
            return 1;
        }
        old_n = n;

        for (a = 0; a < NB_ALGOS; a++)
        {
            double total = 0;
            double average;

            if (n > limits[a])
                continue;

            for (r = 0; r < REPEATS; r++)
            {
                clock_t start, end;
                int *copy = malloc(sizeof(int) * n);

                if (copy == NULL)
                {
                    printf("Erreur : pas assez de memoire\n");
                    return 1;
                }

                memcpy(copy, base, sizeof(int) * n);

                start = clock();
                run_sort(a, copy, n);
                end = clock();

                if (!is_sorted(copy, n))
                    printf("ERREUR : %s ne trie pas correctement !\n", names[a]);

                total = total + (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;
                free(copy);
            }

            average = total / REPEATS;

            fprintf(files[a], "%ld %.3f\n", n, average);
            fprintf(csv, "%s,%ld,%.3f\n", names[a], n, average);
            fflush(files[a]);
            fflush(csv);

            done_steps++;
            printf("[%2d/%d] %-15s n = %-9ld %10.2f ms\n",
                   done_steps, total_steps, names[a], n, average);
        }
    }

    free(base);
    fclose(csv);
    for (a = 0; a < NB_ALGOS; a++)
        fclose(files[a]);

    printf("\nMesures terminees. Lancement de gnuplot...\n");
    status = system("gnuplot plot.gnu");
    if (status != 0)
        printf("gnuplot n'a pas pu se lancer (est-il installe et dans le PATH ?)\n");
    else
        printf("Graphiques crees (fichiers .png).\n");

    return 0;
}
