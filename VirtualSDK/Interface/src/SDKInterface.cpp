/*************************************************************************/
/** Copyright.															**/
/** FileName: SDKInterface.cpp											**/
/** Author: Polarix														**/
/** Description: SDK swap interface function defines.					**/
/*************************************************************************/
//=======================================================================//
//= Include files.													    =//
//=======================================================================//
#include <wx/msgdlg.h>
#include "SDKInterface.h"
#include "LCDFrame.h"
#include "DemoProc.h"

//=======================================================================//
//= User definition.												    =//
//=======================================================================//
//#define	SDK_THREAD_LOCK()					wxCriticalSectionLocker clsCSLock(s_clsEventSyncCS)
#define EventSyncLock()							{s_clsEventSyncCS.Enter();}
#define EventSyncUnlock()						{s_clsEventSyncCS.Leave();}

#define SDK_DEFAULT_HEART_BEAT_INTERVAL_MS		(50)
#define SDK_EVENT_SYNC_TIMEOUT_MS				(500)

//=======================================================================//
//= Static function declaration.									    =//
//=======================================================================//
static void					SGUI_SDK_PrepareSDK(void);
static bool					SGUI_SDK_SyncMainFrameEvent(wxEvent& clsEvent, ENV_FLAG_INDEX eSyncFlag, int iTimeOutMs);

//=======================================================================//
//= Data type definition.											    =//
//=======================================================================//
static bool					s_barrEventFlag[ENV_FLAG_IDX_MAX];
static unsigned int         s_uiKeyCode;
static wxCriticalSection	s_clsEventSyncCS;

//=======================================================================//
//= Function define.										            =//
//=======================================================================//

/*************************************************************************/
/** Function Name:	USR_ACT_OnKeyPress									**/
/** Purpose:		Recive and process key press event.					**/
/** Resources:		None.												**/
/** Params:																**/
/** @ uiKeyCode:        Key code.										**/
/** Return:			None.												**/
/** Notice:			None.												**/
/*************************************************************************/
void SGUI_SDK_KeyPressInterruptEvent(unsigned int uiKeyCode)
{
    /*----------------------------------*/
    /* Variable Declaration				*/
    /*----------------------------------*/
    SGUI_UINT16				uiEventKeyCode;
    HMI_EVENT				stEvent;

    /*----------------------------------*/
    /* Initialize						*/
    /*----------------------------------*/
    uiEventKeyCode =		uiKeyCode;
    stEvent.Action =		HMI_ENGINE_ACTION_KEY_PRESS;
    stEvent.Data =			(SGUI_BYTE*)&uiEventKeyCode;

    /*----------------------------------*/
    /* Process							*/
    /*----------------------------------*/
    // Call demo process.
    EventProcess(HMI_ENGINE_EVENT_ACTION, &stEvent);
    SGUI_SDK_RefreshDisplay();
}

void SGUI_SDK_HeartBeatTimerTagEvent(void)
{
    /*----------------------------------*/
    /* Variable Declaration				*/
    /*----------------------------------*/
    HMI_EVENT				stEvent;
    SGUI_INT				iRandomNumber;

    /*----------------------------------*/
    /* Initialize						*/
    /*----------------------------------*/
    stEvent.Action =		HMI_ENGINE_ACTION_ON_TIMER;
    stEvent.Data =			NULL;

    /*----------------------------------*/
    /* Process							*/
    /*----------------------------------*/
    iRandomNumber = rand();

    iRandomNumber = (iRandomNumber % 200)-100;
    stEvent.Data = (SGUI_BYTE*)(&iRandomNumber);
    // Post timer event.
    EventProcess(HMI_ENGINE_EVENT_ACTION, &stEvent);
    SGUI_SDK_RefreshDisplay();
}

