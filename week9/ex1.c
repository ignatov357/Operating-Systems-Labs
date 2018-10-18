#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

int miss = 0, hit = 0;

typedef struct frame{
    int page_number;
    unsigned char lifespan;
    bool referenced;
} frame;

void paging(int number, frame* frames,  int frame_size);

int main(){
    int frame_size = 20;
    scanf("%d", &frame_size);
    frame frames[frame_size];
    FILE *fp = fopen("Lab 09 input.txt", "r");
    int number = 0;

    for (int j = 0 ; j < frame_size; ++j) {
        frames[j].page_number = -1;
        frames[j].referenced = false;
        frames[j].lifespan = 0;
    }

    while (fscanf(fp, "%d", &number) == 1) paging(number, &frames, frame_size);


    fclose(fp);
    printf("\nHIT = %d | MISS = %d\nHIT/MISS Rate = %f\n",hit, miss, (float) hit/miss);

    return 0;
}

void paging(int number, frame* frames, int frame_size) {
    bool founded;
    founded = false;
    for (int j = 0; j < frame_size; ++j) {
        if (frames[j].page_number != number) frames[j].referenced = false;
        else {
            frames[j].referenced = true;
            founded = true;
            hit++;
            printf("HIT: %d\n", number);
        }
    }

    if(!founded){
        miss++;
        int minimal_index = 0;
        unsigned char minimal_span;
        minimal_span = frames[0].lifespan;
        for(int j = 1; j < frame_size; j++)
            if (minimal_span > frames[j].lifespan) {
                minimal_index = j;
                minimal_span = frames[j].lifespan;
            }

        frames[minimal_index].referenced = true;
        frames[minimal_index].page_number = number;
    }

    for(int j = 0; j < frame_size; j++){
        frames[j].lifespan >>= 1;
        if (frames[j].referenced) frames[j].lifespan = (1 << (sizeof(frames[j].lifespan)*8-1)) | frames[j].lifespan;
    }
}