#include"../header/header.h"
using namespace cv;
using namespace std;

char *negatives_document_name="negatives",
     *negatives_text_name="negatives"
    ,*positives_document_name="positives"
    ,*positives_text_name="positives"
    ,*data_doc ="data";

void train()
{
    Mat image;
    int image_height,image_width;
    // ///////////////////////// //////////
    char image_path[50];
    char image_name[50];

    int negatives_images_num=1;
    char negatives_text_path[50];

    sprintf(negatives_text_path,"%s/%s.txt",negatives_document_name,negatives_text_name);
    FILE *negatives_file=fopen(negatives_text_path,"w");
    while(1)
    {
        sprintf(image_name,"(%d)",negatives_images_num);
        sprintf(image_path,"%s/%s.jpg",negatives_document_name,image_name);
        image = imread(image_path,CV_LOAD_IMAGE_COLOR);
        if(image.cols==0)
        {
            negatives_images_num--;
            break;
        }
        sprintf(image_path,"%s/%d.jpg",negatives_document_name,negatives_images_num);
        imwrite(image_path,image);
        fprintf(negatives_file,"%d.jpg\n",negatives_images_num);
        negatives_images_num++;
    }
    fclose(negatives_file);

    int positives_images_num=1;
    char positives_text_path[50];

    sprintf(positives_text_path,"%s/%s.txt",positives_document_name,positives_text_name);
    FILE *positives_file=fopen(positives_text_path,"w");
    while(1)
    {
        sprintf(image_name," (%d)",positives_images_num);
        sprintf(image_path,"%s/%s.jpg",positives_document_name,image_name);
        image = imread(image_path,CV_LOAD_IMAGE_COLOR);
        if(image.cols==0)
        {
            positives_images_num--;
            break;
        }
        image_height = image.cols;
        image_width = image.rows;
        sprintf(image_path,"%s/%d.jpg",positives_document_name,positives_images_num);
        imwrite(image_path,image);
        fprintf(positives_file,"%d.jpg 1 0 0 %d %d\n\n",positives_images_num,image_height,image_width);
        positives_images_num++;
    }
    image.release();
    fclose(positives_file);

    //system("pause");

char system_input[150];

    sprintf(system_input,"opencv_createsamples.exe -info %s -vec data/positives.vec  -maxangel 10 -num %d -w 17 -h 14 -mode ALL",positives_text_path,positives_images_num);
    system(system_input);


    sprintf(system_input,"opencv_haartraining.exe -data %s/data -vec %s/positives.vec -bg %s -nsplit 2 -minpos %d -nonsym -nstages 7 -npos %d -nneg %d -minhitrate 0.9999 -maxfalsealarm 0.5 -weighttrimming 0.95 -w 17 -h 14 -mem 5000 -mode ALL  "
            ,data_doc,data_doc ,negatives_text_path,positives_images_num/2,positives_images_num,negatives_images_num);
    system(system_input);
}