void SGUI_SDK_RTCInterruptTagEvent(void)
{
    /*----------------------------------*/
    /* Variable Declaration				*/
    /*----------------------------------*/
    HMI_EVENT				stEvent;

    /*----------------------------------*/
    /* Initialize						*/
    /*----------------------------------*/
    stEvent.Action =		HMI_ENGINE_ACTION_ON_TIMER_RTC;
    stEvent.Data = 			NULL;

    /*----------------------------------*/
    /* Process							*/
    /*----------------------------------*/
    // Post RTC update message to a screen.
    EventProcess(HMI_ENGINE_EVENT_ACTION, &stEvent);
    SGUI_SDK_RefreshDisplay();
}

/*************************************************************************/
/** Function Name:	VDIF_SetPixel                                       **/
/** Purpose:		Set virtual device pixel register data.             **/
/** Params:																**/
/**	@ iPosX[in]:		Pixel x-coordinate on display panel.			**/
/**	@ iPosY[in]:		Pixel y-coordinate on display panel.			**/
/**	@ iPixelValue[out]:	Pixel value, 0 for clear, 1 for set.			**/
/** Return:			None.                                               **/
/** Notice:			None.                                               **/
/*************************************************************************/
void SGUI_SDK_SetPixel(int iPosX, int iPosY, int iPixelValue)
{
    /*----------------------------------*/
    /* Variable Declaration				*/
    /*----------------------------------*/
    LCDFrame*           pclsMainFrameObjectPtr;

    /*----------------------------------*/
    /* Initialize						*/
    /*----------------------------------*/
    pclsMainFrameObjectPtr = LCDFrame::GetInstance();

    /*----------------------------------*/
    /* Process							*/
    /*----------------------------------*/
    if(NULL != pclsMainFrameObjectPtr)
    {
        pclsMainFrameObjectPtr->SetLCDPixel(iPosX, iPosY, iPixelValue);
    }
}

/*************************************************************************/
/** Function Name:	VDIF_GetPixel                                       **/
/** Purpose:		Get a pixel value form virtual device register.     **/
/** Params:																**/
/**	@ iPosX[in]:		Pixel x-coordinate on display panel.			**/
/**	@ iPosY[in]:		Pixel y-coordinate on display panel.		    **/
/** Return:			Pixel state, 0 for cleared, 1 for set.              **/
/** Notice:			None.                                               **/
/*************************************************************************/
int SGUI_SDK_GetPixel(int iPosX, int iPosY)
{
    /*----------------------------------*/
    /* Variable Declaration				*/
    /*----------------------------------*/
    LCDFrame*           pclsMainFrameObjectPtr;
    int					iPixelValue;

    /*----------------------------------*/
    /* Initialize						*/
    /*----------------------------------*/
    pclsMainFrameObjectPtr = LCDFrame::GetInstance();

    /*----------------------------------*/
    /* Process							*/
    /*----------------------------------*/
    if(NULL != pclsMainFrameObjectPtr)
    {
        iPixelValue = pclsMainFrameObjectPtr->GetLCDPixel(iPosX, iPosY);
    }
    else
    {
        iPixelValue = 0;
    }

    return iPixelValue;
}

/*************************************************************************/
/** Function Name:	VDIF_RefreshDisplay.                                **/
/** Purpose:		Refresh virtual device display.                     **/
/** Params:			None.                                               **/
/** Return:			None.                                               **/
/** Notice:			None.                                               **/
/*************************************************************************/
void SGUI_SDK_RefreshDisplay(void)
{
    /*----------------------------------*/
    /* Variable Declaration				*/
    /*----------------------------------*/
    LCDFrame*           pclsMainFrameObjectPtr;

    /*----------------------------------*/
    /* Initialize						*/
    /*----------------------------------*/
    pclsMainFrameObjectPtr = LCDFrame::GetInstance();

    /*----------------------------------*/
    /* Process							*/
    /*----------------------------------*/
    if(NULL != pclsMainFrameObjectPtr)
    {
        pclsMainFrameObjectPtr->RefreshLCD();
    }
}

