#ifndef TC_IOT_DEVICE_LOGIC_H
#define TC_IOT_DEVICE_LOGIC_H

#include "tc_iot_inc.h"

#define PARA_STR_LEN		(512)

/* ����ģ�屾�ش洢�ṹ���� local data struct define */
typedef struct _tc_iot_shadow_local_data {
    tc_iot_shadow_bool param_bool;
    tc_iot_shadow_enum param_enum;
    tc_iot_shadow_number param_number;
    char param_string[PARA_STR_LEN];
}tc_iot_shadow_local_data;


/* ����ģ���ֶ� ID �궨��*/
#define TC_IOT_PROP_param_bool 0
#define TC_IOT_PROP_param_enum 1
#define TC_IOT_PROP_param_number 2
#define TC_IOT_PROP_param_string 3

#define TC_IOT_PROPTOTAL 4


/* enum macro definitions */

/* enum macro definition for param_enum */
#define TC_IOT_PROP_param_enum_enum_a 0
#define TC_IOT_PROP_param_enum_enum_b 1
#define TC_IOT_PROP_param_enum_enum_c 2


tc_iot_shadow_client * tc_iot_get_shadow_client(void);
#endif /* end of include guard */
