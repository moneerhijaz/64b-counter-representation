#include <cstdio>
#include <cstdint>
#include <chrono>
#include <cmath>
#include <inttypes.h>

int main() {
	using namespace std::chrono;
	auto start = high_resolution_clock::now();
	long double days_left = 0;
	const uint64_t MAX_t = 0xFFFFFFFFFFFFFFFF;
	const long double MS_PER_DAY = 1000.0L * 60.0L * 60.0L * 24.0L;
	bool updated = false;

	for (uint64_t bit = 0; bit < MAX_t; bit++) {
		printf("\rBits: ");
		for (int i = 63; i >= 0; i--) {
			printf("%d", static_cast<int>((bit >> i) & 1ULL));
			
			if (i % 4 == 0) {
				printf(" ");
			}
		}
		printf("| ");
	
		auto end = high_resolution_clock::now();
		long double elapsed_ms = duration<long double, std::milli>(end - start).count();
		long double elapsed_s = duration<long double>(end - start).count();
		long double done = static_cast<long double>(bit) + 1.0L;
		uint64_t remaining_iters = MAX_t - bit - 1;
		long double mod_5s = std::fmod(elapsed_s, 5.0L);
		if (mod_5s < 1.0L && !updated) {
			days_left = (elapsed_ms / done) * static_cast<long double>(remaining_iters) / MS_PER_DAY;
			updated = true;
		} else if (mod_5s >= 1.0L) {
			updated = false;
		}
	
		printf("Decimal: %" PRIu64 " | ", bit);
		printf("Time elapsed: %.2Lf seconds | ", elapsed_s);
		printf("Time left: %.2Lf years", days_left / 365);
		fflush(stdout);
	}

	return 0;
}
