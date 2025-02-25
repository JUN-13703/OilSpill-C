/*
 *  Seek thermal interface
 *  Author: Maarten Vandersteegen
 */

#ifndef SEEK_THERMAL_H
#define SEEK_THERMAL_H

#include <opencv2/opencv.hpp>
#include "SeekCam.h"

#define THERMAL_WIDTH       206
#define THERMAL_HEIGHT      156
#define THERMAL_RAW_WIDTH   208
#define THERMAL_RAW_HEIGHT  156
#define THERMAL_RAW_SIZE    (THERMAL_RAW_WIDTH * THERMAL_RAW_HEIGHT)

namespace LibSeek {

class SeekThermal: public SeekCam
{
public:
    SeekThermal();
    /*
     *  ffc_filename:
     *      Filename for additional flat field calibration and corner
     *      gradient elimination. If provided and found, the image will
     *      be subtracted from each retrieved frame. If not, no additional
     *      flat field calibration will be applied
     */
    SeekThermal(std::string ffc_filename);

    virtual bool init_cam();
    virtual int frame_id();
    virtual int frame_counter();

private:
    uint16_t m_buffer[THERMAL_RAW_SIZE];

};

} /* LibSeek */

#endif /* SEEK_THERMAL_H */
