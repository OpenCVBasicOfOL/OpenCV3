
#include <cv.h>
#include <highgui.h>
#include <stdio.h>
#include <stdlib.h>

void makeY(IplImage *orig, IplImage *r, IplImage *g, IplImage *b)
{
	int y, x;
	double e;
	double point = 0;
	double **store;

	store = (double**)malloc(sizeof(double)* orig->height);
	
	for ( y = 0 ; y < orig->height ; y ++)
	{
		store[y] = (double*)malloc(sizeof(double) * orig->width);
	}
	
	
	for ( y = 0 ; y < orig->height ; y ++)
	{
		for ( x = 0 ; x< orig->width  ; x++ )
		{
			
			CvScalar itensity1 = cvGet2D(r, y, x);
			CvScalar itensity2 = cvGet2D(g, y, x);
			CvScalar itensity3 = cvGet2D(b, y, x);
			store[y][x] = (double)itensity1.val[0] * 0.299 + (double)itensity2.val[0] * 0.587 + (double)itensity3.val[0] * 0.114;
		}
	}
	 

		
	for ( y = 0 ; y < orig->height ; y ++)
	{
		for ( x = 0 ; x< orig->width ; x++ )
		{
			cvSet2D(orig, y, x, cvScalar(store[y][x]));
		
		}
	}
	free(store);
}

void makeCb(IplImage *orig, IplImage *r, IplImage *g, IplImage *b)
{
	int y, x;
	double e;
	double point = 0;
	double **store;

	store = (double**)malloc(sizeof(double)* orig->height);
	
	for ( y = 0 ; y < orig->height ; y ++)
	{
		store[y] = (double*)malloc(sizeof(double) * orig->width);
	}
	
	
	for ( y = 0 ; y < orig->height ; y ++)
	{
		for ( x = 0 ; x< orig->width  ; x++ )
		{
			
			CvScalar itensity1 = cvGet2D(r, y, x);
			CvScalar itensity2 = cvGet2D(g, y, x);
			CvScalar itensity3 = cvGet2D(b, y, x);
			store[y][x] = 128 - (double)itensity1.val[0] * 0.168736 - (double)itensity2.val[0] * 0.331264 + (double)itensity3.val[0] * 0.5;
		}
	}
	 

		
	for ( y = 0 ; y < orig->height ; y ++)
	{
		for ( x = 0 ; x< orig->width ; x++ )
		{
			cvSet2D(orig, y, x, cvScalar(store[y][x]));
		
		}
	}
	free(store);
}

void makeCr(IplImage *orig, IplImage *r, IplImage *g, IplImage *b)
{
	int y, x;
	double e;
	double point = 0;
	double **store;

	store = (double**)malloc(sizeof(double)* orig->height);
	
	for ( y = 0 ; y < orig->height ; y ++)
	{
		store[y] = (double*)malloc(sizeof(double) * orig->width);
	}
	
	
	for ( y = 0 ; y < orig->height ; y ++)
	{
		for ( x = 0 ; x< orig->width  ; x++ )
		{
			
			CvScalar itensity1 = cvGet2D(r, y, x);
			CvScalar itensity2 = cvGet2D(g, y, x);
			CvScalar itensity3 = cvGet2D(b, y, x);
			store[y][x] = 128 + (double)itensity1.val[0] * 0.5 - (double)itensity2.val[0] * 0.418668 - (double)itensity3.val[0] * 0.081312;
		}
	}
	 

		
	for ( y = 0 ; y < orig->height ; y ++)
	{
		for ( x = 0 ; x< orig->width ; x++ )
		{
			cvSet2D(orig, y, x, cvScalar(store[y][x]));
		
		}
	}
	free(store);
}

void make22(IplImage *orig)
{
	int y, x;
	double e;
	double point = 0;
	double **store;

	store = (double**)malloc(sizeof(double)* orig->height);
	
	for ( y = 0 ; y < orig->height ; y ++)
	{
		store[y] = (double*)malloc(sizeof(double) * orig->width);
	}
	
	
	for ( y = 0 ; y < orig->height ; y ++)
	{
		for ( x = 0 ; x< orig->width  ; x+= 2 )
		{
			
			CvScalar itensity1 = cvGet2D(orig, y, x);
			CvScalar itensity2 = cvGet2D(orig, y, x+1);

			store[y][x] = ((double)itensity1.val[0] + (double)itensity2.val[0]) * 0.5;
			store[y][x+1] = ((double)itensity1.val[0] + (double)itensity2.val[0]) * 0.5;
		}
	}
	 

		
	for ( y = 0 ; y < orig->height ; y ++)
	{
		for ( x = 0 ; x< orig->width ; x++ )
		{
			cvSet2D(orig, y, x, cvScalar(store[y][x]));
		}
	}
	free(store);
}

