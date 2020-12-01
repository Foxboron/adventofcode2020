project('aoc', 'c')

progs = [
  'day1',
  'day2',
]

foreach p : progs
  exe = executable(p, '@0@/main.c'.format(p))
  test(p, exe)
endforeach
