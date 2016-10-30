/*******************************************************************************
 *
 *                             Messenger Backend
 *     Copyright (C) 2016 Björn Petersen Software Design and Development
 *                   Contact: r10s@b44t.com, http://b44t.com
 *
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later
 * version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see http://www.gnu.org/licenses/ .
 *
 *******************************************************************************
 *
 * File:    mrsmtp.h
 * Authors: Björn Petersen
 * Purpose: Use SMTP servers
 *
 ******************************************************************************/


#ifndef __MRSMTP_H__
#define __MRSMTP_H__
#ifdef __cplusplus
extern "C" {
#endif


/*** library-private **********************************************************/

typedef struct mrsmtp_t
{
	mailsmtp*    m_hEtpan;
	mrmailbox_t* m_mailbox;
	char*        m_from;
	int          m_esmtp;
} mrsmtp_t;

mrsmtp_t*    mrsmtp_new          (mrmailbox_t*);
void         mrsmtp_unref        (mrsmtp_t*);
int          mrsmtp_is_connected (mrsmtp_t*);
int          mrsmtp_connect      (mrsmtp_t*);
void         mrsmtp_disconnect   (mrsmtp_t*);
int          mrsmtp_send_msg     (mrsmtp_t*, uint32_t msg_id);


#ifdef __cplusplus
} /* /extern "C" */
#endif
#endif /* __MRPARAM_H__ */

