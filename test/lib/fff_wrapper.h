#include <functional>
/* Configure FFF to use std::function, which enables capturing lambdas */
#define CUSTOM_FFF_FUNCTION_TEMPLATE(RETURN, FUNCNAME, ...) std::function<RETURN(__VA_ARGS__)> FUNCNAME
#include "fff.h"