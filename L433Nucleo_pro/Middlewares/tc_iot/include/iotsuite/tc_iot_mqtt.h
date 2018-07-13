#ifndef TC_IOT_MQTT_H
#define TC_IOT_MQTT_H

#include "tc_iot_inc.h"


/**
 * @brief ��Ϣ ID ���ȡֵ��MQTT Э���޶� [Packet
 * Identifier](http://docs.oasis-open.org/mqtt/mqtt/v3.1.1/os/mqtt-v3.1.1-os.html#_Toc398718025) ֻ��
 * 2 �ֽڣ��뱣�� 65535 ���ֵ��Ҫ�Ķ� 
 */
#define TC_IOT_MAX_PACKET_ID 65535

/* ������Ҫ�㹻��ţ�
 * 1) 2^64 ��ʮ��������ֵ��
 * 2) true or false �����ַ�����
 * 3) method �ֶ�����: get, update, control,reply */
#define TC_IOT_MAX_FIELD_LEN  22


/**
 * @brief �ͻ�������� Topic ���������ҵ�񳡾���
 * ʵ�ʶ��ĵ���� Topic ������������á�
 */
#define TC_IOT_MAX_MESSAGE_HANDLERS 5



/**
 * @brief ��Ϣ���Ļذ���SUBACK ������
 * [returnCode](http://docs.oasis-open.org/mqtt/mqtt/v3.1.1/os/mqtt-v3.1.1-os.html#_Toc398718071)
 *
 */
typedef enum _tc_iot_mqtt_qos_e {
    TC_IOT_QOS0 = 0,  /**< QOS0*/
    TC_IOT_QOS1 = 1, /**< QOS1*/
    TC_IOT_QOS2 = 2, /**< QOS2*/
    TC_IOT_SUBFAIL = 0x80, /**< ����ʧ�ܣ��п��� Topic �����ڣ�������Ȩ�޵�*/
} tc_iot_mqtt_qos_e;


/**
 * @brief MQTT ��������ذ���CONNACK ������
 * [returnCode](http://docs.oasis-open.org/mqtt/mqtt/v3.1.1/os/mqtt-v3.1.1-os.html#_Toc398718035)
 */
typedef enum _tc_iot_mqtt_conn_ack_e {
    TC_IOT_CONN_SUCCESS = 0, /**< ���ӳɹ�*/
    TC_IOT_CONN_PROTOCOL_UNACCEPTABLE = 1, /**< ����ʧ�ܣ���֧�������Э��汾*/
    TC_IOT_CONN_CLIENT_ID_INVALID = 2, /**< ����ʧ�ܣ�Client Id �ж��Ƿ�*/
    TC_IOT_CONN_SERVICE_UNAVAILABLE = 3,  /**< ����ʧ�ܣ���˷��񲻿���*/
    TC_IOT_CONN_BAD_USER_OR_PASSWORD = 4,  /**< ����ʧ�ܣ��û���������У�鲻ͨ��*/
    TC_IOT_CONN_NOT_AUTHORIZED = 5,  /**< ����ʧ�ܣ��û�����δ��Ȩ*/
} tc_iot_mqtt_conn_ack_e;

/**
 * @brief MQTT Publis������Ϣ��ͷ����������(��Э��ͷ)���ؼ�����˵��
 */
typedef struct _tc_iot_mqtt_message {
    int qos; /**< QOS����*/
    unsigned char retained;  /**< �Ƿ�Ҫ�����˳־ñ������Ϣ*/
    unsigned char dup; /**< �Ƿ��ط���Ϣ*/
    unsigned short id; /**< ��Ϣ ID*/
    void* payload; /**< ��Ϣ��������*/
    size_t payloadlen; /**< ��Ϣ�������ݳ���*/
} tc_iot_mqtt_message;


/**
 * @brief ���յ��Ķ�����Ϣ
 */
typedef struct _tc_iot_message_data {
    tc_iot_mqtt_message* message; /**< ��Ϣ����*/
    MQTTString* topicName; /**< ���� Topic*/
    void * mqtt_client;
    void * context;
} tc_iot_message_data;


/**
 * @brief ����������Ӧ��CONNACK �ذ�����
 */
typedef struct _tc_iot_mqtt_connack_data {
    unsigned char rc;  /**< @link tc_iot_mqtt_conn_ack_e ������ @endlink*/
    unsigned char sessionPresent; /**< [Session Present](http://docs.oasis-open.org/mqtt/mqtt/v3.1.1/os/mqtt-v3.1.1-os.html#_Toc398718035)*/
} tc_iot_mqtt_connack_data;


/**
 * @brief ������Ϣ���������ݡ�
 */
typedef struct _tc_iot_mqtt_suback_data {
    tc_iot_mqtt_qos_e grantedQoS; /**< ��Ϣ QOS �ȼ�*/
} tc_iot_mqtt_suback_data;

