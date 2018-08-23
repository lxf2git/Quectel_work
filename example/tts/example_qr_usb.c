/**
 *@file     example_qr_usb.c
 *@date     2018-08-16
 *@author   robin 
 *@brief    example_qr_usb_daemon
 */

#include "ql_oe.h"
#include "ql_at_cmd.h"

#define  RESPONESE_SIZE    128UL
#define TAG   "QL_QR_USB_E"
#define QL_QR_USB_LOG(format, ...)     fprintf(stderr, [TAG]"[%d]:"format, __LINE__, ##__VA_ARGS__)

void user_callback( void* args,  char *at_response)
{
 	 QL_QR_USB_LOG("at_response:%s\n",  at_response);
}



int main(int argc, char *argv[])
{

	QL_QR_USB_LOG("entry\n");

		
	//init camera 
       ql_qr_usb_camera_init();

	
      //use at test cmd
       ql_qr_usb_atcmd_func("AT\r\n",user_callback);

	// open camera 
	//AT+QCAMOPEN=?
      ql_qr_usb_atcmd_func("AT+QCAMOPEN=480,640\r\n",user_callback);
	
	
	//start scanning  
 	//AT+QCAMIDFY
 	
	ql_qr_usb_atcmd_func("AT+QCAMIDFY=1\r\n",user_callback);

	
	//stop scanning 
	//ql_qr_usb_atcmd_func("AT+QCAMIDFY=0\r\n",user_callback);
	
	
	// close camera
	// AT+QCAMCLOSE
	//ql_qr_usb_atcmd_func( "AT+QCAMCLOSE\r\n",user_callback);

	//other AT+CMD please refence AT manual 

    while (1) {
        sleep(1);
    }
    
    return 0;
}
