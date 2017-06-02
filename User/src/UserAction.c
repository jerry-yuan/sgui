/*************************************************************************/
/** Copyright.															**/
/** FileName: UserAction.c												**/
/** Author: XuYulin														**/
/** Version: 1.0.0.0													**/
/** Description: User operation interface.								**/
/** History:															**/
/**	XuyYulin	2017/2/27	2.0.0.0		New create.						**/
/** XuYulin 2017/2/27 1.0 build this moudle								**/
/*************************************************************************/

//=======================================================================//
//= Include files.													    =//
//=======================================================================//
#include "UserAction.h"
#include "LCD_OperationIF.h"


#include "HMI_Data.h"
#include "HMI_Process.h"

//=======================================================================//
//= Static variable declaration.									    =//
//=======================================================================//

//GUI_LIST_STRUCT			stTestList = {{NULL, 16, arrstTestListItems}};

//=======================================================================//
//= Static function declaration.									    =//
//=======================================================================//

//=======================================================================//
//= Function implementation.										    =//
//=======================================================================//
/*************************************************************************/
/** Function Name:	USR_ACT_OnInitialize								**/
/** Purpose:		Process with application startup.					**/
/** Resources:		None.												**/
/** Params:			None.												**/
/** Return:			None.												**/
/** Notice:			None.												**/
/*************************************************************************/
void USR_ACT_OnInitialize(void)
{
	HMI_Action_Initialize();
}

/*************************************************************************/
/** Function Name:	USR_ACT_OnKeyPress									**/
/** Purpose:		Recive and process keyboard event.					**/
/** Resources:		None.												**/
/** Params:																**/
/** @uiKeyCode:			Key code.										**/
/** Return:			None.												**/
/** Notice:			None.												**/
/*************************************************************************/
void USR_ACT_OnKeyPress(bool bShift, bool bCtrl, bool bAlt, uint16_t uiKeyCode)
{
	uint16_t		uiOptionKeyFlags = KEY_OPTION_NONE;
	if(true == bShift)
	{
		uiOptionKeyFlags |= KEY_OPTION_SHIFT;
	}
	if(true == bCtrl)
	{
		uiOptionKeyFlags |= KEY_OPTION_CTRL;
	}
	if(true == bAlt)
	{
		uiOptionKeyFlags |= KEY_OPTION_ALT;
	}
	HMI_Action_UserActions(uiOptionKeyFlags, &uiKeyCode);
}

void USR_ACT_OnTimerEventProcess(void)
{
	HMI_Action_RefreshScreen(0, NULL);
}

void USR_ACT_OnRTCUpdateEventProcess(uint16_t uiYear, uint16_t uiMonth, uint16_t uiDay, uint16_t uiHour, uint16_t uiMinute, uint16_t uiSecond)
{
	HMI_RTC_TIME		stRTCTime;

	stRTCTime.Year = uiYear;
	stRTCTime.Month = uiMonth;
	stRTCTime.Day = uiDay;
	stRTCTime.Hour = uiHour;
	stRTCTime.Minute = uiMinute;
	stRTCTime.Second = uiSecond;

	HMI_Action_RefreshScreen(2, &stRTCTime);
}