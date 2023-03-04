// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  if (!n) return 1;
	else if (n==1) return value;
	int count = 0;
	double res = 1;
	while (count != n) {
		res *= value;
		count++;
	}
	return res;
}

uint64_t fact(uint16_t n) {
  if (!n) return 1;
	else return n*fact(n - 1);
}

double calcItem(double x, uint16_t n) {
  return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
  double sum = 1;
	uint16_t n = 1;
	while (n != count) {
		sum += calcItem(x, n);
		n++;
	}
	return sum;
}

double sinn(double x, uint16_t count) {
  double sum = x;
	uint16_t n = 2;
	while (n != count+1) {
		sum += pown(-1, n - 1) * calcItem(x, 2 * n - 1);
		n++;
	}
	return sum;
}

double cosn(double x, uint16_t count) {
  double sum = 1;
	uint16_t n = 2;
	while (n != count + 1) {
		sum += pown(-1, n - 1) * calcItem(x, 2 * n - 2);
		n++;
	}
	return sum;
}
