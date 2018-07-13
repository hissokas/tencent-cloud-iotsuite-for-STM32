#ifndef TC_IOT_EXPORT_H
#define TC_IOT_EXPORT_H

#include "tc_iot_inc.h"

int tc_io_main(int argc, char** argv);


/**
 * @brief tc_iot_set_log_level ������־����������
 *
 * @param log_level ��Ҫ���õ���־����
 */
void tc_iot_set_log_level(tc_iot_log_level_e log_level);

/**
 * @brief tc_iot_get_log_level ��ȡ��־����������
 *
 * @return ���ص�ǰϵͳ���õ���־����
 */
tc_iot_log_level_e tc_iot_get_log_level();


/**
 * @brief tc_iot_log_level_enabled �ж�ָ���ȼ�����־����ǰ�Ƿ������
 *
 * @param log_level ��Ҫ�жϵ���־����
 *
 * @return Ϊ 1 ��ʾ��������� 0 ��ʾָ������־�ȼ��������ã����������
 */
char tc_iot_log_level_enabled(tc_iot_log_level_e log_level);


/**
 * @brief tc_iot_mqtt_client_construct ���� MQTT client��������MQ������
 *
 * @param p_mqtt_client MQTT client ���󣬳��Ρ�
 * @param p_client_config ������ʼ�� MQTT Client �����������Ϣ, ��Ρ�
 *
 * @return ���������
 * @see tc_iot_sys_code_e
 */
int tc_iot_mqtt_client_construct(tc_iot_mqtt_client* p_mqtt_client,
                                 tc_iot_mqtt_client_config* p_client_config);


/**
 * @brief tc_iot_mqtt_client_destroy �ر� MQTT client ���ӣ������� MQTT client
 *
 * @param p_mqtt_client MQTT client ����
 */
void tc_iot_mqtt_client_destroy(tc_iot_mqtt_client* p_mqtt_client);


/**
 * @brief tc_iot_mqtt_client_is_connected �ж� MQTT client ����ǰ�Ƿ������ӷ�
 * ���
 *
 * @param p_mqtt_client MQTT client ����
 *
 * @return 1 ��ʾ�����ӣ�0 ��ʾδ���ӡ�
 */
char tc_iot_mqtt_client_is_connected(tc_iot_mqtt_client* p_mqtt_client);


/**
 * @brief tc_iot_mqtt_client_yield MQTT client
 * ��ѭ������������ά�֡�������Ϣ��Ӧ��ʱ��⡢������������Ϣ��ȡ�Ȳ�����
 *
 * @param p_mqtt_client MQTT client ����
 * @param timeout_ms �ȴ�ʱ�ӣ���λ����
 *
 * @return ���������
 * @see tc_iot_sys_code_e
 */
int tc_iot_mqtt_client_yield(tc_iot_mqtt_client* p_mqtt_client, int timeout_ms);


/**
 * @brief tc_iot_mqtt_client_publish ��ָ���� Topic ������Ϣ
 *
 * @param p_mqtt_client MQTT client ����
 * @param topic Topic ����
 * @param msg ��������Ϣ
 *
 * @return ���������
 * @see tc_iot_sys_code_e
 */
int tc_iot_mqtt_client_publish(tc_iot_mqtt_client* p_mqtt_client,
                               const char* topic, tc_iot_mqtt_message* msg);


/**
 * @brief tc_iot_mqtt_client_subscribe ����ָ��һ������ Topic ����Ϣ
 *
 * @param p_mqtt_client MQTT client ����
 * @param topic_filter ������ Topic ����
 * @param qos ���ζ��ĵ� QOS �ȼ�
 * @param msg_handler ������Ϣ�ص�
 * @param context ������Ӧ�ص� context
 *
 * @return ���������
 * @see tc_iot_sys_code_e
 */
int tc_iot_mqtt_client_subscribe(tc_iot_mqtt_client* p_mqtt_client,
                                 const char* topic_filter,
                                 tc_iot_mqtt_qos_e qos,
                                 message_handler msg_handler,
                                 void * context);

/**
 * @brief tc_iot_mqtt_client_unsubscribe ȡ����ĳ������ Topic ����
 *
 * @param p_mqtt_client MQTT client ����
 * @param topic_filter ��ȡ������ Topic ����
 *
 * @return ���������
 * @see tc_iot_sys_code_e
 */
