#include "Complex.h"
#include "matread.h"

#define PIC_SIZE_H (1080)
#define PIC_SIZE_W (1920)
#define MAX_ITERATIONS (500)


Mat m(PIC_SIZE_H, PIC_SIZE_W, CV_8UC3, Scalar(255, 255, 255));
Matread mr(m);

int mandelb(const Comp& c) {
	Comp x(0, 0);
	int ans = 0;
	while (abs2(x) < 4 && ans < 500) {
		x = x * x + c;
		ans++;
	}
	if (ans != MAX_ITERATIONS)
		return ans;
	else
		return 0;
}

int main() {
	int frame = 0;
	while (waitKey(1)) {
		for (int x = 0; x < PIC_SIZE_W; x++)
		for (int y = 0; y < PIC_SIZE_H; y++) {
			pt x_ = +(((pt) x) / (PIC_SIZE_W - 1) * 2 - 1) * PIC_SIZE_W / PIC_SIZE_H;
			pt y_ = -(((pt) y) / (PIC_SIZE_H - 1) * 2 - 1);
			Comp c = Comp(x_ * 2 / pow(2, frame) - 1.7433419053321 , y_ * 2 / pow(2, frame) + 0.0000907687489);
			int mand = mandelb(c);
			if (mand == 0 || true) {
				mr.get(x, y, 0) = mand * 111;
				mr.get(x, y, 1) = mand * 53;
				mr.get(x, y, 2) = mand * 137;
			}
		}

		//imshow("main", m);
		frame++;
		cout << frame << endl;
		imwrite(to_string(frame) + ".jpg", m);
	}
}