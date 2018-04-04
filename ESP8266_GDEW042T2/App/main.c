/**
  ******************************************************************************
  * @file    main.c
  * @author  Sky.Ye
  * @version V1.0
  * @date    2018-01-xx
  * @brief   ESP8266 WiFi + Elink 4.2inch ePaperģ�����
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:Ұ�� iSO STM32 ������ 
  * ��̳    :http://www.chuxue123.com
  * �Ա�    :http://firestm32.taobao.com
  *
  ******************************************************************************
  */ 
 
#include "include.h"
 
 

/**
  * @brief  ������
  * @param  ��
  * @retval ��
  */
int main ( void )
{
	/* ��ʼ�� */
  USARTx_Config();                                                              //��ʼ������1
	
	SysTick_Init();                                                               //���� SysTick Ϊ 1ms �ж�һ�� 
	
	ESP8266_Init();                                                               //��ʼ��WiFiģ��ʹ�õĽӿں�����
	
	DHT11_Init();
	
  LED_Init();
	
	Beep_Init();
	
	FLASH_SPI_initialize();
	
	/**elink SPI init**/
	elink_spi_gpio_config();
	
	/**elink ePaper init**/
	elink_gpio_config();
	
	elink_display_init();
	
	Delay_ms(100);
	
	ELINK042_DispString_EN_CH( 128, 192, "Hello World...", WHITE); 
	ELINK042_DispString_EN_CH( 64, 64, "��Ϊ���ӱ�ǩ", WHITE); 
//	ELINK042_DispString_EN_CH( 128, 128, "HuaWei electric tag", WHITE); 
	
	DBG( "\r\n[BIRD] WF-ESP8266 WiFiģ�����...\r\n" );//��ӡ����������ʾ��Ϣ

	ESP8266_StaTcpClient_UnvarnishTest();
	
	/************************power off Sequence************************/
	/**Vcom and data interval setting**/
	elink_soft_vcom_set();

	/**Power off**/
	elink_soft_power_switch(0);	
	
	/**deep sleep**/
	elink_soft_deep_sleep();
	/************************power off Sequence************************/	
 
  while( 1 )
	{
		//printf ( "\r\n[BIRD] elink ePaper ����...\r\n" );                          //��ӡ����������ʾ��Ϣ
		
		//Elink042DispChinaString( 16, 16, "Ұ�𿪷���", WHITE); 

	
	}
	
	
}


/*********************************************END OF FILE**********************/
