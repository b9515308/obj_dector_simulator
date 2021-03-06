//============================================================================
// Name        : obj_dector.cpp
// Author      : Lucas
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "object_int.h"
#include "object_dector.hpp"
using namespace cv;
using namespace std;
#include <yolo_lib.h>


int main() {

#if (PURE_POST_PROCESSING)
	object_detection(NULL,NULL,INPUT_COL_PIXEL,INPUT_RAW_PIXEL, NULL, PRE_BUILD_CUBE);
	return 0;
#endif

#if (YOLO_INFERENCE)
	setup_yolo_env(CFG_FILE, WEIGHT_FILE);
	object_detection_video(NULL,NULL,INPUT_COL_PIXEL,INPUT_RAW_PIXEL, NULL,
			YOLO_SW_INFERENCE, "src/resource/dog.jpg");
	object_detection_video(NULL,NULL,INPUT_COL_PIXEL,INPUT_RAW_PIXEL, NULL,
			YOLO_SW_INFERENCE, "src/resource/eagle.jpg");
	return 0;
#endif
}

int sample( int argc, char** argv )
{
  Mat image;
  image = imread( argv[1], 1 );

  if( argc != 2 || !image.data )
    {
      printf( "No image data \n" );
      return -1;
    }

  namedWindow( "Display Image", CV_WINDOW_AUTOSIZE );
  imshow( "Display Image", image );

  waitKey(0);

  return 0;
}

