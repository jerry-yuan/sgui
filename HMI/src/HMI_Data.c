/*************************************************************************/
/** Copyright.															**/
/** FileName: HMI_Data.c												**/
/** Author: Polarix														**/
/** Version: 1.0.0.0													**/
/** Description: User operation interface.								**/
/** History:															**/
/**	XuyYulin	2017/2/27	2.0.0.0		New create.						**/
/** XuYulin 2017/2/27 1.0 build this moudle								**/
/*************************************************************************/
//=======================================================================//
//= Include files.													    =//
//=======================================================================//
#include "HMI_Data.h"
#include "HMI_Demo01_Text.h"
#include "HMI_Demo02_List.h"
#include "HMI_Demo03_Notice1.h"
#include "HMI_Demo03_Notice2.h"


//=======================================================================//
//= User Macro definition.											    =//
//=======================================================================//
#define		HMI_PRESSED_KEY_MAX								(2)

//=======================================================================//
//= Data type definition.											    =//
//=======================================================================//
typedef struct
{
	uint16_t		Options;
	uint16_t		Keys[HMI_PRESSED_KEY_MAX];
}HMI_USER_KEY_ACTION;

//=======================================================================//
//= Static variable declaration.									    =//
//=======================================================================//
// Record count of screen.
static size_t						uiScreenCount;
// Record the index of the currently active screen.
static size_t						uiCurrentScreenIndex;
// Record the history of the screen follow-up.
static size_t						uiScreenFollowUpHistory[HMI_GOBACK_HISTORY_SIZE_MAX];
static size_t						uiScreenFollowUpHistoryCount;

static HMI_SCREEN*					pstarrScreenDataArray[] = {
												// Add HMI data here.
												&g_stHMI_DemoText,
												&g_stHMI_DemoList,
												&g_stHMI_DemoRTCNotice,
												&g_stHMI_DemoTextNotice

												};

//=======================================================================//
//= Function implementation.										    =//
//=======================================================================//
/*****************************************************************************/
/** Function Name:	HMI_ActionMap_Initialize								**/
/** Purpose:		Initialize screen follow-up data.						**/
/** Resources:		Screen data array and count variable.					**/
/** Parameters:		None.													**/
/** Return:			None.													**/
/** Notice:			This function must be called in action map initialize	**/
/**					process.												**/
/*****************************************************************************/
void HMI_ScreenData_Initialize(void)
{
	/*----------------------------------*/
	/* Variable Declaration				*/
	/*----------------------------------*/
	size_t				uiScreenIndex;

	/*----------------------------------*/
	/* Initialize						*/
	/*----------------------------------*/
	uiCurrentScreenIndex = 0;
	uiScreenCount = sizeof(pstarrScreenDataArray)/sizeof(HMI_SCREEN*);

	/*----------------------------------*/
	/* Process							*/
	/*----------------------------------*/
	// Initialize each screen.
	for(uiScreenIndex=0; uiScreenIndex<uiScreenCount; uiScreenIndex++)
	{
		if(NULL != pstarrScreenDataArray[uiScreenIndex])
		{
			pstarrScreenDataArray[uiScreenIndex]->ScreenID = uiScreenIndex;
            if(NULL != pstarrScreenDataArray[uiScreenIndex]->Actions->Initialize)
			{
				// Run initialize process if existed.
				pstarrScreenDataArray[uiScreenIndex]->Actions->Initialize();
			}
		}
	}

	uiScreenFollowUpHistoryCount = 0;
}

/*****************************************************************************/
/** Function Name:	Set current active screen data pointer.					**/
/** Purpose:		Set static screen data pointer to a new data structure.	**/
/** Resources:		Static global screen data pointer.						**/
/** Parameters:																**/
/**	@uiScreenIndex:		Screen data will be set.							**/
/** Return:			None.													**/
/** Notice:			None.													**/
/*****************************************************************************/
void HMI_ScreenData_SetCurrentScreen(size_t uiScreenIndex)
{
	uiCurrentScreenIndex = uiScreenIndex;
}

/*****************************************************************************/
/** Function Name:	HMI_ScreenData_GetCurrentScreen.						**/
/** Purpose:		Get current screen data structure pointer which in		**/
/**					active.													**/
/** Resources:		Static global screen data pointer.						**/
/** Parameters:		None.													**/
/** Return:			Current in active screen data structure pointer.		**/
/** Notice:			None.													**/
/*****************************************************************************/
HMI_SCREEN* HMI_ScreenData_GetCurrentScreen(void)
{
	/*----------------------------------*/
	/* Variable Declaration				*/
	/*----------------------------------*/
	HMI_SCREEN*				pstCurrentScreen;

	/*----------------------------------*/
	/* Process							*/
	/*----------------------------------*/
	if(uiCurrentScreenIndex < uiScreenCount)
	{
		pstCurrentScreen = pstarrScreenDataArray[uiCurrentScreenIndex];
	}
	else
	{
		pstCurrentScreen = NULL;
	}

    return pstCurrentScreen;
}

/*****************************************************************************/
/** Function Name:	HMI_ScreenData_AddToHistory.							**/
/** Purpose:		Get current screen data structure pointer which in		**/
/**					active.													**/
/** Resources:		Static global screen data pointer.						**/
/** Parameters:		None.													**/
/** Return:			Current in active screen data structure pointer.		**/
/** Notice:			None.													**/
/*****************************************************************************/
bool HMI_ScreenData_AddToHistory(size_t uiScreenIndex)
{
	bool			bProcessResult;

	if(uiScreenFollowUpHistoryCount < HMI_GOBACK_HISTORY_SIZE_MAX)
	{
		uiScreenFollowUpHistory[uiScreenFollowUpHistoryCount] = uiScreenIndex;
		uiScreenFollowUpHistoryCount++;
		bProcessResult = true;
	}
	else
	{
		bProcessResult = false;
	}

	return bProcessResult;
}

/*****************************************************************************/
/** Function Name:	HMI_ScreenData_GetFromHistory.							**/
/** Purpose:		Get current screen data structure pointer which in		**/
/**					active.													**/
/** Resources:		Static global screen data pointer.						**/
/** Parameters:		None.													**/
/** Return:			Current in active screen data structure pointer.		**/
/** Notice:			None.													**/
/*****************************************************************************/
size_t HMI_ScreenData_GetLastHistory(void)
{
	size_t				uiScreenID;
	if(uiScreenFollowUpHistoryCount > 0)
	{
		uiScreenFollowUpHistoryCount--;
		uiScreenID = uiScreenFollowUpHistory[uiScreenFollowUpHistoryCount];
	}
	else
	{
		uiScreenID = HMI_SCREEN_START;
	}
	return uiScreenID;
}

void HMI_ScreenData_Memcpy(void* pDest, const void* pSrc, size_t uiSize)
{
	memcpy(pDest, pSrc, uiSize);
}