typedef void (*message_handler)(tc_iot_message_data*);


/**
 * @brief �ͻ�������״̬
 */
typedef enum _tc_iot_mqtt_client_state_e {
    CLIENT_INVALID, /**< �Ƿ�״̬������δ��ʼ��*/
    CLIENT_INTIALIAZED, /**< �ѳ�ʼ�������������Ϣ������*/
    CLIENT_NETWORK_READY, /**< �����(TCP �� TLS)��������ɣ��ɽ��� MQTT CONN ����*/
    CLIENT_CONNECTED, /**< Ӧ�ò�������ɣ�MQTT CONN/CONNACK �ɹ�*/
} tc_iot_mqtt_client_state_e;

typedef struct _tc_iot_mqtt_client tc_iot_mqtt_client;

/**
 * @brief  ���ӶϿ��ص�����ԭ�ͣ��û���ͨ��ʵ�ָú�����
 * ��ע�ᵽ MQTT client�ϣ�ʵ�ֶ�����״̬�ļ�أ��Ա�
 * �����ӶϿ�ʱ���õ�֪ͨ������Ӧ����
 *
 * @param p_mqtt_client MQTT client ����
 *
 */
typedef void (*disconnectHandler)(tc_iot_mqtt_client*, void*);



/**
 * @brief MQTT client ����ṹ������ MQTT �ͻ���������á�����״̬��
 * �ص�����ʱ��Ҫ���շ�����������Ϣ��
 */
struct _tc_iot_mqtt_client {
    unsigned int command_timeout_ms;  /**< MQTT ָ�ʱ���ã����ݿͻ����豸����������ʵ������������к������á�
                                        1) ���ڿͻ������粻�ȶ�����£��ʵ��ӳ�ʱ�ӣ����Ա�����Ч���������ԣ�
                                        2) ���ڿͻ��������Ϊ�ȶ�������£��������ý϶̵�ʱ�ӣ�ȷ�������������쳣ʱ��
                                        �ܼ�ʱ����ʱ���Ʒ��֣���ʱ�����ָ�����*/
    size_t buf_size;  /**< ���ͻ�������С���̶�Ϊ TC_IOT_CLIENT_SEND_BUF_SIZE*/
    size_t readbuf_size;  /**< ���ջ�������С���̶�Ϊ TC_IOT_CLIENT_READ_BUF_SIZE*/
    unsigned char buf[TC_IOT_CLIENT_SEND_BUF_SIZE]; /**< ���ͻ�����������ҵ�������ʵ�ʷ��������Ĵ�С��
                                                      �����趨 TC_IOT_CLIENT_READ_BUF_SIZE ��ֵ */
    unsigned char readbuf[TC_IOT_CLIENT_READ_BUF_SIZE];  /**< ���ջ������Ĵ�С�����ݷ�����·�������Ϣ������С��
                                                           �����趨 TC_IOT_CLIENT_READ_BUF_SIZE ��ֵ */
    unsigned int keep_alive_interval;  /**< �ͻ������������������ͼ������λ���� */
    char auto_reconnect; /**< ����⵽��ʱ�������쳣ʱ���Ƿ��Զ����� */
    unsigned int reconnect_timeout_ms; /**< �Զ�������ǰ�ȴ�ʱ��*/
    int clean_session;  /**< [CleanSession](http://docs.oasis-open.org/mqtt/mqtt/v3.1.1/os/mqtt-v3.1.1-os.html#_Toc398718030) ״̬*/
    unsigned int next_packetid;  /**< ��һ�����õ���Ϣ ID*/
    char ping_outstanding; /**< �Ƿ����ڽ������� PING ����*/
    tc_iot_mqtt_client_state_e state; /**< ����״̬*/
    MQTTPacket_connectData connect_options; /**< �������� */

    struct MessageHandlers {
        const char* topicFilter;
        tc_iot_mqtt_qos_e qos;
        message_handler fp;
        void * context;
    } message_handlers[TC_IOT_MAX_MESSAGE_HANDLERS]; /**< ������Ϣ�ص�*/

    message_handler  default_msg_handler; /**< ������ϢĬ�ϻص�*/
    disconnectHandler disconnect_handler; /**< ���ӶϿ�֪ͨ�ص�*/

    tc_iot_network_t ipstack; /**< �������*/
    tc_iot_timer last_sent; /**< ���һ�η�����ʱ���������ж��Ƿ���Ҫ���� keep alive ����*/
    tc_iot_timer last_received; /**< ���һ���հ���ʱ���������ж��Ƿ���Ҫ���� keep alive ����*/
    tc_iot_timer ping_timer; /**< keep alive ping����ʱ��*/
    tc_iot_timer reconnect_timer; /**< ������ʱ���������ж��Ƿ���Ҫ������һ����������*/
    
