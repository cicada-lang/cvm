#include "index.h"
#include "../lang/tests/index.h"

static int run(const char **args);

void
version_command(const command_runner_t *runner) {
    command_t *command = command_create("version");
    command->run_fn = run;
    command_runner_add_command(runner, command);
}

static int
run(const char **args) {
    (void) args;

    printf("%s\n", X_VERSION);

    return 0;
}
