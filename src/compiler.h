#ifndef _COMPILER_H_
#define _COMPILER_H_

#include <stdint.h>
#include <stddef.h>

#define CMD_CC "gcc"

#define BF_MEMORY_CAPACITY 4096
#define STR_IMPL_(x) #x
#define STR(x) STR_IMPL_(x)

#define C_ENTRYPOINT \
    "#include <stdio.h>\n" \
    "int main(void)\n" \
    "{\n" \
    "char memory[" STR(BF_MEMORY_CAPACITY) "] = { 0 };\n" \
    "char* ptr = memory;\n\n"
#define C_END "\nreturn 0;\n}"

#define C_PTR_INC    "++ptr;\n"
#define C_PTR_DEC    "--ptr;\n"
#define C_PLUS       "++*ptr;\n"
#define C_MINUS      "--*ptr;\n"
#define C_PRINT      "putchar(*ptr);\n"
#define C_INPUT      "*ptr = getchar();"
#define C_LOOP_START "while (*ptr) {\n"
#define C_LOOP_END   "}\n"

#define BF_PLUS       '+'
#define BF_MINUS      '-'
#define BF_RIGHT      '>'
#define BF_LEFT       '<'
#define BF_LOOP_START '['
#define BF_LOOP_END   ']'

int32_t transpile_program_to_file(const char* program, size_t program_size, const char* file_path);
int32_t compile_program(const char* transpiled_file_path, const char* out_file);

#endif // _COMPILER_H_