int tc_iot_mqtt_client_unsubscribe(tc_iot_mqtt_client* p_mqtt_client,
                                   const char* topic_filter);


/**
 * @brief tc_iot_mqtt_client_disconnect �Ͽ� MQTT client �����˵�����
 *
 * @param p_mqtt_client MQTT client ����
 *
 * @return ���������
 * @see tc_iot_sys_code_e
 */
int tc_iot_mqtt_client_disconnect(tc_iot_mqtt_client* p_mqtt_client);

/**
 *  @brief tc_iot_server_init
 * �����豸���ò�������ʼ������
 *  @param  p_shadow_client �豸�������
 *  @param  p_client_config �������ò�����
 *  @return ���������
 *  @see tc_iot_sys_code_e
 */
int tc_iot_server_init(tc_iot_shadow_client* p_shadow_client, tc_iot_shadow_config * p_client_config);


/**
 *  @brief tc_iot_server_loop
 *  ����������ѭ�����������շ������ͼ���Ӧ���ݡ�
 *  @param  p_shadow_client �豸�������
 *  @param yield_timeout ѭ���ȴ�ʱ�䣬��λ����
 *  @return ���������
 *  @see tc_iot_sys_code_e
 */

int tc_iot_server_loop(tc_iot_shadow_client* p_shadow_client, int yield_timeout);

/**
 *  @brief tc_iot_server_destroy
 * ����ģ��������������ͷ���Դ��
 *  @param  p_shadow_client �豸Ӱ�Ӷ���
 *  @return ���������
 *  @see tc_iot_sys_code_e
 */

int tc_iot_server_destroy(tc_iot_shadow_client* p_shadow_client);



/**
 *  @brief tc_iot_report_device_data

    @par
    ��鱾�ر������ݺͷ���˲��죬�ϱ��豸����ģ�������������״̬�����µ�����ˡ�

 *  @param  p_shadow_client �豸Ӱ�Ӷ���
 *  @return ���������
 *  @see tc_iot_sys_code_e
 */
int tc_iot_report_device_data(tc_iot_shadow_client* p_shadow_client);

/**
 *  @brief tc_iot_confirm_devcie_data

    @par
    ȷ�Ϸ���˿���ָ��ִ�н�������������·��� desired ָ��ִ�гɹ���
    ���ϱ�����״̬������ն�Ӧ�� desired ָ�
 *  @param  p_shadow_client �豸Ӱ�Ӷ���
 *  @return ���������
 *  @see tc_iot_sys_code_e
 */
int tc_iot_confirm_devcie_data(tc_iot_shadow_client* p_shadow_client);




#if 0
/**
 * @brief tc_iot_coap_construct ��ʼ�� CoAP �ͻ�������
 *
 * @param c ����ʼ���� CoAP �ͻ������ݽṹ��
 * @param p_client_config ��ʼ����ز���������
 * CoAP �����ַ���˿ڡ��Ƿ�ʹ�� DTLS��DTLS PSK��
 * ��Ʒ��Ϣ���豸���ơ��豸��Կ���ص������ȡ�
 *
 * @return ���������
 * @see tc_iot_sys_code_e
 */
int tc_iot_coap_construct(tc_iot_coap_client* c, tc_iot_coap_client_config* p_client_config);


/**
 * @brief tc_iot_coap_auth ������֤����ȡ��������������豸 Token��
 *
 * @param c �ѳ�ʼ���õ� CoAP �ͻ��ˡ�
 *
 * @return ���������
 * @see tc_iot_sys_code_e
 */
int tc_iot_coap_auth(tc_iot_coap_client* c);


/**
 * @brief tc_iot_coap_send_message �����˷��� CoAP ��Ϣ��
 *
 * @param c �ѳɹ���ȡ��ȡ��Ȩ Token �� CoAP �ͻ��ˡ�
 * @param message �����͵���Ϣ
 * @param callback ��Ϣ�ص�
 * @param timeout_ms ��Ϣ���ȴ�ʱ��
 * @param session_context ��Ϣ�ص�͸������
 *
 * @return ���������
 * @see tc_iot_sys_code_e
 */
int tc_iot_coap_send_message(tc_iot_coap_client* c, tc_iot_coap_message* message,
        tc_iot_coap_con_handler callback, int timeout_ms, void * session_context);


