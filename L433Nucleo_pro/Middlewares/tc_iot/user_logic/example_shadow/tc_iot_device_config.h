#ifndef TC_IOT_DEVICE_CONFIG_H
#define TC_IOT_DEVICE_CONFIG_H

/* �豸�����ȡ secret �ӿڣ���ַ��ʽΪ��<������ʶ>.auth-device-iot.tencentcloudapi.com/secret */
/* Token�ӿڣ���ַ��ʽΪ��<������ʶ>.auth-device-iot.tencentcloudapi.com/token */
/* ������ʶ��
    ���ݻ���=gz
    ��������=bj
    ...
*/
#ifdef ENABLE_TLS
#define TC_IOT_CONFIG_AUTH_API_URL "https://gz.auth-device-iot.tencentcloudapi.com/token"
#define TC_IOT_CONFIG_ACTIVE_API_URL "https://gz.auth-device-iot.tencentcloudapi.com/secret"
#else
#define TC_IOT_CONFIG_AUTH_API_URL "http://gz.auth-device-iot.tencentcloudapi.com/token"
#define TC_IOT_CONFIG_ACTIVE_API_URL "http://gz.auth-device-iot.tencentcloudapi.com/secret"
#endif

#define TC_IOT_CONFIG_ACTIVE_API_URL_DEBUG   "http://gz.auth.iot.cloud.tencent.com/secret"
#define TC_IOT_CONFIG_AUTH_API_URL_DEBUG	 "http://gz.auth.iot.cloud.tencent.com/token"

/************************************************************************/
/**********************************������********************************/

#ifdef ENABLE_TLS
/* �Ƿ�����TLS����MQTT����*/
#define TC_IOT_CONFIG_USE_TLS 1
#else
#define TC_IOT_CONFIG_USE_TLS 0
#endif

#if TC_IOT_CONFIG_USE_TLS
/* MQ�����TLS�˿�һ��Ϊ8883*/
#define TC_IOT_CONFIG_SERVER_PORT 8883
#else
/* MQ�����Ĭ�϶˿�һ��Ϊ1883*/
#define TC_IOT_CONFIG_SERVER_PORT 1883
#endif


#define ENABLE_MQTT

/* ����������Ҫ���ڹ���������Ʒ���豸��Ȼ���ȡ�����Ϣ����*/
/* MQ�����ַ�������ڲ�Ʒ��������Ϣҳ��->��mqtt���ӵ�ַ��λ���ҵ���*/
#define TC_IOT_CONFIG_SERVER_HOST "mqtt-m1j432sw.ap-guangzhou.mqtt.tencentcloudmq.com"  
 




/*#define TC_IOT_CONFIG_SERVER_HOST "localhost"*/
/* ��Ʒid�������ڲ�Ʒ��������Ϣҳ��->����Ʒid��λ���ҵ�*/
#define TC_IOT_CONFIG_DEVICE_PRODUCT_ID "iot-eib00wp2"
/* ��Ʒid�������ڲ�Ʒ��������Ϣҳ��->����Ʒkey��λ���ҵ�*/
#define TC_IOT_CONFIG_DEVICE_PRODUCT_KEY "mqtt-m1j432sw"

/* �豸��Կ�������ڲ�Ʒ���豸����->���豸֤�顱->��Device Secret��λ���ҵ�*/
#define TC_IOT_CONFIG_DEVICE_SECRET "3903d58467e1397c3068012a0cdff4b9"

/* �豸���ƣ������ڲ�Ʒ���豸����->���豸���ơ�λ���ҵ�*/
#define TC_IOT_CONFIG_DEVICE_NAME "collector_1_1"

/* client id ����������ɣ������ʽΪ��ProductKey@DeviceName�� */
#define TC_IOT_CONFIG_DEVICE_CLIENT_ID TC_IOT_CONFIG_DEVICE_PRODUCT_KEY "@" TC_IOT_CONFIG_DEVICE_NAME

/************************************************************************/
/**********************************ѡ����********************************/
/* ����username��password��*/
/* 1)�����ͨ��TC_IOT_CONFIG_AUTH_API_URL�ӿڣ���̬��ȡ�ģ��������������ɲ�����д*/
/* 2)�����Ԥ������õĹ̶�username��password�����԰ѻ�ȡ���Ĺ̶�������д������λ��*/
#if 1==1
/* Token ģʽ */
#define TC_IOT_CONFIG_DEVICE_USER_NAME ""
#define TC_IOT_CONFIG_DEVICE_PASSWORD ""
#else
/* ֱ��ģʽ */
#define TC_IOT_CONFIG_DEVICE_USER_NAME ""
#define TC_IOT_CONFIG_DEVICE_PASSWORD ""
#endif
/************************************************************************/


/* connect��publish��subscribe��unsubscribe */
/* ������ִ�г�ʱʱ������λ�Ǻ���*/
#define TC_IOT_CONFIG_COMMAND_TIMEOUT_MS  30000
/* TLS ����ִ�г�ʱʱ������λ�Ǻ���*/
#define TC_IOT_CONFIG_TLS_HANDSHAKE_TIMEOUT_MS  10000
/* keep alive ���ʱ������λ����*/
#define TC_IOT_CONFIG_KEEP_ALIVE_INTERVAL_SEC  120
/* ������ϻ����˳�ʱ���Ƿ��Զ�����*/
#define TC_IOT_CONFIG_AUTO_RECONNECT 1

#define TC_IOT_CONFIG_CLEAN_SESSION 1


/* shadow������Ϣtopic��mq����˵���Ӧ���������ͣ�*/
/* ���ᷢ���� "shadow/get/<product id>/<device name>" ���topic*/
/* �ͻ���ֻ��Ҫ�������topic����*/
#define TC_IOT_SUB_TOPIC_PREFIX "shadow/get/"
#define TC_IOT_SUB_TOPIC_FMT TC_IOT_SUB_TOPIC_PREFIX "%s/%s"
#define TC_IOT_SUB_TOPIC_DEF TC_IOT_SUB_TOPIC_PREFIX TC_IOT_CONFIG_DEVICE_PRODUCT_ID "/" TC_IOT_CONFIG_DEVICE_NAME
/* shadow������Ϣtopic���ͻ����������˵���Ϣ�����������topic����*/
/* topic��ʽ"shadow/update/<product id>/<device name>"*/
#define TC_IOT_PUB_TOPIC_PREFIX "shadow/update/"
#define TC_IOT_PUB_TOPIC_FMT TC_IOT_PUB_TOPIC_PREFIX "%s/%s"
#define TC_IOT_PUB_TOPIC_DEF TC_IOT_PUB_TOPIC_PREFIX TC_IOT_CONFIG_DEVICE_PRODUCT_ID "/" TC_IOT_CONFIG_DEVICE_NAME

/* tls �������*/
/* ��֤��·��*/
#define TC_IOT_CONFIG_ROOT_CA NULL
/* �ͻ���֤��·��*/
#define TC_IOT_CONFIG_CLIENT_CRT NULL
/* �ͻ���˽Կ·��*/
#define TC_IOT_CONFIG_CLIENT_KEY NULL

#define TC_IOT_TROUBLE_SHOOTING_URL "https://git.io/vN9le"

#endif /* end of include guard */
