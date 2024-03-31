#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern void slidingWindowx64(float* input, float* answer, size_t INPUT_SIZE);

void slidingWindow(float* input, float* answer, size_t INPUT_SIZE) {
	int i, j;
	for (i = 0; i < INPUT_SIZE - 6; i++) {
		answer[i] = 0;
		for (j = 0; j < 7; j++) {
			answer[i] += input[i + j];
		}
	}
}

void printHeader(int k, float* input) {
	switch (k) {
	case 0:
		printf("2^20 Elements\n");
		break;
	case 1:
		printf("2^24 Elements\n");
		break;
	case 2:
		printf("2^28 Elements\n");
		break;
	}
	printf("%-18s", "First 10 inputs:");
	for (int i = 0; i < 10; i++) {
		printf("    %f", input[i]);
	}
	printf("\n\n");
}

int main() {
	// clock initialization
	clock_t begin, end;
	double timeTaken;
	double avgTime;

	// loop initialization
	int loop = 30;

	// input initializatioon
	float* input;

	// answer initializatioon
	float* answer;

	// size declaration
	size_t INPUT_BYTES, ANSWER_SIZE, ANSWER_BYTES;
	size_t INPUT_SIZE[] = { 1 << 20, 1 << 24, 1 << 28 }; // n (Vector Size)

	for (int k = 0; k < 3; k++) {
		INPUT_BYTES = INPUT_SIZE[k] * sizeof(float);
		ANSWER_SIZE = INPUT_SIZE[k] - 6;
		ANSWER_BYTES = ANSWER_SIZE * sizeof(float);

		// array initializatin
		input = (float*)malloc(INPUT_BYTES);
		answer = (float*)malloc(INPUT_BYTES);

		// initilization of array elements to 1
		for (int i = 0; i < INPUT_SIZE[k]; i++) {
			input[i] = (float)rand() / RAND_MAX;
		}

		printHeader(k, input);


		// C

		// fill the cache
		slidingWindow(input, answer, INPUT_SIZE[k]);
		free(answer);
		answer = (float*)malloc(INPUT_BYTES);


		timeTaken = 0;
		avgTime = 0;
		for (int i = 0; i < loop; i++) {
			begin = clock();
			slidingWindow(input, answer, INPUT_SIZE[k]);
			end = clock();
			timeTaken += ((double)(end - begin)) * 1e3 / CLOCKS_PER_SEC;
		}
		avgTime = timeTaken / loop;

		// Output printing
		printf("%-18s", "C output:");
		for (int i = 0; i < 10; i++) {
			printf("    %f", answer[i]);
		}
		printf("\n\nTotal Time: %f \n", timeTaken);
		printf("Average Time: %f \n\n", avgTime);

		// Refresh answer array
		free(answer);

		answer = (float*)malloc(INPUT_BYTES);


		// sasm

		// fill the cache
		slidingWindowx64(input, answer, INPUT_SIZE[k]);
		free(answer);
		answer = (float*)malloc(INPUT_BYTES);


		timeTaken = 0;
		avgTime = 0;
		for (int i = 0; i < loop; i++) {
			begin = clock();
			slidingWindowx64(input, answer, ANSWER_SIZE);
			end = clock();
			timeTaken += ((double)(end - begin)) * 1e3 / CLOCKS_PER_SEC;
		}
		avgTime = timeTaken / loop;

		// Output printing
		printf("%-18s", "SASM output:");
		for (int i = 0; i < 10; i++) {
			printf("    %f", answer[i]);
		}
		printf("\n\nTotal Time: %f \n", timeTaken);
		printf("Average Time: %f \n\n", avgTime);
		free(answer);
		free(input);
	}

	return 0;
}