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
 * File:    mrsimplify.h
 * Authors: Björn Petersen
 * Purpose: Simplify and normalise text: Remove quotes, signatures, unnecessary
 *          lineends etc.
 *
 ******************************************************************************/


#ifndef __MRSIMPLIFY_H__
#define __MRSIMPLIFY_H__


class MrSimplify
{
public:
	                    MrSimplify           ();
	                    ~MrSimplify          ();

	// The data returned from Simplify() must be free()'d when no longer used
	char*               Simplify             (const char* txt_unterminated, int txt_bytes, int mimetype /*eg. MR_MIMETYPE_TEXT_HTML*/);

private:
	void                SimplifyPlainText    (char* buf);
	void                SimplifyHtml         (char* buf);

	void                RemoveCrChars        (char* buf);

	bool                IsEmpty              (const char* buf);
	bool                IsPlainQuote         (const char* buf);
	bool                IsQuoteHeadline      (const char* buf);

	carray*             SplitIntoLines       (const char* buf);
	void                FreeSplittedLines    (carray*);
};


#endif // __MRSIMPLIFY_H__
