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

int object_detection(unsigned short *frm_data_in, unsigned short *frm_data_out,
		 int height, int width, int stride);

#ifdef __cplusplus
}
#endif
#endif /* SRC_SRC_F2D_OBJECT_INT_H_ */
