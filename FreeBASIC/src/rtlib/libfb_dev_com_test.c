/*
 *  libfb - FreeBASIC's runtime library
 *	Copyright (C) 2004-2005 Andre V. T. Vicentini (av1ctor@yahoo.com.br) and others.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/*
 *	dev_com - COMx device
 *
 * chng: aug/2005 written [mjs]
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "fb.h"
#include "fb_rterr.h"

/*:::::*/
int fb_DevComTestProtocolEx( struct _FB_FILE *handle,
                             const char *filename,
                             size_t filename_len,
                             size_t *pPort )
{
    char ch;
    size_t i, port;

    if( pPort ) {
        *pPort = 0;
    }

    if( strncasecmp(filename, "SER:", 4)==0 ) {
        if( pPort )
            *pPort = 1;
        return TRUE;
    }

    if( filename_len < 5 )
        return FALSE;
    if( strncasecmp(filename, "COM", 3)!=0 )
        return FALSE;

    port = 0;
    i = 3;
    ch = filename[i];
    while( ch>='0' && ch<='9' ) {
        port = port * 10 + (ch - '0');
        ch = filename[++i];
    }

    if( port==0 )
        return FALSE;
    if( ch!=':' )
        return FALSE;

    if( pPort )
        *pPort = port;

    return TRUE;
}

/*:::::*/
int fb_DevComTestProtocol( struct _FB_FILE *handle,
                           const char *filename,
                           size_t filename_len )
{
    return fb_DevComTestProtocolEx( handle, filename, filename_len, NULL );
}

