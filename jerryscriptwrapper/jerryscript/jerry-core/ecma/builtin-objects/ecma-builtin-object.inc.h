/* Copyright JS Foundation and other contributors, http://js.foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * Object built-in description
 */

#include "ecma-builtin-helpers-macro-defines.inc.h"

/* Number properties:
 *  (property name, number value, writable, enumerable, configurable) */

/* ECMA-262 v5, 15.2.3 */
NUMBER_VALUE (LIT_MAGIC_STRING_LENGTH,
              1,
              ECMA_PROPERTY_FIXED)

/* Object properties:
 *  (property name, object pointer getter) */

/* ECMA-262 v5, 15.2.3.1 */
OBJECT_VALUE (LIT_MAGIC_STRING_PROTOTYPE,
              ECMA_BUILTIN_ID_OBJECT_PROTOTYPE,
              ECMA_PROPERTY_FIXED)

/* Routine properties:
 *  (property name, C routine name, arguments number or NON_FIXED, value of the routine's length property) */
ROUTINE (LIT_MAGIC_STRING_GET_PROTOTYPE_OF_UL, ECMA_OBJECT_ROUTINE_GET_PROTOTYPE_OF, 1, 1)
ROUTINE (LIT_MAGIC_STRING_GET_OWN_PROPERTY_NAMES_UL, ECMA_OBJECT_ROUTINE_GET_OWN_PROPERTY_NAMES, 1, 1)
#if ENABLED (JERRY_ES2015)
ROUTINE (LIT_MAGIC_STRING_GET_OWN_PROPERTY_SYMBOLS_UL, ECMA_OBJECT_ROUTINE_GET_OWN_PROPERTY_SYMBOLS, 1, 1)
#endif /* ENABLED (JERRY_ES2015) */
ROUTINE (LIT_MAGIC_STRING_SEAL, ECMA_OBJECT_ROUTINE_SEAL, 1, 1)
ROUTINE (LIT_MAGIC_STRING_FREEZE, ECMA_OBJECT_ROUTINE_FREEZE, 1, 1)
ROUTINE (LIT_MAGIC_STRING_PREVENT_EXTENSIONS_UL, ECMA_OBJECT_ROUTINE_PREVENT_EXTENSIONS, 1, 1)
ROUTINE (LIT_MAGIC_STRING_IS_SEALED_UL, ECMA_OBJECT_ROUTINE_IS_SEALED, 1, 1)
ROUTINE (LIT_MAGIC_STRING_IS_FROZEN_UL, ECMA_OBJECT_ROUTINE_IS_FROZEN, 1, 1)
ROUTINE (LIT_MAGIC_STRING_IS_EXTENSIBLE, ECMA_OBJECT_ROUTINE_IS_EXTENSIBLE, 1, 1)
ROUTINE (LIT_MAGIC_STRING_KEYS, ECMA_OBJECT_ROUTINE_KEYS, 1, 1)
ROUTINE (LIT_MAGIC_STRING_GET_OWN_PROPERTY_DESCRIPTOR_UL, ECMA_OBJECT_ROUTINE_GET_OWN_PROPERTY_DESCRIPTOR, 2, 2)
ROUTINE (LIT_MAGIC_STRING_CREATE, ECMA_OBJECT_ROUTINE_CREATE, 2, 2)
ROUTINE (LIT_MAGIC_STRING_DEFINE_PROPERTIES_UL, ECMA_OBJECT_ROUTINE_DEFINE_PROPERTIES, 2, 2)
ROUTINE (LIT_MAGIC_STRING_DEFINE_PROPERTY_UL, ECMA_OBJECT_ROUTINE_DEFINE_PROPERTY, 3, 3)

#if ENABLED (JERRY_ES2015_BUILTIN)
ROUTINE (LIT_MAGIC_STRING_SET_PROTOTYPE_OF_UL, ECMA_OBJECT_ROUTINE_SET_PROTOTYPE_OF, 2, 2)
ROUTINE (LIT_MAGIC_STRING_ASSIGN, ECMA_OBJECT_ROUTINE_ASSIGN, NON_FIXED, 2)
ROUTINE (LIT_MAGIC_STRING_IS, ECMA_OBJECT_ROUTINE_IS, 2, 2)
#endif /* ENABLED (JERRY_ES2015_BUILTIN) */

#include "ecma-builtin-helpers-macro-undefs.inc.h"
