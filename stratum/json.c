#pragma once
#include "json.h"
#include "stratum.h"
#include "client.h"
#include <stdio.h> // Use this for C instead of <iostream>


// Define the constant placeholder for invalid JSON values
#ifdef __cplusplus
const struct _json_value json_value_none; /* Zero-initialized by the constructor */
#else
const struct _json_value json_value_none = { 0 }; /* Explicitly zero-initialized */
#endif