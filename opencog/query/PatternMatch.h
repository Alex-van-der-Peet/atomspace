/*
 * PatternMatch.h
 *
 * Author: Linas Vepstas February 2008
 *
 * Copyright (C) 2008,2009,2015 Linas Vepstas <linasvepstas@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License v3 as
 * published by the Free Software Foundation and including the exceptions
 * at http://opencog.org/wiki/Licenses
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program; if not, write to:
 * Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef _OPENCOG_PATTERN_MATCH_H
#define _OPENCOG_PATTERN_MATCH_H

#include <set>

#include <opencog/atomspace/Handle.h>
#include <opencog/query/Implicator.h>
#include <opencog/query/PatternMatchCallback.h>

namespace opencog {

class SatisfactionLink;

class PatternMatch
{
	friend class SatisfactionLink;

	protected:
		static bool recursive_virtual(PatternMatchCallback& cb,
		            const std::vector<Handle>& virtuals,
		            const std::vector<Handle>& negations,
		            const std::map<Handle, Handle>& var_gnds,
		            const std::map<Handle, Handle>& term_gnds,
		            std::vector<std::vector<std::map<Handle, Handle>>> comp_var_gnds,
		            std::vector<std::vector<std::map<Handle, Handle>>> comp_term_gnds);
};

} // namespace opencog

#endif // _OPENCOG_PATTERN_MATCH_H
