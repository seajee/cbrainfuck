#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if (argc <= 1)
    {
        fprintf(stderr, "Usage: cbrainfuck <filename>\n");
        return 1;
    }

    const char* file_name = argv[1];
    const char* out_file_name = "bf.c";
    char* c_compile_cmd = "cc bf.c -o bf.o";
    FILE* file = fopen(file_name, "rb");

    if (file == NULL)
    {
        fprintf(stderr, "Error: Could not read file\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    char* program = malloc(file_size + 1);
    fread(program, file_size, 1, file);
    fclose(file);
    program[file_size] = 0;

    char instruction;
    size_t program_size = strlen(program);

    FILE* out_file = fopen(out_file_name, "w");

    if (out_file == NULL)
    {
        fprintf(stderr, "Error: Could not create output file\n");
        return 1;
    }

    fputs("#include <stdio.h>\nint main()\n{\n    char memory[4096] = { 0 };\n    char* ptr = memory;\n", out_file);

    for (size_t i = 0; i < program_size; ++i)
    {
        instruction = program[i];

        switch (instruction)
        {
            case '>':
                fputs("    ++ptr;\n", out_file);
                break;
            case '<':
                fputs("    --ptr;\n", out_file);
                break;
            case '+':
                fputs("    ++*ptr;\n", out_file);
                break;
            case '-':
                fputs("    --*ptr;\n", out_file);
                break;
            case '.':
                fputs("    putchar(*ptr);\n", out_file);
                break;
            case ',':
                fputs("    *ptr = getchar();", out_file);
                break;
            case '[':
                fputs("    while (*ptr)\n    {\n", out_file);
                break;
            case ']':
                fputs("    }\n", out_file);
        }
    }

    fputs("    return 0;\n}", out_file);
    fclose(out_file);
    system(c_compile_cmd);

    if (remove("bf.c") != 0)
        printf("Alert: Could not delete translated file \"bf.c\"\n");

    printf("Compiled Successfully\n");
    
    return 0;
}
