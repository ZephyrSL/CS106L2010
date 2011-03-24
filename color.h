/* Lecture code 4.2
 *
 * color.h file for sample 4.1.  The macros contained in here
 * are of the format DEFINE_COLOR(color, opposite) and can be
 * used by a calling application to export this information as
 * needed.  See the second half of Handout #08 for more
 * information.
 */

#ifndef DEFINE_COLOR
#error
#endif

DEFINE_COLOR(Red, Cyan)
DEFINE_COLOR(Green, Magenta)
DEFINE_COLOR(Blue, Yellow)
DEFINE_COLOR(Cyan, Red)
DEFINE_COLOR(Magenta, Green)
DEFINE_COLOR(Yellow, Blue)
DEFINE_COLOR(White, Black)
DEFINE_COLOR(Black, White)
