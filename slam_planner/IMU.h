#ifndef _ROS_slam_planner_IMU_h
#define _ROS_slam_planner_IMU_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace slam_planner
{

  class IMU : public ros::Msg
  {
    public:
      float quaternion[4];
      float gyroscope[3];
      float accelerometer[3];
      float rpy[3];
      typedef int8_t _temperature_type;
      _temperature_type temperature;

    IMU():
      quaternion(),
      gyroscope(),
      accelerometer(),
      rpy(),
      temperature(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      for( uint32_t i = 0; i < 4; i++){
      union {
        float real;
        uint32_t base;
      } u_quaternioni;
      u_quaternioni.real = this->quaternion[i];
      *(outbuffer + offset + 0) = (u_quaternioni.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_quaternioni.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_quaternioni.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_quaternioni.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->quaternion[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_gyroscopei;
      u_gyroscopei.real = this->gyroscope[i];
      *(outbuffer + offset + 0) = (u_gyroscopei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_gyroscopei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_gyroscopei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_gyroscopei.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->gyroscope[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_accelerometeri;
      u_accelerometeri.real = this->accelerometer[i];
      *(outbuffer + offset + 0) = (u_accelerometeri.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_accelerometeri.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_accelerometeri.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_accelerometeri.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->accelerometer[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_rpyi;
      u_rpyi.real = this->rpy[i];
      *(outbuffer + offset + 0) = (u_rpyi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rpyi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_rpyi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_rpyi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->rpy[i]);
      }
      union {
        int8_t real;
        uint8_t base;
      } u_temperature;
      u_temperature.real = this->temperature;
      *(outbuffer + offset + 0) = (u_temperature.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->temperature);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      for( uint32_t i = 0; i < 4; i++){
      union {
        float real;
        uint32_t base;
      } u_quaternioni;
      u_quaternioni.base = 0;
      u_quaternioni.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_quaternioni.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_quaternioni.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_quaternioni.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->quaternion[i] = u_quaternioni.real;
      offset += sizeof(this->quaternion[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_gyroscopei;
      u_gyroscopei.base = 0;
      u_gyroscopei.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_gyroscopei.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_gyroscopei.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_gyroscopei.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->gyroscope[i] = u_gyroscopei.real;
      offset += sizeof(this->gyroscope[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_accelerometeri;
      u_accelerometeri.base = 0;
      u_accelerometeri.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_accelerometeri.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_accelerometeri.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_accelerometeri.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->accelerometer[i] = u_accelerometeri.real;
      offset += sizeof(this->accelerometer[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_rpyi;
      u_rpyi.base = 0;
      u_rpyi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rpyi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_rpyi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_rpyi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->rpy[i] = u_rpyi.real;
      offset += sizeof(this->rpy[i]);
      }
      union {
        int8_t real;
        uint8_t base;
      } u_temperature;
      u_temperature.base = 0;
      u_temperature.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->temperature = u_temperature.real;
      offset += sizeof(this->temperature);
     return offset;
    }

    const char * getType(){ return "slam_planner/IMU"; };
    const char * getMD5(){ return "c2bcd83820da00fff261b67d6490da58"; };

  };

}
#endif
