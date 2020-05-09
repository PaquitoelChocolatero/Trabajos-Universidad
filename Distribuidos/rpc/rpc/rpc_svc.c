/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "rpc.h"
#include <stdio.h>
#include <stdlib.h>
#include <rpc/pmap_clnt.h>
#include <string.h>
#include <memory.h>
#include <sys/socket.h>
#include <netinet/in.h>

#ifndef SIG_PF
#define SIG_PF void(*)(int)
#endif

int
_registeruser_1 (char * *argp, void *result, struct svc_req *rqstp)
{
	return (registeruser_1_svc(*argp, result, rqstp));
}

int
_unregisteruser_1 (char * *argp, void *result, struct svc_req *rqstp)
{
	return (unregisteruser_1_svc(*argp, result, rqstp));
}

int
_connectuser_1 (connectuser_1_argument *argp, void *result, struct svc_req *rqstp)
{
	return (connectuser_1_svc(argp->user, argp->ip, argp->port, result, rqstp));
}

int
_disconnectuser_1 (char * *argp, void *result, struct svc_req *rqstp)
{
	return (disconnectuser_1_svc(*argp, result, rqstp));
}

int
_publishfile_1 (publishfile_1_argument *argp, void *result, struct svc_req *rqstp)
{
	return (publishfile_1_svc(argp->user, argp->file, argp->description, result, rqstp));
}

int
_deletefile_1 (deletefile_1_argument *argp, void *result, struct svc_req *rqstp)
{
	return (deletefile_1_svc(argp->user, argp->file, result, rqstp));
}

int
_listuser_1 (char * *argp, void *result, struct svc_req *rqstp)
{
	return (listuser_1_svc(*argp, result, rqstp));
}

int
_listcontent_1 (listcontent_1_argument *argp, void *result, struct svc_req *rqstp)
{
	return (listcontent_1_svc(argp->user, argp->puser, result, rqstp));
}

int
_comprobar_1 (char * *argp, void *result, struct svc_req *rqstp)
{
	return (comprobar_1_svc(*argp, result, rqstp));
}

static void
fildistributor_1(struct svc_req *rqstp, register SVCXPRT *transp)
{
	union {
		char *registeruser_1_arg;
		char *unregisteruser_1_arg;
		connectuser_1_argument connectuser_1_arg;
		char *disconnectuser_1_arg;
		publishfile_1_argument publishfile_1_arg;
		deletefile_1_argument deletefile_1_arg;
		char *listuser_1_arg;
		listcontent_1_argument listcontent_1_arg;
		char *comprobar_1_arg;
	} argument;
	union {
		int registeruser_1_res;
		int unregisteruser_1_res;
		int connectuser_1_res;
		int disconnectuser_1_res;
		int publishfile_1_res;
		int deletefile_1_res;
		mchains listuser_1_res;
		mchains listcontent_1_res;
		int comprobar_1_res;
	} result;
	bool_t retval;
	xdrproc_t _xdr_argument, _xdr_result;
	bool_t (*local)(char *, void *, struct svc_req *);

	switch (rqstp->rq_proc) {
	case NULLPROC:
		(void) svc_sendreply (transp, (xdrproc_t) xdr_void, (char *)NULL);
		return;

	case registerUser:
		_xdr_argument = (xdrproc_t) xdr_wrapstring;
		_xdr_result = (xdrproc_t) xdr_int;
		local = (bool_t (*) (char *, void *,  struct svc_req *))_registeruser_1;
		break;

	case unregisterUser:
		_xdr_argument = (xdrproc_t) xdr_wrapstring;
		_xdr_result = (xdrproc_t) xdr_int;
		local = (bool_t (*) (char *, void *,  struct svc_req *))_unregisteruser_1;
		break;

	case connectUser:
		_xdr_argument = (xdrproc_t) xdr_connectuser_1_argument;
		_xdr_result = (xdrproc_t) xdr_int;
		local = (bool_t (*) (char *, void *,  struct svc_req *))_connectuser_1;
		break;

	case disconnectUser:
		_xdr_argument = (xdrproc_t) xdr_wrapstring;
		_xdr_result = (xdrproc_t) xdr_int;
		local = (bool_t (*) (char *, void *,  struct svc_req *))_disconnectuser_1;
		break;

	case publishFile:
		_xdr_argument = (xdrproc_t) xdr_publishfile_1_argument;
		_xdr_result = (xdrproc_t) xdr_int;
		local = (bool_t (*) (char *, void *,  struct svc_req *))_publishfile_1;
		break;

	case deleteFile:
		_xdr_argument = (xdrproc_t) xdr_deletefile_1_argument;
		_xdr_result = (xdrproc_t) xdr_int;
		local = (bool_t (*) (char *, void *,  struct svc_req *))_deletefile_1;
		break;

	case listUser:
		_xdr_argument = (xdrproc_t) xdr_wrapstring;
		_xdr_result = (xdrproc_t) xdr_mchains;
		local = (bool_t (*) (char *, void *,  struct svc_req *))_listuser_1;
		break;

	case listContent:
		_xdr_argument = (xdrproc_t) xdr_listcontent_1_argument;
		_xdr_result = (xdrproc_t) xdr_mchains;
		local = (bool_t (*) (char *, void *,  struct svc_req *))_listcontent_1;
		break;

	case comprobar:
		_xdr_argument = (xdrproc_t) xdr_wrapstring;
		_xdr_result = (xdrproc_t) xdr_int;
		local = (bool_t (*) (char *, void *,  struct svc_req *))_comprobar_1;
		break;

	default:
		svcerr_noproc (transp);
		return;
	}
	memset ((char *)&argument, 0, sizeof (argument));
	if (!svc_getargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		svcerr_decode (transp);
		return;
	}
	retval = (bool_t) (*local)((char *)&argument, (void *)&result, rqstp);
	if (retval > 0 && !svc_sendreply(transp, (xdrproc_t) _xdr_result, (char *)&result)) {
		svcerr_systemerr (transp);
	}
	if (!svc_freeargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		fprintf (stderr, "%s", "unable to free arguments");
		exit (1);
	}
	if (!fildistributor_1_freeresult (transp, _xdr_result, (caddr_t) &result))
		fprintf (stderr, "%s", "unable to free results");

	return;
}

void cerrarServidor() {
    stopServer();
    fprintf(stderr, "\nCerrando servidor...\n");
    exit(0);
}

int
main (int argc, char **argv)
{
	//Capturamos Ctrl+C para añadir funcionalidades
    signal(SIGINT, cerrarServidor);

	register SVCXPRT *transp;

	pmap_unset (fildistributor, distrver);

	transp = svcudp_create(RPC_ANYSOCK);
	if (transp == NULL) {
		fprintf (stderr, "%s", "cannot create udp service.");
		exit(1);
	}
	if (!svc_register(transp, fildistributor, distrver, fildistributor_1, IPPROTO_UDP)) {
		fprintf (stderr, "%s", "unable to register (fildistributor, distrver, udp).");
		exit(1);
	}

	transp = svctcp_create(RPC_ANYSOCK, 0, 0);
	if (transp == NULL) {
		fprintf (stderr, "%s", "cannot create tcp service.");
		exit(1);
	}
	if (!svc_register(transp, fildistributor, distrver, fildistributor_1, IPPROTO_TCP)) {
		fprintf (stderr, "%s", "unable to register (fildistributor, distrver, tcp).");
		exit(1);
	}

	startServer();
	svc_run ();
	fprintf (stderr, "%s", "svc_run returned");
	exit (1);
	/* NOTREACHED */
}
