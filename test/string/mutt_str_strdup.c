/**
 * @file
 * Test code for mutt_str_strdup()
 *
 * @authors
 * Copyright (C) 2019 Richard Russon <rich@flatcap.org>
 *
 * @copyright
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 2 of the License, or (at your option) any later
 * version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#define TEST_NO_MAIN
#include "acutest.h"
#include "config.h"
#include "mutt/mutt.h"

void test_mutt_str_strdup(void)
{
  // char *mutt_str_strdup(const char *str);

  {
    TEST_CHECK(mutt_str_strdup(NULL) == NULL);
  }

  {
    TEST_CHECK(mutt_str_strdup("") == NULL);
  }

  {
    char *str = "apple";
    char *result = mutt_str_strdup(str);
    TEST_CHECK(result != NULL);
    TEST_CHECK(result != str);
    TEST_CHECK(strcmp(result, str) == 0);
    FREE(&result);
  }
}
