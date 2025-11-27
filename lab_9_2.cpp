#include "lab_9_2.h"

// Функція для обчислення w за Варіантом 14
double calculate_w(double x, double z) {
    double w;

    // Логіка обчислення за умовою:
    // w = { max(x, z) * min(x + z, x * z),  якщо 5 < z < 10
    //     { min^2 (|x - z|, z),           якщо z <= 5 або z >= 10

    if (z > 5 && z < 10) {
        // Умова 1: 5 < z < 10
        double term1 = MAX(x, z);
        double term2 = MIN(x + z, x * z);
        w = term1 * term2;
    } else {
        // Умова 2: z <= 5 або z >= 10
        double inner_min = MIN(ABS(x - z), z);
        w = SQR(inner_min);
    }

    return w;
}