/**
 * @brief tc_iot_coap_publish Ϊ���� tc_iot_coap_send_message
 * ���ϲ��߼���װ�������������ϱ���Ϣ��
 *
 * @param c �ѳɹ���ȡ��ȡ��Ȩ Token �� CoAP �ͻ��ˡ�
 * @param uri_path �ϱ��ӿ� URI Path����ǰ�̶���д
 * TC_IOT_COAP_SERVICE_PUBLISH_PATH��
 * @param topic_query_uri �ϱ���Ϣ����Ŀ�� Topic
 * �����������̶���ʽΪ��tp=Topic_Name��������ϱ���Ϣ�� TopicA��
 * ����Ӧ���� tp= ǰ׺����дΪ ��tp=TopicA��
 * @param msg �ϱ���Ϣ Payload ��
 * @param callback �ϱ�����ص���
 *
 * @return ���������
 * @see tc_iot_sys_code_e
 *
 */
int tc_iot_coap_publish( tc_iot_coap_client * c, const char * uri_path, 
        const char * topic_query_uri, const char * msg, tc_iot_coap_con_handler callback);

/**
 * @brief tc_iot_coap_rpc Ϊ���� tc_iot_coap_send_message 
 * ���ϲ��߼���װ����������Ӱ�ӷ��������Զ��� Topic ��Զ�̷���
 *
 * @param c �ѳɹ���ȡ��ȡ��Ȩ Token �� CoAP �ͻ��ˡ�
 * @param uri_path �ϱ��ӿ� URI Path����ǰ�̶���д
 * TC_IOT_COAP_SERVICE_RPC_PATH��
 * @param topic_query_uri RPC �����������Ŀ�� Topic
 * �����������̶���ʽΪ��pt=Topic_Name��������� TopicUpdate��
 * ����Ӧ���� pt= ǰ׺����дΪ ��pt=TopicUpdate��
 * @param topic_resp_uri RPC ������Ӧ Topic
 * �����������̶���ʽΪ��st=Topic_Name��������� TopicCmd��
 * ����Ӧ���� st= ǰ׺����дΪ ��st=TopicUpdate��
 * @param msg �ϱ���Ϣ Payload ��
 * @param callback RPC ���ý���ص���
 *
 * @return ���������
 * @see tc_iot_sys_code_e
 *
 */
int tc_iot_coap_rpc( tc_iot_coap_client * c, const char * uri_path, 
        const char * topic_query_uri, const char * topic_resp_uri,
        const char * msg, tc_iot_coap_con_handler callback);

/**
 *
 * @brief tc_iot_coap_yield  CoAP client ��ѭ��������������Ϣ��Ӧ��ʱ
 * ��⡢������������Ϣ��ȡ�Ȳ�����
 *
 * @param c CoAP client ����
 * @param timeout_ms �ȴ�ʱ�ӣ���λ����
 *
 * @return ���������
 * @see tc_iot_sys_code_e
 */
int tc_iot_coap_yield(tc_iot_coap_client * c, int timeout_ms);


/**
 * @brief tc_iot_coap_destroy �ͷ� CoAP client ���������Դ��
 *
 * @param c CoAP client ����
 */
void tc_iot_coap_destroy(tc_iot_coap_client* c);


/**
 * @brief tc_iot_coap_get_message_code ��ȡ��Ϣ����򷵻��롣
 *
 * @param message CoAP ��Ϣ
 *
 * @return ��Ϣ����򷵻���
 * @see tc_iot_coap_rsp_code
 */
unsigned char tc_iot_coap_get_message_code(tc_iot_coap_message* message);

/**
 * @brief tc_iot_coap_get_message_payload ��ȡ CoAP ��Ϣ�� Payload ���ݡ�
 *
 * @param message CoAP ��Ϣ
 * @param payload_len Payload �ĳ���
 * @param payload Payload �����׵�ַ
 *
 * @return ��������룬���� TC_IOT_SUCCESS ��˵����ȡ�ɹ���
 * @see tc_iot_sys_code_e
 */
int tc_iot_coap_get_message_payload(tc_iot_coap_message* message, int *payload_len, unsigned char **payload);



