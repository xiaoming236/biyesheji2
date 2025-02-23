// ��ȫ��ֵ����
#define TEMP_MIN        -20    // ����¶� -20��
#define TEMP_MAX        50     // ����¶� 50��
#define TEMP_THRESHOLD_MIN  15    // �¶���ֵ��Сֵ
#define TEMP_THRESHOLD_MAX  45    // �¶���ֵ���ֵ

#define SMOKE_MIN       0      // �������Ũ�� 0ppm
#define SMOKE_MAX       1000   // �������Ũ�� 1000ppm
#define SMOKE_WARNING   400    // ������ֵ 400ppm
#define SMOKE_DANGER    800    // ����Σ��ֵ 800ppm

#define CO_MIN          0      // ���COŨ�� 0ppm
#define CO_MAX          2000   // ���COŨ�� 2000ppm
#define CO_WARNING      200    // CO����ֵ 200ppm
#define CO_DANGER       800    // COΣ��ֵ 800ppm

// ������ֵ�洢
typedef struct {
    float temp;          // �¶�ֵ
    float humi;          // ʪ��ֵ
    uint16_t smoke_ppm;  // ����Ũ��(ppm)
    uint16_t co_ppm;     // COŨ��(ppm)
} sensor_data_t;

extern sensor_data_t sensor_data;