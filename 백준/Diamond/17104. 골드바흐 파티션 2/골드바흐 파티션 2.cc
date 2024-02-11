#include <stdio.h>
#include <math.h>
#define MM 1001000
//푸리에 변환후 길이
#define NN 1048576
//푸리에 변환 길이
#define DD 20
//log2(NN);

typedef float reals;
reals const PI = 3.14159265358979323846;
class complex {
public:
	reals real, imag;
	void Set(reals r, reals i) {
		real = r;
		imag = i;
	}
	void Set(complex c) {
		real = c.real;
		imag = c.imag;
	}
	void SetAngle(reals angle) {
		real = cos(angle);
		imag = sin(angle);
	}
	complex operator+(complex &c) {
		complex plus;
		plus.Set(real + c.real, imag + c.imag);
		return plus;
	}
	complex operator-(complex &c) {
		complex minus;
		minus.Set(real - c.real, imag - c.imag);
		return minus;
	}
	complex operator*(complex &c) {
		complex mul;
		mul.Set(real*c.real - imag * c.imag, real*c.imag + imag * c.real);
		return mul;
	}
};

int reverse(int a) {
	int res = 0, now = a;
	for (int i = 0; i < DD; i++) {
		res *= 2;
		res += now % 2;
		now /= 2;
	}
	return res;
}

void fft(int *a, int *a2, int len, complex *f) {
	complex temp, e, o;
	for (int i = 0; i <= len; i++) {
		a2[reverse(i)] = a[i];
	}
	for (int i = 0; i < NN; i += 2) {
		f[i].Set((reals)(a2[i] + a2[i + 1]), 0);
		f[i + 1].Set((reals)(a2[i] - a2[i + 1]), 0);
	}
	for (int i = 4; i <= NN; i *= 2) {
		for (int j = 0; j < NN; j += i) {
			for (int k = j; k < j + i / 2; k++) {
				e.Set(f[k]);
				o.Set(f[k + i / 2]);
				temp.SetAngle(-2 * PI / i * (k - j));
				o.Set(o * temp);
				f[k].Set(e + o);
				f[k + i / 2].Set(e - o);
			}
		}
	}
}

void ifft(complex *f1, complex *f2, int *c) {
	complex e, o, temp;
	reals d;
	for (int i = 0; i < NN; i++) {
		f2[reverse(i)].Set(f1[i]);
	}
	for (int i = 2; i <= NN; i *= 2) {
		for (int j = 0; j < NN; j += i) {
			for (int k = j; k < j + i / 2; k++) {
				e.Set(f2[k]);
				o.Set(f2[k + i / 2]);
				temp.SetAngle(2 * PI / i * (k - j));
				o.Set(o * temp);
				f2[k].Set(e + o);
				f2[k + i / 2].Set(e - o);
			}
		}
	}
	for (int i = 0; i < NN; i++) {
		d = f2[i].real / NN;
		c[i] = round(d);
	}
}

int main(void) {
	int a2[NN], b2[NN], c[NN], t, n;
	complex f1[NN], f2[NN];
	for (int i = 0; i < NN; i++) {
		a2[i] = 0;
		b2[i] = 0;
	}
	for (int i = 3; i < MM; i += 2) {
		a2[i] = 1;
	}
	for (int i = 3; i < MM; i += 2) {
		if (a2[i] == 1) {
			for (int j = i * 3; j < MM; j += 2 * i) {
				a2[j] = 0;
			}
			b2[i / 2] = 1;
		}
	}
	for (int i = 0; i < NN; i++) {
		c[i] = 0;
	}
	fft(b2, c, MM, f1);
	for (int i = 0; i < NN; i++) {
		f1[i].Set(f1[i] * f1[i]);
	}
	ifft(f1, f2, c);
	for (int i = 0; i < MM / 2; i++) {
		c[i] = (c[i] + 1) / 2;
	}
	c[1] = 1;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		printf("%d\n", c[n / 2 - 1]);
	}
}