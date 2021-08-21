#ifndef _ROS_slam_planner_MotorCmd_h
#define _ROS_slam_planner_MotorCmd_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace slam_planner
{

  class MotorCmd : public ros::Msg
  {
    public:
      typedef uint8_t _mode_type;
      _mode_type mode;
      typedef float _q_type;
      _q_type q;
      typedef float _dq_type;
      _dq_type dq;
      typedef float _tau_type;
      _tau_type tau;
      typedef float _Kp_type;
      _Kp_type Kp;
      typedef float _Kd_type;
      _Kd_type Kd;
      uint32_t reserve[3];

    MotorCmd():
      mode(0),
      q(0),
      dq(0),
      tau(0),
      Kp(0),
      Kd(0),
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
      } u_tau;
      u_tau.real = this->tau;
      *(outbuffer + offset + 0) = (u_tau.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_tau.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_tau.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_tau.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tau);
      union {
        float real;
        uint32_t base;
      } u_Kp;
      u_Kp.real = this->Kp;
      *(outbuffer + offset + 0) = (u_Kp.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_Kp.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_Kp.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_Kp.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->Kp);
      union {
        float real;
        uint32_t base;
      } u_Kd;
      u_Kd.real = this->Kd;
      *(outbuffer + offset + 0) = (u_Kd.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_Kd.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_Kd.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_Kd.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->Kd);
      for( uint32_t i = 0; i < 3; i++){
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
      } u_tau;
      u_tau.base = 0;
      u_tau.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_tau.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_tau.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_tau.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->tau = u_tau.real;
      offset += sizeof(this->tau);
      union {
        float real;
        uint32_t base;
      } u_Kp;
      u_Kp.base = 0;
      u_Kp.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_Kp.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_Kp.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_Kp.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->Kp = u_Kp.real;
      offset += sizeof(this->Kp);
      union {
        float real;
        uint32_t base;
      } u_Kd;
      u_Kd.base = 0;
      u_Kd.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_Kd.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_Kd.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_Kd.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->Kd = u_Kd.real;
      offset += sizeof(this->Kd);
      for( uint32_t i = 0; i < 3; i++){
      this->reserve[i] =  ((uint32_t) (*(inbuffer + offset)));
      this->reserve[i] |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->reserve[i] |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->reserve[i] |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->reserve[i]);
      }
     return offset;
    }

    const char * getType(){ return "slam_planner/MotorCmd"; };
    const char * getMD5(){ return "bbb3b7d91319c3a1b99055f0149ba221"; };

  };

}
#endif
