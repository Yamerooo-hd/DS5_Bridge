#include "runtime_fail_fast.h"

#include "hardware/watchdog.h"
#include "pico/platform.h"

extern "C" [[noreturn]] void sensa_runtime_panic(char const *message, ...) {
    (void)message;
    watchdog_enable(0, false);
    while (true) {
        tight_loop_contents();
    }
}

namespace std {

[[noreturn]] void __throw_bad_alloc() {
    sensa_runtime_panic("bad_alloc");
}

[[noreturn]] void __throw_bad_array_new_length() {
    sensa_runtime_panic("bad_array");
}

[[noreturn]] void __throw_length_error(char const *) {
    sensa_runtime_panic("length_error");
}

[[noreturn]] void __throw_out_of_range_fmt(char const *, ...) {
    sensa_runtime_panic("out_of_range");
}

} // namespace std
