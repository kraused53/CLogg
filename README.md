# CLogg
A simple, cmake fetchable, [C]++ [Logg]er

## Features

- Simple API for emitting log messages from any C++ application
- Built as a static library — link once, use everywhere
- Clean CMake integration with namespace support (`clogg::clogg`)
- Optional example target to get started quickly

## Project Structure

```
CLogg/
├── src/            # Library implementation
├── example/        # Usage example (clogg_testing.cpp)
├── CMakeLists.txt
└── LICENSE         # MIT
```

## Requirements

- CMake 3.20+
- A C++20-compatible compiler (GCC, Clang, MSVC)

## Building

### Standalone

```bash
git clone https://github.com/kraused53/CLogg.git
cd CLogg
cmake -B build -DCLOGG_BUILD_EXAMPLES=ON
cmake --build build
```

The example binary will be placed in `bin/`.

### As a subdirectory (via `add_subdirectory`)

```cmake
add_subdirectory(CLogg)
target_link_libraries(your_target PRIVATE clogg::clogg)
```

### Via FetchContent

```cmake
include(FetchContent)

FetchContent_Declare(
    clogg
    GIT_REPOSITORY https://github.com/kraused53/CLogg.git
    GIT_TAG        main
)

FetchContent_MakeAvailable(clogg)

target_link_libraries(your_target PRIVATE clogg::clogg)
```

> **Note:** Examples are not built when consuming CLogg via FetchContent (`CLOGG_BUILD_EXAMPLES` defaults to `OFF`).

## Usage

Include the header and start logging:

```cpp
#include "CLogg.h"

int main() {
    // Example usage — refer to include/CLogg.h for the full API

    // Optional Color Output
    CLogg::enable_color();

    // Four levels of terminal logging
    CLogg::Log( "This is an informational log..." );
    CLogg::Dbg( "This is a debug log..." );
    CLogg::Wrn( "This is a warning log..." );
    CLogg::Err( "This is an error log..." );

    return 0;
}
```

See [`example/clogg_example.cpp`](example/clogg_example.cpp) for a complete working example.

## CMake Options

| Option | Default | Description |
|---|---|---|
| `CLOGG_BUILD_EXAMPLES` | `OFF` | Build the example executable |

## License

This project is licensed under the [MIT License](LICENSE).