void make20(IplImage *orig)
{
	int y, x;
	double e;
	double point = 0;
	double **store;

	store = (double**)malloc(sizeof(double)* orig->height);
	
	for ( y = 0 ; y < orig->height ; y ++)
	{
		store[y] = (double*)malloc(sizeof(double) * orig->width);
	}
	
	
	for ( y = 0 ; y < orig->height ; y +=2)
	{
		for ( x = 0 ; x< orig->width  ; x+= 2 )
		{
			
			CvScalar itensity1 = cvGet2D(orig, y, x);
			CvScalar itensity2 = cvGet2D(orig, y, x+1);
			CvScalar itensity3 = cvGet2D(orig, y+1, x);
			CvScalar itensity4 = cvGet2D(orig, y+1, x+1);

			double a = ((double)itensity1.val[0] + (double)itensity2.val[0] + (double)itensity3.val[0] + (double)itensity4.val[0]) * 0.25;

			store[y][x] = a;
			store[y][x+1] = a;
			store[y+1][x] = a;
			store[y+1][x+1] = a;
		}
	}
	 

		
	for ( y = 0 ; y < orig->height ; y ++)
	{
		for ( x = 0 ; x< orig->width ; x++ )
		{
			cvSet2D(orig, y, x, cvScalar(store[y][x]));
		}
	}
	free(store);
}

void make11(IplImage *orig)
{
		int y, x;
	double e;
	double point = 0;
	double **store;

	store = (double**)malloc(sizeof(double)* orig->height);
	
	for ( y = 0 ; y < orig->height ; y ++)
	{
		store[y] = (double*)malloc(sizeof(double) * orig->width);
	}
	
	
	for ( y = 0 ; y < orig->height ; y ++)
	{
		for ( x = 0 ; x< orig->width  ; x+= 4 )
		{
			
			CvScalar itensity1 = cvGet2D(orig, y, x);
			CvScalar itensity2 = cvGet2D(orig, y, x+1);
			CvScalar itensity3 = cvGet2D(orig, y, x+2);
			CvScalar itensity4 = cvGet2D(orig, y, x+3);

			store[y][x] = ((double)itensity1.val[0] + (double)itensity2.val[0] + (double)itensity3.val[0] + (double)itensity4.val[0]) * 0.25;
			store[y][x+1] = ((double)itensity1.val[0] + (double)itensity2.val[0] + (double)itensity3.val[0] + (double)itensity4.val[0]) * 0.25;
			store[y][x+2] = ((double)itensity1.val[0] + (double)itensity2.val[0] + (double)itensity3.val[0] + (double)itensity4.val[0]) * 0.25;
			store[y][x+3] = ((double)itensity1.val[0] + (double)itensity2.val[0] + (double)itensity3.val[0] + (double)itensity4.val[0]) * 0.25;
		}
	}
	 

		
	for ( y = 0 ; y < orig->height ; y ++)
	{
		for ( x = 0 ; x< orig->width ; x++ )
		{
			cvSet2D(orig, y, x, cvScalar(store[y][x]));
		}
	}
	free(store);
}

