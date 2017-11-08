/*
* Yiheng Zhang 08.30.2017
* programmed once
*/

#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <assert.h>
#include "bmp.h"

using namespace std;

double countRMSE(_BMP& pic, _BMP& ref)
{
	assert(pic.getWidth() == ref.getWidth());
	assert(pic.getHeight() == ref.getHeight());

	int w = pic.getWidth(), h = pic.getHeight();
	int n = w * h * 3;
	double RMSE = 0;


	double NUM_256 = 256;

	for (int y = 0; y < h; ++y)
	{
		for (int x = 0; x < w; ++x)
		{
			int R1 = pic.ImgValue_s[3 * (w*y + x) + 2];
			int G1 = pic.ImgValue_s[3 * (w*y + x) + 1];
			int B1 = pic.ImgValue_s[3 * (w*y + x) + 0];

			int R2 = ref.ImgValue_s[3 * (w*y + x) + 2];
			int G2 = ref.ImgValue_s[3 * (w*y + x) + 1];
			int B2 = ref.ImgValue_s[3 * (w*y + x) + 0];

			if (abs(R1 - R2) > 255 || abs(G1 - G2) > 255 || abs(B1 - B2) > 255)
			{
				cout << "error" << endl;
			}

			double diffR = pow(abs(R1 - R2), 2) / NUM_256 / NUM_256;
			double diffG = pow(abs(G1 - G2), 2) / NUM_256 / NUM_256;
			double diffB = pow(abs(B1 - B2), 2) / NUM_256 / NUM_256;

			double sum = (diffR + diffG + diffB);

			RMSE = RMSE + sum;
		}
	}

	RMSE = RMSE / n;
	//cout << RMSE << endl;
	return RMSE;
}


int main()
{
	_BMP pic, ref;
	double RMSE = 0;

	pic.Load("ggbs_s_mbe_iter=10_time=36.884003.bmp");
	ref.Load("ref.bmp");
	//pic.DownSample(1);
	//pic.Save("gray.bmp");
	//cout << pic.getHeight() << pic.getWidth() << ref.getHeight() << ref.getWidth() << endl;

	RMSE = countRMSE(pic, ref);
	cout << "The RMSE between test pic and reference = " << RMSE << endl;

	return 0;
}