/*************************************************************************/
/** Function Name:	VDIF_ClearDisplay.                                  **/
/** Purpose:		Clear screen display.                               **/
/** Params:			None.                                               **/
/** Return:			None.                                               **/
/** Notice:			None.                                               **/
/*************************************************************************/
void SGUI_SDK_ClearDisplay(void)
{
    /*----------------------------------*/
    /* Variable Declaration				*/
    /*----------------------------------*/
    LCDFrame*           pclsMainFrameObjectPtr;

    /*----------------------------------*/
    /* Initialize						*/
    /*----------------------------------*/
    pclsMainFrameObjectPtr = LCDFrame::GetInstance();

    /*----------------------------------*/
    /* Process							*/
    /*----------------------------------*/
    if(NULL != pclsMainFrameObjectPtr)
    {
        pclsMainFrameObjectPtr->ClearLCD();
        pclsMainFrameObjectPtr->RefreshLCD();
    }
}

void EnterCriticalSection(void)
{
	s_clsEventSyncCS.Enter();
}

void LeaveCriticalSection(void)
{
	s_clsEventSyncCS.Leave();
}

bool SGUI_SDK_SyncMainFrameEvent(wxEvent& clsEvent, ENV_FLAG_INDEX eSyncFlag, int iTimeOutMs)
{
    /*----------------------------------*/
    /* Variable Declaration				*/
    /*----------------------------------*/
    LCDFrame*           pclsMainFrameObjectPtr;
    TimerSetEvent		clsEventObject;
    bool				bReturn;
    int					iWaitTimeMs;

    /*----------------------------------*/
    /* Initialize						*/
    /*----------------------------------*/
    pclsMainFrameObjectPtr = LCDFrame::GetInstance();
    bReturn =			false;
    iWaitTimeMs =		iTimeOutMs;

    /*----------------------------------*/
    /* Process							*/
    /*----------------------------------*/
    do
    {
        if(NULL == pclsMainFrameObjectPtr)
        {
            // No main frame instance.
            break;
        }
        // Set window ID.
        clsEvent.SetId(pclsMainFrameObjectPtr->GetId());
        // Post event.
        SGUI_SDK_SetEvnetSyncFlag(eSyncFlag, false);
        wxPostEvent(pclsMainFrameObjectPtr, clsEvent);
        // Wait for sync
        if(iWaitTimeMs < 1)
        {
            // No wait, return immediately.
            bReturn = true;

            SGUI_SDK_SetEvnetSyncFlag(eSyncFlag, true);
            break;
        }
        else
        {
            while(iWaitTimeMs--)
            {
                if(true == SGUI_SDK_GetEventSyncFlag(eSyncFlag))
                {
                    // Sync done
                    bReturn = true;
                    break;
                }
                wxMilliSleep(1);
            }
        }
    }
    while(0);

    return bReturn;
}

void SGUI_SDK_SetEvnetSyncFlag(ENV_FLAG_INDEX eIndex, bool bValue)
{
    /*----------------------------------*/
    /* Process							*/
    /*----------------------------------*/
    EventSyncLock();
    s_barrEventFlag[eIndex] = bValue;
    EventSyncUnlock();
}

/*************************************************************************/
/** Function Name:	SetKeyEventData.									**/
/** Purpose:		Set key code value when key press event targets.	**/
/** Params:																**/
/**	@ uiKeyCode[in]:	Key code.										**/
/** Return:			None.												**/
/** Notice:			This function used to save and keep pressed key 	**/
/**					code value, must be called before SetEvnetFlag.		**/
/*************************************************************************/
void SGUI_SDK_SyncKeyEventData(unsigned int uiKeyCode)
{
    /*----------------------------------*/
    /* Process							*/
    /*----------------------------------*/
    EventSyncLock();
    s_uiKeyCode = uiKeyCode;
    EventSyncUnlock();
}

