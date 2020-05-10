/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "storage.h"
#include "operations.h"

bool_t 
registeruser_1_svc(char *user, int *result,  struct svc_req *rqstp)
{
	bool_t retval;
	*result=registerU(user);
	
	retval=TRUE;
	return retval;
}

bool_t
unregisteruser_1_svc(char *user, int *result,  struct svc_req *rqstp)
{
	bool_t retval;

	*result=unregisterU(user);
	
	retval=TRUE;

	return retval;
}

bool_t
connectuser_1_svc(char *user, char *ip, int port, int *result,  struct svc_req *rqstp)
{
	bool_t retval;

	*result=connectU(user, ip, port);
	
	retval=TRUE;

	return retval;
}

bool_t
disconnectuser_1_svc(char *user, int *result,  struct svc_req *rqstp)
{
	bool_t retval;

	*result=disconnectU(user);
	
	retval=TRUE;

	return retval;
}

bool_t
publishfile_1_svc(char *user, char *file, char *description, int *result,  struct svc_req *rqstp)
{
	bool_t retval;

	*result=publishF(user, file, description);
	
	retval=TRUE;

	return retval;
}

bool_t
deletefile_1_svc(char *user, char *file, int *result,  struct svc_req *rqstp)
{
	bool_t retval;

	*result=deleteF(user, file);
	
	retval=TRUE;

	return retval;
}

bool_t
listuser_1_svc(char *user, mchains *result,  struct svc_req *rqstp)
{
	bool_t retval;



	return retval;
}

bool_t
listcontent_1_svc(char *user, char *puser, mchains *result,  struct svc_req *rqstp)
{
	bool_t retval;


	return retval;
}

bool_t
comprobar_1_svc(char *user, int *result,  struct svc_req *rqstp)
{
	bool_t retval;

	*result=check_User(user);
	
	retval=TRUE;

	return retval;
}

int
fildistributor_1_freeresult (SVCXPRT *transp, xdrproc_t xdr_result, caddr_t result)
{
	xdr_free (xdr_result, result);


	return 1;
}