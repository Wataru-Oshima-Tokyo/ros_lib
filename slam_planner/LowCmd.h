#ifndef _ROS_slam_planner_LowCmd_h
#define _ROS_slam_planner_LowCmd_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "slam_planner/MotorCmd.h"
#include "slam_planner/LED.h"
#include "slam_planner/Cartesian.h"

namespace slam_planner
{

  class LowCmd : public ros::Msg
  {
    public:
      typedef uint8_t _levelFlag_type;
      _levelFlag_type levelFlag;
      typedef uint16_t _commVersion_type;
      _commVersion_type commVersion;
      typedef uint16_t _robotID_type;
      _robotID_type robotID;
      typedef uint32_t _SN_type;
      _SN_type SN;
      typedef uint8_t _bandWidth_type;
      _bandWidth_type bandWidth;
      slam_planner::MotorCmd motorCmd[20];
      slam_planner::LED led[4];
      uint8_t wirelessRemote[40];
      typedef uint32_t _reserve_type;
      _reserve_type reserve;
      typedef uint32_t _crc_type;
      _crc_type crc;
      slam_planner::Cartesian ff[4];

    LowCmd():
      levelFlag(0),
      commVersion(0),
      robotID(0),
      SN(0),
      bandWidth(0),
      motorCmd(),
      led(),
      wirelessRemote(),
      reserve(0),
      crc(0),
      ff()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->levelFlag >> (8 * 0)) & 0xFF;
      offset += sizeof(this->levelFlag);
      *(outbuffer + offset + 0) = (this->commVersion >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->commVersion >> (8 * 1)) & 0xFF;
      offset += sizeof(this->commVersion);
      *(outbuffer + offset + 0) = (this->robotID >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->robotID >> (8 * 1)) & 0xFF;
      offset += sizeof(this->robotID);
      *(outbuffer + offset + 0) = (this->SN >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->SN >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->SN >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->SN >> (8 * 3)) & 0xFF;
      offset += sizeof(this->SN);
      *(outbuffer + offset + 0) = (this->bandWidth >> (8 * 0)) & 0xFF;
      offset += sizeof(this->bandWidth);
      for( uint32_t i = 0; i < 20; i++){
      offset += this->motorCmd[i].serialize(outbuffer + offset);
      }
      for( uint32_t i = 0; i < 4; i++){
      offset += this->led[i].serialize(outbuffer + offset);
      }
      for( uint32_t i = 0; i < 40; i++){
      *(outbuffer + offset + 0) = (this->wirelessRemote[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->wirelessRemote[i]);
      }
      *(outbuffer + offset + 0) = (this->reserve >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->reserve >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->reserve >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->reserve >> (8 * 3)) & 0xFF;
      offset += sizeof(this->reserve);
      *(outbuffer + offset + 0) = (this->crc >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->crc >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->crc >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->crc >> (8 * 3)) & 0xFF;
      offset += sizeof(this->crc);
      for( uint32_t i = 0; i < 4; i++){
      offset += this->ff[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->levelFlag =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->levelFlag);
      this->commVersion =  ((uint16_t) (*(inbuffer + offset)));
      this->commVersion |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->commVersion);
      this->robotID =  ((uint16_t) (*(inbuffer + offset)));
      this->robotID |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->robotID);
      this->SN =  ((uint32_t) (*(inbuffer + offset)));
      this->SN |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->SN |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->SN |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->SN);
      this->bandWidth =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->bandWidth);
      for( uint32_t i = 0; i < 20; i++){
      offset += this->motorCmd[i].deserialize(inbuffer + offset);
      }
      for( uint32_t i = 0; i < 4; i++){
      offset += this->led[i].deserialize(inbuffer + offset);
      }
      for( uint32_t i = 0; i < 40; i++){
      this->wirelessRemote[i] =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->wirelessRemote[i]);
      }
      this->reserve =  ((uint32_t) (*(inbuffer + offset)));
      this->reserve |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->reserve |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->reserve |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->reserve);
      this->crc =  ((uint32_t) (*(inbuffer + offset)));
      this->crc |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->crc |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->crc |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->crc);
      for( uint32_t i = 0; i < 4; i++){
      offset += this->ff[i].deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "slam_planner/LowCmd"; };
    const char * getMD5(){ return "357432b2562edd0a8e89b9c9f5fc4821"; };

  };

}
#endif
