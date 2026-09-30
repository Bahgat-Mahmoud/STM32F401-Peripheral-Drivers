/*
 * ESP_cfg.c
 *
 *  Created on: Aug 30, 2023
 *      Author: admin
 */

#include "../../LIB/STD_TYPES.h"

#include "ESP_int.h"
/*
 * FTP Login/Username: itiainshams.freevar.com
 */
HESP_RouterCfg_t  RouterInfo={
       .Name     = "NR",
	   .Password = "12052002@NR"
};
HESP_ServerCfg_t  SurverInfo=
{
		.Url        ="GET http://itiainshams.freevar.com/status.txt",
		.LengthOfUrl="47",
		.Ip         ="23.179.32.37",
		.Port       ="80"

};
