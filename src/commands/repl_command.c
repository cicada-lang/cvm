#include "index.h"
#include "../lang/index.h"

static int run(const char **args);

void
repl_command(const command_runner_t *runner) {
    command_t *command = command_create("repl");
    command->description = "start the read-eval-print-loop";
    command->run = run;
    command_runner_add_command(runner, command);
}

int
run(const char **args) {
    (void) args;

    printf("%s\n", X_VERSION);

    return 0;
}
