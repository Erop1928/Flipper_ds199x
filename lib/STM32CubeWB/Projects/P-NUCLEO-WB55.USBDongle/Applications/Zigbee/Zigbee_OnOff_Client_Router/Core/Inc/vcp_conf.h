/**
 ******************************************************************************
 * @file    vcp_conf.h
 * @author  MCD Application Team
 * @brief   Configuration of the vcp interface
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under Ultimate Liberty license
 * SLA0044, the "License"; You may not use this file except in compliance with
 * the License. You may obtain a copy of the License at:
 *                             www.st.com/SLA0044
 *
 ******************************************************************************
 */


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __VCP_CONF_H
#define __VCP_CONF_H

#include "app_zigbee.h"
#ifdef __cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
#define VCP_BAUD_RATE                             (115200)

#define VCP_TASK_ID                               (CFG_TASK_VCP_SEND_DATA)
#define VCP_TASK_PRIO                             (CFG_SCH_PRIO_1)

#ifdef  VCP_TX_PATH_INTERFACE_READY_SETUP_TIME
#define VCP_TIMER_PROC_ID                         (CFG_TIM_PROC_ID_ISR)
#endif

/* External variables --------------------------------------------------------*/
/* Exported macros -----------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */


#ifdef __cplusplus
}
#endif

#endif /*__VCP_CONF_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
