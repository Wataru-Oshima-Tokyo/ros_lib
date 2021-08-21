#ifndef _ROS_slam_planner_HighCmd_h
#define _ROS_slam_planner_HighCmd_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "slam_planner/LED.h"

namespace slam_planner
{

  class HighCmd : public ros::Msg
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
      typedef uint8_t _mode_type;
      _mode_type mode;
      typedef float _forwardSpeed_type;
      _forwardSpeed_type forwardSpeed;
      typedef float _sideSpeed_type;
      _sideSpeed_type sideSpeed;
      typedef float _rotateSpeed_type;
      _rotateSpeed_type rotateSpeed;
      typedef float _bodyHeight_type;
      _bodyHeight_type bodyHeight;
      typedef float _footRaiseHeight_type;
      _footRaiseHeight_type footRaiseHeight;
      typedef float _yaw_type;
      _yaw_type yaw;
      typedef float _pitch_type;
      _pitch_type pitch;
      typedef float _roll_type;
      _roll_type roll;
      slam_planner::LED led[4];
      uint8_t wirelessRemote[40];
      uint8_t AppRemote[40];
      typedef uint32_t _reserve_type;
      _reserve_type reserve;
      typedef int32_t _crc_type;
      _crc_type crc;

    HighCmd():
      levelFlag(0),
      commVersion(0),
      robotID(0),
      SN(0),
      bandWidth(0),
      mode(0),
      forwardSpeed(0),
      sideSpeed(0),
      rotateSpeed(0),
      bodyHeight(0),
      footRaiseHeight(0),
      yaw(0),
      pitch(0),
      roll(0),
      led(),
      wirelessRemote(),
      AppRemote(),
      reserve(0),
      crc(0)
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
      *(outbuffer + offset + 0) = (this->mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->mode);
      union {
        float real;
        uint32_t base;
      } u_forwardSpeed;
      u_forwardSpeed.real = this->forwardSpeed;
      *(outbuffer + offset + 0) = (u_forwardSpeed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_forwardSpeed.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_forwardSpeed.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_forwardSpeed.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->forwardSpeed);
      union {
        float real;
        uint32_t base;
      } u_sideSpeed;
      u_sideSpeed.real = this->sideSpeed;
      *(outbuffer + offset + 0) = (u_sideSpeed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_sideSpeed.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_sideSpeed.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_sideSpeed.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sideSpeed);
      union {
        float real;
        uint32_t base;
      } u_rotateSpeed;
      u_rotateSpeed.real = this->rotateSpeed;
      *(outbuffer + offset + 0) = (u_rotateSpeed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rotateSpeed.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_rotateSpeed.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_rotateSpeed.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->rotateSpeed);
      union {
        float real;
        uint32_t base;
      } u_bodyHeight;
      u_bodyHeight.real = this->bodyHeight;
      *(outbuffer + offset + 0) = (u_bodyHeight.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_bodyHeight.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_bodyHeight.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_bodyHeight.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->bodyHeight);
      union {
        float real;
        uint32_t base;
      } u_footRaiseHeight;
      u_footRaiseHeight.real = this->footRaiseHeight;
      *(outbuffer + offset + 0) = (u_footRaiseHeight.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_footRaiseHeight.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_footRaiseHeight.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_footRaiseHeight.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->footRaiseHeight);
      union {
        float real;
        uint32_t base;
      } u_yaw;
      u_yaw.real = this->yaw;
      *(outbuffer + offset + 0) = (u_yaw.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_yaw.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_yaw.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_yaw.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->yaw);
      union {
        float real;
        uint32_t base;
      } u_pitch;
      u_pitch.real = this->pitch;
      *(outbuffer + offset + 0) = (u_pitch.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pitch.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pitch.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pitch.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pitch);
      union {
        float real;
        uint32_t base;
      } u_roll;
      u_roll.real = this->roll;
      *(outbuffer + offset + 0) = (u_roll.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_roll.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_roll.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_roll.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->roll);
      for( uint32_t i = 0; i < 4; i++){
      offset += this->led[i].serialize(outbuffer + offset);
      }
      for( uint32_t i = 0; i < 40; i++){
      *(outbuffer + offset + 0) = (this->wirelessRemote[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->wirelessRemote[i]);
      }
      for( uint32_t i = 0; i < 40; i++){
      *(outbuffer + offset + 0) = (this->AppRemote[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->AppRemote[i]);
      }
      *(outbuffer + offset + 0) = (this->reserve >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->reserve >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->reserve >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->reserve >> (8 * 3)) & 0xFF;
      offset += sizeof(this->reserve);
      union {
        int32_t real;
        uint32_t base;
      } u_crc;
      u_crc.real = this->crc;
      *(outbuffer + offset + 0) = (u_crc.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_crc.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_crc.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_crc.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->crc);
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
      this->mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->mode);
      union {
        float real;
        uint32_t base;
      } u_forwardSpeed;
      u_forwardSpeed.base = 0;
      u_forwardSpeed.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_forwardSpeed.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_forwardSpeed.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_forwardSpeed.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->forwardSpeed = u_forwardSpeed.real;
      offset += sizeof(this->forwardSpeed);
      union {
        float real;
        uint32_t base;
      } u_sideSpeed;
      u_sideSpeed.base = 0;
      u_sideSpeed.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_sideSpeed.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_sideSpeed.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_sideSpeed.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->sideSpeed = u_sideSpeed.real;
      offset += sizeof(this->sideSpeed);
      union {
        float real;
        uint32_t base;
      } u_rotateSpeed;
      u_rotateSpeed.base = 0;
      u_rotateSpeed.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rotateSpeed.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_rotateSpeed.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_rotateSpeed.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->rotateSpeed = u_rotateSpeed.real;
      offset += sizeof(this->rotateSpeed);
      union {
        float real;
        uint32_t base;
      } u_bodyHeight;
      u_bodyHeight.base = 0;
      u_bodyHeight.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_bodyHeight.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_bodyHeight.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_bodyHeight.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->bodyHeight = u_bodyHeight.real;
      offset += sizeof(this->bodyHeight);
      union {
        float real;
        uint32_t base;
      } u_footRaiseHeight;
      u_footRaiseHeight.base = 0;
      u_footRaiseHeight.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_footRaiseHeight.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_footRaiseHeight.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_footRaiseHeight.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->footRaiseHeight = u_footRaiseHeight.real;
      offset += sizeof(this->footRaiseHeight);
      union {
        float real;
        uint32_t base;
      } u_yaw;
      u_yaw.base = 0;
      u_yaw.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_yaw.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_yaw.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_yaw.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->yaw = u_yaw.real;
      offset += sizeof(this->yaw);
      union {
        float real;
        uint32_t base;
      } u_pitch;
      u_pitch.base = 0;
      u_pitch.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pitch.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pitch.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pitch.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pitch = u_pitch.real;
      offset += sizeof(this->pitch);
      union {
        float real;
        uint32_t base;
      } u_roll;
      u_roll.base = 0;
      u_roll.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_roll.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_roll.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_roll.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->roll = u_roll.real;
      offset += sizeof(this->roll);
      for( uint32_t i = 0; i < 4; i++){
      offset += this->led[i].deserialize(inbuffer + offset);
      }
      for( uint32_t i = 0; i < 40; i++){
      this->wirelessRemote[i] =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->wirelessRemote[i]);
      }
      for( uint32_t i = 0; i < 40; i++){
      this->AppRemote[i] =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->AppRemote[i]);
      }
      this->reserve =  ((uint32_t) (*(inbuffer + offset)));
      this->reserve |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->reserve |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->reserve |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->reserve);
      union {
        int32_t real;
        uint32_t base;
      } u_crc;
      u_crc.base = 0;
      u_crc.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_crc.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_crc.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_crc.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->crc = u_crc.real;
      offset += sizeof(this->crc);
     return offset;
    }

    const char * getType(){ return "slam_planner/HighCmd"; };
    const char * getMD5(){ return "1a655499a3f64905db59ceed65ca774a"; };

  };

}
#endif
