/*
  This is a simple C program to demonstrate the usage of callbacks
  The callback function is in the same file as the calling code.
  The callback function can later be put into external library like
  e.g. a shared object to increase flexibility.
*/

#include <stdio.h>
#include <string.h>

typedef struct _MyMsg {
    int appId;
    char msgbody[32];
} MyMsg;

void myfunc2(MyMsg *msg)
{
    printf(" my func 2.\n");
    if (strlen(msg->msgbody) > 0 )
	printf("App Id = %d \nMsg = %s \n",msg->appId, msg->msgbody);
    else
	printf("App Id = %d \nMsg = No Msg\n",msg->appId);
}

void myfunc(MyMsg *msg)
{

    if( msg->appId == 2) return myfunc2(msg);

    printf(" my func.\n");
    if (strlen(msg->msgbody) > 0 )
	printf("App Id = %d \nMsg = %s \n",msg->appId, msg->msgbody);
    else
	printf("App Id = %d \nMsg = No Msg\n",msg->appId);
}




/*
 * Prototype declaration
 */
void (*callback)(MyMsg *);

int main(void)
{
    MyMsg msg1;

    strcpy(msg1.msgbody, "This is a test\n");
    /*
     * Assign the address of the function "myfunc" to the function
     * pointer "callback" (may be also written as "callback = &myfunc;")
     */
    callback = &myfunc;
    /*
     * Call the function (may be also written as "(*callback)(&msg1);")
     */
    for( int target = 0 ; target <= 2; target++){
	msg1.appId = target;
	(*callback)(&msg1);
    }
    return 0;
}