void make10(IplImage *orig)
{
		int y, x;
	double e;
	double point = 0;
	double **store;

	store = (double**)malloc(sizeof(double)* orig->height);
	
	for ( y = 0 ; y < orig->height ; y ++)
	{
		store[y] = (double*)malloc(sizeof(double) * orig->width);
	}
	
	
	for ( y = 0 ; y < orig->height ; y +=4)
	{
		for ( x = 0 ; x< orig->width  ; x+= 4 )
		{
			
			CvScalar itensity1 = cvGet2D(orig, y, x);
			CvScalar itensity2 = cvGet2D(orig, y, x+1);
			CvScalar itensity3 = cvGet2D(orig, y, x+2);
			CvScalar itensity4 = cvGet2D(orig, y, x+3);
			CvScalar itensity5 = cvGet2D(orig, y+1, x);
			CvScalar itensity6 = cvGet2D(orig, y+1, x+1);
			CvScalar itensity7 = cvGet2D(orig, y+1, x+2);
			CvScalar itensity8 = cvGet2D(orig, y+1, x+3);
			CvScalar itensity9 = cvGet2D(orig, y+2, x);
			CvScalar itensity10 = cvGet2D(orig, y+2, x+1);
			CvScalar itensity11 = cvGet2D(orig, y+2, x+2);
			CvScalar itensity12 = cvGet2D(orig, y+2, x+3);
			CvScalar itensity13 = cvGet2D(orig, y+3, x);
			CvScalar itensity14 = cvGet2D(orig, y+3, x+1);
			CvScalar itensity15 = cvGet2D(orig, y+3, x+2);
			CvScalar itensity16 = cvGet2D(orig, y+3, x+3);

			store[y][x] = ((double)itensity1.val[0] + (double)itensity2.val[0] + (double)itensity3.val[0] + (double)itensity4.val[0] + (double)itensity5.val[0] + (double)itensity6.val[0] + (double)itensity7.val[0] + (double)itensity8.val[0] + (double)itensity9.val[0] + (double)itensity10.val[0] + (double)itensity11.val[0] + (double)itensity12.val[0]+(double)itensity13.val[0] + (double)itensity14.val[0] + (double)itensity15.val[0] + (double)itensity16.val[0]) /16;
			store[y][x+1] = ((double)itensity1.val[0] + (double)itensity2.val[0] + (double)itensity3.val[0] + (double)itensity4.val[0] + (double)itensity5.val[0] + (double)itensity6.val[0] + (double)itensity7.val[0] + (double)itensity8.val[0] + (double)itensity9.val[0] + (double)itensity10.val[0] + (double)itensity11.val[0] + (double)itensity12.val[0]+(double)itensity13.val[0] + (double)itensity14.val[0] + (double)itensity15.val[0] + (double)itensity16.val[0]) /16;
			store[y][x+2] = ((double)itensity1.val[0] + (double)itensity2.val[0] + (double)itensity3.val[0] + (double)itensity4.val[0] + (double)itensity5.val[0] + (double)itensity6.val[0] + (double)itensity7.val[0] + (double)itensity8.val[0] + (double)itensity9.val[0] + (double)itensity10.val[0] + (double)itensity11.val[0] + (double)itensity12.val[0]+(double)itensity13.val[0] + (double)itensity14.val[0] + (double)itensity15.val[0] + (double)itensity16.val[0]) /16;
			store[y][x+3] = ((double)itensity1.val[0] + (double)itensity2.val[0] + (double)itensity3.val[0] + (double)itensity4.val[0] + (double)itensity5.val[0] + (double)itensity6.val[0] + (double)itensity7.val[0] + (double)itensity8.val[0] + (double)itensity9.val[0] + (double)itensity10.val[0] + (double)itensity11.val[0] + (double)itensity12.val[0]+(double)itensity13.val[0] + (double)itensity14.val[0] + (double)itensity15.val[0] + (double)itensity16.val[0]) /16;
			store[y+1][x] = ((double)itensity1.val[0] + (double)itensity2.val[0] + (double)itensity3.val[0] + (double)itensity4.val[0] + (double)itensity5.val[0] + (double)itensity6.val[0] + (double)itensity7.val[0] + (double)itensity8.val[0] + (double)itensity9.val[0] + (double)itensity10.val[0] + (double)itensity11.val[0] + (double)itensity12.val[0]+(double)itensity13.val[0] + (double)itensity14.val[0] + (double)itensity15.val[0] + (double)itensity16.val[0]) /16;
			store[y+1][x+1] = ((double)itensity1.val[0] + (double)itensity2.val[0] + (double)itensity3.val[0] + (double)itensity4.val[0] + (double)itensity5.val[0] + (double)itensity6.val[0] + (double)itensity7.val[0] + (double)itensity8.val[0] + (double)itensity9.val[0] + (double)itensity10.val[0] + (double)itensity11.val[0] + (double)itensity12.val[0]+(double)itensity13.val[0] + (double)itensity14.val[0] + (double)itensity15.val[0] + (double)itensity16.val[0]) /16;
			store[y+1][x+2] = ((double)itensity1.val[0] + (double)itensity2.val[0] + (double)itensity3.val[0] + (double)itensity4.val[0] + (double)itensity5.val[0] + (double)itensity6.val[0] + (double)itensity7.val[0] + (double)itensity8.val[0] + (double)itensity9.val[0] + (double)itensity10.val[0] + (double)itensity11.val[0] + (double)itensity12.val[0]+(double)itensity13.val[0] + (double)itensity14.val[0] + (double)itensity15.val[0] + (double)itensity16.val[0]) /16;
			store[y+1][x+3] = ((double)itensity1.val[0] + (double)itensity2.val[0] + (double)itensity3.val[0] + (double)itensity4.val[0] + (double)itensity5.val[0] + (double)itensity6.val[0] + (double)itensity7.val[0] + (double)itensity8.val[0] + (double)itensity9.val[0] + (double)itensity10.val[0] + (double)itensity11.val[0] + (double)itensity12.val[0]+(double)itensity13.val[0] + (double)itensity14.val[0] + (double)itensity15.val[0] + (double)itensity16.val[0]) /16;
			store[y+2][x] = ((double)itensity1.val[0] + (double)itensity2.val[0] + (double)itensity3.val[0] + (double)itensity4.val[0] + (double)itensity5.val[0] + (double)itensity6.val[0] + (double)itensity7.val[0] + (double)itensity8.val[0] + (double)itensity9.val[0] + (double)itensity10.val[0] + (double)itensity11.val[0] + (double)itensity12.val[0]+(double)itensity13.val[0] + (double)itensity14.val[0] + (double)itensity15.val[0] + (double)itensity16.val[0]) /16;
			store[y+2][x+1] = ((double)itensity1.val[0] + (double)itensity2.val[0] + (double)itensity3.val[0] + (double)itensity4.val[0] + (double)itensity5.val[0] + (double)itensity6.val[0] + (double)itensity7.val[0] + (double)itensity8.val[0] + (double)itensity9.val[0] + (double)itensity10.val[0] + (double)itensity11.val[0] + (double)itensity12.val[0]+(double)itensity13.val[0] + (double)itensity14.val[0] + (double)itensity15.val[0] + (double)itensity16.val[0]) /16;
			store[y+2][x+2] = ((double)itensity1.val[0] + (double)itensity2.val[0] + (double)itensity3.val[0] + (double)itensity4.val[0] + (double)itensity5.val[0] + (double)itensity6.val[0] + (double)itensity7.val[0] + (double)itensity8.val[0] + (double)itensity9.val[0] + (double)itensity10.val[0] + (double)itensity11.val[0] + (double)itensity12.val[0]+(double)itensity13.val[0] + (double)itensity14.val[0] + (double)itensity15.val[0] + (double)itensity16.val[0]) /16;
			store[y+2][x+3] = ((double)itensity1.val[0] + (double)itensity2.val[0] + (double)itensity3.val[0] + (double)itensity4.val[0] + (double)itensity5.val[0] + (double)itensity6.val[0] + (double)itensity7.val[0] + (double)itensity8.val[0] + (double)itensity9.val[0] + (double)itensity10.val[0] + (double)itensity11.val[0] + (double)itensity12.val[0]+(double)itensity13.val[0] + (double)itensity14.val[0] + (double)itensity15.val[0] + (double)itensity16.val[0]) /16;
			store[y+3][x] = ((double)itensity1.val[0] + (double)itensity2.val[0] + (double)itensity3.val[0] + (double)itensity4.val[0] + (double)itensity5.val[0] + (double)itensity6.val[0] + (double)itensity7.val[0] + (double)itensity8.val[0] + (double)itensity9.val[0] + (double)itensity10.val[0] + (double)itensity11.val[0] + (double)itensity12.val[0]+(double)itensity13.val[0] + (double)itensity14.val[0] + (double)itensity15.val[0] + (double)itensity16.val[0]) /16;
			store[y+3][x+1] = ((double)itensity1.val[0] + (double)itensity2.val[0] + (double)itensity3.val[0] + (double)itensity4.val[0] + (double)itensity5.val[0] + (double)itensity6.val[0] + (double)itensity7.val[0] + (double)itensity8.val[0] + (double)itensity9.val[0] + (double)itensity10.val[0] + (double)itensity11.val[0] + (double)itensity12.val[0]+(double)itensity13.val[0] + (double)itensity14.val[0] + (double)itensity15.val[0] + (double)itensity16.val[0]) /16;
			store[y+3][x+2] = ((double)itensity1.val[0] + (double)itensity2.val[0] + (double)itensity3.val[0] + (double)itensity4.val[0] + (double)itensity5.val[0] + (double)itensity6.val[0] + (double)itensity7.val[0] + (double)itensity8.val[0] + (double)itensity9.val[0] + (double)itensity10.val[0] + (double)itensity11.val[0] + (double)itensity12.val[0]+(double)itensity13.val[0] + (double)itensity14.val[0] + (double)itensity15.val[0] + (double)itensity16.val[0]) /16;
			store[y+3][x+3] = ((double)itensity1.val[0] + (double)itensity2.val[0] + (double)itensity3.val[0] + (double)itensity4.val[0] + (double)itensity5.val[0] + (double)itensity6.val[0] + (double)itensity7.val[0] + (double)itensity8.val[0] + (double)itensity9.val[0] + (double)itensity10.val[0] + (double)itensity11.val[0] + (double)itensity12.val[0]+(double)itensity13.val[0] + (double)itensity14.val[0] + (double)itensity15.val[0] + (double)itensity16.val[0]) /16;
		}
	}
	 

		
	for ( y = 0 ; y < orig->height ; y ++)
	{
		for ( x = 0 ; x< orig->width ; x++ )
		{
			cvSet2D(orig, y, x, cvScalar(store[y][x]));
		}
	}
	free(store);
}

