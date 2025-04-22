#pragma once
#include <stdio.h>
#include "matrix.h"
#include "type_info.h"

#ifdef __cplusplus
extern "C"
{
#endif

    const struct type_info *get_double_type();

#ifdef __cplusplus
}
#endif