/*************************************************************************/
/** Function Name:	GetEventFlag.										**/
/** Purpose:		Post SDK heart-beat timer set event to main frame.	**/
/** Params:																**/
/**	@ uiIntervalMs[in]:	Timer interval in ms, 0 to stop timer.			**/
/** Return:																**/
/**	@ true:				Post message and wait sync successfully.		**/
/**	@ false:			Post message failed or wait for sync timeout.	**/
/** Notice:			This function will start a timer for demo process,	**/
/**					like screen auto scroll animation or dummy data		**/
/**					input.												**/
/*************************************************************************/
bool SGUI_SDK_GetEventSyncFlag(ENV_FLAG_INDEX eIndex)
{
    /*----------------------------------*/
    /* Variable Declaration				*/
    /*----------------------------------*/
    bool				bReturn;

    /*----------------------------------*/
    /* Process							*/
    /*----------------------------------*/
    EventSyncLock();
    bReturn = s_barrEventFlag[eIndex];
    EventSyncUnlock();
    return bReturn;
}

/*************************************************************************/
/** Function Name:	SetSDKHeartBeatTimer.								**/
/** Purpose:		Post SDK heart-beat timer set event to main frame.	**/
/** Params:																**/
/**	@ uiIntervalMs[in]:	Timer interval in ms, 0 to stop timer.			**/
/** Return:																**/
/**	@ true:				Post message and wait sync successfully.		**/
/**	@ false:			Post message failed or wait for sync timeout.	**/
/** Notice:			This function will start a timer for demo process,	**/
/**					like screen auto scroll animation or dummy data		**/
/**					input, the recommended setting is 20(ms) or more.	**/
/*************************************************************************/
bool SGUI_SDK_ConfigHearBeatTimer(unsigned int uiIntervalMs)
{
    /*----------------------------------*/
    /* Variable Declaration				*/
    /*----------------------------------*/
    TimerSetEvent		clsEventObject;
    bool				bReturn;

    /*----------------------------------*/
    /* Initialize						*/
    /*----------------------------------*/
    bReturn =			false;

    /*----------------------------------*/
    /* Process							*/
    /*----------------------------------*/
    // Prepare event object.

    clsEventObject.SetEventType(wxEVT_TIMER_SET);
    clsEventObject.SetInterval(uiIntervalMs);

    // Post event.
    bReturn = SGUI_SDK_SyncMainFrameEvent(clsEventObject, ENV_FLAG_IDX_SDK_TIM_SET, SDK_EVENT_SYNC_TIMEOUT_MS);

    return bReturn;
}

/*************************************************************************/
/** Function Name:	SetRTCTimer.										**/
/** Purpose:		Post RTC timer set event to main frame.				**/
/** Params:																**/
/**	@ bEnabled[in]:		RTC timer enable.								**/
/** Return:																**/
/**	@ true:				Post message and wait sync successfully.		**/
/**	@ false:			Post message failed or wait for sync timeout.	**/
/** Notice:			This function will start RTC for demo process, like **/
/**					screen auto scroll animation or dummy data input.	**/
/*************************************************************************/
bool SGUI_SDK_EnableRTCInterrupt(bool bEnabled)
{
    /*----------------------------------*/
    /* Variable Declaration				*/
    /*----------------------------------*/
    RTCSwitchEvent		clsEventObject;
    bool				bReturn;

    /*----------------------------------*/
    /* Initialize						*/
    /*----------------------------------*/
    bReturn =			false;

    /*----------------------------------*/
    /* Process							*/
    /*----------------------------------*/
    // Prepare event object.

    clsEventObject.SetEventType(wxEVT_RTC_SWITCH);
    clsEventObject.SetReqState(bEnabled);

    // Post event.
    bReturn = SGUI_SDK_SyncMainFrameEvent(clsEventObject, ENV_FLAG_IDX_SDK_RTC_EN, SDK_EVENT_SYNC_TIMEOUT_MS);

    return bReturn;
}

