#include<stdio.h>
int neuron(int input[2], double w1, double w2, double b) {
	double z = w1 * input[0] + w2 * input[1] + b;
	double z_max = w1 + w2 + b;
	int activation = (z >=0) ? 1 : 0;
	return activation;

}
double* training() {
	double w1 = 1, w2 = 1, b = 0, learning_factor = 0.1;
	int input[4][2] = { {0,0},{1,0},{0,1},{1,1} };
	int output[] = { 0,0,0,1 };
	int n = 100;
	for (int i = 0;i < 200;i++) {

		int errors = 0;
		for (int f = 0;f < 4; f++) {
			int s = neuron(input[f], w1, w2, b);
			int error = output[f] - s;
			if (error != 0) {
				errors++;
				w1 = w1 + input[f][0] * error * learning_factor;
				w2 = w2 + input[f][1] * error * learning_factor;
				b = b + learning_factor * error;
			}

		}
		if (errors == 0) {
			break;
		}
	}
	 static double r[] = { w1,w2,b };
	return r;
}
int main() {
	//test case
	double *parameters = training();
	printf("enter input 1<0,1> :");
	int input1;
	scanf_s("%d", &input1);
	int input2;
	printf("enter input 2<0,1> :");
	scanf_s("%d",&input2);
	int x[] = {input1, input2};
	int n = neuron(x,parameters[0],parameters[1],parameters[2]);
	printf("your output is %d ",n);
	return 0;
}