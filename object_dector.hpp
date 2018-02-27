#ifndef SRC_SRC_F2D_OBJECT_DECTOR_HPP_
#define SRC_SRC_F2D_OBJECT_DECTOR_HPP_

#include <list>
#define RAW_IMAGE_CHANNEL	-1
#define RAW_IMAGE_SIZE		0
#define WEIGHT_CNT			-1
#define CLASS_CNT			20
#define PURE_POST_PROCESSING 1
#define DEMO_MODE	0

#define INPUT_RAW_PIXEL	(416)
#define INPUT_COL_PIXEL	(416)
#define INPUT_SIZE	(INPUT_RAW_PIXEL*INPUT_COL_PIXEL)
#define INPUT_RGB_CHANNEL	3
#define OUTPUT_RAW_PIXEL	INPUT_RAW_PIXEL
#define OUTUT_COL_PIXEL		INPUT_COL_PIXEL
#define OUTPUT_LOCATION_X	(400)
#define OUTPUT_LOCATION_Y	(500)
#define PREDICT_CUBE_SIZE	(7*7*30*4)
#define PREDICT_CUBE_WIDTH	(7)
#define PREDICT_CUBE_HEIGHT	(7)
#define PREDICT_CUBE_DEPTH	(30)
#define PREDICT_NUM_OF_BOX  (2)
#define PREDICT_NUM_OF_GRIDS	(PREDICT_CUBE_WIDTH * PREDICT_CUBE_HEIGHT)

typedef struct the_class
{
	unsigned int index;
	float prob;
	float *class_prob [CLASS_CNT];
}THE_CLASS;

typedef struct the_box
{
	unsigned float x;
	unsigned float y;
	unsigned float w;
	unsigned float h;
	unsigned float con;
	float score;
	THE_CLASS *candidate;

}THE_BOX;

typedef struct hash_chain
{
	list<THE_BOX> map[CLASS_CNT];
}HASH_CHAIN;

typedef struct raw_loc_layout
{
	float x;
	float y;
	float w;
	float h;
}RAW_LOC_LAYOUT;

typedef struct raw_data_layout
{
	float class_prob[PREDICT_CUBE_WIDTH][PREDICT_CUBE_HEIGHT][CLASS_CNT];
	float con[PREDICT_CUBE_WIDTH][PREDICT_CUBE_HEIGHT][PREDICT_NUM_OF_BOX];
	RAW_LOC_LAYOUT loc[PREDICT_CUBE_WIDTH][PREDICT_CUBE_HEIGHT][PREDICT_NUM_OF_BOX];
}RAW_DATA_LAYOUT;

typedef struct the_predicted_data
{
	RAW_DATA_LAYOUT *data;
	unsigned int w;
	unsigned int h;
	unsigned int d;
}THE_PREDICTED_DATA;

typedef struct the_weight
{
	float *weight;
	unsigned int len;
	unsigned int layer;
}THE_WEIGHT;

typedef struct image_data
{
	unsigned short *data;
	unsigned int len;
	unsigned int width;
	unsigned int height;
	unsigned int channel;
}IMAGE_DATA;

typedef struct infer_controller
{
	IMAGE_DATA *input;
	std::list<THE_WEIGHT> *weight_list;
	unsigned int cnt_weight;
}INFER_CONTROLLER;



#endif /* SRC_SRC_F2D_OBJECT_DECTOR_HPP_ */
