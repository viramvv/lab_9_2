cmake_minimum_required(VERSION 3.26)
project(lab_9_2)

set(CMAKE_CXX_STANDARD 17)

# --- Налаштування Google Test ---
# Вимагає знайти бібліотеки Google Test та Google Mock
find_package(GTest REQUIRED)

# --- 1. Бібліотека з макросами та виразом (lab_9_2) ---

# Додаємо вихідні файли бібліотеки
add_library(lab_9_2
        lab_9_2.cpp
        lab_9_2.h
)

# --- 2. Виконуваний файл програми (main.cpp) ---

# Додаємо основний виконуваний файл (програма для користувача)
add_executable(lab_9_2_app main.cpp)
# Лінкуємо його з нашою бібліотекою (де визначені макроси)
target_link_libraries(lab_9_2_app lab_9_2)

# --- 3. Виконуваний файл тестів (UnitTest9.cpp) ---

# Додаємо виконуваний файл тестів
add_executable(UnitTest9 UnitTest9.cpp)
# Лінкуємо його з нашою бібліотекою (що тестується) та бібліотеками GTest
target_link_libraries(UnitTest9
        lab_9_2
        GTest::gtest_main
)

# Додаємо команду для запуску тестів через ctest
include(GoogleTest)
gtest_discover_tests(UnitTest9)