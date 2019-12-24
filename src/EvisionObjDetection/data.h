#ifndef DATA_H
#define DATA_H
#include <pthread.h>

#if defined(_MSC_VER) && _MSC_VER < 1900
	#define inline __inline
#endif

#include "darknet.h"
#include "matrix.h"
#include "list.h"
#include "image.h"
#include "tree.h"
//#include <thread>

static inline float distance_from_edge(int x, int max)
{
    int dx = (max/2) - x;
    if (dx < 0) dx = -dx;
    dx = (max/2) + 1 - dx;
    dx *= 2;
    float dist = (float)dx/max;
    if (dist > 1) dist = 1;
    return dist;
}

void print_letters(float *pred, int n);
data load_data_captcha(char **paths, int n, int m, int k, int w, int h);
data load_data_captcha_encode(char **paths, int n, int m, int w, int h);
data load_data_old(char **paths, int n, int m, char **labels, int k, int w, int h);
data load_data_detection(int n, char **paths, int m, int w, int h, int c, int boxes, int classes, int use_flip, float jitter, float hue, float saturation, float exposure, int small_object);
data load_data_tag(char **paths, int n, int m, int k, int use_flip, int min, int max, int size, float angle, float aspect, float hue, float saturation, float exposure);
matrix load_image_augment_paths(char **paths, int n, int use_flip, int min, int max, int size, float angle, float aspect, float hue, float saturation, float exposure);
data load_data_super(char **paths, int n, int m, int w, int h, int scale);
data load_data_augment(char **paths, int n, int m, char **labels, int k, tree *hierarchy, int use_flip, int min, int max, int size, float angle, float aspect, float hue, float saturation, float exposure);
data load_go(char *filename);

box_label *read_boxes(char *filename, int *n);
data load_cifar10_data(char *filename);
data load_all_cifar10();

data load_data_writing(char **paths, int n, int m, int w, int h, int out_w, int out_h);

list *get_paths(char *filename);
char **get_labels(char *filename);
char **get_labels_custom(char *filename, int *size);
void get_random_batch(data d, int n, float *X, float *y);
data get_data_part(data d, int part, int total);
data get_random_data(data d, int num);
void get_next_batch(data d, int n, int offset, float *X, float *y);
data load_categorical_data_csv(char *filename, int target, int k);
void normalize_data_rows(data d);
void scale_data_rows(data d, float s);
void translate_data_rows(data d, float s);
void randomize_data(data d);
data *split_data(data d, int part, int total);
data concat_data(data d1, data d2);
data concat_datas(data *d, int n);
void fill_truth(char *path, char **labels, int k, float *truth);

#endif
