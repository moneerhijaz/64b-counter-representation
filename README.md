# 64-bit counter visualization

A small C++17 terminal exercise that prints a counter in binary nibble groups and decimal, alongside elapsed time and an extrapolated completion estimate.

```bash
make                 # clang++ by default
./main               # Ctrl+C to stop
# Alternative compiler: make CXX=g++
```

Requires a C++17 compiler and Make. Output updates in place using carriage returns; avoid redirecting an unlimited run to a file. `make clean` removes local executables.

`main.cc` uses `uint64_t`, bit shifts, and `std::chrono`. The loop prints values from zero through `UINT64_MAX - 1`, excluding the maximum itself. The estimate reflects terminal-output overhead and early samples; it is not a CPU benchmark or a practical promise of completion.

Status: learning exercise. A short bounded smoke run can verify formatting, but completing the entire range is not a reasonable test. MIT: [LICENSE](LICENSE).
