#include "systemFunc.h"
#include "../stdlib/stdlib.h"

#define IS_CMD(line, cmd) ((unsigned int) strstr(line, cmd) == (unsigned int) line)

int start()
{
    char *line;
    unsigned int temp;

    uprintf("----------System shell-----------\n");
    line = (char*)umalloc(256);

    while (1)
    {
        uprintf("> ");
        ureadln(line);

        if (IS_CMD(line, "help")) {
            uprintf("All commands:\n");
            uprintf("help           - show this text\n");
            uprintf("exec file_name - run the specified program\n");
            uprintf("kill pid       - kills process\n");
            uprintf("all            - list all processes\n");
            uprintf("clear          - clear screen\n");
        } else if (IS_CMD(line, "exec")) {
            uprintf("pid: 0x%x\n", uexec((char*)(line + strlen("exec") + 1)));

        } else if (IS_CMD(line, "kill")) {
            temp = str_toIntHex(line + strlen("kill") + 1);
            if (temp != 0)
                ukill(temp);
            uprintf("process killed: 0x%x\n", temp);
        } else if (IS_CMD(line, "all")) {
            print_processes();
        } else if (IS_CMD(line, "clear")) {
            uclear_screen();
        } else {
            uprintf("unknown command %s\n", line);
        }
    }
}
