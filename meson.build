project('wrapdb-tree', 'c',
  version : '0.1.0',
  license : 'MIT',
  default_options : ['warning_level=1', 'c_std=c11'])

ttf_dep = dependency('sdl2_ttf',
  fallback : ['sdl2_ttf', 'sdl2_ttf_dep'],
  required : false)

executable('ttfdemo',
  'src/main.c',
  dependencies : [ttf_dep],
  install : true)