/**
 * @brief tc_iot_ota_construct ��ʼ�� OTA �������
 *
 * @param ota_handler ����ʼ���� OTA ����
 * @param mqtt_client OTA ����ͨ�� MQTT Э��������ͨѶ����Ҫָ������ͨѶ��
 * MQTT Client��
 * @param sub_topic OTA ������Ϣ Topic
 * @param pub_topic OTA ������Ϣ Topic
 * @param ota_msg_callback OTA ������Ϣ�ص�֪ͨ����
 *
 * @return ��������룬���� TC_IOT_SUCCESS ��˵����ȡ�ɹ���
 * @see tc_iot_sys_code_e
 */
int tc_iot_ota_construct(tc_iot_ota_handler * ota_handler, tc_iot_mqtt_client * mqtt_client, 
        const char * sub_topic, const char * pub_topic, message_handler ota_msg_callback);


/**
 * @brief tc_iot_ota_destroy OTA ������������ȡ�� OTA ��Ϣ���ģ��ͷ���Դ��
 *
 * @param ota_handler ���ͷŵ� OTA �������
 */
void tc_iot_ota_destroy(tc_iot_ota_handler * ota_handler);


/**
 * @brief tc_iot_ota_report_upgrade OTA ����ִ�й����У��ϱ��̼����ؼ��������ȡ�
 *
 * @param ota_handler OTA �������
 * @param state ��ǰ������չö��
 * @param message ������Ϣ
 * 1.��ǰ��չΪ�ɹ�ʱ���ϱ� TC_IOT_OTA_MESSAGE_SUCCESS ��
 * 2.�����ʧ��ʱ���ϱ���Ӧ��ʧ����Ϣ���� TC_IOT_OTA_MESSAGE_FAILED ��
 * @param percent �ٷֱȣ�0~100������ state Ϊ OTA_DOWNLOAD
 * ʱ��Ч�������ϱ�������ɰٷֱȡ�
 *
 * @return ��������룬���� TC_IOT_SUCCESS ��˵����ȡ�ɹ���
 * @see tc_iot_sys_code_e
 */
int tc_iot_ota_report_upgrade(tc_iot_ota_handler * ota_handler, tc_iot_ota_state_e state, char * message, int percent);

/**
 *  @brief tc_iot_ota_report_firm
     �ϱ��豸ϵͳ��Ϣ
 @par
 �ϱ��̼���Ϣ���̼���Ϣ key �� value �ɸ���ʵ��Ӧ�ó���ָ�������磬Ҫ�ϱ� �̼��汾��sdk �汾��
 Ӳ���汾�����÷�ʽΪ��

 @code{.c}
 tc_iot_ota_report_firm(&handler,
         "sdk-ver", TC_IOT_SDK_VERSION,
         "firm-ver",TC_IOT_FIRM_VERSION, NULL);
 @endcode

 *  @param ota_handler OTA ����
 *  @param va_list �ɱ�����б�����ʵ���ϱ����ָ������ʽΪ key1,value1,key2,value2, ..., NULL
 * ���� key value �Է�ʽ������ָ�������һ����������ΪNULL����Ϊ�����ֹ����
 *  @return ���������
 * @see tc_iot_sys_code_e
 */
int tc_iot_ota_report_firm(tc_iot_ota_handler * ota_handler, ...);


/**
 * @brief tc_iot_ota_request_content_length ��ȡָ�� URL �ļ��Ĵ�С��
 *
 * @param api_url ����ȡ��Ϣ���ļ� URL
 *
 *  @return ���������
 * @see tc_iot_sys_code_e
 */
int tc_iot_ota_request_content_length(const char* api_url);


/**
 * @brief tc_iot_ota_download ����ָ���Ĺ̼� URL ��ַ�����ع̼�
 *
 * @param api_url �̼���ַ
 * @param partial_start ����ƫ�Ƶ�ַ��Ĭ���� 0������Ҫ����ʱ������Ҫƫ�Ƶ�ֵ��
 * @param download_callback
 * ���ع��̻ص������ڻ��������ޣ�ÿ���سɹ�һ�����ݣ��ͻ�ͨ�����ص���֪ͨ�豸��
 * ���д������磬д�뵽 Flash �С�
 * @param context �ص�͸������
 *
 *  @return ���������
 * @see tc_iot_sys_code_e
 */
int tc_iot_ota_download(const char* api_url, int partial_start, tc_iot_http_download_callback download_callback, const void * context);

#endif

#endif /* end of include guard */
