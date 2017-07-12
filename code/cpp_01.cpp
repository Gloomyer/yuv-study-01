#include <stdio.h>
#include <stdlib.h>

int simplest_yuv420_split(int w, int h,int num){  
    FILE *fp = fopen("../video/yuv_420p.yuv", "rb+");
    FILE *fp1 = fopen("../video/output_420_y.y", "wb+");
    FILE *fp2 = fopen("../video/output_420_u.y", "wb+");
    FILE *fp3 = fopen("../video/output_420_v.y", "wb+");

    unsigned char * pic = (unsigned char *)malloc(w * h * 3 / 2);

    for(int i = 0; i < num; i++){
        fread(pic, 1, w * h * 3 / 2, fp);

        fwrite(pic, 1, w * h , fp1);
    
        fwrite(pic + w * h, 1, w * h / 4, fp2);

        fwrite(pic + w * h * 5 / 4, 1, w * h / 4, fp3);
    }

    fclose(fp3);
    fclose(fp2);
    fclose(fp1);
    fclose(fp);

    return 0;
}

int main(){
    simplest_yuv420_split(352, 288, 300);

    return 0;
}