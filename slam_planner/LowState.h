#ifndef _ROS_slam_planner_LowState_h
#define _ROS_slam_planner_LowState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "slam_planner/IMU.h"
#include "slam_planner/MotorState.h"
#include "slam_planner/Cartesian.h"

namespace slam_planner
{

  class LowState : public ros::Msg
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
      typedef slam_planner::IMU _imu_type;
      _imu_type imu;
      slam_planner::MotorState motorState[20];
      int16_t footForce[4];
      int16_t footForceEst[4];
      typedef uint32_t _tick_type;
      _tick_type tick;
      uint8_t wirelessRemote[40];
      typedef uint32_t _reserve_type;
      _reserve_type reserve;
      typedef uint32_t _crc_type;
      _crc_type crc;
      slam_planner::Cartesian eeForceRaw[4];
      slam_planner::Cartesian eeForce[4];
      typedef slam_planner::Cartesian _position_type;
      _position_type position;
      typedef slam_planner::Cartesian _velocity_type;
      _velocity_type velocity;
      typedef slam_planner::Cartesian _velocity_w_type;
      _velocity_w_type velocity_w;

    LowState():
      levelFlag(0),
      commVersion(0),
      robotID(0),
      SN(0),
      bandWidth(0),
      imu(),
      motorState(),
      footForce(),
      footForceEst(),
      tick(0),
      wirelessRemote(),
      reserve(0),
      crc(0),
      eeForceRaw(),
      eeForce(),
      position(),
      velocity(),
      velocity_w()
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
      offset += this->imu.serialize(outbuffer + offset);
      for( uint32_t i = 0; i < 20; i++){
      offset += this->motorState[i].serialize(outbuffer + offset);
      }
      for( uint32_t i = 0; i < 4; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_footForcei;
      u_footForcei.real = this->footForce[i];
      *(outbuffer + offset + 0) = (u_footForcei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_footForcei.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->footForce[i]);
      }
      for( uint32_t i = 0; i < 4; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_footForceEsti;
      u_footForceEsti.real = this->footForceEst[i];
      *(outbuffer + offset + 0) = (u_footForceEsti.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_footForceEsti.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->footForceEst[i]);
      }
      *(outbuffer + offset + 0) = (this->tick >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->tick >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->tick >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->tick >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tick);
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
      offset += this->eeForceRaw[i].serialize(outbuffer + offset);
      }
      for( uint32_t i = 0; i < 4; i++){
      offset += this->eeForce[i].serialize(outbuffer + offset);
      }
      offset += this->position.serialize(outbuffer + offset);
      offset += this->velocity.serialize(outbuffer + offset);
      offset += this->velocity_w.serialize(outbuffer + offset);
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
      offset += this->imu.deserialize(inbuffer + offset);
      for( uint32_t i = 0; i < 20; i++){
      offset += this->motorState[i].deserialize(inbuffer + offset);
      }
      for( uint32_t i = 0; i < 4; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_footForcei;
      u_footForcei.base = 0;
      u_footForcei.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_footForcei.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->footForce[i] = u_footForcei.real;
      offset += sizeof(this->footForce[i]);
      }
      for( uint32_t i = 0; i < 4; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_footForceEsti;
      u_footForceEsti.base = 0;
      u_footForceEsti.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_footForceEsti.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->footForceEst[i] = u_footForceEsti.real;
      offset += sizeof(this->footForceEst[i]);
      }
      this->tick =  ((uint32_t) (*(inbuffer + offset)));
      this->tick |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->tick |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->tick |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->tick);
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
      offset += this->eeForceRaw[i].deserialize(inbuffer + offset);
      }
      for( uint32_t i = 0; i < 4; i++){
      offset += this->eeForce[i].deserialize(inbuffer + offset);
      }
      offset += this->position.deserialize(inbuffer + offset);
      offset += this->velocity.deserialize(inbuffer + offset);
      offset += this->velocity_w.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "slam_planner/LowState"; };
    const char * getMD5(){ return "d739b5f213dd3e0dc70a1630cf024e14"; };

  };

}
#endif
