/**
 * @file
 *
 * @brief Объявление прототипов функций и констант
 *
 */

#define COLOR_MORE(color, str, ...) printf("\033[%dm" #str "\033[0m", color, __VA_ARGS__)
#define COLOR(color, str) printf("\033[%dm%s\033[0m\n", color, str)

const        long double EPSILON = 1e-6;

const     int AMOUNT_COEFFS = 3;
const      int AMOUNT_ROOTS = 2;

const       char  hello_t[] = "**HELLO TEST MODE**";
const        char hello_u[] = "**HELLO USER MODE**";

const         char test_y[] = "**Завершен успешно**";
const         char test_n[] = "**Завершен c ошибкой**";

const char ERROR_ISFINITE[] = "Бесконечное число или NAN";
const      char PATH_NULL[] = "Нулевой указатель";
const     char SAME_PATHS[] = "Одинаковые пути на разные массивы";
const   char UNREAL_VALUE[] = "Невозможное значение переменной";

const      int ERROR_OUTPUT = -1;

struct COEFFS_AND_ROOTS {
                           long double a, b, c;
                           int solutions_ref;
                           long double x1_ref, x2_ref;
                           long double x1, x2;
                         };

enum COLOR {
                       RED = 31,
                     GREEN = 32,
                    YELLOW = 33,
                    PURPLE = 35
            };

enum NAME_ROOTS {
                        X1 = 0,
                        X2 = 1,
                    X1_REF = 0,
                    X2_REF = 1
                 };

enum NAME_COEFFS {
                    A_COEFF = 0,
                    B_COEFF = 1,
                    C_COEFF = 2
                  };

enum AMOUNT_ROOTS {
                       NO_NUM_TEST = -1,
                          NO_ROOTS = 0,
                          ONE_ROOT = 1,
                         TWO_ROOTS = 2,
                    INFINITY_ROOTS = 100,
                    NO_VALID_ROOTS = 777
                   };

/**
 * @brief  Осуществляет ввод коэффициентов с клавиатуры
 *
 * @param [in]   name                   name - имя коэффициента, значение которого будет введено
 *
 * @param [out]  coefficient     coefficient - массив, хранящий коэффициенты уравнения
 */
long double input_coefficient (char name);

/**
 * @brief Универсальная функция для очистки буфера ввода
 */
void clear_the_input_buffer (void);

/**
 * @brief  Запускает решение квадратного или линейного уравнения в зависимости от значений коэффициентов
 *
 * @param  [in] coeff       coeff - массив, хранящий коэффициенты уравнения
 * @param [out] roots        root - массив, хранящий корни ураванения
 *
 * @return int  Возвращает количество корней
 */
int solve_equation (COEFFS_AND_ROOTS* data);

/**
 * @brief  Решает линейные уравнения
 *
 * @param  [in] coeff       coeff - массив, хранящий коэффициенты уравнения
 * @param [out] roots        root - массив, хранящий корни уравнения
 *
 * @return int  Возвращает количество корней
 */
int solution_of_a_linear_equation (COEFFS_AND_ROOTS *data);

/**
 * @brief Решает квадратные уравнения
 *
 * @param  [in] coeff       coeff - массив, хранящий коэффициенты уравнения
 * @param [out] roots        root - массив, хранящий корни уравнения
 *
 * @return int  Возвращает количество корней
 */
int solution_of_a_quadratic_equation (COEFFS_AND_ROOTS *data);

/**
 * @brief  Выводит в консоль корни уравнения и их количество
 *
 * @param [in] solutions    solutions - количество корней
 * @param [in] roots             root - массив, хранящий корни уравнения
 */
int output_roots (COEFFS_AND_ROOTS* data, int solutions);
/**
 * @brief  Сравнивает число с нулем
 *
 * @param [in] num     num - число, которое необходимо сравнить с нулем
 * @return bool  Возвращает правду если число равно нулю и ложь во всех других случаях
 */
bool iszero (long double num);

/**
 * @brief Запускает тестирование программы, решающей квадратные уравнения
 *
 * @return int  Возвращает количество успешно пройденных тестов
 */
int test (void);

/**
 * @brief
 *
 * @param [in]  coeff                      coeff - массив, хранящий коэффициенты уравнения
 * @param [in]  roots                       root - массив, хранящий корни, которые нашла функция, решающая квадратные ураванение
 * @param [in]  roots_ref              roots_ref - массив, хранящий правильные корни уравнения
 * @param [in]  solutions              solutions - количество корней, которое посчитала функция, решающая квадратные ураванение
 * @param [in]  solutions_ref      solutions_ref - правильное количество корней
 * @param [out]  n_test_y               n_test_y - количество успешно пройденных тестов
 */
int dispatcher (int solutions, COEFFS_AND_ROOTS* data_t);

/**
 * @brief  Выводит всю информацию по тесту, который провалился
 *
 * @param [in]  coeff                      coeff - массив, хранящий коэффициенты уравнения
 * @param [in]  roots                       root - массив, хранящий корни, которые нашла функция, решающая квадратные ураванение
 * @param [in]  roots_ref              roots_ref - массив, хранящий правильные корни уравнения
 * @param [in]  solutions              solutions - количество корней, которое посчитала функция, решающая квадратные ураванение
 * @param [in]  solutions_ref      solutions_ref - правильное количество корней
 */
int test_finished_error (int solutions, COEFFS_AND_ROOTS* data_t);

/**
 * @brief Сравнивает два числа с плавающей точкой
 *
 * @param [in] num1    num1 - одно из чисел для сравнения
 * @param [in] num2    num2 - одно из чисел для сравнения
 * @return bool Возвращает правду, если числа равны и ложь во всех других случаях
 */
bool equality_double (long double num1, long double num2);

/**
 * @brief Делает вывод в консоль цветным
 *
 * @param [in] str         str - строка, которую нужно вывести определенным цветом
 * @param [in] color     color - цвет, в который должен быть покрашен вывод
 */
void color_output (const char* str, int color);

/**
 * @brief Проверяет код на ошибки
 *
 * @param data      Условие, выполнение которого говрит нам об ошибке в коде
 * @param error     Наименование ошибки
 * @param file      Имя файла, в котором произошла ошибка
 * @param func      Имя функции, в которой произошла ошибка
 * @param line      Номер строки, в которой произошла ошибка
 */
bool my_assert(bool data, const char* error, const char* file, const char* func, int line);