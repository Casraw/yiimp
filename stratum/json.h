
/* vim: set et ts=3 sw=3 sts=3 ft=c:
 *
 * Copyright (C) 2012, 2013, 2014 James McLaughlin et al.  All rights reserved.
 * https://github.com/udp/json-parser
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */
#pragma once

typedef enum
{
   json_none = 0,
   json_object,
   json_array,
   json_integer,
   json_double,
   json_string,
   json_boolean,
   json_null
} json_type;

#ifndef JSON_H
#define JSON_H

// Declare the constant placeholder for invalid JSON values
#ifdef __cplusplus
extern const struct _json_value json_value_none; /* Zero-initialized by constructor */
#else
extern const struct _json_value json_value_none; /* Explicitly zero-initialized */
#endif

// Other declarations...

#endif // JSON_H

#ifndef _JSON_H
#define _JSON_H

#ifndef json_char
   #define json_char char
#endif

#ifndef json_int_t
   #ifndef _MSC_VER
      #include <inttypes.h>
      #define json_int_t int64_t
   #else
      #define json_int_t __int64
   #endif
#endif

#include <stdlib.h>

#ifdef __cplusplus

   #include <string.h>

   extern "C"
   {

#endif

typedef struct
{
   unsigned long max_memory;
   int settings;

   /* Custom allocator support (leave null to use malloc/free)
    */

   void * (* mem_alloc) (size_t, int zero, void * user_data);
   void (* mem_free) (void *, void * user_data);

   void * user_data;  /* will be passed to mem_alloc and mem_free */

} json_settings;

#ifndef JSON_H
#define JSON_H

typedef struct _json_object_entry {
    char* name;                   // Key name for objects
    unsigned int name_length;     // Length of the key name
    struct _json_value* value;    // Pointer to the value associated with the key
} json_object_entry;

typedef struct _json_value {
   struct _json_value* parent;   // Parent node in the JSON tree
   json_type type;               // JSON type (e.g., object, array, string, etc.)

   union {
     int boolean;              // Boolean value
     json_int_t integer;       // Integer value
     double dbl;               // Double value

     struct {
       unsigned int length;  // Length of the string
       char* ptr;            // Null-terminated string pointer
     } string;

      struct {
        unsigned int length;  // Number of object entries
        json_object_entry* values;  // Array of object entries (key-value pairs)
      } object;

      struct {
        unsigned int length;  // Number of array elements
        struct _json_value** values;  // Array of pointers to JSON values
      } array;
   } u;

   union {
     struct _json_value* next_alloc;  // Next allocated node (used internally)
     void* object_mem;               // Memory reserved for objects (used internally)
   } _reserved;

#ifdef __cplusplus
public:
   inline _json_value() { memset(this, 0, sizeof(_json_value)); }

   inline const struct _json_value& operator[](int index) const {
      if (type != json_array || index < 0 || (unsigned int)index >= u.array.length) {
         return json_value_none;
      }
      return *u.array.values[index];
   }

   inline const struct _json_value& operator[](const char* index) const {
      if (type != json_object) return json_value_none;

      for (unsigned int i = 0; i < u.object.length; ++i) {
         if (!strcmp(u.object.values[i].name, index)) {
            return *u.object.values[i].value;
         }
      }
      return json_value_none;
   }

   inline operator const char*() const {
      return type == json_string ? u.string.ptr : "";
   }

   inline operator json_int_t() const {
      return type == json_integer ? u.integer : (type == json_double ? (json_int_t)u.dbl : 0);
   }

   inline operator bool() const {
      return type == json_boolean && u.boolean != 0;
   }

   inline operator double() const {
      return type == json_double ? u.dbl : (type == json_integer ? (double)u.integer : 0.0);
   }
#endif

} json_value;

#endif // JSON_H

#define json_enable_comments  0x01

struct YAAMP_CLIENT; // Vorwärtsdeklaration

json_value * json_parse (const json_char * json,
                         size_t length);

#define json_error_max 128
json_value * json_parse_ex (json_settings * settings,
                            const json_char * json,
                            size_t length,
                            char * error);

void json_value_free (json_value *);


/* Not usually necessary, unless you used a custom mem_alloc and now want to
 * use a custom mem_free.
 */
void json_value_free_ex (json_settings * settings,
                         json_value *);

json_value* json_get_val(json_value *obj, const char *key);

// todo
char* json_dumps(json_value * value, int opt);

typedef json_value json_t;
#define json_typeof(json)      ((json)->type)
#define json_is_array(json)    (json && json_typeof(json) == json_array)
#define json_is_integer(json)  (json && json_typeof(json) == json_integer)
#define json_is_double(json)   (json && json_typeof(json) == json_double)
#define json_is_string(json)   (json && json_typeof(json) == json_string)
#define json_is_null(json)     (json && json_typeof(json) == json_null)

int json_integer_value(const json_value *json);
char* json_string_value(const json_value *json);
double json_double_value(const json_value *json);

json_value* json_new_object();
void json_add_bool(json_value* obj, const char* name, bool value);
void json_add_string(json_value* obj, const char* name, const char* value);
void json_add_null(json_value* obj, const char* name);
void stratum_send_json(YAAMP_CLIENT* client, json_value* response);

int json_get_int_value(json_value* obj, const char* key, int default_value);
double json_get_double_value(json_value* obj, const char* key, double default_value);
void json_add_value(json_value* obj, const char* key, json_value* value);
const char* json_get_string_value(json_value* obj, const char* key, const char* default_value);
void json_debug(json_value* obj);

#ifdef __cplusplus
   } /* extern "C" */
#endif

#endif


