#ifndef _ROS_slam_planner_MotorState_h
#define _ROS_slam_planner_MotorState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace slam_planner
{

  class MotorState : public ros::Msg
  {
    public:
      typedef uint8_t _mode_type;
      _mode_type mode;
      typedef float _q_type;
      _q_type q;
      typedef float _dq_type;
      _dq_type dq;
      typedef float _ddq_type;
      _ddq_type ddq;
      typedef float _tauEst_type;
      _tauEst_type tauEst;
      typedef float _q_raw_type;
      _q_raw_type q_raw;
      typedef float _dq_raw_type;
      _dq_raw_type dq_raw;
      typedef float _ddq_raw_type;
      _ddq_raw_type ddq_raw;
      typedef int8_t _temperature_type;
      _temperature_type temperature;
      uint32_t reserve[2];

    MotorState():
      mode(0),
      q(0),
      dq(0),
      ddq(0),
      tauEst(0),
      q_raw(0),
      dq_raw(0),
      ddq_raw(0),
      temperature(0),
      reserve()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->mode);
      union {
        float real;
        uint32_t base;
      } u_q;
      u_q.real = this->q;
      *(outbuffer + offset + 0) = (u_q.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_q.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_q.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_q.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->q);
      union {
        float real;
        uint32_t base;
      } u_dq;
      u_dq.real = this->dq;
      *(outbuffer + offset + 0) = (u_dq.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_dq.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_dq.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_dq.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->dq);
      union {
        float real;
        uint32_t base;
      } u_ddq;
      u_ddq.real = this->ddq;
      *(outbuffer + offset + 0) = (u_ddq.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ddq.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ddq.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ddq.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ddq);
      union {
        float real;
        uint32_t base;
      } u_tauEst;
      u_tauEst.real = this->tauEst;
      *(outbuffer + offset + 0) = (u_tauEst.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_tauEst.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_tauEst.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_tauEst.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tauEst);
      union {
        float real;
        uint32_t base;
      } u_q_raw;
      u_q_raw.real = this->q_raw;
      *(outbuffer + offset + 0) = (u_q_raw.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_q_raw.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_q_raw.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_q_raw.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->q_raw);
      union {
        float real;
        uint32_t base;
      } u_dq_raw;
      u_dq_raw.real = this->dq_raw;
      *(outbuffer + offset + 0) = (u_dq_raw.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_dq_raw.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_dq_raw.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_dq_raw.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->dq_raw);
      union {
        float real;
        uint32_t base;
      } u_ddq_raw;
      u_ddq_raw.real = this->ddq_raw;
      *(outbuffer + offset + 0) = (u_ddq_raw.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ddq_raw.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ddq_raw.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ddq_raw.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ddq_raw);
      union {
        int8_t real;
        uint8_t base;
      } u_temperature;
      u_temperature.real = this->temperature;
      *(outbuffer + offset + 0) = (u_temperature.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->temperature);
      for( uint32_t i = 0; i < 2; i++){
      *(outbuffer + offset + 0) = (this->reserve[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->reserve[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->reserve[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->reserve[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->reserve[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->mode);
      union {
        float real;
        uint32_t base;
      } u_q;
      u_q.base = 0;
      u_q.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_q.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_q.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_q.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->q = u_q.real;
      offset += sizeof(this->q);
      union {
        float real;
        uint32_t base;
      } u_dq;
      u_dq.base = 0;
      u_dq.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_dq.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_dq.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_dq.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->dq = u_dq.real;
      offset += sizeof(this->dq);
      union {
        float real;
        uint32_t base;
      } u_ddq;
      u_ddq.base = 0;
      u_ddq.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ddq.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ddq.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ddq.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->ddq = u_ddq.real;
      offset += sizeof(this->ddq);
      union {
        float real;
        uint32_t base;
      } u_tauEst;
      u_tauEst.base = 0;
      u_tauEst.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_tauEst.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_tauEst.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_tauEst.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->tauEst = u_tauEst.real;
      offset += sizeof(this->tauEst);
      union {
        float real;
        uint32_t base;
      } u_q_raw;
      u_q_raw.base = 0;
      u_q_raw.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_q_raw.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_q_raw.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_q_raw.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->q_raw = u_q_raw.real;
      offset += sizeof(this->q_raw);
      union {
        float real;
        uint32_t base;
      } u_dq_raw;
      u_dq_raw.base = 0;
      u_dq_raw.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_dq_raw.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_dq_raw.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_dq_raw.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->dq_raw = u_dq_raw.real;
      offset += sizeof(this->dq_raw);
      union {
        float real;
        uint32_t base;
      } u_ddq_raw;
      u_ddq_raw.base = 0;
      u_ddq_raw.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ddq_raw.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ddq_raw.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ddq_raw.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->ddq_raw = u_ddq_raw.real;
      offset += sizeof(this->ddq_raw);
      union {
        int8_t real;
        uint8_t base;
      } u_temperature;
      u_temperature.base = 0;
      u_temperature.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->temperature = u_temperature.real;
      offset += sizeof(this->temperature);
      for( uint32_t i = 0; i < 2; i++){
      this->reserve[i] =  ((uint32_t) (*(inbuffer + offset)));
      this->reserve[i] |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->reserve[i] |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->reserve[i] |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->reserve[i]);
      }
     return offset;
    }

    const char * getType(){ return "slam_planner/MotorState"; };
    const char * getMD5(){ return "94c55ee3b7852be2bd437b20ce12a254"; };

  };

}
#endif
