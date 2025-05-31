#include <stdio.h>
#include <stdlib.h>

// Function to allocate memory for the array
float** allocateArray(int students) {
	float** arr = (float**)malloc(students*sizeof(float*));
	if (!arr) {
		return NULL;
	}
	for (int i = 0; i < students; i++) {
		arr[i] = (float*)malloc(3*sizeof(float));
		if (!arr[i]) {
			for(int j = 0; j < i; j++) {
				free(arr[j]);
			}
			free(arr);
			return NULL;
		}
	}
	return arr;
}

// Function to free the allocated memory
void deallocateArray(float** arr, int students) {
	for (int i = 0; i < students; i++) {
		free(arr[i]);
	}
	free(arr);
}

// Function to calculate BMI and store in the third column
void calculateBMI(float** arr, int students) {
	for (int i = 0; i < students; i++) {
		arr[i][2] = arr[i][1] / (arr[i][0] * arr[i][0]);	
	}
}

// Function to count students with BMI within the given range
int countStudentsInBMIRange(float** arr, int students, float low, float high) {
	int count = 0;
	for (int i = 0; i < students; i++) {
		if (arr[i][2] >= low && arr[i][2] <= high) {
			count++;
		}
	} 
	return count;
}

int testAllocateArray() {
	int marks = 0;
	int students = 4;
	float** arr = allocateArray(students);

	// Check if the memory was allocated correctly
	if(arr != NULL) {
		for (int i = 0; i < students; i++) {
			if(arr[i] != NULL);  // Ensure each row is not NULL
			marks += 1;
		}
	}

	// Clean up
	deallocateArray(arr, students);

	printf(" %d/%d", marks, 4);
	return marks;
}

int testCalculateBMI() {
	int students = 4;
	float heights[5] = {1.75, 1.60, 1.80, 1.68};
	float weights[5] = {68, 55, 80, 60};
	float expected_bmis[5] = {22.20, 21.48, 24.69, 21.26};
	int marks = 0;

	float** arr = allocateArray(students);

	// Assign height and weight
	for (int i = 0; i < students; i++) {
		arr[i][0] = heights[i];
		arr[i][1] = weights[i];
	}

	// Calculate BMI
	calculateBMI(arr, students);

	// Test BMI calculation
	for (int i = 0; i < students; i++) {
		// Check if calculated BMI matches expected BMI (within tolerance due to float precision)
		if ((arr[i][2] - expected_bmis[i]) < 0.01) {
			marks += 1;  // Increment marks if the test passes
		}
	}

	deallocateArray(arr, students);
	printf("%d/%d\n", marks, students);  // Print marks out of total students
	return marks;
}

int testCountStudentsInBMIRange() {
	int students = 5;
	float heights[5] = {1.75, 1.60, 1.80, 1.68, 1.50};
	float weights[5] = {68, 55, 80, 60, 45};
	float expected_bmis[5] = {22.20, 21.48, 24.69, 21.26, 20.00};
	int marks = 0;

	float** arr = allocateArray(students);

	// Assign height and weight
	for (int i = 0; i < students; i++) {
		arr[i][0] = heights[i];
		arr[i][1] = weights[i];
	}

	// Calculate BMI
	calculateBMI(arr, students);

	// Test with range 21-23 (should match 3 students)
	int count = countStudentsInBMIRange(arr, students, 21, 23);
	if(count == 3) {
		marks += 4;
	}

	// Test with range 19-21 (should match 1 student)
	count = countStudentsInBMIRange(arr, students, 19, 21);
	if(count == 1) {
		marks += 4;
	}

	// Test with range 24-25 (should match 1 student)
	count = countStudentsInBMIRange(arr, students, 24, 25);
	if(count == 1) {
		marks += 4;
	}

	deallocateArray(arr, students);

	printf(" %d/%d", marks, 12);
	return marks;
}

int main() {
	printf("\033[1m\033[36m\nTesting 2D Dynamic Arrays:\033[0m");
	int total = 0;
	int max_marks = 20;

	printf("\n\n\033[35mTesting allocation:\033[0m");
	total += testAllocateArray();

	printf("\n\n\033[35mTesting BMI calculation:\033[0m");
	total += testCalculateBMI();

	printf("\n\n\033[35mTesting number of students in BMI range:\033[0m");
	total += testCountStudentsInBMIRange();

	printf("\n\n\033[1m\033[35mTotal:\033[0m %d/%d\n\n", total, max_marks);

	return 0;
}