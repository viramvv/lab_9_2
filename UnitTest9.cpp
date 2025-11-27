#include "gtest/gtest.h"
#include "lab_9_2.h"

// Константа для порівняння чисел з плаваючою точкою (double)
const double EPSILON = 1e-9;

// --- ТЕСТУВАННЯ ОСНОВНОЇ ФУНКЦІЇ ---

TEST(Variant14Test, ZInRangeCase1) {
    // Тест 1: x=2, z=6. Умова: 5 < z < 10
    // Очікується: max(2, 6) * min(2+6, 2*6) = 6 * min(8, 12) = 6 * 8 = 48.0
    double x = 2.0;
    double z = 6.0;
    double expected = 48.0;
    ASSERT_NEAR(calculate_w(x, z), expected, EPSILON);
}

TEST(Variant14Test, ZInRangeCase2) {
    // Тест 2: x=12, z=7. Умова: 5 < z < 10
    // Очікується: max(12, 7) * min(12+7, 12*7) = 12 * min(19, 84) = 12 * 19 = 228.0
    double x = 12.0;
    double z = 7.0;
    double expected = 228.0;
    ASSERT_NEAR(calculate_w(x, z), expected, EPSILON);
}

TEST(Variant14Test, ZOutsideRangeCase1_ZLessThan5) {
    // Тест 3: x=15, z=5. Умова: z <= 5
    // Очікується: min^2(|15 - 5|, 5) = min^2(10, 5) = 5^2 = 25.0
    double x = 15.0;
    double z = 5.0;
    double expected = 25.0;
    ASSERT_NEAR(calculate_w(x, z), expected, EPSILON);
}

TEST(Variant14Test, ZOutsideRangeCase2_ZGreaterThan10) {
    // Тест 4: x=3, z=10. Умова: z >= 10
    // Очікується: min^2(|3 - 10|, 10) = min^2(7, 10) = 7^2 = 49.0
    double x = 3.0;
    double z = 10.0;
    double expected = 49.0;
    ASSERT_NEAR(calculate_w(x, z), expected, EPSILON);
}

// Додатковий тест для перевірки макросів
TEST(MacroTest, MaxMin) {
    // Перевірка, чи коректно працює макрос MAX
    ASSERT_EQ(MAX(5, 10), 10);
    // Перевірка, чи коректно працює макрос MIN
    ASSERT_EQ(MIN(5, 10), 5);
}

