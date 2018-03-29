/*
 * object_int.h
 *
 *  Created on: Feb 21, 2018
 *      Author: lucas
 */

#ifndef SRC_SRC_F2D_OBJECT_INT_H_
#define SRC_SRC_F2D_OBJECT_INT_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
	PRE_BUILD_CUBE,
	YOLO_SW_INFERENCE
}INFER_TYPE;


int object_detection(unsigned short *frm_data_in, unsigned short *frm_data_out,
		 int height, int width, int stride, INFER_TYPE type);

#define INPUT_RAW_PIXEL	(768)
#define INPUT_COL_PIXEL	(576)
//#define INPUT_RAW_PIXEL	(416)
//#define INPUT_COL_PIXEL	(416)

#ifdef __cplusplus
}
#endif
#endif /* SRC_SRC_F2D_OBJECT_INT_H_ */
