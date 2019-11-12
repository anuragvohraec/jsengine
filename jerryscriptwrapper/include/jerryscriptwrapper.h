#ifndef jerryscriptwrapper
#define jerryscriptwrapper
#include "jerryscript.h"
char* giveMeStringFromJerryValue(jerry_value_t value);
char* runJSCode(char *program);
#endif // !jerryscriptwrapper