/*************************************************************************/
/** Function Name:	PrepareSDK.											**/
/** Purpose:		Initialize global variable of SDK.					**/
/** Params:			None.                                               **/
/** Return:			None.                                               **/
/** Notice:			This function must only called when dummy main		**/
/**					starting.											**/
/*************************************************************************/
void SGUI_SDK_PrepareSDK(void)
{
    /*----------------------------------*/
    /* Process							*/
    /*----------------------------------*/
    // Initialize event sync flag
    for(unsigned int i=0; i<ENV_FLAG_IDX_MAX; i++)
    {
        s_barrEventFlag[i] = false;
    }
    // Initialize key coed variable.
    s_uiKeyCode = KEY_VALUE_NONE;
}

/*************************************************************************/
/** Function Name:	InitializeSDK.										**/
/** Purpose:		Post initialize event and wait for event sync.		**/
/** Params:			None.                                               **/
/** Return:			None.                                               **/
/** Notice:			Post event to main frame for initialize SDK.		**/
/*************************************************************************/
bool SGUI_SDK_Initialize(void)
{
    /*----------------------------------*/
    /* Variable Declaration				*/
    /*----------------------------------*/
    InitEvent			clsEventObject;
    bool				bReturn;

    /*----------------------------------*/
    /* Initialize						*/
    /*----------------------------------*/
    bReturn =			false;

    /*----------------------------------*/
    /* Process							*/
    /*----------------------------------*/
    // Prepare event object.
    clsEventObject.SetEventType(wxEVT_SDK_INIT);

    bReturn = SGUI_SDK_SyncMainFrameEvent(clsEventObject, ENV_FLAG_IDX_SDK_INIT, SDK_EVENT_SYNC_TIMEOUT_MS);

    return bReturn;
}

/*************************************************************************/
/** Function Name:	SGUI_SDK_DummyMainProc								**/
/** Purpose:		Main process start interface.						**/
/** Params:			None.                                               **/
/** Return:			return code, 0 for no error.						**/
/** Notice:			This function simulates the main entry function of	**/
/**					the target platform, it will called by main frame	**/
/**					thread helper process.								**/
/*************************************************************************/
int SGUI_SDK_DummyMainProc(void)
{
	bool		bRet;
    // Initialize SDK.
    SGUI_SDK_PrepareSDK();
    // Initialize main frame.
    bRet = SGUI_SDK_Initialize();
    if(false == bRet)
	{
		wxMessageBox("Initialize error.");
	}
    // Start heart-beat timer.
    SGUI_SDK_ConfigHearBeatTimer(SDK_DEFAULT_HEART_BEAT_INTERVAL_MS);
	// Start RTC timer.
    SGUI_SDK_EnableRTCInterrupt(true);

    // Initialize Engine.
    InitializeEngine();

    while(1)
    {
        // Check and process heart-beat timer event.
        if(true == SGUI_SDK_GetEventSyncFlag(ENV_FLAG_IDX_SDK_TIM_EVENT))
        {
            SGUI_SDK_HeartBeatTimerTagEvent();
            SGUI_SDK_SetEvnetSyncFlag(ENV_FLAG_IDX_SDK_TIM_EVENT, false);
        }
        // Check and process key press event.
        if(true == SGUI_SDK_GetEventSyncFlag(ENV_FLAG_IDX_SDK_KEY_EVENT))
        {
            SGUI_SDK_KeyPressInterruptEvent(s_uiKeyCode);
            SGUI_SDK_SetEvnetSyncFlag(ENV_FLAG_IDX_SDK_KEY_EVENT, false);
        }
        // Check and process RTC event.
        if(true == SGUI_SDK_GetEventSyncFlag(ENV_FLAG_IDX_SDK_RTC_EVENT))
        {
            SGUI_SDK_RTCInterruptTagEvent();
            SGUI_SDK_SetEvnetSyncFlag(ENV_FLAG_IDX_SDK_RTC_EVENT, false);
        }
    }

    return 0;
}
