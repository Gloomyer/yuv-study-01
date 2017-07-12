#include <stdio.h>
#include <stdlib.h>

int simplest_yuv444_split(int w, int h,int num){  
    FILE *fp = fopen("../video/yuv_444p.yuv", "rb+");
    FILE *fp1 = fopen("../video/output_444_y.y", "wb+");
    FILE *fp2 = fopen("../video/output_444_u.y", "wb+");
    FILE *fp3 = fopen("../video/output_444_v.y", "wb+");

    unsigned char * pic = (unsigned char *)malloc(w * h * 3);

    for(int i = 0; i < num; i++){
        fread(pic, 1, w * h * 3, fp);

        fwrite(pic, 1, w * h , fp1);
    
        fwrite(pic + w * h, 1, w * h, fp2);

        fwrite(pic + w * h * 2, 1, w * h, fp3);
    }

    fclose(fp3);
    fclose(fp2);
    fclose(fp1);
    fclose(fp);

    return 0;
}

int main(){
    simplest_yuv444_split(256, 256, 1);

    return 0;
}