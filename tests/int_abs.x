[ int_dup 0 int_lesser
  [ -1 int_mul ] if
] 'int_abs define

0 int_abs 0 int_equal assert
1 int_abs 1 int_equal assert
-1 int_abs 1 int_equal assert