    long         client_init_time;
} ;

typedef enum _tc_iot_device_auth_mode_e {
    TC_IOT_MQTT_AUTH_NONE,
    TC_IOT_MQTT_AUTH_STATIC_PASS,
    TC_IOT_MQTT_AUTH_DYNAMIC_TOKEN,
} tc_iot_device_auth_mode_e;

/**
 * @brief �豸��Ϣ
 */
typedef struct _tc_iot_device_info {
    char secret[TC_IOT_MAX_SECRET_LEN];  /**< �豸ǩ����Կ*/
    char product_id[TC_IOT_MAX_PRODUCT_ID_LEN]; /**< �豸 Product Id*/
    char device_name[TC_IOT_MAX_DEVICE_NAME_LEN];  /**< �豸 Device Name*/
    char client_id[TC_IOT_MAX_CLIENT_ID_LEN]; /**< �豸 Client Id*/

    char username[TC_IOT_MAX_USER_NAME_LEN]; /**< ���� MQ ����˵� Username*/
    char password[TC_IOT_MAX_PASSWORD_LEN]; /**< ���� MQ ����˵� Password*/
    long token_expire_time;  /**< username & password ��ʱʱ��*/
} tc_iot_device_info;


/**
 * @brief MQTT client �ͻ�������
 */
typedef struct _tc_iot_mqtt_client_config {
    tc_iot_device_info device_info;  /**< �豸��Ϣ*/
    char* host; /**< MQ �����ַ*/
    uint16_t port; /**< MQ ����˿�*/
    int command_timeout_ms; /**< MQTT ָ�ʱʱ�ӣ���λ����*/
    int tls_handshake_timeout_ms; /**< TLS ����ʱ�ӣ���λ����*/
    int keep_alive_interval; /**< �������ּ������λ�� */
    char clean_session; /**< Clean Session ��־*/
    char use_tls; /**< �Ƿ�ͨ�� TLS ���ӷ���*/
    char auto_reconnect; /**< �Ƿ��Զ����� */
    const char* p_root_ca; /**< ��֤��*/
    const char* p_client_crt; /**< �ͻ���֤��*/
    const char* p_client_key; /**< �ͻ���˽Կ*/

    disconnectHandler disconnect_handler; /**< ���ӶϿ��ص�*/
    message_handler   default_msg_handler; /**< Ĭ����Ϣ����ص�*/
    char willFlag;
    MQTTPacket_willOptions will; 
} tc_iot_mqtt_client_config;


int tc_iot_mqtt_init(tc_iot_mqtt_client* c,
                     tc_iot_mqtt_client_config* p_client_config);

int tc_iot_mqtt_connect_with_results(tc_iot_mqtt_client* client,
                                     MQTTPacket_connectData* options,
                                     tc_iot_mqtt_connack_data* data);
int tc_iot_mqtt_connect(tc_iot_mqtt_client* client,
                        MQTTPacket_connectData* options);
int tc_iot_mqtt_reconnect(tc_iot_mqtt_client* c);
int tc_iot_mqtt_publish(tc_iot_mqtt_client* client, const char*,
                        tc_iot_mqtt_message*);
int tc_iot_mqtt_set_message_handler(tc_iot_mqtt_client* c,
                                    const char* topicFilter,
                                    tc_iot_mqtt_qos_e qos,
                                    message_handler message_handler,
                                    void * context);
int tc_iot_mqtt_subscribe(tc_iot_mqtt_client* client, const char* topicFilter,
                          tc_iot_mqtt_qos_e, message_handler, void * context);
int tc_iot_mqtt_subscribe_with_results(tc_iot_mqtt_client* client,
                                       const char* topicFilter,
                                       tc_iot_mqtt_qos_e, message_handler,
                                       void * context,
                                       tc_iot_mqtt_suback_data* data);
int tc_iot_mqtt_unsubscribe(tc_iot_mqtt_client* client,
                            const char* topicFilter);
int tc_iot_mqtt_disconnect(tc_iot_mqtt_client* client);
int tc_iot_mqtt_yield(tc_iot_mqtt_client* client, int time);
int tc_iot_mqtt_is_connected(tc_iot_mqtt_client* client);
int tc_iot_mqtt_set_state(tc_iot_mqtt_client* client,
                          tc_iot_mqtt_client_state_e state);
tc_iot_mqtt_client_state_e tc_iot_mqtt_get_state(tc_iot_mqtt_client* client);
char tc_iot_mqtt_get_auto_reconnect(tc_iot_mqtt_client* client);
int tc_iot_mqtt_set_auto_reconnect(tc_iot_mqtt_client* client,
                                   char auto_reconnect);
void tc_iot_init_mqtt_conn_data(MQTTPacket_connectData * conn_data);
void tc_iot_mqtt_destroy(tc_iot_mqtt_client* c);

#endif /* end of include guard */
