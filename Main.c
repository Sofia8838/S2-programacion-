#include <stdio.h>

#define ESTUDIANTES 5
#define ASIGNATURAS 3
#define MAX_NOMBRE 50

int main() {
    float calificaciones[ESTUDIANTES][ASIGNATURAS];
    float promedioEst[ESTUDIANTES], promedioAsig[ASIGNATURAS];
    float maxEst[ESTUDIANTES], minEst[ESTUDIANTES];
    float maxAsig[ASIGNATURAS], minAsig[ASIGNATURAS];
    int aprobados[ASIGNATURAS] = {0}, reprobados[ASIGNATURAS] = {0};
    char nombresEstudiantes[ESTUDIANTES][MAX_NOMBRE];
    char nombresAsignaturas[ASIGNATURAS][MAX_NOMBRE];

    printf("Ingrese los nombres de los %d estudiantes:\n", ESTUDIANTES);
    for (int i = 0; i < ESTUDIANTES; i++) {
        printf("Estudiante %d: ", i + 1);
        scanf(" %[^\n]", nombresEstudiantes[i]);
    }

    printf("\nIngrese los nombres de las %d asignaturas:\n", ASIGNATURAS);
    for (int j = 0; j < ASIGNATURAS; j++) {
        printf("Asignatura %d: ", j + 1);
        scanf(" %[^\n]", nombresAsignaturas[j]);
    }

    printf("\n--- Ingreso de calificaciones ---\n");
    for (int i = 0; i < ESTUDIANTES; i++) {
        for (int j = 0; j < ASIGNATURAS; j++) {
            float nota;
            int valid;
            do {
                printf("Ingrese calificación de %s en %s (0 a 10): ", nombresEstudiantes[i], nombresAsignaturas[j]);
                valid = scanf("%f", &nota);

                if (valid != 1 || nota < 0 || nota > 10) {
                    printf("Entrada inválida. Solo números entre 0 y 10.\n");
                    while (getchar() != '\n');  
                }
            } while (valid != 1 || nota < 0 || nota > 10);

            calificaciones[i][j] = nota;
        }
    }

    for (int i = 0; i < ESTUDIANTES; i++) {
        float suma = 0;
        maxEst[i] = minEst[i] = calificaciones[i][0];
        for (int j = 0; j < ASIGNATURAS; j++) {
            float nota = calificaciones[i][j];
            suma += nota;
            if (nota > maxEst[i]) maxEst[i] = nota;
            if (nota < minEst[i]) minEst[i] = nota;
        }
        promedioEst[i] = suma / ASIGNATURAS;
    }

    for (int j = 0; j < ASIGNATURAS; j++) {
        float suma = 0;
        maxAsig[j] = minAsig[j] = calificaciones[0][j];
        for (int i = 0; i < ESTUDIANTES; i++) {
            float nota = calificaciones[i][j];
            suma += nota;
            if (nota > maxAsig[j]) maxAsig[j] = nota;
            if (nota < minAsig[j]) minAsig[j] = nota;
            if (nota >= 6) aprobados[j]++;
            else reprobados[j]++;
        }
        promedioAsig[j] = suma / ESTUDIANTES;
    }

    printf("\n--- Promedios por Estudiante ---\n");
    for (int i = 0; i < ESTUDIANTES; i++) {
        printf("%s: Promedio = %.2f | Máxima = %.1f | Mínima = %.1f\n",
               nombresEstudiantes[i], promedioEst[i], maxEst[i], minEst[i]);
    }

    printf("\n--- Promedios por Asignatura ---\n");
    for (int j = 0; j < ASIGNATURAS; j++) {
        printf("%s: Promedio = %.2f | Máxima = %.1f | Mínima = %.1f\n",
               nombresAsignaturas[j], promedioAsig[j], maxAsig[j], minAsig[j]);
    }

    printf("\n--- Aprobados y Reprobados por Asignatura ---\n");
    for (int j = 0; j < ASIGNATURAS; j++) {
        printf("%s: Aprobados = %d | Reprobados = %d\n",
               nombresAsignaturas[j], aprobados[j], reprobados[j]);
    }

    return 0;
}