int main()
{
	IplImage *herrington = cvLoadImage("lena.bmp");
	IplImage *result = cvCreateImage(cvGetSize(herrington), 8, 3);
	
	IplImage *Rh = cvCreateImage(cvGetSize(herrington), 8, 1);
	IplImage *Gh = cvCreateImage(cvGetSize(herrington), 8, 1);
	IplImage *Bh = cvCreateImage(cvGetSize(herrington), 8, 1);
	cvCvtColor(result, result, CV_RGB2YCrCb);
	cvSplit(herrington, Rh, Gh, Bh, 0);

	IplImage *Y = cvCreateImage(cvGetSize(herrington), 8, 1);
	IplImage *Cb = cvCreateImage(cvGetSize(herrington), 8, 1);
	IplImage *Cr = cvCreateImage(cvGetSize(herrington), 8, 1);
	
	makeY(Y, Rh, Gh, Bh);
	makeCb(Cb, Rh, Gh, Bh);
	makeCr(Cr, Rh, Gh, Bh);
	
	cvCvtPlaneToPix(Y, Cr, Cb, NULL, result);
	cvCvtColor(result, result, CV_YCrCb2RGB);
	cvSaveImage("444_Y.png", Y);
	cvSaveImage("444_Cr.png", Cr);
	cvSaveImage("444_Cb.png", Cb);
	cvSaveImage("444.png", result);
	

	
	makeY(Y, Rh, Gh, Bh);
	makeCb(Cb, Rh, Gh, Bh);
	makeCr(Cr, Rh, Gh, Bh);

	make22(Cb);
	make22(Cr);

	cvCvtPlaneToPix(Y, Cr, Cb, NULL, result);
	cvCvtColor(result, result, CV_YCrCb2RGB);
	cvSaveImage("422_Y.png", Y);
	cvSaveImage("422_Cr.png", Cr);
	cvSaveImage("422_Cb.png", Cb);
	cvSaveImage("422.png", result);
	
	
	makeY(Y, Rh, Gh, Bh);
	makeCb(Cb, Rh, Gh, Bh);
	makeCr(Cr, Rh, Gh, Bh);

	make20(Cb);
	make20(Cr);

	cvCvtPlaneToPix(Y, Cr, Cb, NULL, result);
	cvCvtColor(result, result, CV_YCrCb2RGB);
	cvSaveImage("420_Y.png", Y);
	cvSaveImage("420_Cr.png", Cr);
	cvSaveImage("420_Cb.png", Cb);
	cvSaveImage("420.png", result);
	

	makeY(Y, Rh, Gh, Bh);
	makeCb(Cb, Rh, Gh, Bh);
	makeCr(Cr, Rh, Gh, Bh);

	make11(Cb);
	make11(Cr);

	cvCvtPlaneToPix(Y, Cr, Cb, NULL, result);
	cvCvtColor(result, result, CV_YCrCb2RGB);
	cvSaveImage("411_Y.png", Y);
	cvSaveImage("411_Cr.png", Cr);
	cvSaveImage("411_Cb.png", Cb);
	cvSaveImage("411.png", result);


	makeY(Y, Rh, Gh, Bh);
	makeCb(Cb, Rh, Gh, Bh);
	makeCr(Cr, Rh, Gh, Bh);

	make10(Cb);
	make10(Cr);

	cvCvtPlaneToPix(Y, Cr, Cb, NULL, result);
	cvCvtColor(result, result, CV_YCrCb2RGB);
	cvSaveImage("410_Y.png", Y);
	cvSaveImage("410_Cr.png", Cr);
	cvSaveImage("410_Cb.png", Cb);
	cvSaveImage("410.png", result);
	
	cvReleaseImage(&herrington);
	cvReleaseImage(&Rh);
	cvReleaseImage(&Gh);
	cvReleaseImage(&Bh);
	cvReleaseImage(&Y);
	cvReleaseImage(&Cb);
	cvReleaseImage(&Cr);

	return 0;
}