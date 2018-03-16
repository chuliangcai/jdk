/*
 * Copyright (c) 1999, 2010, Oracle and/or its affiliates. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 only, as
 * published by the Free Software Foundation.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * You should have received a copy of the GNU General Public License version
 * 2 along with this work; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Please contact Oracle, 500 Oracle Parkway, Redwood Shores, CA 94065 USA
 * or visit www.oracle.com if you need additional information or have any
 * questions.
 *
 */

#include "precompiled.hpp"
#include "ci/ciUtilities.hpp"
#include "gc/shared/cardTableModRefBS.hpp"
#include "gc/shared/cardTable.hpp"
#include "memory/universe.hpp"

// ciUtilities
//
// Miscellaneous internal compiler interface routines.

// ------------------------------------------------------------------
// basictype_to_str
const char* basictype_to_str(BasicType t) {
  const char* str = type2name(t);
  if (str == NULL) return "illegal";
  return str;
}

// ------------------------------------------------------------------
// basictype_to_char
const char basictype_to_char(BasicType t) {
  char c = type2char(t);
  return c ? c : 'X';
}

// ------------------------------------------------------------------
// card_table_base
jbyte *ci_card_table_address() {
  BarrierSet* bs = Universe::heap()->barrier_set();
  CardTableModRefBS* ctbs = barrier_set_cast<CardTableModRefBS>(bs);
  CardTable* ct = ctbs->card_table();
  assert(sizeof(*ct->byte_map_base()) == sizeof(jbyte), "adjust users of this code");
  return ct->byte_map_base();
}
