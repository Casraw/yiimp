#include "json.h"

// Define the constant placeholder for invalid JSON values
#ifdef __cplusplus
const struct json_value json_value_none; /* Zero-initialized by the constructor */
#else
const struct json_value json_value_none = { 0 }; /* Explicitly zero-initialized */
#endif