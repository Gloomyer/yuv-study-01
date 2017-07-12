#include <stdio.h>
#include <stdlib.h>

#define BORDER 10

int yuv420_border(int w, int h,int num){  
    FILE *fp = fopen("../video/yuv_420p.yuv", "rb+");
    FILE *fp1 = fopen("../video/output_420_border.yuv", "wb+");

    unsigned char * pic = (unsigned char *)malloc(w * h * 3 / 2);

    for(int i = 0; i < num; i++){
        fread(pic, 1, w * h * 3 / 2, fp);

		for(int j = 0;j < h; j++){
            for(int k = 0; k < w; k++){
				//这个判断就是为了计算出边框10个像素点的数据
                if(k < BORDER || k > (w-BORDER) || j < BORDER || j > ( h - BORDER)) 
                    pic[j*w+k]=255;
            }
        }

		fwrite(pic, 1, w * h * 3 / 2, fp1);
    }


    fclose(fp1);
    fclose(fp);

    return 0;
}

int main(){
    yuv420_border(352, 288, 300);
    return 0;
}