
//error_MSGZ
#ifndef RAILHUBZ_ERROR_MSGZ_01_HPP
#define RAILHUBZ_ERROR_MSGZ_01_HPP


typedef int ERRORCODE; 

	
	enum Error_Triage : int
	{ 
   
		LV1 =1,
		LV2 =2,
		LV0 =-1,
		RENDER_LZ=5,
		UNKNOWN_ERROR = 0,
		NON_ERROR = 255 
		
	};
 enum Exit_Error_Code : int{
   NO_ERROR = 0, 
   PARSER_FAIL = -11,
   MAIN_FAIL = -14,  
   FILE_FORMATE_ERROR = -17,
   MAPLOOKUP_FAIL = -18,
   OI_UTILITYZ_FAIL =-21,
   NOTFOUND = -28,
   NOT_PROCESSED_IN_QUE =-29,
  

   };

#endif