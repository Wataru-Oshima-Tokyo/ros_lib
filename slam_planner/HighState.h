#ifndef _ROS_slam_planner_HighState_h
#define _ROS_slam_planner_HighState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "slam_planner/IMU.h"
#include "slam_planner/Cartesian.h"

namespace slam_planner
{

  class HighState : public ros::Msg
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
      typedef slam_planner::IMU _imu_type;
      _imu_type imu;
      typedef float _forwardSpeed_type;
      _forwardSpeed_type forwardSpeed;
      typedef float _sideSpeed_type;
      _sideSpeed_type sideSpeed;
      typedef float _rotateSpeed_type;
      _rotateSpeed_type rotateSpeed;
      typedef float _bodyHeight_type;
      _bodyHeight_type bodyHeight;
      typedef float _updownSpeed_type;
      _updownSpeed_type updownSpeed;
      typedef float _forwardPosition_type;
      _forwardPosition_type forwardPosition;
      typedef float _sidePosition_type;
      _sidePosition_type sidePosition;
      slam_planner::Cartesian footPosition2Body[4];
      slam_planner::Cartesian footSpeed2Body[4];
      int16_t footForce[4];
      int16_t footForceEst[4];
      typedef uint32_t _tick_type;
      _tick_type tick;
      uint8_t wirelessRemote[40];
      typedef uint32_t _reserve_type;
      _reserve_type reserve;
      typedef uint32_t _crc_type;
      _crc_type crc;
      slam_planner::Cartesian eeForce[4];
      float jointP[12];

    HighState():
      levelFlag(0),
      commVersion(0),
      robotID(0),
      SN(0),
      bandWidth(0),
      mode(0),
      imu(),
      forwardSpeed(0),
      sideSpeed(0),
      rotateSpeed(0),
      bodyHeight(0),
      updownSpeed(0),
      forwardPosition(0),
      sidePosition(0),
      footPosition2Body(),
      footSpeed2Body(),
      footForce(),
      footForceEst(),
      tick(0),
      wirelessRemote(),
      reserve(0),
      crc(0),
      eeForce(),
      jointP()
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
      offset += this->imu.serialize(outbuffer + offset);
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
      } u_updownSpeed;
      u_updownSpeed.real = this->updownSpeed;
      *(outbuffer + offset + 0) = (u_updownSpeed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_updownSpeed.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_updownSpeed.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_updownSpeed.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->updownSpeed);
      union {
        float real;
        uint32_t base;
      } u_forwardPosition;
      u_forwardPosition.real = this->forwardPosition;
      *(outbuffer + offset + 0) = (u_forwardPosition.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_forwardPosition.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_forwardPosition.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_forwardPosition.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->forwardPosition);
      union {
        float real;
        uint32_t base;
      } u_sidePosition;
      u_sidePosition.real = this->sidePosition;
      *(outbuffer + offset + 0) = (u_sidePosition.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_sidePosition.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_sidePosition.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_sidePosition.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sidePosition);
      for( uint32_t i = 0; i < 4; i++){
      offset += this->footPosition2Body[i].serialize(outbuffer + offset);
      }
      for( uint32_t i = 0; i < 4; i++){
      offset += this->footSpeed2Body[i].serialize(outbuffer + offset);
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
      offset += this->eeForce[i].serialize(outbuffer + offset);
      }
      for( uint32_t i = 0; i < 12; i++){
      union {
        float real;
        uint32_t base;
      } u_jointPi;
      u_jointPi.real = this->jointP[i];
      *(outbuffer + offset + 0) = (u_jointPi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_jointPi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_jointPi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_jointPi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->jointP[i]);
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
      this->mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->mode);
      offset += this->imu.deserialize(inbuffer + offset);
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
      } u_updownSpeed;
      u_updownSpeed.base = 0;
      u_updownSpeed.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_updownSpeed.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_updownSpeed.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_updownSpeed.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->updownSpeed = u_updownSpeed.real;
      offset += sizeof(this->updownSpeed);
      union {
        float real;
        uint32_t base;
      } u_forwardPosition;
      u_forwardPosition.base = 0;
      u_forwardPosition.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_forwardPosition.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_forwardPosition.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_forwardPosition.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->forwardPosition = u_forwardPosition.real;
      offset += sizeof(this->forwardPosition);
      union {
        float real;
        uint32_t base;
      } u_sidePosition;
      u_sidePosition.base = 0;
      u_sidePosition.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_sidePosition.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_sidePosition.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_sidePosition.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->sidePosition = u_sidePosition.real;
      offset += sizeof(this->sidePosition);
      for( uint32_t i = 0; i < 4; i++){
      offset += this->footPosition2Body[i].deserialize(inbuffer + offset);
      }
      for( uint32_t i = 0; i < 4; i++){
      offset += this->footSpeed2Body[i].deserialize(inbuffer + offset);
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
      offset += this->eeForce[i].deserialize(inbuffer + offset);
      }
      for( uint32_t i = 0; i < 12; i++){
      union {
        float real;
        uint32_t base;
      } u_jointPi;
      u_jointPi.base = 0;
      u_jointPi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_jointPi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_jointPi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_jointPi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->jointP[i] = u_jointPi.real;
      offset += sizeof(this->jointP[i]);
      }
     return offset;
    }

    const char * getType(){ return "slam_planner/HighState"; };
    const char * getMD5(){ return "ecc2950a071fd456ed31756d75114627"; };

  };

}
#endif
