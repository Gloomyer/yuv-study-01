#include <stdio.h>
#include <stdlib.h>

int yuv420_gray(int w, int h,int num){  
    FILE *fp = fopen("../video/yuv_420p.yuv", "rb+");
    FILE *fp1 = fopen("../video/output_420_gray.yuv", "wb+");

    unsigned char * pic = (unsigned char *)malloc(w * h * 3 / 2);

    for(int i = 0; i < num; i++){
        fread(pic, 1, w * h * 3 / 2, fp);
		for(int j = 0; j < w * h / 2; j++){
			(pic + w * h)[j] = 128; //u/vÐÞ¸ÄÎª128
			//printf("%d  ", (pic + w * h)[j]);
		}
		fwrite(pic, 1, w * h * 3 / 2, fp1);
    }


    fclose(fp1);
    fclose(fp);

    return 0;
}

int main(){
    yuv420_gray(352, 288, 300);
    return 0;
}